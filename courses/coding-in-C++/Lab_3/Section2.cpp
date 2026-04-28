#include <iostream>

class User{
    protected:
    std::string name;
    int id;

public:

    User(std::string name, int id){
        this->name = name;
        this->id = id;
    }

    void printInfo(){
    std::cout<<"Name: "<<name <<"\n";
    std::cout<<"ID: "<< id << "\n"; 

    }

};

class Student : public User{
    private: 
    int grade;

    public:
    
    void printRole(){
        User::printInfo();
        std::cout<<"Grade"<<grade<<"\n";
    }

};

int main(){
    User user1("Daniel", 12);
    user1.printInfo();
    Student Student1("")
    return 0;
}