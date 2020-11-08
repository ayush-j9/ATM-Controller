//
// Created by Ayush J on 11/8/2020.
//

/*Write code for a simple ATM. It doesn't need any UI (either graphical or console), but a controller should be implemented and tested.



Requirements
At least the following flow should be implemented:
Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw
For simplification, there are only 1 dollar bills in this world, no cents. Thus account balance can be represented in integer.
Your code doesn't need to integrate with a real bank system, but keep in mind that we may want to integrate it with a
 real bank system in the future. It doesn't have to integrate with a real cash bin in the ATM, but keep in mind that
 we'd want to integrate with that in the future. And even if we integrate it with them, we'd like to test our code.
 Implementing bank integration and ATM hardware like cash bin and card reader is not a scope of this task, but testing
 the controller part (not including bank system, cash bin etc) is within the scope.

A bank API wouldn't give the ATM the PIN number, but it can tell you if the PIN number is correct or not.
Based on your work, another engineer should be able to implement the user interface. You don't need to implement
 any REST API, RPC, network communication etc, but just functions/classes/methods, etc.


You can simplify some complex real world problems if you think it's not worth illustrating in the project.

How to submit
Please upload the code for this project to GitHub or anywhere, and post a link to your repository below. Please attach the instruction to clone your project, build and run tests in README.md file in the root directory of the repository.*/

#ifndef ATM_CONTROLLER_ATM_H
#define ATM_CONTROLLER_ATM_H

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>

#include "Account.h"
#include "Card.h"
#include "AdditionalClasses.h"


class ATM {
public:
    ATM();

    void addAccountTOATM(Account &acc);

    void insertCard(Card &card);

    void readCard();

    void enterPIN();

    void selectAccountType(AccountType accType);

    void showBalance();

    void withdrawMoney(int amount);

    void depositMoney(int amount);

    void endSession();

    bool isUserValid();


private:

    int getBalance();

    CardReader cardReader;
    KeyPad keyPad;
    AccountType currAccountType{NotSelected};
    Card *cardCurrentlyHolding{nullptr};
    bool userValidated{false};
    Account *acc{nullptr};

    //The accounts and the search services are usually done through the bank Services but we are keeping them here for
    // now
    vector<Account> allAccounts;
    unordered_map<int, int> cardNum2AccountIdx;
    //    CashBin cashBin;
};


#endif //ATM_CONTROLLER_ATM_H
