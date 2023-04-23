#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// ���� 17270 - �������� �����
// dijkstra
// ��� 3

// �����̿� ���� �Ѵ� ���ͽ�Ʈ�� ������
// �ϳ��� ���鼭 ���� ���� �� üũ�ϸ� ��

// ���� �� �о�� ��
// ������ �����ϴ� ��Ʈ�� ��� ��Ʈ �� *�ִ� �Ÿ�* ������ ��
// Ư��, �ִ� �Ÿ� ������ �ֵ� �� ���� �����ϴ� �ֵ� ���� ���� �ִ�

#define INF 999999999

int v, m, j, s;
struct vertex
{
	int idx;
	int visit = -1;
	int dist = INF;
};
bool operator<(vertex v1, vertex v2)
{
	return v1.dist > v2.dist;
}
vector<vertex> V;
priority_queue<vertex> pq;

struct edge
{
	int oppo;
	int weight;
};
vector<vector<edge>> E;

void dijkstra(int start)
{
	while (!pq.empty()) pq.pop();
	for (int i = 1; i <= v; i++)
	{
		V[i].idx = i;
		V[i].dist = INF;
		V[i].visit = -1;
	}

	V[start].dist = 0;
	pq.push(V[start]);

	while (!pq.empty())
	{
		vertex tmp = pq.top();
		pq.pop();

		if (V[tmp.idx].visit == 1) continue;
		V[tmp.idx].visit = 1;

		for (int i = 0; i < E[tmp.idx].size(); i++)
		{
			if (V[E[tmp.idx][i].oppo].visit == -1 && V[E[tmp.idx][i].oppo].dist > E[tmp.idx][i].weight + tmp.dist)
			{
				V[E[tmp.idx][i].oppo].dist = E[tmp.idx][i].weight + tmp.dist;
				pq.push(V[E[tmp.idx][i].oppo]);
			}
		}
	}
}

// ������ ���� üũ ���Ͽ�
struct node
{
	int num; // ��ȣ
	int total_dist; // ��ü �Ÿ�
	int j_dist; // �����̷κ��� �Ÿ�
};
bool cmp(node n1, node n2)
{
	if (n1.total_dist < n2.total_dist) return true;
	else if (n1.total_dist == n2.total_dist && n1.j_dist < n2.j_dist) return true;
	else if (n1.total_dist == n2.total_dist && n1.j_dist == n2.j_dist && n1.num < n2.num) return true;
	return false;
}
vector<node> result_vec;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> v >> m;
	V.resize(v + 1);
	E.resize(v + 1);

	int a, b, c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		E[a].push_back({ b, c });
		E[b].push_back({ a, c });
	}
	cin >> j >> s;

	vector<int> time; // �����̰� �ɸ��� �ð�
	time.resize(v + 1);

	// ������ dijkstra
	dijkstra(j);
	for (int i = 1; i <= v; i++)
	{
		time[i] = V[i].dist;
	}

	// ���� dijkstra
	dijkstra(s);

	int min_val = INF; // �ִ� �Ÿ� ������ �ֵ� �� ���� ���� ����
	for (int i = 1; i <= v; i++)
	{
		if (i == s || i == j) continue;
		if (min_val > time[i] + V[i].dist) min_val = time[i] + V[i].dist;
		if (time[i] <= V[i].dist)
		{
			result_vec.push_back({ i, time[i] + V[i].dist, time[i] });
		}
	}

	sort(result_vec.begin(), result_vec.end(), cmp);
	if (result_vec.empty() || result_vec[0].total_dist != min_val) cout << -1;
	else cout << result_vec[0].num;

	return 0;
}