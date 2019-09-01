/*
#include <string>
#include<unordered_map>
#include <vector>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	unordered_map< string, string >store;
	string split[100000][3] = { "" ,};

	
	for (int i = 0; i < record.size(); i++) {
		int inx = 0;
		int col_inx = 0;

		while (col_inx<3) {
			while (inx< record.at(i).size()&& record.at(i).at(inx) != ' ') {

				split[i][col_inx] += record.at(i).at(inx);
				inx++;
				if (inx >= record.at(i).size())break;
			}
			inx++;
			col_inx++;
		}
	}
	for (int i = 0; i < record.size(); i++) {
		if (split[i][0] == "Enter" || split[i][0] == "Change") {
			bool flag = false;
			unordered_map< string, string > ::iterator  iter;
			if (store.find(split[i][1]) != store.end()) {
				flag = true;
				iter = store.find(split[i][1]);
			}

			if (flag == true)
				iter->second = split[i][2];
			else
				store.insert(make_pair(  split[i][1], split[i][2]));
		
		}

	}

	for (int i = 0; i < record.size(); i++) {
		unordered_map< string, string > ::iterator  iter;
		if (split[i][0] == "Enter") {
			iter = store.find(split[i][1]);
			string nick = iter->second;
			nick = nick + "님이 들어왔습니다.";
			answer.push_back(nick);
		}
		else if (split[i][0] == "Leave") {
			iter = store.find(split[i][1]);
			string nick = iter->second;
			nick = nick + "님이 나갔습니다.";
			answer.push_back(nick);
		}
	}
	return answer;
}

int main() {
	vector<string>record;
	record.push_back("Enter uid12345 Muzi");
	record.push_back("Leave uid12345");

	//메인 함수는 test 용
	
	return 0;
}
*/