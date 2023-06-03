#include <iostream>
#include <cmath>

using namespace std;

// ���� 9764 - ���� �ٸ� �ڿ����� ��
// DP
// �ǹ� 1

// ��� i�� ceil(i / 2)���� Ȯ���ϸ� ��
// DP[k][i] = i��° ��, �ش� ���� �̷�� ���� ���� ���� k
// i - k��°���� ���� �̷�� ���� ���� ���� ������ k �ʰ����� ��  

// ��ȭ��
// DP[k][i] = sum(DP[k �ʰ�][i - k]);

int n;
int DP[2001][2001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	// ���� DP ����

	// ���� ����
	DP[1][1] = 1;

	// DP
	for (int i = 2; i <= 2000; i++)
	{
		for (int j = i - 1; j >= ceil(i / 2); j--)
		{
			for (int k = i - j + 1; k <= j; k++)
			{
				DP[i - j][i] = (DP[i - j][i] + DP[k][j]) % 100999;
			}
		}
		DP[i][i] = 1;
		//if (i % 100 == 0) cout << i << '\n';
	}
	

	int T;
	long long int res;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n;
		res = 0;
		for (int i = 1; i <= n; i++)
		{
			res = (res + DP[i][n]) % 100999;
		}
		cout << res << '\n';
	}

	return 0;
}