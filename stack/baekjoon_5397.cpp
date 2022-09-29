#include <iostream>
#include <string>
using namespace std;

// ���� 5397�� - Ű�ΰ�
// ����, ��ũ�� ����Ʈ
// ��ũ�� ����Ʈ�ε� Ǯ���

char arr[1000001];
char stack[1000001];

// arr + stack
// Ŀ�� ���� : arr, Ŀ�� ���� : stack

int main()
{
	int t, stack_ptr, arr_ptr;
	cin >> t;
	for (int i = 0; i < t; i++)
	{
		string str;
		cin >> str; // �Է�
		stack_ptr = -1;
		arr_ptr = -1;
		for (int j = 0; j < str.size(); j++)
		{
			if (str[j] == '<')
			{
				if (arr_ptr == -1) continue;
				stack[++stack_ptr] = arr[arr_ptr];
				arr_ptr--;
			}
			else if (str[j] == '>')
			{
				if (stack_ptr == -1) continue;
				arr[++arr_ptr] = stack[stack_ptr];
				stack_ptr--;
			}
			else if (str[j] == '-') // ����
			{
				if (arr_ptr == -1) continue;
				arr_ptr--;
			}
			else
			{
				arr[++arr_ptr] = str[j];
			}
		}
		for (int j = 0; j <= arr_ptr; j++)
		{
			cout << arr[j];
		}
		for (int j = stack_ptr; j >= 0; j--)
		{
			cout << stack[j]; // ���
		}
		cout << '\n';
	}
	return 0;
}