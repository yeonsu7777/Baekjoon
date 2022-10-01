#include <iostream>
#include <queue>
#define ll long long
using namespace std;

struct node {
	ll idx;
	ll shortcut;
	ll change;
	node* left;
	node* right;
};

node ch[10000];
ll inputs[1000000];
ll DP[1000000];
int N, M, K;
ll a, b, c;
ll edit = 0;
queue<ll> q;

void get_input()
{
	for (int i = 1; i <= N; i++)
	{
		scanf("%lld", &inputs[i]);
	}
	for (int i = 1; i <= N; i++)
	{
		DP[i] = DP[i-1] + inputs[i];
	}
	for (int i = 0; i < M; i++)
		ch[i].shortcut = i;
}

ll find_b()
{
	if (!edit)
		return 0;

	ll curr = 0;
	while(true)
	{
		if (ch[curr].idx == b)
			return curr;
		else if (ch[curr].idx < b)
			if (ch[curr].right)
				curr = ch[curr].right->shortcut;
			else
				return curr;
		else if (ch[curr].idx > b)
			if (ch[curr].left)
				curr = ch[curr].left->shortcut;
			else
				return curr;
	}

	return 0;
}

void change()
{
	ll curr = find_b();
	if (ch[curr].idx==b)
	{
		ch[curr].change = c - inputs[b];
	}
	else
	{
		ch[edit].idx = b;
		ch[edit].change = c - inputs[b];

		if (edit > 0)
		{
			if (ch[curr].idx < b)
				ch[curr].right = &ch[edit];
			else
				ch[curr].left = &ch[edit];
		}
		edit++;
	}
}

void get_sum()
{
	ll result = DP[c] - DP[b - 1];
	ll curr;
	if (edit > 0)
	{
		q.push(0);
		while (!q.empty())
		{
			curr = q.front();
			q.pop();
			if (ch[curr].idx >= b && ch[curr].idx <= c)
				result += ch[curr].change;
			if (ch[curr].idx > b && ch[curr].left)
				q.push(ch[curr].left->shortcut);
			if (ch[curr].idx < c && ch[curr].right)
				q.push(ch[curr].right->shortcut);
		}
	}

	printf("%lld\n", result);
}

int main()
{
	scanf("%d %d %d", &N, &M, &K);
	get_input();

	for (int i = 0; i < M + K; i++)
	{
		scanf("%lld %lld %lld", &a, &b, &c);
		if (a == 1)
			change();
		else
			get_sum();
	}
	return 0;
}