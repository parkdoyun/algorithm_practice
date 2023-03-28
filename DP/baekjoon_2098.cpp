#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 2098 - ���ǿ� ��ȸ
// DP, ���ǿ� ��ȸ(TSP) ����
// ��� 1

// ��ȸ�̹Ƿ� ó�� ���� ������ 0������ ���� ����

#define INF 999999999

int n;
int cost[17][17]; // cost[i][j] = i���� j�� ���� ���
int DP[17][65536];
int visit_complete;

int dfs(int now, int visited) // now : ���� ��ġ, visited : visit flag
{
	if (visited == visit_complete) // ���� �� �湮�ߴٸ�
	{
		if (cost[now][0] == 0) DP[now][visited] = INF; // 0������ ���� ��� ���ٸ� (��� ���� �� �ǵ���)
		else DP[now][visited] = cost[now][0];
		return DP[now][visited]; // 0���� ����(������ ����) ��� ��ȯ
	}

	if (DP[now][visited] != 0)
	{
		return DP[now][visited]; // �̹� ���ŵ� �� �ִٸ�(�湮�� �� �ִٸ�) ��ȯ
	}
	
	int bit = 1;
	int tmp = INF;
	for (int i = 1; i < n; i++)
	{
		bit = bit << 1;
		if ((visited & bit) != 0 || cost[now][i] == 0) continue; // �̹� �湮�� �� �ִٸ� pass, 0���� �������̹Ƿ� 1������ Ȯ��

		// now => i ���� ��� + i������ ������ �ֵ��� ���� �������� ������ �� �Ÿ�
		// �ּ��� �ֵ�� ����
		tmp = min(tmp, dfs(i, (visited | (1 << i))) + cost[now][i]);
	}
	DP[now][visited] = tmp;

	return DP[now][visited];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	visit_complete = (1 << n) - 1; // n�� 4�� �� 1111
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) cin >> cost[i][j];
	}

	cout << dfs(0, 1);

	return 0;
}