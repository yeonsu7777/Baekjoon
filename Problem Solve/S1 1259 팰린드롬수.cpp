//2021.08.12
//���� 1259��: �Ӹ���Ҽ�
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string number;
	int left, right;
	bool result;

	while (true)
	{
		result = true;
		cin >> number;
		if (number == "0")
			break;
		left = 0;
		right = number.size() - 1;
		while (left < right)
		{
			if (number[left++] != number[right--])
				result = false;
		}
		if (result)
			printf("yes\n");
		else
			printf("no\n");
	}
}