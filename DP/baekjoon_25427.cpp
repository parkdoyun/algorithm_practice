#include <iostream>
#include <string>

using namespace std;

// ���� 25427 - DKSH�� ã�ƶ�
// DP
// ��� 5

// ���� ũ�� �� Ȯ������ (int�� ������ �� Ȯ��)

// ��ȭ��
// i) D�� �� DP[0][i] = DP[0][i-1] + 1
// ii) K�� �� DP[1][i] = DP[1][i-1] + DP[0][i-1]
// iii) S�� �� DP[2][i] = DP[2][i-1] + DP[1][i-1]
// iv) H�� �� DP[3][i] = DP[3][i-1] + DP[2][i-1]
// v) �ƴ� �� DP[n][i] = DP[n][i-1]

int n;
string s;
long long int DP[4][100001]; // 0 : D, 1 : K, 2 : S, 3 : H

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> s;

	// �ʱ�����
	if (s[0] == 'D')
	{
		DP[0][0] = 1;
	}

	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == 'D') DP[0][i] = DP[0][i - 1] + (long long int)1;
		else DP[0][i] = DP[0][i - 1];
		if (s[i] == 'K') DP[1][i] = DP[1][i - 1] + DP[0][i - 1];
		else DP[1][i] = DP[1][i - 1];
		if (s[i] == 'S') DP[2][i] = DP[2][i - 1] + DP[1][i - 1];
		else DP[2][i] = DP[2][i - 1];
		if (s[i] == 'H') DP[3][i] = DP[3][i - 1] + DP[2][i - 1];
		else DP[3][i] = DP[3][i - 1];
	}

	cout << DP[3][n - 1];

	return 0;
}