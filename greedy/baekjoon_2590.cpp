#include <iostream>

using namespace std;

// 백준 2590 - 색종이
// greedy
// 골드 4

// 6번 색종이는 무조건 판 1개 사용
// 5번 색종이는 1번 색종이와 사용 가능
// 4번 색종이는 1번, 2번 색종이와 사용 가능
// 3번 색종이는 1, 2, 3번 색종이와 사용 가능 

int paper[7];
int total_cnt;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 1; i <= 6; i++)
	{
		cin >> paper[i];
	}
	total_cnt = paper[6];

	// 5번 색종이 채우기
	// 한 판에 5번 색종이 한개와 최대 1번 색종이 11개 가능
	for (int i = 0; i < paper[5]; i++)
	{
		total_cnt++;
		if (paper[1] < 11) paper[1] = 0;
		else paper[1] -= 11;
	}

	// 4번 색종이 채우기
	// 한 판에 2번 색종이 5개 가능
	// 1번 색종이는 남은 개수만큼 가능
	int tmp;
	for (int i = 0; i < paper[4]; i++)
	{
		total_cnt++;
		if (paper[2] < 5)
		{
			tmp = (5 - paper[2]) * 4;
			paper[2] = 0;
			if (paper[1] > tmp) paper[1] -= tmp;
			else paper[1] = 0;
		}
		else paper[2] -= 5;
	}

	// 3번 색종이 채우기
	while (paper[3] > 0)
	{
		total_cnt++;
		if (paper[3] <= 4) // 마지막 턴
		{
			if (paper[3] == 1) // 2번 최대 5개
			{
				if (paper[2] >= 5)
				{
					paper[2] -= 5;
					if (paper[1] >= 7) paper[1] -= 7;
					else paper[1] = 0;
				}
				else
				{
					tmp = 27 - paper[2] * 4;
					paper[2] = 0;
					if (paper[1] >= tmp) paper[1] -= tmp;
					else paper[1] = 0;
				}
			}
			else if (paper[3] == 2) // 2번 최대 3개
			{
				if (paper[2] >= 3)
				{
					paper[2] -= 3;
					if (paper[1] >= 6) paper[1] -= 6;
					else paper[1] = 0;
				}
				else
				{
					tmp = 18 - paper[2] * 4;
					paper[2] = 0;
					if (paper[1] >= tmp) paper[1] -= tmp;
					else paper[1] = 0;
				}
			}
			else if (paper[3] == 3) // 2번 최대 1개
			{
				if (paper[2] >= 1)
				{
					paper[2] -= 1;
					if (paper[1] >= 6) paper[1] -= 6;
					else paper[1] = 0;
				}
				else
				{
					if (paper[1] >= 9) paper[1] -= 9;
					else paper[1] = 0;
				}
			}
			break;
		}
		paper[3] -= 4;
	}

	// 1번, 2번 남았으면 채우기
	while (paper[1] > 0 || paper[2] > 0)
	{
		total_cnt++;
		if (paper[2] >= 9)
		{
			paper[2] -= 9;
		}
		else
		{
			tmp = 36 - paper[2] * 4;
			paper[2] = 0;
			if (paper[1] >= tmp) paper[1] -= tmp;
			else paper[1] = 0;
		}
	}

	cout << total_cnt;

	return 0;
}