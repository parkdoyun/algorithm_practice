#include <iostream>
#include <vector>

using namespace std;

// ���� 11657 - Ÿ�Ӹӽ�
// bellman-ford
// ��� 4

// bellman-ford
// ������ ����ġ ������ �� ���
// �Ź� ��� ���� ���� Ȯ���Ͽ� �ִ� �Ÿ� ���� �� �ִٸ� ���δ�.
// ���� ����Ŭ �����ؾ� ��
// �ð� ���⵵ O(N^2)
// dijkstra���� �ð� ���⵵ ũ�Ƿ� ����ġ ��� ������ ���� ��� X

// ����Ŭ ����ٸ� -1 ���
// ����Ŭ : n - 1�� ��ȸ ���Ŀ��� ��� ���ŵǴ� ���� �ִٸ� ���� ����Ŭ ��

#define INF 1000000000

int n, m;

struct vertex
{
	int idx;
	long long time = INF;
};

struct edge
{
	int oppo;
	long long weight;
};

vector<vertex> V;
vector<vector<edge>> E;

int bellmanFord(int start)
{
	V[start].time = 0;

	for (int i = 0; i < n; i++) // n-1�� Ȯ�� (n��°�� �پ��� �� ������ ���� ����Ŭ ����)
	{
		// ��� edge ���� Ȯ��
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < E[j].size(); k++)
			{
				if (V[j].time != INF && V[E[j][k].oppo].time > V[j].time + E[j][k].weight)
				{
					if (i == n - 1) return -1;
					V[E[j][k].oppo].time = V[j].time + E[j][k].weight;
				}
			}
		}
	}
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	V.resize(n + 1);
	E.resize(n + 1);

	for (int i = 1; i <= n; i++) V[i].idx = i;

	int a, b;
	long long c;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		E[a].push_back({ b, c });
	}

	if (bellmanFord(1) == -1)
	{
		cout << -1;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			if (V[i].time == INF) cout << -1 << '\n';
			else cout << V[i].time << '\n';
		}
	}
	

	return 0;
}