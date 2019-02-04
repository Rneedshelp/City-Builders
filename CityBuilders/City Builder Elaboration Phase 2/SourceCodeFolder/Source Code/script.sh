#!/bin/bash
echo beginning compilation of City Builder
rm *.o
rm *.exe
g++ -Wall -std=c++11 -m64 main.cpp -c -o cityBuilder.o
echo compilation successful. beginning linking
g++ -m64 -o p1.exe cityBuilder.o
echo linking successful. Executing project 1
./p1.exe
echo shell done 
