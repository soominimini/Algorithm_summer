/*
#include<stdio.h>
#include<deque>
#include<algorithm>
#include<iostream>
#include<string>
#include<set>
using namespace std;
char arr[30];
int n, k;


int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}//처음 arr에 글자 넣어놓고
		deque<char>dq;
		set<string>password;
		set<string>init;
		string init_string = "";
		int div = n / 4;
		for (int i = 0; i < n; i+= div) {
			for (int j = i; j < i + div; j++) {
				init_string += arr[j];
			}
			init.insert(init_string);
			password.insert(init_string);
			init_string = "";
		}

		while (true) {
			set<string>tmp;
			for (int i = 0; i < n; i++) {
				dq.push_back(arr[i]);
			}//디큐에 넣어놓는 과정
			//디큐를 조작
			dq.push_front( dq.back());
			dq.pop_back();
			int inx = 0;
			bool flag = false;
			while (!dq.empty()) {
				string pass = "";
				for (int i = 0; i < div; i++) {
					if (dq.empty())break;
					char node = dq.front(); dq.pop_front();
					arr[inx++] = node;
					pass += node;

				}//하나의 비밀번호 완성
				if (pass.length() == div) {
					tmp.insert(pass);
					password.insert(pass);
				}
			}
			if (tmp == init) {
				//초기에 만들었던 비밀번호랑 같게 나올 경우
				break;
			}

		}
		long long int ret_arr[10000];
		int ret_inx = 0;
		set<string> ::iterator iter;
		for (iter = password.begin(); iter != password.end();) {
			string iter_at = *iter;
			long long int ret = 0;
			for (int i = 0; i < iter_at.length(); i++) {
				long long int tmp;
				long long int pow_Ret = pow(16, iter_at.length() - 1 - i);
				if(iter_at.at(i)>=65) tmp = pow_Ret * (iter_at.at(i)-55);
				else tmp = pow_Ret * (iter_at.at(i)-'0');
				ret += tmp;

			}
			ret_arr[ret_inx++] = ret;
			ret = 0;
			iter++;
		}
		sort(ret_arr, ret_arr + ret_inx, greater<int>());

		printf("#%d %lld\n", i + 1, ret_arr[k-1]);
		ret_inx = 0;
	}
	return 0;
}

*/