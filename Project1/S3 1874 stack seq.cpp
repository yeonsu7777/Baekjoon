#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main()
{
	int n;
	bool seq = true;
	int tmp;
	int lastnum = 0;
	stack<int> sequence;
	queue<char> result;

	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &tmp);
		if (sequence.size()==0)
		{
			for (int j = lastnum + 1; j <= tmp; j++)
			{
				sequence.push(j);
				result.push('+');
			}
			lastnum = tmp;
			sequence.pop();
			result.push('-');
		}
		else if (tmp > sequence.top())
		{
			for (int j = lastnum + 1; j <= tmp; j++)
			{
				sequence.push(j);
				result.push('+');
			}
			lastnum = tmp;
			sequence.pop();
			result.push('-');
		}
		else if (tmp < sequence.top())
		{
			seq = false;
			break;
		}
		else
		{
			sequence.pop();
			result.push('-');
		}
	}

	if (seq)
	{
		for (int i = 0; i = result.size(); i++)
		{
			printf("%c\n", result.front());
			result.pop();
		}
	}
	else
		printf("NO");
}