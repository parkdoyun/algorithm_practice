#include <iostream>
#include <algorithm>

using namespace std;

// ���� 1660 - ĸƾ �̴ټ�
// DP (���� ����)
// �ǹ� 1

// DP[i] = i���� ���� �� �ִ� ���ü��
// DP[i] = min(i���� ���� �� �ִ� ���ü�� ����)
// DP[i] = min(DP[i - tetra[1]], DP[i - tetra[2]], ... DP[i - tetra[tetra_idx]]) + 1

int triangle[1000];
int tetra[1000]; // ���ü�� �̷�� �������� ������
int DP[300001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, max_n, tetra_idx;
	cin >> n;

	triangle[1] = 1;
	tetra[1] = 1;
	max_n = 1; // n�� �̳����� ���� �� �ִ� ���� ū ���ü
	if (n == 1) // ����
	{
		cout << 1;
		return 0;
	}

	for (int i = 2; i <= n; i++)
	{
		triangle[i] = triangle[i - 1] + i;
		tetra[i] = tetra[i - 1] + triangle[i];
		if (n < tetra[i])
		{
			max_n = i - 1;
			break;
		}
	}
	
	// ���� ����
	DP[1] = 1;

	// DP
	tetra_idx = 1;
	for (int i = 2; i <= n; i++)
	{
		if (tetra[tetra_idx + 1] <= i) tetra_idx++;
		DP[i] = DP[i - 1];
		for (int j = 2; j <= tetra_idx; j++)
		{
			DP[i] = min(DP[i], DP[i - tetra[j]]);
		}
		DP[i]++;
	}

	cout << DP[n];

	return 0;
}