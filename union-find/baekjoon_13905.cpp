#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 13905 - ����
// union-find
// ��� 4

// �������� �������� �� �ϴ� ���, �ִ� ��� ������ 0�̶�� �� ������

#define INF 999999999
int n, m;
int s, e;
int min_cnt = INF;

struct edge
{
	int u;
	int v;
	int weight;
};
bool cmp(edge e1, edge e2)
{
	return e1.weight > e2.weight;
}
vector<edge> vec;
int parent[100001];
int find(int a)
{
	if (parent[a] == a) return a;
	return parent[a] = find(parent[a]);
}
int Union(int a, int b)
{
	int a_r = find(a);
	int b_r = find(b);
	if (a_r == b_r) return -1;
	parent[b_r] = a_r;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> s >> e;
	for (int i = 1; i <= n; i++) parent[i] = i;

	int h1, h2, k;
	for (int i = 0; i < m; i++)
	{
		cin >> h1 >> h2 >> k;
		vec.push_back({ h1, h2, k });
	}
	sort(vec.begin(), vec.end(), cmp);

	// union-find
	for (int i = 0; i < m; i++)
	{
		if (find(s) == find(e)) break;
		if (Union(vec[i].u, vec[i].v) == 1) // union�� ���� ���� üũ
		{ 
			if (min_cnt > vec[i].weight) min_cnt = vec[i].weight;
		}
	}

	if (find(s) != find(e)) cout << 0; // �������� �� �ϴ� ��� ����ϴ� ������ 0��
	else cout << min_cnt;

	return 0;
}