#include <iostream>
#include <string>

using namespace std;

// softeer
// ������ 3�� - �÷������ ��ȣ
// �� 3
// 1�ð�, 5ms
// simulation

// XX�� ������ ZZ�� �ٲٴ� �Ŷ�� �߸� ������


int alphabet[26]; // key���� �ߺ� ���� ����
char key[5][5]; // key
string key_s, msg;

void findKey(char k, int &y, int &x)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (key[i][j] == k)
			{
				y = i;
				x = j;
				return;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> msg >> key_s;

	// key ����
	int key_idx = 0;
	int key_len = key_s.length();
	int start_idx = 0;

	alphabet[9] = 1;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			// key_s �� ä���� ��
			if (key_idx >= key_len)
			{
				for (int k = start_idx; k < 26; k++)
				{
					if (alphabet[k] == 0)
					{
						alphabet[k] = 1;
						key[i][j] = (char)('A' + k);
						start_idx = k + 1;
						break;
					}
				}
			}
			else
			{
				int flag = 0;
				while (key_idx < key_len)
				{
					if (alphabet[(int)(key_s[key_idx] - 'A')] == 0)
					{
						alphabet[(int)(key_s[key_idx] - 'A')] = 1;
						key[i][j] = key_s[key_idx];
						flag = 1;
						break;
					}
					key_idx++;
				}
				// �ߺ��̶� �׳� �������� ���
				if (flag == 0)
				{
					for (int k = start_idx; k < 26; k++)
					{
						if (alphabet[k] == 0)
						{
							alphabet[k] = 1;
							key[i][j] = (char)('A' + k);
							start_idx = k + 1;
							break;
						}
					}
				}
			}
		}
	}

	// �޽��� ����
	string new_msg = "";
	char c1, c2;
	for (int i = 0; i < msg.length(); i++)
	{
		// �� �������� �ϳ� ����
		if (i == msg.length() - 1)
		{
			new_msg = new_msg + msg[i] + 'X';
		}
		else
		{
			c1 = msg[i];
			c2 = msg[i + 1];
			if (c1 == c2)
			{
				if (c1 == 'X') // XX
				{
					new_msg = new_msg + c1 + 'Q';
				}
				else
				{
					new_msg = new_msg + c1 + 'X';
				}
			}
			else
			{
				new_msg = new_msg + c1 + c2;
				i++; // �ǳʶٱ�
			}
		}
	}

	string total_str = "";
	int x1, x2, y1, y2;
	for (int i = 0; i < new_msg.length(); i+=2)
	{

		findKey(new_msg[i], y1, x1);
		findKey(new_msg[i + 1], y2, x2);

		// �ٲٱ�
		if (y1 == y2) // XX�� ����
		{
			x1 = (x1 + 1) % 5;
			x2 = (x2 + 1) % 5;
		}
		else if (x1 == x2)
		{
			y1 = (y1 + 1) % 5;
			y2 = (y2 + 1) % 5;
		}
		else
		{
			int tmp_x = x2;
			x2 = x1;
			x1 = tmp_x;
		}
		total_str = total_str + key[y1][x1] + key[y2][x2];
	}
	cout << total_str;

	return 0;
}