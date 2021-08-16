#include <iostream>
using namespace std;

struct node {
	string letters;
	int length;
};

node word[20000];

int partition(node arr[], int low, int high)
{
	node tmp;
	int pivot = arr[high].length;
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		if (arr[j].length < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
		else if (arr[j].length == pivot)
		{
			if (arr[j].letters < arr[high].letters)
			{
				i++;
				if (i != j)
				{
					tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}
	tmp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = tmp;
	return(i + 1);
}

void quickSort(node arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

void solve(void)
{
	int N;
	int i;
	string tmp;
	scanf("%d", &N);
	for (i = 0; i < N; i++)
	{
		cin >> word[i].letters;
		word[i].length = word[i].letters.size();
	}

	quickSort(word, 0, N - 1);

	tmp = word[0].letters;

	cout << word[0].letters;
	printf("\n");

	for (i = 1; i < N; i++)
	{
		if (tmp != word[i].letters)
		{
			cout<< word[i].letters;
			printf("\n");
			tmp = word[i].letters;
		}
	}
}

int main()
{
	solve();
	return 0;
}