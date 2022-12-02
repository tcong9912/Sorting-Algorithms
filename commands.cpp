#include "commands.h"


template <class T>
void HoanVi(T& a, T& b)
{
	T x = a;
	a = b;
	b = x;
}

//-------------------------------------------------

// Hàm phát sinh mảng dữ liệu ngẫu nhiên
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự tăng dần
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}

// Hàm phát sinh mảng dữ liệu có thứ tự ngược (giảm dần)
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}

// Hàm phát sinh mảng dữ liệu gần như có thứ tự
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}

void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	// ngẫu nhiên
		GenerateRandomData(a, n);
		break;
	case 1:	// có thứ tự
		GenerateSortedData(a, n);
		break;
	case 2:	// có thứ tự ngược
		GenerateReverseData(a, n);
		break;
	case 3:	// gần như có thứ tự
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}


bool checkNumber(char s[])
{
	int len = strlen(s);
	bool isNumber = 0;
	for (int i = 0; i < len; i++)
	{
		if (s[i] - '0' > 9 || s[i] - '0' < 0)
		{
			return 0;
		}
	}
	return 1;
}

int stringToNumber(char s[])
{
	int len = strlen(s);
	bool isNumber = 0;
	int n = 0;
	for (int i = len - 1; i >= 0; i--)
	{
		n += (int)(s[i] - '0') * pow(10, len - 1 - i);
	}
	return n;
}


void writeFile(const char fileInput[], int a[], int n)
{
	FILE* f = fopen(fileInput, "wt");
	if (f == NULL)
	{
		return;
	}

	fprintf(f, "%d\n", n);
	for (int i = 0; i < n; i++)
	{
		fprintf(f, "%d ", a[i]);
	}
	fclose(f);
}


void readFile1(int*& a, int& n, const char fileInput[], bool& rightInput)
{
	FILE* f;

	f = fopen(fileInput, "rt");

	if (f == NULL)
	{
		cout << "File not exist\n";
		rightInput = 0;
		return;
	}
	else
	{
		cout << "Input file: " << fileInput << endl;
		fscanf(f, "%d\n", &n);

		a = new int[n];

		for (int i = 0; i < n; i++)
		{
			fscanf(f, "%d ", &a[i]);
		}
		fclose(f);
		cout << "Input size: " << n << endl;
	}
	rightInput = 1;
}

void checkAlgorithm1(int*& a, int& n, char algorithm[], const char fileInput[], char outPut[])
{
	bool rightInput = 0;
	cout << "Algorithm: " << nameAlgorithm(algorithm) << endl;
	readFile1(a, n, fileInput, rightInput);
	if (rightInput == 1)
	{
		double timeUse;
		long long countCmp = 0;
		callAlgorithm(algorithm, timeUse, countCmp, a, n);
		checkOutput2(a, n, outPut, timeUse, countCmp);
		writeFile("output.txt", a, n);
	}
	delete[]a;
}


void checkOutput2(int* a, int n, char outPut[], double timeUse, long long countCmp)
{
	if (strcmp(outPut, "-time") == 0)// check output
	{
		cout << "-------------------------------\n";
		cout << "Running time(msec): " << timeUse << endl;
	}
	else if (strcmp(outPut, "-comp") == 0)
	{
		cout << "-------------------------------\n";
		cout << "Comparisions: " << countCmp << endl;
	}
	else if (strcmp(outPut, "-both") == 0)
	{
		cout << "-------------------------------\n";
		cout << "Running time(msec): " << timeUse << endl;
		cout << "Comparisions: " << countCmp << endl;
	}
	else
	{
		cout << "Please check output parameters agrument\n";
	}
}

void checkInputOrder2(int* a, char inputOrder[], int n)
{
	if (strcmp(inputOrder, "-rand") == 0)
	{
		GenerateData(a, n, 0);
		cout << "Input Order: randomized data\n";
	}
	else if (strcmp(inputOrder, "-sorted") == 0)
	{
		GenerateData(a, n, 1);
		cout << "Input Order: sorted data\n";
	}
	else if (strcmp(inputOrder, "-rev") == 0)
	{
		GenerateData(a, n, 2);
		cout << "Input Order:  reverse sorted data\n";
	}
	else if (strcmp(inputOrder, "-nsorted") == 0)
	{
		GenerateData(a, n, 3);
		cout << "Input Order: nearly sorted data\n";
	}
	else
	{
		cout << "Please check input order agrument\n";
	}
}

void checkInputSize2(int*& a, int& n, char inputSize[], char inputOrder[], bool& rightInput)
{
	if (checkNumber(inputSize) == 1)
	{
		n = stringToNumber(inputSize);
		a = new int[n];
		cout << "Input Size: " << n << endl;
		checkInputOrder2(a, inputOrder, n);
		rightInput = 1;
	}
	else
	{
		cout << "Please check input size agrument\n";
		rightInput = 0;
	}
}

void checkAlgorithm2(int*& a, int& n, char algorithm[], char inputSize[], char inputOrder[], char outPut[])
{
	bool rightInput = 0;
	cout << "Algorithm: " << nameAlgorithm(algorithm) << endl;
	checkInputSize2(a, n, inputSize, inputOrder, rightInput);
	writeFile("input.txt", a, n);
	if (rightInput == 1)
	{
		double timeUse;
		long long countCmp = 0;
		callAlgorithm(algorithm, timeUse, countCmp, a, n);
		checkOutput2(a, n, outPut, timeUse, countCmp);
		writeFile("output.txt", a, n);
	}
	delete[]a;
}

void writeFile3(int i, int a[], int n)
{
	switch (i)
	{
	case 0:
	{
		writeFile("input_1.txt", a, n);// rand
	}
	case 1:
	{
		writeFile("input_3.txt", a, n);//sort
	}
	case 2:
	{
		writeFile("input_4.txt", a, n);//nsort
	}
	case 3:
	{
		writeFile("input_2.txt", a, n);// nsort
	}
	}
}
void Output3(int* a, int n, char outPut[], double timeUse, long long countCmp)
{
	if (strcmp(outPut, "-time") == 0)// check output
	{
		cout << "-------------------------------\n";
		cout << "Running time(msec): " << timeUse << endl;
	}
	else if (strcmp(outPut, "-comp") == 0)
	{
		cout << "-------------------------------\n";
		cout << "Comparisions: " << countCmp << endl;
	}
	else if (strcmp(outPut, "-both") == 0)
	{
		cout << "-------------------------------\n";
		cout << "Running time(msec): " << timeUse << endl;
		cout << "Comparisions: " << countCmp << endl;
	}
	else
	{
		cout << "Please check output parameters agrument\n";
	}
}

void outputOrder3(int i)
{
	switch (i)
	{
	case 0:
	{
		cout << endl;
		cout << "Input Order: randomized data\n";
		break;
	}
	case 1:
	{
		cout << endl;
		cout << "Input Order: sorted data\n";
		break;
	}
	case 2:
	{
		cout << endl;
		cout << "Input Order:  reverse sorted data\n";
		break;
	}
	case 3:
	{
		cout << endl;
		cout << "Input Order: nearly sorted data\n";
		break;
	}
	}
}

void checkInputSize3(int*& a, int& n, char inputSize[], bool& rightInput)
{
	if (checkNumber(inputSize) == 1)
	{
		n = stringToNumber(inputSize);
		a = new int[n];
		cout << "Input Size: " << n << endl;
		rightInput = 1;
	}
	else
	{
		cout << "Please check input size agrument\n";
		rightInput = 0;
	}
}

void checkAlgorithm3(int*& a, int& n, char algorithm[], char inputSize[], char outPut[])
{
	bool rightInput = 0;
	cout << "Algorithm: " << nameAlgorithm(algorithm) << endl;
	checkInputSize3(a, n, inputSize, rightInput);
	if (rightInput == 1)
	{
		for (int i = 0; i < 4; i++)
		{
			long long countCmp = 0;
			double timeUse;
			GenerateData(a, n, i);
			writeFile3(i, a, n);
			outputOrder3(i);
			callAlgorithm(algorithm, timeUse, countCmp, a, n);
			Output3(a, n, outPut, timeUse, countCmp);
		}
	}
	delete[]a;
}

void checkOutput4(int* a, int n, double timeUse1, long long countCmp1, double timeUse2, long long countCmp2)
{
	cout << "-------------------------------\n";
	cout << "Running time(msec): " << timeUse1 << " | " << timeUse2 << endl;
	cout << "Comparisions: " << countCmp1 << " | " << countCmp2 << endl;
}

void readFile4(int*& a, int& n, const char fileInput[], bool& rightInput)
{
	FILE* f;

	f = fopen(fileInput, "rt");

	if (f == NULL)
	{
		cout << "File not exist\n";
		rightInput = 0;
		return;
	}
	else
	{
		cout << "Input file: " << fileInput << endl;
		fscanf(f, "%d\n", &n);

		a = new int[n];

		for (int i = 0; i < n; i++)
		{
			fscanf(f, "%d ", &a[i]);
		}
		fclose(f);
		cout << "Input size: " << n << endl;
	}
	rightInput = 1;
}

char* nameAlgorithm(char algorithm[])
{
	char* s = new char[100];
	if (strcmp(algorithm, "heap-sort") == 0)
	{
		s = strcpy(s, "Heap Sort");
		s[10] = '\0';
	}
	else if (strcmp(algorithm, "merge-sort") == 0)
	{
		s = strcpy(s, "Merge Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "radix-sort") == 0)
	{
		s = strcpy(s, "Radix Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "counting-sort") == 0)
	{
		s = strcpy(s, "Counting Sort");
		s[14] = '\0';
	}
	else if (strcmp(algorithm, "shaker-sort") == 0)
	{
		s = strcpy(s, "Shaker Sort");
		s[12] = '\0';
	}
	else if (strcmp(algorithm, "quick-sort") == 0)
	{
		s = strcpy(s, "Quick Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "shell-sort") == 0)
	{
		s = strcpy(s, "Shell Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "insertion-sort") == 0)
	{
		s = strcpy(s, "Insertion Sort");
		s[15] = '\0';
	}
	else if (strcmp(algorithm, "flash-sort") == 0)
	{
		s = strcpy(s, "Flash Sort");
		s[11] = '\0';
	}
	else if (strcmp(algorithm, "selection-sort") == 0)
	{
		s = strcpy(s, "Selection Sort");
		s[15] = '\0';
	}
	else if (strcmp(algorithm, "bubble-sort") == 0)
	{
		s = strcpy(s, "Bubble Sort");
		s[12] = '\0';
	}
	else
	{
		s = strcpy(s, "Wrong algorithm protoptype please check again!!!");
		s[49] = '\0';
	}
	return s;
}

void callAlgorithm(char algorithm[], double& timeUse, long long& countCmp, int*& a, int n)
{
	clock_t start, end;
	if (strcmp(algorithm, "heap-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		heapSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countHeapSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "merge-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		mergeSort(a, 0, n - 1);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countMergeSort(b, 0, n - 1, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "radix-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		radixSort(a, n, log10(getMax(a, n)) + 1);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countRadixSort(b, n, log10(getMax(a, n)) + 1, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "counting-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		countingSort(a, n, getMin(a, n), getMax(a, n));
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countCountingSort(b, n, countGetMin(b, n, countCmp), countGetMax(b, n, countCmp), countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "shaker-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		shakerSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countShakerSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "quick-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		quickSort(a, 0, n - 1);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countQuickSort(b, 0, n - 1, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "shell-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		shellSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countShellSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "insertion-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		insertionSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countInsertionSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "flash-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		flashSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countFlashSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "selection-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		selectionSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countSelectionSort(b, n, countCmp);
		delete[]b;
	}
	else if (strcmp(algorithm, "bubble-sort") == 0)
	{
		int* b = new int[n];
		copy(a, a + n, b);
		start = clock();
		bubbleSort(a, n);
		end = clock();
		timeUse = (double)(end - start) / (CLOCKS_PER_SEC / 1000);
		countBubbleSort(b, n, countCmp);
		delete[]b;
	}
	else
	{
		cout << "Please check algorithm name agrument\n";
	}
}

void checkAlgorithm4(int*& a, int& n, char algorithm1[], char algorithm2[], const char fileInput[])
{
	bool rightInput = 0;
	if (strcmp(algorithm1, algorithm2) == 0)
	{
		cout << "Same algorithm please input again\n";
	}
	else
	{
		cout << "Algorithm: ";
		cout << nameAlgorithm(algorithm1) << " | " << nameAlgorithm(algorithm2) << endl;
		readFile4(a, n, fileInput, rightInput);
		if (rightInput == 1)
		{
			double timeUse1, timeUse2;
			long long countCmp1 = 0;
			long long countCmp2 = 0;
			callAlgorithm(algorithm1, timeUse1, countCmp1, a, n);
			callAlgorithm(algorithm2, timeUse2, countCmp2, a, n);
			checkOutput4(a, n, timeUse1, countCmp1, timeUse2, countCmp2);
		}
	}
}

void checkInputSize5(int*& a, int& n, char inputSize[], char inputOrder[], bool& rightInput)
{
	if (checkNumber(inputSize) == 1)
	{
		rightInput = 1;
		n = stringToNumber(inputSize);
		a = new int[n];
		cout << "Input Size: " << n << endl;
		checkInputOrder2(a, inputOrder, n);
	}
	else
	{
		cout << "Please check input size agrument\n";
		rightInput = 0;
	}
}

void checkAlgorithm5(int*& a, int& n, char algorithm1[], char algorithm2[], char inputSize[], char inputOrder[])
{
	bool rightInput = 0;
	if (strcmp(algorithm1, algorithm2) == 0)
	{
		cout << "Same algorithm please input again\n";
	}
	else
	{
		cout << "Algorithm: ";
		cout << nameAlgorithm(algorithm1) << " | " << nameAlgorithm(algorithm2) << endl;
		checkInputSize5(a, n, inputSize, inputOrder, rightInput);
		writeFile("input.txt", a, n);
		if (rightInput == 1)
		{
			double timeUse1, timeUse2;
			long long countCmp1 = 0;
			long long countCmp2 = 0;
			int* b = new int[n];
			copy(a, a + n, b);
			callAlgorithm(algorithm1, timeUse1, countCmp1, a, n);
			callAlgorithm(algorithm2, timeUse2, countCmp2, b, n);
			checkOutput4(a, n, timeUse1, countCmp1, timeUse2, countCmp2);
		}
	}
}
