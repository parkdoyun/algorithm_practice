#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 백준 10800 - 컬러볼
// 부분합
// 골드 3

// 배열 터지지 않을까?
// 1. 전체 공 sumArr 배열 (몇번째 idx인지 알아야 함)
// 2. 색깔별 공 sumArr 배열 (크기 및 info 배열에서 어디있는지 알아야 함)
// 3. 공 정보 배열 (부분 sumArr에서 어디있는지 알아야 함)

// 이분탐색으로 위치 찾아서 (나보다 작지만 제일 큰 애) => 시간초과
// 나 빼고 부분합 빼기

// 이분탐색 말고 그냥 기록하자
// 같은 수가 두개 있을 때 생각 못 함!!!

struct ball
{
	int idx; // 전체 배열에서 몇번인지
	int size = 0;
};

bool cmp1(ball b1, ball b2)
{
	if (b1.size < b2.size) return true;
	return false;
}
struct color_b
{
	int size;
	int idx; // info 배열에서 어딘지
};
bool cmp2(color_b b1, color_b b2)
{
	if (b1.size < b2.size) return true;
	return false;
}

struct info_b
{
	int color;
	int size;
	int idx; // color 배열에서 어딘지
	int total_idx; // total_vec 배열에서 어딘지
};

int sumArr[200002]; // 전체 부분합 배열
vector<info_b> info_vec; // 정보 배열
vector<ball> total_vec; // 전체 공 정렬할 배열
vector<vector<color_b>> color_vec;
vector<vector<int>> sum_color; // color sum arr
int n;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	total_vec.resize(n + 1);
	color_vec.resize(n + 1);
	sum_color.resize(n + 1);
	info_vec.resize(n + 1);

	int c, s;
	for (int i = 1; i <= n; i++)
	{
		cin >> c >> s;
		info_vec[i].size = s;
		info_vec[i].color = c;
		total_vec[i].idx = i;
		total_vec[i].size = s;
		if (color_vec[c].empty()) color_vec[c].push_back({ 0, -1 });
		color_vec[c].push_back({ s, i });
	}

	// 정렬 및 부분합 배열 생성
	sort(total_vec.begin(), total_vec.end(), cmp1);
	for (int i = 1; i <= n; i++)
	{
		sumArr[i] = sumArr[i - 1] + total_vec[i].size;
		info_vec[total_vec[i].idx].total_idx = i;
	}
	for (int i = 1; i <= n; i++)
	{
		if (color_vec[i].empty()) continue;
		sort(color_vec[i].begin(), color_vec[i].end(), cmp2);
		sum_color[i].resize(color_vec[i].size());
		sum_color[i][0] = 0;
		for (int j = 1; j < color_vec[i].size(); j++)
		{
			sum_color[i][j] = sum_color[i][j - 1] + color_vec[i][j].size;
			// 인덱스 매칭 같이 해주기
			info_vec[color_vec[i][j].idx].idx = j;
		}
	}
	
	int res;
	int info_total_idx, info_c, info_i, info_s;
	for (int i = 1; i <= n; i++)
	{
		// 나보다 같은 것 있으면 삭제
		info_total_idx = info_vec[i].total_idx;
		info_c = info_vec[i].color;
		info_i = info_vec[i].idx;
		info_s = info_vec[i].size;

		res = sumArr[info_total_idx - 1] - sum_color[info_c][info_i - 1];

		// 나와 같은 것 앞에 있으면 삭제 (total_vec)
		for (int j = info_total_idx - 1; j >= 1; j--)
		{
			if (total_vec[j].size == info_s) res -= info_s;
			else break;
		}

		// 나와 같은 것 앞에 있으면 더하기 (color_vec)
		for (int j = info_i - 1; j >= 1; j--)
		{
			if (color_vec[info_c][j].size == info_s) res += info_s;
			else break;
		}

		cout << res << '\n';
	}


	return 0;
}