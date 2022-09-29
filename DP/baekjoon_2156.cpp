#include <iostream>

using namespace std;

// 백준 2156 - 포도주 시식
// DP
// 실버 1

// 바로 전이랑 이어서 마시는 게 더 큰지 아니면 점프해서 마시는 게 큰지?
// 점프 할건지 아닌지

// 반례 : 점프를 한번 하라는 말은 없었음

int wine[10001];

int DP1[10001]; // 포도주를 첫번째로 마시는 배열, 여기 애들은 무조건 첫번째로 마신 값만
int DP2[10001]; // 포도주를 두번째로 마시는 배열

int DP_no[10001]; // 포도주를 마시지 않는 배열

int main()
{
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> wine[i];
	}

	// 기저 조건
	DP1[0] = wine[0];
	DP2[0] = 0;
	DP_no[0] = 0;

	for (int i = 1; i < n; i++) // i번째에서 점프할 때, 첫번째 와인일 때, 두번째 와인일 때
	{
		int tmp_max = DP_no[i - 1];
		if (tmp_max < DP1[i - 1]) tmp_max = DP1[i - 1];
		if (tmp_max < DP2[i - 1]) tmp_max = DP2[i - 1];
		DP_no[i] = tmp_max;
		DP1[i] = DP_no[i - 1] + wine[i];
		DP2[i] = DP1[i - 1] + wine[i];
	}


	int max = DP1[n - 1];
	if (max < DP2[n - 1]) max = DP2[n - 1];
	if (max < DP_no[n - 1]) max = DP_no[n - 1];

	cout << max;

	return 0;
}