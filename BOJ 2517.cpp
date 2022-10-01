#include <iostream>
#include <algorithm>
using namespace std;

struct Player {
	int i;
	int power;

	bool operator< (const Player& ref) const
	{
		return this->power < ref.power;
	}
};

Player list[500000];
int result[500000];

int main()
{
	int N;
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		list[i].i = i;
		scanf("%d", &list[i].power);
		result[i] = 1;
	}
	sort(list, list + N);

	for (int i = 0; i < N-1; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			if (list[i].i > list[j].i)
				result[list[i].i]++;
		}
	}

	for (int i = 0; i < N; i++)
		printf("%d\n", result[i]);
	return 0;
}