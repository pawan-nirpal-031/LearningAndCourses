rm OpenANN
cmake -DCMAKE_C_COMPILER=gcc .
make
./OpenANN
#( find ./ -name '*.cpp' -print0 | xargs -0 cat ) | wc -l
