#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// 백준 1050 - 물약
// 문자열 파싱
// 골드 1

// 계산해보고 값 나오고 최소이면 map 갱신 or 값이 처음 들어가면 map 갱신
// map 갱신되는 것 없으면 while loop 나오기
// 식은 변형하지 말고 계속 계산 -> map에 필요한 값 없으면 pass

int n, m;

map<string, long long> map_list; // 재료
vector<string> exp_vec; // 수식

int main()
{
	cin >> n >> m;
	string str;
	int a;

	// 재료 입력
	for (int i = 0; i < n; i++)
	{
		cin >> str >> a;
		map_list.insert({ str, a });
	}

	// 식 입력
	for (int i = 0; i < m; i++)
	{
		cin >> str;
		exp_vec.push_back(str);
	}

	// 식 계산 while 도는데 -> 바뀐 게 없다면 -> change_cnt = -1
	int change_cnt = -1;
	while (true)
	{
		change_cnt = -1;
		for (int i = 0; i < m; i++)
		{
			int tmp_idx = 0;
			string name = ""; // 식 주인공 누군지
			while (exp_vec[i][tmp_idx] != '=')
			{
				name += exp_vec[i][tmp_idx];
				tmp_idx++;
			}
			tmp_idx++;

			// 식 계산
			int tmp_alpha = tmp_idx;
			long long sum = 0;
			int cal_chk = -1; // 식이 계산 가능한지

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
				// 만약 muls_1이랑 muls_2가 map에 둘다 없다면 -> 식 계산 X
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
			{ // 아직 맵에 없음 -> insert
				change_cnt = 1;
				map_list.insert({ name, sum });
			}
			else if (cal_chk == -1 && map_list[name] > sum)
			{ // 최소값으로 갱신
				change_cnt = 1;
				map_list[name] = sum;
			}
			
		}

		if (change_cnt == -1) break;
	}


	// map에서 LOVE 찾고 없으면 -1 아니면 값 출력
	if (map_list.find("LOVE") == map_list.end()) cout << -1;
	else if (map_list["LOVE"] > 1000000000) cout << 1000000001;
	else cout << map_list["LOVE"];

	return 0;
}