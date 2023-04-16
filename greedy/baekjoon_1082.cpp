#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// ���� 1082 - �� ��ȣ
// greedy
// ��� 3

// �ڸ��� ���� �� �� ũ�� (���� �� �� �� �ִ� ��)
// �ڸ��� ���ٸ� ���� ū �� �� ũ��
// ���� ���� �� �ϴ� �� �� �ִ� ��ŭ ���
// ó�� �ڸ������� �ٲ� �� �ִ� ���� ū ���� �ٲ۴�

struct room
{
	int num;
	int price;
};
vector<room> info; // �ε��� = ���ȣ
vector<room> vec; // ���� ���� �������
vector<room> vec2; // ���ȣ ū �������

bool cmp(room r1, room r2)
{
	if (r1.price < r2.price) return true;
	else if (r1.price == r2.price && r1.num > r2.num) return true;
	return false;
}
bool cmp2(room r1, room r2)
{
	return r1.num > r2.num;
}

int n, m;
int room_num[52];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 52; i++) room_num[i] = -1;

	cin >> n;
	int p;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		vec.push_back({ i, p });
	}
	cin >> m;
	
	info = vec;
	sort(vec.begin(), vec.end(), cmp);
	vec2 = vec;
	sort(vec2.begin(), vec2.end(), cmp2);

	// ����
	// ���� 0�� �ִ� �� �ƴ϶��
	// 0���� �����ϸ� �� �ȴ�
	int pos_n = m / vec[0].price; // �ڸ���

	// ���� : 0�� ���� ��� => ������ 0
	if (n == 1 && vec[0].num == 0)
	{
		cout << 0;
		return 0;
	}

	// ù��° ���� 0 �ƴϾ�� ��
	if (pos_n > 1 && vec[0].num == 0)
	{
		room_num[0] = vec[1].num;
		if (m - vec[1].price < 0) // ���� 0 �ƴ� �� ù������ �� �Ǹ� -> ������ �׳� 0
		{
			cout << 0;
			return 0;
		}
		else
		{
			m -= vec[1].price;
			pos_n = 1;
			while (m > 0)
			{
				if (m - vec[0].price < 0) break;
				room_num[pos_n] = 0;
				m -= vec[0].price;
				pos_n++;
			}
		}
	}
	else
	{
		for (int i = 0; i < pos_n; i++)
		{
			room_num[i] = vec[0].num;
			m -= vec[0].price;
		}
	}

	// �ٲٱ�
	for (int i = 0; i < pos_n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (vec2[j].num == room_num[i]) break; // ������ �� �������� ������ �� ����
			if (m >= (vec2[j].price - info[room_num[i]].price))
			{
				m -= (vec2[j].price - info[room_num[i]].price);
				room_num[i] = vec2[j].num;
				break;
			}
		}
	}

	for (int i = 0; i < pos_n; i++) cout << room_num[i];

	return 0;
}