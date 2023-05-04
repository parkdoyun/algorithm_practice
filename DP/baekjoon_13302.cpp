#include <iostream>
#include <algorithm>

using namespace std;

// 백준 13302 - 리조트
// DP (bottom-up)
// 골드 4

// 맨 마지막까지 갔다가 다시 재귀 반환하면서 DP 채움
// 결국 맨 초기 상태(1일째, 쿠폰 0개)가 정답이 됨

#define INF 999999999

int n, m;
int DP[101][101];
int absent[101]; // 쉬는 날

int chk(int day, int cou)
{
	if (day > n) return 0; // 만약 n일 이후라면 정답에 관여하면 안 되므로
	else if (DP[day][cou] != INF) return DP[day][cou]; // 이미 정해졌다면 (시간 단축 위해)

	// 안 오는 날일 경우 다음 날로 넘김
	if (absent[day] == 1)
	{
		DP[day][cou] = chk(day + 1, cou);
		return DP[day][cou];
	}

	int tmp_min = min(DP[day][cou], chk(day + 1, cou) + 10000); // 1일권 사용
	tmp_min = min(tmp_min, chk(day + 3, cou + 1) + 25000); // 연속 3일권 사용
	tmp_min = min(tmp_min, chk(day + 5, cou + 2) + 37000); // 연속 5일권 사용

	if (cou >= 3) // 쿠폰 사용 가능할 때
	{
		tmp_min = min(tmp_min, chk(day + 1, cou - 3));
	}

	DP[day][cou] = tmp_min; // 갱신

	return DP[day][cou];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;

	// 초기화
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 100; j++) DP[i][j] = INF;
	}

	int a;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		absent[a] = 1;
	}

	// DP
	cout << chk(1, 0);

	return 0;
}