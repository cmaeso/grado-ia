from .Image import Image
import cv2
import numpy as np

class FrameOfReference:
    """
    Constructor que crea una nueva instancia de FrameOfReference
    (Sistema de Referencia) dada la longitud de los ejes.

    Args:
        axs_length (int): Longitud de cada eje.
    """
    def __init__(self, axs_length: int):
        self.axs3D = np.array([
            [0, 0, 0, 1],
            [axs_length, 0, 0, 1],
            [0, axs_length, 0, 1],
            [0, 0, -axs_length, 1]
        ], dtype=np.float32).T

    """
    Copia la imagen que recibe como argumento y, utilizando la matriz 'P',
    dibuja los ejes X, Y y Z del SR de la plantilla en la escena.

    Args:
        image (Image): Imagen sobre la que se dibujará el SR.
        P (np.ndarray): Matriz de proyección que relaciona las coordenadas en mm respecto
                        a la plantilla con las coordenadas en px respecto al SR de la imagen.
    """
    def plot_on_image(self, image: Image, P: np.ndarray) -> np.ndarray:
        axs2D = P @ self.axs3D
        axs2D /= axs2D[2, :]
        points2D_cart = axs2D[:2, :].T
        origin = (int(points2D_cart[0][0]), int(points2D_cart[0][1]))
        xpoint = (int(points2D_cart[1][0]), int(points2D_cart[1][1]))
        ypoint = (int(points2D_cart[2][0]), int(points2D_cart[2][1]))
        zpoint = (int(points2D_cart[3][0]), int(points2D_cart[3][1]))

        img_fr = image.copy().image
        cv2.line(img_fr, origin, xpoint, (0, 0, 255), 10)
        cv2.line(img_fr, origin, ypoint, (255, 0, 0), 10)
        cv2.line(img_fr, origin, zpoint, (0, 255, 0), 10)

        return img_fr
