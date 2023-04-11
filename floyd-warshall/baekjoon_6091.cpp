#include <iostream>
#include <string>

using namespace std;

// 백준 6091 - 핑크 플로이드
// floyd-warshall
// 골드 1

// floyd-warshall algorithm
// dijkstra가 한 정점에서 다른 모든 정점 사이 최단 거리 구한다면,
// floyd-warshall은 모든 정점에서 모든 정점 사이 최단 거리 구한다
// i->j 비용 => max(i->j 비용, i->k 비용 + k->j 비용)
// 점화식 DP[i][j] = max(DP[i][j], DP[i][k] + DP[k][j]);

// 최단 거리들로부터 어떤 간선이 포함되었는지 찾아야 함
// DP[i][j]가 모든 DP[i][k] + DP[k][j] 조합보다 작다면 -> 간선 존재

#define INF 922337203685477580

int n;
long long int DP[1025][1025]; // 최단 거리 (총 거리가 아니라 한 정점에서 다른 정점의 거리가 15000이라는 뜻)
long long int arr[1025][1025]; // 인접리스트

void floyd_warshall()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (DP[i][j] >= DP[i][k] + DP[k][j]) // 이게 한개라도 있으면 i, j 인접 X
				{
					arr[i][j]++; // 모든 경로에서 이게 없다면 둘만 이어지는 길 있는 것 
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

	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		DP[i][i] = INF;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			cin >> DP[i][j];
			DP[j][i] = DP[i][j]; // 양방향
		}
	}

	floyd_warshall();

	int cnt;
	for (int i = 1; i <= n; i++)
	{
		string s = "";
		cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 0)
			{
				cnt++;
				s = s + to_string(j) + " ";
			}
		}
		cout << cnt << ' ' << s << '\n';
	}

	return 0;
}