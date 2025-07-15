import pickle
from sklearn.metrics import accuracy_score, f1_score

class OCRClassifier:
    def fit(self, X, y):
        raise NotImplementedError("Debes implementar el método fit")

    def predict(self, X):
        raise NotImplementedError("Debes implementar el método predict")

    def save(self, path):
        with open(path, 'wb') as f:
            pickle.dump(self, f)

    def load(self, path):
        with open(path, 'rb') as f:
            classifier = pickle.load(f)
        return classifier

    def evaluate(self, X, y):   
        y_pred = self.predict(X)
        accuracy = accuracy_score(y, y_pred)
        f1 = f1_score(y, y_pred, average='weighted')
        return accuracy, f1
