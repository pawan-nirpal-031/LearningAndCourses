cmake -DCMAKE_C_COMPILER=gcc .
make
mv CoreANN bin
echo $"Running program..."
./bin/CoreANN