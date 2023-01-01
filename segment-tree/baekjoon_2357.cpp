#include <iostream>
#include <algorithm>

using namespace std;

// ���� 2357 - �ּڰ��� �ִ�
// segment tree
// ��� 1

int n, m;
int arr[100001];
int tree[400001]; // max
int tree2[400001]; // min

int treeInit(int start, int end, int idx) // �ִ�
{
	if (start == end) // �� ���̶�� (leaf)
	{
		tree[idx] = arr[start];
		return tree[idx];
	}
	int mid = (start + end) / 2;
	tree[idx] = max(treeInit(start, mid, idx * 2), treeInit(mid + 1, end, idx * 2 + 1));
	return tree[idx];
}

int treeInit2(int start, int end, int idx)
{
	if (start == end) // �� ���̶�� (leaf)
	{
		tree2[idx] = arr[start];
		return tree2[idx];
	}
	int mid = (start + end) / 2;
	tree2[idx] = min(treeInit2(start, mid, idx * 2), treeInit2(mid + 1, end, idx * 2 + 1));
	return tree2[idx];
}

// ���� ���ϱ�
int traversal(int start, int end, int idx, int left, int right)
{
	// ���� �ۿ� �ִ� ���
	if (left > end || right < start) return 0;

	// ���� �ȿ� �ִ� ���
	if (left <= start && right >= end)
	{
		return tree[idx];
	}

	// ���� �ִ� ���ϱ�
	int mid = (start + end) / 2;
	return max(traversal(start, mid, idx * 2, left, right), traversal(mid + 1, end, idx * 2 + 1, left, right));
}

int traversal2(int start, int end, int idx, int left, int right)
{
	//cout << idx << ' ' << left << ' ' << right << '\n';
	// ���� �ۿ� �ִ� ���
	if (left > end || right < start) return 1000000001;

	// ���� �ȿ� �ִ� ���
	if (left <= start && right >= end)
	{
		return tree2[idx];
	}

	// ���� �ּڰ� ���ϱ�
	int mid = (start + end) / 2;
	return min(traversal2(start, mid, idx * 2, left, right), traversal2(mid + 1, end, idx * 2 + 1, left, right));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	// Ʈ�� ����
	treeInit(1, n, 1);
	treeInit2(1, n, 1);

	int a, b;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;
		cout << traversal2(1, n, 1, a, b) << ' ' << traversal(1, n, 1, a, b) << '\n';
	}

		
	return 0;
}