#include <iostream>
#include <queue>

using namespace std;

// ���� 17136 - ������ ���̱�

// �������� ��� ĭ�� ���� 1�̾�� ���� �� �ִ� -> ���̸� ���� 0 ��
// �����̴� ũ�� ���� 5����
// ������ 5���ϱ� �˻��Լ��� ������
// ���� ũ�� ���� �� �ִ� ������ ���̰� -> ������ �۰� �ؼ� �ٿ��� ��
// ó�� ���� 1�� �簢���� ���� ���� 1�̹Ƿ� ������ ���� ũ�� �˻�

// ���� ���� ������ �Ʒ� �ι� ������ ��
// -1�� �ƴ� �� �߿��� �ּ� ���

int board[11][11];
int board2[11][11];
int chk[11][11];
int paper_n[6] = { 0, 5, 5, 5, 5, 5 }; // ���� ������ ����
int cnt = 0;
int cnt2 = 0;

void chkClear()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) chk[i][j] = 0;
	}
}

struct node
{
	int y;
	int x;
	int dist;
};

void attachPaper(int start_y, int start_x, int paper_size, int num)
{
	for (int i = 0; i < paper_size; i++)
	{
		for (int j = 0; j < paper_size; j++)
		{
			if(num == 1) board[start_y + i][start_x + j] = 0;
			else board2[start_y + i][start_x + j] = 0;
		}
	}
}

int OK(int start_y, int start_x, int size)
{
	if (start_y + size - 1 >= 10 || start_x + size - 1 >= 10) return -1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[start_y + i][start_x + j] == 0) return -1;
		}
	}
	return 1; // ����
}

int OK2(int start_y, int start_x, int size)
{
	if (start_y - size + 1 < 0 || start_x - size + 1 < 0) return -1;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board2[start_y - i][start_x - j] == 0) return -1;
		}
	}
	return 1; // ����
}


void checkPaper(int start_y, int start_x)
{
	// ���� ū ũ����� Ȯ��
	int size = 1;
	for (int i = 5; i > 1; i--)
	{
		if (OK(start_y, start_x, i) == 1)
		{
			size = i;
			break;
		}
	}

	// size���� ������ ���̱�
	// ������ -> �� ���� ������ ���� ������ ã�� ���̱�
	for (int i = size; i >= 1; i--)
	{
		if (paper_n[i] > 0)
		{
			// ������ ���̱� -> 0���� �����
			attachPaper(start_y, start_x, i, 1);

			paper_n[i]--;
			cnt++;
			break;
		}
	}
}

void checkPaper2(int start_y, int start_x)
{
	// ���� ū ũ����� Ȯ��
	int size = 1;
	for (int i = 5; i > 1; i--)
	{
		if (OK2(start_y, start_x, i) == 1)
		{
			size = i;
			break;
		}
	}

	// size���� ������ ���̱�
	// ������ -> �� ���� ������ ���� ������ ã�� ���̱�
	for (int i = size; i >= 1; i--)
	{
		if (paper_n[i] > 0)
		{
			// ������ ���̱� -> 0���� �����
			attachPaper(start_y - i + 1, start_x - i + 1, i, 2);

			paper_n[i]--;
			cnt2++;
			break;
		}
	}
}

int main()
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			cin >> board[i][j];
			board2[i][j] = board[i][j];
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == 1)
			{
				// �˻��Լ�
				checkPaper(i, j);
			}
		}
	}

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (board[i][j] == 1)
			{
				cnt = -1;
				break;
			}
		}
	}

	// ������ �Ʒ����� �ٽ� �˻�
	paper_n[1] = 5;
	paper_n[2] = 5;
	paper_n[3] = 5;
	paper_n[4] = 5;
	paper_n[5] = 5;

	for (int i = 9; i >= 0; i--)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (board2[i][j] == 1)
			{
				// �˻��Լ�
				checkPaper2(i, j);
			}
		}
	}

	for (int i = 9; i >= 0; i--)
	{
		for (int j = 9; j >= 0; j--)
		{
			if (board2[i][j] == 1)
			{
				cnt2 = -1;
				break;
			}
		}
	}

	if (cnt == -1 && cnt2 == -1) cout << -1;
	else if(cnt == -1 && cnt2 != -1)
	{
		cout << cnt2;
	}
	else if (cnt != -1 && cnt2 == -1)
	{
		cout << cnt;
	}
	else
	{
		cout << min(cnt, cnt2);
	}
	return 0;
}