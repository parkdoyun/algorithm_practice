#include <iostream>
#include <vector>

using namespace std;

// swea 2115 - ���� ä��
// dfs, backtracking

// ���� ���η� M�� ���ӵǵ���
// �θ��� �ϲ� -> �ϳ� �����ϰ� �ٸ� �ϳ� �����ϸ� �ɵ� for�� 2��
// ��� ���� �� �ִ� ���
// ���� 2�� �����ϴ� �Լ� + ����ϴ� �Լ� 2��

int max1;
int n, m, c;
int arr[11][11];
struct node
{
	int y;
	int x;
};

node n1, n2; // ���� 2��
int path[5];
int total1, total2;

void DFS(int lv, int num) // n : ��� ��������
{
	if (lv == m)
	{
		int res = 0;
		int sum = 0; // ���� ���� ��, c ������ X
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
	// �� ���뿡�� �ִ�� ���� �� �ִ� �� ã�� => backtracking
	// 1�� ����
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
	if (x + m <= n - m) // �ش� ������ ���� �����ϸ�
	{
		for (int i = x + m; i < n; i++)
		{
			if (i > n - m) break;
			n2.y = y;
			n2.x = i;
			// ���� ���
			int res = cal();
			if (res > max1) max1 = res;
		}
	}
	// ���� ������
	for (int j = y + 1; j < n; j++)
	{
		for (int i = 0; i < n; i++)
		{
			if (i > n - m) break;
			n2.y = j;
			n2.x = i;
			// ���� ���
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
				// ���� ����
				n1.y = i;
				n1.x = j;
				choose(i, j);
			}
		}


		cout << '#' << tc << ' ' << max1 << '\n';
	}

	return 0;
}