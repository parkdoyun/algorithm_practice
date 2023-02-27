#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 10800 - �÷���
// �κ���
// ��� 3

// �迭 ������ ������?
// 1. ��ü �� sumArr �迭 (���° idx���� �˾ƾ� ��)
// 2. ���� �� sumArr �迭 (ũ�� �� info �迭���� ����ִ��� �˾ƾ� ��)
// 3. �� ���� �迭 (�κ� sumArr���� ����ִ��� �˾ƾ� ��)

// �̺�Ž������ ��ġ ã�Ƽ� (������ ������ ���� ū ��) => �ð��ʰ�
// �� ���� �κ��� ����

// �̺�Ž�� ���� �׳� �������
// ���� ���� �ΰ� ���� �� ���� �� ��!!!

struct ball
{
	int idx; // ��ü �迭���� �������
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
	int idx; // info �迭���� �����
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
	int idx; // color �迭���� �����
	int total_idx; // total_vec �迭���� �����
};

int sumArr[200002]; // ��ü �κ��� �迭
vector<info_b> info_vec; // ���� �迭
vector<ball> total_vec; // ��ü �� ������ �迭
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

	// ���� �� �κ��� �迭 ����
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
			// �ε��� ��Ī ���� ���ֱ�
			info_vec[color_vec[i][j].idx].idx = j;
		}
	}
	
	int res;
	int info_total_idx, info_c, info_i, info_s;
	for (int i = 1; i <= n; i++)
	{
		// ������ ���� �� ������ ����
		info_total_idx = info_vec[i].total_idx;
		info_c = info_vec[i].color;
		info_i = info_vec[i].idx;
		info_s = info_vec[i].size;

		res = sumArr[info_total_idx - 1] - sum_color[info_c][info_i - 1];

		// ���� ���� �� �տ� ������ ���� (total_vec)
		for (int j = info_total_idx - 1; j >= 1; j--)
		{
			if (total_vec[j].size == info_s) res -= info_s;
			else break;
		}

		// ���� ���� �� �տ� ������ ���ϱ� (color_vec)
		for (int j = info_i - 1; j >= 1; j--)
		{
			if (color_vec[info_c][j].size == info_s) res += info_s;
			else break;
		}

		cout << res << '\n';
	}


	return 0;
}