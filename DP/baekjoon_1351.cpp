#include <iostream>
#include <map>

using namespace std;

// ���� 1351 - ���� ����
// DP
// ��� 5

// �迭�� �Ϸ� �ߴµ� �迭 ����
// �� �̿��ؼ� ��ͷ� ǰ(�Ǻ���ġ ��ͷ� Ǫ�� �Ͱ� ������ ���)
// int�� �ϴϱ� division by zero ���� -> long long���� �ٲٴ� �� (�����÷ο� �߻��� ��)

map<long long, long long> DP;
long long n, p, q;

long long DFS(long long val)
{
	if (DP.find(val) != DP.end())
	{
		return DP[val];
	}
	long long a = DFS(val / p); // �ڵ� ©�� (�Ҽ���)
	DP.insert({ val / p, a });
	long long b = DFS(val / q);
	DP.insert({ val / q, b });

	return a + b;
}
int main()
{
	cin >> n >> p >> q;

	DP.insert({ 0, 1 });

	cout << DFS(n);

	return 0;
}