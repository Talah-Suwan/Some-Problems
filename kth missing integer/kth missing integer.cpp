
#include <iostream>
using namespace std;

int findKthMissingInteger(int arr[], int size, int k) {
	int count = 0;              //  a Counter for missing numbers
	int numberInOrder = 1;
	int i = 0;

	while (count < k) {
		if (i < size && arr[i] == numberInOrder) {
			i++;
		}
		else {
			count++;  // Number is missing
			if (count == k)
				return numberInOrder;
		}
		numberInOrder++;
	}

	return -1;
}
int main() {

	bool flag = false;
	while (!flag) {
		cout << "Please enter the size of the array: ";
		int arrSize;
		cin >> arrSize;

		int arr[150];

		cout << "Please enter the positive array elements in an ascending order: " << endl;
		for (int i = 0; i < arrSize; i++) {
			cin >> arr[i];
		}

		cout << endl << "Please enter the Kth positive integer that is missing from this array: ";
		int k;
		cin >> k;

		cout << endl << "The " << k << " missing positive integer is: " << findKthMissingInteger(arr, arrSize, k) << endl;

		cout << "Would you like to try it again? (if yes, press 1 , if no, press any other number) " << endl;
		int answer;
		cin >> answer;

		if (answer != 1)
			flag = true;
	}
	return 0;

}