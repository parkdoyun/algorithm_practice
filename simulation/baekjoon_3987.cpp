#include <iostream>

using namespace std;

// 백준 3987 - 보이저 1호
// simulation
// 실버 2

// 방향이 같이 있는 chk 배열
// chk 배열에서 같은 방향으로 진행해야 하는 것 만날 경우 무한히 반복 -> return
// 블랙홀 만나거나 항성계 벗어나면 끝

int n, m;
int y_mov[] = { -1, 0, 1, 0 };
int x_mov[] = { 0, 1, 0, -1 }; // 0 : 상, 1 : 우, 2 : 하, 3 : 좌
char board[501][501];
int chk[4][501][501]; // 0 : 상, 1 : 우, 2 : 하, 3 : 좌
char printDir[] = { '*', 'U', 'R', 'D', 'L' };

void chkClear()
{
	for (int k = 0; k < 4; k++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++) chk[k][i][j] = 0;
		}
	}
}

int voyager_flag = 0;
int voyager_dir = 0; // 1 : U, 2 : R, 3 : D, 4 : L
int total_max = 0; // 전체 최댓값
int tmp_max; // 한번 할때마다 최댓값
int total_dir;

void go(int y, int x, int time, int start_dir) // dir => 1 : 상, 2 : 우, 3 : 하, 4 : 좌
{
	if (voyager_flag == 1) return;

	int dir = start_dir;
	// 앞으로 쭉 나가기
	int ty = y + y_mov[dir - 1];
	int tx = x + x_mov[dir - 1];
	int ttime = time + 1;
	while (true)
	{
		// 벗어나게 되거나 블랙홀 만나면
		if (ty < 0 || ty >= n || tx < 0 || tx >= m || board[ty][tx] == 'C')
		{
			if (tmp_max < ttime) tmp_max = ttime;
			return;
		}
		// 무한으로 돌게 되면
		else if (chk[dir-1][ty][tx] == 1)
		{
			voyager_dir = start_dir;
			voyager_flag = 1;
			return;
		}
		// 방향 바꾸기
		else if (board[ty][tx] == '/' || board[ty][tx] == '\\')
		{
			chk[dir - 1][ty][tx] = 1; // dir => 1 : 상, 2 : 우, 3 : 하, 4 : 좌
			if (board[ty][tx] == '/')
			{
				if (dir == 1) dir = 2;
				else if (dir == 2) dir = 1;
				else if (dir == 3) dir = 4;
				else dir = 3;
			}
			else
			{
				if (dir == 1) dir = 4;
				else if (dir == 2) dir = 3;
				else if (dir == 3) dir = 2;
				else dir = 1;
			}
			ttime++;
			ty += y_mov[dir - 1];
			tx += x_mov[dir - 1];
		}
		else
		{
			chk[dir - 1][ty][tx] = 1;
			ttime++;
			ty += y_mov[dir - 1];
			tx += x_mov[dir - 1];
		}
		
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int start_y, start_x; // pr, pc

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	cin >> start_y >> start_x;
	start_y--;
	start_x--;

	for (int i = 1; i <= 4; i++)
	{
		tmp_max = 0;
		chkClear();
		go(start_y, start_x, 0, i);
		if (voyager_flag == 1) break;
		if (tmp_max > total_max)
		{
			total_max = tmp_max;
			total_dir = i;
		}
	}
	if (voyager_flag == 1)
	{
		cout << printDir[voyager_dir] << "\nVoyager";
	}
	else
	{
		cout << printDir[total_dir] << '\n' << total_max;
	}

	return 0;
}