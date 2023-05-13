#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tuple>

//Left off: code in account switch functionality then file i/o
//Major Bug:
//enum class Coin {penny = 0, nickel, dime, quarter};

enum User {UserOne = 1, UserTwo = 2, UserThree = 3,  UserFour = 4, UserFive = 5};

struct CoinStruct {
    std::string account_name;
    int pennies{};
    int nickels{};
    int dimes{};
    int quarters{};
};

void coin_calculator(std::vector<CoinStruct> &user_accounts, std::string &name)
{
    std::cout << "(Coin Calculator)" << std::endl;
    std::cout << " How many pennies do you have: ";
    int pennies{};
    std::cin >> pennies;
    CoinStruct account{};

    account.account_name = name;

    account.pennies = pennies;

    std::cout << "How many nickels do you have: ";
    int nickels{};
    std::cin >> nickels;
    account.nickels = nickels;

    std::cout << "How many dimes do you have: ";
    int dimes{};
    std::cin >> dimes;
    account.dimes = dimes;

    std::cout << "How many quarters do you have: ";
    int quarters{};
    std::cin >> quarters;
    account.quarters = quarters;

    user_accounts.push_back(account);
}

void coin_deposit(std::vector<CoinStruct> &user_accounts, int accountSwitch)
{
    Reentry:
    std::cout << "(Coin Deposit)" << std::endl;
    std::cout << "What type of coin are you adding to the account: " << std::endl;
    std::cout << " 1. Penny";
    std::cout << " 2. Nickel";
    std::cout << " 3. Dime";
    std::cout << " 4. Quarter" << "\n";

    int coinChoice{};
    std::cin >> coinChoice;

    std::cout << "How many coins of this type: " << std::endl;
    int coinAmount{};
    std::cin >> coinAmount;

        switch (coinChoice) {
            case 1:
                user_accounts.at(0).pennies = user_accounts.at(0).pennies + coinAmount;
                break;
            case 2:
                user_accounts.at(0).nickels = user_accounts.at(0).nickels + coinAmount;
                break;
            case 3:
                user_accounts.at(0).dimes = user_accounts.at(0).dimes + coinAmount;
                break;
            case 4:
                user_accounts.at(0).quarters = user_accounts.at(0).quarters + coinAmount;
                break;
        }

    /*if(accountSwitch == 2){
        switch (coinChoice) {
            case 1:
                user_accounts[1].pennies + coinAmount;
                break;
            case 2:
                user_accounts[1].nickels + coinAmount;
                break;
            case 3:
                user_accounts[1].dimes + coinAmount;
                break;
            case 4:
                user_accounts[1].quarters + coinAmount;
                break;
        }
    }
    if(accountSwitch == 3){
        switch (coinChoice) {
            case 1:
                user_accounts[2].pennies + coinAmount;
                break;
            case 2:
                user_accounts[2].nickels + coinAmount;
                break;
            case 3:
                user_accounts[2].dimes + coinAmount;
                break;
            case 4:
                user_accounts[2].quarters + coinAmount;
                break;
        }
    }
    if(accountSwitch == 4){
        switch (coinChoice) {
            case 1:
                user_accounts[3].pennies + coinAmount;
                break;
            case 2:
                user_accounts[3].nickels + coinAmount;
                break;
            case 3:
                user_accounts[3].dimes + coinAmount;
                break;
            case 4:
                user_accounts[3].quarters + coinAmount;
                break;
        }
    }
    if(accountSwitch == 5){
        switch (coinChoice) {
            case 1:
                user_accounts[4].pennies + coinAmount;
                break;
            case 2:
                user_accounts[4].nickels + coinAmount;
                break;
            case 3:
                user_accounts[4].dimes + coinAmount;
                break;
            case 4:
                user_accounts[4].quarters + coinAmount;
                break;
        }
    }*/
    std::cout << "Deposit more coins\n" << "1 --> Yes  0 --> No\n";
    bool depositChoice;
    std::cin >> depositChoice;

    if(depositChoice)
    {
        goto Reentry;
    }
}

void coin_balance(std::vector<CoinStruct> &user_accounts, int accountSwitch)
{
    std::cout << "(Coin Balance)" << std::endl;
    switch(accountSwitch){
        case UserOne:
            std::cout << "Balance is: $" << ((user_accounts.at(0).pennies * .01) + (user_accounts.at(0).nickels * .05) + (user_accounts.at(0).dimes * .1) + (user_accounts.at(0).quarters * .25)) << std::endl;
            break;
        case UserTwo:
            std::cout << "Balance is: $" << ((user_accounts[1].pennies * .01) + (user_accounts[1].nickels * .05) + (user_accounts[1].dimes * .1) + (user_accounts[1].quarters * .25)) << std::endl;
            break;
        case UserThree:
            std::cout << "Balance is: $" << ((user_accounts[2].pennies * .01) + (user_accounts[2].nickels * .05) + (user_accounts[2].dimes * .1) + (user_accounts[2].quarters * .25)) << std::endl;
            break;
        case UserFour:
            std::cout << "Balance is: $" << ((user_accounts[3].pennies * .01) + (user_accounts[3].nickels * .05) + (user_accounts[3].dimes * .1) + (user_accounts[3].quarters * .25)) << std::endl;
            break;
        case UserFive:
            std::cout << "Balance is: $" << ((user_accounts[4].pennies * .01) + (user_accounts[4].nickels * .05) + (user_accounts[4].dimes * .1) + (user_accounts[4].quarters * .25)) << std::endl;
            break;
    }
}

void account_creation(std::vector<CoinStruct> &user_accounts, std::string name)
{
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    std::cout << "(Account Creation)" << std::endl;
    std::cout << "First name on account?:";
    std::getline(std::cin, name);
    std::cout << "Lets set up your account:" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;
    coin_calculator(user_accounts, name);
    std::cout << "Account created successfully! Thank you for choosing Cosmere Banking." << std::endl;
}

int main()
{
    std::vector<CoinStruct> user_accounts;
    std::string name;
    std::string accountData = "appdata.txt";       //I'm stopping here because I want to finish solutions to data transfer and account switching between apps
    std::fstream fout;

    std::cout << "Welcome to Cosmere Banking" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    std::cout << "First lets create your account:" << std::endl;  //Want to make this an if statement when I get my data file setup, if user is new: do this
    account_creation(user_accounts, name);
    std::cout << "Continue to " << user_accounts.at(0).account_name << "'s account?:\n" << "1 --> Yes  0 --> No\n";

    int accountSwitch{1}; //Here I will have to add choose account if user is not new to the program, in order to get my start choice plus user_account vector index for apps
                          //I have to setup my data file(s) to access different account information after the first run of program.
    bool startChoice;
    std::cin >> startChoice;
    while(startChoice)
    {
        std::cout << "What application do you want to run:\n" << "1 --> Coin Deposit| " << "2 --> Coin Balance| " << "3 --> Account Creation" << std::endl;
        int appRun{};
        std::cin >> appRun;
        switch (appRun)
        {
            case 1:
                coin_deposit(user_accounts, accountSwitch);
                std::cout <<"Exit the Cosmere Banking?: 0 --> Yes  1 --> No\n";
                std::cin >> startChoice;
                break;
            case 2:
                coin_balance(user_accounts, accountSwitch);
                std::cout <<"Exit the Cosmere Banking?: 0 --> Yes  1 --> No\n";
                std::cin >> startChoice;
                break;
            case 3:
                account_creation(user_accounts, name);
                std::cout <<"Exit the Cosmere Banking?: 0 --> Yes  1 --> No\n";
                std::cin >> startChoice;
                break;
        }
    }
    std::cout << "Thank You for Banking with the Cosmere";
    return 0;
}
