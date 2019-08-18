
/*
#include<stdio.h>
#include<iostream>
#include<queue>
using namespace std;

struct AREA {
	int wolfNum = 0;
	int sheepNum = 0;
};

bool visited[251][251];
char map[251][251];
AREA area[50000];
int row, col;

int dx[] = { -1,0,+1,0 };
int dy[] = { 0,-1,0,+1 };

void func(int y, int x, int inx) {
	visited[y][x] = true;
	queue<int>q;
	int this_area_wolf = 0;
	int this_area_sheep = 0;

	q.push(y * 1000 + x);

	while (!q.empty()) {
		int cy = q.front() / 1000;
		int cx = q.front() % 1000;
		q.pop();
		int ny, nx;

		if (map[cy][cx] == 'v')this_area_wolf++;
		else if (map[cy][cx] == 'o')this_area_sheep++;

		for (int i = 0; i < 4; i++) {
			ny = cy + dy[i]; nx = cx + dx[i];
			if (ny < 0 || nx < 0 || ny >= row || nx >= col)continue;
			else if (visited[ny][nx] == true) continue;
			else if (map[ny][nx] == '#')continue;

			visited[ny][nx] = true;
			q.push(ny * 1000 + nx);
		}

	}
	area[inx].sheepNum = this_area_sheep;
	area[inx].wolfNum = this_area_wolf;

	return;

}

int main() {
	cin >> row >> col;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			cin >> map[i][j];
		}
	}
	int area_inx = 0;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			if (map[i][j] != '#'&& visited[i][j] == false) {
				func(i, j, area_inx++);
			}
		}
	}
	for (int i = 0; i < area_inx; i++) {
		if (area[i].wolfNum >= area[i].sheepNum) {
			area[i].sheepNum = 0;
		}
		else {
			area[i].wolfNum = 0;
		}
	}
	int ret_sheep = 0, ret_wolf = 0;
	for (int i = 0; i < area_inx; i++) {
		ret_sheep += area[i].sheepNum;
		ret_wolf += area[i].wolfNum;
	}
	printf("%d %d\n", ret_sheep, ret_wolf);
	return 0;
}

*/