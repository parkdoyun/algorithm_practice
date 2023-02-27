#include <iostream>
#include <vector>
using namespace std;

// ���� 15681 - Ʈ���� ����
// tree, recursion
// ��� 5

// Ʈ�� �ѹ� ��ȸ�ϸ鼭 �������� �κ� ������ ǥ��
// ����Ʈ�� ��ȸ�ϸ鼭 ī��Ʈ
// �ð��ʰ�

// �Է� ���� ������ ��ȸ X
// ó�� ��ȸ�� �� ����Ʈ���� ī��Ʈ ����س���

int n, r, q;
struct vertex
{
	int idx;
	int visit = -1;
	int cnt = 0;
};
struct edge
{
	int oppo;
	int flag = 0; // 1 : �������� ����
};
vector<vertex> V;
vector<vector<edge>> E;
int cnt;

// edge check
int traversal(int now)
{
	int tmp_cnt = 1;
	V[now].visit = 1;
	for (int i = 0; i < E[now].size(); i++)
	{
		if (V[E[now][i].oppo].visit == -1)
		{
			E[now][i].flag = 1;
			tmp_cnt += traversal(E[now][i].oppo);
		}
	}
	V[now].cnt = tmp_cnt;
	return tmp_cnt;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> r >> q;
	V.resize(n + 1);
	E.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		V[i].idx = i;
	}

	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		E[u].push_back({ v });
		E[v].push_back({ u });
	}

	// Ʈ�� ��Ʈ���� �ѹ� ��ȸ
	// �������� ������ ǥ��
	traversal(r);

	for (int i = 0; i < q; i++)
	{
		cin >> u;
		cout << V[u].cnt << '\n';
	}

	return 0;
}