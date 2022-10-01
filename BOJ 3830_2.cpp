#include <iostream>
using namespace std;

int N, M; //N: 샘플 개수, M: 출근 일수
char input;
int a, b, w;

int grp[100001];
long long diff[100001];

void initialize(int N)
{
	for (int i = 1; i <= N; i++)
	{
		grp[i] = i;
		diff[i] = 0;
	}
}

int find_set(int a)
{
	if (grp[a] == a)
		return a;
	else
	{
		int parent = find_set(grp[a]);
		diff[a] += diff[grp[a]];
		return grp[a] = parent;
	}
}

void union_set(int a, int b, int w)
{
	int aRoot = find_set(a);
	int bRoot = find_set(b);

	if (aRoot == bRoot)
		return;

	diff[bRoot] = diff[a] + w - diff[b];
	grp[bRoot] = aRoot;
}

int main()
{
	while (true)
	{
		scanf("%d %d", &N, &M);
		if (N == 0 && M == 0)	//test case 종료
			break;

		initialize(N);
		for (int i = 0; i < M; i++)
		{
			getchar();
			scanf("%c %d %d", &input, &a, &b);

			if (input == '!')
			{
				scanf("%d", &w);
				union_set(a, b, w);
			}
			else
			{
				if (find_set(a) != find_set(b))
					printf("UNKNOWN\n");
				else
				{
					int aRoot = find_set(a);
					int bRoot = find_set(b);
					printf("%lld\n", diff[b] - diff[a]);
				}
			}
		}
	}

	return 0;
}