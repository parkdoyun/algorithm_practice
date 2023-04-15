#include <iostream>

using namespace std;

// ���� 10422 - ��ȣ
// DP
// ��� 4

// ������ ¦���� ���� �ùٸ� ���ڿ� ����
// + �ֵ� ���� �� (DP[i - 2])
// + ū ��ȣ�� ���� ���� ���ؾ� �� ex) 6�ڸ��� : ((())), (()())
// ��ȭ�� DP[i] = DP[i - 2] + DP[i - 2] * arr[2] + DP[i - 4] * arr[4] + DP[i - 6] * arr[6] + ...

#define MOD 1000000007
long long int DP[5001];
long long int arr[5001]; // ū ��ȣ�� ���� ���� ǥ��

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	// ���� ����
	DP[2] = 1;
	arr[2] = 1;
	int k;

	for (int i = 4; i <= 5000; i += 2)
	{
		arr[i] = DP[i - 2];
		k = 2;
		for (int j = i - 2; j >= 2; j -= 2)
		{
			DP[i] = (long long int)(DP[i] + (long long int)(DP[j] * arr[k])) % (long long int)(MOD);
			k += 2;
		}
		DP[i] = (long long int)(DP[i] + DP[i - 2]) % (long long int)(MOD);
	}

	int L;
	for (int tc = 1; tc <= T; tc++)
	{
		cin >> L;

		cout << DP[L] << '\n';
	}

	return 0;
}