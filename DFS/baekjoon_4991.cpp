#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ���� 4991 - �κ� û�ұ�
// backtracking, BFS
// ��� 2

// ������� ��� ������ ĭ�� �����̶�� �ϰ�
// �� �� ���� �� ��� ����� ���� ���ϰ� ���� (BFS)

// backtracking���� �´� ��� ã�ƺ���
// �ּҰ� ���


int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
int w, h;
char board[21][21];
int chk[21][21];
int order[12];
int path[12];
int room_size; // �� ������
int total_w;

struct edge
{
	int oppo;
	int weight = -1;
};
vector<vector<edge>> E;

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
vector<node> vec_room;

void chkClear()
{
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++) chk[i][j] = 0;
	}
}

int pathLen(int a, int b) // ��� ������ ĭ ������ ��� ���� ����
{
	while (!pq.empty()) pq.pop();

	int gy = vec_room[b].y;
	int gx = vec_room[b].x;

	chkClear();
	int ty, tx;
	pq.push({ vec_room[a].y, vec_room[a].x, 0 });

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		if (chk[tmp.y][tmp.x] == 1) continue;
		chk[tmp.y][tmp.x] = 1;

		if (tmp.y == gy && tmp.x == gx) return tmp.dist;

		for (int i = 0; i < 4; i++)
		{
			ty = tmp.y + y_mov[i];
			tx = tmp.x + x_mov[i];
			if (ty >= 0 && ty < h && tx >= 0 && tx < w &&
				chk[ty][tx] == 0 && board[ty][tx] != 'x')
			{
				pq.push({ ty, tx, tmp.dist + 1 });
			}
		}
	}
	return -1;
}

int min1;
void backtracking(int lv, int dist)
{
	if (dist > min1) return;

	if (lv == room_size)
	{
		// �˾ƺ���
		if (min1 > dist) min1 = dist;
		return;
	}

	for (int i = 1; i < room_size; i++)
	{
		if (order[i] == 0)
		{
			path[lv] = i;
			order[i] = 1;
			int tmp_dist = E[path[lv]][path[lv - 1]].weight; // �迭 ã�ƺ���
			if (tmp_dist != -1) backtracking(lv + 1, dist + tmp_dist);
			order[i] = 0;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int sy, sx;
	E.resize(12);
	for (int i = 0; i < 12; i++) E[i].resize(12);

	while (true)
	{
		cin >> w >> h;
		if (h == 0 && w == 0) break;

		vec_room.clear();
		room_size = 0;
		total_w = 0;

		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 'o')
				{
					sy = i;
					sx = j;
				}
				else if (board[i][j] == '*')
				{
					vec_room.push_back({ i, j });
					room_size++;
				}
			}
		}

		// �� ó���� ����� ����
		vec_room.insert(vec_room.begin(), { sy, sx });
		room_size++;

		// ��� �����鿡 ���Ͽ� edge �ֱ�
		for (int i = 0; i < room_size; i++)
		{
			for (int j = i + 1; j < room_size; j++)
			{
				int tmp_d = pathLen(i, j);
				if (tmp_d != -1)
				{
					E[i][j].weight = tmp_d;
					E[j][i].weight = tmp_d;
				}
				else
				{
					E[i][j].weight = -1;
					E[j][i].weight = -1;
				}
			}
		}
		// backtracking���� ������ �� Ȯ��
		min1 = 1000000000;

		path[0] = 0;
		order[0] = 1;

		for (int i = 1; i < room_size; i++)
		{
			if (order[i] == 0)
			{
				path[1] = i;
				order[i] = 1;
				int tmp_dist = E[path[1]][path[0]].weight; // �迭 Ȯ��
				if (tmp_dist != -1) backtracking(2, tmp_dist);
				order[i] = 0;
			}
		}

		if (min1 == 1000000000) cout << -1 << '\n';
		else cout << min1 << '\n';
		
	}


	return 0;
}