#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cmp1(const void* a, const void* b)
{
	int* m = (int*)a;
	int* n = (int*)b;
	return *m - *n;
}

void test_qsort_1()
{
	printf("\n==========\n");
	int a[3] = { 5,2,8 };
	printf("before qsort:\n");
	for (int i = 0; i < sizeof(a)/sizeof(a[0]); i++) {
		printf("%d ", a[i]);
	}
	qsort(a, sizeof(a) / sizeof(a[0]), sizeof(a[0]), cmp1);
	printf("\nafter qsort:\n");
	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%d ", a[i]);
	}
}


int cmp2(const void* a, const void* b)
{
	int* m = (int*)a; // 强转
	int* n = (int*)b;
	if (m[0] != n[0]) {
		return m[0] - n[0];
	}
	else {
		return m[1] - n[1];
	}
}

void test_qsort_2()
{
	printf("\n==========\n");
	int a[4][2] = { {6,2},{3,8},{9,7},{3,5} };
	printf("\nbefore qsort:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[i][j]);
		}
	}
	qsort(a, 4, sizeof(a) / 4, cmp2);
	printf("\nafter qsort:\n");
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[i][j]);
		}
	}
}

int cmp3(const void* a, const void* b)
{
	int* m = *(int**)a;
	int* n = *(int**)b;
	if (m[0] != n[0]) {
		return m[0] - n[0];
	}
	else {
		return m[1] - n[1];
	}
}

void test_qsort_3()
{
	printf("\n==========\n");
	srand((unsigned int)time(NULL));//初始化种子为随机值
	int** a = (int**)calloc(3 , sizeof(int*));
	if (a == NULL) return;
	for (int i = 0; i < 3; i++) {
		a[i] = (int*)calloc(2 , sizeof(int));
		if (a[i] == NULL) return;
		a[i][0] = rand() % 9;
		a[i][1] = rand() % 9;
	}
	printf("\nbefore qsort:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[i][j]);
		}
	}
	qsort(a, 3, sizeof(int*), cmp3);
	// qsort(a, 3, sizeof(int) * 2, cmp3);
	printf("\nafter qsort:\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d ", a[i][j]);
		}
	}
}