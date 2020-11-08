# ATM-Controller
Cpp Version - C++14
CMakeList - 3.15 (in case you want to build with cmake)

Implemeted functionalities:
Insert Card => PIN number => Select Account => See Balance/Deposit/Withdraw

Provisions have been made to add bank system, bank services, search and transcation related information. It will also be possible to add hardware related functionalities like card reader, keypad, cash bin and currency. 

Currently, the account information is stored inside the controller. Since Pin based authentication is done using bank services, I have added a bank service function for the ease of use and hardcoded the pin to 1234.

## RUN
```bash
g++ main.cpp Account.cpp ATM.cpp Card.cpp -o solution.out
./solution.out
```
