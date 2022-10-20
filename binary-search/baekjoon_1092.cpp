#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ���� 1092 - ��
// greedy, binary_search
// ��� 5

// �̺� Ž�� (�� ũ���� �� ���� �� �ִ� �ڽ� ����)
// �ڽ��� ���࿡ �Ǿ����� OK(mid) == 1�̸� �ڽ� ������ �� �ð��̹Ƿ�
// �ð��� �� �ٿ���(�ڽ� ������ �ٿ���) �� �ð� �ȿ� �ڽ��� ũ���ο� ��� ���� �� Ȯ��

bool cmp(int a, int b)
{
	if (a < b) return true;
	return false;
}

vector<int> crane;
vector<int> box;
int n, m, a;

int ok(int mid) // ũ���ο� mid������ŭ �ڽ��� ��� �� �ִ���
{
	int idx = 0;
	for (int i = 0; i < n; i++)
	{
		int tmp_idx = idx;
		if (idx >= m) break;
		for (int j = tmp_idx; j < tmp_idx + mid; j++)
		{
			if (j >= m) break;
			if (box[j] > crane[i]) break;
			idx++;
		}
	}
	if (idx < m) return -1;
	return 1;
}

int main()
{

	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> a;
		crane.push_back(a);
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		box.push_back(a);
	}

	sort(crane.begin(), crane.end(), cmp);
	sort(box.begin(), box.end(), cmp);

	if (box[m - 1] > crane[n - 1])
	{
		cout << -1;
		return 0;
	}

	// �̺� Ž��
	int start = 1;
	int end = m;
	int mid;
	int time = m;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (ok(mid) == 1)
		{
			if (time > mid) time = mid;
			end = mid - 1;
		}
		else start = mid + 1;
	}
	cout << time;
	return 0;
}