#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

struct INFO {
	int number, fail_ratio;
};

bool comp(const INFO &a,const INFO &b ) {
	if (a.fail_ratio > b.fail_ratio)return true;
	else if (a.fail_ratio == b.fail_ratio) {
		if (a.number < b.number)return true;
		return false;
	}
	else return false;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	int len = stages.size();
	sort(stages.begin(), stages.end());
	

	INFO arr[200001];//실패율과 각 실패율의 스테이지 번호 저장
	int inx = 0;
	for (int i = 0; i < len; i++) {
		int stand = stages.at(i);
		//현재 기준 번호
		int child=1, parent=1;
		for (int j = i; j < len; j++) {
			if (stand == stages.at(j)) {
				child++;
			}
			else {
				parent++;
			}
		}
		parent += child;
		//분자가 0이 아닌 경우에만 계산 가능
		arr[inx].fail_ratio = child / parent;
		arr[inx++].number = stand;
	}
	sort(arr, arr + inx, comp);

	return answer;
}

int main() {
	vector<int>stages = { 2, 1, 2, 6, 2, 4, 3, 3 };

	solution(5, stages);
	return 0;
}