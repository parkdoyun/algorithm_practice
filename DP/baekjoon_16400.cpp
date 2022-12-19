#include <iostream>
#include <vector>

using namespace std;

// ���� 16400 - �Ҽ� ȭ��
// �����佺�׳׽��� ü + DP
// ��� 5

// �����佺�׳׽��� ü + DP (���� ����)
// �����佺�׳׽��� ü : �Ҽ� ã�� �˰���
// ���� ���� ��ȭ�� DP[j] = DP[j] + DP[j-prime_num[i]];

int chk[40001];
vector<int> prime_num;
int DP[40001];

void findPrime(int n) // �����佺�׳׽��� ü
{
	for (int i = 2; i <= n; i++)
	{
		if (chk[i] == 1) continue;

		// i�� ��� ��� �Ҽ� �ƴϹǷ� �����
		for (int j = 2; i * j <= n; j++)
		{
			chk[i * j] = 1;
		}
	}

	// �����ִ� �� �Ҽ��� �迭�� �ֱ�
	for (int i = 2; i <= n; i++)
	{
		if (chk[i] == 1) continue;
		prime_num.push_back(i);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	findPrime(n); // �Ҽ� ã��

	// ���� ���� Ǯ���� DP Ǯ��

	for (int i = 0; i < prime_num.size(); i++)
	{
		DP[prime_num[i]] = (DP[prime_num[i]] + 1) % 123456789;
		for (int j = prime_num[i]; j <= n; j++)
		{
			DP[j] = (DP[j] + DP[j - prime_num[i]]) % 123456789;
		}
	}

	cout << DP[n];

	return 0;
}