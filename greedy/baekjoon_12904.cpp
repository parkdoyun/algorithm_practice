#include <iostream>
#include <string>
using namespace std;

// ���� 12904 - A�� B
// greedy
// ��� 5

// t���� s�� ���� �� �ִ��� ���� ��
// ABBA -> ABB -> BA -> B (�ȴ�)

int main()
{
	string s, t;
	cin >> s >> t;

	string tmp; // �������
	while (s.size() < t.size())
	{
		if (t[t.size() - 1] == 'A')
		{
			t.pop_back();
		}
		else
		{
			t.pop_back();
			tmp = "";
			for (int i = t.size() - 1; i >= 0; i--)
			{
				tmp += t[i];
			}
			t = tmp;
		}
	}
	if (t == s) cout << 1;
	else cout << 0;

	return 0;
}