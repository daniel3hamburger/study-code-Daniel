#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
template<typename A, std::size_t N>
std::vector<A> import(A (&myArray)[N]){
   std::vector <A> myVector;

    for(std::size_t i=0;i<N; ++i){
         myVector.push_back(myArray[i]);
    }

    return myVector;
};


template<typename D>
void analysis(const std::vector<D>& myVector){
    D sum = std::accumulate(myVector.begin(),myVector.end(),0);
    std::vector<D> myCopy= myVector;

    std::sort(myCopy.begin(),myCopy.end());
    D max =myCopy.back();
    
    int size= myCopy.size();

    double average= sum/size;
    for(D value: myVector){
        std::cout<<value<<" ";
    }
    std::cout<<std::endl;
    std::cout<<"MAX: "<<max<< std::endl;
    std::cout<<"SUM: "<<sum<<std::endl;
    std::cout<<"Average: "<< average<<std::endl;
};

template<>
void analysis<bool>(const std::vector<bool>& myVector){
    int size=myVector.size();
    int count=std::count(myVector.begin(),myVector.end(),true);

    if (count > size / 2){
        std::cout<<"true";
    
    }
    else{
        std::cout<<"False";
    }
    
};
int main(){
    std::vector<double> myVector= {2.6,6,9.3,2,7,5};
    analysis(myVector);
    std::vector<int> myVector1= {2,6,9,2,7,5};
    analysis(myVector1);
    int myarray[4]={4,7,3,2};
    std::vector<int> myVector2 = import(myarray);
    analysis(myVector2);
    std::vector<bool> myVector3={false,false,true};
    analysis(myVector3);
    return 0;
}