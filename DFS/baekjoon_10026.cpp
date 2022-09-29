#include <iostream>
using namespace std;

// ���� 10026�� - ���ϻ���
// DFS
// �Ϲ� ����, ���ϻ��� ���� ������ DFS ����
// ���ϻ����� ��쿡�� board���� R,G �ϳ��� �����ϰ� �ٽ� ������ ��
// DFS�� ���� ���϶��� ���ư�
// �ѹ� DFS -> ���� �� ���� ���� �湮

char board[102][102];
void DFS(int n, int x, int y);
int visit[102][102]{ 0 };
int cnt;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 102; i++)
	{
		for (int j = 0; j < 102; j++) board[i][j] = '*';
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> board[i][j];
		}
	}
	// �Ϲ� ����
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visit[i][j] == 0)
			{
				cnt++;
				visit[i][j] = 1;
				DFS(n, i, j);
			}
		}
	}
	cout << cnt << ' ';
	// ���ϻ��� ����
	for (int i = 1; i <= n; i++) // R,G �ϳ��� ����
	{
		for (int j = 1; j <= n; j++)
		{
			if (board[i][j] == 'G') board[i][j] = 'R';
			visit[i][j] = 0;
		}
	}
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (visit[i][j] == 0)
			{
				cnt++;
				visit[i][j] = 1;
				DFS(n, i, j);
			}
		}
	}
	cout << cnt << '\n';
	return 0;
}

void DFS(int n, int x, int y)
{
	if (board[x - 1][y] != '*' && visit[x - 1][y] == 0 && board[x - 1][y] == board[x][y])
	{
		visit[x - 1][y] = 1;
		DFS(n, x - 1, y);
	}
	if (board[x + 1][y] != '*' && visit[x+1][y] == 0 && board[x+1][y] == board[x][y])
	{
		visit[x + 1][y] = 1;
		DFS(n, x + 1, y);
	}

	if (board[x][y + 1] != '*' && visit[x][y+1] == 0
		&& board[x][y+1] == board[x][y])
	{
		visit[x][y + 1] = 1;
		DFS(n, x, y + 1);
	}
	if (board[x][y - 1] != '*' && visit[x][y - 1] == 0
		&& board[x][y - 1] == board[x][y])
	{
		visit[x][y - 1] = 1;
		DFS(n, x, y - 1);
	}
	
}
