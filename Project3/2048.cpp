
/*
#include<stdio.h>
#include<queue>
#include<algorithm>
using namespace std;

struct INFO {
	int x, y, val;
};

int n;
int map[21][21];
int arr[5] ;
int max_ret = 0;

int func2(int backup[][21]) {

	int max_tmp = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			max_tmp = max(max_tmp, backup[i][j]);
		}
	}
	
	return max_tmp;
}


void func() {

	int backup[21][21] = { 0, };
	queue<INFO>q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			backup[i][j] = map[i][j];
		}
	}
	for (int k = 0; k < 5; k++) {

		if (arr[k] == 1) {
			bool visited[21][21] = { false, };
			for (int j = 0; j < n; j++) {
				for (int i = 1; i < n; i++) {
					if (backup[i - 1][j] != 0 && backup[i - 1][j] == backup[i][j] && visited[i - 1][j] == false) {
						backup[i - 1][j] += backup[i][j];
						backup[i][j] = 0;
						visited[i-1][j] = true;
					}
					else if (backup[i - 1][j] == 0) {
						int next = i;
						while (backup[next - 1][j]==0 && next>=1) {
							backup[next - 1][j] = backup[next][j];
							backup[next][j] = 0;
							next--;
						}
						if (backup[next - 1][j] != 0 && backup[next - 1][j] == backup[next][j] && visited[next - 1][j] == false) {
							backup[next - 1][j] += backup[next][j];
							backup[next][j] = 0;
							visited[next - 1][j] = true;
						}

					}
				}
			}
		}// 위로 이동하는 경우
		else if (arr[k] == 2) {
			bool visited[21][21] = { false, };
			for (int j = 0; j < n; j++) {
				for (int i = n-2; i >=0; i--) {
					if (backup[i + 1][j] != 0 && backup[i + 1][j] == backup[i][j] && visited[i + 1][j] == false) {
						backup[i + 1][j] += backup[i][j];
						backup[i][j] = 0;
						visited[i + 1][j] = true;
					}
					else if (backup[i + 1][j] == 0) {
						int next = i;
						while (backup[next + 1][j] == 0 && next <= n-2) {
							backup[next + 1][j] = backup[next][j];
							backup[next][j] = 0;
							next++;
						}
						if (backup[next + 1][j] != 0 && backup[next + 1][j] == backup[next][j] && visited[next + 1][j] == false) {
							backup[next + 1][j] += backup[next][j];
							backup[next][j] = 0;
							visited[next + 1][j] = true;
						}

					}
				}
			}
		
		}//아래로 이동
		else if (arr[k] == 3) {
			bool visited[21][21] = { false, };
			for (int i = 0; i < n; i++) {
				for (int j = 1; j < n; j++) {
					if (backup[i][j - 1] != 0 && backup[i][j - 1] == backup[i][j] && visited[i][j - 1] == false) {
						backup[i][j - 1] += backup[i][j];
						backup[i][j] = 0;
						visited[i][j - 1] = true;
					}
					else if (backup[i][j - 1] == 0) {
						int next = j;
						while (backup[i][next-1]==0 && next>=1) {
							backup[i][next - 1] = backup[i][next];
							backup[i][next] = 0;
							next--;
						}
						if (backup[i][next - 1] != 0 && backup[i][next - 1] == backup[i][next] && visited[i][next - 1] == false) {
							backup[i][next - 1] += backup[i][next];
							backup[i][next] = 0;
							visited[i][next - 1] = true;
						}
					}
				}
			}
		
		}//왼쪽으로 이동
		else if (arr[k] == 4) {
			bool visited[21][21] = { false, };
			for (int i = 0; i < n; i++) {
				for (int j = n - 2; j >= 0; j--) {
					if (backup[i][j + 1] != 0 && backup[i][j + 1] == backup[i][j] && visited[i][j + 1] == false) {
						backup[i][j + 1] += backup[i][j];
						backup[i][j] = 0;
						visited[i][j + 1] = true;
					}
					else if (backup[i][j + 1] == 0) {
						int next = j;
						while (backup[i][next + 1] == 0 && next <=n-2) {
							backup[i][next + 1] = backup[i][next];
							backup[i][next] = 0;
							next++;
						}
						if (backup[i][next + 1] != 0 && backup[i][next + 1] == backup[i][next] && visited[i][next + 1] == false) {
							backup[i][next + 1] += backup[i][next];
							backup[i][next] = 0;
							visited[i][next + 1] = true;
						}
					}
				}
			}
		}
		//한번 수행하고 가장 큰 블록 값 구하고 
		int max_tmp  = func2(backup);
		max_ret = max(max_ret, max_tmp);
	}
	return;
}

void permu(int cnt) {

	if (cnt == 5) {
		//수열 하나 완성
	//	for (int i = 0; i < 5; i++)
	//		printf("%d ", arr[i]);
	//	printf("\n");

		func();

	//	printf("현재 까지의 맥스 값 :    %d\n", max_ret);
		return;
	}
	for (int i = 1; i <= 4; i++) {
		arr[cnt] = i;
		permu(cnt+1);
	}
	return;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	permu(0);
//	func();
	printf("%d", max_ret);
	return 0;
}
*/