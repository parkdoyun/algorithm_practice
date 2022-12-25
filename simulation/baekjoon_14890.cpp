#include <iostream>

using namespace std;

// ���� 14890 - ����
// simulation
// ��� 3

// �� �Ǵ� ���
// 1. ���� ���̰� 1 �̻� �� ���
// 2. ���� ���̰� ���� ���̺��� ���� ���

// ���� ���� �ִ� ���̰� ���� ���ϼ��� �ִ�

int n, l;
int board[101][101];
int chk[101][101]; // ���� üũ

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> l;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cin >> board[i][j];
	}

	int cnt = 0;
	int max1, max_idx, tmp, flag, tmp_height;
	// ���� ��
	for (int i = 0; i < n; i++)
	{
		// Ȯ��
		// �պ���
		flag = 0;
		tmp = n-1;
		while (tmp >= 1)
		{
			if (board[i][tmp] + 1 < board[i][tmp - 1])
			{
				flag = 1;
				break;
			}
			else if (board[i][tmp] > board[i][tmp - 1] + 1)
			{
				flag = 1;
				break;
			}
			else if (board[i][tmp] == board[i][tmp - 1] + 1)
			{
				// ���� ���̸�ŭ ���� �ִ��� Ȯ��
				int tmp_cnt = 0;
				tmp_height = board[i][tmp - 1];
				for (int j = 1; j <= l; j++)
				{
					if (tmp - j < 0 || board[i][tmp - j] != tmp_height || 
						chk[i][tmp-j] == 1) break;
					tmp_cnt++;
				}
				if (tmp_cnt == l) // ok
				{
					// ���� ����
					for (int j = 1; j <= l; j++)
					{
						chk[i][tmp - j] = 1;
					}
					tmp -= l;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else if (board[i][tmp] + 1 == board[i][tmp - 1]) // �� �ڷ� ���� �� �־�� ��
			{
				// ���� ���̸�ŭ ���� �ִ��� Ȯ��
				int tmp_cnt = 0;
				tmp_height = board[i][tmp];
				for (int j = 0; j < l; j++)
				{
					if (tmp + j >= n || board[i][tmp + j] != tmp_height ||
						chk[i][tmp + j] == 1) break;
					tmp_cnt++;
				}
				if (tmp_cnt == l) // ok
				{
					// ���� ����
					for (int j = 0; j < l; j++)
					{
						chk[i][tmp + j] = 1;
					}
					tmp--;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else tmp--;
		}
		if (flag == 1) continue;
		cnt++;
	}
	
	// chk clear
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) chk[i][j] = 0;
	}

	// ������
	for (int i = 0; i < n; i++)
	{
		// Ȯ��
		// �պ���
		flag = 0;
		tmp = n - 1;
		while (tmp >= 1)
		{
			if (board[tmp][i] + 1 < board[tmp - 1][i])
			{
				flag = 1;
				break;
			}
			else if (board[tmp][i] > board[tmp - 1][i] + 1)
			{
				flag = 1;
				break;
			}
			else if (board[tmp][i] == board[tmp - 1][i] + 1)
			{
				// ���� ���̸�ŭ ���� �ִ��� Ȯ��
				int tmp_cnt = 0;
				tmp_height = board[tmp - 1][i];
				for (int j = 1; j <= l; j++)
				{
					if (tmp - j < 0 || board[tmp - j][i] != tmp_height || chk[tmp - j][i] == 1) break;
					tmp_cnt++;
				}
				if (tmp_cnt >= l) // ok
				{
					for (int j = 1; j <= l; j++)
					{
						chk[tmp - j][i] = 1;
					}
					tmp -= l;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else if (board[tmp][i] + 1 == board[tmp - 1][i])
			{
				int tmp_cnt = 0;
				tmp_height = board[tmp][i];
				for (int j = 0; j < l; j++)
				{
					if (tmp + j >= n || board[tmp + j][i] != tmp_height || chk[tmp + j][i] == 1) break;
					tmp_cnt++;
				}
				if (tmp_cnt >= l) // ok
				{
					for (int j = 0; j < l; j++)
					{
						chk[tmp + j][i] = 1;
					}
					tmp--;
				}
				else
				{
					flag = 1;
					break;
				}
			}
			else tmp--;
		}
		if (flag == 1) continue;

		cnt++;
	}

	cout << cnt;

	return 0;
}