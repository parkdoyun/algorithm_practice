#include <iostream>

using namespace std;

// ���� 2502 - �� �Դ� ȣ����
// DP
// �ǹ� 1

// �Ųٷ� �Ǻ���ġ

// ��ȭ�� DP[i] = DP[i - 1] + DP[i - 2]
// DP[i - 2] = DP[i] - DP[i - 1]
// DP[i] = DP[i + 2] - DP[i + 1]

// �׻� DP[i-1]�� DP[i] ���� �۾ƾ� �Ѵ�
// ���� Ŀ���ٸ� -1 return

int d, k;
int DP[31];

int chk(int start)
{
	int tmp;
	DP[d - 1] = start;
	for (int i = d - 2; i >= 1; i--)
	{
		tmp = DP[i + 2] - DP[i + 1];
		if (tmp < 0) return -1;
		DP[i] = tmp;
	}
	if (DP[2] - DP[1] < 0) return -1;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> d >> k;
	DP[d] = k;

	int start = k / 2 + 1;

	for (int i = start; i < k; i++)
	{
		if (chk(i) == 1)
		{
			cout << DP[1] << '\n' << DP[2];
			break;
		}
	}

	return 0;
}