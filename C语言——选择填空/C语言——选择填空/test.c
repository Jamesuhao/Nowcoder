#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stddef.h>

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

//8.������δ��ʼ����������������Ϊ���ֵ
int main()
{
	int k = 3;
	int s[2];
	s[0] = k;
	k = s[1] * 10;
	printf("%d\n", k);
	return 0;
}

//9.���ñ�׼��ʱ���#include <stdlib.h>����ȷ�ģ����ҳ�������ٶȱ�#include ��stdlib.h��Ҫ�졣
//��Ϊ#inlcude <> ���� ֻ����ϵͳĿ¼,������������Ŀ¼.�������Լ�дһ��ͷ�ļ�,����#include <>�����.  
//#inlude ""������������Ŀ¼,�������Ŀ¼û�вŻ�����ϵͳĿ¼.
//���԰�ϵͳ���ļ� �ŵ���ǰĿ¼�� �ĳ� ""   ��������ʹ��

//10.const����ָ����������⣺
//const������*��ߣ���const char* p����ʾp��ָ��ı������ݲ��ɱ䣬ָ��ָ����Ըı䣻
//const������*�ұߣ���char* const p����ʾp�Ǹ�����ָ�룬������ָ��������������ָ��ı������ݿɱ䣻
//const������*��ߺ��ұߣ���const char* const p����ʾp��ָ���ܸı䣬ָ��ı�������Ҳ���ܸı䡣

//11.������ڹ���ʱ���ڴ洢�������洢���������
//������ڴ水������Ϣ�����һ���Ϊ�����࣬����������ݡ��������������Ƽ�������ĳ�������ָ��ļ��ϣ��������ǳ������д���Ķ���

//12������������charת��Ϊintʱ�ؼ���char��unsigned����signed�������unsigned��ִ��0��չ�������signed��ִ�з���λ��չ����int������signed����unsiged�޹ء�
signed char a = 0xe0;
unsigned int b = a;
unsigned char c = a;
//a Ϊsigned char    �ͣ�λ���intС��ִ�з���λ��չ��������Ϊ 0xffffffe0;
//c Ϊunsigned char�ͣ�λ���intС��ִ������չ��������Ϊ 0x000000e0;

//13.��ṹ�������С�Ĺ���
//(1)��һ�����ݳ�Ա����ṹ����� ƫ����Ϊ0�ĵ�ַ��
//(2)������Ա����Ҫ���뵽����������������VS����8�ֽ� Linux����4�ֽ�
//������=������Ĭ�϶�������ó�Ա��С�Ľ�Сֵ
//(3)�ṹ���ܴ�СΪ��������(ÿ����Ա��������һ��������)��������
//(4)���Ƕ���˽ṹ��������Ƕ�׵Ľṹ����뵽�Լ������������������������ṹ��������С����������������(��Ƕ�׽ṹ��Ķ�����)����������
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
	printf("%d\n", offsetof(struct s1, c1));//c1���ڽṹ�����ʼλ�õ�ƫ����Ϊ0
	printf("%d\n", offsetof(struct s1, i));//i���ڽṹ�����ʼλ�õ�ƫ����Ϊ4
	printf("%d\n", offsetof(struct s1, c2));//c2���ڽṹ�����ʼλ�õ�ƫ����Ϊ8
	printf("%d\n", sizeof(struct s1));//�ṹ�����s1�Ĵ�СΪ12
	printf("%d\n", sizeof(struct s2));//�ṹ�����s2�Ĵ�СΪ8
	printf("%d\n", sizeof(struct s3));//�ṹ�����s3�Ĵ�СΪ16
	printf("%d\n", sizeof(struct s4));//�ṹ�����s4�Ĵ�СΪ31
	return 0;
}