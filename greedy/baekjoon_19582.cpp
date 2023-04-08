#include <iostream>

using namespace std;

// ���� 19582 - 200�Ⱓ ��������ߴ��� PS �ְ��ڰ� �� �ǿ� ���Ͽ�
// greedy, ���� ��
// ��� 3

// ���±��� �� > ��� ���� �� => ���� �� �Ѵ� (���²� �� �� �ִ� ���� ���)
// 1. �̹� ��ȸ �ϳ� ���µ� �� ���� ��� -> Zzz
// 2-1. �E ��ȸ ���� ��� -> Kkeo-eok
// 2-2. �ϳ��� ���� ����� ��� -> Kkeo-eok

// 3. �ش� ��ȸ�� ���� ����� ���� ���� (�� �� ��ȸ�� �����ϴ� �� �ƴ϶�)

int n;
int price[100001]; // ���
int cond[100001];
long long int sumArr[100001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	int x, p;
	for (int i = 1; i <= n; i++)
	{
		cin >> x >> p;
		cond[i] = x;
		price[i] = p;
		sumArr[i] = sumArr[i - 1] + (long long int)p;
	}

	int except = 0; // �� ��� (���� ��ȸ ��� �� �ִ�)
	int flag = 0;
	int max1 = price[1];
	int now; // ���� ��� (���� ��� �� �Ҷ� ��ȸ�� ���)
	for (int i = 1; i <= n; i++)
	{
		if (cond[i] < sumArr[i - 1] - except) // �ʰ��� ���
		{
			if (except == 0) // ó���� ���
			{
				// ���µ��� �� ���� Zzz
				except = max1;
				now = price[i];
				if (i == n) break;
				if (cond[i] < sumArr[i - 1] - except) // ���� ���� ���� �� ���� ��� �� �ϸ�, ���� ����� ����
				{
					except = price[i];
				}
			}
			else
			{
				if (cond[i] < sumArr[i - 1] - now) // ���� ����� �Q�� ���� �� �ȴٸ�
				{
					flag = 1; 
					break;
				}
				except = now;
			}
		}
		if (max1 < price[i]) max1 = price[i];
	}

	if (flag == 1) cout << "Zzz";
	else cout << "Kkeo-eok";	

	return 0;
}