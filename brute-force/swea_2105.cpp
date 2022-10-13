#include <iostream>

using namespace std;

// swea 2105 - ����Ʈ ī��
// brute-force

// ��� ����� �� �� �غ���
// ���� 1 ~ n
// ���� 1 ~ n
// ���� arr ����� �ٷ� ��
// �ƴϸ� path �迭 üũ
// ��� �迭 �� 1 �����̸� ok

int n;
int path[101]; // ���� üũ -> �ߺ��Ǹ� X
int arr[21][21]; // arr ����
int max1; // �ִ�
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
			// i : ���η� ���� ��ŭ j : ���η� ���� ��ŭ
			int chk = -1; // ���������� �� ������ ���� X
			pathClear();
			tmp_y = y;
			tmp_x = x;
			//path[arr[tmp_y][tmp_x]]++;
			for (int k = 0; k < 4; k++)
			{
				if (k % 2 == 0) // ���η� �̵� (i��)
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
				else // ���η� �̵� (j��)
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
		// �밢�� Ȯ��
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