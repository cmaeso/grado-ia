import torch.nn as nn

class MLP(nn.Module):
    def __init__(self, input_size, hidden_size, output_size):
        super(MLP, self).__init__()
        self.model = nn.Sequential(
            nn.Flatten(1, -1),
            nn.Linear(input_size, hidden_size),
            nn.ReLU(),
            nn.Linear(hidden_size, output_size)
        )

    def forward(self, x):
        return self.model(x)


class CNN(nn.Module):
    def __init__(self, output_dim):
        super(CNN, self).__init__()

        # Primer bloque convolucional
        self.conv_block1 = nn.Sequential(
            nn.Conv2d(in_channels=3, out_channels=8, kernel_size=3, stride=2, padding=1),
            nn.BatchNorm2d(8),
            nn.ReLU(),

        )
        # Segundo bloque convolucional
        self.conv_block2 = nn.Sequential(
            nn.Conv2d(in_channels=8, out_channels=64, kernel_size=3, stride=2, padding=1),
            nn.BatchNorm2d(64),
            nn.ReLU(),

        )
        # Tercer bloque convolucional
        self.conv_block3 = nn.Sequential(
            nn.Conv2d(in_channels=64, out_channels=32, kernel_size=3, stride=2, padding=1),
            nn.BatchNorm2d(32),
            nn.ReLU(),

        )
        # Capa de aplanado
        self.flatten = nn.Flatten()

        # Linear para la clasificación
        self.fully_conected = nn.Linear(32 * 4 * 4, output_dim)

    def forward(self, x):
        # Primer bloque convolucional
        x = self.conv_block1(x)

        # Segundo bloque convolucional
        x = self.conv_block2(x)

        # Tercer bloque convolucional
        x = self.conv_block3(x)

        # Aplanar la salida de la última capa convolucional
        x = self.flatten(x)

        # Linear para clasificación
        x = self.fully_conected(x)

        return x
