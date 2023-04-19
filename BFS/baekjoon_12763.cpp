#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// ���� 12763 - �����ϸ� �� ��
// BFS
// ��� 2

// ���� �غ��� �ǰڴ�
// ���� �� �Ѵٸ� -1

#define INF 999999999

int n, t, m, l;

struct node
{
	int num; // ���� �ǹ� ��ȣ
	int time; // �ɸ� �ð�
	int money; // ���� ��
};
bool operator<(node n1, node n2)
{
	if (n1.money > n2.money) return true;
	else if (n1.money == n2.money && n1.time > n2.time) return true;
	return false;
}
priority_queue<node> pq;

vector<vector<node>> E;
int min_money = INF;

void BFS()
{
	pq.push({ 1, 0, 0 });

	while (!pq.empty())
	{
		node tmp = pq.top();
		pq.pop();

		// visit ó���ϸ� �� �� (�ð��̳� �� �������� visit ó���ϸ� ���� �� �� ���̳� �ð��� �ɸ��� ����� �� ���� �� ����)
		//if (visit[tmp.num] == 1) continue;
		//visit[tmp.num] = 1;

		if (tmp.num == n)
		{
			if(min_money > tmp.money) min_money = tmp.money;
			continue;
		}

		for (int i = 0; i < E[tmp.num].size(); i++)
		{
			if (tmp.money + E[tmp.num][i].money <= m &&	tmp.time + E[tmp.num][i].time <= t)
			{
				pq.push({ E[tmp.num][i].num, tmp.time + E[tmp.num][i].time, tmp.money + E[tmp.num][i].money });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> t >> m >> l;

	E.resize(n + 1);

	int u, v, t1, m1;
	for (int i = 0; i < l; i++)
	{
		cin >> u >> v >> t1 >> m1;
		E[u].push_back({ v, t1, m1 });
		E[v].push_back({ u, t1, m1 });
	}

	BFS();

	if(min_money == INF) cout << -1;
	else cout << min_money;

	return 0;
}