#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#if 0
//1.��c�����У��޷������������з��Ž�������ʱ��ͳһ�����޷��Ŵ���
int main()
{
	unsigned int a = 10;
	int b = -20;
	((a + b) > 10) ? printf(">10") : printf("<=10");
	return 0;
}
//2.ע�⣺���ڱ��ʽ��ֻ����٣���������ֵ��j=5�Ǹ�ֵ���ʽ�����ǱȽϱ��ʽ��
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
//3.ע�����ѭ��i���Ѿ��Լ���
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

//4.ע�����continue���÷��Լ�ѭ���������ж�
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

//5.double��ӡС�������6λ
int main()
{
	double x = 2.0 ;
	double y = 0.0;
	if (x < 0.0)
	{
		y = 0.0;
	}
	else if ((x < 5.0) && (!x))//(!x)��ʾֻ��xΪ0ʱ���ʽΪ��
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

//6ע�����ֱ��ʽ�͸�ֵ�����𣬱��ʽ֮�������
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
//7ö�ٵ����ԣ�enum�У���Ԫ�ز���ֵ�Ļ���Ĭ��Ϊ0����һ��Ԫ�ز���ֵ�Ļ���ǰһ��Ԫ�ش�1
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

