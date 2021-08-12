//2021.08.12
//น้มุ 15829น๘: Hashing
#include <iostream>
using namespace std;

int main()
{
	int L;
	char letter;
	long long numbers[50];
	long long result = 0;

	scanf("%d ", &L);
	for (int i = 0; i < L; i++)
	{
		scanf("%c", &letter);
		numbers[i] = letter - 'a' + 1;
	}

	for (int i = L - 1; i > 0; i--)
	{
		result = ((result + numbers[i]) * 31);
		result %= 1234567891;
	}
	result = (result + numbers[0]) % 1234567891;

	printf("%lld", result);
}