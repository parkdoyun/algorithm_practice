#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// swea 1953 - 탈주범 검거
// bfs

// 시간에 맞춰서 갈 수 있는지 체크
// 반대쪽에서 연결되는지도 확인해야 함

int arr[51][51];
int chk[51][51];
int n, m, r, c, l;
int cnt;

void chkClear()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) chk[i][j] = 0;
	}
}
struct node
{
	int y;
	int x;
	int time;
};

bool operator<(node n1, node n2)
{
	if (n1.time > n2.time) return true;
	return false;
}
vector<vector<int>> tunnel = { // 터널 구조물에 따라
	{0, 1, 2, 3}, 
	{0, 1},
	{2, 3},
	{0, 3},
	{1, 3}, 
	{1, 2},
	{0, 2} };

int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };

priority_queue<node> pq;
void BFS()
{
	while (!pq.empty()) pq.pop();

	pq.push({ r, c, 1 });
	cnt = 1;
	chk[r][c] = 1;

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();
		if (tmp.time >= l) break;

		int t = arr[tmp.y][tmp.x] - 1;
		for (int i = 0; i < tunnel[t].size(); i++)
		{
			// 반대쪽에서 연결되는지도 확인해야 함
			if (tmp.y + y_mov[tunnel[t][i]] >= 0 && tmp.y + y_mov[tunnel[t][i]] < n &&
				tmp.x + x_mov[tunnel[t][i]] >= 0 && tmp.x + x_mov[tunnel[t][i]] < m &&
				chk[tmp.y + y_mov[tunnel[t][i]]][tmp.x + x_mov[tunnel[t][i]]] == 0 &&
				arr[tmp.y + y_mov[tunnel[t][i]]][tmp.x + x_mov[tunnel[t][i]]] != 0)
			{
				int tmp_chk = -1;
				int tmp_x = tmp.x + x_mov[tunnel[t][i]];
				int tmp_y = tmp.y + y_mov[tunnel[t][i]];
				int tmp_t = arr[tmp.y + y_mov[tunnel[t][i]]][tmp.x + x_mov[tunnel[t][i]]] - 1;
				for (int j = 0; j < tunnel[tmp_t].size(); j++)
				{
					if (tmp_x + x_mov[tunnel[tmp_t][j]] == tmp.x && tmp_y + y_mov[tunnel[tmp_t][j]] == tmp.y)
					{
						tmp_chk = 1;
						break;
					}
				}
				if (tmp_chk == -1) continue;
				chk[tmp.y + y_mov[tunnel[t][i]]][tmp.x + x_mov[tunnel[t][i]]] = 1;
				pq.push({ tmp.y + y_mov[tunnel[t][i]] , tmp.x + x_mov[tunnel[t][i]] , tmp.time + 1 });
				cnt++;
			}
		}
	}
	
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m >> r >> c >> l;
		chkClear();
		cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				cin >> arr[i][j];
			}
		}

		BFS();

		cout << '#' << tc << ' ' << cnt << '\n';
	}

	return 0;
}