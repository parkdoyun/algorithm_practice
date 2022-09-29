#include <iostream>

using namespace std;

// ���� 2133 - Ÿ�� ä���
// DP
// ��� 4

int DP[31];

int main()
{
	DP[0] = 1;
	DP[1] = 0;
	DP[2] = 3;
	int n;
	cin >> n;
	if (n % 2 == 1) cout << 0;
	else
	{
		for (int i = 4; i <= n; i += 2)
		{
			DP[i] = DP[i - 2] * 3;
			for (int j = 4; j <= i; j += 2)
			{
				DP[i] += DP[i-j] * 2;
			}
		}
		cout << DP[n];
	}

	return 0;
}