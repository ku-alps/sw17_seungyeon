#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
	int w, h, n; //����,����,�߶���� ���� ����
	cin >> w >> h;
	cin >> n;
	vector<int> width(n+1,0); //���� ����
	vector<int> height(n+1,0); //���� ����
	for (int i = 0; i < n; i++) {
		int line;
		int val;
		cin >> line >> val;
		if (line) height.push_back(val); //��������
		else width.push_back(val); //��������
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