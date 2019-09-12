#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#if 0
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
#endif

