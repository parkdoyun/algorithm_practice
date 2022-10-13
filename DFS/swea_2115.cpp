#include <iostream>
#include <vector>

using namespace std;

// swea 2115 - 벌꿀 채취
// dfs, backtracking

// 벌통 가로로 M개 연속되도록
// 두명의 일꾼 -> 하나 선택하고 다른 하나 선택하면 될듯 for문 2개
// 모든 수익 중 최댓값 출력
// 벌통 2개 선택하는 함수 + 계산하는 함수 2개

int max1;
int n, m, c;
int arr[11][11];
struct node
{
	int y;
	int x;
};

node n1, n2; // 벌통 2개
int path[5];
int total1, total2;

void DFS(int lv, int num) // n : 몇번 벌통인지
{
	if (lv == m)
	{
		int res = 0;
		int sum = 0; // 벌통 정보 합, c 넘으면 X
		for (int i = 0; i < m; i++)
		{
			if (path[i] == 1)
			{
				if (num == 1)
				{
					res += arr[n1.y][n1.x + i] * arr[n1.y][n1.x + i];
					sum += arr[n1.y][n1.x + i];
				}
				else
				{
					res += arr[n2.y][n2.x + i] * arr[n2.y][n2.x + i];
					sum += arr[n2.y][n2.x + i];
				}
			}
		}
		if (sum <= c)
		{
			if (num == 1)
			{
				if (total1 < res) total1 = res;
			}
			else
			{
				if (total2 < res) total2 = res;
			}
		}
		return;
	}

	path[lv] = 1;
	DFS(lv + 1, num);

	path[lv] = 0;
	DFS(lv + 1, num);
}

int cal()
{
	// 각 벌통에서 최대로 얻을 수 있는 값 찾기 => backtracking
	// 1번 벌통
	total1 = 0;

	path[0] = 1;
	DFS(1, 1);

	path[0] = 0;
	DFS(1, 1);

	total2 = 0;
	path[0] = 1;
	DFS(1, 2);

	path[0] = 0;
	DFS(1, 2);

	return total1 + total2;
}

void choose(int y, int x)
{
	if (x + m <= n - m) // 해당 열에서 선택 가능하면
	{
		for (int i = x + m; i < n; i++)
		{
			if (i > n - m) break;
			n2.y = y;
			n2.x = i;
			// 벌통 계산
			int res = cal();
			if (res > max1) max1 = res;
		}
	}
	// 다음 열부터
	for (int j = y + 1; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i > n - m) break;
			n2.y = j;
			n2.x = i;
			// 벌통 계산
			int res = cal();
			if (res > max1) max1 = res;
		}
	}
}


int main()
{
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m >> c;
		max1 = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> arr[i][j];
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (j > n - m) break;
				// 벌통 선택
				n1.y = i;
				n1.x = j;
				choose(i, j);
			}
		}


		cout << '#' << tc << ' ' << max1 << '\n';
	}

	return 0;
}