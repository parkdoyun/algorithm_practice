#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 19623 - ȸ�ǽ� ���� 4
// DP
// ��� 3

// ��ȭ�� : �ش� ȸ�Ǹ� ��������
// max(�� ���� �ð����� ���� �ð� �� ���̳� ���� �ֵ� �� �ִ�� ���ϰų�, �� ���۽ð��� ���۰� ���� ���̿� �ִ� �ֵ�)

// ���� idx�� ����Ű�� DP ������ ���� ���ԵǴ� �� �� ũ�ٸ�(idx ������ ���鼭 ���� ��ġ�� �ʴ� �ִ� + �� �ο�) ����
// �ƴϸ� pass

struct confer
{
	int start; // ���� �ð�
	int end; // ������ �ð�
	int man; // ȸ�� �ο�
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
int num[100001]; // ��� �迭�� ���Ұ� �� ����������
int idx = 0; // �ִ��� ����Ű�� �ε���

void chk(int now)
{
	// ã��
	for (int i = idx; i >= 1; i--)
	{
		if (vec[num[i]].end <= vec[now].start)
		{
			// �� (�� ���� �� �� ũ�ٸ�)
			if (DP[i] + vec[now].man > DP[idx])
			{
				idx++;
				DP[idx] = DP[i] + vec[now].man;
				num[idx] = now;
			}
			return;
		}
	}
	// 0���� �Դٸ� now�� ���� �� �ۿ� ����
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

	// DP ���� ����
	DP[0] = 0;
	num[0] = -1; // ���� ���� ���� �߰��ϱ�

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