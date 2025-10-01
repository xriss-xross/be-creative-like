#include <iostream>
#include <limits>

using std::cout;
using std::cin;

int main() {
    bool status = true;
    
    cout << "Hello World!\n";

    while (status) {
        int inp;
        cin >> inp;

        if (cin.fail()) {
            cout << "Error: failed to read a valid input\nPlease ensure that you use integers only\n";
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else if ((inp%3) == 0 && (inp%5) == 0) {
            cout << "Fizzbuzz\n";
        } else if ((inp%3) == 0) {
            cout << "Fizz\n";
        } else if ((inp%5) == 0) {
            cout << "Buzz\n";
        } else { 
            cout << "-------------------------------------\n"<< inp << " is neither fizz nor buzz!\n";
            status = false;
        }
    }
    return 0;
}
