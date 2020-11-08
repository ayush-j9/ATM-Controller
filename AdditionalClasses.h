//
// Created by Ayush J on 11/8/2020.
//

#ifndef ATM_CONTROLLER_ADDITIONALCLASSES_H
#define ATM_CONTROLLER_ADDITIONALCLASSES_H


#include "Card.h"

class Currency {
    int val{1};
    int NoteID;
};

class CashBin;

class BankService;

class Transaction {
public:
    enum TransactionType {
        DEBIT,
        CREDIT,
    };
    enum TransactionStatus {
        SUCCESSFUL,
        PENDING,
        FAILED,
    };

    int TransactionId;
    TransactionType transactionType;
    TransactionStatus transactionStatus;
};

class CardReader {
    Card *card;
};


class KeyPad {
public:
    int getPINfromKeyPad() {
        int pin;
        cin >> pin;
        return pin;
    }
};

//class Search Not to be used
class Search {
public:
    static Account &getAccountFromCardNumber(const int cardNumber);

private:
    unordered_map<int, Account> card2Account;
};


#endif //ATM_CONTROLLER_ADDITIONALCLASSES_H
