#include <iostream>
using namespace std;

char channel[7];
int broken;
int keypad[10];
int result;
int h_l[2]; //0: high, 1: low
int push;
char new_ch[8];

void get_input()
{
	for (int i = 0; i < 10; i++)
		keypad[i] = 1;

	scanf("%s %d", channel, &broken);
	for (int i = 0; i < broken; i++)
	{
		int tmp;
		scanf("%d", &tmp);
		keypad[tmp] = 0;
	}

	for (int i = 0; i < 10; i++)
	{
		if (keypad[i])
		{
			h_l[1] = i + '0';
			break;
		}
	}
	for (int i = 9; i >= 0; i--)
	{
		if (keypad[i])
		{
			h_l[0] = i + '0';
			break;
		}
	}
}

void get_channel(int idx)
{
	if (channel[idx] == 0)
	{
		int tmp = abs(atoi(new_ch) - atoi(channel)) + idx;
		result = tmp < result ? tmp : result;
		return;
	}

	if (push==2)
	{
		for (int i = 0; i < 10; i++)
		{
			if (keypad[i])
			{
				new_ch[idx] = i + '0';
				if (i < channel[idx] - '0')
					push = 0;
				else if (i > channel[idx] - '0')
					push = 1;

				get_channel(idx + 1);
				push = 2;
			}
		}
	}
	else
	{
		new_ch[idx] = h_l[push];
		get_channel(idx + 1);
	}
}

void check_last()
{
	int length = 0;
	while (channel[length] != 0)
		length++;
	
	// 한자릿 수 더 큰 경우 중에 가장 작은 값
	for (int i = 1; i < 10; i++)
	{
		if (keypad[i])
		{
			new_ch[0] = i + '0';
			break;
		}
	}
	for (int i = 1; i <= length; i++)
		new_ch[i] = h_l[1];

	int tmp = abs(atoi(new_ch) - atoi(channel)) + length + 1;
	result = tmp < result ? tmp : result;


	// 한자릿 수 더 작은 경우 중에 가장 큰 값
	if (length > 1)
	{
		for (int i = 0; i < 8; i++)
			new_ch[i] = 0;
		for (int i = 0; i < length - 1; i++)
			new_ch[i] = h_l[0];
		int tmp = abs(atoi(new_ch) - atoi(channel)) + length - 1;
		result = tmp < result ? tmp : result;
	}
}

int main()
{
	get_input();
	result = abs(atoi(channel) - 100);

	if (broken != 10)
	{
		push = 2;
		get_channel(0);
		check_last();
	}
	printf("%d", result);
	return 0;
}