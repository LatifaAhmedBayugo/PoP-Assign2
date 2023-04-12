#include <iostream>
#include <string>

using namespace std;

// Function to check if a string input contains only digits
bool is_digits(const string& str)
{
    return str.find_first_not_of("0123456789") == string::npos;
}

// Main function
int main()
{
    int pin = 0000; // Default pin
    int balance = 1000; // Default balance
    int attempts = 0; // Counter for pin entry attempts

    while (true)
    {
        int option;
        cout << "Welcome to Mobile Money Service\n";
        cout << "Please select an option:\n";
        cout << "1. Authenticate\n";
        cout << "2. Reset/Change Pin\n";
        cout << "3. Check Balance\n";
        cout << "4. Send Money\n";
        cout << "5. Exit\n";
        cout << "Option: ";
        cin >> option;

        if (option == 1) // Authentication
        {
            int input_pin;
            cout << "Please enter your PIN: ";
            cin >> input_pin;
            if (input_pin == pin)
            {
                cout << "Authentication Successful\n";
            }
            else
            {
                attempts++;
                if (attempts >= 3)
                {
                    cout << "Maximum Pin entry attempts exceeded. Program Exiting\n";
                    return 0;
                }
                else
                {
                    cout << "Incorrect Pin. Please try again\n";
                }
            }
        }
        else if (option == 2) // Reset/Change Pin
        {
            int new_pin;
            cout << "Please enter your new PIN: ";
            cin >> new_pin;
            pin = new_pin;
            cout << "PIN has been reset/changed successfully\n";
        }
        else if (option == 3) // Check Balance
        {
            cout << "Your current balance is: " << balance << endl;
        }
        else if (option == 4) // Send Money
        {
            string recipient_account;
            int amount;
            cout << "Please enter the recipient's account number (10 digits and starts with 0): ";
            cin >> recipient_account;
            if (recipient_account.length() != 10 || !is_digits(recipient_account))
            {
                cout << "Invalid account number. Please enter a valid 10-digit account number\n";
                continue;
            }
            cout << "Please enter the amount to send: ";
            cin >> amount;
            if (amount <= 0 || amount > balance)
            {
                cout << "Invalid amount. Please enter a valid amount\n";
                continue;
            }
            string confirm;
            cout << "Do you want to send money to this account? " << recipient_account << " (YES/NO): ";
            cin >> confirm;
            if (confirm == "YES")
            {
                balance -= amount;
                cout << "Transaction Successful. " << amount << " has been sent to " << recipient_account << endl;
            }
            else
            {
                cout << "Transaction Cancelled\n";
            }
        }
        else if (option == 5) // Exit
        {
            cout << "Thank you for using Mobile Money Service\n";
            return 0;
        }
        else
        {
            cout << "Invalid option. Please enter a valid option\n";
        }
    }
    return 0;
}

