#include <iostream>
#include <vector>

using namespace std;

// ���� 14567 - ��������
// tree, DFS
// ��� 5

// �������� ���ٰ� ���ƿ��鼭 ���� ���
// �ڽĵ� �� ���� ���� ���̷� ���

// �ð��ʰ� -> visit ó�� ������, Ȯ�� ������

struct vertex
{
	int idx;
	int visit = -1;
	int h;
};
vector<vertex> V;
vector<vector<int>> E;
int n, m;

// ��ȸ �Լ�
int traversal(int now)
{
	V[now].visit = 1;
	int height = 1;
	int tmp;

	for (int i = 0; i < E[now].size(); i++)
	{
		if (V[E[now][i]].visit == -1)
		{
			tmp = traversal(E[now][i]) + 1;
		}
		else tmp = V[E[now][i]].h + 1;
		if (tmp > height) height = tmp;
	}
	V[now].h = height;
	return height;
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
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		E[b].push_back(a);
	}
	for (int i = 1; i <= n; i++)
	{
		if (V[i].visit == 1) continue;
		traversal(i);
	}

	for (int i = 1; i <= n; i++) cout << V[i].h << ' ';

	return 0;
}