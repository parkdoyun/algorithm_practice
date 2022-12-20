#include <iostream>
#include <queue>

using namespace std;

// ���� 16946 - �� �μ��� �̵��ϱ� 4
// DFS
// ��� 2

// 1. backtracking
// �ð� �ʰ�
// 1000 * 1000 ũ��� �ٸ� ��� �ʿ�
// 2. BFS => �ð� �ʰ�

// DP?
// DP[i][j] = 1 + DP[i-1][j] + DP[i+1][j] + DP[i][j-1] + DP[i][j+1]; (�� �ƴ� �ֵ�)

// 3. DFS
// 0�� ���� ���� ���� (����� �� �󺧸�)
// ������ �� ����Ǿ����� ���� �� ����
// arr[i][j] = 1 + arr[i-1][j](�갡 ���Ե� ������ ũ��) + arr[i+1][j] + arr[i][j-1] + arr[i][j+1]; (�� �ƴ� �ֵ�)
// ���� 4��(�����¿�) �ߺ� �����ؾ� ��

int n, m;
int chk[1001][1001];
int board[1001][1001];
int y_mov[] = { -1, 1, 0, 0 };
int x_mov[] = { 0, 0, -1, 1 };
int block_n[1000005]; // �󺧸��� �� �� ��� �������

void labeling(int y, int x, int a) // �󺧸�
{
	block_n[a]++;
	board[y][x] = a;
	int ty, tx;
	for (int i = 0; i < 4; i++)
	{
		ty = y + y_mov[i];
		tx = x + x_mov[i];
		if (ty >= 0 && ty < n && tx >= 0 && tx < m &&
			board[ty][tx] == 0 && chk[ty][tx] == 0)
		{
			chk[ty][tx] = 1;
			labeling(ty, tx, a);
		}
	}
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
			if (c == '0') board[i][j] = 0;
			else board[i][j] = 1;
		}
	}
	// �󺧸�
	int idx = 2;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] >= 1 || chk[i][j] == 1) continue;
			chk[i][j] = 1;
			labeling(i, j, idx);
			idx++;
		}
	}

	int path[4];
	int ty, tx;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (board[i][j] != 1)
			{
				cout << 0;
				continue;
			}
			idx = 0;
			for (int k = 0; k < 4; k++)
			{
				ty = i + y_mov[k];
				tx = j + x_mov[k];
				if (ty >= 0 && ty < n && tx >= 0 && tx < m &&
					board[ty][tx] != 1) {
					// �ߺ� üũ
					int flag = 0;
					for (int r = 0; r < idx; r++)
					{
						if (path[r] == board[ty][tx])
						{
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						path[idx] = board[ty][tx];
						idx++;
					}
				}
			}
			int res = 1;
			for (int i = 0; i < idx; i++)
			{
				res += block_n[path[i]];
			}
			cout << res % 10;
		}
		cout << '\n';
	}


	return 0;
}