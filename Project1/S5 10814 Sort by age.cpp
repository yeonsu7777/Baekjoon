#include <iostream>
#include <algorithm>
using namespace std;

struct member
{
	int id;
	int age;
	string name;
};

bool sorting(member a, member b)
{
	if (a.age == b.age)
		return a.id < b.id;
	return a.age < b.age;
}

member judge[100000];
int main()
{
	int N;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		judge[i].id = i;
		cin >> judge[i].age >> judge[i].name;
	}
	sort(judge, judge + N, sorting);
	for (int i = 0; i < N; i++)
		cout << judge[i].age << ' ' << judge[i].name << '\n';
}