#include <iostream>
#include <queue>

using namespace std;

// ���� 1922 - ��Ʈ��ũ ����
// ��� 4
// MST

int n, m;

int parent[1001];

struct edge
{
	int start;
	int end;
	int weight;
};

int Find(int a)
{
	if (parent[a] == a) return a;
	return Find(parent[a]);
}

void Union(int a, int b)
{
	if (Find(a) == Find(b)) return;
	parent[Find(a)] = Find(b);
}

bool operator<(edge e1, edge e2)
{
	if (e1.weight > e2.weight) return true;
	return false;
}

priority_queue<edge> pq;

int kruskal()
{
	int cost = 0;
	while (!pq.empty())
	{
		edge tmp = pq.top();
		pq.pop();

		if (Find(tmp.start) == Find(tmp.end)) continue;
		Union(tmp.start, tmp.end);
		cost += tmp.weight;
	}
	return cost;
}

int main()
{
	cin >> n >> m;

	// parent �ʱ�ȭ
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}
	
	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}

	cout << kruskal();

	return 0;
}