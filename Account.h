//
// Created by Ayush J on 11/8/2020.
//

#ifndef ATM_CONTROLLER_ACCOUNT_H
#define ATM_CONTROLLER_ACCOUNT_H

#include <string>
#include <iostream>

#include "Card.h"

using namespace std;


enum AccountType {
    Checking,
    Savings,
    Growth,
    NotSelected,
};


class Account {
public:
    Account() = delete;


    Account(Card c);

    int getBalance(const AccountType accountType);

    void addMoney(const AccountType accountType, int amount);

    bool withdrawMoney(const AccountType accountType, int amount);

    int getCardNumber();


private:
    string name;
    string contactNum;
    string Address;
    string BankName;
    string BranchNAme;
    int BankID;
    Card card;
    AccountType accType;
    int growthBalance;
    int checkingBalance;
    int savingsBalance;
    int AccountID;


};


#endif //ATM_CONTROLLER_ACCOUNT_H
