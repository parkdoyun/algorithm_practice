#include <iostream>
#include <string>

using namespace std;

// ���� 12852 - 1�� ����� 2
// DP
// �ǹ� 1

// ��ȭ��
// if(DP[i / 3]�� DP[i] + 1���� Ŭ ��) DP[i / 3] = DP[i] + 1;
// if(DP[i / 2]�� DP[i] + 1���� Ŭ ��) DP[i / 2] = DP[i] + 1;
// if(DP[i - 1]�� DP[i] + 1���� Ŭ ��) DP[i - 1] = DP[i] + 1;

int DP[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) DP[i] = 1000000;

	// �ʱ� ����
	DP[n] = 0;
	if (n % 3 == 0) DP[n / 3] = 1;
	if (n % 2 == 0) DP[n / 2] = 1;
	DP[n - 1] = 1;

	// ��ȭ��
	for (int i = n - 1; i >= 1; i--)
	{
		if (i % 3 == 0 && DP[i / 3] > DP[i] + 1)
		{
			DP[i / 3] = DP[i] + 1;
		}
		if (i % 2 == 0 && DP[i / 2] > DP[i] + 1)
		{
			DP[i / 2] = DP[i] + 1;
		}
		if (DP[i - 1] > DP[i] + 1)
		{
			DP[i - 1] = DP[i] + 1;
		}
	}

	cout << DP[1] << '\n';
	int res[100001];

	int cnt = 0;
	int idx = 1;
	while (idx <= n)
	{
		if (idx == n)
		{
			res[cnt] = n;
			break;
		}
		res[cnt] = idx;
		cnt++;
		if (idx * 3 <= n && DP[idx * 3] == DP[idx] - 1)
		{
			idx = idx * 3;
		}
		else if (idx * 2 <= n && DP[idx * 2] == DP[idx] - 1)
		{
			idx = idx * 2;
		}
		else
		{
			idx++;
		}
	}

	for (int i = cnt; i >= 0; i--)
	{
		cout << res[i] << ' ';
	}

	return 0;
}