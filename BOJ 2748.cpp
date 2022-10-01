#include <iostream>
using namespace std;

long long fibonacci[90];
int num1, num2, num3;

int main()
{
    int n;
    scanf("%d", &n);

    num2 = 0;
    num3 = 1;
    n--;

    while (n)
    {
        num1 = num2;
        num2 = num3;
        num3 = num1 + num2;
        if(num3>= 1000000)
            num3 %= 1000000;
        n--;
    }

    printf("%d", num3);
}