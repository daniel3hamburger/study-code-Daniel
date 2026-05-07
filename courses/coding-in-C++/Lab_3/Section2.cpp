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
    Student(std::string name, int id, int grade):User(name,id), grade(grade){}
    void printRole(){
        std::cout<<"Name: "<<name <<"\n";
        std::cout<<"ID: "<< id << "\n"; 
        std::cout<<"Grade: "<<grade<<"\n";
    }

};

class Instructor: public User{
    private: 
    int salary;

    public:
    Instructor(std::string name,int id, int salary): User(name,id),salary(salary){}

    void printRole(){
        std::cout<<"Name: "<<name <<"\n";
        std::cout<<"ID: "<< id << "\n"; 
        std::cout<< "Salary: "<< salary<<std::endl;
    }
};

int main(){
    Student user1("Daniel", 12, 2);
    Instructor student1("Michi", 11, 5);
    user1.printRole();
    student1.printRole();
    return 0;
}