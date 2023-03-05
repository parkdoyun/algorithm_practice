#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� 16932 - ��� �����
// BFS
// ��� 3

// 1. 1�� ������ �ֵ� �׷����� ���� ��� �׷����� ���(vec)
// 2. 0�� ���� �����¿쿡 1�� �׷� �ִٸ� ���ؼ� �ִ��̶� ��
// �����¿쿡 ���� �׷��� �� �ֱ� ������ ���� ó�� �ؾ� ��

int n, m;
int board[1001][1001];
int visit[1001][1001];
int board_idx[1001][1001]; // 1�� �ֵ� �׷� ���� �ε����� ����
int max_size = 0;
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
struct node
{
	int y;
	int x;
};
queue<node> q;
vector<int> vec; // �� �׷� ����� ����

void makeGroup(int sy, int sx, int s_idx)
{
	while (!q.empty()) q.pop();

	q.push({ sy, sx });
	int group_size = 0;
	int ty, tx;

	while (!q.empty())
	{
		node tmp = q.front();
		q.pop();

		if (visit[tmp.y][tmp.x] == 1) continue;
		visit[tmp.y][tmp.x] = 1;
		board_idx[tmp.y][tmp.x] = s_idx;
		group_size++;

		for (int i = 0; i < 4; i++)
		{
			ty = tmp.y + y_mov[i];
			tx = tmp.x + x_mov[i];

			if (ty >= 0 && ty < n && tx >= 0 && tx < m && visit[ty][tx] == 0 && board[ty][tx] == 1)
			{
				q.push({ ty, tx });
			}
		}
	}

	vec.push_back(group_size);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	vec.push_back(-1); // idx 1���� ����
	
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}

	// �׷����� ����
	int idx = 1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 1 && visit[i][j] == 0)
			{
				makeGroup(i, j, idx);
				idx++;
			}
		}
	}

	// 0�� �ֵ�κ��� �ִ� ã��
	int tmp_s;
	int ty, tx;
	int path[4];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] == 0)
			{
				tmp_s = 1;
				path[0] = 0; path[1] = 0;
				path[2] = 0; path[3] = 0;
				for (int r = 0; r < 4; r++)
				{
					ty = i + y_mov[r];
					tx = j + x_mov[r];
					int flag = 0;
					if (ty >= 0 && ty < n && tx >= 0 && tx < m && board_idx[ty][tx] >= 1)
					{
						for (int k = 0; k < r; k++)
						{
							if (path[k] == board_idx[ty][tx])
							{
								flag = 1;
								break;
							}
						}
						if (flag == 1) continue;
						tmp_s += vec[board_idx[ty][tx]];
						path[r] = board_idx[ty][tx];
					}
				}
				if (tmp_s > max_size) max_size = tmp_s;
			}
		}
	}
	cout << max_size;

	return 0;
}