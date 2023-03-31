cmake -DCMAKE_CXX_COMPILER=clang++ . 
make
./OpenANN_Clang
#( find ./ -name '*.cpp' -print0 | xargs -0 cat ) | wc -l