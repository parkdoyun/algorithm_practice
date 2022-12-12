#include <iostream>
#include <vector>

using namespace std;

// ���� 1043 - ������
// union-find
// ��� 4

// ���� �ƴ� ������� ���ԵǸ� ������ ���� ���ؾ� �� 
// ���⿡ �ٸ� ���Ե��� ���� ����� ��� ���� ���ؾ� ��

// ���� �׷����� Ǯ�� (���Ǹ��� ���� �ϴ� �ֵ鳢�� ����)
// ������ �ƴ� ������ ���� �� �ִ� �ֵ� ��� ���� => ������ ����(union-find) 
// ��� �׷��� ���� Ȯ�� (���� ���� �ϴ� �ֵ� ���ԵǸ� ������ 1��)
// ���� �ƴ� ����� ������� ���� �ֵ� �ִ� �� (������ �ϴ� ��) chk

int n, m, true_n;
int V[51]; // 0 : ����� �� �� ��, 1 : ���� ���� ��
vector<vector<int>> party; // ��Ƽ ���
int root[51];

int find(int a)
{
	if (root[a] == a) return a;
	return find(root[a]);
}

void Union(int a, int b)
{
	int a_root = find(a);
	int b_root = find(b);
	if (a_root == b_root) return;

	if (V[a_root] == 0 && V[b_root] == 1)
	{
		root[a_root] = b_root;
	}
	else // �Ѵ� 0�̰ų� A�� 1 => ������ A�� ����
	{
		root[b_root] = a_root;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m >> true_n;

	party.resize(m + 1);
	for (int i = 1; i <= n; i++)
	{
		root[i] = i; // ó���� ��Ʈ�� �ڱ� �ڽ�
	}
	int a;
	for (int i = 0; i < true_n; i++)
	{
		cin >> a;
		V[a] = 1;
	}
	
	int party_n;
	for (int i = 0; i < m; i++)
	{
		cin >> party_n;
		int prev, now;
		for (int j = 0; j < party_n; j++)
		{
			if (j == 0)
			{
				cin >> prev;
				party[i].push_back(prev);
			}
			else
			{
				cin >> now;
				Union(prev, now);
				prev = now;
			}
		}
	}

	// �ϳ��� ���� �����鼭 root�� 1�̸� 1�� �ٲ�
	for (int i = 1; i <= n; i++)
	{
		if (V[find(i)] == 1) V[i] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < m; i++)
	{
		if (V[party[i][0]] == 0) cnt++;
	}

	cout << cnt;

	return 0;
}