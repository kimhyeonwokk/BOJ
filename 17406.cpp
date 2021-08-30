#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <utility>
#include <unordered_map>
#include <map>
#include <queue>
#include <stack>
#include <iomanip>
using namespace std;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);
}
struct operation{
	int r, c, s;
};
int array_map_original[51][51];
int array_map_copy[51][51];
int N, M, K;
vector<operation> operation_list;
bool operation_check[6];
operation choose_oper[6];
// 오른쪽 아래 왼쪽 위쪽
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
int min_result = 987654321;
void cal_array_value() {
	for (int i = 1; i <= N; i++) {
		int total = 0;
		for (int j = 1; j <= M; j++) {
			total += array_map_copy[i][j];
		}
		min_result = min(min_result, total);
	}
}
void turn(const operation& oper) {
	for (int i = 1; i <= oper.s; i++) {
		deque<int> temp;
		int x = oper.r - i;
		int y = oper.c - i;
		temp.push_back(array_map_copy[x][y]);
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < i * 2; k++) {
				x += dx[j];
				y += dy[j];
				temp.push_back(array_map_copy[x][y]);
			}
		}	
		temp.pop_back();
		array_map_copy[x][y] = temp.back();
		temp.pop_back();
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < i * 2; k++) {
				if (temp.empty()) {
					continue;
				}
				x += dx[j];
				y += dy[j];
				array_map_copy[x][y] = temp.front();
				temp.pop_front();
			}
		}
	}

}
void choose(int count) {
	if (count == K) {
		memcpy(array_map_copy, array_map_original, sizeof(array_map_copy));
		for (int i = 0; i < K; i++) {
			//cout << choose_oper[i].r << " " << choose_oper[i].c << " " << choose_oper[i].s;
			turn(choose_oper[i]);
		}
		cal_array_value();
		return;
	}
	for (int i = 0; i < K; i++) {
		if (!operation_check[i]) {
			operation_check[i] = true;
			choose_oper[count] = operation_list[i];
			choose(count + 1);
			operation_check[i] = false;
		}
	}
}
void input() {
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> array_map_original[i][j];
	for (int i = 1; i <= K; i++) {
		int r, c, s;
		cin >> r >> c >> s;
		operation_list.push_back({ r, c, s });
	}
}
int main() {
	init();
	input();
	choose(0);
	cout << min_result << endl;
}
