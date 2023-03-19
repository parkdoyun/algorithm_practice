#include <iostream>
#include <string>

using namespace std;

// ���� 16432 - ������� ȣ����
// greedy
// ��� 4

int DP[10][1001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m, a;
	bool failed = false; // �� ���� �� ���ٸ�
	cin >> n >> m;

	// �ʱ� ����
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		DP[a][0] = 1;
	}

	for (int i = 1; i < n; i++)
	{
		cin >> m;
		bool tmp = true;
		for (int j = 0; j < m; j++)
		{
			cin >> a;
			if (failed == true) continue;
			for (int r = 1; r <= 9; r++)
			{
				if (r == a) continue;
				if (DP[r][i - 1] != 0)
				{
					DP[a][i] = r;
					tmp = false;
					break;
				}
			}
		}
		if (tmp == true) failed = true;
	}

	string s = "";
	if (failed == true) cout << -1;
	else
	{
		int start;
		for (int i = 1; i <= 9; i++)
		{
			if (DP[i][n - 1] != 0)
			{
				start = DP[i][n - 1];
				s = (char)('0' + i) + s;
				break;
			}
		}

		for (int i = n - 2; i >= 0; i--)
		{
			s = (char)('0' + start) + s;
			start = DP[start][i];
		}
		
		for (int i = 0; i < s.length(); i++) cout << s[i] << '\n';
	}

	return 0;
}