#include <iostream>
#include <queue>

using namespace std;

// 백준 1113 - 수영장 만들기
// BFS
// 골드 1

// 무조건 1씩 높은 곳으로 채우기
// ex) 1인 애들 채우기 -> 2인 애들 채우기 -> 3인 애들 채우기...
// 같은 자리에서 테두리 없어질때까지 채우기

// 넣을 수 있는 애들 전부 queue에 넣기 (fill_q)
// 테두리 확인되면 fill_q에 있는 애들 채우기
// 테두리 확인
// fill_q에 들어간 애들 중 가장자리 애들 있다면 테두리 X

struct node
{
	int y;
	int x;
	int depth;
};
int n, m;
int board[51][51];
int visit[51][51];
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
int water_cap = 0;
queue<node> q;
queue<node> fill_q;

// 채우면 true return, 못 채우면 false return
bool BFS(int sy, int sx, int sd) // 깊이 sd인 애들만 채우기 (얘보다 낮거나 같은 애들만)
{
	while (!fill_q.empty()) fill_q.pop();
	while (!q.empty()) q.pop();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) visit[i][j] = 0;
	}

	q.push({ sy, sx, sd });
	int ty, tx;
	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();

		if (visit[tmp.y][tmp.x] == 1) continue;
		visit[tmp.y][tmp.x] = 1;

		if (board[tmp.y][tmp.x] <= sd) fill_q.push(tmp);

		for (int i = 0; i < 4; i++)
		{
			ty = tmp.y + y_mov[i];
			tx = tmp.x + x_mov[i];

			if (ty >= 0 && ty < n && tx >= 0 && tx < m &&
				visit[ty][tx] == 0 && board[ty][tx] <= sd)
			{
				// 테두리 확인하고 채울 수 있으면 채우기
				if (ty == 0 || ty == n - 1 || tx == 0 || tx == m - 1) return false;
				q.push({ ty, tx, board[ty][tx] });
			}
		}
	}

	// 채우기
	while (!fill_q.empty())
	{
		node tmp = fill_q.front();
		fill_q.pop();

		if (board[tmp.y][tmp.x] == sd + 1) continue; // 이미 채움
		water_cap += sd + 1 - board[tmp.y][tmp.x];
		board[tmp.y][tmp.x] = sd + 1;
	}

	return true;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	char c;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> c;
			board[i][j] = (int)(c - '0');
		}
	}

	int tmp_h;
	for (int i = 1; i < n - 1; i++) // 가장자리 어차피 물 못 채움
	{
		for (int j = 1; j < m - 1; j++)
		{
			tmp_h = board[i][j];
			for (int k = tmp_h; k <= 9; k++)
			{
				if (!BFS(i, j, k)) break;
			}
		}
	}

	cout << water_cap;

	return 0;
}