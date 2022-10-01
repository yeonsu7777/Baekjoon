#include <iostream>
#include <cstring>
#define GOLIMIT 1000000000
using namespace std;

char command[1000000][15];
long long stack[1000];

void gostack(int cidx)
{
	int top = 0;
	bool error = false;

	for (int i = 0; i < cidx; i++)
	{
		if (strcmp(command[i], "POP") == 0)
		{
			if (top < 0)
			{
				error = true;
				break;
			}
			top--;
		}
		else if (strcmp(command[i], "INV") == 0)
		{
			if (top < 0)
			{
				error = true;
				break;
			}
			stack[top] = 0 - stack[top];
		}
		else if (strcmp(command[i], "DUP") == 0)
		{
			if (top < 0)
			{
				error = true;
				break;
			}
			stack[top + 1] = stack[top];
			top++;
		}
		else if (strcmp(command[i], "SWP") == 0)
		{
			if (top <= 0)
			{
				error = true;
				break;
			}
			long long tmp = stack[top];
			stack[top] = stack[top - 1];
			stack[top - 1] = tmp;
		}
		else if (strcmp(command[i], "ADD") == 0)
		{
			if (top <= 0)
			{
				error = true;
				break;
			}
			stack[top - 1] += stack[top];
			top--;
			if (stack[top] > GOLIMIT || stack[top] < -GOLIMIT)
			{
				error = true;
				break;
			}
		}
		else if (strcmp(command[i], "SUB") == 0)
		{
			if (top <= 0)
			{
				error = true;
				break;
			}
			stack[top - 1] -= stack[top];
			top--;
			if (stack[top] > GOLIMIT || stack[top] < -GOLIMIT)
			{
				error = true;
				break;
			}
		}
		else if (strcmp(command[i], "MUL") == 0)
		{
			if (top <= 0)
			{
				error = true;
				break;
			}
			stack[top - 1] *= stack[top];
			top--;
			if (stack[top] > GOLIMIT || stack[top] < -GOLIMIT)
			{
				error = true;
				break;
			}
		}
		else if (strcmp(command[i], "DIV") == 0)
		{
			if (top <= 0 || stack[top] == 0)
			{
				error = true;
				break;
			}
			stack[top - 1] = stack[top - 1] / stack[top];
			top--;
		}
		else if (strcmp(command[i], "MOD") == 0)
		{
			if (top <= 0 || stack[top] == 0)
			{
				error = true;
				break;
			}
			stack[top - 1] = stack[top - 1] % stack[top];
			top--;
		}
		else
		{
			top++;
			stack[top] = atoi(command[i]);
		}
	}

	if (error || top != 0)
		printf("ERROR\n");
	else
		printf("%lld\n", stack[0]);
}

int main()
{
	int cidx = 0;
	bool run = true;
	while (true)
	{
		if (cidx)
			printf("\n");

		cidx = 0;
		while (cidx < 1000000)
		{
			scanf("%s", command[cidx]);
			if (strcmp(command[cidx], "QUIT") == 0)
			{
				run = false;
				break;
			}
			else if (strcmp(command[cidx], "END") == 0)
				break;
			else if(strcmp(command[cidx], "NUM")==0)
				scanf("%s", command[cidx]);

			cidx++;
		}

		if (!run)
			break;

		int program;
		scanf("%d", &program);
		for (int i = 0; i < program; i++)
		{
			scanf("%lld", &stack[0]);
			gostack(cidx);
		}
	}

	return 0;
}