#include <iostream>

using namespace std;

// swea 2105 - 디저트 카페
// brute-force

// 모든 경우의 수 다 해보자
// 가로 1 ~ n
// 세로 1 ~ n
// 범위 arr 벗어나면 바로 끝
// 아니면 path 배열 체크
// 모든 배열 값 1 이하이면 ok

int n;
int path[101]; // 숫자 체크 -> 중복되면 X
int arr[21][21]; // arr 보드
int max1; // 최댓값
int x_mov[] = { 1, -1, -1, 1 };
int y_mov[] = { 1, 1, -1, -1 };

void pathClear()
{
	for (int i = 1; i <= 100; i++) path[i] = 0;
}

void dessert(int y, int x)
{
	int tmp_y, tmp_x;
	for (int i = 1; i < n; i++)
	{
		for (int j = 1; j < n; j++)
		{
			// i : 가로로 가는 만큼 j : 세로로 가는 만큼
			int chk = -1; // 삐져나가는 것 있으면 세면 X
			pathClear();
			tmp_y = y;
			tmp_x = x;
			//path[arr[tmp_y][tmp_x]]++;
			for (int k = 0; k < 4; k++)
			{
				if (k % 2 == 0) // 가로로 이동 (i번)
				{
					for (int r = 0; r < i; r++)
					{
						tmp_y += y_mov[k];
						tmp_x += x_mov[k];
						if (tmp_y < 0 || tmp_y >= n ||
							tmp_x < 0 || tmp_x >= n)
						{
							chk = 1;
							break;
						}
						else if (path[arr[tmp_y][tmp_x]] > 0)
						{
							chk = 1;
							break;
						}
						else path[arr[tmp_y][tmp_x]]++;
					}
				}
				else // 세로로 이동 (j번)
				{
					for (int r = 0; r < j; r++)
					{
						tmp_y += y_mov[k];
						tmp_x += x_mov[k];
						if (tmp_y < 0 || tmp_y >= n ||
							tmp_x < 0 || tmp_x >= n)
						{
							chk = 1;
							break;
						}
						else if (path[arr[tmp_y][tmp_x]] > 0)
						{
							chk = 1;
							break;
						}
						else path[arr[tmp_y][tmp_x]]++;
					}
				}
				if (chk == 1) break;
			}
			if (chk == -1)
			{
				int res = i * 2 + j * 2;
				if (res > max1) max1 = res;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		max1 = -1;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}
		// 대각선 확인
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dessert(i, j);
			}
		}


		cout << '#' << tc << ' ' << max1 << '\n';
	}
	return 0;
}