#include <iostream>

using namespace std;

// ���� 2239 - ������
// backtracking
// ��� 4

// simulation���� Ǯ�ٰ� �ð��ʰ� �� ���� -> backtracking
// 1���� �����鼭 �ϴ� path[]�� 0 ������ �� ������ �������� �ѱ�

int board[10][10];

void pathChk(int y, int x, int path[10]) // board[y][x]�� �� �� �ִ� �� ����
{
	// ������ Ȯ��
	for (int i = 0; i < 9; i++)
	{
		path[board[y][i]]++;
	}
	// ������ Ȯ��
	for (int i = 0; i < 9; i++)
	{
		path[board[i][x]]++;
	}
	// ���� Ȯ��
	int sy = y - (y % 3);
	int sx = x - (x % 3);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			path[board[sy + i][sx + j]]++;
		}
	}
}

int total_flag = 0;
void backtracking(int y, int x) // �� ���� ��ĭ�� üũ�ϸ� ��
{
	if (total_flag == 1) return;
	int tmp_path[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	// ����, ����, ���� Ȯ���ؼ� ���� �� �ִ� ���� ������� �ְ� backtracking
	// ä�� �� �ִ� ���� ���ٸ� return
	// �ش� ���� �� �� �ִ� �� ���� -> ���� ��ͷ� ���ƿͼ� ���� ���� ä��

	int flag = 0;

	int ty = -1; // �� ���� ��ĭ
	int tx = -1;
	for (int i = x + 1; i < 9; i++)
	{
		if (board[y][i] == 0)
		{
			ty = y;
			tx = i;
			break;
		}
	}
	if (ty == -1 && tx == -1)
	{
		for (int i = y + 1; i < 9; i++)
		{
			for (int j = 0; j < 9; j++)
			{
				if (board[i][j] == 0)
				{
					ty = i;
					tx = j;
					break;
				}
			}
			if (ty != -1) break;
		}
	}
	// �� ty�� tx -1 => ������ �ϼ�(���� ��ĭ�� �� �� �̻� 0�� �ֵ� ����)
	if (ty == -1 && tx == -1)
	{
		total_flag = 1;
		return;
	}
	else // �ƴ϶�� ���� ��ĭ ä���
	{
		for (int j = 0; j <= 9; j++) tmp_path[j] = 0;
		pathChk(ty, tx, tmp_path);
		for (int j = 1; j <= 9; j++)
		{
			if (tmp_path[j] != 0) continue;
			board[ty][tx] = j;
			backtracking(ty, tx);
			if (total_flag == 1) return;
			board[ty][tx] = 0;
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	char c;
	int sy = -1;
	int sx = -1;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> c;
			board[i][j] = (int)(c - '0');
			if (board[i][j] == 0 && sy == -1 && sx == -1)
			{
				sy = i;
				sx = j;
			}
		}
	}

	int tmp_path[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	pathChk(sy, sx, tmp_path);
	for (int i = 1; i <= 9; i++)
	{
		if (tmp_path[i] != 0) continue;
		board[sy][sx] = i;
		backtracking(sy, sx);
		if (total_flag == 1) break;
		board[sy][sx] = 0;
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++) cout << board[i][j];
		cout << '\n';
	}

	return 0;
}