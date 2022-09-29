#include <iostream>
using namespace std;

// ���� 1987�� - ���ĺ�
// DFS

int alpha_check[27]{ 0 }; // 0~25 ��� A : 0�� �ε��� ���
char board[22][22];
void DFS(int r, int c, int x, int y, int route_n);
int max_num = -1; // �ִ� ĭ ��, �ָ��� ������ ��ȣ�ϴٰ� �� �� ����

int main()
{
	int r, c;
	cin >> r >> c;
	
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			cin >> board[i][j];
		}
	}
	DFS(r, c, 1, 1, 0);
	cout << max_num << '\n';
	return 0;
}
void DFS(int r, int c, int x, int y, int route_n)
{
	alpha_check[(int)(board[x][y] - 'A')] = 1;
	if (route_n + 1 > max_num) max_num = route_n + 1;
	// �����¿� üũ
	if (x + 1 <= r && x + 1 >= 1 && y <= c && y >= 1
		&& alpha_check[(int)(board[x + 1][y] - 'A')] == 0)
	{
		DFS(r, c, x + 1, y, route_n + 1);
	}
	if (x - 1 <= r && x - 1 >= 1 && y <= c && y >= 1
		&& alpha_check[(int)(board[x - 1][y] - 'A')] == 0)
	{
		DFS(r, c, x - 1, y, route_n + 1);
	}
	if (x <= r && x >= 1 && y + 1 <= c && y + 1 >= 1
		&& alpha_check[(int)(board[x][y + 1] - 'A')] == 0)
	{
		DFS(r, c, x, y + 1, route_n + 1);
	}
	if (x <= r && x >= 1 && y - 1 <= c && y - 1 >= 1
		&& alpha_check[(int)(board[x][y - 1] - 'A')] == 0)
	{
		DFS(r, c, x, y - 1, route_n + 1);
	}
	alpha_check[(int)(board[x][y] - 'A')] = 0; // ���� ����� -> �� �ϸ� �ٸ� ��ο� ����
}