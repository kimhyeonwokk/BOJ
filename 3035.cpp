// 3055 탈출
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int R, C;
char map[51][51] = { };
int check[51][51] = { 0 };
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
void find(queue<pair<int, int>> &q,int &final_x,int &final_y) {
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == '*') {
				check[i][j] = 1;
				q.push(make_pair(i, j));
			}
			if (map[i][j] == 'D') {
				final_x = i;
				final_y = j;
			}
		}
	}
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			if (map[i][j] == 'S') {
				check[i][j] = 1;
				q.push(make_pair(i, j));
			}
		}
	}
}
void BFS() {
	queue<pair<int, int>> q;
	int final_x;
	int final_y;
	find(q,final_x,final_y);
	while (!q.empty()) {
		int x1 = q.front().first;
		int y1 = q.front().second;
		if (x1 == final_x && y1 == final_y)
			break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int next_x1 = x1 + dx[i];
			int next_y1 = y1 + dy[i];
			if (map[x1][y1] == '*') {
				if (next_x1 >= 1 && next_y1 >= 1 && next_x1 <= R && next_y1 <= C){
					if (map[next_x1][next_y1] == '.') {
						map[next_x1][next_y1] = '*';
						q.push(make_pair(next_x1, next_y1));
						check[next_x1][next_y1] = -1;
					}
				}
			}
			else if (map[x1][y1] == 'S') {
				if (next_x1 >= 1 && next_y1 >= 1 && next_x1 <= R && next_y1 <= C) {
					if (map[next_x1][next_y1] == '.' || map[next_x1][next_y1] == 'D') {
						map[next_x1][next_y1] = 'S';
						q.push(make_pair(next_x1, next_y1));
						check[next_x1][next_y1] = check[x1][y1] + 1;
					}
				}
			}
		}
	}
	if (check[final_x][final_y] == 0) {
		cout << "KAKTUS\n" << endl;
		return;
	}
	cout << check[final_x][final_y]-1 << endl;
}
int main() {
	cin >> R >> C;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) 
			cin >> map[i][j];
	BFS();
}
