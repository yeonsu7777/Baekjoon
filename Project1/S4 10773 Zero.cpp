#include <iostream>
#include <stack>
using namespace std;

int main()
{
	stack<int> money;
	int K;
	int input;
	int result = 0;
	int rightnum;
	scanf("%d", &K);

	for (int i = 0; i < K; i++)
	{
		scanf("%d", &input);
		if (input)
			money.push(input);
		else
			money.pop();
	}

	rightnum = money.size();
	for (int i = 0; i < rightnum; i++)
	{
		result += money.top();
		money.pop();
	}

	printf("%d", result);
}