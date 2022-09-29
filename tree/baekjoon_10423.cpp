#include <iostream>
#include <queue>

using namespace std;

// ���� 10423 - ���Ⱑ ������
// ��� 2
// MST
// ������ �迭�� �ϳ� �� �����Ͽ� Ʈ���� ��ǥ�� �����Ҹ� ����Ѵ�.

struct edge
{
	int start;
	int end;
	int weight;
};

bool operator<(edge e1, edge e2)
{
	if (e1.weight > e2.weight) return true;
	return false;
}

int parent[1001];
int yny[1001]; // ������ ���� �� -> 0

priority_queue<edge> pq;

int Find(int a)
{
	if (parent[a] == a) return a;
	return Find(parent[a]);
}

void Union(int a, int b)
{
	//if (Find(a) == Find(b)) return;
	if (yny[Find(a)] == 0 && yny[Find(b)] != 0)
	{
		parent[Find(a)] = Find(b);
	}
	else if (yny[Find(a)] != 0 && yny[Find(b)] == 0)
	{
		parent[Find(b)] = Find(a);
	}
	else parent[Find(a)] = Find(b);
}

int kruskal()
{
	int sum = 0;
	while (!pq.empty())
	{
		edge tmp = pq.top();
		pq.pop();

		int max_a = Find(tmp.start);
		int max_b = Find(tmp.end);
		if (max_a == max_b) continue;
		if (!(yny[max_a] == 0 || yny[max_b] == 0)) continue;

		Union(tmp.start, tmp.end);
		sum += tmp.weight;
	}
	return sum;
}
int main()
{
	int n, m, k;
	cin >> n >> m >> k;

	int a;
	for (int i = 0; i < k; i++)
	{
		cin >> a;
		yny[a] = a;
	}

	// parent �ʱ�ȭ
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	int u, v, d;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> d;
		pq.push({ u, v, d });
	}

	int res = kruskal();
	cout << res;

	return 0;
}