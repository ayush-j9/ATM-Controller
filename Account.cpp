//
// Created by Ayush J on 11/8/2020.
//

#include "Account.h"

Account::Account(Card c) : card{c} {

    growthBalance = 1000;
    savingsBalance = 2000;
    checkingBalance = 3000;
}


int Account::getCardNumber() {
    return card.getNumber();
}


int Account::getBalance(const AccountType accountType) {
    if (accountType == Growth) {
        return growthBalance;
    } else if (accountType == Savings) {
        return savingsBalance;
    } else if (accountType == Checking) {
        return checkingBalance;
    } else {
        cerr << "Wrong Account type" << endl;
        return -1;
    }
}

void Account::addMoney(const AccountType accountType, int amount) {
    if (accountType == Growth) {
        growthBalance += amount;
    } else if (accountType == Savings) {
        savingsBalance += amount;
    } else if (accountType == Checking) {
        checkingBalance += amount;
    } else {
        cerr << "Wrong Account type" << endl;
    }
}

bool Account::withdrawMoney(const AccountType accountType, int amount) {
    if (accountType == Growth) {
        growthBalance -= amount;
    } else if (accountType == Savings) {
        savingsBalance -= amount;
    } else if (accountType == Checking) {
        checkingBalance -= amount;
    } else {
        cerr << "Wrong Account type" << endl;
        return false;
    }
    return true;
}