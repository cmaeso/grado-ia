from .Model3D import Model3D
import numpy as np

class Cube(Model3D):
    """
    Escala el cubo teniendo en cuenta la región que va a ocupar.

    Args:
        real_region (np.ndarray): Puntos que definen la región que ocupará el cubo en milímetros.
    """
    def scale_with_region(self, real_region: np.ndarray):
        width_mm = real_region[0, 1] - real_region[0, 0]
        width_cube = self.vertices[0, 1] - self.vertices[1, 1]
        self.scale(width_mm / width_cube)
    
    """
    Translada el cubo teniendo en cuenta la región que va a ocupar.

    Args:
        real_region (np.ndarray): Puntos que definen la región que ocupará el cubo en milímetros.
    """
    def translate_with_region(self, real_region: np.ndarray):
        bottom_face_vertex = self.vertices[self.vertices[:, 2] == np.min(self.vertices[:, 2], axis=0)]
        bottom_face_center = np.mean(bottom_face_vertex, axis=0)
        region_center = np.array([(real_region[0, 0] + real_region[0, 2]) / 2,
                                  (real_region[1, 0] + real_region[1, 2]) / 2,
                                  0], dtype=np.float32)
        translation_vector = (region_center - bottom_face_center).reshape(1, 3)
        translation_vector[0, 2] = -translation_vector[0, 2]
        self.translate(translation_vector)
