#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stddef.h>

//1.在c语言中，无符号整型在与有符号进行运算时，统一当做无符号处理
int main()
{
	unsigned int a = 10;
	int b = -20;
	((a + b) > 10) ? printf(">10") : printf("<=10");
	return 0;
}
//2.注意：对于表达式，只看真假，不考虑数值。j=5是赋值表达式，不是比较表达式。
int main()
{
	int i = 0;
	int j = 0;
	for (i = 0, j = 5; i = j;)
	{
		printf("%d %d\n", i, j);
		i++;
		j--;
	}
	return 0;
}
//3.注意进入循环i就已经自加了
int main()
{
	int i = 0;
	int j = 0;
	int p[8] = { 11, 12, 13, 14, 15, 16, 17, 18 };
	while (i++ < 7)  
	{
		if (p[i] % 2)
		{
			j += p[i];
		}
	}
	printf("%d\n", j);
	return 0;
}

//4.注意理解continue的用法以及循环条件的判断
int main()
{
	int x = 1;
	int i = 1;
	for(; x<50; i++)
	{
		if (x >= 10)
		{
		break;
		}	
		if (x % 2 != 0)
		{
			x += 3; 
			continue;
		}
		x -= -1;
	}
	printf("%d %d\n", x, i);
	return 0;
}

//5.double打印小数点跟后6位
int main()
{
	double x = 2.0 ;
	double y = 0.0;
	if (x < 0.0)
	{
		y = 0.0;
	}
	else if ((x < 5.0) && (!x))//(!x)表示只有x为0时表达式为真
	{
		y = 1.0 / (x + 2.0);
	}
	if (x < 10.0)
	{
		y = 1.0 / x;
	}
	else
	{
		y = 10.0;
	}
	printf("%f\n", y);
	return 0;
}

//6注意区分表达式和赋值的区别，表达式之关心真假
int main()
{
	int i = 0;
	int j = 0;
	int m = 6;
	int n = 4;
	int *p = &n;
	int *q = &m;
	i = p == &m;
	j = (-*p) / (*q) + 7;
	printf("i=%d,j=%d\n", i, j);
	return 0;
}
//7枚举的特性：enum中：首元素不赋值的话，默认为0；后一个元素不赋值的话比前一个元素大1
enum {
	a, b = 5, c, d = 4, e
} k;
int main()
{
	k = c;
	printf("k=%d\n", k);
	return 0;
}

//8.因数组未初始化，所以其中数据为随机值
int main()
{
	int k = 3;
	int s[2];
	s[0] = k;
	k = s[1] * 10;
	printf("%d\n", k);
	return 0;
}

//9.引用标准库时语句#include <stdlib.h>是正确的，而且程序编译速度比#include “stdlib.h”要快。
//因为#inlcude <> 首先 只搜索系统目录,不会搜索本地目录.比如你自己写一个头文件,你用#include <>会出错.  
//#inlude ""首先搜索本地目录,如果本地目录没有才会搜索系统目录.
//可以把系统的文件 放到当前目录下 改成 ""   可以优先使用

//10.const修饰指针变量的问题：
//const出现在*左边，如const char* p，表示p所指向的变量内容不可变，指针指向可以改变；
//const出现在*右边，如char* const p，表示p是个常量指针，即不能指向其他变量，而指向的变量内容可变；
//const出现在*左边和右边，如const char* const p，表示p的指向不能改变，指向的变量内容也不能改变。

//11.计算机在工作时，内存储器用来存储程序和数据
//计算机内存按所存信息的类别一般分为两大类，即程序和数据。程序是用来控制计算机完成某项任务的指令的集合，而数据是程序运行处理的对象

//12整形提升：将char转换为int时关键看char是unsigned还是signed，如果是unsigned就执行0扩展，如果是signed就执行符号位扩展。跟int本身是signed还是unsiged无关。
signed char a = 0xe0;
unsigned int b = a;
unsigned char c = a;
//a 为signed char    型，位宽比int小，执行符号位扩展，被提升为 0xffffffe0;
//c 为unsigned char型，位宽比int小，执行零扩展，被提升为 0x000000e0;

//13.求结构体变量大小的规则：
//(1)第一个数据成员在与结构体变量 偏移量为0的地址处
//(2)其他成员变量要对齐到对齐数的整数倍：VS下是8字节 Linux下是4字节
//对齐数=编译器默认对齐数与该成员大小的较小值
//(3)结构体总大小为最大对齐数(每个成员变量都有一个对其数)的整数倍
//(4)如果嵌套了结构体的情况，嵌套的结构体对齐到自己的最大对齐数的整数倍处，结构体的整体大小就是所有最大对齐数(含嵌套结构体的对其数)的整数倍。
struct s1
{
	char c1;//1  8  1  0
	int i;     //4  8  4   4
	char c2;//1  8  1   8 
};
struct s2
{
	char c1;//1 8  1 0
	char c2;//1 8  1 1
	int i;     // 4 8  4  4
};
struct s3
{
	double d;//8 8 8 0
	char c;//1 8 1 8
	int i;//4 8 4 12
};
struct s4
{
	char c1;//1 8 1 0
	struct s3 s3;//16 8  8  8
	double d;//8 8 8 24
};
int main()
{
	printf("%d\n", offsetof(struct s1, c1));//c1对于结构体的起始位置的偏移量为0
	printf("%d\n", offsetof(struct s1, i));//i对于结构体的起始位置的偏移量为4
	printf("%d\n", offsetof(struct s1, c2));//c2对于结构体的起始位置的偏移量为8
	printf("%d\n", sizeof(struct s1));//结构体变量s1的大小为12
	printf("%d\n", sizeof(struct s2));//结构体变量s2的大小为8
	printf("%d\n", sizeof(struct s3));//结构体变量s3的大小为16
	printf("%d\n", sizeof(struct s4));//结构体变量s4的大小为31
	return 0;
}