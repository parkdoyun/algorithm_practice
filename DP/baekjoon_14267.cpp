#include <iostream>
#include <vector>

using namespace std;

// 백준 14267 - 회사 문화 1
// DP
// 골드 4

// 칭찬 = 내가 받은 칭찬 + 직속 상사가 받은 칭찬
// 사장부터 밑으로 내려와야 함

int n, m;
int praise[100001]; // 칭찬
vector<vector<int>> child;
int DP[100001];

void traversal(int now)
{
	for (int i = 0; i < child[now].size(); i++)
	{
		DP[child[now][i]] = DP[now] + praise[child[now][i]];
		traversal(child[now][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	child.resize(n + 1);
	int a;
	for (int i = 1; i <= n; i++)
	{
		cin >> a;
		if (i == 1) continue;
		child[a].push_back(i);
	}

	int num, w;
	for (int i = 0; i < m; i++)
	{
		cin >> num >> w;
		praise[num] += w;
	}

	for (int i = 0; i < child[1].size(); i++)
	{
		DP[child[1][i]] = praise[child[1][i]];
		traversal(child[1][i]);
	}

	for (int i = 1; i <= n; i++) cout << DP[i] << ' ';

	return 0;
}