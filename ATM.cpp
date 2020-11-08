//
// Created by Ayush J on 11/8/2020.
//

#include "ATM.h"


void ATM::addAccountTOATM(Account &acc) {
    allAccounts.push_back(acc);
    cardNum2AccountIdx[acc.getCardNumber()] = allAccounts.size() - 1;
}


//Not Implementing
bool banskServiceAuthenticate(const Card *cardCurrentlyHolding, const int pin) {
    if (pin == 1234)
        return true;
    return false;
}

ATM::ATM() {

}

void ATM::enterPIN() {
    int pin = keyPad.getPINfromKeyPad();
    userValidated = banskServiceAuthenticate(cardCurrentlyHolding, pin);
    if (userValidated) {

        acc = &(allAccounts[cardNum2AccountIdx[cardCurrentlyHolding->getNumber()]]);
        auto aa = allAccounts[0];
        return;
        //breaking since search service is not made
        acc = &(Search::getAccountFromCardNumber(cardCurrentlyHolding->getNumber()));
    }
}


// we will get all cardInformation from cardReader
void ATM::insertCard(Card &card) {
//    cardReader.readCard();
    cardCurrentlyHolding = &card;
}


void ATM::selectAccountType(const AccountType accType) {
    currAccountType = accType;
}

void ATM::withdrawMoney(int amount) {
    if (amount <= acc->getBalance(currAccountType))
        acc->withdrawMoney(currAccountType, amount);
    else
        cerr << "Not Enough Balance " << endl;
}

void ATM::depositMoney(int amount) {
    if (amount > 0)
        acc->addMoney(currAccountType, amount);
    else
        cerr << "" << endl;
}

int ATM::getBalance() {
    return acc->getBalance(currAccountType);
}

void ATM::showBalance() {
    cout << getBalance() << endl;
}

void ATM::endSession() {
    acc = nullptr;
    userValidated = false;
    currAccountType = NotSelected;
    cardCurrentlyHolding = nullptr;
}

bool ATM::isUserValid() {
    return userValidated;
}
