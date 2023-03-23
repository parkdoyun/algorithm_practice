#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 2406 - 안정적인 네트워크
// union-find
// 골드 3

// 1번이 끊어지지 않는 이상 전부 연결되어 있음
// 1번만 끊어보면 됨
// 1번 없는 상태에서 (연결 안 한 상태) 전부 연결되었는지 확인

int n, m;
int x = 0;
int k = 0;
int root[1001];

int find(int a)
{
	if (root[a] == a) return a;
	return root[a] = find(root[a]);
}

bool Union(int a, int b)
{
	int a_r = find(a);
	int b_r = find(b);
	if (a_r == b_r) return false;
	root[b_r] = a_r;
	return true;
}

struct node
{
	int weight;
	int u;
	int v;
};
bool cmp(node n1, node n2)
{
	return n1.weight < n2.weight;
}
vector<node> vec;

struct connect
{
	int u;
	int v;
};
vector<connect> connect_com;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
	{
		root[i] = i;
		//Union(1, i);
	}

	int x1, y1;
	for (int i = 0; i < m; i++)
	{
		cin >> x1 >> y1;
		Union(x1, y1);
	}

	int w;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> w;
			if (i == 1 || i >= j) continue;
			vec.push_back({ w, i, j });
		}
	}

	sort(vec.begin(), vec.end(), cmp);

	// union
	for (int i = 0; i < vec.size(); i++)
	{
		if (Union(vec[i].u, vec[i].v))
		{
			x += vec[i].weight;
			k++;
			connect_com.push_back({ vec[i].u, vec[i].v });
		}
	}

	cout << x << ' ' << k << '\n';
	for (int i = 0; i < k; i++)
	{
		cout << connect_com[i].u << ' ' << connect_com[i].v << '\n';
	}

	return 0;
}