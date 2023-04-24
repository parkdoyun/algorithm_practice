#include <iostream>
#include <algorithm>

using namespace std;

// ���� 2643 - ������ �÷� ����
// DP
// ��� 4

// ������ ũ��� DP
// ��ȭ��
// i * j ũ������� ������ ���� = max((i-1)*(j-1) ũ������� ����, (i)*(j-1) ũ������� ����, (i-1)*(j) ũ������� ����)
// ���� i*j ũ���� �����̰� �����Ѵٸ� DP[i][j]++

int n;
int DP[1001][1001];
int paper[1001][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int a, b;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		paper[a][b] = 1;
		paper[b][a] = 1;
	}

	for (int i = 1; i <= 1000; i++)
	{
		for (int j = 1; j <= 1000; j++)
		{
			DP[i][j] = max(DP[i - 1][j - 1], DP[i][j - 1]);
			DP[i][j] = max(DP[i][j], DP[i - 1][j]);
			if (paper[i][j] == 1) // ���� �ִٸ�
			{
				DP[i][j]++;
			}
		}
	}

	cout << DP[1000][1000];

	return 0;
}