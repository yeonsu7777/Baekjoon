#include <iostream>
#include <algorithm>
using namespace std;

struct coor
{
	int x, y;
};

coor coordinates[100000];

bool compare(coor a, coor b)
{
	if (a.y == b.y)
		return a.x < b.x;
	return a.y < b.y;
}

int main()
{
	int N;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d %d", &coordinates[i].x, &coordinates[i].y);

	sort(coordinates, coordinates + N, compare);
	for (int i = 0; i < N; i++)
		printf("%d %d\n", coordinates[i].x, coordinates[i].y);
}