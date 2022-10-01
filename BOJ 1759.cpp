#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int L, C;
vector<char> letters;
int picked[16] = { 0, };
int moja[2];

int moeum(char alphabet)
{
	char cons[5] = { 'a', 'e', 'i', 'o', 'u' };
	for (int i = 0; i < 5; i++)
		if (alphabet == cons[i])
			return 0;
	return 1;
}

void choose(int level)
{
	if (level == L)
	{
		if (moja[0] >= 1 && moja[1] >= 2)
		{
			for (int i = 0; i < L; i++)
				printf("%c", letters[picked[i]]);
			printf("\n");
		}
	}
	else
	{
		int start = 0;
		if (level)
			start = picked[level - 1] + 1;
		for (int i = start; i <= C - L + level; i++)
		{
			picked[level] = i;
			int getMOJA = moeum(letters[i]);
			moja[getMOJA]++;
			choose(level + 1);
			moja[getMOJA]--;
		}
	}
}


int main()
{
	scanf("%d %d", &L, &C);

	for (int i = 0; i < C; i++)
	{	
		getchar();
		char input;
		scanf("%c", &input);
		letters.push_back(input);
	}

	sort(letters.begin(), letters.end());
	choose(0);
}