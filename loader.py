import numpy as np
import cv2


def load_image(filepath):
    image = cv2.imread(filepath)
    image = cv2.cvtColor(image, cv2.COLOR_BGR2RGB)
    image = image[::-1, :, :]
    image = image.astype(np.float32) / 255
    return image


def load_images(filepaths):
    images = []
    for filepath in filepaths:
        image = load_image(filepath)
        images.append(image)
    return images