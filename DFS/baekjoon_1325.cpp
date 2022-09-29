#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 백준 1325 - 효율적인 해킹
// DFS

struct node
{
	int idx;
	int res;
};

vector<vector<int>> vec;
int n;
int visit[10001] = { 0 };
vector<node> res;

int cnt = 0;
void visitClear()
{
	cnt = 0;
	for (int i = 1; i <= n; i++)
	{
		visit[i] = 0;
	}
}
void DFS(int idx)
{
	for (int i = 0; i < vec[idx].size(); i++)
	{
		if (visit[vec[idx][i]] == 0)
		{
			visit[vec[idx][i]] = 1;
			cnt++;
			DFS(vec[idx][i]);
		}
	}
}

bool cmp(node n1, node n2)
{
	if (n1.res > n2.res) return true;
	else if (n1.res == n2.res && n1.idx < n2.idx) return true;
	return false;
}

int main()
{
	int m, a, b;
	cin >> n >> m;
	vec.resize(n + 1);

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		vec[b].push_back(a);
	}
	
	for (int i = 0; i < n; i++)
	{
		visitClear();
		visit[i + 1] = 1;
		DFS(i + 1);
		node n = { i + 1, cnt };
		res.push_back(n);
	}

	sort(res.begin(), res.end(), cmp);

	int max = res[0].res;
	int tmp = 0;
	while (res[tmp].res == max && tmp < res.size())
	{
		cout << res[tmp].idx << ' ';
		tmp++;
	}


	return 0;
}