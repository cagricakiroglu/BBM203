#pragma once
#include <cstdio>
#include <iostream>
#include <stdlib.h>
#include<fstream>
#include <sstream>
using namespace std;


int directionDecider(int totalOfThisMatrix);
// int* CoreChanger(int* CoreArray,int direction ,int numOfKeyRowAndColumnofMatrix ,int row,int column);
void printerFunc(int rowP, int colP, int total,int printCounter,stringstream *outputstring,ofstream &myfile);
int** read_makeGrid(int row, int column);
void deleteArray(int** dynamicArray,int row);
int** getKeyMatrix(int num,stringstream &keysmatrix);
void gameFunc(int** dynamicArray,int** key_dynamicArray,int* Core2Array,int num,int row , int column ,int printCounter,stringstream *outputstring,ofstream &myfile);