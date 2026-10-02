#include <iostream>
template<typename T,typename D>

class Pair{
    private:
    T typo1;
    D typo2;

    public:
    Pair(T typo1, D typo2):typo1(typo1), typo2(typo2){}

    void setTypo1(T typo1){
        this->typo1= typo1;
    }
    void setTypo2(D setTypo2){
        this->typo2=typo2;
    }

    D getTypo2()const {
        return typo2;
    }

    T getTypo1()const {
        return typo1;
    }
};

int main(){

    return 0;
}
