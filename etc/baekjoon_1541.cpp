#include <iostream>
#include <string>

using namespace std;

// ���� 1541 - �Ҿ���� ��ȣ
// ���ڿ�
// ������ ��ȣ�� ���� �ڿ����� �ٽ� ���� ���� ������
// �������θ� ������ �ִ�� ����
// �ݷ� �� Ȯ��

int main()
{
	string s, tmp;
	cin >> s;

	// ó�� �� ������ ���ϰ�
	tmp = "";
	int idx = 0;
	for (int i = 0; s[i] != '-' && s[i] != '+' && i < s.length(); i++)
	{
		tmp += s[i];
		idx++;
	}

	int res = 0;

	// �� �ĺ����� ���� ��ȣ -> �ϴ� �־����
	int chk_minus = 0; // 1�̸� ����, 0�̸� ����
	int tmp_num;
	while (idx < s.length())
	{
		if (s[idx] == '+')
		{
			if(tmp != "") res += stoi(tmp);
			tmp = "";
			idx++;
			chk_minus = 0;
		}
		else if (s[idx] == '-')
		{
			if (tmp != "") res += stoi(tmp);
			tmp = "";
			idx++;
			chk_minus = 1;
			// ��ȣ ���� ��
			tmp_num = 0;
			while (s[idx] != '-' && idx < s.length())
			{
				if (s[idx] == '+')
				{
					tmp_num += stoi(tmp);
					tmp = "";
				}
				else tmp += s[idx];
				idx++;
			}
			if (tmp != "")
			{
				tmp_num += stoi(tmp);
				tmp = "";
			}
			res -= tmp_num;
			//idx++;
		}
		else
		{
			tmp += s[idx];
			idx++;
		}
	}
	if (tmp != "" && chk_minus == 0)
	{
		int num = stoi(tmp);
		res += num;
	}
	else if (tmp != "" && chk_minus == 1)
	{
		int num = stoi(tmp);
		res -= num;
	}

	cout << res;

	return 0;
}