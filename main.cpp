#include "commands.h"
//#pragma warning(disable:4996)

int main(int argc, char* argv[])
{
	int* a;
	int n = 0;
	if (strcmp(argv[1], "-a")  == 0)
	{
		cout << "ALGORITHM MODE\n";
		if (strcmp(argv[3] + strlen(argv[3]) - 4, ".txt") == 0)// command1
		{
			checkAlgorithm1(a, n, argv[2], argv[3], argv[4]);
		}
		else if (argc == 6)// command 2
		{
			checkAlgorithm2(a, n, argv[2], argv[3], argv[4], argv[5]);
		}
		else if (argc == 5)// command 3
		{
			checkAlgorithm3(a, n, argv[2], argv[3], argv[4]);
		}
		else
		{
			cout << "Wrong prototype please check again!!!\n";
		}
	}
	else if(strcmp(argv[1], "-c") == 0)
	{
		if (strcmp(argv[4] + strlen(argv[4]) - 4, ".txt") == 0)// command4
		{
			checkAlgorithm4(a, n, argv[2], argv[3], argv[4]);
		}
		else if (argc == 6)// command5
		{
			checkAlgorithm5(a, n, argv[2], argv[3], argv[4], argv[5]);
		}
		else
		{
			cout << "Wrong prototype please check again!!!\n";
		}
	}
	return 0; 
}

//struct Algorithm
//{
//	char* name;
//	int index;
//};
//
//int main()
//{
//	int* a[11];
//	int n = 0;
//	long long countCmp = 0;
//	double timeUse = 0;
//	char* s = new char[100];
//	char* s2 = new char[100];
//
//	FILE* f = fopen("runtime2.txt", "wt");
//	FILE* f2 = fopen("comp2.txt", "wt");
//	if (f == NULL)
//	{
//		return 0;
//	}
//	if (f2 == NULL)
//	{
//		return 0;
//	}
//	for (int i = 0; i < 1; i++)//Order
//	{
//		switch (i)
//		{
//			case 0:
//			{
//				strcpy(s2, "rand");
//				s2[9] = '\0';
//				break;
//			}
//			case 1:
//			{
//				strcpy(s2, "sorted");
//				s2[11] = '\0';
//				break;
//			}
//			case 2:
//			{
//				strcpy(s2, "rev");
//				s2[8] = '\0';
//				break;
//			}
//			case 3:
//			{
//				strcpy(s2, "nsorted");
//				s2[12] = '\0';
//				break;
//			}
//		}
//		fprintf(f, "%s\n", s2);
//		fprintf(f2, "%s\n", s2);
//		for (int j = 0; j < 6; j++)//Size
//		{
//			switch (j)
//			{
//				case 0:
//				{
//					n = 10000;
//					break;
//				}
//				case 1:
//				{
//					n = 30000;
//					break;
//				}
//				case 2:
//				{
//					n = 50000;
//					break;
//				}
//				case 3:
//				{
//					n = 100000;
//					break;
//				}
//				case 4:
//				{
//					n = 300000;
//					break;
//				}
//				case 5:
//				{
//					n = 500000;
//					break;
//				}
//			}
//			a[0] = new int[n];
//			GenerateData(a[0], n, i);
//			for (int t = 1; t < 11; t++)
//			{
//				a[t] = new int[n];
//				copy(a[0], a[0] + n, a[t]);
//			}
//			fprintf(f, "%d:\n", n);
//			fprintf(f2, "%d:\n", n);
//			for (int k = 10; k < 11; k++)//Sorting
//			{
//				switch (k)
//				{
//					case 0:
//					{
//						strcpy(s, "heap-sort");
//						s[10] = '\0';
//						break;
//					}
//					case 1:
//					{
//						strcpy(s, "merge-sort");
//						s[11] = '\0';
//						break;
//					}
//					case 2:
//					{
//						strcpy(s, "radix-sort");
//						s[11] = '\0';
//						break;
//					}
//					case 3:
//					{
//						strcpy(s, "counting-sort");
//						s[14] = '\0';
//						break;
//					}
//					case 4:
//					{
//						strcpy(s, "shaker-sort");
//						s[12] = '\0';
//						break;
//					}
//					case 5:
//					{
//						strcpy(s, "quick-sort");
//						s[11] = '\0';
//						break;
//					}
//					case 6:
//					{
//						strcpy(s, "shell-sort");
//						s[11] = '\0';
//						break;
//					}
//					case 7:
//					{
//						strcpy(s, "insertion-sort");
//						s[15] = '\0';
//						break;
//					}
//					case 8:
//					{
//						strcpy(s, "flash-sort");
//						s[11] = '\0';
//						break;
//					}
//					case 9:
//					{
//						strcpy(s, "selection-sort");
//						s[15] = '\0'; 
//						break;
//					}
//					case 10:
//					{
//						strcpy(s, "bubble-sort");
//						s[12] = '\0';
//						break;
//					}
//				}
//				countCmp = 0;
//				callAlgorithm(s, timeUse, countCmp, a[k], n);
//				cout << "Order: " << s2 << endl;
//				cout << "Size: " << n << endl;
//				cout << "Algorithm: " << s << endl;
//				cout << "--------------------\n";
//				cout << "Running time(msec): " << timeUse << endl;
//				cout << "Comparisions: " << countCmp << endl;
//				cout << endl;
//				fprintf(f, "%f ", timeUse);
//				fprintf(f2, "%llu ", countCmp);
//			}
//			fprintf(f, "\n");
//			fprintf(f2, "\n");
//		}
//		fprintf(f, "\n");
//		fprintf(f2, "\n");
//	}
//	fclose(f);
//	fclose(f2);
//	return 0;
//}
