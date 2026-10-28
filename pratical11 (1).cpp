exception handling in c++
#include <iostream>
using namespace std;

int main() {
    int a, b;

    cout << "Enter numerator: ";
    cin >> a;

    cout << "Enter denominator: ";
    cin >> b;

    try {
        if (b == 0) {
            throw b;
        }

        cout << "Result = " << (float)a / b << endl;
    }
    catch (int x) {
        cout << "Exception caught: Division by zero is not allowed!"
             << endl;
    }

    cout << "Program continues normally." << endl;

    return 0;
}

Check voting eligibility

#include <iostream>
using namespace std;

int main() {
    int age;

    cout << "Enter your age: ";
    cin >> age;

    try {
        if (age < 0) {
            throw age;
        }

        if (age < 18) {
            throw "Not eligible for voting";
        }

        cout << "You are eligible for voting." << endl;
    }
    catch (int x) {
        cout << "Error: Age cannot be negative." << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }

    return 0;
}


Multiple catch blocks

#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "Enter 1 for integer exception"
         << "\nEnter 2 for character exception"
         << "\nEnter choice: ";
    cin >> choice;

    try {
        if (choice == 1) {
            throw 100;
        }
        else if (choice == 2) {
            throw 'A';
        }
        else {
            throw 3.14;
        }
    }
    catch (int x) {
        cout << "Integer exception: " << x << endl;
    }
    catch (char ch) {
        cout << "Character exception: " << ch << endl;
    }
    catch (double x) {
        cout << "Double exception: " << x << endl;
    }

    return 0;
}




Catch all exceptions
#include <iostream>
using namespace std;

int main() {
    int choice;

    cout << "Enter a number (1 or 2): ";
    cin >> choice;

    try {
        if (choice == 1) {
            throw 10;
        }
        else {
            throw "Unknown error";
        }
    }
    catch (int x) {
        cout << "Integer exception caught: " << x << endl;
    }
    catch (...) {
        cout << "Some other exception occurred." << endl;
    }

    return 0;
}




Real-life example: ATM withdrawal
#include <iostream>
using namespace std;

int main() {
    double balance = 5000;
    double amount;

    cout << "Available balance: Rs. " << balance << endl;
    cout << "Enter withdrawal amount: ";
    cin >> amount;

    try {
        if (amount <= 0) {
            throw "Invalid withdrawal amount";
        }

        if (amount > balance) {
            throw "Insufficient balance";
        }

        balance -= amount;
        cout << "Withdrawal successful." << endl;
        cout << "Remaining balance: Rs. " << balance << endl;
    }
    catch (const char* msg) {
        cout << "Transaction failed: " << msg << endl;
    }

    return 0;
}