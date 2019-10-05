#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif
#define MAX 200
#include<iostream>
#include <string>
using namespace std;

struct str {
	int num0; //0 갯수
	int num1; //1 갯수
};

int cnt[MAX] = { 0, };
int main() {
	int n;
	scanf("%d", &n);
	bool isConflict1 = false;
	for (int i = 0; i < n; i++) {
		string str1, str2; //입력받은 s,t 문자열 저장 변수
		cin >> str1 >> str2;

		pair<str, str> p;
		int count = 0; //? 제외하고 일치하지 않는 문자열 갯수

		for (int j = 0; j < str1.size(); j++) {
			if (str2[j] == '0') p.second.num0++;
			else p.second.num1++;

			if (str1[j] == '0') p.first.num0++;
			else if (str1[j] == '1') p.first.num1++;
			else {
				if (str2[j] == '0') p.first.num0++;
				else p.first.num1++;
				cnt[i]++;
				str1[j] = str2[j];
				continue;
			}
			if (str1[j] != str2[j]) {
				count++;
				if (str1[j] == '1')
					isConflict1 = true;
			}
		}
		if (p.first.num1 > p.second.num1) cnt[i] = -1;
		else if(p.first.num1==p.second.num1) cnt[i] += (count / 2);
		else {
			if (count % 2 == 0) cnt[i] += (p.second.num1 - p.first.num1);
			else {
				if(isConflict1) cnt[i] += (count+1)/2;
				else cnt[i] += count;
			}
		}
		isConflict1 = false;
	}
	for (int i = 0; i < n; i++) 
		printf("Case %d: %d\n", i + 1, cnt[i]);
	
	return 0;
}
