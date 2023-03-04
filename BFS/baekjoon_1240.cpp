#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 백준 1240 - 노드사이의 거리
// BFS
// 골드 5

// tree의 dist 배열 생성
// 만약 INF 값이 아니라면, 이미 다른 점으로부터 도착한 경우 => 결과 출력

#define INF 999999999
int n, m;
int dist[2][1001];
int visit[2][1001]; // 각 두 노드로부터 순회의 visit 배열
struct vertex
{
	int num;
	int start; // 시작된 노드 번호
	int dist = 999999999;
};
struct edge
{
	int oppo;
	int weight;
};
queue<vertex> q;
vector<vector<edge>> E;

void traversal(int u, int v)
{
	// init
	for (int i = 1; i <= n; i++)
	{
		dist[0][i] = INF;
		dist[1][i] = INF;
		visit[0][i] = -1; // u
		visit[1][i] = -1; // v
	}
	dist[0][u] = 0; dist[1][v] = 0;

	while (!q.empty()) q.pop();

	q.push({ u, 0, 0 });
	q.push({ v, 1, 0 });

	while (!q.empty())
	{
		vertex tmp = q.front();
		q.pop();

		if (visit[tmp.start][tmp.num] == 1) continue;
		visit[tmp.start][tmp.num] = 1;

		if (tmp.start == 0 && dist[1][tmp.num] != INF) // 도착
		{
			cout << tmp.dist + dist[1][tmp.num] << '\n';
			break;
		}
		else if (tmp.start == 1 && dist[0][tmp.num] != INF) // 도착
		{
			cout << tmp.dist + dist[0][tmp.num] << '\n';
			break;
		}

		dist[tmp.start][tmp.num] = tmp.dist;
		for (int i = 0; i < E[tmp.num].size(); i++)
		{
			if (visit[tmp.start][E[tmp.num][i].oppo] == -1)
			{
				q.push({ E[tmp.num][i].oppo, tmp.start, tmp.dist + E[tmp.num][i].weight });
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	E.resize(n + 1);

	int u, v, w;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v >> w;
		E[u].push_back({ v, w });
		E[v].push_back({ u, w });
	}

	for (int i = 0; i < m; i++)
	{
		cin >> u >> v;
		traversal(u, v);
	}

	return 0;
}