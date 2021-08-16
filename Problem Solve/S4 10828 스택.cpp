//2021.08.16
//백준 10828번: 스택
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int N;
	string command;
	int inputNum;
	stack<int> myStack;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		cin >> command;
		
		if (command == "push")
		{
			cin >> inputNum;
			myStack.push(inputNum);

		}
		else if (command == "pop")
		{
			if (!myStack.empty())
			{
				printf("%d\n", myStack.top());
				myStack.pop();
			}
			else
				printf("-1\n");
		}
		else if (command == "size")
		{
			printf("%d\n", myStack.size());
		}
		else if (command == "empty")
		{
			printf("%d\n", myStack.empty());
		}
		else if (command == "top")
		{
			if (!myStack.empty())
				printf("%d\n", myStack.top());
			else
				printf("-1\n");
		}
	}
}