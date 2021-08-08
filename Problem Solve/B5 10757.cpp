#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>

using namespace std;

int result[10001] = { 0, };

int main()
{
	string A;
	string B;
	int aindex, bindex;
	int rindex;
	int sum;
	int resultsize;

	cin >> A >> B;

	aindex = A.size();
	bindex = B.size();

	if (aindex > bindex)
	{
		resultsize = aindex;
		for (rindex = aindex; rindex >= 0; rindex--)
		{
			aindex--;
			bindex--;

			if (aindex < 0)
				break;

			if (bindex >= 0)
			{
				sum = A[aindex] + B[bindex] - '0' - '0' + result[rindex];
				if (sum > 9)
					result[rindex - 1] = 1;
				result[rindex] = sum % 10;
			}
			else
			{
				sum = A[aindex] - '0' + result[rindex];
				if (sum > 9)
					result[rindex - 1] = 1;
				result[rindex] = sum % 10;
			}
		}
	}
	else
	{
		resultsize = bindex;
		for (rindex = bindex; rindex >= 0; rindex--)
		{
			aindex--;
			bindex--;

			if (bindex < 0)
				break;

			if (aindex >= 0)
			{
				sum = A[aindex] + B[bindex] - '0' - '0' + result[rindex];
				if (sum > 9)
					result[rindex - 1] = 1;
				result[rindex] = sum % 10;
			}
			else
			{
				sum = B[bindex] - '0' + result[rindex];
				if (sum > 9)
					result[rindex - 1] = 1;
				result[rindex] = sum % 10;
			}
		}
	}

	if (result[0])
		printf("%d", result[0]);

	for (int i = 1; i <= resultsize; i++)
	{
		printf("%d", result[i]);
	}


	return 0;
}