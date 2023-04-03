#include <iostream>

using namespace std;

// ���� 19644 - ���� ���� ����� �������� ���ٴ�
// greedy
// ��� 4

// �ð� �ʰ�

// ��Ÿ� => �ش� ���̸�ŭ mk�� �� �� �ִٴ� ����
// �ѹ��� ���鼭 mk * ml���� ū �ֵ� ������ bomb_n���� ũ�� NO
// ��ź ������ �ش� ��Ÿ����� �پ�� ��

int L, ml, mk, bomb_n;
int road[3000001];
int chk[3000001]; // ���� �󸶳� ���� ���������� ī��Ʈ, 1�̸� �ö󰡰� -1�̸� ������, 0�̸� �״��

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> L >> ml >> mk;
	cin >> bomb_n;

	int now_n = 1; // ���� ����ؼ� �� �� �ִ���
	int cnt = 0; // ��ź �ּ� ��� ����
	int flag = 0;
	for (int i = 1; i <= L; i++)
	{
		cin >> road[i];
		if (road[i] > mk * now_n)
		{
			cnt++;
			chk[i]--; // ������ ��������
			if (i + ml <= L) chk[i + ml]++; // �ö󰣴�
		}
		if (i < ml)
		{
			now_n++;
		}
		now_n += chk[i];
		if (now_n < 0) flag = -1; // ��� �Ұ���
		if (ml == 1) // ���� : ml 1�� �� ��ź �׻� �ᵵ ������ ����� ����
		{
			now_n = 1;
		}
	}

	if (cnt > bomb_n || flag == -1) cout << "NO";
	else cout << "YES";	

	return 0;
}