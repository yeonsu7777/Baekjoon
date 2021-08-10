//2021.08.10
//���� 2164��: ī��2
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int N;
	queue<int> q;

	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
		q.push(i);

	while (q.size() > 1)
	{
		q.pop();
		q.push(q.front());
		q.pop();
	}

	printf("%d", q.front());
}