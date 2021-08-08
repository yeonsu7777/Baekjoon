//2021.08.08
//���� 11650��: ��ǥ �����ϱ�
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first)
		return p1.second < p2.second;

	return p1.first < p2.first;
}

int main()
{
	int test_case;
	int a, b;
	vector<pair<int, int>> num(test_case);

	scanf("%d", &test_case);
	for (int i = 0; i < test_case; i++)
	{
		scanf("%d %d", &a, &b);
		num.push_back(pair<int, int>(a, b));
	}

	sort(num.begin(), num.end(), compare);

	for (int i = 0; i < test_case; i++)
	{
		printf("%d %d\n", num[i].first, num[i].second);
	}
}