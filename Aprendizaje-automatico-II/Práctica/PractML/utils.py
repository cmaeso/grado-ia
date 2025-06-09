import torch
import torch.nn as nn
import pandas as pd
from torch.utils.data import DataLoader
import matplotlib.pyplot as plt
import numpy as np
from sklearn.metrics import confusion_matrix, classification_report
import seaborn as sns

def count_trainable_params(model: nn.Module) -> int:
    """
    Cuenta cuántos parámetros del modelo se pueden entrenar.

    Args:
        model (nn.Module): El modelo de PyTorch que queremos analizar.

    Returns:
        int: La cantidad de parámetros entrenables.
    """
    total_params = 0
    for p in model.parameters():
            if p.requires_grad:
                total_params += p.numel() #cuenta num elementos de un tensor
    return total_params

# Función de entrenamiento
def train(model, train_loader, loss_fn, optimizer, device):
    model.train()
    running_loss = 0.0
    correct = 0
    total = 0
    for images, labels in train_loader:
        images, labels = images.to(device), labels.to(device)

        # Forward pass
        outputs = model(images)
        loss =loss_fn(outputs, labels)

        # Backward pass y optimización
        optimizer.zero_grad()
        loss.backward()
        optimizer.step()

        running_loss += loss.item()

        # Calcular la precisión

        predicted = torch.argmax(outputs, dim=1)

        total += labels.size(0)
        correct += (predicted == labels).sum().item()

    avg_loss = running_loss / len(train_loader)
    accuracy = correct / total
    return avg_loss, accuracy

# Función de evaluación
def evaluate(model, val_loader, loss_fn, device):
    model.eval()
    running_loss = 0.0
    correct = 0
    total = 0
    with torch.no_grad():
        for images, labels in val_loader:
            images, labels =images.to(device), labels.to(device)

            # Forward pass
            outputs = model(images)
            loss =loss_fn(outputs, labels)

            running_loss += loss.item()

            # Calcular la precisión
            predicted = torch.argmax(outputs, dim=1)
            total += labels.size(0)
            correct += (predicted == labels).sum().item()

    avg_loss = running_loss / len(val_loader)
    accuracy = correct / total
    return avg_loss, accuracy

def train_and_evaluate(model, train_loader, val_loader, loss_fn, optimizer, device, num_epochs=10, test_loader=None, name='None'):
    train_losses = []
    val_losses = []
    train_accuracies = []  # Lista para almacenar las precisiones de entrenamiento
    val_accuracies = []  # Lista para almacenar las precisiones de validación

    # Ciclo de entrenamiento
    for epoch in range(num_epochs):
        # Entrenamiento
        train_loss, train_accuracy =  train(model, train_loader, loss_fn, optimizer, device)
        # COMPLETAR

        train_losses.append(train_loss)
        train_accuracies.append(train_accuracy)

        # Evaluación en el conjunto de validación
        val_loss, val_accuracy = evaluate(model, val_loader, loss_fn, device)# COMPLETAR

        val_losses.append(val_loss)
        val_accuracies.append(val_accuracy)

        # Imprimir pérdidas y precisión
        print(f"Epoch [{epoch+1}/{num_epochs}], Train Loss: {train_loss:.4f}, Train Accuracy: {train_accuracy:.4f}, Validation Loss: {val_loss:.4f}, Validation Accuracy: {val_accuracy:.4f}")

    # Guardar pérdidas y precisión en archivos CSV
    train_loss_df = pd.DataFrame({'Epoch': range(1, num_epochs+1), 'Train Loss': train_losses, 'Train Accuracy': train_accuracies})
    val_loss_df = pd.DataFrame({'Epoch': range(1, num_epochs+1), 'Validation Loss': val_losses, 'Validation Accuracy': val_accuracies})

    train_loss_df.to_csv(f'train_loss_{name}.csv', index=False)
    val_loss_df.to_csv(f'valid_loss_{name}.csv', index=False)

    # Evaluación en el conjunto de test (si se proporciona)
    if test_loader is not None:
        test_loss, test_accuracy =  evaluate(model, test_loader, loss_fn, device)
        print(f"Test Loss: {test_loss:.4f}, Test Accuracy: {test_accuracy:.4f}")

        # Guardar la precisión de test en un archivo CSV
        test_accuracy_df = pd.DataFrame({'Test Accuracy': [test_accuracy]})
        test_accuracy_df.to_csv(f'test_accuracy_{name}.csv', index=False)

    # Guardar las precisiones de entrenamiento y validación en archivos CSV
    train_accuracy_df = pd.DataFrame({'Epoch': range(1, num_epochs+1), 'Train Accuracy': train_accuracies})
    val_accuracy_df = pd.DataFrame({'Epoch': range(1, num_epochs+1), 'Validation Accuracy': val_accuracies})

    train_accuracy_df.to_csv(f'train_accuracy_{name}.csv', index=False)
    val_accuracy_df.to_csv(f'valid_accuracy_{name}.csv', index=False)

    return train_loss_df, val_loss_df, test_loss, test_accuracy

def save_full_model(model, file_name):
    """
    Guarda el modelo completo, incluyendo la arquitectura y los pesos.

    Args:
        model: El modelo de PyTorch a guardar.
        file_name: El nombre del archivo donde se guardará el modelo.
    """
    torch.save(model, file_name)
    print(f"Modelo completo guardado como {file_name}")


def load_full_model(file_name):

    """
    Carga el modelo completo desde un archivo guardado.

    Args:
        file_name: El nombre del archivo del modelo guardado.

    Returns:
        model: El modelo cargado.
    """
    model = torch.load(file_name)
    print(f"Modelo cargado desde {file_name}")
    return model

def plot_loss_accuracy(train_loss_file, valid_loss_file, train_accuracy_file, valid_accuracy_file):
    # Leer los archivos CSV con los datos
    train_loss_df = pd.read_csv(train_loss_file)
    valid_loss_df = pd.read_csv(valid_loss_file)
    train_accuracy_df = pd.read_csv(train_accuracy_file)
    valid_accuracy_df = pd.read_csv(valid_accuracy_file)


    # Configuración de la figura
    fig, (ax1, ax2) = plt.subplots(1, 2, figsize=(14, 6))

    # Gráfico de las pérdidas
    ax1.plot(train_loss_df['Epoch'], train_loss_df['Train Loss'], label='Train Loss', color='blue', linestyle='-', marker='o')
    ax1.plot(valid_loss_df['Epoch'], valid_loss_df['Validation Loss'], label='Validation Loss', color='red', linestyle='-', marker='x')
    ax1.set_title('Train & Validation Loss', fontsize=14)
    ax1.set_xlabel('Epoch', fontsize=12)
    ax1.set_ylabel('Loss', fontsize=12)
    ax1.legend()
    ax1.grid(True)

    # Gráfico de las precisiones
    ax2.plot(train_accuracy_df['Epoch'], train_accuracy_df['Train Accuracy'], label='Train Accuracy', color='blue', linestyle='-', marker='o')
    ax2.plot(valid_accuracy_df['Epoch'], valid_accuracy_df['Validation Accuracy'], label='Validation Accuracy', color='red', linestyle='-', marker='x')
    ax2.set_title('Train & Validation Accuracy', fontsize=14)
    ax2.set_xlabel('Epoch', fontsize=12)
    ax2.set_ylabel('Accuracy', fontsize=12)
    ax2.legend()
    ax2.grid(True)

    # Mostrar las gráficas
    plt.tight_layout()
    plt.show()


def plot_confusion_matrix(model, test_dataloader, device):
    """
    Genera y pinta la matriz de confusión de un modelo en PyTorch utilizando el DataLoader de prueba,
    y guarda la imagen resultante.

    Args:
        model: El modelo de PyTorch entrenado.
        test_dataloader: El DataLoader que contiene los datos de prueba.
        device: El dispositivo en el que se encuentra el modelo (CPU o GPU).
        filename: El nombre del archivo para guardar la imagen de la matriz de confusión.
    """
    # Poner el modelo en modo de evaluación
    model.eval()
            # COMPLETAR

    all_preds = []
    all_labels = []

    # Desactivar el cálculo de gradientes (no se necesita para la inferencia)
    with torch.no_grad():
        for images, labels in test_dataloader:
            # Enviar las imágenes y las etiquetas al dispositivo correcto
            images, labels =  images.to(device), labels.to(device) # COMPLETAR

            # Obtener las predicciones del modelo
            outputs = model(images) # COMPLETAR
            preds = torch.argmax(outputs, dim=1) # COMPLETAR

            # Almacenar las predicciones y las etiquetas reales
            all_preds.extend(preds.cpu().numpy())  # Convertir a CPU y luego a numpy
            all_labels.extend(labels.cpu().numpy())

    # Calcular la matriz de confusión
    cm =  confusion_matrix(all_labels, all_preds)  # COMPLETAR

    # Pintar la matriz de confusión usando seaborn
    plt.figure(figsize=(10, 7))
    sns.heatmap(cm, annot=False, fmt='d', cmap='Blues', xticklabels=np.arange(cm.shape[1]), yticklabels=np.arange(cm.shape[0]))
    plt.xlabel('Predicción')
    plt.ylabel('Etiqueta Real')
    plt.title('Matriz de Confusión')
    plt.show()

    return cm

def plot_error_per_class(cm, title="Porcentaje de error por clase"):
    """
    Calcula y visualiza el porcentaje de error por clase a partir de la matriz de confusión.

    Args:
        cm (numpy.ndarray): Matriz de confusión (2D array).
        title (str): Título del gráfico.
    """
    # Calcular el porcentaje de error por clase
    total_per_class = cm.sum(axis=1)
    errors_per_class = total_per_class - np.diag(cm)
    error_per_class = errors_per_class / total_per_class

    # Crear el gráfico de barras
    plt.figure(figsize=(10, 6))
    plt.bar(np.arange(len(cm)), 100 * error_per_class, color='orange')
    plt.xlabel("Clases")
    plt.ylabel("Porcentaje de Error (%)")
    plt.title(title)
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    plt.xticks(np.arange(len(cm)))
    plt.tight_layout()
    plt.show()
