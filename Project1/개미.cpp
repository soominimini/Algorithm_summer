/*
#include<iostream>
#include<string>
using namespace std;

struct INFO {
	bool group;
	char val;

};
INFO arr[100000];
int lenA, lenB;
string a, b;

int operation_time;


void swap(int i, int j) {
	INFO inf;
	inf = arr[i];
	arr[i] = arr[j];
	arr[j] = inf;
	return;
}

int main() {
	cin >> lenA >> lenB;
	cin >> a >> b;
	cin >> operation_time;

	string tmp ="";
	for (int i = lenA - 1; i >= 0; i--) {
		tmp += a.at(i);
	}
	a = tmp;
	for (int i = 0; i < lenA ; i++) {
		arr[i].val = a.at(i);
		arr[i].group = true;
	}
	for (int i = 0; i < lenB; i++) {
		arr[i+lenA].val = b.at(i);
		arr[i + lenA].group = false;
	}
	while (operation_time>0) {

		bool visited[10000] = {false,};
		for (int i = 0; i < lenA + lenB-1; i++) {
			if (arr[i].group != arr[i + 1].group &&visited[i]==false && visited[i+1]==false) {
				swap(i,i+1);
				visited[i] = true;
				visited[i + 1] = true;
			}
		}
		operation_time--;
	}
	for (int i = 0; i < lenA + lenB ; i++) {
		printf("%c", arr[i].val);
	}
	return 0;
}
*/