#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
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
