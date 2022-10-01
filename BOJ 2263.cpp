#include <iostream>
using namespace std;

struct node
{
	int index;
	node* leftchild = 0;
	node* rightchild = 0;
};

int n;
node tree[100001];
int in[100001];
int post[100001];

void get_input()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		tree[i].index = i;
	for (int i = 0; i < n; i++)
		scanf("%d", &in[i]);
	for (int i = 0; i < n; i++)
		scanf("%d", &post[i]);
}

void make_tree(int i_s, int i_e, int p_s, int p_e)
{
	int root = post[p_e];
	int in_idx;
	for (int i = i_s; i <= i_e; i++)
	{
		if (in[i] == root)
		{
			in_idx = i;
			break;
		}
	}

	int front_l = in_idx - i_s;


	if (in_idx > i_s)
		tree[root].leftchild = &tree[post[p_s + front_l - 1]];
	if (p_s + front_l != p_e)
		tree[root].rightchild = &tree[post[p_e - 1]];


	if (front_l > 1)
		make_tree(i_s, in_idx - 1, p_s, p_s + front_l - 1);
	if (i_e - in_idx > 1)
		make_tree(in_idx + 1, i_e, p_s + front_l, p_e - 1);
}

void preorder(int idx)
{
	printf("%d ", idx);
	if (tree[idx].leftchild)
		preorder(tree[idx].leftchild->index);
	if (tree[idx].rightchild)
		preorder(tree[idx].rightchild->index);
}

int main()
{
	get_input();
	make_tree(0, n - 1, 0, n - 1);
	preorder(post[n - 1]);
	return 0;
}