#include <iostream>
using namespace std;

int E, S, M; // 15 28 19
int date;

int main()
{
	scanf("%d %d %d", &E, &S, &M);
	if (E == 15)
		E = 0;
	if (M == 19)
		M = 0;
	date = S;

	while (date % 15 != E || date % 19 != M)
	{
		if (date % 15 == E)
			date += 15 * 28;
		else if (date % 19 == M)
			date += 19 * 28;
		else
			date += 28;
	}

	printf("%d", date);
}