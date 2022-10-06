#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// swea 1949 - 등산로 조성
// 최장 등산로 찾아라
// 시작은 무조건 제일 높은 곳부터
// 높은 곳 -> 낮은 곳만 가능, 상하좌우 이동만 가능
// 딱 한 곳을 K만큼 낮출 수 있음
// 필요한 경우, 높이를 1보다 작게 만드는 것도 가능 (0 이하)
// 등산로 찾기 - DFS
// DFS 하는데, 만약 길이 끊기면(더 갈 수 없으면 숫자 커서)
// 거기서 한번 깎고 다시 DFS (DFS 함수 다르게)
// 이렇게 한 모든 애들 다 담고 max 값 출력

int arr[9][9];
int arr_copy[9][9]; // 새로운 DFS 할 때 카피할 보드
int chk[9][9];
int y_mov[] = { -1, 0, 1, 0 };
int x_mov[] = { 0, 1, 0, -1 };

int n, k;

vector<int> path_len; // 등산로 길이 -> 여기서 최장 찾으면 됨

void DFS_new(int y, int x, int len)
{
	for (int i = 0; i < 4; i++)
	{
		if (y + y_mov[i] >= 0 && y + y_mov[i] < n &&
			x + x_mov[i] >= 0 && x + x_mov[i] < n &&
			arr_copy[y][x] > arr_copy[y + y_mov[i]][x + x_mov[i]] &&
			chk[y + y_mov[i]][x + x_mov[i]] == 0)
		{
			chk[y + y_mov[i]][x + x_mov[i]] = 1;
			DFS_new(y + y_mov[i], x + x_mov[i], len + 1);
			chk[y + y_mov[i]][x + x_mov[i]] = 0;
		}
	}
	path_len.push_back(len);
}


void DFS(int y, int x, int len)
{
	for (int i = 0; i < 4; i++)
	{
		if (y + y_mov[i] >= 0 && y + y_mov[i] < n &&
			x + x_mov[i] >= 0 && x + x_mov[i] < n &&
			arr[y][x] > arr[y + y_mov[i]][x + x_mov[i]] &&
			chk[y + y_mov[i]][x + x_mov[i]] == 0)
		{
			chk[y + y_mov[i]][x + x_mov[i]] = 1;
			DFS(y + y_mov[i], x + x_mov[i], len + 1);
			chk[y + y_mov[i]][x + x_mov[i]] = 0;
		}
		else if (y + y_mov[i] >= 0 && y + y_mov[i] < n &&
			x + x_mov[i] >= 0 && x + x_mov[i] < n &&
			arr[y][x] > arr[y + y_mov[i]][x + x_mov[i]] - k &&
			chk[y + y_mov[i]][x + x_mov[i]] == 0) // 건널 수 있을 때까지만 깎자
		{
			// arr 카피
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (j == y + y_mov[i] && k == x + x_mov[i])
					{
						arr_copy[j][k] = arr[y][x] - 1;
					}
					else arr_copy[j][k] = arr[j][k];
				}
			}

			// 새로운 DFS 돌리기, chk도 그대로 사용
			chk[y + y_mov[i]][x + x_mov[i]] = 1;
			DFS_new(y + y_mov[i], x + x_mov[i], len + 1);
			chk[y + y_mov[i]][x + x_mov[i]] = 0;
		}
	}
	path_len.push_back(len);
}

bool cmp(int a, int b)
{
	if (a > b) return true;
	return false;
}

int main()
{
	int T;
	cin >> T;

	for (int tc = 0; tc < T; tc++)
	{
		cin >> n >> k;
		int max = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
				if (max < arr[i][j]) max = arr[i][j];
			}
		}

		// max 값인 애들 DFS 돌리기
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (arr[i][j] == max)
				{
					// DFS
					chk[i][j] = 1;
					DFS(i, j, 1);
					chk[i][j] = 0;
				}
			}
		}

		sort(path_len.begin(), path_len.end(), cmp);
		cout << '#' << tc + 1 << ' ' << path_len[0] << '\n';

		// chk, arr 초기화
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				arr[i][j] = 0;
				chk[i][j] = 0;
			}
		}
		path_len.clear();
	}


	return 0;
}