#include <iostream>

using namespace std;

// ���� 17406 - �迭 ������ 4
// ��� 4
// dfs, backtracking

// ��� ȸ�� ���� �� �غ��� �ּ� ���

int path[7];
int check[7];
int operation[7][3]; // ���� ������ �迭
int arr[51][51]; // �迭 ����
int arr_cp[51][51];
int min1 = 1000000000;
int n, m, k;

void arrCopy()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++) arr_cp[i][j] = arr[i][j];
	}
}

void rotate(int start_y, int start_x, int end_y, int end_x) // ȸ�� ����
{
	// ����
	int tmp_val = arr_cp[start_y][end_x];
	int tmp_val2 = arr_cp[end_y][start_x];
	int j = start_x;
	for (int i = end_x; i > start_x; i--)
	{
		arr_cp[start_y][i] = arr_cp[start_y][i - 1];
		arr_cp[end_y][j] = arr_cp[end_y][j + 1];
		j++;
	}

	// ����
	j = start_y;
	for (int i = end_y; i > start_y + 1; i--)
	{
		arr_cp[i][end_x] = arr_cp[i - 1][end_x];
		arr_cp[j][start_x] = arr_cp[j + 1][start_x];
		j++;
	}
	arr_cp[start_y + 1][end_x] = tmp_val;
	arr_cp[end_y - 1][start_x] = tmp_val2;
}

int cal()
{
	int res = 0;
	// ��� �� �ּҰ� res��
	arrCopy();
	for (int i = 0; i < k; i++)
	{
		int start_y = operation[path[i]][0] - operation[path[i]][2] - 1;
		int start_x = operation[path[i]][1] - operation[path[i]][2] - 1;
		int end_y = operation[path[i]][0] + operation[path[i]][2] - 1;
		int end_x = operation[path[i]][1] + operation[path[i]][2] - 1;
		
		// �� ó�� �� �����ϰ� ���� �� ����
		while (!(start_y == end_y && start_x == end_x))
		{
			rotate(start_y, start_x, end_y, end_x);
			start_y++;
			start_x++;
			end_y--;
			end_x--;
		}
	}

	// �ּҰ� ã��
	for (int i = 0; i < m; i++)
	{
		res += arr_cp[0][i];
	}

	for (int i = 1; i < n; i++)
	{
		int tmp = 0;
		for (int j = 0; j < m; j++)
		{
			tmp += arr_cp[i][j];
		}
		if (tmp < res) res = tmp;
	}

	return res;
}
void DFS(int lv)
{
	if (lv == k)
	{
		// �迭 �ּҰ� ���
		int tmp = cal();
		if (tmp < min1) min1 = tmp;
		return;
	}

	for (int i = 1; i <= k; i++)
	{
		if (check[i] == 1) continue;
		check[i] = 1;
		path[lv] = i;
		DFS(lv + 1);
		path[lv] = 0;
		check[i] = 0;
	}
}
int main()
{
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= k; i++)
	{
		for (int j = 0; j < 3; j++) cin >> operation[i][j];
	}

	for (int i = 1; i <= k; i++)
	{
		check[i] = 1;
		path[0] = i;
		DFS(1);
		path[0] = 0;
		check[i] = 0;
	}

	cout << min1;

	return 0;
}