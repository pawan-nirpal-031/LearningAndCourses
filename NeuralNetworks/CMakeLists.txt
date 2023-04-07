cmake_minimum_required(VERSION 3.0)
project( OpenANN )

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -std=c++14")



add_executable(
    OpenANN
    src/main.cpp
    src/Neuron.cpp
    src/Layer.cpp
    src/Matrix.cpp
    src/NeuralNetwork.cpp
)
