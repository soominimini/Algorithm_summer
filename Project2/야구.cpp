#include<stdio.h>
#include<algorithm>
using namespace std;

int numbering[9] = { 0,0,0,1,0,0,0,0,0 };
bool visited[10] = { false,true,false,false,false,false,false,false,false , false};
int input[51][9];
int n;
int max_socre = 0;

int func() {
	int cur_ining = 0;
	int init_person = 0;
	int total_score = 0;
	int out_cnt = 0;

	int ground_people[9] = {0,};
	//이닝이 바뀌었을 때만 원점으로

	while (cur_ining < n) {
		bool out_flag = false;
		//bool visited[] 혹시 마운드에 나가 있는 선수 있는지 표시
		for (int i = init_person; i < 9; i++) {
			int person_number = numbering[i];
			int score = input[cur_ining][person_number - 1];

			if (score == 0)out_cnt++;
			else if (score == 1 || score==2 || score==3 ||score==4) {
				for (int j = 0; j < 9; j++) {
					if (ground_people[j] != 0) ground_people[j] += score;
				}
				ground_people[person_number - 1] += score;
			}
			//스코어 찾아내고 카운팅까지 끝냄
			if (out_cnt == 3) {
				if (i == 8) {
					init_person = 0;
				}//다음 이닝에서 어떤 선수 부터 시작할지 기억
				else init_person = i + 1; 
				out_flag = true;
				break;
			}
			else {
				for (int j = 0; j < 9; j++) {
					if (ground_people[j] >= 4) {
						total_score++;
						ground_people[j] = 0;
					}
				}
			}


		}
		if (out_flag == true) {
			//이닝이 바뀌는 경우
			//3아웃 끝났으니까 out원점?
			out_cnt = 0;
			cur_ining++;
			for (int i = 0; i < 9; i++) {
				ground_people[i] = 0;
			}
		}
		else {
			init_person = 0;
			continue;
		}
	}
	return total_score;
}

void permu(int cnt) {
	if (cnt == 3) permu(cnt + 1);
	else if (cnt == 9) {
	//	for (int i = 0; i < 9; i++) {
	//	printf("%d ", numbering[i]);

//	}
//	printf("\n");
		//순열 하나 뽑아 낸 후에는 
		int tmp_score = func();
	//	printf("---------------socre : %d-------------\n" , tmp_score);
		max_socre = max(max_socre, tmp_score);
		return;
	}
	else {
		for (int i = 1; i < 10; i++) {
			if (visited[i] == true) continue;
			numbering[cnt] = i;
			visited[i] = true;
			permu(cnt + 1);
			visited[i] = false;
		}
	}
	return;
}
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++)
			scanf("%d", &input[i][j]);
	}
	permu(0);
	printf("%d\n", max_socre);
	return 0;
}