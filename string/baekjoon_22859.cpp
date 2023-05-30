#include <iostream>
#include <string>

using namespace std;

// 백준 22859 - HTML 파싱
// string
// 골드 3

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string doc, tmp, title_s;
	getline(cin ,doc);
	string par_s = ""; // 문단 내용

	int doc_len = doc.length();

	int idx = 0;

	while (idx < doc_len)
	{
		while (doc[idx] != '<') idx++;
		if (idx >= doc_len) break;

		// tag 안 내용 찾기
		idx++;
		tmp = "";
		while (doc[idx] != '>')
		{
			tmp += doc[idx];
			idx++;
		}
		idx++;

		if (tmp == "main")
		{
			;
		}
		else if (tmp == "/main") break; // 끝
		else if (tmp.substr(0, 4) == "div ") // div
		{
			cout << "title : ";
			// 제목 파싱
			int tmp_idx = 0;
			while (tmp[tmp_idx] != '"') tmp_idx++;
			tmp_idx++;
			title_s = "";

			// 처음 공백 제거
			while (tmp_idx < tmp.length() && tmp[tmp_idx] == ' ') tmp_idx++;

			while (tmp_idx < tmp.length() && tmp[tmp_idx] != '"')
			{
				title_s += tmp[tmp_idx];
				tmp_idx++;
			}

			// 끝 공백 제거
			while (!title_s.empty() && title_s.back() == ' ') title_s.pop_back();

			// 중간 공백 제거
			if (!title_s.empty())
			{
				for (int i = 0; i < title_s.length() - 1; i++)
				{
					if (title_s[i] == ' ' && title_s[i + 1] == ' ')
					{
						title_s.erase(i, 1);
						i--;
						if (i < 0) break;
					}
				}
			}
			cout << title_s << '\n';
		}
		else if (tmp == "p") // 문단 시작
		{
			while (idx < doc_len && doc[idx] != '<')
			{
				par_s += doc[idx];
				idx++;
			}
		}
		else if (tmp == "/p") // 문단 끝
		{
			// 공백 제거
			// 처음 공백 제거
			while (!par_s.empty() && par_s[0] == ' ') par_s.erase(0, 1);

			// 끝 공백 제거
			while (!par_s.empty() && par_s.back() == ' ') par_s.pop_back();

			// 중간 공백 제거
			if (!par_s.empty())
			{
				for (int i = 0; i < par_s.length() - 1; i++)
				{
					if (par_s[i] == ' ' && par_s[i + 1] == ' ')
					{
						par_s.erase(i, 1);
						i--;
						if (i < 0) break;
					}
				}
			}

			cout << par_s << '\n';
			par_s = "";
		}
		else // 문장 포함
		{
			while (idx < doc_len && doc[idx] != '<')
			{
				par_s += doc[idx];
				idx++;
			}
		}
	}

	return 0;
}