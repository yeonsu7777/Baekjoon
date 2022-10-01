#include <iostream>
#include <queue>
using namespace std;

int N, inputnum;
priority_queue<int> maxh;
priority_queue<int, vector<int>, greater<int>> minh;

void middle()
{
	if (minh.size() > maxh.size())
	{
		maxh.push(minh.top());
		minh.pop();
	}
	else if (minh.size() + 1 < maxh.size())
	{
		minh.push(maxh.top());
		maxh.pop();
	}
	printf("%d\n", maxh.top());
}

int main()
{
	scanf("%d", &N);
	scanf("%d", &inputnum);
	maxh.push(inputnum);
	printf("%d\n", inputnum);

	for (int i = 1; i < N; i++)
	{
		scanf("%d", &inputnum);
		if (inputnum >= maxh.top())
			minh.push(inputnum);
		else
			maxh.push(inputnum);
		middle();
	}
}