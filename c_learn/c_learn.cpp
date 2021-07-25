#include "c_learn.h"

int main()
{
	test_point_and_array_1();
	
	int a[2][3] = { {1,2,3},{4,5,6} };
	test_point_and_array_2(a, 2);

	test_qsort_1();
	test_qsort_2();
	test_qsort_3();
}