#include <iostream>
#include <cmath>

using namespace std;

// swea 4012 - �丮��
// brute-force

// ��� ������ �� �ּڰ� ���
// backtracking���� ��� ������ ���ϱ� (n/2�� ����)
// backtracking���� ���� �������� ���� �� �ִ� �ó��� ���� �� �ּ� ã��
// ex) n = 6, [1, 2, 3] ���õǸ� => �� = s12 + s21 + s13 + s31 + s23 + s32 �̷��� ����

int n;
int arr[17][17];
int min1;
int path[16]; // backtracking
int a_path[9];
int b_path[9];

int cal() // A : path ǥ��, B : path ǥ�� X
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
	// a ��� => for�� 2�� �����鼭 ���
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
	if (lv == n / 2) // �� ���
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