#include <iostream>
#include "ATM.h"

int main() {

    ATM atm;

    //making account with card number just for testing
    Card card(12345);

    Account acc(12345);
    atm.addAccountTOATM(acc);

    //Test
    atm.insertCard(card);
    cout << "Enter Pin" << endl;
    atm.enterPIN();
    if (!atm.isUserValid()) {
        cerr << "Wrong PIN: write 1234 Next time" << endl;
    } else {
        cout << "Select account type : \n" <<
             "    Checking : 0\n" <<
             "    Savings : 1 ,\n" <<
             "    Growth : 2" <<
             endl;
        int accType;
        cin >> accType;

        atm.selectAccountType(static_cast<AccountType>(accType));

        int task;
        cout << "What do you want to do: \n" <<
             "    Check Balance : 0\n" <<
             "    Deposit : 1 ,\n" <<
             "    Withdraw : 2" <<
             endl;
        cin >> task;
        if (task == 0) {
            atm.showBalance();
        } else if (task == 1) {
            cout << "How much are you depositing? " << endl;
            int amount;
            cin >> amount;
            atm.depositMoney(amount);
            cout << "New Balance : " << endl;
            atm.showBalance();
        } else if (task == 2) {
            cout << "Enter Amount to be withDrawn " << endl;
            int amount;
            cin >> amount;
            atm.withdrawMoney(amount);
            cout << "New Balance : " << endl;
            atm.showBalance();
        }

//        atm.endSession();

    }
    return 0;
}