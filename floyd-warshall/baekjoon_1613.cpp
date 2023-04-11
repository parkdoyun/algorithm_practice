#include <iostream>

using namespace std;

// ���� 1613 - ����
// floyd-warshall
// ��� 3

// floyd-warshall algorithm
// dijkstra�� �� �������� �ٸ� ��� ���� ���� �ִ� �Ÿ� ���Ѵٸ�,
// floyd-warshall�� ��� �������� ��� ���� ���� �ִ� �Ÿ� ���Ѵ�

// i->j ��� => max(i->j ���, i->k ��� + k->j ���)
// ��ȭ�� DP[i][j] = max(DP[i][j], DP[i][k] + DP[k][j]);

int n, k;
int DP[401][401];

void floydWarshall()
{
	for (int k = 1; k <= n; k++) // ��ġ�� ���
	{
		for (int i = 1; i <= n; i++) // ��� ���
		{
			for (int j = 1; j <= n; j++) // ���� ���
			{
				if (DP[i][j] == 0) // ���� ��
				{
					if (DP[i][k] == 1 && DP[k][j] == 1) DP[i][j] = 1;
					else if (DP[i][k] == -1 && DP[k][j] == -1) DP[i][j] = -1;
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	int a, b;
	for (int i = 0; i < k; i++)
	{
		cin >> a >> b;
		DP[a][b] = -1; // Ȯ���� �տ� �Ͼ
		DP[b][a] = 1; // Ȯ���� �ڿ� �Ͼ
	}

	floydWarshall();

	int s;
	cin >> s;

	for (int i = 0; i < s; i++)
	{
		cin >> a >> b;
		cout << DP[a][b] << '\n';
	}

	return 0;
}