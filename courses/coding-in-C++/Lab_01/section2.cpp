#include <iostream>
#include <cstdint>
#include <limits>


namespace __validation__ {
    bool isSenior(int age){ 
        return age >= 65;
    }   

    bool isAdult(int age){
        return age >= 18;
    }
}

int main(){
    int age=0;

    while(true){
    std::cout << "How old are you: ";
    if(std::cin >> age) break;

    std::cout << "Error, type in numbers\n";
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}


    std :: cout << "You are "<< age <<" old.\n";

   if( __validation__::isSenior(age)){
    std::cout<< "That means that you are a senior citizen. ";
   }

   else if (__validation__::isAdult(age)){
    std::cout<<"This means that you are a an adult. ";
   }
   else if (!(__validation__::isAdult(age)))
   {
    std::cout<<"This means that you are a kid or teenager. ";
   }
   
return 0;
}