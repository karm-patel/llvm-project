## Preprocessing
git reset --hard f08d86fc7f4479d5f44d75c720201334682075b8

## Building
https://llvm.org/docs/CMake.html

cmake -j 12 -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ../llvm
sudo make -j 12

sudo cmake --build . --target install

make check-all # installed opt locally

## Genarte bitcode .bc file
clang -emit-llvm -c hello.c

## General commands
opt --print-passes # print all available passes
opt -load build/lib/LLVMHello.so -hello -enable-new-pm=0 hello.bc > /dev/null # To run c file through pass

Creat IR:
clang -emit-llvm -S hello.c 