#include <iostream>

using namespace std;

// ���� 16724 - �Ǹ� �δ� �糪��
// DFS
// ��� 3

// cycle�� ���� ���� �ȴ�
// cycle ���ο� safe zone ��ġ�ϸ� �ǹǷ�

// 1 ������ ���ο� cycle => cnt++
// 2 ������ ����(cycle�̱⵵ ������ �̹� cycle �˻� ���� ǥ�ñ⵵ ��)

int n, m;
int board[1001][1001];
int chk[1001][1001]; // visit : 1, cycle : 2
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
int cnt = 0;

void search(int y, int x)
{
	chk[y][x] = 1;
	int ty = y + y_mov[board[y][x]];
	int tx = x + x_mov[board[y][x]];
	if (chk[ty][tx] == 1) cnt++; // cycle ����
	else if (chk[ty][tx] == 0) search(ty, tx);
	chk[y][x] = 2; // ������ ���� ���� ������ 2�� �ٲ�� �򰥸��� ����
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
			if (c == 'U') board[i][j] = 0;
			else if (c == 'D') board[i][j] = 1;
			else if (c == 'L') board[i][j] = 2;
			else board[i][j] = 3;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (chk[i][j] == 0) search(i, j);
		}
	}

	cout << cnt;

	return 0;
}