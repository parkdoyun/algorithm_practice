#include <iostream>

using namespace std;

int n, x;
int board[21][21];
int chk[21][21];

// swea 4014 - Ȱ�ַ� �Ǽ�
// two pointer
// ������ �̵��ϸ鼭 Ȱ�ַ� ǥ��
// 2 �̻� ���̳��� ����
// 1 ��ŭ Ŭ �� -> �ڷ� üũ 1
// 1 ��ŭ ���� �� -> ������ üũ 1

int chkH(int h)
{
	for (int i = 0; i < n; i++)
	{
		chk[h][i] = 0;
	}

	for (int i = 1; i < n; i++)
	{
		if (board[h][i - 1] == board[h][i]) continue;
		else if (board[h][i - 1] + 1 == board[h][i])
		{ // ���� ���̸�ŭ �������� (�ڷ�)
			for (int j = 1; j <= x; j++)
			{
				if (i - j < 0) return -1;
				if (chk[h][i - j] == 1) return -1;
				chk[h][i - j] = 1;
			}
		}
		else if (board[h][i - 1] - 1 == board[h][i])
		{
			// ���� ���̸�ŭ �������� (������)
			for (int j = 0; j < x; j++)
			{
				if (i + j >= n) return -1;
				if (chk[h][i + j] == 1) return -1;
				chk[h][i + j] = 1;
			}
		}
		else
		{
			return -1;
		}
	}
	return 1;
}

int chkW(int w)
{
	for (int i = 0; i < n; i++)
	{
		chk[i][w] = 0;
	}

	for (int i = 1; i < n; i++)
	{
		if (board[i - 1][w] == board[i][w]) continue;
		else if (board[i - 1][w] + 1 == board[i][w])
		{ // ���� ���̸�ŭ �������� (�ڷ�)
			for (int j = 1; j <= x; j++)
			{
				if (i - j < 0) return -1;
				if (chk[i - j][w] == 1) return -1;
				chk[i - j][w] = 1;
			}
		}
		else if (board[i - 1][w] - 1 == board[i][w])
		{
			// ���� ���̸�ŭ �������� (������)
			for (int j = 0; j < x; j++)
			{
				if (i + j >= n) return -1;
				if (chk[i + j][w] == 1) return -1;
				chk[i + j][w] = 1;
			}
		}
		else
		{
			return -1;
		}
	}
	return 1;
}


int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> x;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
			}
		}

		// Ȱ�ַ� üũ
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			// ���� i�� Ȯ��
			if (chkH(i) == 1) res++;
			// ���� i�� Ȯ��
			if (chkW(i) == 1) res++;
		}

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}