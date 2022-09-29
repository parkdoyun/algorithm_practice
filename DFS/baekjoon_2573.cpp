#include <iostream>
using namespace std;

// ���� 2573�� - ����
// DFS
// �ֺ� 0 ����� �����ϴ� �迭 (�����¿�)
// �Ѳ����� ���� ��Ŵ
// �� ������� Ȯ�� (DFS)

struct node
{
	int x = -1;
	int y = -1;
	int zero_cnt = -1;
};

int board[302][302]{ 0 }; // ����
int visit[302][302]{ 0 }; // �湮
void DFS(int n, int m, int x, int y);

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
		}
	}
	int year = 0;
	while (true) // �� ��� ���Ϸ� ���� ������
	{
		node arr[10001];
		int arr_ptr = 0; // ������ �� �� �ִ� �迭 ������
		for (int i = 1; i < n-1; i++)
		{
			for (int j = 1; j < m-1; j++)
			{
				if (board[i][j] != 0)
				{
					// �����¿� 0 Ȯ��
					int zero_cnt = 0;
					if (board[i - 1][j] == 0) zero_cnt++;
					if (board[i + 1][j] == 0) zero_cnt++;
					if (board[i][j - 1] == 0) zero_cnt++;
					if (board[i][j + 1] == 0) zero_cnt++;
					arr[arr_ptr] = { i, j, zero_cnt };
					arr_ptr++;
				}
			}
		}
		// ���� 0��(������ �� ���� ������ �и����� ����)
		if (arr_ptr == 0)
		{
			cout << "0\n";
			break;
		}
		// ����
		for (int i = 0; i < arr_ptr; i++)
		{
			if (board[arr[i].x][arr[i].y] >= arr[i].zero_cnt)
			{
				board[arr[i].x][arr[i].y] -= arr[i].zero_cnt;
			}
			else board[arr[i].x][arr[i].y] = 0;
		}
		year++;
		
		// ��� ���� Ȯ��
		int mass_n = 0;
		for (int i = 1; i < n - 1; i++)
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (board[i][j] != 0 && visit[i][j] == 0)
				{
					visit[i][j] = 1;
					DFS(n, m, i, j);
					mass_n++;
				}
			}
		}
		if (mass_n >= 2)
		{
			cout << year << '\n';
			break;
		}

		//memset(visit, 0, sizeof(visit)); // visit�迭 0���� �ʱ�ȭ -> �� ��
		for (int i = 1; i < n - 1; i++) // �湮 �ʱ�ȭ
		{
			for (int j = 1; j < m - 1; j++)
			{
				if (visit[i][j] != 0) visit[i][j] = 0;
			}
		}
		
	}

	return 0;
}
void DFS(int n, int m, int x, int y)
{
	// �����¿� 0 �ƴϰ� ��������, �湮 �� �ߴ��� Ȯ��
	if (x + 1 >= 1 && x + 1 < n - 1 && y >= 1 && y < m - 1
		&& board[x+1][y] != 0 && visit[x+1][y] == 0)
	{
		visit[x + 1][y] = 1;
		DFS(n, m, x + 1, y);
	}
	if (x - 1 >= 1 && x - 1 < n - 1 && y >= 1 && y < m - 1
		&& board[x - 1][y] != 0 && visit[x - 1][y] == 0)
	{
		visit[x - 1][y] = 1;
		DFS(n, m, x - 1, y);
	}
	if (x >= 1 && x < n - 1 && y + 1 >= 1 && y + 1 < m - 1
		&& board[x][y + 1] != 0 && visit[x][y + 1] == 0)
	{
		visit[x][y + 1] = 1;
		DFS(n, m, x, y + 1);
	}
	if (x>= 1 && x< n - 1 && y - 1 >= 1 && y - 1 < m - 1
		&& board[x][y - 1] != 0 && visit[x][y - 1] == 0)
	{
		visit[x][y - 1] = 1;
		DFS(n, m, x, y - 1);
	}
}
