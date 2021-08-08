#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>

using namespace std;

void solve(void)
{
	int A, B;
	int one, two, three;

	scanf("%d %d", &A, &B);

	one = A % 10;
	two = (A / 10) % 10;
	three = (A / 100) % 10;
	A = one * 100 + two * 10 + three;

	one = B % 10;
	two = (B / 10) % 10;
	three = (B / 100) % 10;
	B = one * 100 + two * 10 + three;

	if (A > B)
		printf("%d", A);
	else
		printf("%d", B);
}

int main()
{
	//int test_case;
	//int T;

	//freopen("input.txt", "r", stdin);
	//cin >> T;

	solve();
	return 0;
}