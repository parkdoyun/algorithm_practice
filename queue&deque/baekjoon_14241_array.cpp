#include <iostream>

using namespace std;

// ���� 14241�� - ������ ��ġ��
// �迭 �̿�

int main()
{
	int n;
	cin >> n;
	int arr[101]{ 0 };
	int tmp;
	
	for (int i = 0; i < n; i++)
	{
		cin >> tmp;
		arr[tmp]++;
	}

	// ���� ��� -> ���� ���� �����Ӻ��� ���
	int slime_count = 0; // ��� ������ ���´���
	int score = 0; // ����
	int slime_size = 0; // ��ģ ������ ũ��
	for (int i = 1; i <= 100; i++)
	{
		while (arr[i] != 0)
		{
			if (slime_count == 0) slime_size = i;
			else
			{
				score += slime_size * i;
				slime_size += i;
			}
			arr[i]--;
			slime_count++;
		}		
	}
	cout << score << endl; // ���� ���
	return 0;
}