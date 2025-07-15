# @brief main_text_ocr
# @author Jose M. Buenaposada (josemiguel.buenaposada@urjc.es)
# @date 2025
#

import cv2
import os
import sys

import pickle
import sklearn
from sklearn.metrics import ConfusionMatrixDisplay
from src.preprocessor import CharImgPreprocessor
from src.ocr_training_data_loader import OCRTrainingDataLoader

from src.eval_utils import (
    print_metrics,
    plot_roc_curve,
    plot_precision_recall,
    plot_confusion_matrix
)
from src.classifiers.base import OCRClassifier
from src.classifiers.svm import SVMClassifier
from src.classifiers.knn import KNNClassifier  
from src.classifiers.rf import RFClassifier
import numpy as np
import matplotlib.pyplot as plt
import argparse

from sklearn.preprocessing import label_binarize

src_path = os.path.abspath(os.path.join(os.path.dirname(__file__), "src"))
sys.path.append(src_path)


def get_classifier(name):
    name = name.lower()
    if name == 'svm':
        return SVMClassifier()
    elif name == 'rf':
        return RFClassifier()
    elif name == 'knn':
        return KNNClassifier()
    else:
        raise ValueError(f"Clasificador no soportado: {name}")


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Crea y ejecuta un detector sobre las imágenes de test')
    parser.add_argument(
        '--train_ocr_path', default="../Materiales_Práctica2/train_ocr", help='Select the training data dir for OCR')
    parser.add_argument(
        '--test_ocr_char_path', default="../Materiales_Práctica2/test_ocr_char", help='Imágenes de test para OCR de caracteres')
    parser.add_argument(
        '--test_ocr_words_path', default="../Materiales_Práctica2/test_ocr_words_plain", help='Imágenes de test para OCR con palabras completas')
    parser.add_argument(
        '--save_model_path', default=".", help='Directorio para guardar el modelo entrenado')
    parser.add_argument(
        '--classifier', default="rf", help='Clasificador a usar: rf, knn, svm')
    
    args = parser.parse_args()

    TEST_OCR_CLASSIFIER_IN_CHARS=True
    TEST_OCR_CLASSIFIER_IN_WORDS=False #No implementamos el ej 3
    SAVED_OCR_CLF = "clasificador.pickle"
    
    # Create the classifier reading the training data
    print("Training OCR classifier ...")

    data_ocr = OCRTrainingDataLoader(char_size=(30, 30))

    if not os.path.exists(SAVED_OCR_CLF):

        # Load OCR training data (individual char images)
        print("Loading train char OCR data ...")
        train_data = data_ocr.load(args.train_ocr_path)
        X_train, y_train = [], []
        for label, images in train_data.items():
            for img in images:
                X_train.append(img.flatten())
                y_train.append(label)
        X_train = np.array(X_train)
        y_train = np.array(y_train)


        # Train the OCR classifier for individual chars
        clf = get_classifier(args.classifier)
        clf.fit(X_train, y_train)
        
        with open(SAVED_OCR_CLF, "wb") as pickle_file:
            pickle.dump(clf, pickle_file)
            print(f"Modelo guardado en: {args.save_model_path}")


    else:
        with open(SAVED_OCR_CLF, "rb") as pickle_file:
            clf = pickle.load(pickle_file)

    test_loader = OCRTrainingDataLoader()
    if TEST_OCR_CLASSIFIER_IN_CHARS:
        # Load OCR testing data (individual char images) in args.test_char_ocr_path
        print("Loading test char OCR data ...")
        gt_data = test_loader.load(args.test_ocr_char_path)
        X_test, gt_test = [], []
        for label, images in gt_data.items():
            for img in images:
                X_test.append(img.flatten())
                gt_test.append(label)
        X_test = np.array(X_test)
        gt_test = np.array(gt_test)

        
        print("Executing classifier in char images ...")
        estimated_test = clf.predict(X_test)
        
        # Display of classifier results statistics
        print("\n[ Evaluación básica ]")
        metrics = print_metrics(gt_test, estimated_test)

        print("\n[ Evaluación avanzada y visualización ]")
        classes = sorted(np.unique(gt_test))
        y_test_bin = label_binarize(gt_test, classes=classes)
        y_pred_bin = label_binarize(estimated_test, classes=classes)

        plot_roc_curve(y_test_bin, y_pred_bin, classes, args.classifier, plots_dir="eval_plots")
        plot_precision_recall(y_test_bin, y_pred_bin, classes, args.classifier, plots_dir="eval_plots", f1_reference=metrics['f1_macro_present'])
        plot_confusion_matrix(gt_test, estimated_test, classes, args.classifier, plots_dir="eval_plots")


        
        

    if TEST_OCR_CLASSIFIER_IN_WORDS:
        # Load full words images for testing the words reader.
        print("Loading and processing word images OCR data ...")

        # Open results file
        results_save_path = "results_ocr_words_plain"
        try:
            os.mkdir(results_save_path)
        except:
            print('Can not create dir "' + results_save_path + '"')

        results_file = open(os.path.join(results_save_path, "results_text_lines.txt"), "w")
        
        # Execute the OCR over every single image in args.test_words_ocr_path
        # POR HACER ...







