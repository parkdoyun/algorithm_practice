#include <iostream>
#include <algorithm>

using namespace std;

// ���� 20167 - ��Ʋ��Ʋ ȣ�� �ֹ��� - ��ɼ�
// DP
// �ǹ� 1

// i��° ���� �������� �����Ұ���?
// ��ȭ��
// max(i + 1��°������ DP, i��°�� ó���� ��)
// DP[i] = max(DP[i + 1], i��°�� ó��)

int n, k;
int food[21];
int DP[21];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		cin >> food[i];
	}

	int tmp = 0;
	int idx;
	
	// DP
	for (int i = n; i >= 1; i--)
	{
		tmp = 0;
		for (int j = i; j <= n; j++)
		{
			tmp += food[j];
			if (tmp >= k)
			{
				idx = j;
				break;
			}
		}
		if (tmp - k < 0) DP[i] = DP[i + 1];
		else DP[i] = max(DP[i + 1], DP[idx + 1] + tmp - k);
	}

	cout << DP[1];

	return 0;
}