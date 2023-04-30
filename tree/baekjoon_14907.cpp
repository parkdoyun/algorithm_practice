#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 백준 14907 - 프로젝트 스케줄링
// tree
// 골드 2

// 부모가 여러개 -> 부모들이 전부 완료될 때까지 하지 못 한다
// 부모들의 최댓값에서 더해야 함
// 정점 최대 26개 (A : 0 ~ Z : 25)
// 자식 여러명, 부모 여러명 => 트리 구조 2차원 배열

// **예외 : 루트가 여럿일 수 있음**

#define INF 999999999

int root[26]; // 1이면 부모 X, 루트
int vertex_time[26];
int total_time[26]; // 소요된 시간
vector<vector<int>> parent; // 부모 관계
vector<vector<int>> child; // 자식 관계

// 만약 다른 부모가 INF (일단 나오기)
// 만약 모든 부모가 INF 아니라면 그 중 최대로 설정
// 자식들로 타고 들어가기
void recursion(int now)
{
	if (total_time[now] != INF) return; // 이미 정한 곳 pass

	if (root[now] == 1) total_time[now] = vertex_time[now];
	else
	{
		int max1 = -1;
		for (int i = 0; i < parent[now].size(); i++)
		{
			if (total_time[parent[now][i]] == INF) return; // 하나라도 아직 방문 안 됐다면
			if (max1 < total_time[parent[now][i]]) max1 = total_time[parent[now][i]];
		}
		total_time[now] = max1 + vertex_time[now];
	}

	// 자식으로 들어가기
	for (int i = 0; i < child[now].size(); i++)
	{
		recursion(child[now][i]);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	for (int i = 0; i < 26; i++)
	{
		vertex_time[i] = -1;
		total_time[i] = INF;
	}

	int idx, vertex, tmp_time;
	string s, tmp;
	parent.resize(26);
	child.resize(26);

	// 입력
	while (!cin.eof())
	{
		getline(cin, s);
		if (cin.eof()) break; // eof 입력 받으면

		vertex = (int)(s[0] - 'A');

		idx = 2;

		tmp = ""; // 자연수
		for (; idx < s.length(); idx++)
		{
			if (s[idx] == ' ' || (s[idx] >= 'A' && s[idx] <= 'Z')) break;
			tmp += s[idx];
		}
		tmp_time = stoi(tmp);
		vertex_time[vertex] = tmp_time; // 해당 정점에서만 걸리는 시간

		idx++;
		tmp = "";
		for (; idx < s.length(); idx++)
		{
			if (s[idx] == ' ') break;
			tmp += s[idx];
		}

		if (tmp.empty()) root[vertex] = 1; // 부모 없으면 루트
		else // 표시하기
		{
			for (int i = 0; i < tmp.length(); i++)
			{
				idx = (int)(tmp[i] - 'A');
				parent[vertex].push_back(idx);
				child[idx].push_back(vertex);
			}
		}
	}

	// 최솟값 구하기
	// 루트부터 타고타고
	for (int i = 0; i < 26; i++)
	{
		if (root[i] == 0) continue;
		recursion(i);
	}

	int max1 = -1;
	for (int i = 0; i < 26; i++)
	{
		if (vertex_time[i] == -1) continue;
		if (total_time[i] > max1) max1 = total_time[i];
	}

	cout << max1;

	return 0;
}