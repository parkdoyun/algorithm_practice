#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 6497 - ���³�
// union-find
// ��� 4

// union�� �ּҸ� �����ϸ�
// �������� ������ �ʿ� ���� => ���� �����ϴ� ���

// union-find �ð� ���� �ڵ� �����α�

int n, m;
int root[200001];

struct node
{
	int a;
	int b;
	int weight;
};
bool operator<(node n1, node n2)
{
	if (n1.weight > n2.weight) return true;
	return false;
}
bool cmp(node n1, node n2)
{
	if (n1.weight < n2.weight) return true;
	return false;
}
vector<node> vec;
int cost;

int find(int a)
{
	if (root[a] == a) return a;
	return root[a] = find(root[a]); // �̷��� �ϸ� �ð� �����
}

void Union(int a, int b, int w)
{
	int a_r = find(a);
	int b_r = find(b);
	if (a_r == b_r)
	{
		cost += w;
		return;
	}
	root[b_r] = a_r;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int x, y, z;
	vec.resize(200001);
	while (true)
	{
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		for (int i = 0; i < n; i++) root[i] = i; // **�Ǽ� �� �ϵ��� ����**

		for (int i = 0; i < m; i++)
		{
			cin >> x >> y >> z;
			vec[i].a = x;
			vec[i].b = y;
			vec[i].weight = z;
		}

		sort(vec.begin(), vec.begin() + m, cmp);
		cost = 0;

		for (int i = 0; i < m; i++)
		{
			Union(vec[i].a, vec[i].b, vec[i].weight);
		}
		cout << cost << '\n';
	}

	return 0;
}