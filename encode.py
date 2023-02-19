import numpy as np
import cv2
import threading
import multiprocessing

from time import time, sleep

from jxlbinding import encode_image


def jxl_write(filepath, image):
    jxl = encode_image(image)
    jxl.tofile(filepath)


def jxl_write_multi(filepaths, images):
    num_processes = len(images)
    processes = []

    for i in range(num_processes):
        processes.append(multiprocessing.Process(target=jxl_write, args=(filepaths[i], images[i])))

    for p in processes:
        p.start()

    for p in processes:
        p.join()

    while True:
        all_done = True

        for p in processes:
            if p.is_alive():
                all_done = False
        
        if all_done:
            break
        else:
            sleep(0.01)