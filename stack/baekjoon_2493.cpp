#include <iostream>
using namespace std;

// ���� 2493�� - ž
// ����
// ���� �տ� �ִ� ž�� ��ȣ ���� �� �Ѵٸ�(���ٸ�) push
// ���ÿ��� ������������ ������ �� (7, 5, 2, ...)
// ���� �տ� �ִ� ž�� ��ȣ ���� ������ �� (���� ��) ���ÿ� �ִ� ž�� ���� ������ �� Ȯ��
// ���ÿ� �ִ� ž���� ���� �� ž���� ū ���̱� ������ ���ÿ� �ִ� ��
// �����ϸ� pop, �ε��� ����

struct node
{
	int height = 0; // ž ����
	int idx = 0; // ���°�� ž����
};

struct node stack[500002]; // ����
int arr[500002]{ 0 }; // �迭
int tower_num[500002]{ 0 }; // ���° ž�� �����ϴ���

int main()
{
	int n, stack_ptr;
	cin >> n;
	stack_ptr = -1;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i]; // �Է�
	}

	for (int i = n; i >= 2; i--)
	{
		if (arr[i] > arr[i - 1]) // ���� �տ� �ִ� ž�� ���ٸ�
		{// stack�� ����
			stack[++stack_ptr] = node{ arr[i], i };
		}
		else // ���� �տ� �ִ� ž�� ���ٸ�
		{
			// ���� ž Ȯ��
			while (stack_ptr > -1)
			{
				if (stack[stack_ptr].height < arr[i - 1]) // �տ� �ִ� ž�� ���ÿ� �ִ� ž���� ���ٸ�
				{
					// pop
					tower_num[stack[stack_ptr].idx] = i - 1;
					stack_ptr--;
				}
				else break;
			}
			
			// ���� ž ���� ����
			tower_num[i] = i - 1;
		}
	}

	// ���� ���� (�ʿ� X, ���� �� ����� ����Ʈ �� 0���� ������)

	for (int i = 1; i <= n; i++)
	{
		cout << tower_num[i] << ' ';
	}
	cout << '\n';

	return 0;
}