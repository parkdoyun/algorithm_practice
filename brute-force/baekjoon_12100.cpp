#include <iostream>

using namespace std;

// ���� 12100 - 2048 (Easy)
// brute-force, backtracking, ����
// ��� 2

// ������ �� �ִ� �� �����¿�, �ִ� 5
// 1. backtracking���� ��� ���� ����
// 2. �����̸鼭 �ִ� ��� ����

int n;
int board[21][21];
int board_cp[21][21];
int path[6]; // backtracking, 1:��, 2:��, 3:��, 4:��
int max1 = 0;

void copy()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) board_cp[i][j] = board[i][j];
	}
}

int move(int dir) // ��ϵ� �����̰�, �ִ� ��ȯ
{
	int tmp_max = 0;
	int tmp_arr[21]; // ��� ������ �ӽ� �迭
	int idx;

	if (dir == 1) // ��
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) tmp_arr[j] = 0;
			idx = 0;

			// �ֵ� ���Ƴֱ�
			for (int j = 0; j < n; j++)
			{
				if (board_cp[j][i] == 0) continue;
				tmp_arr[idx] = board_cp[j][i];
				idx++;
				board_cp[j][i] = 0;
			}

			// �ϳ��� ��ġ��
			idx = 1;
			while (idx < n)
			{
				if (tmp_arr[idx-1] == tmp_arr[idx])
				{
					tmp_arr[idx - 1] *= 2;
					tmp_arr[idx] = 0;
					idx += 2;
				}
				else // ���� ���� -> �������� �ѱ�
				{
					idx++;
				}
			}

			// �ٽ� �ֱ�
			idx = 0;
			for (int j = 0; j < n; j++)
			{
				if (tmp_arr[j] == 0) continue;
				board_cp[idx][i] = tmp_arr[j];
				if (tmp_arr[j] > tmp_max) tmp_max = tmp_arr[j];
				idx++;
			}
		}
	}
	else if (dir == 2) // ��
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) tmp_arr[j] = 0;
			idx = 0;

			// �ֵ� ���Ƴֱ�
			for (int j = n-1; j >= 0; j--)
			{
				if (board_cp[j][i] == 0) continue;
				tmp_arr[idx] = board_cp[j][i];
				idx++;
				board_cp[j][i] = 0;
			}

			// �ϳ��� ��ġ��
			idx = 1;
			while (idx < n)
			{
				if (tmp_arr[idx - 1] == tmp_arr[idx])
				{
					tmp_arr[idx - 1] *= 2;
					tmp_arr[idx] = 0;
					idx += 2;
				}
				else // ���� ���� -> �������� �ѱ�
				{
					idx++;
				}
			}

			// �ٽ� �ֱ�
			idx = n-1;
			for (int j = 0; j < n; j++)
			{
				if (tmp_arr[j] == 0) continue;
				if (tmp_arr[j] > tmp_max) tmp_max = tmp_arr[j];
				board_cp[idx][i] = tmp_arr[j];
				idx--;
			}
		}
	}
	else if (dir == 3) // ��
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) tmp_arr[j] = 0;
			idx = 0;

			// �ֵ� ���Ƴֱ�
			for (int j = 0; j < n; j++)
			{
				if (board_cp[i][j] == 0) continue;
				tmp_arr[idx] = board_cp[i][j];
				idx++;
				board_cp[i][j] = 0;
			}

			// �ϳ��� ��ġ��
			idx = 1;
			while (idx < n)
			{
				if (tmp_arr[idx - 1] == tmp_arr[idx])
				{
					tmp_arr[idx - 1] *= 2;
					tmp_arr[idx] = 0;
					idx += 2;
				}
				else // ���� ���� -> �������� �ѱ�
				{
					idx++;
				}
			}

			// �ٽ� �ֱ�
			idx = 0;
			for (int j = 0; j < n; j++)
			{
				if (tmp_arr[j] == 0) continue;
				if (tmp_arr[j] > tmp_max) tmp_max = tmp_arr[j];
				board_cp[i][idx] = tmp_arr[j];
				idx++;
			}
		}
	}
	else // ��
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) tmp_arr[j] = 0;
			idx = 0;

			// �ֵ� ���Ƴֱ�
			for (int j = n - 1; j >= 0; j--)
			{
				if (board_cp[i][j] == 0) continue;
				tmp_arr[idx] = board_cp[i][j];
				idx++;
				board_cp[i][j] = 0;
			}

			// �ϳ��� ��ġ��
			idx = 1;
			while (idx < n)
			{
				if (tmp_arr[idx - 1] == tmp_arr[idx])
				{
					tmp_arr[idx - 1] *= 2;
					tmp_arr[idx] = 0;
					idx += 2;
				}
				else // ���� ���� -> �������� �ѱ�
				{
					idx++;
				}
			}

			// �ٽ� �ֱ�
			idx = n - 1;
			for (int j = 0; j < n; j++)
			{
				if (tmp_arr[j] == 0) continue;
				if (tmp_arr[j] > tmp_max) tmp_max = tmp_arr[j];
				board_cp[i][idx] = tmp_arr[j];
				idx--;
			}
		}
	}

	return tmp_max;
}

int cal() // ���
{
	int total_max = 0;
	for (int i = 0; i < 5; i++)
	{
		int tmp = move(path[i]); // ��ϵ� �����̱�
		if (tmp > total_max) total_max = tmp;
	}
	return total_max;
}

void backtracking(int lv)
{
	if (lv == 5)
	{
		// ���
		copy();
		int res = cal();
		if (res > max1) max1 = res;
		return;
	}

	for (int i = 1; i <= 4; i++)
	{
		path[lv] = i;
		backtracking(lv + 1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= 4; i++)
	{
		path[0] = i;
		backtracking(1);
	}
	
	cout << max1;

	return 0;
}