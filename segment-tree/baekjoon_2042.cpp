#include <iostream>

using namespace std;

// ���� 2042 - ���� �� ���ϱ�
// segment-tree
// ��� 1

int n, m, k;
long long int arr[1000001];
long long int tree[4000001];

long long int treeInit(int start, int end, int idx)
{
	// leaf�� �迭 �� Ʈ���� �ֱ�
	if (start == end)
	{
		tree[idx] = arr[start];
		return tree[idx];
	}

	// Ʈ�� ���
	int mid = (start + end) / 2;
	tree[idx] = (long long int)(treeInit(start, mid, idx * 2) + treeInit(mid + 1, end, idx * 2 + 1));
	return tree[idx];
}

long long int traversal(int start, int end, int idx, int left, int right)
{
	// ���� ���� ��� (���ϸ� �� �ǹǷ� 0 return)
	if (left > end || right < start) return 0;

	// ���� ���� ���
	if (left <= start && right >= end)
	{
		return tree[idx];
	}
	// �׷��� ���� ��� �� ���ϱ�
	int mid = (start + end) / 2;

	return (long long int)(traversal(start, mid, idx * 2, left, right) + traversal(mid + 1, end, idx * 2 + 1, left, right));
}

void Update(int start, int end, int idx, int mod_val, long long int val) // val : ��� �����յ��� ����Ǿ�� �ϴ� ��
{
	// �����Ϸ��� ���� ���� ���� ���
	if (mod_val < start || mod_val > end) return;

	// ���� �ȿ� ������ ��ͷ� ���鼭 �ٸ� ���� ����
	tree[idx] = (long long int)(tree[idx] + val);
	if (start == end) // **leaf�� ��� arr[start]�� �����ؾ� ��!!!!***
	{
		arr[start] = (long long int)(arr[start] + val);
		return;
	}
	
	int mid = (start + end) / 2;
	Update(start, mid, idx * 2, mod_val, val);
	Update(mid + 1, end, idx * 2 + 1, mod_val, val);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}

	treeInit(1, n, 1);

	int a, b;
	long long int c;

	for (int i = 0; i < k + m; i++)
	{
		cin >> a >> b >> c;
		if (a == 1) // b��° ���� c�� ����
		{
			Update(1, n, 1, b, (long long int)(c - arr[b]));
		}
		else // b���� c���� ������ ���ϱ�
		{
			cout << (long long int)traversal(1, n, 1, b, c) << '\n';
		}
	}


	return 0;
}