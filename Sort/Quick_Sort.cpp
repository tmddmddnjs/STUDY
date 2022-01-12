#include <iostream>
using namespace std;

void swap(int* a, int* b);
void Quick(int left, int right);

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}
int Data[100];
void Quick(int left, int right) {
	int pivot, i, j, temp;
	if (left >= right)
		return;
	pivot = left;
	i = left + 1;
	j = right;
	while (i <= j) {
		while (Data[i] <= Data[pivot] && i <= right)
			i++;
		while (Data[j] >= Data[pivot] && j > left)
			j--;
		if (i > j) {
			swap(Data[j], Data[pivot]);
		}
		else {
			swap(Data[i], Data[j]);
		}
	}
	Quick(left, j - 1);
	Quick(j + 1, right);
}

int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> Data[i];
	}
	Quick(0, count - 1);
	for (int i = 0; i < count; i++) {
		cout << Data[i] << ' ';
	}
}