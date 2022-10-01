#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct node {
	double distance;
	int a, b;
	bool operator<(const node& ref) const {
		return this->distance < ref.distance;
	}
};

int N;
double x[100], y[100];
vector<node> v;
double dx, dy, dist;
int set[100];
double result;
int star = 1;

void getInput()
{
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lf %lf", &x[i], &y[i]);
		set[i] = i;
	}
}

void getDistance()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = i + 1; j < N; j++)
		{
			v.push_back({ 0, i, j });
			dx = x[i] - x[j];
			dy = y[i] - y[j];
			dist = sqrt(dx * dx + dy * dy);
			v.back().distance = dist;
		}
	}
}

int findSet(int a)
{
	if (set[a] == a)
		return a;
	else
		return set[a] = findSet(set[a]);
}

bool sameSet(int a, int b)
{
	return findSet(a) == findSet(b);
}

void unionSet(int a, int b)
{
	int pa = findSet(a);
	int pb = findSet(b);
	set[pa] = pb;
}

void solve()
{
	for (int i = 0; i < v.size(); i++)
	{
		if (star == N)
			break;
		if (!sameSet(v[i].a, v[i].b))
		{
			result += v[i].distance;
			unionSet(v[i].a, v[i].b);
			star++;
		}
	}
}

int main()
{
	getInput();
	getDistance();
	sort(v.begin(), v.end());
	solve();

	printf("%.3g", result);
	return 0;
}