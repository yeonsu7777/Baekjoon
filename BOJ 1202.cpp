#include <iostream>
#include <queue>
#include <algorithm>
#define ll long long
using namespace std;

struct node
{
	int M, V;
	bool operator<(node const& ref) const {
		return this->M < ref.M;
	}
};

int N, K, bag[300005];
ll result = 0;
node jewel[300005];

void getInput()
{
	scanf("%d %d", &N, &K);

	for (int i = 0; i < N; i++)
		scanf("%d %d", &jewel[i].M, &jewel[i].V);

	for (int i = 0; i < K; i++)
		scanf("%d", &bag[i]);

	sort(bag, bag + K);
	sort(jewel, jewel + N);
}

priority_queue<int> pq;

int main()
{
	getInput();

	int pushed = 0;
	for (int i = 0; i < K; i++)
	{
		while (pushed < N && (jewel[pushed].M <= bag[i]))
		{
			pq.push(jewel[pushed++].V);
		}
		if (!pq.empty())
		{
			result += (ll)pq.top();
			pq.pop();
		}
	}

	printf("%lld", result);
	return 0;
}