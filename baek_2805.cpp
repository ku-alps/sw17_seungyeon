#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> v;
int n, m; //n: ������ �� ,m:���������� ������ ����

int getTree(int x) {
	int sum = 0;

	for (int i : v) {
		if (i > x)
			sum += (i - x);
	}
	return sum;
}
int main() {
	int h = 0; //���ܱ� ����
	cin >> n >> m;
	v = vector<int>(n); //n���� ���Ҹ� 0���� �ʱ�ȭ 
	for (int i = 0; i < n; i++) {
		cin >> v.at(i);
	}
	sort(v.begin(), v.end());
	//	h = v.back() / 2; //�߰��� ����
	int start = 0;
	int end = v.back();

	while (start <= end) {
		int mid = (start + end) / 2;
		int sum = getTree(mid);
		if (sum >= m) {
			if (h < mid) {// �� ���� ����
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