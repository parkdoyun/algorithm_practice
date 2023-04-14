#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 백준 19537 - 전투 시뮬레이션
// simulation, BFS
// 플래티넘 5

int n, h, w, m, k;
int board[501][501]; // 지형 보드
int visit[501][501];
int board_unit[501][501]; // 유닛 있는 보드
int rugged[10]; // 험준도
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };

struct unit
{
	int m; // 이동력
	int t; // 세력 
	int y;
	int x;
	int flag = 0;
};
vector<unit> vec_unit;

bool operator<(unit n1, unit n2)
{
	if (n1.flag == 1 && n2.flag == 0) return true;
	else if (n1.flag == n2.flag && n1.m < n2.m) return true;
	return false;
}
priority_queue<unit> q;

void visitClr()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++) visit[i][j] = 0;
	}
}

void gogo(int num, int goal_y, int goal_x)
{
	if (board_unit[goal_y][goal_x] != 0) return; // 다른 유닛 있을 경우

	while (!q.empty()) q.pop();
	visitClr();

	int sy = vec_unit[num].y; // 현재 나
	int sx = vec_unit[num].x;
	
	int ty, tx;
	visit[sy][sx] = 1;
	int incident_flag;
	for (int i = 0; i < 4; i++)
	{
		ty = sy + y_mov[i];
		tx = sx + x_mov[i];
		if (ty < 0 || ty >= h || tx < 0 || tx >= w) continue;
		if (rugged[board[ty][tx]] == -1 || vec_unit[num].m - rugged[board[ty][tx]] < 0) // 지형 험준하거나 스태미나 다 썼다면
		{
			visit[ty][tx] = 1;
			continue;
		}
		incident_flag = 0;
		// 다른 유닛 인접한지 검사
		for (int j = 0; j < 4; j++)
		{
			if (ty + y_mov[j] < 0 || ty + y_mov[j] >= h || tx + x_mov[j] < 0 || tx + x_mov[j] >= w) continue;
			if (board_unit[ty + y_mov[j]][tx + x_mov[j]] != 0 && vec_unit[board_unit[ty + y_mov[j]][tx + x_mov[j]]].t != vec_unit[num].t)
			{
				incident_flag = 1;
				break;
			}
		}
		if (board_unit[ty][tx] == 0) // 없거나
		{
			q.push({ vec_unit[num].m - rugged[board[ty][tx]], vec_unit[num].t, ty, tx, incident_flag });
		}
		else if (vec_unit[board_unit[ty][tx]].t == vec_unit[num].t) // 같은 유닛 있을 경우 (통과)
		{
			q.push({ vec_unit[num].m - rugged[board[ty][tx]], vec_unit[num].t, ty, tx, incident_flag });
		}
	}

	while (!q.empty())
	{
		unit tmp = q.top();
		q.pop();

		if (visit[tmp.y][tmp.x] == 1) continue;
		visit[tmp.y][tmp.x] = 1;

		// 만약 교전인데 도착했다면 도착 표시
		if (tmp.y == goal_y && tmp.x == goal_x)
		{
			// 정보 변경
			board_unit[vec_unit[num].y][vec_unit[num].x] = 0;
			vec_unit[num].y = tmp.y;
			vec_unit[num].x = tmp.x;
			board_unit[vec_unit[num].y][vec_unit[num].x] = num;
			return;
		}
		else if (tmp.flag == 1) // 도착했거나 교전 시작한다면
		{
			continue;
		}

		for (int i = 0; i < 4; i++)
		{
			ty = tmp.y + y_mov[i];
			tx = tmp.x + x_mov[i];

			if (ty < 0 || ty >= h || tx < 0 || tx >= w || visit[ty][tx] == 1) continue;
			if (rugged[board[ty][tx]] == -1) // 지형 험준
			{
				visit[ty][tx] = 1;
				continue;
			}
			else if (tmp.m - rugged[board[ty][tx]] < 0) // 스태미나 부족
			{
				continue;
			}
			incident_flag = 0;
			// 다른 유닛 인접한지 검사
			for (int j = 0; j < 4; j++)
			{
				if (ty + y_mov[j] < 0 || ty + y_mov[j] >= h || tx + x_mov[j] < 0 || tx + x_mov[j] >= w) continue;
				if (board_unit[ty + y_mov[j]][tx + x_mov[j]] != 0 && vec_unit[board_unit[ty + y_mov[j]][tx + x_mov[j]]].t != tmp.t)
				{
					incident_flag = 1;
					break;
				}
			}
			if (board_unit[ty][tx] == 0) // 없거나
			{
				q.push({ tmp.m - rugged[board[ty][tx]], tmp.t, ty, tx, incident_flag });
			}
			else if (vec_unit[board_unit[ty][tx]].t == tmp.t) // 같은 유닛 있을 경우 (통과)
			{
				q.push({ tmp.m - rugged[board[ty][tx]], tmp.t, ty, tx, incident_flag });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> h >> w;

	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cin >> rugged[i];
	}

	cin >> m;
	vec_unit.resize(m + 1);
	int mov, t, y, x, u;
	for (int i = 1; i <= m; i++)
	{
		cin >> mov >> t >> y >> x;
		vec_unit[i].m = mov;
		vec_unit[i].t = t;
		vec_unit[i].y = y;
		vec_unit[i].x = x;
		board_unit[y][x] = i;
	}

	// 약진 명령
	cin >> k;
	for (int i = 0; i < k; i++)
	{
		cin >> u >> y >> x;
		gogo(u, y, x);
	}

	for (int i = 1; i <= m; i++)
	{
		cout << vec_unit[i].y << ' ' << vec_unit[i].x << '\n';
	}

	return 0;
}