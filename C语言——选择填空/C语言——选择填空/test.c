#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
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
