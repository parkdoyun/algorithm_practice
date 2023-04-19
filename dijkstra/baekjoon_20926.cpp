#include <iostream>
#include <queue>

using namespace std;

// 백준 20926 - 얼음 미로
// dijkstra
// 골드 2

#define INF 999999999

int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
int w, h;
int board[501][501];

struct node
{
	int y;
	int x;
	int dist;
};
bool operator<(node n1, node n2)
{
	return n1.dist > n2.dist;
}
priority_queue<node> pq;

int visit[501][501];
int dist[501][501];
int min_time = INF;

void dijkstra(int sy, int sx)
{
	dist[sy][sx] = 0;
	visit[sy][sx] = 1;

	// 4방향 모두 해서 넣기
	int tmp_dist, ty, tx;
	for (int i = 0; i < 4; i++)
	{
		tmp_dist = 0;
		ty = sy + y_mov[i];
		tx = sx + x_mov[i];

		while (ty >= 0 && ty < h && tx >= 0 && tx < w)
		{
			if (board[ty][tx] == -1) // 출구
			{
				if (dist[ty][tx] > tmp_dist)
				{
					dist[ty][tx] = tmp_dist;
					pq.push({ ty, tx, tmp_dist });
				}
				break;
			}
			else if (board[ty][tx] == -2) // 바위
			{
				if (dist[ty - y_mov[i]][tx - x_mov[i]] > tmp_dist)
				{
					dist[ty - y_mov[i]][tx - x_mov[i]] = tmp_dist;
					pq.push({ ty - y_mov[i], tx - x_mov[i], tmp_dist });
				}
				break;
			}
			else if (board[ty][tx] == -3) // 구멍
			{
				break;
			}
			tmp_dist += board[ty][tx];
			ty += y_mov[i];
			tx += x_mov[i];
		}
	}

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		if (visit[tmp.y][tmp.x] == 1) continue;
		visit[tmp.y][tmp.x] = 1;

		if (board[tmp.y][tmp.x] == -1)
		{
			min_time = tmp.dist;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			tmp_dist = 0;
			ty = tmp.y + y_mov[i];
			tx = tmp.x + x_mov[i];

			while (ty >= 0 && ty < h && tx >= 0 && tx < w)
			{
				if (board[ty][tx] == -1) // 출구
				{
					if (dist[ty][tx] > tmp.dist + tmp_dist && visit[ty][tx] == -1)
					{
						dist[ty][tx] = tmp.dist + tmp_dist;
						pq.push({ ty, tx, tmp.dist + tmp_dist });
					}
					break;
				}
				else if (board[ty][tx] == -2) // 바위
				{
					if (dist[ty - y_mov[i]][tx - x_mov[i]] > tmp.dist + tmp_dist && visit[ty - y_mov[i]][tx - x_mov[i]] == -1)
					{
						dist[ty - y_mov[i]][tx - x_mov[i]] = tmp.dist + tmp_dist;
						pq.push({ ty - y_mov[i], tx - x_mov[i], tmp.dist + tmp_dist });
					}
					break;
				}
				else if (board[ty][tx] == -3) // 구멍
				{
					break;
				}
				tmp_dist += board[ty][tx];
				ty += y_mov[i];
				tx += x_mov[i];
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> h;

	int sy, sx;
	char c;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			visit[i][j] = -1;
			dist[i][j] = INF;

			cin >> c;
			if (c >= '0' && c <= '9') board[i][j] = (int)(c - '0');
			else
			{
				if (c == 'T')
				{
					board[i][j] = 0;
					sy = i;
					sx = j;
				}
				else if (c == 'R') // 바위
				{
					board[i][j] = -2;
				}
				else if (c == 'H') // 구멍
				{
					board[i][j] = -3;
				}
				else // E
				{
					board[i][j] = -1;
				}
			}
		}
	}

	dijkstra(sy, sx);

	if (min_time == INF) cout << -1;
	else cout << min_time;

	return 0;
}