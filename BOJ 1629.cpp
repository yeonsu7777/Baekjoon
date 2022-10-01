#include <iostream>
using namespace std;

int A, B, C;

int dc(int num)
{
	if (num == 1)
		return A % C;
	else
	{
		long long tmp = dc(num / 2);
		if (num % 2)
			return ((tmp * tmp) % C * (A % C)) % C;
		else
			return (tmp * tmp) % C;
	}
}

int main()
{
	scanf("%d %d %d", &A, &B, &C);

	int mod = A % C;
	if (mod == 0)
		printf("0");
	else
		printf("%d", dc(B));
}