#include <iostream>
#include <vector>
using namespace std;

// ���� 11725�� - Ʈ���� �θ� ã��
// DFS, Ʈ��

// ���᳢�� �ٿ����� ���߿� (DFS, BFS) Ž��

vector<vector<int>> tree(100001); // Ʈ��(�糡 ���� ���� ��� ����)
int parent_arr[100001]{ 0 }; // �θ� ���� �Է��� �迭

void DFS(int tmp, int parent);

int main()
{
	int n, a, b;
	cin >> n;

	for (int i = 0; i < n - 1; i++)
	{
		cin >> a >> b;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	// Ž������ �θ� ã��
	DFS(1, 0);
	
	for (int i = 2; i <= n; i++)
	{
		cout << parent_arr[i] << '\n';
	}
	return 0;
}

void DFS(int tmp, int parent)
{
	for (int i = 0; i < tree[tmp].size(); i++)
	{
		if (tree[tmp][i] == parent) continue;
		else
		{
			parent_arr[tree[tmp][i]] = tmp;
			DFS(tree[tmp][i], tmp);
		}
	}
}