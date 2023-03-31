cmake -DCMAKE_CXX_COMPILER=/home/pnirpal/Workspace/compilers/aocc-compiler-4.0.0/bin/clang++ . 
make
./OpenANN_Aocc
#( find ./ -name '*.cpp' -print0 | xargs -0 cat ) | wc -l