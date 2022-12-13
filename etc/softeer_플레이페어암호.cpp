#include <iostream>
#include <string>

using namespace std;

// softeer - �÷������ ��ȣ
// ����
// ��3

// XX�� �� ������ ZZ�� �ٲٴ� �� �ƴ϶� ���� �ɷ� �ٲ۴� => �̰Ͷ����� Ʋ��

int alphabet[27];
char board[6][6];

string cipher(string tmp)
{
	int y1, x1, y2, x2;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (board[i][j] == tmp[0])
			{
				y1 = i;
				x1 = j;
			}
			else if (board[i][j] == tmp[1])
			{
				y2 = i;
				x2 = j;
			}
		}
	}

	// ����
	if (tmp == "XX") // **�� �� ����!!! ������ ZZ�� �ٲٴ� �� �ƴ϶� ���� �ɷ� �ٲ۴�**
	{
		tmp[0] = board[y1][(x1 + 1) % 5];
		tmp[1] = board[y1][(x1 + 1) % 5];
		return tmp;
	}
	else if (y1 == y2) // ���������� ��ĭ �̵�
	{
		tmp[0] = board[y1][(x1 + 1) % 5];
		tmp[1] = board[y1][(x2 + 1) % 5];
	}
	else if (x1 == x2) // ������
	{
		tmp[0] = board[(y1 + 1) % 5][x1];
		tmp[1] = board[(y2 + 1) % 5][x1];
	}
	else // X��
	{
		tmp[0] = board[y1][x2];
		tmp[1] = board[y2][x1];
	}
	
	return tmp;
}

int main(int argv, char **argc)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string msg, key;
	cin >> msg >> key;

	// J�� ��� �� ��
	alphabet[(int)('J' - 'A')] = 1;

	// key ä���
	int idx = 0;
	int alpha_idx = 0;
	int k_len = key.length();
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (idx < k_len)
			{
				board[i][j] = key[idx];
				alphabet[(int)(key[idx] - 'A')] = 1;
				idx++;
				while (idx < k_len)
				{
					if (alphabet[(int)(key[idx] - 'A')] == 0) break;
					idx++;
				}
			}
			else // ������ ���ĺ� ������� ä���
			{
				while (alpha_idx < 26)
				{
					if (alphabet[alpha_idx] == 0)
					{
						board[i][j] = (char)('A' + alpha_idx);
						alphabet[alpha_idx] = 1;
						alpha_idx++;
						break;
					}
					alpha_idx++;
				}
			}
		}	
	}

	// �ΰ��� ����߸���
	idx = 0;
	int msg_len = msg.length();
	string tmp_len;
	string res = "";
	while (idx < msg_len)
	{
		tmp_len = "";
		tmp_len += msg[idx];
		idx++;
		if (idx == msg_len) // ������ �ѱ��ڿ��� ��
		{
			tmp_len += "X";
		}
		else if (msg[idx] == msg[idx - 1]) // �Ȱ��� ��
		{
			if (tmp_len == "X") tmp_len += "Q";
			else tmp_len += "X";
		}
		else
		{
			tmp_len += msg[idx];
			idx++;
		}

		// ��ȣȭ
		tmp_len = cipher(tmp_len);

		res += tmp_len;
	}

	cout << res;

	return 0;
}