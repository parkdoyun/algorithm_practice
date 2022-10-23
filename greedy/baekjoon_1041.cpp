#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ���� 1041 - �ֻ���
// greedy
// ��� 5

// �𼭸��� ���
// �������� ���� �ּҰ�����
// ���� �� �����̴� 3�� => ¦��� �ؾߵ�
// (A, F), (B, E), (C, D) ¦
// �ּ� 3���� �ּ� 2�� ���ϱ�
// �ؿ� �� �����̴� 2��
// ������ �𼭸��� 2��
// ������ �ּ� ��鸸 ����

bool cmp(int a, int b)
{
	if (a < b) return true;
	return false;
}

int dice[7];
vector<int> min_dice;


int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < 6; i++)
	{
		cin >> dice[i]; 
	}
	
	min_dice.push_back(min(dice[0], dice[5]));
	min_dice.push_back(min(dice[1], dice[4]));
	min_dice.push_back(min(dice[2], dice[3]));
	
	sort(min_dice.begin(), min_dice.end(), cmp);

	unsigned long long res = 0;
	
	int three = 0;
	for (int i = 0; i < 3; i++) three += min_dice[i];

	int two = three - min_dice[2];

	// �� �� ������
	res += (unsigned long long)(three * 4);
	
	// �Ʒ� �� ������
	res += (unsigned long long)(two * 4);

	// �𼭸��� : ���� n-2, 4��
	res += (unsigned long long)((n - 2) * two * 8);

	// �� �� �𼭸��� : 4��, ���� n-2
	res += (unsigned long long)((n - 2) * min_dice[0] * 4);

	// ������
	unsigned long long a = (unsigned long long)((unsigned long long)(n - 2) * (unsigned long long)(n - 2));
	a = (unsigned long long)(a * min_dice[0]);
	a = (unsigned long long)(a * 5);

	res += a;

	// �ֻ��� ũ�� 1�� �� ���� ó��
	if (n == 1)
	{
		int max = dice[0];
		res = 0;
		for (int i = 0; i < 6; i++)
		{
			res += dice[i];
			if (dice[i] > max) max = dice[i];
		}
		res -= max;
	}
	cout << res;

	return 0;
}