#include <iostream>
#include <cmath>

using namespace std;

// 백준 1629 - 곱셈
// divide-and-conquer
// 분할정복 이용한 거듭제곱
// 실버 1

// 분할-정복 알고리즘 이용해서 O(logN) 시간복잡도
// 3^13 = 3^8 * 3^4 * (3^2 포함 X) * 3^1
// 13(dec) = 1101(bin)
// 해당되는 것만 곱하기


long long int power(long long int n, long long int k, long long int c)
{
	long long int res = 1;

	while (k > 0)
	{
		if (k % 2 == 1) // 나머지 연산, 홀수라면 (해당 된다면)
		{
			res *= n;
			res %= c; // 나머지 연산 (커질 것 대비)
		}
		n *= n;
		n %= c; // 나머지 연산 (커질 것 대비)
		k /= 2; // 나머지 연산 -> 1 남는지 안 남는지
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	long long int a, b, c; // 오버플로우 조심
	cin >> a >> b >> c;

	cout << power(a, b, c);

	return 0;
}