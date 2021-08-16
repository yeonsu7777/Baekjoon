//2021.08.16
//백준 10828번: 스택
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int T;
	string parenthesis;
	bool vps;
	stack<int> check;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		vps = true;
		while (!check.empty())
			check.pop();
		cin >> parenthesis;
		if (parenthesis.size() % 2)
			vps = false;
		else
		{
			for (int j = 0; j < parenthesis.size(); j++)
			{
				if (parenthesis[j] == '(')
					check.push(1);
				else if (parenthesis[j] == ')')
				{
					if (check.empty())
					{
						vps = false;
						break;
					}
					check.pop();
				}
			}
			if (!check.empty())
				vps = false;
		}

		if (vps)
			printf("YES\n");
		else
			printf("NO\n");
	}
}