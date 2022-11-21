#include <iostream>

using namespace std;

// ���� 17136 - ������ ���̱�
// brute-force, DFS
// ��� 2

// �����̷� ���� �� �ִ� ��� ������ �� �غ��� (DFS)
// �����̷� �� ���� �� ������ ���� ������ �� ī��Ʈ

// ���� ���� �κ� �߰��ϰ� �ش� ĭ �����̷� ���� �� ������
// ���� ���� ������ �κ����� DFS

// �����̷� �� �������� DFS return

int min1 = 10000000;
int path[25];
int cp[11][11];
int paper_n[6] = { 0, 5, 5, 5, 5, 5 }; // ������ ����

void findNext(int y, int x, int &y1, int &x1) // ���� �����̷� ����� �ϴ� �κ� ã��
{
	for (int i = y; i < 10; i++)
	{
		if (i == y)
		{
			for (int j = x; j < 10; j++)
			{
				if (cp[i][j] == 1)
				{
					y1 = i;
					x1 = j;
					return;
				}
			}
		}
		else
		{
			for (int j = 0; j < 10; j++)
			{
				if (cp[i][j] == 1)
				{
					y1 = i;
					x1 = j;
					return;
				}
			}
		}
	}
	y1 = -1; // �����̷� ���� �κ� X -> �� ����
	x1 = -1;
}

int printChk(int y, int x, int n) // �����̷� ���� �� �ִ��� Ȯ��
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (cp[y + i][x + j] == 0) return -1;
		}
	}
	return 1;
}

void print(int y, int x, int n, int val) // �����̷� ���� �Ǵ� ���󺹱�
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cp[y + i][x + j] = val;
		}
	}
}

void DFS(int y, int x, int cnt) {
	int next_y, next_x;
	for (int i = 1; i <= 5; i++)
	{
		if (paper_n[i] == 0) continue;
		if (printChk(y, x, i) == 1) // i ũ���� �����̷� ���� �� �ִٸ�
		{
			print(y, x, i, 0); // �����̷� ����
			paper_n[i]--; // ������ ī��Ʈ ���̱�
			findNext(y, x, next_y, next_x);
			if (next_y != -1 && next_x != -1)
			{ // �������� �Ѿ
				DFS(next_y, next_x, cnt + 1);
			}
			else // �����̷� �� ���� -> ������ ���� ī��Ʈ
			{
				if (min1 > cnt) min1 = cnt;
			}
			paper_n[i]++; // ī��Ʈ ���󺹱�
			print(y, x, i, 1); // ���� �� ���󺹱�
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++) cin >> cp[i][j];
	}

	int start_y, start_x;
	findNext(0, 0, start_y, start_x);
	if (start_y == -1 && start_x == -1) // ������ �ʿ� ���ٸ� �ٷ� 0 ���
	{
		cout << 0;
		return 0;
	}
	DFS(start_y, start_x, 1);

	if (min1 == 10000000) min1 = -1;
	cout << min1;

	return 0;
}