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
// 게리맨더링 2  백준 17779 브루트포스
int N;
int MAP[21][21];
int result = 987654321;
void init() {
	ios::sync_with_stdio(false);
	cin.tie(0);	
}

bool one(int &x,int &y, int &d1, int &d2, int &i,int &j) {
	if (i >= 1 && i < x + d1 && j >= 1 && j <= y) {
		if (i >= x && j >= y - i + x) {
			return false;
		}
		return true;
	}
	return false;
}
bool two(int& x, int& y, int& d1, int& d2, int& i, int& j) {
	if (i >= 1 && i <= x + d2 && j > y && j <= N) {
		if (i >= x && j <= y + i - x) {
			return false;
		}
		return true;
	}
	return false;
}
bool three(int& x, int& y, int& d1, int& d2, int& i, int& j) {
	if (i >= x + d1 && i <= N && j >= 1 && j < y - d1 + d2) {
		if (i <= x + d1 + d2 && j >= y + d2 - d1 - (x + d1 + d2 - i)) {
			return false;
		}
		return true;
	}
	return false;
}
bool four(int& x, int& y, int& d1, int& d2, int& i, int& j) {
	if (i > x + d2 && i <= N && j >= y-d1+d2 && j <= N) {
		if (i <= x + d1 + d2 && j <= y + d2 - d1 + (x + d1 + d2 - i)) {
			return false;
		}
		return true;
	}
	return false;
}
void Divide_Areas(int& x, int& y, int& d1, int& d2) {
	int num_area[6] = { 0 };
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (one(x, y, d1, d2, i, j)) {
				num_area[1] += MAP[i][j];
			}
			else if (two(x, y, d1, d2, i, j)) {
				num_area[2] += MAP[i][j];
			}
			else if (three(x, y, d1, d2, i, j)) {
				num_area[3] += MAP[i][j];
			}
			else if (four(x, y, d1, d2, i, j)) {
				num_area[4] += MAP[i][j];
			}
			else {
				num_area[5] += MAP[i][j];
			}
		}
	}
	sort(num_area + 1, num_area + 6);
	result = min(result, num_area[5] - num_area[1]);
}
void choose_d1_d2(int &x, int &y) {
	int d1 = 1;
	int d2 = 1;
	bool flag = false;
	while (1) {
		if (x + d1 + d2 <= N && y - d1 >= 1 && y + d2 <= N) {

			Divide_Areas(x, y, d1, d2);
			d2++;
			flag = true;
		}
		else if(flag == true){
			d1++;
			d2 = 1;
			flag = false;
		}
		else if (flag == false)
			break;
	}
}
void solve() {
	for (int x = 1; x <= N; x++) {
		for (int y = 2; y <= N - 1; y++) {
			choose_d1_d2(x, y);
		}
	}
}
void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> MAP[i][j];
		}
	}
}
int main() {
	init();
	input();
	solve();
	cout << result << endl;
}
