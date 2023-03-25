#include <iostream>
#include <map>
#include <string>

using namespace std;

// ���� 2866 - ���ڿ� �߶󳻱�
// binary search
// ��� 5

// ������ �� ��ģ�� => ��� ����� start = mid + 1
// ��ģ�� => end = mid - 1

char arr[1001][1001];
int r, c;
int max_cnt = 0;
map<string, int> map_chk; // �ߺ��Ǵ� ���ڿ� üũ

bool tableChk(int mid)
{
	map_chk.clear();
	string tmp;
	for (int i = 0; i < c; i++)
	{
		tmp = "";
		for (int j = mid; j < r; j++)
		{
			tmp += arr[j][i];
		}
		if (map_chk.find(tmp) != map_chk.end()) return false; // ��ģ��
		map_chk.insert({ tmp, 1 });
	}
	return true;
}

void binary_search()
{
	int start = 0;
	int end = r - 1;
	int mid;

	while (start <= end)
	{
		mid = (start + end) / 2;

		if (tableChk(mid)) // �� ��ģ��
		{
			if (max_cnt < mid) max_cnt = mid;

			start = mid + 1;
		}
		else end = mid - 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> r >> c;

	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++) cin >> arr[i][j];
	}

	binary_search();

	cout << max_cnt;

	return 0;
}