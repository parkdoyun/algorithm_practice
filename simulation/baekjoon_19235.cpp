#include <iostream>

using namespace std;

// ���� 19235 - ���̳뵵�̳�
// ����
// �÷�Ƽ�� 5

// �� �� ������� 1��
// 1, 2, 3���� ��� Ȯ���ؾ� �� (���� ��糢�� �������� �ż�)

// blue�� �� 2�� 1�� ǥ��
// green�� �� 3�� 1�� ǥ�� (������ ������ �� �Ȱ��� ���)

// blue�� 2�� ��ϸ� �����ϸ� �ǰ� green�� 3�� ��ϸ� �����ϸ� �ȴ�
// (�������� ���� ����� �������� ��� ����)

// ** ���� �� ������ 0~4 ������� ���� ��!!!**

int blue[4][6];
int green[6][4];
int score = 0;

// ���� üũ
int chkLine_blue() // ������ -1 return
{
	int flag;
	for (int i = 5; i >= 0; i--)
	{
		flag = 0;
		for (int j = 0; j < 4; j++)
		{
			if (blue[j][i] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) return i;
	}
	return -1;
}

// block ������ �����;� ��
// �ѹ��� ��� �� �� ���־� ��
void deleteLine_blue(int line_n, int f) // line �� ���ְ� �����
{
	// ���� �����
	int flag = -1;
	int tmp_line = line_n;
	while (true)
	{
		if(f != -1) score++;
		for (int i = 0; i < 4; i++)
		{
			blue[i][line_n] = 0; // �����
		}
		if (f == -1) break;

		flag = -1;
		tmp_line--;
		for (int i = 0; i < 4; i++)
		{
			if (blue[i][tmp_line] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
		line_n = tmp_line; // �� á�ٸ� ���� �� ����
	}

	// �����
	for (int i = line_n - 1; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (blue[j][i] == 0) continue;
			if (blue[j][i] == 1)
			{
				int idx = i;
				for (int k = i + 1; k <= 5; k++)
				{
					if (blue[j][k] != 0) break;
					idx = k;
				}
				blue[j][i] = 0;
				blue[j][idx] = 1;
			}
			else // 3
			{
				int idx1 = i;
				int idx2 = i;
				for (int k = i + 1; k <= 5; k++)
				{
					if (blue[j][k] != 0) break;
					idx1 = k;
				}
				for (int k = i + 1; k <= 5; k++)
				{
					if (blue[j + 1][k] != 0) break;
					idx2 = k;
				}
				blue[j][i] = 0;
				blue[j + 1][i] = 0;
				if (idx1 < idx2)
				{
					blue[j][idx1] = 3;
					blue[j + 1][idx1] = 3;
				}
				else
				{
					blue[j][idx2] = 3;
					blue[j + 1][idx2] = 3;
				}
				j++; // ���� �� �ʿ� X
			}
		}
	}
}

int chkLine_green() // ������ -1 return
{
	int flag;
	for (int i = 5; i >= 0; i--)
	{
		flag = 0;
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 0) return i;
	}
	return -1;
}

void deleteLine_green(int line_n, int f) // line �� ���ְ� �����
{
	int flag = -1;
	int tmp_line = line_n;
	while (true)
	{
		// ���� �����
		if(f != -1) score++; // ���� �� �� (���� ĭ ������ �� �� �ƴ� ��)
		for (int i = 0; i < 4; i++)
		{
			green[line_n][i] = 0; // �����
		}
		if (f == -1) break; // ���� ĭ ���� �� ������ �ѹ��� ����� ������

		flag = -1;
		tmp_line--;
		for (int i = 0; i < 4; i++)
		{
			if (green[tmp_line][i] == 0)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1) break;
		line_n = tmp_line; // �� á�ٸ� ���� �� ����
	}

	// �����
	for (int i = line_n - 1; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j] == 0) continue;
			if (green[i][j] == 1)
			{
				int idx = i;
				for (int k = i + 1; k <= 5; k++)
				{
					if (green[k][j] != 0) break;
					idx = k;
				}
				green[i][j] = 0;
				green[idx][j] = 1;
			}
			else // 2
			{
				int idx1 = i;
				int idx2 = i;
				for (int k = i + 1; k <= 5; k++)
				{
					if (green[k][j] != 0) break;
					idx1 = k;
				}
				for (int k = i + 1; k <= 5; k++)
				{
					if (green[k][j + 1] != 0) break;
					idx2 = k;
				}
				green[i][j] = 0;
				green[i][j + 1] = 0;
				if (idx1 < idx2)
				{
					green[idx1][j] = 2;
					green[idx1][j + 1] = 2;
				}
				else
				{
					green[idx2][j] = 2;
					green[idx2][j + 1] = 2;
				}
				j++; // ���� �� �ʿ� X
			}
		}
	}
}

// ��� ����
// ���� ���� �� ä������ ���ְ� �б�
void movBlock_blue(int t, int y, int x)
{
	int place = 5;
	// ��� ����
	if (t == 1)
	{
		for (int i = 1; i <= 5; i++)
		{
			if (blue[y][i] != 0)
			{
				place = i - 1;
				break;
			}
		}
		blue[y][place] = 1;
	}
	else if (t == 2)
	{
		for (int i = 1; i <= 5; i++)
		{
			if (blue[y][i] != 0)
			{
				place = i - 1;
				break;
			}
		}
		blue[y][place] = 1;
		blue[y][place - 1] = 1;
	}
	else // 3
	{
		int place2 = 5;
		for (int i = 1; i <= 5; i++)
		{
			if (blue[y][i] != 0)
			{
				place2 = i - 1;
				break;
			}
		}
		for (int i = 1; i <= 5; i++)
		{
			if (blue[y + 1][i] != 0)
			{
				place = i - 1;
				break;
			}
		}
		if (place < place2) // place ä��
		{
			blue[y][place] = 3;
			blue[y + 1][place] = 3;
		}
		else
		{
			blue[y][place2] = 3;
			blue[y + 1][place2] = 3;
		}
	}

	// ���� á���� Ȯ�� �� ���ֱ�
	while (true)
	{
		place = chkLine_blue();
		if (place == -1) break;
		deleteLine_blue(place, 1); // place �� ���ֱ�
	}
}

void movBlock_green(int t, int y, int x)
{
	int place = 5;
	// ��� ����
	if (t == 1)
	{
		for (int i = 1; i <= 5; i++)
		{
			if (green[i][x] != 0)
			{
				place = i - 1;
				break;
			}
		}
		green[place][x] = 1;
	}
	else if (t == 3)
	{
		for (int i = 1; i <= 5; i++)
		{
			if (green[i][x] != 0)
			{
				place = i - 1;
				break;
			}
		}
		green[place][x] = 1;
		green[place - 1][x] = 1;
	}
	else // t == 2
	{
		int place2 = 5;
		for (int i = 1; i <= 5; i++)
		{
			if (green[i][x] != 0)
			{
				place2 = i - 1;
				break;
			}
		}
		for (int i = 1; i <= 5; i++)
		{
			if (green[i][x + 1] != 0)
			{
				place = i - 1;
				break;
			}
		}
		if (place < place2)
		{
			green[place][x] = 2;
			green[place][x + 1] = 2;
		}
		else
		{
			green[place2][x] = 2;
			green[place2][x + 1] = 2;
		}
	}

	// ���� á���� Ȯ�� �� ���ֱ�
	while (true)
	{
		place = chkLine_green();
		if (place == -1) break;
		deleteLine_green(place, 1); // place �� ���ֱ� (��� �� �� ���ֱ�)
	}
}

// ���� ĭ�� ��� ���� �� ó�� �Լ�
void movLine_blue()
{
	int flag = 0;
	for (int i = 1; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (blue[j][i] != 0)
			{
				flag++;
				break;
			}
		}
	}

	for (int i = 0; i < flag; i++)
	{
		deleteLine_blue(5, -1);
	}
}

// ���� ĭ�� ��� ���� �� ó�� �Լ�
void movLine_green()
{
	int flag = 0;
	for (int i = 1; i >= 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (green[i][j] != 0)
			{
				flag++;
				break;
			}
		}
	}

	for (int i = 0; i < flag; i++)
	{
		deleteLine_green(5, -1);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	int t, x, y;
	for (int i = 0; i < n; i++)
	{
		cin >> t >> y >> x;
		movBlock_blue(t, y, x);
		movBlock_green(t, y, x);
		movLine_blue();
		movLine_green();
	}

	int block_n = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (blue[i][j] != 0) block_n++;
			if (green[j][i] != 0) block_n++;
		}
	}

	cout << score << '\n' << block_n;

	return 0;
}