#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int w, h, n; //가로,세로,잘라야할 점선 갯수
	cin >> w >> h;
	cin >> n;
	vector<int> width(n+1,0); //가로 점선
	vector<int> height(n+1,0); //세로 점선
	for (int i = 0; i < n; i++) {
		int line;
		int val;
		cin >> line >> val;
		if (line) height.push_back(val); //가로점선
		else width.push_back(val); //세로점선
	}
	width.push_back(h);
	height.push_back(w);

	sort(width.begin(), width.end());
	sort(height.begin(), height.end());
	int max_w = width.front();
	int max_h = height.front();
	for (int i = 1; i < width.size(); i++) {
		if (max_w < width[i] - width[i - 1])
			max_w = width[i] - width[i - 1];
	}
	for (int i = 1; i < height.size(); i++) {
		if (max_h < height[i] - height[i - 1])
			max_h = height[i] - height[i - 1];
	}
	cout << max_h * max_w;
	return 0;
}