# libjxl-tiny-python

Python binding of libjxl-tiny using pybind11

## Setup

`conda create -n jxl python=3.9`

`conda activate jxl`

`pip install opencv-python`

`conda install -c conda-forge libstdcxx-ng=12`

`git clone https://github.com/caseypeat/libjxl-tiny-python.git --recursive --shallow-submodules`

`pip install -e ./`


## Run

`python -m scripts.single`

`python -m scripts.multi`