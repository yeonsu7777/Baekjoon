#include <iostream>
#include <vector>
using namespace std;

int result;

struct node {
	int number;
	int dist;
	int bottomD;
};

vector<node> A_L[10001];
int n;

void get_input()
{
	scanf("%d", &n);

	int a, b, w;
	for (int i = 0; i < n - 1; i++)
	{
		scanf("%d %d %d", &a, &b, &w);
		A_L[a].push_back({ b, w, 0 });
	}
}

void get_bottom(int idx, node* parent)
{
	node* curr;
	for (int i = 0; i < A_L[idx].size(); i++)
	{
		curr = &A_L[idx][i];
		get_bottom(curr->number, curr);
		if (parent->bottomD < parent->dist + curr->bottomD)
			parent->bottomD = parent->dist + curr->bottomD;
	}
	if (A_L[idx].size() == 0)
		parent->bottomD = parent->dist;
}

int main()
{
	get_input();
	A_L[0].push_back({ 0, 0, 0 });
	get_bottom(1, &A_L[0][0]);

	result = 0;
	for (int i = 1; i <= n; i++)
	{
		if (A_L[i].size() == 0)
			continue;

		int tmp = A_L[i][0].bottomD;
		if (result < tmp)
			result = tmp;

		//size more or same than 2
		for (int j = 0; j < A_L[i].size() - 1; j++)
		{
			for (int k = 1; k < A_L[i].size(); k++)
			{
				tmp = A_L[i][j].bottomD + A_L[i][k].bottomD;
				if (result < tmp)
					result = tmp;
			}
		}
	}

	printf("%d", result);

	return 0;
}