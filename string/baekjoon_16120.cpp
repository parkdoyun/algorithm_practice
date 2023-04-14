#include <iostream>
#include <string>

using namespace std;

// ���� 16120 - PPAP
// string, greedy
// ��� 4

// PPAP => �߰� P�� ġȯ�Ǿ�� ��
// PPAP �� ���ڿ� ����Ű�� ������ ����Ͽ� �׻� PPAP�� �߰� P�� ġȯ�ǵ��� ��

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int point = 0; // PPAP ���ڿ� �� ������

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'P') // 'P'PAP �̰ų� P'P'AP �� ��
		{
			point++;
			continue;
		}

		if (point >= 2 && s[i + 1] == 'P') // 'A' ��ġ�� ��
		{
			point--; // �߰� P�� ġȯ
			i++; // ���� PPAP ���ڿ� �̵�
		}
		else
		{
			cout << "NP";
			return 0;
		}
	}

	if(point == 1) cout << "PPAP"; // �߰� P���� Ȯ��
	else cout << "NP"; // �ƴ϶��

	return 0;
}