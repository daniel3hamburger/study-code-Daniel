#include <stdio.h>

int main (){
 int myNumbers[5]= {10,20,30,40,50};

 int* Var2= myNumbers+1;
 int* Var5= myNumbers+4;

printf(" 1 adress: %p", &Var2);
printf(" 2 adress: %p \n", &Var5);
printf("Adress dif : %d",(Var5-Var2));

//Differenz von der ersten Postion des Pointers bis zum anderen sind 3 Postionen 
    return 0;
}