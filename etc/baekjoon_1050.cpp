#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// ���� 1050 - ����
// ���ڿ� �Ľ�
// ��� 1

// ����غ��� �� ������ �ּ��̸� map ���� or ���� ó�� ���� map ����
// map ���ŵǴ� �� ������ while loop ������
// ���� �������� ���� ��� ��� -> map�� �ʿ��� �� ������ pass

int n, m;

map<string, long long> map_list; // ���
vector<string> exp_vec; // ����

int main()
{
	cin >> n >> m;
	string str;
	int a;

	// ��� �Է�
	for (int i = 0; i < n; i++)
	{
		cin >> str >> a;
		map_list.insert({ str, a });
	}

	// �� �Է�
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		exp_vec.push_back(str);
	}

	// �� ��� while ���µ� -> �ٲ� �� ���ٸ� -> change_cnt = -1
	int change_cnt = -1;
	while (true)
	{
		change_cnt = -1;
		for (int i = 0; i < m; i++)
		{
			int tmp_idx = 0;
			string name = ""; // �� ���ΰ� ������
			while (exp_vec[i][tmp_idx] != '=')
			{
				name += exp_vec[i][tmp_idx];
				tmp_idx++;
			}
			tmp_idx++;

			// �� ���
			int tmp_alpha = tmp_idx;
			long long sum = 0;
			int cal_chk = -1; // ���� ��� ��������

			string muls_1 = "";
			string muls_2 = "";
			while (tmp_alpha < exp_vec[i].size())
			{
				muls_1 = "";
				muls_2 = "";
				while (exp_vec[i][tmp_alpha] >= '0' && exp_vec[i][tmp_alpha] <= '9')
				{
					muls_1 += exp_vec[i][tmp_alpha];
					tmp_alpha++;
				}
				//cout << muls_1 << endl;
				//tmp_alpha++;
				while (exp_vec[i][tmp_alpha] != '+' && tmp_alpha < exp_vec[i].size())
				{
					muls_2 += exp_vec[i][tmp_alpha];
					tmp_alpha++;
				}
				//cout << muls_2 << endl;
				// ���� muls_1�̶� muls_2�� map�� �Ѵ� ���ٸ� -> �� ��� X
				if (map_list.find(muls_2) == map_list.end())
				{
					cal_chk = 1;
					break;
				}

				long long m1 = stoll(muls_1);
				long long m2 = map_list[muls_2];

				if (m1 > 1000000001 || m2 > 1000000001) sum = 1000000001;
				else sum += m1 * m2;

				//cout << sum << endl;
				tmp_alpha++;
			}
			if (cal_chk == -1 && map_list.find(name) == map_list.end())
			{ // ���� �ʿ� ���� -> insert
				change_cnt = 1;
				map_list.insert({ name, sum });
			}
			else if (cal_chk == -1 && map_list[name] > sum)
			{ // �ּҰ����� ����
				change_cnt = 1;
				map_list[name] = sum;
			}
			
		}

		if (change_cnt == -1) break;
	}


	// map���� LOVE ã�� ������ -1 �ƴϸ� �� ���
	if (map_list.find("LOVE") == map_list.end()) cout << -1;
	else if (map_list["LOVE"] > 1000000000) cout << 1000000001;
	else cout << map_list["LOVE"];

	return 0;
}