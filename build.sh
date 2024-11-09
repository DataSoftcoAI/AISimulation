#install clang,opencv
xcode-select --install
#build:
clang++ ai_simulator.cpp -o ai_simulator -std=c++11
# or
clang++ ai_simulator.cpp -o ai_simulator -std=c++11 `pkg-config --cflags --libs opencv4`
#run:
./ai_simulator
