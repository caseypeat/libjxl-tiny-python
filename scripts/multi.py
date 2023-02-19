from encode import jxl_write_multi
from loader import load_images


if __name__ == "__main__":
    filepaths_input = ["./images/1.jpg", "./images/2.jpg"]
    filepaths_output = ["./images/1.jxl", "./images/2.jxl"]

    images = load_images(filepaths_input)

    jxl_write_multi(filepaths_output, images)
