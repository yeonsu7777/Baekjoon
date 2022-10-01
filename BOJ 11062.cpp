#include <iostream>
using namespace std;

int N;
int card[1000];

void solve()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &card[i]);
	}
}

int main()
{
	int TC;
	scanf("%d", &TC);
	for (int i = 0; i < TC; i++)
	{
		solve();
	}

	return 0;
}