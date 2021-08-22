//2021.08.21
//https://www.acmicpc.net/problem/10845
//Baekjoon 10845: Queue
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	int num;
	string command;
	queue<int> myQueue;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> command;

		if (command == "push")
		{
			cin >> num;
			myQueue.push(num);
		}
		else if (command == "pop")
		{
			if (myQueue.empty())
				cout << -1 << '\n';
			else
			{
				cout << myQueue.front()<<'\n';
				myQueue.pop();
			}
		}
		else if (command == "size")
		{
			cout << myQueue.size() << '\n';
		}
		else if (command == "empty")
		{
			cout << myQueue.empty() << '\n';
		}
		else if (command == "front")
		{
			if (myQueue.empty())
				cout << -1 << '\n';
			else
				cout << myQueue.front() << '\n';
		}
		else if (command == "back")
		{
			if (myQueue.empty())
				cout << -1 << '\n';
			else
				cout << myQueue.back() << '\n';;
		}
	}
}