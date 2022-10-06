#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// swea 1949 - ���� ����
// ���� ���� ã�ƶ�
// ������ ������ ���� ���� ������
// ���� �� -> ���� ���� ����, �����¿� �̵��� ����
// �� �� ���� K��ŭ ���� �� ����
// �ʿ��� ���, ���̸� 1���� �۰� ����� �͵� ���� (0 ����)
// ���� ã�� - DFS
// DFS �ϴµ�, ���� ���� �����(�� �� �� ������ ���� Ŀ��)
// �ű⼭ �ѹ� ��� �ٽ� DFS (DFS �Լ� �ٸ���)
// �̷��� �� ��� �ֵ� �� ��� max �� ���

int arr[9][9];
int arr_copy[9][9]; // ���ο� DFS �� �� ī���� ����
int chk[9][9];
int y_mov[] = { -1, 0, 1, 0 };
int x_mov[] = { 0, 1, 0, -1 };

int n, k;

vector<int> path_len; // ���� ���� -> ���⼭ ���� ã���� ��

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
			chk[y + y_mov[i]][x + x_mov[i]] == 0) // �ǳ� �� ���� �������� ����
		{
			// arr ī��
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

			// ���ο� DFS ������, chk�� �״�� ���
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

		// max ���� �ֵ� DFS ������
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

		// chk, arr �ʱ�ȭ
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