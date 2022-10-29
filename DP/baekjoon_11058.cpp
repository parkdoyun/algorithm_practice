#include <iostream>
#include <algorithm>

using namespace std;

// ���� 11058 - ũ������
// DP
// ��� 5

// �׻� ctrl-A + ctrl-V�� �ѹ��� �ϵ��� ���� 
// 1) A ���(DP[i-1] + 1)�� �� ū��
// 2) �ٷ� ctrl-A + ctrl-C + ctrl-V�� �� �� �� ū��(DP[i-3] + DP[i-3])
// 3) ctrl-A + ctrl-C + ctrl-V + ctrl-V (DP[i-4] + DP[i-4] + DP[i-4])
// 4) ctrl-A + ctrl-C + ctrl-V + ctrl-V + ctrl-V (DP[i-5] * 4)
// �� 4��° ctrl-V���� �ٽ� ctrl-A + ctrl-C + ctrl-V�� �ϴ� �� �� ũ��


long long DP[101];

int main()
{
	int n;
	cin >> n;

	// ���� ����
	// �׳� A �������� �ִ���
	// DP[0] = 0;
	DP[1] = 1;
	DP[2] = 2;


	for (int i = 3; i <= n; i++)
	{
		DP[i] = DP[i - 1] + 1;
		DP[i] = max(DP[i], DP[i - 3] * 2);
		DP[i] = max(DP[i], DP[i - 4] * 3);
		DP[i] = max(DP[i], DP[i - 5] * 4);
	}

	cout << DP[n];

	return 0;
}