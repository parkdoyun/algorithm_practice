#include <iostream>
#include <string>

using namespace std;

// ���� 4889 - �������� ���ڿ�
// greedy, string
// �ǹ� 1

// ������ �ѱ�ٰ� �� ������ �ٲٱ�

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	int tc = 1;

	while (true)
	{
		cin >> s;
		if (s[0] == '-') break;

		int open_n = 0;
		int cnt = 0;

		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == '{')
			{
				open_n++;
			}
			else
			{
				if (open_n == 0) // �߸��Ǿ���
				{
					cnt++; // '{'�� �ٲ���
					open_n++;
				}
				else
				{
					open_n--;
				}
			}
		}

		if (open_n > 0) // �߸��Ǿ���
		{
			cnt += open_n / 2;
		}

		cout << tc << ". " << cnt << '\n';

		tc++;

	}
	
	return 0;
}