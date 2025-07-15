import cv2
import numpy as np

class CharImgPreprocessor:
    def _init_(self, size=(30, 30)):
        self.size = size  # Tamaño de salida de las imágenes

    def process_image(self, img_gray):
        """
        Procesa una imagen en escala de grises y devuelve una lista de imágenes
        de caracteres recortadas y redimensionadas a self.size x self.size.
        """
        thresh = cv2.adaptiveThreshold(
            img_gray, 255, 
            cv2.ADAPTIVE_THRESH_MEAN_C, 
            cv2.THRESH_BINARY_INV, 11, 2
        )

        contours, _ = cv2.findContours(
            thresh, cv2.RETR_EXTERNAL, 
            cv2.CHAIN_APPROX_SIMPLE
        )

        bboxes = []
        for cnt in contours:
            x, y, w, h = cv2.boundingRect(cnt)
            if w > 5 and h > 5:  # filtro para eliminar ruido
                bboxes.append((x, y, w, h))
        
        if bboxes:
            return bboxes[0]
        else:
            return (0, 0, img_gray.shape[1], img_gray.shape[0])
    