#pragma once
#include "sortingAlgo.h"
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

template <class T>
void HoanVi(T& a, T& b);
void GenerateRandomData(int a[], int n);
void GenerateSortedData(int a[], int n);
void GenerateReverseData(int a[], int n);
void GenerateNearlySortedData(int a[], int n);
void GenerateData(int a[], int n, int dataType);
bool checkNumber(char s[]);
int stringToNumber(char s[]);
void writeFile(const char fileInput[], int a[], int n);
void readFile1(int*& a, int& n, const char fileInput[], bool& rightInput);
void checkAlgorithm1(int*& a, int& n, char algorithm[], const char fileInput[], char outPut[]);
void checkOutput2(int* a, int n, char outPut[], double timeUse, long long countCmp);
void checkInputOrder2(int* a, char inputOrder[], int n);
void checkInputSize2(int*& a, int& n, char inputSize[], char inputOrder[], bool& rightInput);
void checkAlgorithm2(int*& a, int& n, char algorithm[], char inputSize[], char inputOrder[], char outPut[]);
void writeFile3(int i, int a[], int n);
void Output3(int* a, int n, char outPut[], double timeUse, long long countCmp);
void outputOrder3(int i);
void checkInputSize3(int*& a, int& n, char inputSize[], bool& rightInput);
void checkAlgorithm3(int*& a, int& n, char algorithm[], char inputSize[], char outPut[]);
void checkOutput4(int* a, int n, double timeUse1, long long countCmp1, double timeUse2, long long countCmp2);
void readFile4(int*& a, int& n, const char fileInput[], bool& rightInput);
char* nameAlgorithm(char algorithm[]);
void callAlgorithm(char algorithm[], double& timeUse, long long& countCmp, int*& a, int n);
void checkAlgorithm4(int*& a, int& n, char algorithm1[], char algorithm2[], const char fileInput[]);
void checkInputSize5(int*& a, int& n, char inputSize[], char inputOrder[], bool& rightInput);
void checkAlgorithm5(int*& a, int& n, char algorithm1[], char algorithm2[], char inputSize[], char inputOrder[]);
