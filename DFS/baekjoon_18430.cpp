#include <iostream>

using namespace std;

// 백준 18430 - 무기 공학
// DFS, backtracking
// 골드 5

// 5 * 5라 가능한 가짓수 다 해봐도 됨

int n, m;
int board[6][6];
int visit[6][6];
int max1 = 0;
int y_mov[4][2] = { {1, 1}, {1, 1}, {0, 1}, {0, 1} };
int x_mov[4][2] = { {0, -1}, {0, 1}, {-1, -1}, {1, 1} };

void backtracking(int y, int x, int n1)
{
	visit[y][x] = 1;

	int ty1, tx1, ty2, tx2;
	for (int i = 0; i < 4; i++)
	{
		ty1 = y + y_mov[i][0];
		tx1 = x + x_mov[i][0];
		ty2 = y + y_mov[i][1];
		tx2 = x + x_mov[i][1];
		if (ty1 >= 0 && ty1 < n && tx1 >= 0 && tx1 < m &&
			ty2 >= 0 && ty2 < n && tx2 >= 0 && tx2 < m &&
			visit[ty1][tx1] == 0 && visit[ty2][tx2] == 0)
		{
			visit[ty1][tx1] = 1;
			visit[ty2][tx2] = 1;
			// 다음 길 찾기
			if (max1 < n1 + board[y][x] + board[ty1][tx1] * 2 + board[ty2][tx2]) max1 = n1 + board[y][x] + board[ty1][tx1] * 2 + board[ty2][tx2];
			
			for (int k = x + 1; k < m; k++)
			{
				if (visit[y][k] == 0)
				{
					backtracking(y, k, n1 + board[y][x] + board[ty1][tx1] * 2 + board[ty2][tx2]);
				}
			}

			for (int j = y + 1; j < n; j++)
			{
				for (int k = 0; k < m; k++)
				{
					if (visit[j][k] == 0)
					{
						backtracking(j, k, n1 + board[y][x] + board[ty1][tx1] * 2 + board[ty2][tx2]);
					}
				}
			}
			visit[ty1][tx1] = 0;
			visit[ty2][tx2] = 0;
		}
	}
	visit[y][x] = 0;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int j = 0; j < n; j++)
	{
		for (int k = 0; k < m; k++)
		{
			backtracking(j, k, 0);
		}
	}

	cout << max1;

	return 0;
}