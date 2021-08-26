#include <iostream>
#include <deque>
using namespace std;
// 12시부터 시작
deque<int> circle[51];
deque<int> circle_copy[51];
int N, M, T;
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
void check_adj() {
	bool check = false;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			if (circle[i][j] == 0) {
				circle_copy[i].push_back(0);
				continue;
			}
			bool flag = false;
			for (int k = 0; k < 4; k++) {
				int next_x = i + dx[k];
				int next_y = j + dy[k];
				if (next_x >= 1 && next_x <= N) {
					if (next_y == -1)
						next_y = M - 1;
					if (next_y == M)
						next_y = 0;
					if (circle[next_x][next_y] == circle[i][j]) {
						flag = true;
						break;
					}
				}
			}
			if (flag == true) {
				check = true;
				circle_copy[i].push_back(0);
			}
			else {
				circle_copy[i].push_back(circle[i][j]);
			}
		}
	}

	for (int i = 1; i <= N; i++) {
		circle[i] = circle_copy[i];
		circle_copy[i].clear();
	}
	if (check == false) {
		float total = 0;
		float count = 0;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				total += circle[i][j];
				if (circle[i][j] != 0)
					count++;
			}
		}
		total /= count;
		for (int i = 1; i <= N; i++) {
			for (int j = 0; j < M; j++) {
				if (circle[i][j] == 0)
					continue;
				if (circle[i][j] > total) {
					circle[i][j]--;
				}
				else if (circle[i][j] < total) {
					circle[i][j]++;
				}
			}
		}
	}
}
void clock_wise(int index,int num) {
	for (int j = index; j <= N; j = j + index) {
		for (int i = 0; i < num; i++) {
			circle[j].push_front(circle[j].back());
			circle[j].pop_back();
		}
	}
}
void reverse_clock_wise(int index, int num) {
	for (int j = index; j <= N; j = j + index) {
		for (int i = 0; i < num; i++) {
			circle[j].push_back(circle[j].front());
			circle[j].pop_front();
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> N >> M >> T;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < M; j++) {
			int temp;
			cin >> temp;
			circle[i].push_back(temp);
		}
	}
	int total = 0;
	for (int i = 1; i <= T; i++) {
		int x_i, d_i, k_i;
		cin >> x_i >> d_i >> k_i;
		if (d_i == 0) {
			clock_wise(x_i, k_i);
		}
		else if (d_i == 1) {
			reverse_clock_wise(x_i, k_i);
		}
		/*
		for (int j = 1; j <= N; j++) {
			for (auto k : circle[j]) {
				cout << k << " ";
			}
			cout << endl;
		}
		cout << endl;
		*/
		total = 0;
		check_adj();
		for (int j = 1; j <= N; j++) {
			for (auto k : circle[j]) {
				//cout << k << " ";
				total += k;
			}
			//cout << endl;
		}
		//cout << total << endl;
		//cout << endl;
		//cout << endl;
	}
	cout << total << endl;
}
