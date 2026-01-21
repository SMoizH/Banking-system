#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int months;
    double annualTaxRate;
    double balance;

    
    cout << "Enter annual tax deduction rate (%): ";
    cin >> annualTaxRate;

    cout << "Enter initial account balance: ";
    cin >> balance;

    cout << "Enter number of months since account opened: ";
    cin >> months;

    // Arrays to store monthly data
    double deposits[months];
    double withdrawals[months];
    double taxes[months];

    double monthlyTaxRate = annualTaxRate / 12 / 100;

    double totalDeposits = 0;
    double totalWithdrawals = 0;
    double totalTax = 0;

    // Monthly processing
    for (int i = 0; i < months; i++)
    {
        cout << "\nMonth " << (i + 1) << endl;

        // Deposit input
        do
        {
            cout << "Enter deposit amount: ";
            cin >> deposits[i];
        } while (deposits[i] < 0);

        balance += deposits[i];
        totalDeposits += deposits[i];

        // Withdrawal input
        do
        {
            cout << "Enter withdrawal amount: ";
            cin >> withdrawals[i];
        } while (withdrawals[i] < 0);

        balance -= withdrawals[i];
        totalWithdrawals += withdrawals[i];

        // Tax calculation
        taxes[i] = balance * monthlyTaxRate;
        balance -= taxes[i];
        totalTax += taxes[i];
    }

    // Output summary
    cout << "\n===================================" << endl;
    cout << "Savings Account Summary" << endl;
    cout << "===================================" << endl;
    cout << fixed << setprecision(2);
    cout << "Final Balance: $" << balance << endl;
    cout << "Total Deposited: $" << totalDeposits << endl;
    cout << "Total Withdrawn: $" << totalWithdrawals << endl;
    cout << "Total Tax Deducted: $" << totalTax << endl;

    return 0;
}
