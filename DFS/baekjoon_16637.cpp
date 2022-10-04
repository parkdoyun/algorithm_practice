#include <iostream>

using namespace std;

// ���� 16637 - ��ȣ �߰��ϱ�
// ��� 4
// ����Ž��
// dfs, backtracking

// ������ ��ȣ ���� �־�� �� ��� -> �ִ�

// ���� 6 : 1-9-(1-9)-(1-9)-(1-9)-(1-9) = 24

int op[11]; // ������ + : 1, - : 2, * : 3
int num[11]; // ����
// backtracking�� �����ڸ��� �Ѵ�
// �ٷ� ���� ������ �ΰ��� ��ȣ ĥ �� x
// �ִ� ��ȣ ���� => ������ Ȧ�� : (������ ���� / 2) + 1, ������ ¦�� : ������ ���� / 2
int path[11]; // backtracking �迭 (��ȣ)
int n;
int max1;
int op_idx = 0; // ������ ����
int num_idx = 0; // ���� ����

int cal() // ���� ���� ���
{
	int res = num[0];
	int idx = 0;
	while (idx < op_idx)
	{
		if (idx + 1 < op_idx && path[idx + 1] == 1)
		{
			int tmp = 0;
			// ���� �ͺ��� ���
			if (op[idx + 1] == 1) // +
			{
				tmp = num[idx + 1] + num[idx + 2];
			}
			else if (op[idx + 1] == 2) // -
			{
				tmp = num[idx + 1] - num[idx + 2];
			}
			else // *
			{
				tmp = num[idx + 1] * num[idx + 2];
			}

			if (op[idx] == 1) // +
			{
				res = res + tmp;
			}
			else if (op[idx] == 2) // -
			{
				res = res - tmp;
			}
			else // *
			{
				res = res * tmp;
			}

			idx += 2;
			
		}
		else
		{
			if (op[idx] == 1) // +
			{
				res = res + num[idx + 1];
			}
			else if (op[idx] == 2) // -
			{
				res = res - num[idx + 1];
			}
			else // *
			{
				res = res * num[idx + 1];
			}
			idx++;
		}
	}

	return res;
}

void DFS(int lv, int h) // h : ����
{
	int res = cal(); // �� ���
	if (res > max1) max1 = res;

	if (lv == h)
	{
		return;
	}

	for (int i = 0; i < op_idx; i++)
	{
		// ��ȣ �� ������ ��
		if (path[i] == 1) continue;
		else if (i - 1 > 0 && path[i - 1] == 1) continue;
		path[i] = 1;
		DFS(lv + 1, h);
		path[i] = 0;
	}
}

int main()
{
	cin >> n;
	char c;
	for (int i = 0; i < n; i++)
	{
		cin >> c;
		if (i % 2 == 0) // ����
		{
			num[num_idx] = (int)(c - '0');
			num_idx++;
		}
		else // ��ȣ
		{
			if (c == '+')
			{
				op[op_idx] = 1;
			}
			else if (c == '-')
			{
				op[op_idx] = 2;
			}
			else // *
			{
				op[op_idx] = 3;
			}
			op_idx++;
		}
	}

	// ��ȣ ���� ���� �⺻������
	max1 = cal();
	
	for (int i = 0; i < op_idx; i++)
	{
		if (path[i] == 1) continue;
		else if (i - 1 > 0 && path[i - 1] == 1) continue;
		path[i] = 1;
		DFS(1, (op_idx / 2 + 1));
		path[i] = 0;
	}

	cout << max1;

	return 0;
}