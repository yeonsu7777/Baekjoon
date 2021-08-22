#include <iostream>
using namespace std;

int trees;
unsigned int need;
unsigned int woods[1000000];

bool getwood(unsigned int height)
{
	unsigned int got = 0;
	for (int i = 0; i < trees; i++)
	{
		if (woods[i] > height)
			got += (woods[i] - height);
		if (got >= need)
			return true;
	}
	return false;
}

unsigned int solve(unsigned max)
{
	unsigned int left, right, middle;
	left = 0;
	right = max;
	middle = (left + right) / 2;
	while (left < middle)
	{
		if (getwood(middle))
			left = middle;
		else
			right = middle;
		middle = (left + right) / 2;
	}
	return middle;
}

int main()
{
	unsigned max = 0;
	scanf("%d %u", &trees, &need);
	for (int i = 0; i < trees; i++)
	{
		scanf("%u", &woods[i]);
		if (max < woods[i])
			max = woods[i];
	}

	printf("%u", solve(max));
}