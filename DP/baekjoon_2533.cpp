#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 2533 - ��ȸ�� ����(SNS)
// DP, tree
// ��� 3

// �� ������ �������� �ö���鼭 Ȯ�� (post-traversal)
// now�� �󸮾ƴ��Ͷ�� �ϴ� �� �� ������ �ƴϸ� ���δ� �� ������
// �̹� Ȯ���Ǹ� (visit) �ٽ� �湮 X
// ���� leaf��� �ϴ� ���� ���ϰ� �ö󰡱�

// ��ȭ�� min(DP1[1], DP2[1])
// DP �ΰ�
// ������ ���� ��� ������(DP1), ���� ������ ä������ ������(DP2)
// DP1 = DP2[�ڽ�]�� ��
// DP2 = min(DP1[�ڽ�], DP2[�ڽ�])�� �� + 1
// �� �ؿ� �ֵ��� ���� ���� �����Ѵ� ���� -> �� �ڽĵ��� ���� �󸮾���Ϳ��� ��

// u�� v�� �θ� �ƴ� ���� ���� (�ڽ��ϼ���)

int n;
int total_cnt = 0;
int DP1[1000001]; // ���� ��� ������
int DP2[1000001]; // ���� ä������ ������
int visit[1000001]; // 0 : �湮 X, 1 : �湮��, 2 : Ȯ��
vector<vector<int>> E;

void traversal(int now)
{
	visit[now] = 1;

	for (auto e : E[now])
	{
		if (visit[e] == 1) continue;
		traversal(e);
		DP1[now] += DP2[e];
		DP2[now] += min(DP1[e], DP2[e]);
	}

	DP2[now]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	E.resize(n + 1);

	int u, v;
	for (int i = 0; i < n - 1; i++)
	{
		cin >> u >> v;
		E[u].push_back(v);
		E[v].push_back(u);
	}

	// ��ȸ
	traversal(1);

	cout << min(DP1[1], DP2[1]);
		
	return 0;
}