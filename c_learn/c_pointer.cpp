#include <stdio.h>

void test_point_and_array_1()
{
	int a[2][3] = { {1,2,3},{4,5,6} };
	// 数组名表示的是指向数组首元素的地址
	// a包含两个元素（3个int的数组，姑且叫做arr3，或者int3，哈哈），因此a表示的是第一个int3的地址，类型为int3
	// 指针有两个关键的属性：一个是指向的位置，而是指向的类型
	// 表达式中，数组会被解读为指针，如下三种情况例外：
	// 1、sizeof:数组的大小 2、&+数组名：指向数组的指针 3、字符串常量
	printf("a     = %p, sizeof(a)   = %d\n", a,sizeof(a));
	printf("&a    = %p, sizeof(&a)  = %d\n", &a, sizeof(&a));
	// 注意：指针+ - 的长度与类型有关，sizeof指针大小与具体的指针类型无关！！！
	printf("&a+1  = %p, sizeof(&a+1)= %d\n", &a+1, sizeof(&a+1));
	printf("a + 0 = %p, sizeof(a+0) = %d\n", a + 0, sizeof(a+0));
	printf("a + 1 = %p, sizeof(a+1) = %d\n", a + 1,sizeof(a+1));
	// a[0] 包含三个int元素，即数组名为a[0],因此a[0]表示的是第一个int的地址，类型为int
	// 或者把a[0]替换为A，则a[0]指向的就是A[3]={1,2,3}这个数组的第一个元素
	// 多维数组通过等效数组名的方式进行替换分析
	printf("a[0] = %p,sizeof(a[0]) = %d, *a[0] = %d, *(a[0] + 1) = %d\n", a[0], sizeof(a[0]), *a[0], *(a[0]+1));
}

// 二维数组如何传参
void test_point_and_array_2(int (*p)[3], int size)
{
	for (int s = 0; s < size; s++) {
		for (int i = 0; i < 3; i++) {
			printf("%d\n", p[s][i]);
		}
	}
}