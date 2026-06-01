/*
#include <semaphore.h>
#include <iostream>
#include <vector>
#include <thread>

unsigned int counter = 0;
std::mutex counter_mutex;
void increment(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::lock_guard<std::mutex> lock(counter_mutex);
      counter++;
    }
}

void decrement(int iterations){
        for (int i = 0; i < iterations; ++i) {
        std::lock_guard<std::mutex> lock(counter_mutex);
      counter--;
    }
}

int main(){
    std::thread s1(increment,500000);
    std::thread s2(increment,500000);
    std::thread s3(decrement, 500000);
    s1.join();
    s2.join();
    s3.join();

    std::cout << "Endgueltiger Zaehlerstand: " << counter << std::endl;
    return 0;
}
*/

#include <iostream>
#include <thread>
#include <queue>
#include <vector>

std::queue<int> buffer;
int item_counter = 0;
bool running = true;

void producer(int id) {
    while (running && item_counter < 1000) { 
        int item_id = ++item_counter;
        
        buffer.push(item_id);
        
        std::cout << "[Producer " << id << "] Produziertes Gut: #" << item_id << "\n";
        
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void consumer(int id) {
    while (running) {

        if (!buffer.empty()) {
            int item_id = buffer.front();
            buffer.pop();
            
            std::cout << "[Consumer " << id << "] Verbrauchtes Gut:  #" << item_id << "\n";
        }

        if (item_counter >= 1000 && buffer.empty()) {
            break;
        }
    }
}

int main() {
    
    std::thread p1(producer, 1);
    std::thread c1(consumer, 1);
    std::thread c2(consumer, 2);

    p1.join();
    c1.join();
    c2.join();
    return 0;
}
