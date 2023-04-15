#include <iostream>

using namespace std;

// 백준 17265 - 나의 인생에는 수학과 함께
// DFS
// 골드 5

int n;
char board[6][6];
int visit[6][6];
int y_mov[] = { 1, 0 };
int x_mov[] = { 0, 1 };

int max_n = -999999999;
int min_n = 999999999;

void DFS(int y, int x, int val, int lv)
{
	if (y == n - 1 && x == n - 1)
	{
		if (max_n < val) max_n = val;
		if (min_n > val) min_n = val;
		return;
	}

	int ty, tx;
	for (int i = 0; i < 2; i++)
	{
		ty = y + y_mov[i];
		tx = x + x_mov[i];

		if (ty >= 0 && ty < n && tx >= 0 && tx < n &&
			visit[ty][tx] == 0)
		{
			visit[ty][tx] = 1;

			if (lv % 2 == 1) // 연산자일 때
			{
				if (board[y][x] == '+')
				{
					DFS(ty, tx, val + (int)(board[ty][tx] - '0'), lv + 1);
				}
				else if (board[y][x] == '-')
				{
					DFS(ty, tx, val - (int)(board[ty][tx] - '0'), lv + 1);
				}
				else // *
				{
					DFS(ty, tx, val * (int)(board[ty][tx] - '0'), lv + 1);
				}
			}
			else // 숫자일 때 => 이미 계산 완료
			{
				DFS(ty, tx, val, lv + 1);
			}
			visit[ty][tx] = 0;
		}		
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
		for (int j = 0; j < n; j++) cin >> board[i][j];
	}

	visit[0][0] = 1;
	DFS(0, 0, (int)(board[0][0] - '0'), 0);

	cout << max_n << ' ' << min_n;

	return 0;
}