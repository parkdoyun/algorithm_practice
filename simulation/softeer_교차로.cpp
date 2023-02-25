#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// softeer - ������
// simulation
// q 4�� (A,B,C,D)
// ��Ÿ�� ���� => vector�� ť �߸� �����ε� (����� ��)
// �ϴ� ���� �ڿ� ���� �� ���� �� ����ϴ� �ڵ� X
// ������ �ٷ� ��������
// �� 3

int n;
long long int t;
char w;

struct car
{
	long long int time;
	int idx;
};

queue<car> q[4];
vector<long long int> vec; // ���� �ð� ���
int flag[4]; // 2 : �ð� �� �ż� ���� �� ����, 1 : �����ʿ� �� �־ ���� �� ����, 0 : ���� �� ����

int chkCar(long long int now_time)
{
	int empty_flag = 0;
	int next; // ������ ����
	for (int i = 0; i < 4; i++)
	{
		if (q[i].empty())
		{
			flag[i] = 1;
			continue;
		}
		next = i - 1;
		if (next == -1) next = 3;

		empty_flag = 1;

		if (!q[next].empty() && q[next].front().time <= now_time) flag[i] = 1; // ���� �� ����
		else if (q[i].front().time > now_time) flag[i] = 2; // �� ���µ� �ð��� �� ��
		else flag[i] = 0; // �� ���� ���� �� ����
	}
	if (empty_flag == 0) return -1; // ���� ���� ���ٸ�

	// �� �־ ���� ����
	if (flag[0] == 1 && flag[1] == 1 && flag[2] == 1 && flag[3] == 1) return -1;

	// ���� �� �ִ� �ֵ� �ִٸ�
	if (flag[0] == 0 || flag[1] == 0 || flag[2] == 0 || flag[3] == 0) return 0;

	// ���� �� �־ ���� �� ���� ���� + �ð� �� �ż� �� ������ �ֵ鸸 �ִٸ�
	return 2;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	vec.resize(n + 1);

	for (int i = 0; i < n; i++)
	{
		cin >> t >> w;
		q[(int)(w - 'A')].push({ t, i });
		vec[i] = -1;
	}

	// �ϳ��� ����
	long long int now_time = q[0].front().time;
	for (int i = 1; i < 4; i++)
	{
		if (q[i].empty()) continue;
		if (q[i].front().time < now_time) now_time = q[i].front().time;
	}

	// �Ǵ� �ֵ� ���� �ѹ��� ���� (���ÿ�)
	int res;
	while (true)
	{
		res = chkCar(now_time);

		// deadlock�̳� �� ������
		if (res == -1) break;

		// �ð� ��ٷ��� ��
		if (res == 2)
		{
			now_time = 9999999999;
			for (int i = 0; i < 4; i++)
			{
				if (q[i].empty()) continue;
				else if (q[i].front().time < now_time) now_time = q[i].front().time;
			}
			continue;
		}

		// ���� �� �ִ� �ֵ� pop
		for (int i = 0; i < 4; i++)
		{
			if (flag[i] == 0)
			{
				vec[q[i].front().idx] = now_time;
				q[i].pop();
			}
		}
		now_time++;
	}

	// ��� ���
	for (int i = 0; i < n; i++) cout << vec[i] << '\n';

	return 0;
}