from encode import jxl_write
from loader import load_image


if __name__ == "__main__":
    filepath_input = "./images/1.jpg"
    filepath_output = "./images/1.jxl"

    image = load_image(filepath_input)

    jxl_write(filepath_output, image)
