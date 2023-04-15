#include <iostream>

using namespace std;

// 백준 10422 - 괄호
// DP
// 골드 4

// 무조건 짝수일 때만 올바른 문자열 성립
// + 애들 감싼 것 (DP[i - 2])
// + 큰 괄호로 묶인 수들 더해야 함 ex) 6자릿수 : ((())), (()())
// 점화식 DP[i] = DP[i - 2] + DP[i - 2] * arr[2] + DP[i - 4] * arr[4] + DP[i - 6] * arr[6] + ...

#define MOD 1000000007
long long int DP[5001];
long long int arr[5001]; // 큰 괄호로 묶인 수들 표시

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T;
	cin >> T;

	// 기저 조건
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