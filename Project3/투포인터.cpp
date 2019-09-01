
/*
using namespace std;

int solution(int n) {
	int answer = 0;
	int sum = 0;
	int head = 1, tail = 1;
		for (int i = 1; i <= n; i++) {
			sum += i;

			while (sum>=n) {
			if (sum == n) answer++;
				sum -= tail;
				tail++;
			}
		}

	return answer;
}

int main() {
	solution(15);
	return 0;

}
*/