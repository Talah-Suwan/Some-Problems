
#include <iostream>
using namespace std;

void DeciToBin(int n) {

    // Base case 
    if (n == 0)
        return;
    // General case
    else {
        DeciToBin(n / 2);
        cout << n % 2;
    }
}

int main()
{
    cout << "*** Welcome to the decimal to binary conversion system program ***" << endl;
    int number, answer = 1;

    do {
        cout << "Entre a positive number in decimal, please: ";
        cin >> number;

        while (number < 0) {
            cout << "You have entered a negative number. Please enter another positive one: ";
            cin >> number;
        }
        if (number == 0) {
            cout << "The number 0 in Binary is: 0" << endl;
        }
        else {
            cout << "The number " << number << " in Binary is: ";
            DeciToBin(number);
            cout << endl << endl;
        }

        // if the user wants to convert another number
        cout << "Would you like to convert another number?" << endl;
        cout << "If yes entre 1, if no entre 0: ";
        cin >> answer;
        cout << endl;

    } while (answer == 1);

    cout << "*** Thanks for using our program ***";

}