#include <iostream>
#include <queue>

using namespace std;

// swea 2112 - ��ȣ �ʸ�
// DFS, backtracking

// ��ǰ ���� ��� �˻� -> �ּҰ� ���
// path -> 0 (�� �ֱ�), 1(A, 0), 2(B, 1)

// �ð� �ʰ� ó�� => dfs �ִ��� �ڸ��� + �ٸ� �Լ��鵵 �ִ��� �ڸ���

int d, w, k;
int arr[14][21];
int arr_cp[14][21];
int min1;
int path[21];

int ok()
{
	// arr ���� + ��ǰ ����
	for (int i = 0; i < d; i++)
	{
		if (path[i] != 0)
		{
			for (int j = 0; j < w; j++)
			{
				arr_cp[i][j] = path[i] - 1;
			}
		}
		else
		{
			for (int j = 0; j < w; j++)
			{
				arr_cp[i][j] = arr[i][j];
			}
		}
		
	}

	// ǰ���˻� Ȯ��
	for (int i = 0; i < w; i++)
	{
		int j = 1;
		int same_cnt = 1;
		int chk = -1;
		while (j < d)
		{
			while (j < d && arr_cp[j][i] == arr_cp[j - 1][i])
			{
				same_cnt++;
				j++;
			}
			if (same_cnt >= k)
			{
				chk = 1;
				break;
			}
			same_cnt = 1;
			j++;
		}
		if (chk == -1) return -1; // �ڸ��� -> �ð��ʰ� ���̱� ����
	}

	return 1;
}

int tmp_cnt;
void DFS(int lv)
{
	tmp_cnt = 0;
	for (int i = 0; i < lv; i++) if (path[i] != 0) tmp_cnt++;
	if (tmp_cnt >= min1) return; // �ð� �ʰ������� ���⼭ dfs �ڸ�
	if (lv == d)
	{
		// �հ����� �ƴ���
		int res = ok();
		if (res == -1) return;

		// �հ��̶�� ��ǰ����Ƚ�� ���
		int cnt = 0;
		for (int i = 0; i < d; i++)
		{
			if (path[i] != 0) cnt++;
		}
		if (cnt < min1) min1 = cnt;
		return;
	}

	for (int i = 0; i < 3; i++)
	{
		path[lv] = i;
		DFS(lv + 1);
	}
}


int main()
{
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> d >> w >> k;
		min1 = 100;
		for (int i = 0; i < d; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> arr[i][j];
			}
		}
	
		for (int i = 0; i < w; i++) path[i] = 0;
		if (ok() == 1)
		{
			cout << '#' << tc << ' ' << 0 << '\n';
			continue;
		}

		for (int i = 0; i < 3; i++)
		{
			path[0] = i;
			DFS(1);
		}

		cout << '#' << tc << ' ' << min1 << '\n';
	}

	return 0;
}