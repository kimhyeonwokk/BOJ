#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace  std;
bool cmp(const pair<string, pair<int, pair<int, int>>>& a, const pair<string, pair<int, pair<int, int>>>& b) {
	if (a.second.second.second == b.second.second.second) {
		if (a.second.second.first == b.second.second.first) {
			return a.second.first > b.second.first;
		}
		return a.second.second.first > b.second.second.first;
	}
	return a.second.second.second > b.second.second.second;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	vector<pair<string, pair<int, pair<int, int>>>> vec;
	string name;
	int day, month, year;
	for (int i = 0; i < n; i++) {
		cin >> name >> day >> month >> year;
		vec.push_back(make_pair(name, make_pair(day, make_pair(month, year))));
	}
	sort(vec.begin(), vec.end(),cmp);
	
	cout << vec[0].first << endl;
	cout << vec[n - 1].first << endl;
}
