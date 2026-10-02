#include <iostream>
#include <string>
 class BankAccount{
private:
std::string owner;
double balance;

public:
    void setOwner(std :: string nameOwner){
    owner= nameOwner;
    };

    std::string getOwner(){
    return owner;
    };

    void deposit(double amount){
    balance+= amount;
    };

    void withdraw(double amount){
        if (balance>=amount)
        {
           balance-= amount;
        }
        else{
            std :: cout <<"Less Money to Withdraw \n";
        }
        
    
    };

    double getBalance(){
    return balance;
    };
    void getAccountInfo(){
    std :: cout << "Name on Konto: "<< owner<< "\n";
    std :: cout << "Amount of Money: " << balance<< "€ \n";
    };

 };



int main(){
BankAccount account;
account.deposit(1000);
account.getAccountInfo(); 
account.setOwner("Daniel Hamburger");
account.getAccountInfo(); 
account.withdraw(500);
account.getAccountInfo(); 
    return 0;
}