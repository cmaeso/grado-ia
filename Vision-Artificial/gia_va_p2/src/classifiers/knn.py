from sklearn.neighbors import KNeighborsClassifier
from .base import OCRClassifier

class KNNClassifier(OCRClassifier):
    def __init__(self):
        self.model = KNeighborsClassifier(n_neighbors=3)

    def fit(self, X, y):
        self.model.fit(X, y)

    def predict(self, X):
        return self.model.predict(X)