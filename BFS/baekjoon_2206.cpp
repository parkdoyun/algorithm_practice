#include <iostream>
#include <queue>

using namespace std;

// ���� 2206 - �� �μ��� �̵��ϱ�
// bfs

// �Ѱ��� �μ� �� �� �غ���
// dfs, backtracking -> �ð��ʰ�
// bfs�� �ٲ㺸�� => �޸� �ʰ�
// chk => �� �μ� �Ŷ� �� �μ� �Ŷ� ����

int n, m;

int board[1001][1001];
int chk[2][1001][1001]; // chk[0] : �ѹ��� �� �� �μ�, chk[1] : �� �ѹ� �μ�

int x_mov[] = { 0, 1, -1, 0 };
int y_mov[] = { 1, 0, 0, -1 };

struct node
{
	int y;
	int x;
	int dist;
	int flag = 0;
};

bool operator<(node n1, node n2)
{
	if (n1.dist > n2.dist) return true;
	return false;
}

priority_queue<node> pq;

int BFS(int y, int x)
{
	pq.push({ y, x, 1, 0 });

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();
		if (tmp.y == n - 1 && tmp.x == m - 1)
		{
			return tmp.dist;
		}
		if (chk[tmp.flag][tmp.y][tmp.x] == 1) continue;
		chk[tmp.flag][tmp.y][tmp.x] = 1;

		for (int i = 0; i < 4; i++)
		{
			if (tmp.y + y_mov[i] >= 0 && tmp.y + y_mov[i] < n &&
				tmp.x + x_mov[i] >= 0 && tmp.x + x_mov[i] < m &&
				chk[tmp.flag][tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 0)
			{
				if (tmp.flag == 0 && board[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 1)
				{
					pq.push({ tmp.y + y_mov[i], tmp.x + x_mov[i], tmp.dist + 1, 1 });
				}
				else if (board[tmp.y + y_mov[i]][tmp.x + x_mov[i]] == 0)
				{
					pq.push({ tmp.y + y_mov[i], tmp.x + x_mov[i], tmp.dist + 1, tmp.flag });
				}

			}
		}
	}
	return -1;
}


int main()
{
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


	int res = BFS(0, 0);
	cout << res;

	return 0;
}