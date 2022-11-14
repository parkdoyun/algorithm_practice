#include <iostream>

using namespace std;

// swea 1949 - ���� ����
// DFS 2�� ���� -> ���� ������ �ִ� k ��� �ѹ� �� ������.

int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };

int board[9][9];
int chk[9][9];
int n, k;
int max1;

void DFS2(int tmp, int y, int x, int val)
{
	for (int i = 0; i < 4; i++)
	{
		if (y + y_mov[i] >= 0 && y + y_mov[i] < n &&
			x + x_mov[i] >= 0 && x + x_mov[i] < n &&
			chk[y + y_mov[i]][x + x_mov[i]] == 0 && 
			val > board[y + y_mov[i]][x + x_mov[i]])
		{
			chk[y + y_mov[i]][x + x_mov[i]] = 1;
			DFS2(tmp + 1, y + y_mov[i], x + x_mov[i], board[y + y_mov[i]][x + x_mov[i]]);
			chk[y + y_mov[i]][x + x_mov[i]] = 0;	
		}
	}
	if (tmp > max1)
	{
		max1 = tmp;
	}
}

void DFS(int tmp, int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		if (y + y_mov[i] >= 0 && y + y_mov[i] < n &&
			x + x_mov[i] >= 0 && x + x_mov[i] < n &&
			chk[y + y_mov[i]][x + x_mov[i]] == 0)
		{
			if (board[y][x] > board[y + y_mov[i]][x + x_mov[i]])
			{
				chk[y + y_mov[i]][x + x_mov[i]] = 1;
				DFS(tmp + 1, y + y_mov[i], x + x_mov[i]);
				chk[y + y_mov[i]][x + x_mov[i]] = 0;
			}
			else if(board[y][x] - 1 >= board[y + y_mov[i]][x + x_mov[i]] - k)
			{
				// �ι�° DFS
				// K��ŭ ���� �� ���� ��
				chk[y + y_mov[i]][x + x_mov[i]] = 1;
				DFS2(tmp + 1, y + y_mov[i], x + x_mov[i], board[y][x] - 1);
				chk[y + y_mov[i]][x + x_mov[i]] = 0;
			}
		}
	}
	if (tmp > max1)
	{
		max1 = tmp;
	}
}


int main()
{
	int T;
	cin >> T;
	
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> k;
		max1 = 0;
		int tmp_max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
				if (board[i][j] > tmp_max) tmp_max = board[i][j];
			}
		}

		// DFS
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == tmp_max)
				{
					chk[i][j] = 1;
					DFS(1, i, j);
					chk[i][j] = 0;
				}
			}
		}


		// ��� ���
		cout << '#' << tc << ' ' << max1 << '\n';

	}


	return 0;
}