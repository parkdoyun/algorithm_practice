#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 백준 1238 - 파티
// dikjstra
// 골드 3

struct vertex
{
	int num;
	int dist = 100000;
	int visit = 0;

};
struct edge
{
	int end;
	int weight;
};
bool operator<(vertex v1, vertex v2)
{
	if (v1.dist > v2.dist) return true;
	return false;
}
int n, m, x;
vector<vertex> V;
vector<vector<edge>> E;
priority_queue<vertex> pq;

int main()
{
	cin >> n >> m >> x;

	E.resize(n + 1);
	V.resize(n + 1);

	for (int i = 1; i <= n; i++) V[i].num = i;

	int a, b, t;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> t;
		E[a].push_back({ b, t });
	}

	int dist_arr[1001] = { 0 }; 
	int max_time = 0;
	for (int i = 1; i <= n; i++)
	{
		// dijkstra
		V[i].dist = 0;
		pq.push(V[i]);

		while (!pq.empty())
		{
			vertex tmp = pq.top();
			pq.pop();
			if (V[tmp.num].visit == 2) continue;
			V[tmp.num].visit = 2;

			for (int j = 0; j < E[tmp.num].size(); j++)
			{
				if (V[E[tmp.num][j].end].visit != 2 && tmp.dist + E[tmp.num][j].weight < V[E[tmp.num][j].end].dist)
				{
					V[E[tmp.num][j].end].dist = tmp.dist + E[tmp.num][j].weight;
					pq.push(V[E[tmp.num][j].end]);
				}
			}
			
		}

		// X까지의 시간
		if (i != x)
		{
			dist_arr[i] += V[x].dist;
			//std::cout << i << " : " << V[x].dist << endl;
		}
		else // i == x
		{
			//std::cout << endl << "=========x=======" << endl;
			for (int j = 1; j <= n; j++)
			{
				dist_arr[j] += V[j].dist;
				//std::cout << j << " : " << V[j].dist << endl;
			}
			//std::cout << endl;
		}


		// 초기화
		while (!pq.empty()) pq.pop();
		for (int i = 1; i <= n; i++)
		{
			V[i].visit = 0;
			V[i].dist = 100000;
		}
	}
	
	for (int i = 1; i <= n; i++)
	{
		//cout << i << " : " << dist_arr[i] << endl;
		if (max_time < dist_arr[i]) max_time = dist_arr[i];
	}

	std::cout << max_time;

	return 0;
}