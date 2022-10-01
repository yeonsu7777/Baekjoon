#include <iostream>
#include <string>
#include <vector>
using namespace std;

string text, pattern;
int pleft, pright, plength;
vector<int> answer;
bool isEnd;

void getPattern()
{
	pleft = 0;
	for (int i = 1; i < pattern.size(); i++)
	{
		if (pattern[0] == pattern[i])
		{
			pleft = i;
			break;
		}
	}

	if (pleft != 0)
	{
		int tmp = 1;
		while (pattern[tmp] == pattern[pleft + tmp])
		{
			tmp++;
		}
		pright = pleft + tmp - 1;
	}

	plength = pright - pleft + 1;
	if (pleft == 0)
		plength = 0;
}

void compare(int a, int b)
{
	int tidx = a;
	int pidx = b;

	while ((tidx < text.size()) && (pidx < pattern.size()))
	{
		if (text[tidx] == pattern[pidx])
		{
			tidx++;
			pidx++;
		}
		else
			break;
	}

	if (tidx >= text.size() || isEnd)
	{
		isEnd = true;
		return;
	}

	if (pidx == pattern.size())
	{
		answer.push_back(tidx - pidx + 1);
		if (pright == pattern.size() - 1)
			compare(tidx, pleft);
		else
			compare(tidx, 0);
	}
	else if (pidx < pleft)
	{
		compare(tidx +1, 0);
	}
	else if (pidx <= pright)
	{
		compare(tidx + 1, 0);
	}
	else
	{
		compare(a + pleft + plength, plength);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	getline(cin, text);
	getline(cin, pattern);

	// pleft와 pright 구하기
	getPattern();

	isEnd = false;

	compare(0, 0);

	cout << answer.size() << endl;;

	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;

	return 0;
}