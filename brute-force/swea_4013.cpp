#include <iostream>

using namespace std;

// swea 4013 - 특이한 자석
// brute-force

// pointer 6개
// arr[0] 1개 + 1개 (빨간색 화살표)
// arr[1] 2개 + 1개
// arr[2] 2개 + 1
// arr[3] 1개 + 1

int arr[4][9];
int point[4][3]; // idx 0 : 빨간색 화살표, idx 1 : 3시, idx 2 : 9시
int point_cp[4][3];
int sco[4] = { 1, 2, 4, 8 };

void rotation(int num, int dir) // 시계 1, 반시계 -1
{
	// 복사본 만들어놨다가 point에 한번에 적용시키기

	// arr[num] 회전
	for (int i = 0; i < 3; i++)
	{
		point_cp[num][i] = point_cp[num][i] - dir;
		// 0보다 작거나 7보다 크다면
		if (point_cp[num][i] < 0) point_cp[num][i] = 7;
		else if (point_cp[num][i] > 7) point_cp[num][i] = 0;
	}
	
	// num 앞뒤 바퀴 확인
	int tmp_dir = dir;
	for (int i = num - 1; i >= 0; i--)
	{
		if (arr[i + 1][point[i + 1][2]] == arr[i][point[i][1]]) break;
		tmp_dir = tmp_dir * -1; // 반대 방향
		for (int j = 0; j < 3; j++)
		{
			point_cp[i][j] = point_cp[i][j] - tmp_dir;
			// 0보다 작거나 7보다 크다면
			if (point_cp[i][j] < 0) point_cp[i][j] = 7;
			else if (point_cp[i][j] > 7) point_cp[i][j] = 0;
		}
	}

	tmp_dir = dir;
	for (int i = num + 1; i < 4; i++)
	{
		if (arr[i-1][point[i - 1][1]] == arr[i][point[i][2]]) break;
		tmp_dir = tmp_dir * -1; // 반대 방향
		for (int j = 0; j < 3; j++)
		{
			point_cp[i][j] = point_cp[i][j] - tmp_dir;
			// 0보다 작거나 7보다 크다면
			if (point_cp[i][j] < 0) point_cp[i][j] = 7;
			else if (point_cp[i][j] > 7) point_cp[i][j] = 0;
		}
	}

	// point에 한번에 적용
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++) point[i][j] = point_cp[i][j];
	}
}

int main()
{
	int T, k, score;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> k;

		for (int i = 0; i < 4; i++)
		{
			// 초기화
			point[i][0] = 0;
			point[i][1] = 2;
			point[i][2] = 6;
			
			for (int j = 0; j < 3; j++)
			{
				point_cp[i][j] = point[i][j];
			}

			for (int j = 0; j < 8; j++)
			{
				cin >> arr[i][j];
			}
		}

		int num, dir;
		for (int i = 0; i < k; i++)
		{
			cin >> num >> dir; // 바로 회전
			num--;

			rotation(num, dir);

			for (int i = 0; i < 4; i++)
			{
				//cout << i << ':' << arr[i][point[i][0]] << ' ' << arr[i][point[i][1]] << ' ' << arr[i][point[i][2]] << '\n';
			}
		}

		score = 0;
		for (int i = 0; i < 4; i++)
		{
			if (arr[i][point[i][0]] == 1) score += sco[i];
		}

		cout << '#' << tc << ' ' << score << '\n';
	}


	return 0;
}