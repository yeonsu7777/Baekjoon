//2021.08.08
//���� 2609��: �ִ������� �ּҰ����
#include <iostream>

//�ִ�����
int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

//�ּҰ����
int lcm(int a, int b, int g)
{
	return a * b / g;
}

int main()
{
	int a, b;
	int greatcd;
	int leastcm;

	scanf("%d %d", &a, &b);
	greatcd = gcd(a, b);
	leastcm = lcm(a, b, greatcd);
	printf("%d\n%d\n", greatcd, leastcm);
}