#include <iostream>
#include <string>

class Note{
private:
std:: string* text;

public: 

    Note(std::string text_input){
    text = new std::string;
    *text= text_input;
    }

    Note(const Note &otherNote)
    {
        text = new std::string;
        *text = *otherNote.text;
    }

    ~Note(){
    delete text;
    text = NULL;
    std ::cout <<"Memmory released \n";
    }

    void display(){
    std:: cout<< *text<<"\n";   
    }


};

int main(){

    Note note1 ("My Message");
    Note note2 = note1;
    
    note1.display();
    note2.display();

    return 0;
}