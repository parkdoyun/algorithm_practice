#include <iostream>
#include <queue>

using namespace std;

// 백준 17136 - 색종이 붙이기

// 색종이의 모든 칸이 전부 1이어야 붙일 수 있다 -> 붙이면 전부 0 됨
// 색종이는 크기 별로 5개씩
// 어차피 5개니까 검사함수로 만들자
// 제일 크게 붙일 수 있는 색종이 붙이고 -> 없으면 작게 해서 붙여야 함
// 처음 들어가는 1이 사각형의 가장 왼쪽 1이므로 밑으로 점점 크기 검사

// 왼쪽 위랑 오른쪽 아래 두번 시행한 후
// -1이 아닌 것 중에서 최소 출력

int board[11][11];
int board2[11][11];
int chk[11][11];
int paper_n[6] = { 0, 5, 5, 5, 5, 5 }; // 남은 색종이 갯수
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
	return 1; // 가능
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
	return 1; // 가능
}


void checkPaper(int start_y, int start_x)
{
	// 가장 큰 크기부터 확인
	int size = 1;
	for (int i = 5; i > 1; i--)
	{
		if (OK(start_y, start_x, i) == 1)
		{
			size = i;
			break;
		}
	}

	// size만한 색종이 붙이기
	// 없으면 -> 더 작은 색종이 있을 때까지 찾고 붙이기
	for (int i = size; i >= 1; i--)
	{
		if (paper_n[i] > 0)
		{
			// 색종이 붙이기 -> 0으로 만들기
			attachPaper(start_y, start_x, i, 1);

			paper_n[i]--;
			cnt++;
			break;
		}
	}
}

void checkPaper2(int start_y, int start_x)
{
	// 가장 큰 크기부터 확인
	int size = 1;
	for (int i = 5; i > 1; i--)
	{
		if (OK2(start_y, start_x, i) == 1)
		{
			size = i;
			break;
		}
	}

	// size만한 색종이 붙이기
	// 없으면 -> 더 작은 색종이 있을 때까지 찾고 붙이기
	for (int i = size; i >= 1; i--)
	{
		if (paper_n[i] > 0)
		{
			// 색종이 붙이기 -> 0으로 만들기
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
				// 검사함수
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

	// 오른쪽 아래부터 다시 검사
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
				// 검사함수
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