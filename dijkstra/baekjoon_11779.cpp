#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 백준 11779 - 최소비용 구하기 2
// dijkstra
// 골드 3

int n, m;

struct vertex
{
	int num;
	int dist = 100000000;
	int visit = 0;
	vector<int> path;
};

struct bus
{
	int arrive;
	int cost;
};

bool operator<(vertex v1, vertex v2)
{
	if (v1.dist > v2.dist) return true;
	return false;
}
vector<vertex> V;
vector<vector<bus>> E;
priority_queue<vertex> pq;

int main()
{
	cin >> n >> m;

	V.resize(n + 1);
	E.resize(n + 1);
	for (int i = 1; i <= n; i++) V[i].num = i;
	
	int s, e, c, start, arrive;
	for (int i = 0; i < m; i++)
	{
		cin >> s >> e >> c;
		E[s].push_back({ e, c });
	}

	cin >> start >> arrive;

	V[start].dist = 0;
	pq.push(V[start]);
	
	while (!pq.empty())
	{
		vertex tmp = pq.top();
		pq.pop();
		if (tmp.num == arrive) break;
		if (V[tmp.num].visit == 2) continue;
		V[tmp.num].visit = 2;

		for (int i = 0; i < E[tmp.num].size(); i++)
		{
			if (V[E[tmp.num][i].arrive].visit == 0 && V[E[tmp.num][i].arrive].dist >= tmp.dist + E[tmp.num][i].cost) // 문제 자체가 비용 같은 것도 집어넣도록 설계
			{
				V[E[tmp.num][i].arrive].dist = tmp.dist + E[tmp.num][i].cost;
				// path 변경
				vector<int> tmp_p = V[tmp.num].path;
				tmp_p.push_back(tmp.num);
				V[E[tmp.num][i].arrive].path = tmp_p;
				pq.push(V[E[tmp.num][i].arrive]);
			}
		}

	}
	cout << V[arrive].dist << '\n' << V[arrive].path.size() + 1 << '\n';
	for (int i = 0; i < V[arrive].path.size(); i++)
	{
		cout << V[arrive].path[i] << ' ';
	}
	cout << arrive;

	
	return 0;
}