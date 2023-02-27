#include <iostream>
#include <queue>

using namespace std;

// 백준 16918 - 봄버맨
// simulation
// 실버 1

int r, c, n;
char board[201][201];
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };

int bomb_board[201][201]; // 폭탄 있는 곳
struct bomb
{
	int y;
	int x;
};
queue<bomb> tmp_q; // 여기에 넣고 한번에 터트림
int now_time;

// 폭탄 폭발 시 '.' 이면 폭발 X (전에 폭발로 이미 파괴된 것이므로)

void add_bomb()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (board[i][j] == '.')
			{
				board[i][j] = 'O';
				bomb_board[i][j] = now_time + 3;
			}
		}
	}
}

void explosion()
{
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			if (bomb_board[i][j] == now_time) tmp_q.push({ i, j });
		}
	}
	// 모아놓고 한번에 터트림
	while (!tmp_q.empty())
	{
		bomb tmp = tmp_q.front();
		tmp_q.pop();

		board[tmp.y][tmp.x] = '.';
		bomb_board[tmp.y][tmp.x] = -1;
		for (int i = 0; i < 4; i++)
		{
			if (tmp.y + y_mov[i] < 0 || tmp.y + y_mov[i] >= r ||
				tmp.x + x_mov[i] < 0 || tmp.x + x_mov[i] >= c) continue;
			board[tmp.y + y_mov[i]][tmp.x + x_mov[i]] = '.';
			// 폭탄 있는 경우 없애야 함
			bomb_board[tmp.y + y_mov[i]][tmp.x + x_mov[i]] = -1;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c >> n;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 'O') // bomb
			{
				bomb_board[i][j] = 3;
			}
			else bomb_board[i][j] = -1;
		}
	}

	now_time = 2;
	for (int i = 2; i <= n; i++)
	{
		add_bomb();
		explosion();

		now_time++;
	}


	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) cout << board[i][j];
		cout << '\n';
	}

	return 0;
}