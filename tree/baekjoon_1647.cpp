#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 1647 - ���� ���� ��ȹ
// ��� 4
// MST
// union-find, kruskal
// ����߷� ���� ���ĺ� �Ŀ�
// ���� ��� �� ��

int n, m;

int parent[100001];

struct edge
{
	int start;
	int end;
	int weight;
};

bool cmp(edge e1, edge e2)
{
	if (e1.weight < e2.weight) return true;
	return false;
}

vector<edge> E;


int Find(int a)
{
	if (parent[a] == a) return a;

	return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	if (Find(a) == Find(b)) return;

	parent[Find(a)] = b;
}

int kruskal() // ������
{
	int max = 0;
	int res = 0;

	for (int i = 0; i < E.size(); i++)
	{		
		if (Find(E[i].start) == Find(E[i].end)) continue;
		Union(E[i].start, E[i].end);

		res += E[i].weight;

		if (max < E[i].weight) max = E[i].weight;
	}

	res -= max;
	return res;
}


int main()
{
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
	}

	int a, b, c;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		E.push_back({ a, b, c });
	}

	sort(E.begin(), E.end(), cmp);
	

	// MST ������ �� ���ϱ�
	cout << kruskal();


	return 0;
}