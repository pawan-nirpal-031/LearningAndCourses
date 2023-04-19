cmake_minimum_required(VERSION 3.0)
project( CoreANN )

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -pthread -std=c++14")



add_executable(
    CoreANN
    src/driver.cpp
    src/Neuron.cpp
    src/Matrix.cpp
    src/Layer.cpp
    src/utils/Math.cpp
    src/NeuralNetwork.cpp
    src/Backpropagation.cpp 
    src/FeedForward.cpp
    src/SetErrorsForNetwork.cpp
    src/TrainNetwork.cpp
)
