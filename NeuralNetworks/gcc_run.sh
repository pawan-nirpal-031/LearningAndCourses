rm -r bin/OpenANN
cmake -DCMAKE_C_COMPILER=gcc .
make
mv OpenANN bin
./bin/OpenANN
#( find ./ -name '*.cpp' -print0 | xargs -0 cat ) | wc -l
