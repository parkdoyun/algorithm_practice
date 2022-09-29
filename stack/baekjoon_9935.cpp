#include <iostream>
#include <string>
using namespace std;

// ���� 9935�� - ���ڿ� ����
// ����
// ó������ �ִ´�
// ���� ���� ���ڿ��� �ش�� ��� pop�Ѵ�

char stack[1000001]; // ���� ���� �迭

int main()
{
	string input_s, exp_s;
	cin >> input_s >> exp_s;
	int stack_ptr = -1;
	int exp_size = exp_s.size();
	int err_cnt;
	
	for (int i = 0; i < input_s.size(); i++)
	{
		if (input_s[i] == exp_s[exp_size - 1])
		{ // ������ ���� ���ڿ��� �� ������ pop
			err_cnt = 0;
			for (int j = 0; j < exp_size-1; j++)
			{				
				if (exp_s[exp_size - j - 2] != stack[stack_ptr - j]) // ���� ���ڿ� ������� ������
				{					
					stack[++stack_ptr] = input_s[i]; // �׳� ���ÿ� �ְ� ���� ���ڿ� Ȯ��
					err_cnt = 1;
					break;
				}
			}
			if (err_cnt == 0) // ���� ���ڿ� ���������
			{
				stack_ptr -= (exp_size - 1); // ���� ���ڿ���ŭ pop
			}
		}
		else
		{
			stack[++stack_ptr] = input_s[i];
		}
	}
	if (stack_ptr == -1) cout << "FRULA\n";
	else
	{
		for (int i = 0; i <= stack_ptr; i++) // ��� ���
		{
			cout << stack[i];
		}
		cout << '\n';
	}
	
	return 0;
}