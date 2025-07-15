import os
import numpy as np
import matplotlib.pyplot as plt
from sklearn.metrics import (
    accuracy_score, f1_score, classification_report,
    roc_curve, precision_recall_curve, auc,
    ConfusionMatrixDisplay
)

def print_metrics(y_true, y_pred):
    """
    Imprime métricas de evaluación y devuelve un diccionario con ellas.
    """
    acc = accuracy_score(y_true, y_pred)
    f1_macro_all = f1_score(y_true, y_pred, average='macro')
    present_classes = np.unique(y_true)
    f1_macro_present = f1_score(y_true, y_pred, average='macro', labels=present_classes)
    f1_weighted = f1_score(y_true, y_pred, average='weighted')

    print(f"Accuracy:                  {acc:.4f}")
    print(f"F1-score macro (todas):    {f1_macro_all:.4f}")
    print(f"F1-score macro (present):  {f1_macro_present:.4f}")
    print(f"F1-score weighted:         {f1_weighted:.4f}")

    print("\nInforme por clase:")
    print(classification_report(y_true, y_pred, zero_division=0))

    return {
        'accuracy': acc,
        'f1_macro_all': f1_macro_all,
        'f1_macro_present': f1_macro_present,
        'f1_weighted': f1_weighted
    }

def plot_roc_curve(y_test_bin, y_pred_bin, classes, name, plots_dir="eval_plots"):
    """
    Dibuja la curva ROC multiclase.
    """
    os.makedirs(plots_dir, exist_ok=True)
    fpr, tpr, roc_auc = {}, {}, {}

    for i in range(len(classes)):
        fpr[i], tpr[i], _ = roc_curve(y_test_bin[:, i], y_pred_bin[:, i])
        roc_auc[i] = auc(fpr[i], tpr[i])

    plt.figure(figsize=(8, 6))
    for i in range(len(classes)):
        plt.plot(fpr[i], tpr[i], label=f"Clase {classes[i]} (AUC = {roc_auc[i]:.2f})")
    plt.plot([0, 1], [0, 1], 'k--')
    plt.title(f"Curva ROC – {name.upper()}")
    plt.xlabel("Tasa de falsos positivos")
    plt.ylabel("Tasa de verdaderos positivos")
    plt.legend(loc='lower right', fontsize='small')
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(os.path.join(plots_dir, f"{name}_roc.png"))
    plt.show()


def plot_precision_recall(y_test_bin, y_pred_bin, classes, name, plots_dir="eval_plots", f1_reference=None):
    """
    Dibuja la curva Precision-Recall multiclase.
    """
    os.makedirs(plots_dir, exist_ok=True)
    precision, recall, pr_auc = {}, {}, {}

    plt.figure(figsize=(8, 6))
    for i in range(len(classes)):
        precision[i], recall[i], _ = precision_recall_curve(y_test_bin[:, i], y_pred_bin[:, i])
        pr_auc[i] = auc(recall[i], precision[i])
        plt.plot(recall[i], precision[i], label=f"Clase {classes[i]} (AUC = {pr_auc[i]:.2f})")

    if f1_reference is not None:
        plt.axhline(f1_reference, color='red', linestyle='--', label=f"F1 macro (present) = {f1_reference:.2f}")

    plt.title(f"Precision-Recall – {name.upper()}")
    plt.xlabel("Recall")
    plt.ylabel("Precision")
    plt.grid(True)
    plt.legend(loc="best", fontsize='small')
    plt.tight_layout()
    plt.savefig(os.path.join(plots_dir, f"{name}_pr_curve.png"))
    plt.show()


def plot_confusion_matrix(y_true, y_pred, classes, name, plots_dir="eval_plots"):
    """
    Dibuja la matriz de confusión.
    """
    os.makedirs(plots_dir, exist_ok=True)
    disp = ConfusionMatrixDisplay.from_predictions(
        y_true, y_pred, display_labels=classes,
        xticks_rotation='vertical', cmap='Blues',
        normalize=None
    )
    plt.title(f"Matriz de Confusión – {name.upper()}")
    plt.tight_layout()
    plt.savefig(os.path.join(plots_dir, f"{name}_confmat.png"))
    plt.show()
