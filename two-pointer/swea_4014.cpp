#include <iostream>

using namespace std;

int n, x;
int board[21][21];
int chk[21][21];

// swea 4014 - 활주로 건설
// two pointer
// 포인터 이동하면서 활주로 표시
// 2 이상 차이나면 나감
// 1 만큼 클 때 -> 뒤로 체크 1
// 1 만큼 작을 때 -> 앞으로 체크 1

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
		{ // 경사로 길이만큼 가능한지 (뒤로)
			for (int j = 1; j <= x; j++)
			{
				if (i - j < 0) return -1;
				if (chk[h][i - j] == 1) return -1;
				chk[h][i - j] = 1;
			}
		}
		else if (board[h][i - 1] - 1 == board[h][i])
		{
			// 경사로 길이만큼 가능한지 (앞으로)
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
		{ // 경사로 길이만큼 가능한지 (뒤로)
			for (int j = 1; j <= x; j++)
			{
				if (i - j < 0) return -1;
				if (chk[i - j][w] == 1) return -1;
				chk[i - j][w] = 1;
			}
		}
		else if (board[i - 1][w] - 1 == board[i][w])
		{
			// 경사로 길이만큼 가능한지 (앞으로)
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

		// 활주로 체크
		int res = 0;
		for (int i = 0; i < n; i++)
		{
			// 가로 i행 확인
			if (chkH(i) == 1) res++;
			// 세로 i열 확인
			if (chkW(i) == 1) res++;
		}

		cout << '#' << tc << ' ' << res << '\n';
	}

	return 0;
}