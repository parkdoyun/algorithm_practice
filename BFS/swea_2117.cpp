#include <iostream>
#include <queue>

using namespace std;

// swea 2117 - 홈 방범 서비스
// bfs

// 운영 범위 - 거리에 따라서 |y-y1| + |x-x1| 
// 모든 y,x에 1부터 도시 크기만큼 계산해본다
// 매번 손해 안 보면(이익 0 이상) -> 갯수 비교
// 크기 : 사방으로 1씩 증가 (만약 이미 되어 있다면 -> pass)
int x_mov[] = { 0, 0, -1, 1 };
int y_mov[] = { -1, 1, 0 ,0 };
int arr[21][21];
int chk[21][21];
int n, m;
int max1;

void chkClear()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) chk[i][j] = 0;
	}
}

int cnt = 0; // 매번 확인
struct node
{
	int y;
	int x;
	int dist;
};

bool operator<(node n1, node n2)
{
	if (n1.dist > n2.dist) return true;
	return false;
}
priority_queue<node> pq;
void BFS(int start_y, int start_x)
{
	while (!pq.empty()) pq.pop();

	pq.push({ start_y, start_x, 1 });
	chk[start_y][start_x] = 1;
	if (arr[start_y][start_x] != 0) cnt = 1;
	else cnt = 0;
	int tmp_dist = 0;

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		if (tmp.dist > tmp_dist) // 다 했을 때
		{
			tmp_dist = tmp.dist;
			int res = m * cnt - (tmp.dist * tmp.dist + (tmp.dist - 1) * (tmp.dist - 1));
			if (res >= 0)
			{
				if (max1 < cnt) max1 = cnt;
			}
		}
		if (tmp.dist > n) break;

		for (int i = 0; i < 4; i++)
		{
			if (tmp.y + y_mov[i] >= 0 && tmp.y + y_mov[i] < n &&
				tmp.x + x_mov[i] >= 0 && tmp.x + x_mov[i] < n &&
				chk[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 0)
			{
				chk[tmp.y + y_mov[i]][tmp.x + x_mov[i]] = 1;
				if (arr[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 1) cnt++;
				pq.push({ tmp.y + y_mov[i], tmp.x + x_mov[i], tmp.dist + 1 });
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
		max1 = 0;
		cin >> n >> m;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				chkClear();
				BFS(i, j);
			}
		}


		cout << '#' << tc << ' ' << max1 << '\n';
	}

	return 0;
}