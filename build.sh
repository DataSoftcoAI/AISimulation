#install clang,opencv
xcode-select --install
#build:
clang++ ai_simulator.cpp -o ai_simulator -std=c++11
# or
clang++ ai_simulator.cpp -o ai_simulator -std=c++11 `pkg-config --cflags --libs opencv4`
#run:
./ai_simulator

# python:
pip install -r requirements.txt

# or .venv:
python3 -m venv .venv
source .venv/bin/activate

python -m pip show tensorflow tensorflow-hub
# tensorflow 2.18.0
pip install tensorflow
# tensorflow-hub 0.16.1
pip install tensorflow-hub

# on macOS: conda or miniconad
brew install miniforge
conda create -n tf_env tensorflow
conda activate tf_env
