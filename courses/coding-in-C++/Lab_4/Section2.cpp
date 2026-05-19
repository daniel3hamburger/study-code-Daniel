#include <iostream>
#include <math.h>


class Base{
    public:
    virtual double areaCacultation()const {
        return 0;
    }
    virtual ~Base(){}
};
//it can be a funtion that be above this Base function, 
//this class needs no distructor, the statdart destructor is enough to destry the funtion at the end

class Circle: public Base{
    private:
    double radius;
    const double PI= M_PI;

    public:
    Circle(double radius):radius(radius){};
    double areaCacultation()const override{
        return radius*PI*radius;
    }
};

class Rectangle:public Base{
    private: 
    double lenghtA;
    double lenghtB;

    public:
    Rectangle(double lenghtA, double lenghtB):lenghtA(lenghtA), lenghtB(lenghtB){};
    double areaCacultation()const override{
        return sqrt(lenghtA*lenghtB);
    }
};

int main(){
     int size=4;   
     Circle circle1(3);
    Rectangle rectangle1(2, 6);
    Circle circle2(8);
    Rectangle rectangle2(2, 2);

    Base *array[size]={&circle1, &rectangle1,&circle2,&rectangle2};
    for (int i = 0; i < size; i++)
    {
        std::cout << array[i]->areaCacultation()<<std::endl;
    }
    
    return 0;
}