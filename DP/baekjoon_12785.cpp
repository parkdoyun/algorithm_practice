#include <iostream>

using namespace std;

// ���� 12785 - �������� ���
// DP
// �ǹ� 1

// ������ �佺Ʈ ���Ա����� ������ * �佺Ʈ ���Ժ��� �б������� ������
// DP[i][j] = DP[i - 1][j] + DP[i][j - 1];

int w, h;
int ty, tx; // �佺Ʈ ���� ��ġ
long long int DP[201][201];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> w >> h >> tx >> ty;
	
	// ���� ����
	DP[1][1] = 1;

	// ������ �佺Ʈ ���Ա���
	for (int i = 1; i <= ty; i++)
	{
		for (int j = 1; j <= tx; j++)
		{
			if (i == 1 && j == 1) continue;
			DP[i][j] = (long long int)(DP[i][j - 1] + DP[i - 1][j]) % (long long int)(1000007);
		}
	}

	// �佺Ʈ ���Ժ��� �б�����
	for (int i = ty; i <= h; i++)
	{
		for (int j = tx; j <= w; j++)
		{
			if (i == ty && j == tx) continue;
			DP[i][j] = (long long int)(DP[i][j - 1] + DP[i - 1][j]) % (long long int)(1000007);
		}
	}

	cout << DP[h][w];

	return 0;
}