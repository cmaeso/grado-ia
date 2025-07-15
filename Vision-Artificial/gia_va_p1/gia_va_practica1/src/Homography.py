import os
import cv2
import numpy as np
import numpy.linalg as linalg
from .Image import Image

class Homography:
    def __init__(self):
        pass

    """
    Devuelve la homografía que transforma las coordenadas en píxeles respecto al SR de la plantilla
    en coordenadas en píxeles respecto al SR de la imagen.
    
    Args:
        kp_img (tuple[cv2.KeyPoint]): P.I. detectados en la escena.
        kp_template (tuple[cv2.KeyPoint]): P.I. detectados en la plantilla.
        matches (list[cv2.DMatch]): Matches obtenidos en base a los descriptores.
    """
    @staticmethod
    def t2img_homography(kp_template: tuple[cv2.KeyPoint], kp_img: tuple[cv2.KeyPoint], matches: list[cv2.DMatch]):
        if len(matches) >= 4:
            src_pts = np.array([kp_template[m.queryIdx].pt for m in matches], dtype=np.float32).reshape(-1, 1, 2)
            dst_pts = np.array([kp_img[m.trainIdx].pt for m in matches], dtype=np.float32).reshape(-1, 1, 2)
            return cv2.findHomography(src_pts, dst_pts, cv2.RANSAC)[0]
        else:
            return None, None
    
    """
    Devuelve la homografía que transforma las coordenadas en milímetros respecto al SR de la plantilla
    en coordenadas en píxeles respecto al mismo SR.

    Args:
        corners_w (np.ndarray): Esquinas del objeto plano en mm (respecto al SR de la plantilla). Se utilizan
                                coordenadas cartesianas.
        corners_t (np.ndarray): Esquinas del objeto plano en px (respecto al SR de la plantilla). Se utilizan
                                coordenadas cartesianas.
    """
    @staticmethod
    def world2t_homography(template: Image):
        corners_w_path = os.path.join("config", "object_corners_mm.txt")
        corners_w = np.loadtxt(corners_w_path, dtype=np.float32)
        corners_px = np.array([
            [0, 0],  # Esquina sup. izq.
            [template.shape[1], 0],  # Esquina sup. der.
            [template.shape[1], template.shape[0]],  # Esquina inf. der.
            [0, template.shape[0]]  # Esquina inf. izq.
        ], dtype=np.float32)

        return cv2.getPerspectiveTransform(corners_w, corners_px)
    
    """
    Devuelve la homografía que transforma coordenadas en mm respecto al SR de la plantilla en la escena
    en coordenadas en px respecto al SR de la imagen.

    Args:
        H_w_t (np.ndarray): Homografía que transforma las coordenadas en mm respecto al SR de la plantilla
        en la escena en coordenadas en píxeles respecto al SR de la plantilla.
        H_t_img (np.ndarray): Homografía que transforma las coordenadas en píxles respecto al SR de la plantilla
        en coordenadas en píxeles respecto al SR de la imagen.
    """
    @staticmethod
    def world2img_homography(H_w_t: np.ndarray, H_t_img: np.ndarray):
        return np.dot(H_t_img, H_w_t)
    
    """
    Devuelve la matriz de proyección, que transforma las coordenadas en mm respecto al SR de la plantilla en
    coordenadas en px respecto al SR de la imagen.
    
    Args:
        K (np.ndarray): Matriz de parámetros intrínsecos de la cámara con la que se tomó la imagen de la escena.
        H_w_img (np.ndarray): Homografía que transforma coordenadas en mm respecto al SR de la plantilla en la escena
        en coordenadas en px respecto al SR de la imagen.
    """
    @staticmethod
    def projection_matrix(K: np.ndarray, H_w_img: np.ndarray):
        H_star = linalg.inv(K) @ H_w_img
        h1 = H_star[:, 0]
        h2 = H_star[:, 1]
        h3 = H_star[:, 2]

        lambda_val = linalg.norm(h1)

        r1 = h1 / lambda_val
        r2 = h2 / lambda_val
        r3 = np.cross(r1, r2)
        t = (h3 / lambda_val).reshape(-1, 1)

        R = np.vstack((r1, r2, r3)).T
        
        return K @ np.hstack((R, t))
