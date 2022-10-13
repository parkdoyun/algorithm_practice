#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// swea 2477 - 차량 정비소
// brute-force, bfs

// 우선 순위
// 도착하는 대로 고객번호 부여
// 접수 창구
// 1. 여러 고객이 기다리는 경우 고객 번호가 낮은 순서로 -> (먼저 온 순서로)
// 2. 빈 창구가 여러 곳인 경우 창구번호가 낮은 곳부터 -> 낮은 곳부터 항상 확인
// 정비 창구
// 1. 먼저 기다리는 고객이 우선 -> pq
// 2. 이용했던 접수 창구번호가 작은 고객이 우선 -> pq
// 3. 정비 창구가 작은 곳부터 -> 작은 곳부터 항상 확인

// 접수 기록, 정비 기록, 고객 번호를 기록해야 함 => 나중에 확인
// pq 4개 -> 접수 대기, 정비 대기

// bfs (시간에 따라서 bfs)
// 현재 시간 기록 -> q
// 정비 창구에서 나올 때 확인(a,b)

int n, m, k, a, b;
int recep[10]; // 접수 창구
int repair[10]; // 정비 창구
int total;

struct cust1 // 접수 대기
{ // 고객번호 -> pq에서 빼면서 cnt 해야할 듯
	int arrive; // 도착시간
};

vector<cust1> wait_recep_vec;
struct cust_recep // 접수 중
{
	int use = -1; // 1 : 사용 중
	int num;
	int end_time; // 접수 끝나는 시간
};
vector<cust_recep> vec_recep;

struct cust2 // 정비 대기
{
	int num;
	int wait_time; // 언제부터 기다렸는지
	int recep;
};
bool operator<(cust2 c1, cust2 c2)
{
	if (c1.wait_time > c2.wait_time) return true;
	else if (c1.wait_time == c2.wait_time && c1.recep > c2.recep) return true;
	return false;
}
priority_queue<cust2> pq_repair;

struct cust_repair
{
	int use = -1;
	int num;
	int recep;
	int end_time; // 정비 끝나는 시간
};
vector<cust_repair> vec_repair;

void BFS()
{
	int cust_num = 1; // 접수 시 고객 번호 매기기
	int now_time = 0;
	int recep_cnt = 0; // 아직 접수 중인 애들 있는지
	while (!wait_recep_vec.empty() || !pq_repair.empty() || recep_cnt > 0)
	{
		//cout << endl << "now time : " << now_time << endl;
		// 접수 끝난 애들 빼기
		//cout << endl <<  "===reception finish===" << endl;
		for (int i = 1; i <= n; i++)
		{
			if (vec_recep[i].use == -1) continue;
			if (vec_recep[i].end_time <= now_time)
			{
				cust2 cust_new;
				cust_new.num = vec_recep[i].num;
				cust_new.recep = i;
				cust_new.wait_time = now_time;
				vec_recep[i].use = -1;
				pq_repair.push(cust_new);
				recep_cnt--;
				//cout << cust_new.num << " 접수 끝난 곳 => " << cust_new.recep << '\n';
			}
		}

		// 접수 대기 애들 빼기
		//cout << endl << "===reception waiting finish===" << endl;
		for (int i = 1; i <= n; i++)
		{
			if (wait_recep_vec.empty()) break;
			cust1 tmp_c1 = wait_recep_vec[0];
			if (vec_recep[i].use == -1 && now_time >= tmp_c1.arrive) // 비었음
			{
				wait_recep_vec.erase(wait_recep_vec.begin());
				vec_recep[i].use = 1;
				vec_recep[i].num = cust_num;
				cust_num++;
				vec_recep[i].end_time = now_time + recep[i];
				recep_cnt++;
				//cout << i << " 번에 접수한 고객 => " << vec_recep[i].num << '\n';
			}

		}
		

		// 정비 끝난 애들 빼기
		//cout << endl << "===repair finish===" << endl;
		for (int i = 1; i <= m; i++)
		{
			if (vec_repair[i].use == -1) continue;
			if (vec_repair[i].end_time <= now_time)
			{
				vec_repair[i].use = -1;
				//cout << vec_repair[i].num << " 고객 => recep : " << vec_repair[i].recep << " repair : " << i << '\n';
				if (vec_repair[i].recep == a && i == b)
				{
					total += vec_repair[i].num;
					//cout << "check " << vec_repair[i].num << ' ' << total << endl;
				}
			}
		}


		// 정비 대기 애들 빼기
		//cout << endl << "===repair waiting finish===" << endl;
		for (int i = 1; i <= m; i++)
		{
			if (pq_repair.empty()) break;
			if (vec_repair[i].use == -1) // 비었음
			{
				cust2 tmp_c1 = pq_repair.top();
				pq_repair.pop();
				vec_repair[i].use = 1;
				vec_repair[i].num = tmp_c1.num;
				vec_repair[i].end_time = now_time + repair[i];
				vec_repair[i].recep = tmp_c1.recep;
				//cout << vec_repair[i].num << " 고객 => recep : " << vec_repair[i].recep << " repair : " << i << '\n';
			}

		}

		now_time++;
	}

	// 정비 중인 애들 중 고객 창구 번호 겹치는 애들 카운트
	//cout << endl << "===repair finish===" << endl;
	for (int i = 1; i <= m; i++)
	{
		if (vec_repair[i].use == -1) continue;
		//cout << vec_repair[i].num << " 고객 => recep : " << vec_repair[i].recep << " repair : " << i << '\n';
		if (vec_repair[i].recep == a && i == b)
		{
			total += vec_repair[i].num;
			//cout << "check " << vec_repair[i].num << ' ' << total << endl;
		}
	}
}

int main()
{
	vec_recep.resize(10);
	vec_repair.resize(10);

	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++)
	{
		cin >> n >> m >> k >> a >> b;

		total = 0;
		for (int i = 1; i <= n; i++)
		{
			vec_recep[i].use = -1;
		}
		for (int i = 1; i <= m; i++)
		{
			vec_repair[i].use = -1;
		}

		while (!pq_repair.empty()) pq_repair.pop();
		wait_recep_vec.clear();

		for (int i = 1; i <= n; i++)
		{
			cin >> recep[i];
		}
		for (int i = 1; i <= m; i++) cin >> repair[i];
		int a1;
		for (int i = 1; i <= k; i++)
		{
			cin >> a1;
			wait_recep_vec.push_back({ a1 });
		}

		// 고객번호 1부터 부여
		BFS();

		if (total == 0) total = -1;
		cout << '#' << tc << ' ' << total << '\n';
	}

	return 0;
}