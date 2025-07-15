# @brief Tracker
# @author Jose M. Buenaposada (josemiguel.buenaposada@urjc.es)
# @date 2025
#

import numpy as np
import cv2
import os
from src.preprocessor import CharImgPreprocessor


class OCRTrainingDataLoader:
    """
    Class to read cropped images from the OCR training data generated on folders (one for each char) and return  flattened.
    """

    def __init__(self, char_size=(30,30)):
        self.name = 'URJC-OCR-TRAIN'
        self.char_size = char_size
        self.preprocessor = CharImgPreprocessor()


    def load(self, data_path):
        """
         Given a directory where dataset is, read all the images on each folder (= char).

         :return flattened images and labels
        """
        images = dict()
        X, y = [], []


        for root, dirs, files in os.walk(data_path):
            for name in sorted(dirs):
                print("====> Loading ", name, " images.")
                images[name] = self.__load_images(root, name, self.char_size)
                """for img in images:
                    X.append(img.flatten())
                    y.append(name)"""


        return images # np.array(X), np.array(y)
    

    def __load_images(self, data_path, char_data_dir, chars_size, show_results=False):
        """
         Given a directory where the data from a single class of char is process and crop the images.

         :return images is a list of images
        """
        images = []
        for i, name in enumerate(sorted(os.listdir(os.path.join(data_path, char_data_dir)))):
            I = cv2.imread(os.path.join(data_path, char_data_dir, name), 0)
            if not type(I) is np.ndarray:  # file it is not an image.
                print("*** ERROR: Couldn't read image " + name)
                continue

            # Pre-process images (detect putative chars in the training images as done in detect_putative_chars)
            preprocessor = CharImgPreprocessor()
            r = preprocessor.process_image(I)
            if r is None:
                print("*** ERROR: Couldn't process image " + name)
                continue

            x, y, w, h = r
            original_size = max(w, h)

            if (w==1) or (h==1):
                continue

            # Enlarge rectangle a percentage p on every side
            p = 0.1
            #x = max(int(round(r[0] - r[2] * p)), 0)
            y = max(int(round(r[1] - r[3] * p)), 0)
            #w = int(round(r[2] * (1. + 2.0 * p)))
            h = int(round(r[3] * (1. + 2.0 * p)))
            r = (x, y, w, h)
            new_size = max(w, h)

            if (original_size < 10) or ():
                continue

            if (x < 0) or (y < 0) or (x + w >= I.shape[1]) or (y + h >= I.shape[0]):
                continue

            Icrop = np.zeros((new_size, new_size), dtype=np.uint8)
            x_0 = int((new_size - w) / 2)
            y_0 = int((new_size - h) / 2)

            Icrop[y_0:y_0 + h, x_0:x_0 + w] = I[y:y + h, x:x + w]
            Iresize = cv2.resize(Icrop, chars_size, interpolation=cv2.INTER_NEAREST)
            images.append(Iresize)

            # Plot results
            if show_results and (i==1):
                I2 = cv2.cvtColor(I, cv2.COLOR_GRAY2BGR)
                x, y, w, h = r
                cv2.rectangle(I2, (x, y), (x + w - 1, y + h - 1), (0, 255, 0), 1)
                cv2.imshow('Letters', I2)
                cv2.imshow('crop', cv2.resize(Icrop, None, fx=4.0, fy=4.0))
                cv2.imshow('resize', cv2.resize(Iresize, None, fx=4.0, fy=4.0))
                cv2.waitKey(500)

        return images

    def show_image_examples(self, images, num_imgs_per_class=5):
        Iexamples = None
        for key in images:
            examples = [img for i, img in enumerate(images[key]) if (i < num_imgs_per_class)]

            Irow = None
            num_imgs = 0
            for e in examples:
                if Irow is None:
                    Irow = e
                else:
                    Irow = np.hstack((Irow, e))
                num_imgs += 1

                if num_imgs == num_imgs_per_class:
                    break

            if Iexamples is None:
                Iexamples = Irow
            else:
                Iexamples = np.vstack((Iexamples, Irow))

        return Iexamples
