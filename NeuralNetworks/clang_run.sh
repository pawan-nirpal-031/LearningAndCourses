cmake -DCMAKE_CXX_COMPILER=clang++ . 
make
mv -r OpenANN_Clang bin/
./bin/OpenANN_Clang
#( find ./ -name '*.cpp' -print0 | xargs -0 cat ) | wc -l