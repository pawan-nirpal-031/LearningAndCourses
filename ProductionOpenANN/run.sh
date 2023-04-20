cmake -DCMAKE_C_COMPILER=gcc .
make
mv CoreANNTrain bin
echo $"Running program..."
./bin/CoreANNTrain config/training.json
