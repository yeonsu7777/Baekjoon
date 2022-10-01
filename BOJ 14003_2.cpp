#include <iostream>
#include <algorithm>
using namespace std;

struct arr
{
	int a;
	int p_idx;
	inline bool operator< (const arr& ref) const
	{
		return this->a < ref.a;
	}
};

int N;
arr A[1000005], T[1000005];
int T_length;

void result(int index)
{
	if (index == -1)
		return;
	result(A[index].p_idx);
	printf("%d ", A[index].a);
}

int main()
{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++)
	{
		scanf("%d", &A[i].a);
	}

	for (int i = 1; i <= N; i++)
	{
		arr* idx = lower_bound(T, T + T_length, A[i]);
		if (idx->a == 0 && idx->p_idx == 0)
			T_length++;
		*idx = { A[i].a, i };
		if (idx == T)
			A[i].p_idx = -1;
		else
			A[i].p_idx = idx[-1].p_idx;
	}

	printf("%d\n", T_length);
	result(T[T_length - 1].p_idx);
	return 0;
}