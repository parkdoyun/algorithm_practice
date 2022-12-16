#include <iostream>
#include <cmath>

using namespace std;

// ���� 1629 - ����
// divide-and-conquer
// �������� �̿��� �ŵ�����
// �ǹ� 1

// ����-���� �˰��� �̿��ؼ� O(logN) �ð����⵵
// 3^13 = 3^8 * 3^4 * (3^2 ���� X) * 3^1
// 13(dec) = 1101(bin)
// �ش�Ǵ� �͸� ���ϱ�


long long int power(long long int n, long long int k, long long int c)
{
	long long int res = 1;

	while (k > 0)
	{
		if (k % 2 == 1) // ������ ����, Ȧ����� (�ش� �ȴٸ�)
		{
			res *= n;
			res %= c; // ������ ���� (Ŀ�� �� ���)
		}
		n *= n;
		n %= c; // ������ ���� (Ŀ�� �� ���)
		k /= 2; // ������ ���� -> 1 ������ �� ������
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	
	long long int a, b, c; // �����÷ο� ����
	cin >> a >> b >> c;

	cout << power(a, b, c);

	return 0;
}