#include <iostream>

using namespace std;

// 백준 1613 - 역사
// floyd-warshall
// 골드 3

// floyd-warshall algorithm
// dijkstra가 한 정점에서 다른 모든 정점 사이 최단 거리 구한다면,
// floyd-warshall은 모든 정점에서 모든 정점 사이 최단 거리 구한다

// i->j 비용 => max(i->j 비용, i->k 비용 + k->j 비용)
// 점화식 DP[i][j] = max(DP[i][j], DP[i][k] + DP[k][j]);

int n, k;
int DP[401][401];

void floydWarshall()
{
	for (int k = 1; k <= n; k++) // 거치는 노드
	{
		for (int i = 1; i <= n; i++) // 출발 노드
		{
			for (int j = 1; j <= n; j++) // 도착 노드
			{
				if (DP[i][j] == 0) // 아직 모름
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
		DP[a][b] = -1; // 확실히 앞에 일어남
		DP[b][a] = 1; // 확실히 뒤에 일어남
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