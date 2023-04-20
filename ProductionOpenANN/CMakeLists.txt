cmake_minimum_required(VERSION 3.0)
project( CoreANN )

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fopenmp -O3 -flto -pthread -std=c++14")

add_definitions (
  -DOATPP_DISABLE_LOGD
)

add_executable(
    CoreANNTrain
    src/Neuron.cpp
    src/Matrix.cpp
    src/Layer.cpp
    src/utils/Math.cpp
    src/NeuralNetwork.cpp
    src/Backpropagation.cpp 
    src/FeedForward.cpp
    src/SetErrorsForNetwork.cpp
    src/TrainNetwork.cpp
    src/utils/DataManager.cpp
)
