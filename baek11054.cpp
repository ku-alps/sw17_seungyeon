#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
백준 11054 가장 긴 바이토닉 부분 수열
*/

int main() {
	//input
	int n;
	scanf("%d", &n);
	int * a = new int[n];

	for (int i = 0; i < n; i++) {
		scanf("%d", &(a[i]));
	}


	int* up_list = new int[n];
	int* down_list = new int[n];
	vector<int> lis;

	//0 ~ n-1 각 index까지의 lis
	for (int i = 0; i < n; i++) {
		lis.clear();
		lis.push_back(a[0]);
		for (int j = 1; j <=i;j++) {
			if (a[j] > lis.back()) {
				lis.push_back(a[j]);
			}
			else {
				//lower_bound
				for (int k = 0; k < lis.size(); k++) {
					if (lis[k] > a[j]) {
						lis[k] = a[j];
						break;
					}
					else if (lis[k] == a[j]) break;
				}
			}
		}
		up_list[i] = lis.size();
	
	}
	//n-1 ~ 0 각 index까지의 lis
	for (int i = n -1; i >= 0; i--) {
		lis.clear();
		lis.push_back(a[n-1]);
		for (int j = n-2; j >=i; j--) {
			if (a[j] > lis.back()) {
				lis.push_back(a[j]);
			}
			else {
				//lower_bound
				for (int k = 0; k < lis.size(); k++) {
					if (lis[k] > a[j]) {
						lis[k] = a[j];
						break;
					}
					else if (lis[k] == a[j]) break;
				}
			}
		}
		down_list[n-i-1] = lis.size();

	}
	int sizeMax = up_list[0] + down_list[n-1] - 1;
	for (int i = 1; i <n; i++) {
		sizeMax = max(sizeMax, up_list[i] + down_list[n-i-1] - 1);
	}
	printf("%d", sizeMax);
	return 0;
}