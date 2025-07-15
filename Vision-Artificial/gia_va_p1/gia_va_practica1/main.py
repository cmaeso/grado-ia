from src.Loader import Loader
from src.Image import Image
from src.Detector import Detector
from src.Homography import Homography
from src.FrameOfReference import FrameOfReference
from src.Cube import Cube
from src.PointsOutput import PointsOutput

import os
import argparse

# Programa principal
if __name__ == "__main__":
    """
    Se especifican los argumentos de ejecución:
        - --detector:
        - --test_path: Directorio en que se encuentran las imágenes de test.
        - --models_path: Directorio en que se encuentran los modelos 3D.
    """
    parser = argparse.ArgumentParser(description='Crea y ejecuta un detector sobre las imágenes de test')
    parser.add_argument(
        '--detector', type=str, nargs="?", default="SIFT-FLANN", help='Nombre del detector a ejecutar')
    parser.add_argument(
        '--test_path', default="", help='Carpeta con las imágenes de test')
    parser.add_argument(
        '--models_path', default="", help='Carpeta con los modelos 3D (.obj)')
    args = parser.parse_args()

    """
    Mostramos por pantalla las opciones escogidas
    """
    detector_name = args.detector
    print(f"- Detector seleccionado: {detector_name}")

    test_path = args.test_path
    print(f"- Directorio de test seleccionado: {test_path}")

    models_path = args.models_path
    print(f"- Directorio de modelos 3D (.obj): {models_path}")

    config_path = "config"  # Path de la configuración
    if not os.path.exists("resultado_imgs"):
        os.mkdir("resultado_imgs")  # Creamos directorio para las imágenes con el cubo y el SR
    result_path = os.path.join(".", "resultado_imgs")
    loader = Loader(test_path, models_path, config_path)
    detector = Detector(detector_name)

    """
    Cargamos las imágenes de escenas, la plantilla y los modelos 3D
    """
    images = loader.load_images(gray=False)
    images_gray = [img.to_gray() for img in images]
    template = loader.load_template(gray=True)

    intrinsics = loader.load_intrinsics()  # Parámetros intrínsecos
    fr = FrameOfReference(100)  # Sistema de Referencia
    cube_region = loader.load_cube_region()

    """
    Cargar, escalar y transladar el cubo 3D
    """
    cube = Cube()
    cube.load_from_obj(loader.models_paths[0])
    cube.scale_with_region(cube_region)
    cube.translate_with_region(cube_region)

    """
    Obtener P.I. y descriptores de la plantilla
    """
    kp_template, desc_template = detector.getKPandDesc(template)

    for img, img_gray in zip(images, images_gray):
        kp_img, desc_img = detector.getKPandDesc(img_gray)
        matches = detector.match(desc_template, desc_img)

        H_t_img = Homography.t2img_homography(kp_template, kp_img, matches)  # H_t^img
        H_w_t = Homography.world2t_homography(template)  # H_w^t
        H_w_img = Homography.world2img_homography(H_w_t, H_t_img)  # H_w^img
        P = Homography.projection_matrix(intrinsics, H_w_img)  # Matriz de proyección

        img_fr = fr.plot_on_image(img, P)  # Mostrar SR sobre la plantilla en la escena
        cube.plot_on_image(img_fr, P)  # Mostrar cubo 3D sobre la región especificada de la plantilla en la escena
        save_path = os.path.join(result_path, img.name)
        img_fr = Image(img_fr)
        img_fr.save(save_path)

        output = PointsOutput(P)
        result_points = output.get_border_points()
        x0 = result_points[0, 0]
        y0 = result_points[1, 0]
        x1 = result_points[0, 1]
        y1 = result_points[1, 1]
        x2 = result_points[0, 2]
        y2 = result_points[1, 2]
        x3 = result_points[0, 3]
        y3 = result_points[1, 3]
        with open("resultado.txt", 'a') as result_file:
            result_file.write(f"{img.name}; {x0}; {y0}; {x1}; {y1}; {x2}; {y2}; {x3}; {y3}\n")
        
        print(f"    - {img.name} finalizado.")
    print("- Proceso finalizado, puedes encontrar los resultados en 'results.txt' y 'resultado_imgs/'.")
    