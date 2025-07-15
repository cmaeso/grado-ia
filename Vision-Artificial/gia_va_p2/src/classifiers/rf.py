from sklearn.ensemble import RandomForestClassifier
from .base import OCRClassifier

class RFClassifier(OCRClassifier):
    def __init__(self):
        self.model = RandomForestClassifier(n_estimators=100)

    def fit(self, X, y):
        self.model.fit(X, y)

    def predict(self, X):
        return self.model.predict(X)
