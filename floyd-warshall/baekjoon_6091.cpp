#include <iostream>
#include <string>

using namespace std;

// ���� 6091 - ��ũ �÷��̵�
// floyd-warshall
// ��� 1

// floyd-warshall algorithm
// dijkstra�� �� �������� �ٸ� ��� ���� ���� �ִ� �Ÿ� ���Ѵٸ�,
// floyd-warshall�� ��� �������� ��� ���� ���� �ִ� �Ÿ� ���Ѵ�
// i->j ��� => max(i->j ���, i->k ��� + k->j ���)
// ��ȭ�� DP[i][j] = max(DP[i][j], DP[i][k] + DP[k][j]);

// �ִ� �Ÿ���κ��� � ������ ���ԵǾ����� ã�ƾ� ��
// DP[i][j]�� ��� DP[i][k] + DP[k][j] ���պ��� �۴ٸ� -> ���� ����

#define INF 922337203685477580

int n;
long long int DP[1025][1025]; // �ִ� �Ÿ� (�� �Ÿ��� �ƴ϶� �� �������� �ٸ� ������ �Ÿ��� 15000�̶�� ��)
long long int arr[1025][1025]; // ��������Ʈ

void floyd_warshall()
{
	for (int k = 1; k <= n; k++)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (DP[i][j] >= DP[i][k] + DP[k][j]) // �̰� �Ѱ��� ������ i, j ���� X
				{
					arr[i][j]++; // ��� ��ο��� �̰� ���ٸ� �Ѹ� �̾����� �� �ִ� �� 
				}
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	
	for (int i = 1; i <= n; i++)
	{
		DP[i][i] = INF;
	}

	for (int i = 1; i < n; i++)
	{
		for (int j = i + 1; j <= n; j++)
		{
			cin >> DP[i][j];
			DP[j][i] = DP[i][j]; // �����
		}
	}

	floyd_warshall();

	int cnt;
	for (int i = 1; i <= n; i++)
	{
		string s = "";
		cnt = 0;
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == 0)
			{
				cnt++;
				s = s + to_string(j) + " ";
			}
		}
		cout << cnt << ' ' << s << '\n';
	}

	return 0;
}