#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// swea 5644 - 무선 충전
// brute-force

struct battery
{
	int y;
	int x;
	int c;
	int p;
};
vector<battery> vec_b;
int m, a;

int x_mov[] = { 0, 0, 1, 0, -1 };
int y_mov[] = { 0, -1, 0, 1, 0 };

int a_arr[101];
int b_arr[101];
int board[11][11];
int a_x, a_y, b_x, b_y;

int max1;
int total;

void chk()
{
	max1 = 0;

	int a_idx, b_idx;
	// a가 아무것도 안 걸치는 경우
	for (int i = 0; i < a; i++)
	{
		if (abs(vec_b[i].x - b_x) + abs(vec_b[i].y - b_y) > vec_b[i].c) continue;
		if (max1 < vec_b[i].p) max1 = vec_b[i].p;
	}

	// a가 걸치는 경우
	// a와 b for문 2개로 최댓값 넣자
	a_idx = -1;
	for (int i = 0; i < a; i++) // a
	{
		if (abs(vec_b[i].x - a_x) + abs(vec_b[i].y - a_y) > vec_b[i].c) continue;
		a_idx = i;
		b_idx = -1;
		for (int j = 0; j < a; j++) // b
		{
			if (abs(vec_b[j].x - b_x) + abs(vec_b[j].y - b_y) > vec_b[j].c) continue;
			b_idx = j;
			// 계산, max 값과 비교
			if (a_idx == b_idx)
			{
				if (max1 < vec_b[a_idx].p) max1 = vec_b[a_idx].p;
			}
			else
			{
				if (max1 < vec_b[a_idx].p + vec_b[b_idx].p) max1 = vec_b[a_idx].p + vec_b[b_idx].p;
			}
		}
		if (b_idx == -1) // b가 아무것도 안 걸치는 경우
		{
			if (max1 < vec_b[a_idx].p) max1 = vec_b[a_idx].p;
		}
	}

}


int main()
{
	// 이동시간 마다 매번 backtracking 사용 -> 모든 가짓수 가지고 최댓값 할당
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> m >> a;
		vec_b.clear();
		total = 0;

		for (int i = 0; i < m; i++)
		{
			cin >> a_arr[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b_arr[i];
		}

		for (int i = 0; i < a; i++)
		{
			battery b;
			cin >> b.x >> b.y >> b.c >> b.p;
			vec_b.push_back(b);
		}
		
		a_x = 1;
		a_y = 1;
		b_x = 10;
		b_y = 10;

		// t = 0번부터 시작
		chk();
		//cout << 0 << ' ' << max1 << endl;
		total += max1;


		// t = 1
		for (int i = 0; i < m; i++)
		{
			a_x += x_mov[a_arr[i]];
			a_y += y_mov[a_arr[i]];

			b_x += x_mov[b_arr[i]];
			b_y += y_mov[b_arr[i]];

			chk();
			//cout << i + 1 << ' ' << max1 << endl;

			total += max1;
		}

		cout << '#' << tc << ' ' << total << '\n';

	}

	return 0;
}