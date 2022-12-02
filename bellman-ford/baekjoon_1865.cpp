#include <iostream>
#include <vector>

using namespace std;

// ���� 1865 - ��Ȧ
// ���� ����Ŭ ������ ������ ���ڸ��� ���ư� �� ����
// ���� ����Ŭ �� ����� ������ NO
// ���� ����Ŭ ����� ������� ������ ���ŵǸ� YES (������)

// �̷��� bellman-ford�� ��� ������ ���� 2 * n��ŭ ���鼭 Ȯ���ϸ�
// ���� ������ �ð��ʰ�
// �� ������ ���Ͽ� n-1�� ���鼭 V[j].time != INF �κ��� ���� �ȴ� 

// bellman-ford
// ������ ����ġ ������ �� ���
// �Ź� ��� ���� ���� Ȯ���Ͽ� �ִ� �Ÿ� ���� �� �ִٸ� ���δ�.
// ���� ����Ŭ �����ؾ� ��
// �ð� ���⵵ O(N^2)
// dijkstra���� �ð� ���⵵ ũ�Ƿ� ����ġ ��� ������ ���� ��� X

// ����Ŭ ����ٸ� -1 ���
// ����Ŭ : n - 1�� ��ȸ ���Ŀ��� ��� ���ŵǴ� ���� �ִٸ� ���� ����Ŭ ��

#define INF 2000000000

int n, m, w;

struct vertex
{
	int idx;
	long long time = INF; // ��� �ʰ� ���´ٸ� -> long long���� �ٲ���
};

struct edge
{
	int oppo;
	long long weight;
};

vector<vertex> V;
vector<vector<edge>> E;

int bellmanford(int start) // 0 : NO (cycle X), 1 : YES
{
	V[start].time = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			for (int k = 0; k < E[j].size(); k++)
			{
				if (V[E[j][k].oppo].time > V[j].time + E[j][k].weight)
				{
					if (i == n - 1) // cycle ���� ������ OK
					{
						return 1;
					}
					V[E[j][k].oppo].time = V[j].time + E[j][k].weight;
				}
			}
		}
	}

	return 0;
}

void vertexClr()
{
	for (int i = 1; i <= n; i++) V[i].time = INF;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m >> w;
		V.resize(n + 1);
		E.resize(n + 1);
		for (int i = 1; i <= n; i++) V[i].idx = i;

		int s, e;
		long long t;
		for (int i = 0; i < m; i++)
		{
			cin >> s >> e >> t;
			E[s].push_back({ e, t });
			E[e].push_back({ s, t });
		}

		// ��Ȧ 
		for (int i = 0; i < w; i++)
		{
			cin >> s >> e >> t;
			E[s].push_back({ e, t * -1 });
		}

		/*
		int flag = 0;
		for (int i = 1; i <= n; i++)
		{
			// �ʱ�ȭ
			vertexClr();
			if (bellmanford(i) == 1)
			{
				cout << "YES\n";
				flag = 1;
				break;
			}
		}
		if (flag == 0) cout << "NO\n";
		*/

		if (bellmanford(1) == 1) cout << "YES\n";
		else cout << "NO\n";

		V.clear();
		for (int i = 0; i <= n; i++)
		{
			E[i].clear();
		}
	}

	return 0;
}