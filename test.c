#define _CRT_SECURE_NO_WARNINGS 1
#include "test.h"

int cmp_int(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}
void test1()//整型数据排序
{
	int arr[] = { 5,4,6,7,2,3,8,1,9,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	qsort(arr, sz, sizeof(arr[0]), cmp_int);
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
}


int cmp_float(const void* e1, const void* e2)
{
	if (*(float*)e1 == *(float*)e2)
		return 0;
	else if (*(float*)e1 > *(float*)e2)
		return 1;
	else
		return -1;

	//return (int)(*(float*)e1 - *(float*)e2);//不准确，差值再0.9之内的数字无法准确排序
}
void test2()//浮点型数据排序
{
	float f[] = { 3.0,6.0,4.0,1.0,5.0,2.0,3.9,3.7,3.73,3.358};
	int sz = sizeof(f) / sizeof(f[0]);
	qsort(f, sz, sizeof(f[0]), cmp_float);//qsort库函数用于比较数据，当要比较的两个数据相同时返回值为0，前者大于后者时返回值>0，后者大于前者时返回值<0
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%f ", f[i]);
	}
}


struct Stu
{
	char name[15];
	int age;
};
int cmp_struct_bu_age(const void* e1, const void* e2)
{
	return ((struct Stu*)e1)->age - ((struct Stu*)e2)->age;
}
void test3()//结构体中的整形数据排序
{
	struct Stu s[] = { {"zhangsan",25},{"lisi",15},{"wangwu",30},{"sunliu",27} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_struct_bu_age);

}


int cmp_struct_bu_name(const void* e1, const void* e2)
{
	return strcmp(((struct Stu*)e1)->name, ((struct Stu*)e2)->name);
}
void test4()//结构体中的字符串数据排序
{
	struct Stu s[] = { {"zhangsan",25},{"lisi",15},{"wangwu",30},{"sunliu",27} };
	int sz = sizeof(s) / sizeof(s[0]);
	qsort(s, sz, sizeof(s[0]), cmp_struct_bu_name);
}