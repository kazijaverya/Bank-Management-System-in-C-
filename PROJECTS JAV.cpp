#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class representing a bank account
class BankAccount {
private:
    string holderName; // Name of the account holder
    int accNumber;     // Unique account number
    double accBalance; // Current balance in the account

public:
    // Constructor to initialize a new bank account
    BankAccount(string name, int number, double initialBalance) {
        holderName = name;
        accNumber = number;
        accBalance = initialBalance;
    }

    // Method to deposit money into the account
    void depositFunds(double amount) {
        if (amount > 0) {
            accBalance += amount;
            cout << "₹" << amount << " has been successfully deposited. Your new balance is ₹" << accBalance << ".\n";
        } else {
            cout << "Oops! Invalid deposit amount. Please enter a positive value.\n";
        }
    }

    // Method to withdraw money from the account
    void withdrawFunds(double amount) {
        if (amount > 0 && amount <= accBalance) {
            accBalance -= amount;
            cout << "₹" << amount << " has been withdrawn. Your remaining balance is ₹" << accBalance << ".\n";
        } else {
            cout << "Insufficient funds or invalid amount! Please check and try again.\n";
        }
    }

    // Method to display account details
    void showAccountDetails() const {
        cout << "\n=== Account Information ===\n";
        cout << "Account Holder: " << holderName << endl;
        cout << "Account Number: " << accNumber << endl;
        cout << "Current Balance: ₹" << accBalance << endl;
    }

    // Getter for account number
    int getAccountNumber() const {
        return accNumber;
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\n=== Welcome to the Bank Management System ===\n";
    cout << "1. Create Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Display Account Details\n";
    cout << "5. Exit\n";
    cout << "Please enter your choice: ";
}

// Main function to run the bank management system
int main() {
    vector<BankAccount> accounts; // Vector to store bank accounts
    int choice; // User's menu choice

    while (true) {
        displayMenu(); // Show the menu
        cin >> choice;

        switch (choice) {
            case 1: {
                // Create a new account
                string name;
                int number;
                double initialBalance;

                cout << "Enter Account Holder Name: ";
                cin.ignore(); // Clear the input buffer
                getline(cin, name);
                cout << "Enter Account Number: ";
                cin >> number;
                cout << "Enter Initial Balance: ";
                cin >> initialBalance;

                accounts.emplace_back(name, number, initialBalance); // Add new account
                cout << "Account created successfully! Welcome, " << name << "!\n";
                break;
            }
            case 2: {
                // Deposit money
                int number;
                double amount;

                cout << "Enter Account Number: ";
                cin >> number;
                bool found = false;

                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == number) {
                        cout << "Enter Deposit Amount: ";
                        cin >> amount;
                        acc.depositFunds(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Sorry, account not found!\n";
                }
                break;
            }
            case 3: {
                // Withdraw money
                int number;
                double amount;

                cout << "Enter Account Number: ";
                cin >> number;
                bool found = false;

                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == number) {
                        cout << "Enter Withdrawal Amount: ";
                        cin >> amount;
                        acc.withdrawFunds(amount);
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Sorry, account not found!\n";
                }
                break;
            }
            case 4: {
                // Display account details
                int number;
                cout << "Enter Account Number: ";
                cin >> number;
                bool found = false;

                for (const auto &acc : accounts) {
                    if (acc.getAccountNumber() == number) {
                        acc.showAccountDetails();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Sorry, account not found!\n";
                }
                break;
            }
            case 5:
                cout << "Exiting the system. Goodbye!\n";
                return 0;
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }
}
