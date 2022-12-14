#include <iostream>
#include <vector>

using namespace std;

// softeer - 교차로
// failed

// 시간 초과, 정답은 맞는 듯

// 이렇게 하지 말고
// 어차피 일렬로 이어져 있는 애들은 오른쪽에 차 생기기 전까지 계속 나감
// 오른쪽에 가장 가까운 차나 아니면 계속 이어진 애들 끊길 때까지 계속 나가게 하자

// 시간초과 안 나고 오답 발생

int n;
char w;
long long int t;
struct car
{
	int idx;
	long long int time;
};
vector<vector<car>> vec;
long long int arr[200001];

// 어차피 일렬로 이어져 있는 애들은 오른쪽에 차 생기기 전까지 계속 나감
// 오른쪽에 가장 가까운 차나 아니면 계속 이어진 애들 끊길 때까지 계속 나가게 하자
void cal2()
{
	int v_size[4] = { vec[0].size(), vec[1].size(), vec[2].size(), vec[3].size() };
	int idx[4] = { 0, 0, 0, 0 };
	long long int tmp_time;

	while (true)
	{
		if (idx[0] >= v_size[0] && idx[1] >= v_size[1] && idx[2] >= v_size[2] && idx[3] >= v_size[3]) break;
		if (idx[0] < v_size[0] && idx[1] < v_size[1] && idx[2] < v_size[2] && idx[3] < v_size[3] &&
			vec[0][idx[0]].time == vec[1][idx[1]].time && vec[0][idx[0]].time == vec[2][idx[2]].time && 
			vec[0][idx[0]].time == vec[3][idx[3]].time)
		{
			// 교착상태
			break;
		}

		// A
		if (idx[0] < v_size[0] && (idx[3] >= v_size[3] || vec[3][idx[3]].time > vec[0][idx[0]].time))
		{
			tmp_time = vec[0][idx[0]].time;
			//chk[0] = idx[0];
			while (true)
			{
				if (v_size[0] <= idx[0] || (v_size[3] > idx[3] && vec[3][idx[3]].time == tmp_time) || vec[0][idx[0]].time > tmp_time)
				{
					if (v_size[0] > idx[0] && vec[0][idx[0]].time < tmp_time) vec[0][idx[0]].time = tmp_time;
					if (idx[1] < v_size[1] && vec[1][idx[1]].time < tmp_time) vec[1][idx[1]].time = tmp_time;
					break;
				}
				vec[0][idx[0]].time = tmp_time;

				arr[vec[0][idx[0]].idx] = tmp_time;
				idx[0]++;
				tmp_time = (long long int)(tmp_time + 1);
			}
		}

		if (idx[0] < v_size[0] && idx[1] < v_size[1] && idx[2] < v_size[2] && idx[3] < v_size[3] &&
			vec[0][idx[0]].time == vec[1][idx[1]].time && vec[0][idx[0]].time == vec[2][idx[2]].time &&
			vec[0][idx[0]].time == vec[3][idx[3]].time)
		{
			// 교착상태
			break;
		}

		// B, C
		for (int i = 1; i <= 2; i++)
		{
			if (idx[i] < v_size[i] && (idx[i-1] >= v_size[i-1] || vec[i-1][idx[i-1]].time > vec[i][idx[i]].time))
			{
				tmp_time = vec[i][idx[i]].time;
				//chk[0] = idx[0];
				while (true)
				{
					if (v_size[i] <= idx[i] || (v_size[i - 1] > idx[i - 1] && vec[i - 1][idx[i - 1]].time == tmp_time) || vec[i][idx[i]].time > tmp_time)
					{
						if (v_size[i] > idx[i] && vec[i][idx[i]].time < tmp_time) vec[i][idx[i]].time = tmp_time;
						if (idx[i + 1] < v_size[i + 1] && vec[i + 1][idx[i + 1]].time < tmp_time) vec[i + 1][idx[i + 1]].time = tmp_time;
						break;
					}
					vec[i][idx[i]].time = tmp_time;
					arr[vec[i][idx[i]].idx] = tmp_time;
					idx[i]++;
					tmp_time = (long long int)(tmp_time + 1);
				}
			}
		}

		if (idx[0] < v_size[0] && idx[1] < v_size[1] && idx[2] < v_size[2] && idx[3] < v_size[3] &&
			vec[0][idx[0]].time == vec[1][idx[1]].time && vec[0][idx[0]].time == vec[2][idx[2]].time &&
			vec[0][idx[0]].time == vec[3][idx[3]].time)
		{
			// 교착상태
			break;
		}

		// D
		if (idx[3] < v_size[3] && (idx[2] >= v_size[2] || vec[2][idx[2]].time > vec[3][idx[3]].time))
		{
			tmp_time = vec[3][idx[3]].time;
			//chk[0] = idx[0];
			while (true)
			{
				if (v_size[3] <= idx[3] || (v_size[2] > idx[2] && vec[2][idx[2]].time == tmp_time) || vec[3][idx[3]].time > tmp_time)
				{
					if (v_size[3] > idx[3] && vec[3][idx[3]].time < tmp_time) vec[3][idx[3]].time = tmp_time;
					if (idx[0] < v_size[0] && vec[0][idx[0]].time < tmp_time) vec[0][idx[0]].time = tmp_time;
					break;
				}

				vec[3][idx[3]].time = tmp_time;
				arr[vec[3][idx[3]].idx] = tmp_time;
				idx[3]++;
				tmp_time = (long long int)(tmp_time + 1);
			}
		}

	}
}

int main(int argc, char** argv)
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vec.resize(4); // 0 : A, 1 : B, 2 : C, 3 : D

	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		cin >> t >> w;
		vec[(int)(w - 'A')].push_back({ i, t });
		arr[i] = -1;
	}

	// 교차로 계산
	// 현재 시간 얼마인지 계산하며 4개에서 한개씩 빼자
	cal2();

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << '\n';
	}

	return 0;
}