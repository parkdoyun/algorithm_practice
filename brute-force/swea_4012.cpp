#include <iostream>
#include <cmath>

using namespace std;

// swea 4012 - 요리사
// brute-force

// 모든 가짓수 중 최솟값 출력
// backtracking으로 모든 가짓수 구하기 (n/2개 조합)
// backtracking으로 만든 가짓수로 만들 수 있는 시너지 값들 중 최소 찾기
// ex) n = 6, [1, 2, 3] 선택되면 => 맛 = s12 + s21 + s13 + s31 + s23 + s32 이렇게 구현

int n;
int arr[17][17];
int min1;
int path[16]; // backtracking
int a_path[9];
int b_path[9];

int cal() // A : path 표시, B : path 표시 X
{
	int a_idx = 0;
	int b_idx = 0;
	for (int i = 0; i < n; i++)
	{
		if (path[i] == 1) // a
		{
			a_path[a_idx] = i;
			a_idx++;
		}
		else // b
		{
			b_path[b_idx] = i;
			b_idx++;
		}
	}
	int a = 0;
	int b = 0;
	// a 계산 => for문 2개 돌리면서 계산
	for (int i = 0; i < a_idx; i++)
	{
		for (int j = 0; j < a_idx; j++)
		{
			if (i == j) continue;
			a += arr[a_path[i]][a_path[j]];
		}
	}

	for (int i = 0; i < b_idx; i++)
	{
		for (int j = 0; j < b_idx; j++)
		{
			if (i == j) continue;
			b += arr[b_path[i]][b_path[j]];
		}
	}
	return abs(a - b);
}

void DFS(int lv, int prev_val)
{
	if (lv == n / 2) // 맛 계산
	{
		int res = cal();
		if (res < min1) min1 = res;
		return;
	}

	for (int i = prev_val + 1; i < n; i++)
	{
		if (path[i] == 1) continue;
		path[i] = 1;
		DFS(lv + 1, i);
		path[i] = 0;
	}
}

int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		min1 = 100000000;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++) cin >> arr[i][j];
		}

		for (int i = 0; i < n / 2 + 1; i++)
		{
			path[i] = 1;
			DFS(1, i);
			path[i] = 0;
		}

		cout << '#' << tc << ' ' << min1 << '\n';
	}

	return 0;
}