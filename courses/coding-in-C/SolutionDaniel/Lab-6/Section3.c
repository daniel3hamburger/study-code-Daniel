#include<stdio.h>
struct Sensordata{
    float time;
    double probaility;

};
struct Sensor{
    int id;
    double threshold;
    double data[3000];
    int object_detection[3000];
};

int main(){
    FILE *f;
    f = fopen("sensor1.txt", "r");
    if (!f){
    return 1;
    } 
    
    float time=0;
    float probability=0;
    for (int i = 0; i < 3000; i++){
        fscanf(f, "%f %lf", &time, &probability);

        printf("%.2f %.2lf\n", time , probability);
    }
  
    int time1 = fgetc(f);
    printf("%i\n", time1);


    return 0;
}