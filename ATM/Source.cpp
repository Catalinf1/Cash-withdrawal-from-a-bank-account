#include <conio.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <limits>
#include <string_view>
#include <optional>
#include <format>
#include <fstream>
#include <filesystem>
#include <chrono>


using namespace std;

class Bank {
private:
    string name;
    long long AccountNumber;
    string accountType;        // Account type (e.g., savings, checking)
    double balance = 0.0;
    string mobileNumber;

public:
    void setValues() {
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter account number: ";
        cin >> AccountNumber;
        cout << "Enter account type: ";
        cin >> accountType;
        cout << "Enter initial balance: ";
        cin >> balance;
        cout << "Enter mobile number: ";
        cin >> mobileNumber;
    }

    void showData() const {
        cout << format("Name: {}\n", name);
        cout << format("Account number: {}\n", AccountNumber);
        cout << format("Account type: {}\n", accountType);
        cout << format("Balance: {}\n", balance);
        cout << format("Mobile number: {}\n", mobileNumber);
    }
    // Deposits the specified amount into the account,
   // validates for positive amount, and displays status
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << format("Deposit successful! New balance: {}\n", balance);
        }
        else {
            cout << "Invalid deposit amount.\n" << endl;
        }
    }

    // Withdraws the specified amount from the account,
   // validates for positive amount and sufficient balance,
   // and returns the remaining balance or an empty value
    optional<double> withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << format("Withdrawal successful! New balance: {}\n", balance);
            return balance;
        }
        else {
            cout << "Insufficient funds.\n";
            return nullopt;
        }
    }

    long long getAccountNumber() const {
        return AccountNumber;
    }

    string_view getMobileNumber() const {
        return mobileNumber;
    }

    double getBalance() const {
        return balance;
    }

    void setMobileNumber(string_view newMobileNumber) {
        mobileNumber = newMobileNumber;
        cout << "Mobile number updated successfully.\n";
    }
};

int main() {
    Bank bank;
    int choice;
    double amount;
    string enteredMobileNumber;

    bank.setValues();

    bool validLogin;

    do {
        cout << endl << "\n**** Welcome to ATM *****\n";
        cout << "Enter account number: ";
        long long accountNumber;
        cin >>accountNumber;

        validLogin = (accountNumber == bank.getAccountNumber());

        if (validLogin) {
            do {
                cout << endl << "\n**** Welcome to ATM *****\n" << endl;
                cout << "Select options:\n";
                cout << "1. Check balance\n";
                cout << "2. Cash withdraw\n";
                cout << "3. Show user details\n";
                cout << "4. Update mobile number\n";
                cout << "5. Exit\n";
                cin >> choice;

                switch (choice) {
                case 1:
                    cout << format("Your balance is: {}\n", bank.getBalance());
                    break;
                case 2: {
                    cout << "Enter amount to withdraw: ";
                    cin >> amount;
                    auto result = bank.withdraw(amount);
                    if (result.has_value()) {
                        cout << format("Withdrawal successful! New balance: {}\n", result.value());
                    }
                    else {
                        cout << "Withdrawal failed!\n";
                    }
                    break;
                }
                case 3:
                    bank.showData();
                    break;
                case 4:
                    cout << "Enter current mobile number: ";
                    cin >> enteredMobileNumber;
                    if (enteredMobileNumber == bank.getMobileNumber()) {
                        cout << "Enter new mobile number: ";
                        string newMobileNumber;
                        cin >> newMobileNumber;
                        bank.setMobileNumber(newMobileNumber);
                    }
                    else {
                        cout << "Invalid mobile number." << endl;
                    }
                    break;
                case 5:
                    std::exit(0);
                default:
                    cout << "Invalid choice.\n";
                    break;
                }
            } while (choice != 5);
        }
        else {
            cout << "Invalid account number.\n";
        }
    } while (validLogin);

    return 0;
}

