from sklearn.svm import SVC
import os
import pickle
import sklearn.metrics
from sklearn.metrics import accuracy_score, f1_score
from src.classifiers.base import OCRClassifier

class SVMClassifier(OCRClassifier):
    def __init__(self, kernel='linear', C=1.0):
        self.kernel = kernel
        self.C = C
        self.model = SVC(kernel=self.kernel, C=self.C)

    def fit(self, X, y):
        self.model.fit(X, y)

    def predict(self, X):
        return self.model.predict(X)
