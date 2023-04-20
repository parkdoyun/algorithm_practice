#include <iostream>

using namespace std;

// 백준 19235 - 모노미노도미노
// 구현
// 플래티넘 5

// 한 행 사라지면 1점
// 1, 2, 3으로 모양 확인해야 함 (같은 모양끼리 떨어져야 돼서)

// blue일 때 2도 1로 표기
// green일 때 3도 1로 표기 (어차피 떨어질 때 똑같이 취급)

// blue는 2번 블록만 주의하면 되고 green은 3번 블록만 주의하면 된다
// (나머지는 각자 우수수 떨어져도 상관 없음)

// ** 땡길 때 무조건 0~4 방향부터 봐야 함!!!**

int blue[4][6];
int green[6][4];
int score = 0;

// 한줄 체크
int chkLine_blue() // 없으면 -1 return
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

// block 단위로 내려와야 함
// 한번에 모든 줄 다 없애야 함
void deleteLine_blue(int line_n, int f) // line 열 없애고 땡기기
{
	// 한줄 지우기
	int flag = -1;
	int tmp_line = line_n;
	while (true)
	{
		if(f != -1) score++;
		for (int i = 0; i < 4; i++)
		{
			blue[i][line_n] = 0; // 지우기
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
		line_n = tmp_line; // 다 찼다면 다음 줄 삭제
	}

	// 땡기기
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
				j++; // 다음 할 필요 X
			}
		}
	}
}

int chkLine_green() // 없으면 -1 return
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

void deleteLine_green(int line_n, int f) // line 열 없애고 땡기기
{
	int flag = -1;
	int tmp_line = line_n;
	while (true)
	{
		// 한줄 지우기
		if(f != -1) score++; // 점수 날 때 (연한 칸 때문에 온 게 아닐 때)
		for (int i = 0; i < 4; i++)
		{
			green[line_n][i] = 0; // 지우기
		}
		if (f == -1) break; // 연한 칸 왔을 때 무조건 한번만 지우고 나가기

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
		line_n = tmp_line; // 다 찼다면 다음 줄 삭제
	}

	// 땡기기
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
				j++; // 다음 할 필요 X
			}
		}
	}
}

// 블록 놓기
// 놓고 한줄 다 채웠으면 없애고 밀기
void movBlock_blue(int t, int y, int x)
{
	int place = 5;
	// 블록 놓기
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
		if (place < place2) // place 채택
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

	// 한줄 찼는지 확인 후 없애기
	while (true)
	{
		place = chkLine_blue();
		if (place == -1) break;
		deleteLine_blue(place, 1); // place 줄 없애기
	}
}

void movBlock_green(int t, int y, int x)
{
	int place = 5;
	// 블록 놓기
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

	// 한줄 찼는지 확인 후 없애기
	while (true)
	{
		place = chkLine_green();
		if (place == -1) break;
		deleteLine_green(place, 1); // place 줄 없애기 (모든 줄 다 없애기)
	}
}

// 연한 칸에 블록 있을 때 처리 함수
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

// 연한 칸에 블록 있을 때 처리 함수
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