#include "sortingAlgo.h"


void countBubbleSort(int arr[], int n, long long& countCmp)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; ++countCmp, i < n - 1; i++) {
		haveSwap = false;
		for (j = 0; ++countCmp, j < n - i - 1; j++) {
			if (++countCmp && arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				haveSwap = true;
			}
		}
		if (++countCmp && haveSwap == false) {
			break;
		}
	}
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool haveSwap = false;
	for (i = 0; i < n - 1; i++) {
		haveSwap = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(arr[j], arr[j + 1]);
				haveSwap = true;
			}
		}
		if (haveSwap == false) {
			break;
		}
	}
}


void shellSort(int a[], int n)
{
	for (size_t gap = n / 2; gap > 0; gap /= 2)
	{
		for (size_t i = gap; i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (; j >= gap && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}

	}
}

void countShellSort(int a[], int n, long long& c)
{
	for (size_t gap = n / 2; ++c, gap > 0; gap /= 2)
	{
		for (size_t i = gap; ++c, i < n; i++)
		{
			int temp = a[i];
			int j = i;
			for (; ++c && j >= gap && ++c && a[j - gap] > temp; j -= gap)
			{
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}


void insertionSort(int a[], int n)
{
	for (int i = 1; i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while (a[k] > key && k >= 0)
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}

void countInsertionSort(int a[], int n, long long& c)
{
	for (int i = 1; ++c, i < n; i++)
	{
		int k = i - 1;
		int key = a[i];
		while ((++c && a[k] > key) && (++c && k >= 0))
		{
			a[k + 1] = a[k];
			k--;
		}
		a[k + 1] = key;
	}
}


void countShakerSort(int a[], int n, long long& c)
{
	int l = 0, r = n - 1, k = 0;
	bool sw = 0;
	for (size_t i = l; ++c, i <= r; i++)
	{
		sw = 0;
		for (size_t j = l; ++c, j < r; j++)
		{
			if (++c && a[j] > a[j + 1])
			{
				sw = 1;
				HoanVi(a[j], a[j + 1]);
				k = j;
			}
		}
		if (++c && !sw) return;
		r = k;
		sw = 0;
		for (size_t j = r; ++c, j > l; j--)
		{
			if (++c && a[j] < a[j - 1])
			{
				sw = 1;
				HoanVi(a[j], a[j - 1]);
				k = j;
			}
		}
		if (++c && !sw) return;
		l = k;
	}
}

void shakerSort(int a[], int n)
{
	int l = 0, r = n - 1, k = 0;
	bool sw = 0;
	for (size_t i = l; i <= r; i++)
	{
		sw = 0;
		for (size_t j = l; j < r; j++)
		{
			if (a[j] > a[j + 1])
			{
				sw = 1;
				HoanVi(a[j], a[j + 1]);
				k = j;
			}
		}
		if (!sw) return;
		r = k;
		sw = 0;
		for (size_t j = r; j > l; j--)
		{
			if (a[j] < a[j - 1])
			{
				sw = 1;
				HoanVi(a[j], a[j - 1]);
				k = j;
			}
		}
		if (!sw) return;
		l = k;
	}
}


int findIndexofLargest(int a[], int size)
{
	int largest = 0;
	for (int i = 0; i <= size; i++)
	{
		if (a[i] > a[largest])
		{
			largest = i;
		}
	}
	return largest;
}

int countFindIndexofLargest(int a[], int size, long long& countCmp)
{
	int largest = 0;
	for (int i = 0; ++countCmp, i <= size; i++)
	{
		if (++countCmp && a[i] > a[largest])
		{
			largest = i;
		}
	}
	return largest;
}

void selectionSort(int a[], int n)
{
	for (int i = n - 1; i > 0; i--)
	{
		int largest = findIndexofLargest(a, i);
		swap(a[largest], a[i]);
	}
}

void countSelectionSort(int a[], int n, long long& countCmp)
{
	for (int i = n - 1; ++countCmp, i > 0; i--)
	{
		int largest = countFindIndexofLargest(a, i, countCmp);
		swap(a[largest], a[i]);
	}
}


int countGetMax(int* a, int n, long long& countCmp)
{
	int max = a[0];
	for (int i = 0; ++countCmp, i < n; i++)
	{
		if (++countCmp && a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

int getMax(int* a, int n)
{
	int max = a[0];
	for (int i = 0; i < n; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}
	return max;
}

void countSortDigit(int*& a, int n, int d, long long& countCmp)
{
	int count[10] = { {0} };
	int* outPut = new int[n];

	for (int i = 0; ++countCmp, i < n; i++)
	{
		count[a[i] / d % 10]++;
	}
	//--------------------------------

	for (int i = 1; ++countCmp, i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	//--------------------------------

	for (int i = n - 1; ++countCmp, i >= 0; i--)
	{
		outPut[count[a[i] / d % 10] - 1] = a[i];
		count[a[i] / d % 10]--;
	}
	//--------------------------------

	for (int i = 0; ++countCmp, i < n; i++)
	{
		a[i] = outPut[i];
	}
}

void SortDigit(int*& a, int n, int d)
{
	int count[10] = { {0} };
	int* outPut = new int[n];

	for (int i = 0; i < n; i++)
	{
		count[a[i] / d % 10]++;
	}
	//--------------------------------

	for (int i = 1; i < 10; i++)
	{
		count[i] += count[i - 1];
	}
	//--------------------------------

	for (int i = n - 1; i >= 0; i--)
	{
		outPut[count[a[i] / d % 10] - 1] = a[i];
		count[a[i] / d % 10]--;
	}
	//--------------------------------

	for (int i = 0; i < n; i++)
	{
		a[i] = outPut[i];
	}
}

void countRadixSort(int*& a, int n, int d, long long& countCmp)
{
	int m = countGetMax(a, n, countCmp);

	for (int i = 0; ++countCmp, i < d; i++)
	{
		countSortDigit(a, n, pow(10, i), countCmp);
	}
}

void radixSort(int*& a, int n, int d)
{
	int m = getMax(a, n);

	for (int i = 0; i < d; i++)
	{
		SortDigit(a, n, pow(10, i));
	}
}


int Median(int a[], int l, int r)
{
	int mid = (l + r) / 2;
	if (a[r] < a[l])
	{
		HoanVi(a[l], a[r]);
	}
	if (a[mid] < a[l])
	{
		HoanVi(a[l], a[mid]);
	}
	if (a[r] < a[mid])
	{
		HoanVi(a[mid], a[r]);
	}
	return mid;
}

int countMedian(int a[], int l, int r, long long& countCmp)
{
	int mid = (l + r) / 2;
	if (++countCmp && a[r] < a[l])
	{
		HoanVi(a[l], a[r]);
	}
	if (++countCmp && a[mid] < a[l])
	{
		HoanVi(a[l], a[mid]);
	}
	if (++countCmp && a[r] < a[mid])
	{
		HoanVi(a[mid], a[r]);
	}
	return mid;
}
int patrition(int a[], int l, int r)
{
	int l1 = l, fu = l + 1, p = l;
	while (fu <= r)
	{
		if (a[fu] < a[p])
		{
			HoanVi(a[fu], a[++l1]);
		}
		fu++;
	}
	HoanVi(a[l1], a[p]);
	p = l1;
	return p;
}

int countPatrition(int a[], int l, int r, long long& c)
{
	int l1 = l, fu = l + 1, p = l;
	while (++c && fu <= r)
	{
		if (++c && a[fu] < a[p])
		{
			HoanVi(a[fu], a[++l1]);
		}
		fu++;
	}
	HoanVi(a[l1], a[p]);
	p = l1;
	return p;
}

void quickSort(int a[], int l, int r)
{
	if (l < r)
	{
		HoanVi(a[l], a[Median(a, l, r)]);
		int p = patrition(a, l, r);
		quickSort(a, l, p - 1);
		quickSort(a, p + 1, r);
	}
}

void countQuickSort(int a[], int l, int r, long long& c)
{
	if (++c && l < r)
	{
		HoanVi(a[l], a[countMedian(a, l, r, c)]);
		int p = countPatrition(a, l, r, c);
		countQuickSort(a, l, p - 1, c);
		countQuickSort(a, p + 1, r, c);
	}
}


void countMerge(int*& a, int left, int mid, int right, long long& countCmp)
{
	int n = right - left + 1;
	int* b = new int[n];

	int k = 0;
	int i = left; // chay tu left toi mid
	int j = mid + 1;// chay tu mid + 1 toi right

	while (++countCmp && j <= right && ++countCmp && i <= mid)// vong lap xet khi chua chay het nua mang
	{
		if (++countCmp && a[i] <= a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else
		{
			b[k] = a[j];
			k++;
			j++;
		}
	}
	while (++countCmp && j <= right && ++countCmp && i > mid)// neu mang dau da xong truoc
	{
		b[k] = a[j];
		k++;
		j++;
	}
	while (++countCmp && i <= mid && ++countCmp && j > right)// neu mang sau da xong truoc
	{
		b[k] = a[i];
		k++;
		i++;
	}

	i = left;
	for (int m = 0; ++countCmp, m < n; m++)
	{
		a[i] = b[m];
		i++;
	}
	delete[]b;
}

void Merge(int*& a, int left, int mid, int right)
{
	int n = right - left + 1;
	int* b = new int[n];

	int k = 0;
	int i = left; // chay tu left toi mid
	int j = mid + 1;// chay tu mid + 1 toi right

	while (j <= right && i <= mid)// vong lap xet khi chua chay het nua mang
	{
		if (a[i] <= a[j])
		{
			b[k] = a[i];
			k++;
			i++;
		}
		else
		{
			b[k] = a[j];
			k++;
			j++;
		}
	}
	while (j <= right && i > mid)// neu mang dau da xong truoc
	{
		b[k] = a[j];
		k++;
		j++;
	}
	while (i <= mid && j > right)// neu mang sau da xong truoc
	{
		b[k] = a[i];
		k++;
		i++;
	}

	i = left;
	for (int m = 0; m < n; m++)
	{
		a[i] = b[m];
		i++;
	}
}

void countMergeSort(int*& a, int left, int right, long long& countCmp)
{
	if (++countCmp && left < right)
	{
		int mid = (left + right) / 2;
		countMergeSort(a, left, mid, countCmp);
		countMergeSort(a, mid + 1, right, countCmp);
		countMerge(a, left, mid, right, countCmp);
	}
}

void mergeSort(int*& a, int left, int right)
{
	if (left < right)
	{
		int mid = (left + right) / 2;
		mergeSort(a, left, mid);
		mergeSort(a, mid + 1, right);
		Merge(a, left, mid, right);
	}
}


void swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void countHeapRebuild(int*& a, int k, int n, long long& countCmp)
{
	bool isHeap = 0;
	int j;
	while (++countCmp && isHeap == 0 && ++countCmp && 2 * k + 1 < n)
	{
		j = 2 * k + 1;
		if (++countCmp && j < n - 1)
		{
			if (a[j] < a[j + 1])
			{
				j++;
			}
		}
		if (++countCmp && a[k] >= a[j])
		{
			isHeap = 1;
		}
		else
		{
			swap(a[k], a[j]);
			k = j;
		}
	}
}

void heapRebuild(int*& a, int k, int n)
{
	bool isHeap = 0;
	int j;
	while (isHeap == 0 && 2 * k + 1 < n)
	{
		j = 2 * k + 1;
		if (j < n - 1)
		{
			if (a[j] < a[j + 1])
			{
				j++;
			}
		}
		if (a[k] >= a[j])
		{
			isHeap = 1;
		}
		else
		{
			swap(a[k], a[j]);
			k = j;
		}
	}
}

void countHeapConstruct(int*& a, int n, long long& countCmp)
{
	int index = (n - 1) / 2;

	while (++countCmp && index >= 0)
	{
		countHeapRebuild(a, index, n, countCmp);
		index--;
	}
}


void heapConstruct(int*& a, int n)
{
	int index = (n - 1) / 2;

	while (index >= 0)
	{
		heapRebuild(a, index, n);
		index--;
	}
}

void countHeapSort(int*& a, int n, long long& countCmp)
{
	countHeapConstruct(a, n, countCmp);
	for (int i = n - 1; ++countCmp, i > 0; i--)
	{
		swap(a[0], a[i]);
		countHeapRebuild(a, 0, i, countCmp);
	}
}

void heapSort(int*& a, int n)
{
	heapConstruct(a, n);
	for (int i = n - 1; i > 0; i--)
	{
		swap(a[0], a[i]);
		heapRebuild(a, 0, i);
	}
}


void flashSort(int a[], int n) {
	int minVal = a[0], maxIdx = 0;
	int buckets = int(0.45 * n);
	int* l = new int[buckets];
	for (size_t i = 0; i < buckets; i++)
	{
		l[i] = 0;
	}
	for (size_t i = 1; i < n; i++)
	{
		if (a[i] < minVal) minVal = a[i];
		if (a[i] > a[maxIdx]) maxIdx = i;
	}
	if (a[maxIdx] == minVal) {
		delete[]l;
		return;
	}
	double c1 = (double)(buckets - 1) / (a[maxIdx] - minVal);
	for (size_t i = 0; i < n; i++)
	{
		int bucketIdx = int(c1 * (a[i] - minVal));
		l[bucketIdx]++;
	}
	for (size_t i = 1; i < buckets; i++)
	{
		l[i] += l[i - 1];
	}
	HoanVi(a[maxIdx], a[0]);
	int nmove = 0;
	int j = 0;
	int k = buckets - 1;
	int flash;
	while (nmove < n - 1)
	{
		while (j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (k < 0) break;
		while (j != l[k])
		{
			k = int(c1 * (flash - minVal));
			--l[k];
			HoanVi(flash, a[l[k]]);
			++nmove;
		}
	}
	delete[]l;
	insertionSort(a, n);
}

void countFlashSort(int a[], int n, long long& c) {
	int minVal = a[0], maxIdx = 0;
	int buckets = int(0.45 * n);
	int* l = new int[buckets];
	for (size_t i = 0; ++c, i < buckets; i++)
	{
		l[i] = 0;
	}
	for (size_t i = 1; ++c, i < n; i++)
	{
		if (++c && a[i] < minVal) minVal = a[i];
		if (++c && a[i] > a[maxIdx]) maxIdx = i;
	}
	if (++c && a[maxIdx] == minVal) {
		delete[]l;
		return;
	}
	double c1 = (double)(buckets - 1) / (a[maxIdx] - minVal);
	for (size_t i = 0; ++c, i < n; i++)
	{
		int bucketIdx = int(c1 * (a[i] - minVal));
		l[bucketIdx]++;
	}
	for (size_t i = 1; ++c, i < buckets; i++)
	{
		l[i] += l[i - 1];
	}
	HoanVi(a[maxIdx], a[0]);
	int nmove = 0;
	int j = 0;
	int k = buckets - 1;
	int flash;
	while (++c && nmove < n - 1)
	{
		while (++c && j > l[k] - 1)
		{
			j++;
			k = int(c1 * (a[j] - minVal));
		}
		flash = a[j];
		if (++c && k < 0) break;
		while (++c && j != l[k])
		{
			k = int(c1 * (flash - minVal));
			--l[k];
			HoanVi(flash, a[l[k]]);
			++nmove;
		}
	}
	delete[]l;
	countInsertionSort(a, n, c);
}


int getMin(int a[], int n)
{
	int min = a[0];
	for (int i = 0; i < n; i++)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}

int countGetMin(int a[], int n, long long& countCmp)
{
	int min = a[0];
	for (int i = 0; ++countCmp, i < n; i++)
	{
		if (++countCmp && min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}

void countingSort(int a[], int n, int min, int max)
{
	int d = 0;
	int cs = max - min;

	int* count = new int[cs + 1];

	for (int i = 0; i <= cs; i++)
		count[i] = 0;

	for (int i = 0; i < n; i++)
		count[a[i] - min]++;

	for (int i = 0; i <= cs; i++)
		if (count[i] > 0)
			for (int j = 1; j <= count[i]; j++)
				a[d++] = i + min;
}

void countCountingSort(int a[], int n, int min, int max, long long& countCmp)
{
	int d = 0;
	int cs = max - min;

	int* count = new int[cs + 1];

	for (int i = 0; ++countCmp, i <= cs; i++)
		count[i] = 0;

	for (int i = 0; ++countCmp, i < n; i++)
		count[a[i] - min]++;

	for (int i = 0; ++countCmp, i <= cs; i++)
		if (++countCmp && count[i] > 0)
			for (int j = 1; ++countCmp, j <= count[i]; j++)
				a[d++] = i + min;
}