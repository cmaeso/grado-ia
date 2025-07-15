import os
import cv2
import numpy as np
from tqdm import tqdm

def load_image(path: str, gray: bool):
    """
    Carga una imagen desde el path dado.
    """
    flag = cv2.IMREAD_GRAYSCALE if gray else cv2.IMREAD_COLOR
    img = cv2.imread(path, flag)
    if img is None:
        print(f"[ERROR] No se pudo cargar la imagen: {path}")
    return img

def load_data(data_path, preprocessor):
    """
    Carga y preprocesa imágenes desde un directorio con subdirectorios por clase.
    Devuelve X (imágenes vectorizadas) e y (etiquetas).
    """
    X, y = [], []

    for root, dirs, files in tqdm(os.walk(data_path), desc="Cargando caracteres"):
        label = os.path.basename(root)

        for fname in files:
            fpath = os.path.join(root, fname)
            img = load_image(fpath, gray=True)
            if img is None:
                continue

            chars = preprocessor.process_image(img)

            for char_img in chars:
                vector = char_img.flatten()
                X.append(vector)
                y.append(label)

    return np.array(X), np.array(y)
