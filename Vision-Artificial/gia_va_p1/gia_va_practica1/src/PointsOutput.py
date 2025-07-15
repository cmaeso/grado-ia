import os
import numpy as np

class PointsOutput:
    def __init__(self, P: np.ndarray):
        corners_w_path = os.path.join("config", "object_corners_mm.txt")
        self.corners_w = np.loadtxt(corners_w_path, dtype=np.float32)
        self.corners_w = np.hstack((self.corners_w, np.ones(shape=(self.corners_w.shape[0], 1)))).T
        self.corners_w = np.vstack((self.corners_w[:2, :], np.zeros(shape=(1, self.corners_w.shape[1])), self.corners_w[2, :]))
        self.P = P

    def get_border_points(self):
        result = self.P @ self.corners_w
        return result / result[2, :]
