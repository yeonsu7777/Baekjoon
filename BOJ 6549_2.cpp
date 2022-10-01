#include <iostream>
#include <stack>
#include <algorithm>
#define ll long long
using namespace std;

int N;
ll arr[1000002];
ll result;
stack<int> s;

void getInput()
{
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &arr[i]);
	}
	for (int i = N + 1; i < 1000002; i++)
		arr[i] = 0;
}

int main()
{
	while (true)
	{
		scanf("%d", &N);
		if (N == 0)
			break;
		else
			getInput();

		result = 0;
		while (!s.empty())
			s.pop();

		s.push(0);
		for (int i = 1; i <= N + 1; i++)
		{
			while (!s.empty() && (arr[s.top()] > arr[i]))
			{
				int check = s.top();
				s.pop();
				result = max(result, arr[check] * (ll)(i - s.top() - 1));
			}
			s.push(i);
		}

		printf("%lld\n", result);
	}

	return 0;
}