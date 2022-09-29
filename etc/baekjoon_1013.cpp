#include <iostream>
#include <string>
using namespace std;

// ���� 1013�� - Contact
// ���ڿ�, ����ǥ����
// 01 OR 100:0....01:1...1

int main()
{
	int n;
	cin >> n;
	string s, tmp;
	
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		
		tmp = "";
		int j = 0;
		int err_cnt = 0;
		while (j < s.size())
		{			
			if (s.size() == 1) // �ѱ��� -> ������ NO
			{
				err_cnt = 1;
				break;
			}
			
			tmp += s[j];

			if (tmp == "01")
			{				
				tmp = "";
			}
			else if (tmp == "100")
			{
				while (j != s.size() && s[j] == '0') // 0 �ݺ�
				{
					tmp += s[j];
					j++;
				}
				if (j == s.size() && s[j - 1] == '0') // �������� 0 (100000...0)
				{
					err_cnt = 1;
					break;
				}
				else if (j == s.size() && s[j - 1] == '1') // ���� (1000..01)
				{
					tmp = "";
					break;
				}
				// 1 ��� ����
				if (j != s.size() && s[j] == '1') // 1000...01...
				{
					tmp = s[j];
					j++; // 100..0(1) ó�� 1 ����
				
					while (j != s.size() && s[j] == '1') // 1 �ݺ�
					{
						tmp += s[j];
						j++;
					}
					tmp = "";
					if (s[j - 1] == '1' && s[j - 2] == '0') // 1�� �ϳ����� (100010..)
					{
						continue;
					}
					// ���࿡ 11...1100 �̰ų� 11...1101 �ϼ���
					if (j < s.size() - 1 && s[j] == '0' && s[j + 1] == '0') // 11..1100 -> 100���� ����
					{
						j = j - 1;
						continue;
					}
					else if (j < s.size() - 1 && s[j] == '0' && s[j + 1] == '1') continue; // 01 �ν��ϵ���
				}
				
			}
			else if (tmp == "00" || tmp == "11")
			{
				break;
			}			

			j++;
		}
		if (tmp != "" || err_cnt != 0) cout << "NO\n";
		else cout << "YES\n";
		
	}

	return 0;
}