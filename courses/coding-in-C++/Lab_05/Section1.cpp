#include <iostream>
#include <vector>
#include <algorithm>
template < typename A ,typename D>
class reusable{
    public:
    std::vector<A>my_array{};
    void swap(A &typ_a, A &typ_b){
        std::cout<<"Typ1: "<< typ_a<<std::endl;
        std::cout <<"Typ2: "<< typ_b<<std::endl;

        A typ_c;
        typ_c= typ_b;
        typ_b= typ_a;
        typ_a= typ_c;
        std::cout<<"Swap done\n";

        std::cout<<"Typ1: "<< typ_a<<std::endl;
        std::cout <<"Typ2: "<< typ_b<<std::endl;
    }

    void frames(A typ1,A typ2){
        my_array.push_back(typ1);
        my_array.push_back(typ2);

       for (A i : my_array) {
        std::cout << i << " ";
    }
        
    }

    void smallest(){
        A minValue = my_array[0];

    for (const A& value : my_array) {
        if (value < minValue) {
            minValue = value;
        }
    }
    std::cout << "Kleinste Zahl: " << minValue << std::endl;
    }
    void metadata(D value1, A value2){
        std::cout<<"Channel: "<< value1<<" | ";
        std::cout<<"Priority: "<< value1<<std::endl;
    }
    
};

void sort(const std::vector<int> &myVector){
    
    for (int value: myVector)
    {
        std::cout<< value <<" ";
    }
    std::cout<<std::endl;
    std::vector<int> myCopy= myVector;

    std::sort(myCopy.begin(), myCopy.end());
     for (int value: myCopy)
    {
        std::cout<< value <<" ";
    }
    std::cout<<std::endl;

    std::vector<int> mySearch= myVector;
    auto found=std::find(mySearch.begin(),mySearch.end(),63);
    if (found!=mySearch.end())
    {
        std::cout<<"63 is found\n";
    }
    
    
}; 

void cleanup(const std::vector<int> &myVector){
    std::vector<int> myCopy= myVector;
    int counter =0;
    for (int &value : myCopy) {
        if (value == -1) {
            value = 0;
            counter++;
        }
        for (int v : myCopy) {
            std::cout << v << " ";
        }
        std::cout<<std::endl;
    }
    std::cout<< "Changes: "<<counter <<std::endl;
};

void loop(const std::vector<int> &myVector){
    std::vector <int> myCopy= myVector;
    for(std::vector<int>::iterator it = myCopy.begin();it != myCopy.end(); ++it){
        std::cout << *it <<" ";
    }
};

int main(){
   /* reusable <int,std::string,> r1;
    char a='A';
    char b='H';
    //r1.swap(a,b);
    r1.frames(5, 2);
    r1.frames(9, 4);
    
    r1.smallest();

    r1.metadata("motor-temp", 2);
*/
    std::vector<int> myVector{42, 17, 42, 5, 99, 17, 63, 12};
    sort(myVector);
    std::vector<int> myArray{-1,-1,13,-1,21,21,8,-1,8};
    cleanup(myArray);
    loop(myVector);
    return 0;

    

}
/*
 void frames(A typ1,A typ2){
        my_array.push_back(typ1);
        my_array.push_back(typ2);

       for (A i : my_array) {
        std::cout << i << " ";
    }
*/        