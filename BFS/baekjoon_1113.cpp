#include <iostream>
#include <queue>

using namespace std;

// ���� 1113 - ������ �����
// BFS
// ��� 1

// ������ 1�� ���� ������ ä���
// ex) 1�� �ֵ� ä��� -> 2�� �ֵ� ä��� -> 3�� �ֵ� ä���...
// ���� �ڸ����� �׵θ� ������������ ä���

// ���� �� �ִ� �ֵ� ���� queue�� �ֱ� (fill_q)
// �׵θ� Ȯ�εǸ� fill_q�� �ִ� �ֵ� ä���
// �׵θ� Ȯ��
// fill_q�� �� �ֵ� �� �����ڸ� �ֵ� �ִٸ� �׵θ� X

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

// ä��� true return, �� ä��� false return
bool BFS(int sy, int sx, int sd) // ���� sd�� �ֵ鸸 ä��� (�꺸�� ���ų� ���� �ֵ鸸)
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
				// �׵θ� Ȯ���ϰ� ä�� �� ������ ä���
				if (ty == 0 || ty == n - 1 || tx == 0 || tx == m - 1) return false;
				q.push({ ty, tx, board[ty][tx] });
			}
		}
	}

	// ä���
	while (!fill_q.empty())
	{
		node tmp = fill_q.front();
		fill_q.pop();

		if (board[tmp.y][tmp.x] == sd + 1) continue; // �̹� ä��
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
	for (int i = 1; i < n - 1; i++) // �����ڸ� ������ �� �� ä��
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