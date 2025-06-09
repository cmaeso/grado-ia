from torch.utils.data import Dataset
from PIL import Image
import pandas as pd
import os

class GTS(Dataset):
    def __init__(self, csv_file, root_dir, transform=None):
        """
        Args:
            csv_file (string): Ruta al archivo CSV con las rutas de las imágenes y etiquetas.
            root_dir (string): Directorio raíz.
            transform (callable, optional): Transformaciones a aplicar sobre las imágenes.
        """
        self.root_dir = root_dir
        self.data = pd.read_csv(os.path.join(root_dir,csv_file))
        self.transform = transform

    def __len__(self):
        return len(self.data)

    def __getitem__(self, idx):
        # Obtener la ruta de la imagen y el ClassId
        img_name = os.path.join(self.root_dir, self.data.iloc[idx, 0])  # La columna 0 es la ruta
        image = Image.open(img_name)
        label = int(self.data.iloc[idx, 1])  # La columna 1 es el ClassId

        # Aplicar transformaciones si se especifican
        if self.transform:
            image = self.transform(image)

        return image, label
