#include <iostream>
using namespace std;

int N, M; //N: 샘플 개수, M: 출근 일수
char input;
int a, b, w;

struct disjoint
{
	int grp;
	int w;

	disjoint& operator+= (const disjoint& input)
	{
		grp = input.grp;
		w += input.w;
		return *this;
	}
};

disjoint sample[100001];

void initialize(int N)
{
	for (int i = 1; i <= N; i++)
	{
		sample[i].grp = i;
		sample[i].w = 0;
	}
}

disjoint find(int a)
{
	if (sample[a].grp == a)
		return sample[a];
	else
		return sample[a] += find(sample[a].grp);
}

void union_set(int a, int b, int w)
{
	disjoint aRoot = find(a);
	disjoint bRoot = find(b);

	sample[bRoot.grp].w = aRoot.w + w - sample[b].w;
	sample[bRoot.grp].grp = aRoot.grp;
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
				if (find(a).grp != find(b).grp)
					printf("UNKNOWN\n");
				else
				{
					int aWeight = find(a).w;
					int bWeight = find(b).w;
					printf("%d\n", bWeight - aWeight);
				}
			}
		}
	}

	return 0;
}