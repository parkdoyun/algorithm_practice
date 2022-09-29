#include <iostream>
using namespace std;

// ���� 16173�� - ������ �A��
// �����ʺ��� -> �Ʒ�
// DFS�� �������� �� �ϸ� return
// �����ϸ� ���´�
// brute-force, DFS

void DFS(int n, int x, int y); // check: �����ߴ��� ����
int check = -1;
int board[4][4]{ 0 };

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) // �Է�
	{
		for (int j = 0; j < n; j++)
		{
			cin >> board[i][j];
		}
	}
	
	DFS(n, 0, 0);
	
	if (check == 1) cout << "HaruHaru\n";
	else cout << "Hing\n";
	
	return 0;
}
void DFS(int n, int x, int y)
{
	if (x > n - 1 || y > n - 1) return; // ���� ���
	else if (x == n - 1 && y == n - 1)
	{
		check = 1;
		return;
	}
	else if (board[x][y] == 0) return; // *** 0�� ĭ�� ������ ���ѷ��� ����
	else // �ƴ� ���, �̵�
	{		
		int a = board[x][y];
		DFS(n, x + a, y);
		DFS(n, x, y + a);		
	}
	
}