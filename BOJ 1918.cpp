#include <iostream>
#include <stack>
using namespace std;

int main()
{
	char formula[105];
	scanf("%s", formula);

	stack<char> symbol;

	int curidx = 0;

	while (formula[curidx])
	{
		char curr = formula[curidx];

		if ((curr == '+') || (curr == '-'))
		{
			while (!symbol.empty())
			{
				if (symbol.top() == '(')
					break;
				printf("%c", symbol.top());
				symbol.pop();
			}

			symbol.push(curr);
		}
		else if ((curr == '*') || (curr == '/'))
		{
			if (!symbol.empty())
			{
				if ((symbol.top() == '*') || (symbol.top() == '/'))
				{
					printf("%c", symbol.top());
					symbol.pop();
				}
			}
			symbol.push(curr);
		}
		else if (curr == '(')
		{
			symbol.push(curr);
		}
		else if (curr == ')')
		{
			while (symbol.top() != '(')
			{
				printf("%c", symbol.top());
				symbol.pop();
			}
			symbol.pop();
		}
		else
		{
			printf("%c", curr);
		}

		curidx++;
	}

	while (!symbol.empty())
	{
		printf("%c", symbol.top());
		symbol.pop();
	}

	return 0;
}