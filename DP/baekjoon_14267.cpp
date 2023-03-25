#include <iostream>
#include <vector>

using namespace std;

// ���� 14267 - ȸ�� ��ȭ 1
// DP
// ��� 4

// Ī�� = ���� ���� Ī�� + ���� ��簡 ���� Ī��
// ������� ������ �����;� ��

int n, m;
int praise[100001]; // Ī��
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