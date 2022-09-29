#include <iostream>
#include <map>
using namespace std;

// ���� 10816 - ���� ī�� 2

map<int, int> card;

int arr_plus[10000001] = { 0 }; // 0����
int arr_minus[10000000] = { 0 }; // -1����

int main()
{
	/*
	// �� - �ð� �ʰ�
	// ����� �ð� �ٿ��ִϱ� ���

	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a;
	
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (card.find(a) == card.end()) // �� ã�Ҵٸ� ����
		{

			card.insert({ a, 1 });
		}
		else
		{
			card[a]++; // ī�� �ϳ� �� �߰�
		}
	}

	cin >> m;
	for (int j = 0; j < m; j++)
	{
		// ī�� ã�� ������ 0 ���
		cin >> a;
		if (card.find(a) == card.end()) // ������ 0 ���
		{
			cout << 0 << ' ';
		}
		else cout << card[a] << ' ';
		
	}
	*/

	// �迭 -> �ð��ʰ�
	// ����� �ð� �ٿ��ִϱ� ���
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, m, a;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		if (a >= 0)
		{
			arr_plus[a]++;
		}
		else
		{
			arr_minus[a * -1]++;
		}
	}

	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> a;
		if (a >= 0)
		{
			cout << arr_plus[a] << ' ';
		}
		else
		{
			cout << arr_minus[a * -1] << ' ';
		}
	}

	return 0;
}