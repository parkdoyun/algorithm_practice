#include <stdio.h>
#include <string.h>

// ���� 1406�� - ������
// Ŀ�� �̵��ϸ鼭 ���ÿ� ����
// ���ڿ� �迭 + ���� ����
// ����

char string[600001];
char stack[600001];

int main()
{
	int stack_ptr = -1;
	int string_ptr = -1; // ������ ���� �ε��� ǥ��
	scanf("%s", string);
	string_ptr = strlen(string) - 1;
	int m;
	scanf("%d", &m);
	char inst, c;
	for (int i = 0; i < m; i++)
	{
		scanf("%c", &inst); // ���๮�� �Է�(C++�� �ٸ�)
		scanf("%c", &inst);
		if (inst == 'L')
		{
			if (string_ptr == -1) continue;
			stack[++stack_ptr] = string[string_ptr];
			string_ptr--;
		}
		else if (inst == 'D')
		{
			if (stack_ptr == -1) continue;
			string[++string_ptr] = stack[stack_ptr];
			stack_ptr--;
		}
		else if (inst == 'B')
		{
			if (string_ptr == -1) continue;
			string_ptr--;
		}
		else // P
		{
			scanf("%c", &c); // ����
			scanf("%c", &c);
			string[++string_ptr] = c;
		}
	}
	for (int i = 0; i <= string_ptr; i++)
	{
		printf("%c", string[i]);
	}
	for (int i = stack_ptr; i >= 0; i--) // ������ �Ųٷ�
	{
		printf("%c", stack[i]);
	}


	printf("\n"); // ���� ����ǥ ���� ����
	return 0;
}