#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdint>


void readStudentData(std::string& name, int& homework, int& midterm, int& finalexam) {
    const int Min_Grade = 0;
    const int Max_Grade = 100;
    bool validInput = false;

    std::cout << "Enter Student Name: ";
    std::getline(std::cin, name);

    do {
        std::cout << "Homework score: ";
        if (!(std::cin >> homework) || homework < Min_Grade || homework > Max_Grade) {
            std::cout << "Fehler, neue Eingabe\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else validInput = true;
    } while (!validInput);

    validInput = false;

    do {
        std::cout << "Midterm score: ";
        if (!(std::cin >> midterm) || midterm < Min_Grade || midterm > Max_Grade) {
            std::cout << "Fehler, neue Eingabe\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else validInput = true;
    } while (!validInput);

    validInput = false;

    do {
        std::cout << "Final Exam score: ";
        if (!(std::cin >> finalexam) || finalexam < Min_Grade || finalexam > Max_Grade) {
            std::cout << "Fehler, neue Eingabe\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else validInput = true;
    } while (!validInput);
}


void calculateGrade(int homework, int midterm, int finalExam, double &finalGrade, std::string &letterGrade){
    const int grade_a = 90;
    const int grade_b = 80;
    const int grade_c = 70;
    const int grade_d = 60;
    const int grade_e = 50;

    finalGrade= homework*0.4 + midterm*0.25 + finalExam *0.35 ; 

    if (finalGrade >= grade_a) {
        letterGrade = "A";
    }
    else if (finalGrade >= grade_b){
        letterGrade = "B";
    }
    else if (finalGrade >= grade_c) {
        letterGrade = "C";
    }
    else if (finalGrade >= grade_d) {
        letterGrade = "D";
    }
    else if (finalGrade >= grade_e) {
        letterGrade = "E";
    }
    else {
        letterGrade = "F";
    }

}

void printReport(std::string name, int homework, int midterm, int finalexam, double finalGrade, std::string letterGrade){
std:: string letterStatus="";

    if (letterGrade == "A" || letterGrade =="B" || letterGrade =="C"){
        letterStatus ="Pass";
    }
    else if (letterGrade =="D" ||  letterGrade =="E")
    {
        letterStatus ="Conditional Fail";
    }
    else{
        letterStatus ="Fail";
    }

 std:: cout << "Student-Report \n";
 std:: cout << "----------------------------- \n";
 std:: cout << std ::setw(15)<<"Name: "<<name << "\n \nScores: \n ";
 std:: cout << "----------------------------- \n";
 std:: cout << std::setw(15)<<"Homework: "<< homework << "\n";
 std:: cout << std::setw(15)<<"Midterm: "<<midterm<< "\n";
 std:: cout << std::setw(15)<<"Final Exam: "<< finalexam << "\n \n";
 std:: cout << std::setw(15)<<"Final Grade: "<<finalGrade<< "\n";
 std:: cout << std::setw(15)<<"Letter Grade: "<< letterGrade << "\n";
 std:: cout << std::setw(15)<<"Status: "<<letterStatus<< "\n";

}

int main() {

    std::string name;
    int homework = 0;
    int midterm = 0;
    int final_exam = 0;
    double finalGrade = 0.0;
    std::string letterGrade = "";
 

    readStudentData(name, homework, midterm, final_exam);

    calculateGrade(homework, midterm, final_exam, finalGrade, letterGrade);

    printReport(name, homework, midterm, final_exam, finalGrade, letterGrade);

    return 0;
}
