#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <stack>
#define MAX 12+1
using namespace std;
// Chess_piece 구조체
struct Chess_piece
{
	int x, y;
	int dir;
	int num;
};
// 맵 크기, 말 개수
int N, K;
// 방향 →, ←, ↑, ↓
int dx[5] = { 0, 0,0,-1,1 };
int dy[5] = { 0, 1,-1,0,0 };
// 0 1 2, 흰색 빨간색 파란색 MAP
int map_color[MAX][MAX];
// Chess_piece 정보 저장
Chess_piece Chess_MAP[MAX];
// 쌓인 모양
deque<int> MAP[MAX][MAX];
void print() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cout << MAP[i][j].size() << " ";
		}
		cout << endl;
	}
}
int cal_floor(int& index, int& size_MAP, int& pre_x, int& pre_y) {
	for (int i = 0; i < size_MAP; i++)
		if (MAP[pre_x][pre_y][i] == Chess_MAP[index].num)
			return i;
}
void move_red(int& pre_x, int& pre_y, int& i, int& next_x, int& next_y) {
	int size_MAP = MAP[pre_x][pre_y].size();
	int floor = cal_floor(i, size_MAP, pre_x, pre_y);
	stack<int> temp;
	// 이동할 것들 저장
	for (int j = floor; j < size_MAP; j++) {
		temp.push(MAP[pre_x][pre_y][j]);
	}
	while (!temp.empty()) {
		MAP[pre_x][pre_y].pop_back();
		MAP[next_x][next_y].push_back(temp.top());
		Chess_MAP[temp.top()].x = next_x;
		Chess_MAP[temp.top()].y = next_y;
		temp.pop();
	}
}
void move_white(int& pre_x, int& pre_y, int& i, int& next_x, int& next_y) {
	int size_MAP = MAP[pre_x][pre_y].size();
	int floor = cal_floor(i, size_MAP, pre_x, pre_y);
	vector<int> temp;
	// 이동할 것들 저장
	for (int j = floor; j < size_MAP; j++)
		temp.push_back(MAP[pre_x][pre_y][j]);
	// 이동
	for (auto j : temp) {
		MAP[pre_x][pre_y].pop_back();
		MAP[next_x][next_y].push_back(j);
		Chess_MAP[j].x = next_x;
		Chess_MAP[j].y = next_y;
	}
}

void solve() {
	int count = 1;
	while (1) {
		if (count > 1000) {
			cout << -1 << endl;
			break;
		}
		for (int i = 1; i <= K; i++) {
			int pre_x = Chess_MAP[i].x;
			int pre_y = Chess_MAP[i].y;
			int next_x = pre_x + dx[Chess_MAP[i].dir];
			int next_y = pre_y + dy[Chess_MAP[i].dir];
			if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N) {
				if (map_color[next_x][next_y] == 0) {
					move_white(pre_x, pre_y, i, next_x, next_y);
				}
				else if (map_color[next_x][next_y] == 1) {
					move_red(pre_x, pre_y, i, next_x, next_y);
				}
				else if (map_color[next_x][next_y] == 2) {
					if (Chess_MAP[i].dir == 1)
						Chess_MAP[i].dir = 2;
					else if (Chess_MAP[i].dir == 2)
						Chess_MAP[i].dir = 1;
					else if (Chess_MAP[i].dir == 3)
						Chess_MAP[i].dir = 4;
					else if (Chess_MAP[i].dir == 4)
						Chess_MAP[i].dir = 3;
					next_x = pre_x + dx[Chess_MAP[i].dir];
					next_y = pre_y + dy[Chess_MAP[i].dir];
					if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N) {
						if (map_color[next_x][next_y] == 0) {
							move_white(pre_x, pre_y, i, next_x, next_y);
						}
						else if (map_color[next_x][next_y] == 1) {
							move_red(pre_x, pre_y, i, next_x, next_y);
						}
					}
				}
			}
			else {
				if (Chess_MAP[i].dir == 1)
					Chess_MAP[i].dir = 2;
				else if (Chess_MAP[i].dir == 2)
					Chess_MAP[i].dir = 1;
				else if (Chess_MAP[i].dir == 3)
					Chess_MAP[i].dir = 4;
				else if (Chess_MAP[i].dir == 4)
					Chess_MAP[i].dir = 3;
				next_x = pre_x + dx[Chess_MAP[i].dir];
				next_y = pre_y + dy[Chess_MAP[i].dir];
				if (next_x >= 1 && next_x <= N && next_y >= 1 && next_y <= N) {
					if (map_color[next_x][next_y] == 0) {
						move_white(pre_x, pre_y, i, next_x, next_y);
					}
					else if (map_color[next_x][next_y] == 1) {
						move_red(pre_x, pre_y, i, next_x, next_y);
					}
				}
			}
			for (int num_ = 1; num_ <= K; num_++) {
				if (MAP[Chess_MAP[num_].x][Chess_MAP[num_].y].size() >= 4) {
					cout << count << endl;
					return;
				}
			}
		}
		count++;
	}
}
void input() {
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> map_color[i][j];
	for (int i = 1; i <= K; i++) {
		int x, y, dir;
		cin >> x >> y >> dir;
		Chess_MAP[i] = { x,y,dir,i };
		MAP[x][y].push_back(i);
	}
}
// init 함수
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}
int main() {
	init();
	input();
	solve();
}
