#include <iostream>
#include <queue>
using namespace std;

struct node {
	int absnum;
	int num;
	bool operator < (const node& ref) const
	{
		if (this->absnum == ref.absnum)
			return this->num > ref.num;
		return this->absnum > ref.absnum;
	}
};

int N;
priority_queue<node> pq;

int main()
{
	scanf("%d", &N);
	int tmp;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &tmp);
		if (tmp == 0)
		{
			if (pq.empty())
				printf("0\n");
			else
			{
				printf("%d\n", pq.top().num);
				pq.pop();
			}
		}
		else
		{
			pq.push({ abs(tmp), tmp });
		}
	}
	return 0;
}