#include <iostream>
using namespace std;

char p[100001];
int n;
char input_arr[300005];
int numbers[100000];

void get_input()
{
	scanf("%s %d %s", p, &n, input_arr);

	for (int i = 0; i < n; i++)
		numbers[i] = 0;

	int idx = 1;
	int numbers_idx = 0;
	while (input_arr[idx] != ']')
	{
		if (input_arr[idx] == ',')
		{
			idx++;
			numbers_idx++;
			continue;
		}

		numbers[numbers_idx] = numbers[numbers_idx] * 10 + input_arr[idx] - '0';
		idx++;
	}

	return;
}

void print_result(int n_front, int n_back, bool forward)
{
	printf("[");
	if (n_front <= n_back)
	{
		if (forward)
		{
			for (int i = n_front; i < n_back; i++)
				printf("%d,", numbers[i]);
			printf("%d", numbers[n_back]);
		}
		else
		{
			for (int i = n_back; i > n_front; i--)
				printf("%d,", numbers[i]);
			printf("%d", numbers[n_front]);
		}
	}
	printf("]\n");
	return;
}

void solve()
{
	get_input();

	bool forward = true;
	int n_front = 0;
	int n_back = n - 1;
	int p_idx = 0;
	bool is_error = false;

	while (p[p_idx])
	{
		if (p[p_idx] == 'R')
			forward = !forward;
		else
		{
			if (n_front > n_back)
				is_error = true;
			else if (forward)
				n_front++;
			else
				n_back--;
		}

		p_idx++;
	}

	if (is_error)
		printf("error\n");
	else
		print_result(n_front, n_back, forward);

	return;
}

int main()
{
	int testcase;
	scanf("%d", &testcase);

	for (int i = 0; i < testcase; i++)
		solve();

	return 0;
}