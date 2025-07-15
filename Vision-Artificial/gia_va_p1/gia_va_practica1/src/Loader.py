import os
import numpy as np
from .Image import Image
from .Model3D import Model3D

class Loader:
    """
    Crea una nueva instancia del objeto Loader. Sirve para cargar todos los datos y configuraciones
    necesarias para la ejecución del proyecto.

    Args:
        test_path (str): Ruta en que se encuentran las imágenes de escenas, la imagen de la plantilla
                         y la matriz de parámetros intrínsecos.
        models_path (str): Ruta en que se encuentran los modelos 3D que utilizaremos para R.A.
        config_path (str): Ruta en que se almacenan las configuraciones para FLANN, la región del cubo, etc.
    """
    def __init__(self, test_path: str, models_path: str, config_path: str):
        self.test_path = test_path
        self.models_path = models_path
        self.config_path = config_path
        self.models_paths = [os.path.join(self.models_path, m) for m in os.listdir(self.models_path) if m.endswith(".obj")]
        self.images_paths = [os.path.join(self.test_path, i) for i in os.listdir(self.test_path) if i.endswith(".jpg")]
        self.template_path = os.path.join(self.test_path, "template_cropped.png")

    """
    Devuelve una lista de objetos de tipo Image correspondientes
    a las imágenes del test_path definido por el usuario.

    Args:
        gray (bool): Si es "True", las imágenes se cargan en niveles de gris.
    """
    def load_images(self, gray: bool = False) -> list[Image]:
        return [Image(path, gray) for path in self.images_paths]
    
    """
    Carga la imagen de la plantilla 2D.

    Args:
        gray (bool): Si es "True", la plantilla se cargará en niveles de gris.
    """
    def load_template(self, gray: bool = False) -> Image:
        return Image(self.template_path, gray)
    
    """
    Carga la matriz de parámetros intrínsecos de la cámara con la que se tomaron
    las imágenes de escenas ('test_path/intrinsics.txt').
    """
    def load_intrinsics(self) -> np.ndarray:
        intrinsics_path = os.path.join(self.test_path, "intrinsics.txt")
        return np.loadtxt(intrinsics_path, dtype=np.float32)
    
    """
    Carga la región de la plantilla 2D sobre la que se colocará el cubo. Se encuentra
    en coordenadas homogéneas 2D.
    """
    def load_cube_region(self) -> np.ndarray:
        cube_region_path = os.path.join(self.config_path, "cube_region_mm.txt")
        return np.loadtxt(cube_region_path, dtype=np.float32)
        