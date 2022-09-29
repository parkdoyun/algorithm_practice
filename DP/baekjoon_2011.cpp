#include <iostream>
#include <string>

using namespace std;

// ���� 2011 - ��ȣ�ڵ�
// DP
// ��� 5

// 251 => 2511
// 11�� ������ ��
// 2511 ������ = 251�� ���� ������ + (251 ������ �� ������ 1 ȥ�� �ִ� ������)
// 101, 201ó�� �߰��� 0 �ִ� �ֵ� ó���ؾ� �� 

// 1301 => �̷� �ֵ� 13 01 �̷��� ��� �� �ϴ��� Ȯ�� => 05, 06 �̷� �� ��� X


long long DP[5001];

// �� ���� ȥ���� �ֵ� ���� => ��׸� ���� DP ������ ������� ��
long long arr[5001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// �Է� ���� ��
	if (cin.eof())
	{
		cout << 0;
		return 0;
	}

	string pw;
	cin >> pw;

	// ���� ����
	DP[0] = 1;
	arr[0] = 1;
	
	// �߸��� ��ȣ
	if (pw[0] == '0')
	{
		cout << 0;
		return 0;
	}

	string tmp;
	for (int i = 1; i < pw.size(); i++)
	{
		tmp = pw.substr(i - 1, 2);
		if (tmp == "00") // �߸��� ��ȣ (00)
		{
			cout << 0;
			return 0;
		}

		if (pw[i] == '0')
		{
			if (tmp < "30")
			{
				if (i == pw.size() - 1) // ���� �� �ִ� �ֵ鸸 ����
				{
					DP[i] = arr[i - 1];
					arr[i] = 0;
				}
				else
				{
					DP[i] = arr[i - 1];
					arr[i] = DP[i - 1];
				}
			}
			else if(i == pw.size()-1) // �������� ���� X (130) => �߸��� ��ȣ
			{
				cout << 0;
				return 0;
			}
			else // �� �� ����
			{
				/*
				DP[i] = DP[i - 1];
				arr[i] = DP[i - 1];
				*/
				cout << 0;
				return 0;
			}
			continue;
		}
		else if (pw[i - 1] == '0')
		{
			DP[i] = DP[i - 1];
			arr[i] = DP[i - 1];
			continue;
		}
		
		if (tmp < "27" && tmp >= "01") // ���� 27���� ������ => stoi() ������ ������ ������ �ϴ� �� ã��
		{
			DP[i] = (DP[i - 1] + arr[i - 1]) % 1000000;
			// �� ȥ���� �ֵ� üũ => �굵 ������ ����

			// arr[i-1]�� �� Ŀ���� ���� �ִ�
			// arr[i] = (DP[i] - arr[i - 1]) % 1000000; // �̷��� ���� DP[i]�� ���� ������ ������ �� �Ķ� arr[i-1]���� �۾����� �Ǿ� ������ ���� �� �ִ� => ����
			arr[i] = (DP[i - 1] + arr[i-1] - arr[i - 1]) % 1000000; // ����
		}
		else // tmp >= "27" && tmp <= "99"
		{
			DP[i] = DP[i - 1];
			arr[i] = DP[i - 1]; // ���� �ϳ��� ����
		}
		//cout << DP[i] << ' ' << arr[i] <<  endl;
	}

	cout << DP[pw.size() - 1] % 1000000;


	return 0;
}