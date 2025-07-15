import os
import cv2
import numpy as np
import json
from .Image import Image

valid_detectors = [
    "sift",
    "orb",
]

valid_matchers = [
    "flann",
    "bf"
]

class Detector:
    """
    Crea una nueva instancia del objeto Detector. Sirve para obtener P.I. y descriptores
    y para emparejarlos.

    Args:
        detector_name (str): Nombre de la combinación de detector y matcher a usar.
                             Se especifica con el formato "detector-matcher".
    """
    def __init__(self, detector_name: str):
        self.detector_name = detector_name.split('-')[0].lower()
        self.matcher_name = detector_name.split('-')[-1].lower()

        # Cargamos el detector especificado
        if self.detector_name == "sift":
            self.detector = cv2.SIFT_create()
        elif self.detector_name == "orb":
            self.detector = cv2.ORB_create()
        else:
            print(f"El detector {self.detector_name} no es válido.")
            print("Detectores válidos:")
            print(valid_detectors)

        # Cargamos el matcher especificado
        if self.matcher_name == "flann":
            flann_params_path = os.path.join("config", "flann_params.json")
            with open(flann_params_path, 'r') as flann_params_file:
                flann_params = json.load(flann_params_file)

            if self.detector_name == "sift":
                indexParams = flann_params["SIFT"]["indexParams"]
                searchParams = flann_params["SIFT"]["searchParams"]
                self.matcher = cv2.FlannBasedMatcher(indexParams, searchParams)

            elif self.detector_name == "orb":
                indexParams = flann_params["ORB"]["indexParams"]
                searchParams = flann_params["ORB"]["searchParams"]
                self.matcher = cv2.FlannBasedMatcher(indexParams, searchParams)

        elif self.matcher_name == "bf":
            if self.detector_name == "sift":
                self.matcher = cv2.BFMatcher(normType=cv2.NORM_L2)

            elif self.detector_name == "orb":
                self.matcher = cv2.BFMatcher(normType=cv2.NORM_HAMMING)
        
        else:
            print(f"El matcher {self.matcher_name} no es válido.")
            print("Matchers válidos:")
            print(valid_matchers)

    
    """
    Devuelve los KP (Puntos de Interés) y descriptores de una imagen
    detectados por el detector con el que se inicializó la instancia.

    Args:
        img (Image): Objeto "Image" que corresponde a la imagen de la
                     cual se quieren obtener los KP y descriptores.
    """
    def getKPandDesc(self, img: Image) -> tuple[tuple[cv2.KeyPoint], tuple[np.ndarray]]:
        if not img.is_gray:
            gray_img = img.to_gray()
            return self.detector.detectAndCompute(gray_img.image, None)
        else:
            return self.detector.detectAndCompute(img.image, None)
    
    def __get_good_matches(self, matches: tuple[tuple[cv2.DMatch]], ratio_test_threshold: float) -> list[cv2.DMatch] | None:
        if len(matches) >= 4:
            good_matches = []
            for n1, n2 in matches:
                if n1.distance < (ratio_test_threshold * n2.distance):
                    good_matches.append(n1)
            return good_matches
        else:
            return None

    """
    Empareja los P.I. mediante los descriptores de la imagen de la 
    escena y la plantilla.

    Args:
        desc_img (np.ndarray): Descriptores de la escena.
        desc_template (np.ndarray): Descriptores de la plantilla.
    """
    def match(self, desc_template: np.ndarray, desc_img: np.ndarray) -> list[cv2.DMatch] | None:
        matches = self.matcher.knnMatch(desc_template, desc_img, k=2)
        return self.__get_good_matches(matches, 0.7)
