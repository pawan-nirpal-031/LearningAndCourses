rm -r bin/OpenANN
cmake -DCMAKE_C_COMPILER=gcc .
make
mv OpenANN bin
./bin/OpenANN
#( find ./ -name '*.cpp' -print0 | xargs -0 cat ) | wc -l
# g++ Gradient.cpp -std=c++11 -I/usr/include/python2.7  -I/home/pnirpal/.local/lib/python2.7/site-packages/numpy/core/include/  -lpython2.7
