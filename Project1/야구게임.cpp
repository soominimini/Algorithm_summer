#include<stdio.h>
using namespace std;

int numbering[9] = { 0,0,0,1,0,0,0,0,0 };
bool visited[9] = {false,false,false,false,false,false,false,false,false};
void permu(int cnt) {

	 if (cnt == 9) {
		for (int i = 0; i < 9; i++) {
			printf("%d ", numbering[i]);

		}
		printf("\n");
	}
	else {
		for (int i = 1; i < 10; i++) {
			if (visited[i] == true) continue;
			numbering[cnt] = i;
			visited[i] = true;
			permu(cnt+1);
		}
	}

}
int main() {
	permu(0);
	return 0;
}