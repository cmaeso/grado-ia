import cv2
import numpy as np

class Image:
    """
    Inicializa una instancia de Image (constructor)

    Args:
        image_path (str): Ruta relativa en que se encuentra la imagen
    """
    def __init__(self, image: str | np.ndarray, gray: bool = False):
        if isinstance(image, str):
            self.path = image
            self.name = self.path.split('/')[-1]
            self.is_gray = gray

            # Intentar leer la imagen
            try:
                if gray:
                    self.image = cv2.imread(image, flags=cv2.IMREAD_GRAYSCALE)
                else:
                    self.image = cv2.imread(image)

                if self.image is None:
                    raise FileNotFoundError(f"No se pudo cargar '{image}'.")
                self.shape = self.image.shape

            except FileNotFoundError as error:
                print(error)
        else:
            self.image = image
            self.name = None
            self.path = None
            if len(self.image.shape) == 2:
                self.is_gray = True
            else:
                self.is_gray = False
            self.shape = self.image.shape      

    """
    Devuelve la imagen en niveles de gris (0-255).
    """
    def to_gray(self) -> "Image":
        return Image(self.path, True)
        
    """
    Devuelve una nueva instancia de Image como una copia.
    """
    def copy(self) -> "Image": 
        return Image(self.path, self.is_gray)
    
    """
    Guarda la imagen Image en el disco.

    Args:
        path (str): Ruta en que se almacenará la imagen.
    """
    def save(self, path: str):
        cv2.imwrite(path, self.image)
