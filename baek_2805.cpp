#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int n, m; //n: 나무의 수 ,m:가져가려는 나무의 길이

int getTree(int x) {
	int sum = 0;

	for (int i : v) {
		if (i > x)
			sum += (i - x);
	}
	return sum;
}
int main() {
	int h = 0; //절단기 높이
	cin >> n >> m;
	v = vector<int>(n); //n개의 원소를 0으로 초기화 
	for (int i = 0; i < n; i++) {
		cin >> v.at(i);
	}
	sort(v.begin(), v.end());
	//	h = v.back() / 2; //중간값 설정
	int start = 0;
	int end = v.back();

	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = getTree(mid);
		if (sum >= m) {
			if (h < mid) {// 톱 길이 갱신
				h = mid;
			}
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	cout << h;
	return 0;
}