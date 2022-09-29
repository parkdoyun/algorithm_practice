#include <iostream>
#include <string>

using namespace std;

// ���� 16120 - PPAP
// string
// ��� 4

// PPAP -> PP�� A ������ ���
// ������ PPAP ���ƾ� �� -> P �ϳ� ���� �ٷ� ���� A�� ok

int main()
{
	string s;
	cin >> s;

	int cnt = 0;

	// ���� ó�� (P �ϳ� �Է� �޾��� ��)
	if (s == "P")
	{
		cout << "PPAP";
		return 0;
	}

	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == 'P') {
			cnt++;
		}
		else // A
		{
			if (cnt >= 2) cnt -= 2;
			else
			{
				cout << "NP";
				return 0;
			}
		}
	}

	if (cnt == 0 && s[s.length() - 1] == 'P' && s[s.length() - 2] == 'A')
	{
		cout << "PPAP";
	}
	else cout << "NP";

	return 0;
}