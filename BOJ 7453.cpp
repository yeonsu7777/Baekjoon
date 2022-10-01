#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> A, B, C, D, AB, CD;

int main()
{
	int n;
	int a, b, c, d;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		A.push_back(a);
		B.push_back(b);
		C.push_back(c);
		D.push_back(d);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AB.push_back(A[i] + B[j]);
			CD.push_back(C[i] + D[j]);
		}
	}

	sort(AB.begin(), AB.end());
	sort(CD.begin(), CD.end());

	int ab = 0;
	int cd = CD.size() - 1;
	long long result = 0;
	while (ab < AB.size() && cd >= 0)
	{
		if (AB[ab] + CD[cd] == 0)
		{
			int sameAB = 0;
			int sameCD = 0;
			while (ab + sameAB < AB.size())
			{
				if (AB[ab] == AB[ab + sameAB])
					sameAB++;
				else
					break;
			}
			while (cd + sameCD >= 0)
			{
				if (CD[cd] == CD[cd - sameCD])
					sameCD++;
				else
					break;
			}
			result += (long long)(sameAB * sameCD);
			ab += sameAB;
			cd -= sameCD;
		}
		else if (AB[ab] + CD[cd] < 0)
			ab++;
		else
			cd--;
	}

	printf("%lld", result);
}