#include <iostream>
#include <string>

using namespace std;

// 백준 2651 - 자동차경주대회
// DP
// 골드 4

// 점화식
// DP[i] = min(i로부터 최대 max_len만큼 뒤에 있는 애들의 정비소 시간) + time[i];
// 마지막은 예외로 time[i] 안 더함

int max_len; // 최대 거리
int n; // 정비소 수
int len[103]; // 정비소 간 거리
int time[102]; // 정비소
int DP[103];
int prev_stop[103]; // i번 정비소에서 온 이전 정비소

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> max_len >> n;
	for (int i = 0; i <= n; i++) cin >> len[i];
	for (int i = 1; i <= n; i++) cin >> time[i];
	for (int i = 0; i <= n + 1; i++) DP[i] = -1;

	// DP
	// 기저 조건
	DP[0] = 0; // 시작점
	prev_stop[0] = -1;

	for (int i = 1; i <= n; i++)
	{
		int now_len = 0;
		for (int j = i - 1; j >= 0; j--)
		{
			now_len += len[j];
			if (now_len > max_len) break;

			if (DP[i] > DP[j] || DP[i] == -1)
			{
				DP[i] = DP[j];
				prev_stop[i] = j;
			}
		}
		DP[i] += time[i];
	}

	// 마지막 계산 (n + 1)
	int now_len = 0;
	for (int j = n; j >= 0; j--)
	{
		now_len += len[j];
		if (now_len > max_len) break;

		if (DP[n + 1] > DP[j] || DP[n + 1] == -1)
		{
			DP[n + 1] = DP[j];
			prev_stop[n + 1] = j;
		}
	}

	cout << DP[n + 1] << '\n';
	if (DP[n + 1] != 0)
	{
		int stop_cnt = 0;
		string list = "";

		int idx = prev_stop[n + 1];
		while (idx != 0)
		{
			stop_cnt++;
			list = to_string(idx) + " " + list;
			idx = prev_stop[idx];
		}
		cout << stop_cnt << '\n' << list;
	}
	else cout << 0;

	return 0;
}