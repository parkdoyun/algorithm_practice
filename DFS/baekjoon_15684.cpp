#include <iostream>

using namespace std;

// ���� 15684 - ��ٸ� ����
// DFS, backtracking
// ��� 3
// 30��, 876ms

// ���μ� 3������ �߰� -> �Ǹ� ���
// �� �Ǹ� -1

int max1 = 5;
int n, m, h;
int board[32][12]; // y : H(���μ�), x : N(���μ�)

int cal() // ��ٸ� Ÿ�� ���
{
	for (int i = 1; i <= n; i++)
	{
		int now = i;
		for (int j = 1; j <= h; j++)
		{
			if (board[j][now] == 1)
			{
				now++;
			}
			else if (board[j][now - 1] == 1)
			{
				now--;
			}
		}
		if (i != now) return -1;
	}
	return 0;
}

void backtracking(int lv, int y, int x)
{
	if (lv > max1) return;

	if (lv == 4)
	{
		// Ȯ��
		return;
	}

	for (int i = y; i <= h; i++)
	{
		if (i == y)
		{
			for (int j = x + 1; j <= n; j++)
			{
				if (board[i][j] == 1) continue;
				board[i][j] = 1;
				// ���
				if (cal() == 0 && max1 > lv) max1 = lv;
				backtracking(lv + 1, i, j);
				board[i][j] = 0;
			}
		}
		else
		{
			for (int j = 1; j <= n; j++)
			{
				if (board[i][j] == 1) continue;
				board[i][j] = 1;
				// ���
				if (cal() == 0 && max1 > lv) max1 = lv;
				backtracking(lv + 1, i, j);
				board[i][j] = 0;
			}
		}
		
	}
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m >> h;

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		board[a][b] = 1;
	}

	if (cal() == 0) // �߰� �� �ص� �����ϸ�
	{
		max1 = 0;
	}
	else
	{
		// backtracking ����
		for (int i = 1; i <= h; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (board[i][j] == 1) continue;
				board[i][j] = 1;
				// ���
				if (cal() == 0 && max1 > 1) max1 = 1;
				backtracking(2, i, j);
				board[i][j] = 0;
			}

		}
	}


	if (max1 == 5) max1 = -1;
	cout << max1;

	return 0;
}