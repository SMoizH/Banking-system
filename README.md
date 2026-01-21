# Banking-system


cout << "Enter annual tax deduction rate (%): ";
cin >> annualTaxRate;

cout << "Enter initial account balance: Rs. ";
cin >> balance;

cout << "Enter number of months since account opened: ";
cin >> months;

double deposits[months];
double withdrawals[months];
double taxes[months];

double monthlyTaxRate = annualTaxRate / 12 / 100;

double totalDeposits = 0;
double totalWithdrawals = 0;
double totalTax = 0;


for (int i = 0; i < months; i++)  {
    cout << "\nMonth " << (i + 1) << endl;


    do  {
        cout << "Enter deposit amount: ";
        cin >> deposits[i];
    } while (deposits[i] < 0);

    balance += deposits[i];
    totalDeposits += deposits[i];

    do {
        cout << "Enter withdrawal amount: ";
        cin >> withdrawals[i];
    } while (withdrawals[i] < 0);

    balance -= withdrawals[i];
    totalWithdrawals += withdrawals[i];

    taxes[i] = balance * monthlyTaxRate;
    balance -= taxes[i];
    totalTax += taxes[i];
}

cout << "\n===================================" << endl;
cout << "Savings Account Summary" << endl;
cout << "===================================" << endl;
cout << fixed << setprecision(2);
cout << "Final Balance: Rs." << balance << endl;
cout << "Total Deposited: Rs." << totalDeposits << endl;
cout << "Total Withdrawn: Rs." << totalWithdrawals << endl;
cout << "Total Tax Deducted: Rs." << totalTax << endl;

return 0;
}
