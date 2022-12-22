#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� 14938 - �����׶���
// dijkstra
// ��� 4

// dist : m ���Ϸ� dijkstra ����
// ���� dijkstra�� �׷����� ����Ǹ� �ش� ������ item ���Ѵ� (now_item)
// ��� �������� dijkstra �� �غ��� ���� now_item �� �ִ� ���

#define INF 1000000

struct vertex
{
	int idx;
	int dist = INF;
	int item; // ������
	int visit = -1;
};
bool operator<(vertex v1, vertex v2)
{
	if (v1.dist > v2.dist) return true;
	return false;
}
struct edge
{
	int oppo;
	int weight;
};
int n, m, r;
int now_item; // ���� ���� item
vector<vertex> V;
vector<vector<edge>> E;
priority_queue<vertex> pq;

void dijkstra(int start)
{
	V[start].dist = 0;
	now_item = 0;
	pq.push(V[start]);
	
	while (!pq.empty())
	{
		vertex tmp = pq.top();
		pq.pop();

		if (V[tmp.idx].visit == 1) continue;
		V[tmp.idx].visit = 1;
		if (V[tmp.idx].dist > m) continue;
		now_item += V[tmp.idx].item;

		for (int i = 0; i < E[tmp.idx].size(); i++)
		{
			if (V[E[tmp.idx][i].oppo].dist > V[tmp.idx].dist + E[tmp.idx][i].weight)
			{
				V[E[tmp.idx][i].oppo].dist = V[tmp.idx].dist + E[tmp.idx][i].weight;
				pq.push(V[E[tmp.idx][i].oppo]);
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> r;
	V.resize(n + 1);
	E.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		V[i].idx = i;
		cin >> V[i].item;
	}
	int a, b, w;
	for (int i = 0; i < r; i++)
	{
		cin >> a >> b >> w;
		E[a].push_back({ b, w });
		E[b].push_back({ a, w });
	}

	// �� �������� dijkstra -> �ִ� ã��
	int max1 = 0;
	for (int i = 1; i <= n; i++)
	{
		dijkstra(i);
		if (now_item > max1) max1 = now_item;
		// �ʱ�ȭ
		for (int i = 1; i <= n; i++)
		{
			V[i].dist = INF;
			V[i].visit = -1;
		}
	}

	cout << max1;

	return 0;
}