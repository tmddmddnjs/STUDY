#include <iostream>
using namespace std;

void swap(int* a, int* b);
void Bubble(int count);

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Data[100];
void Bubble(int count) {
	for (int i = 0; i < count; i++) {
		for (int j = 0; j < count - 1; j++) {
			if (Data[j] > Data[j + 1]) {
				swap(Data[j], Data[j + 1]);
			}
		}
	}
}

int main() {
	int count;
	cin >> count;
	for (int i = 0; i < count; i++) {
		cin >> Data[i];
	}
	Bubble(count);
	for (int i = 0; i < count; i++) {
		cout << Data[i] << ' ';
	}
}