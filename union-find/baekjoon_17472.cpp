#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// ���� 17472 - �ٸ� ����� 2
// union-find, BFS
// ��� 1

// 0. ���� ��ȣ �ű�� (BFS)
// 1. �ϴ� ��� �� �� �ٸ� ���س���
// 2. dijkstra�� ����
// 2-1. dijkstra ������ ������� ���� �� �ٸ��� ���� �������� �ؾ� �� (��� �ٸ����� ������)
// 2-2. dijkstra ���� union-find�� ����
// 3. ��� ����ƴ��� Ȯ�� => �̰� ����
// ** �� ���� ��Ʈ���� ��!(��� ����) �׳� ����ƴٰ� ���� �ƴ� **

int n, m;
int board[11][11];
int chk[11][11];
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
int total = 0;

struct node
{
	int y;
	int x;
	int idx;
};
queue<node> q; // �ٴٶ� ����� ������ �ִ� ť

struct vertex
{
	int idx;
	int dist = 10000000;
	int root;
	int chk = -1;
};

bool operator<(vertex v1, vertex v2)
{
	if (v1.dist > v2.dist) return true;
	return false;
}

struct edge
{
	int oppo;
	int weight;
	int me;
};
bool operator<(edge e1, edge e2)
{
	if (e1.weight > e2.weight) return true;
	return false;
}

vector<vertex> V;
vector<vector<edge>> E;
priority_queue<edge> pq;

void chkClear()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) chk[i][j] = 0;
	}
}

queue<node> q1; // �� �����ϱ� ���� ť
void makeIsland(int y, int x, int idx)
{
	// 4���� �߿� �ϳ��� �ٴٶ� ����Ǿ queue�� �־���´�
	while (!q1.empty()) q1.pop();

	q1.push({ y, x, idx });

	while (!q1.empty())
	{
		node tmp = q1.front();
		q1.pop();

		if (chk[tmp.y][tmp.x] == 1) continue;
		chk[tmp.y][tmp.x] = 1;
		board[tmp.y][tmp.x] = idx;

		int flag = 1;

		int tx, ty;
		for (int i = 0; i < 4; i++)
		{
			tx = tmp.x + x_mov[i];
			ty = tmp.y + y_mov[i];
			if (ty >= 0 && ty < n &&
				tx >= 0 && tx < m &&
				chk[ty][tx] == 0)
			{
				if (board[ty][tx] == 1)
				{
					q1.push({ ty, tx });
				}
				else flag = 0; // �ٴٿ� �����
			}
		}

		if (flag != 1) // �ٴٶ� ����Ǿ��ٸ�
		{
			q.push({ tmp.y, tmp.x, idx });
		}
	}
}

void makeBridge() // �ٸ� �����
{
	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();

		// �׹��� ��� �غ���
		int len;
		int ty, tx;
		for (int i = 0; i < 4; i++)
		{
			len = 0;
			ty = tmp.y;
			tx = tmp.x;
			while (true)
			{
				ty += y_mov[i];
				tx += x_mov[i];
				len++;
				if (ty < 0 || ty >= n || tx < 0 || tx >= m) break;
				else if (board[ty][tx] != 0 && board[ty][tx] == tmp.idx)
				{
					break;
				}
				else if (board[ty][tx] != 0 && board[ty][tx] != tmp.idx)
				{
					if (len > 2)
					{
						E[tmp.idx].push_back({ board[ty][tx], len - 1, tmp.idx });
						pq.push(E[tmp.idx].back()); // pq�� ����
					}
					break;
				}
			}
		}
	}
}

int findRoot(int a)
{
	if (V[a].root == a) return a;
	return findRoot(V[a].root);
}

void Union(int a, int b, int w)
{
	int ar = findRoot(a);
	int br = findRoot(b);
	if (ar == br) return;
	total += w;

	V[a].chk = 1;
	V[b].chk = 1;

	if (ar == a)
	{
		V[ar].root = br;
	}
	else V[br].root = ar;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) cin >> board[i][j];
	}

	// �� ��ȣ �ű��
	int idx = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != 0 && chk[i][j] == 0)
			{
				makeIsland(i, j, idx);
				idx++;
			}
		}
	}

	idx--; // �� ����
	V.resize(idx + 1);
	E.resize(idx + 1);

	for (int i = 1; i <= idx; i++)
	{
		V[i].idx = i;
		V[i].root = i; // ��Ʈ�� �ڱ� �ڽ�
	}

	// �ٸ� ���ϱ�
	makeBridge();

	// �� ����
	while (!pq.empty())
	{
		edge tmp = pq.top();
		pq.pop();
		
		Union(tmp.me, tmp.oppo, tmp.weight);
	}

	// �� ����Ǿ����� Ȯ��
	// ** �� ���� ��Ʈ���� ��!(��� ����) �׳� ����ƴٰ� ���� �ƴ� **
	int totalflag = 0;
	int root = findRoot(1);
	for (int i = 2; i <= idx; i++)
	{
		if (findRoot(i) != root) // ���� �� ��
		{
			totalflag = 1;
			break;
		}
	}

	if (totalflag == 0) cout << total;
	else cout << -1;
	

	return 0;
}