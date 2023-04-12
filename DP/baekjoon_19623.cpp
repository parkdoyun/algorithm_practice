#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 19623 - 회의실 배정 4
// DP
// 골드 3

// 점화식 : 해당 회의를 할지말지
// max(내 시작 시간보다 종료 시간 더 앞이나 같은 애들 중 최대랑 더하거나, 내 시작시간이 시작과 종료 사이에 있는 애들)

// 만약 idx가 가리키는 DP 값보다 내가 포함되는 게 더 크다면(idx 이전꺼 보면서 나랑 겹치지 않는 최댓값 + 내 인원) 갱신
// 아니면 pass

struct confer
{
	int start; // 시작 시간
	int end; // 끝나는 시간
	int man; // 회의 인원
};
vector<confer> vec;

bool cmp(confer c1, confer c2)
{
	if (c1.end < c2.end) return true;
	else if (c1.end == c2.end && c1.start > c2.start) return true;
	else if (c1.start == c2.start && c1.end == c2.end && c1.man > c2.man) return true;
	return false;
}

int n;
int DP[100001];
int num[100001]; // 몇번 배열의 원소가 맨 마지막인지
int idx = 0; // 최댓값을 가리키는 인덱스

void chk(int now)
{
	// 찾기
	for (int i = idx; i >= 1; i--)
	{
		if (vec[num[i]].end <= vec[now].start)
		{
			// 비교 (나 더한 게 더 크다면)
			if (DP[i] + vec[now].man > DP[idx])
			{
				idx++;
				DP[idx] = DP[i] + vec[now].man;
				num[idx] = now;
			}
			return;
		}
	}
	// 0까지 왔다면 now만 따질 수 밖에 없음
	if (vec[now].man > DP[idx])
	{
		idx++;
		DP[idx] = vec[now].man;
		num[idx] = now;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int s, e, m;
	for (int i = 0; i < n; i++)
	{
		cin >> s >> e >> m;
		vec.push_back({ s, e, m });
	}

	sort(vec.begin(), vec.end(), cmp);

	// DP 기저 조건
	DP[0] = 0;
	num[0] = -1; // 여기 오면 나만 추가하기

	DP[1] = vec[0].man;
	num[1] = 0;
	idx = 1;

	// DP
	for (int i = 1; i < n; i++)
	{
		chk(i);
	}

	cout << DP[idx];

	return 0;
}