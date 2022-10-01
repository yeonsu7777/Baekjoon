#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

char triangle[101][101][30];

void get_triangle(int n, int m)
{
	stack<char> result;
	int up = 0;

	char* A = triangle[n-1][m-1];
	char* B = triangle[n-1][m];
	int a_length = strlen(A);
	int b_length = strlen(B);

	int idx = 1;
	int sum;
	while (true)
	{
		if (idx > b_length && idx > a_length)
			break;
		else if (idx > b_length)
		{
			if (up)
			{
				if (A[a_length - idx] == '9')
				{
					result.push('0');
					up = 1;
				}
				else
				{
					result.push(A[a_length - idx] + up);
					up = 0;
				}
			}
			else
				result.push(A[a_length - idx]);
		}
		else if (idx > a_length)
		{
			if (up)
			{
				if (B[b_length - idx] == '9')
				{
					result.push('0');
				}
				else
				{
					result.push(B[b_length - idx] + up);
					up = 0;
				}
			}
			else
				result.push(B[b_length - idx]);
		}
		else
		{
			sum = A[a_length - idx] - '0' + B[b_length - idx] - '0' + up;
			if (sum >= 10)
			{
				up = 1;
				sum -= 10;
			}
			else
				up = 0;
			result.push(sum + '0');
		}
		idx++;
	}
	if (up)
		result.push('1');

	idx = 0;
	while (!result.empty())
	{
		triangle[n][m][idx] = result.top();
		result.pop();
		idx++;
	}
}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);

	if (m > n - m)
		m = n - m;

	for (int i = 0; i <= n; i++)
		for (int j = 0; j <= m; j++)
			triangle[i][j][0] = '0';

	triangle[0][0][0] = '1';
	for (int i = 1; i <= n; i++)
	{
		int j_end = i < m ? i : m;
		triangle[i][0][0] = '1';
		for (int j = 1; j <= j_end; j++)
			get_triangle(i, j);
	}

	printf("%s", triangle[n][m]);

	return 0;
}