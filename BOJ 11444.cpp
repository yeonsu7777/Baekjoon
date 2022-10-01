#include <iostream>
#include <stack>;
#define MOD 1000000007
using namespace std;

stack<int> caltype;
long long matrix[2][2] = { {1, 1},{ 1, 0 } }; //11 12 21 22
long long a[2][2] = { {1, 1}, {1, 0} };
long long tmp[2][2];

void matmult()
{
	while (!caltype.empty())
	{
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				tmp[i][j] = matrix[i][j];
				matrix[i][j] = 0;
			}
		if (caltype.top() == 0) //matrix * matrix
		{
			for (int k = 0; k < 2; k++)
				for (int i = 0; i < 2; i++)
					for (int j = 0; j < 2; j++)
						matrix[i][j] += tmp[i][k] * tmp[k][j];
		}
		else //matrix * a
		{
			for (int k = 0; k < 2; k++)
				for (int i = 0; i < 2; i++)
					for (int j = 0; j < 2; j++)
						matrix[i][j] += tmp[i][k] * a[k][j];
		}
		for (int i = 0; i < 2; i++)
			for (int j = 0; j < 2; j++)
			{
				if (matrix[i][j] > MOD)
					matrix[i][j] %= MOD;
			}
		caltype.pop();
	}
}

int main()
{
	long long n;
	scanf("%lld", &n);

	long long firstn = n;

	n -= 2;
	while (n > 1)
	{
		if (n % 2)
		{
			caltype.push(1);
			n--;
		}
		else
		{
			caltype.push(0);
			n /= 2;
		}
	}

	//matrix = get_matrix(n);
	//get_matrix(n - 2);
	matmult();
	long long result = matrix[0][0] + matrix[0][1];
	if (firstn <= 2)
		result = 1;
	printf("%lld", result % MOD);
	return 0;
}