// 2309 일곱난쟁이
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> height;
vector<int> find_seven;
int result = 0;
void find(int index, int cnt) {
	if (cnt == 7) {
		for (auto i : find_seven) {
			result += i;
		}
		if (result == 100) {
			sort(find_seven.begin(), find_seven.end());
			for (auto i : find_seven) {
				cout << i << endl;
			}
			exit(0);
		}
		result = 0;
		return;
	}
	if (index >= 9) return;
	find_seven.push_back(height[index]);
	find(index + 1, cnt + 1);
	find_seven.pop_back();
	find(index + 1, cnt);
}
int main() {
	int x;
	for (int i = 0; i < 9; i++) {
		cin >> x;
		height.push_back(x);
	}
	find(0, 0);
}
