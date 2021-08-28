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
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	int N;
	int document, interview;
	int result = 0;
	vector<pair<int, int>> grade;
	cin >> T;
	while (T--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> document >> interview;
			grade.push_back({ document,interview });
		}
		sort(grade.begin(), grade.end());
		int max_score = grade.front().second;
		for (int i = 0; i < N; i++) {
			if (grade[i].second <= max_score) {
				result++;
				max_score = grade[i].second;
			}
		}
		cout << result << "\n";
		result = 0;
		grade.clear();
	}
}
