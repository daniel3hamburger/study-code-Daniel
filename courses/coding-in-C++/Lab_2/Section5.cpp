/*
#include <iostream>
#include <string>
#include <iomanip>
using namespace std; //Using keyword 

class Article {
public:
    string name; //std::string
    double price;
    int stock;
    string* category; // no need of pointer
    int id; // should be a const 

    Article(string name, double price, int stock, string category, int id) {
        name = name; // usage of this-> is needed (naming conflict)
        price = price; //usage of this -> is needed 
        stock = stock; // usage of this-> is needed
        this->id = id;
        this->category = new string;
        *this->category = category;
    } //initialiser anstatt dem was jetzt ist

    void setPrice(double price) {
        price = price; // no check for negative infos
    }

    void sell(int amount) {
        stock = stock - amount; //can be shorter (-=) //this-> is missing  
    }

    void restock(int amount) {
        this->stock += amount;
    }

    double applyDiscount(double percent) { // ne need of a return statment 
        price = price - price * percent / 100; //missing brackets 
        return price;
    }

    double getPrice() { // no need 
        return price; //should be const
    }

    bool isAvailable() { //missing brackets in if statement // const 
        if (stock > 0)
            return true;
        else
            return false;
    }

    void printInfo() {
        cout << "Article: " << name << endl;
        cout << "Category: " << *category << endl;
        cout << "Price: " << price << endl;
        cout << "Stock: " << stock << endl;
        cout << "ID: " << id << endl;
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101); //magic numbers

    a.sell(15);
    a.restock(-5);
    a.price = -100;
    a.applyDiscount(150);

    if (a.isAvailable()) cout << "Article available" << endl; //should be wirtten in more than one line 

    a.printInfo();
}
*/

#include <iostream>
#include <string>
#include <iomanip>

class Article {
private:
    std:: string name;
    double price;
    int stock;
    std::string category;
    int id;
public:

    Article(std::string name, double price, int stock, std::string category, int id) {
        this->name = name;
        this->price = price;
        this->stock = stock;
        this->id = id;
        this->category = category;
    }

    void setPrice(double price) {
        if (price < 0) {
             std::cout << "Price cannot be negative\n";
            return;
        }
        this->price = price;
    }


    void sell(int amount) {
        if (amount > stock) {
            std::cout << "Not enough in stock\n";
            return;
        }
        stock -= amount;
    }


    void restock(int amount) {
        this->stock += amount;
    }

    void applyDiscount(double percent) {
        if (percent>0 && percent<100)
        {
            price = price - price * percent / 100;
        }
        else{
            std::cout<<"Not a right discount\n";
        }
         
    }

    double getPrice() {
        return price;
    }

    bool isAvailable() {
        if (stock > 0){
            return true;
        }
        else{
            return false;
        }
    }

    void printInfo() {
        std::cout << "Article: " << name << "\n";
        std::cout << "Category: " << category << "\n";
        std::cout << "Price: " << price << "\n";
        std::cout << "Stock: " << stock << "\n";
        std::cout << "ID: " << id << "\n";
    }
};

int main() {
    Article a("Laptop", 999.99, 10, "Electronics", 101);

    a.sell(5);
    a.restock(100);
    a.setPrice(100);
    a.applyDiscount(50);

    if (a.isAvailable()) std::cout << "Article available" << "\n";

    a.printInfo();
}