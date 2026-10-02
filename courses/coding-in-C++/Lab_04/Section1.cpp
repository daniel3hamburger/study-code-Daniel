#include <iostream>
#include <cmath>
class Vector2D{
    private:
    double x;
    double y;

    public:
    Vector2D(): x(0), y(0){}
    Vector2D(double x, double y): x(x), y(y){}

    double getX(){
        return x;
    }
    double getY(){
        return y;
    }
    void print(){
        std::cout<<"X:"<< x << std::endl;
        std::cout<<"Y:"<< y << std::endl;
    }

    double lenghtExcact(){
        return sqrt(x*x +y*y);
    }

    double lenghtRound(){
        return std::round(sqrt(x*x +y*y));
   
    }
    Vector2D operator+(const Vector2D& other)const{
        return Vector2D(x+other.x, y+ other.y);
    }

    Vector2D operator+=(const Vector2D& other){
        x+= other.x;
        y+= other.y;
        return *this;
    }
    Vector2D operator*(int m){
        return Vector2D(x*m, y*m);
    }

};   

int main(){

    Vector2D v1(5.8,8.8);
    Vector2D v2(7,9);
    v1.print();
    std::cout<< v1.lenghtExcact()<<std::endl;
    std::cout<< v1.lenghtRound();

    Vector2D v3 = v1 + v2;
    v3.print();

    v1 += v2;
    v1.print();

    Vector2D v4= v2 * 4;
    v4.print();


    return 0;
}