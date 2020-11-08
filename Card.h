//
// Created by Ayush J on 11/8/2020.
//

#ifndef ATM_CONTROLLER_CARD_H
#define ATM_CONTROLLER_CARD_H

class Card {
public:
    Card(int number);

    int getNumber();


    enum CardType {
        DEBIT,
        CREDIT,
    };
private:


    int cardNumber;
    int CVV;
    int expiryMonth;
    int expiryYear;
    int BankName;
    CardType cardType;


};


#endif //ATM_CONTROLLER_CARD_H
