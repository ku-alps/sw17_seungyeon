#include <iostream>
#include <vector>
using namespace std;
void swqp(int & a, int &b) {
	int t = a;
	a = b;
	b = t;
}
void quickSort(int left, int right, int * data) {
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right) {
		for(;i<=right;i++)
			if (data[i] < data[pivot]) {
				j++;
				swap(data[j], data[i]);
			}
		swap(data[left], data[j]);
		pivot = j;
		quickSort(left, pivot - 1, data);
		quickSort(pivot + 1, right, data);
	}
}
int main() {
	int n;
	int a[50];
	int b[50];
	cin >> n;
	int tmp;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++)
		cin >> b[i];

	quickSort(0, n - 1, a);
	quickSort(0, n - 1, b);
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += a[i] * b[n - i - 1];
	}
	cout << sum;
	return 0;
}