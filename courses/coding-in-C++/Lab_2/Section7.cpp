#include <iostream>
#include <string>

class Rescource{
    private:
    std::string adress;
    std::string content;
    int ranking;

    public:
    Rescource()
    : adress(""), content(""), ranking(0) {}

    Rescource(std::string adress, std::string content, int ranking)
    : adress(adress), content(content), ranking(ranking) {}

    int getRanking(){
        return ranking;
    }
    bool isPopular(){
        int RANK_IMPORTANT =50;
        if (ranking<RANK_IMPORTANT)
        {
        return false;
        }
        return true;
    } 

    bool contains(std::string input){
    return content.find(input)!= std::string::npos;
    }

    void display(){
        std::cout<<"Adress: "<< adress << std::endl;
        std::cout<<"Content: "<< content<< std::endl;
        std::cout<<"Ranking: "<< ranking<< std::endl;
    }

};

class Query{
    private:
    std::string text;
    int max_results;

    public:
    
    Query(std::string text, int max_results)
    : text(text), max_results(max_results) {}

    std::string getText(){
        return text;
    }
    int getMaxResults(){
        return max_results;
    }

    bool isValid(){
        if(text.empty()){
            std::cout<<" String is empty";
            return false;
        }
        if (max_results<= 0)
        {
            std::cout<<"Max Results is negativ!";
            return false;
        }
        
        return true;
    }

    void display(){
        std::cout<<"Text: "<< text << std::endl;
        std::cout<<"Maximal Results: "<< max_results<< std::endl;  

    }
};

class SearchEngine {
private:
    static const int MAX_RESOURCES = 10;
    Rescource resources[MAX_RESOURCES];
    int resource_count;
    int query_count;

public:
    SearchEngine() : resource_count(0), query_count(0) {}

    void addResource(const Rescource& input) {
        if (resource_count < MAX_RESOURCES) {
            resources[resource_count] = input;
            resource_count++;
        } else {
            std::cout << "No more memmory " << std::endl;
        }
    }

    void process(Query& input) {
        if (!input.isValid()) {
            return;
        }

        query_count++;

        std::cout << "Searching for: " << input.getText() << std::endl;

        bool found = false;

        for (int i = 0; i < resource_count; i++) {
            if (resources[i].contains(input.getText())) {
                std::cout << "Found :" << std::endl;
                resources[i].display();
                found = true;
                
            }
        }

        if (!found) {
            std::cout << "No founds" << std::endl;
        }
    }

    void displayInfo() {
        std::cout << "Saved Ressources: " << resource_count << std::endl;
        std::cout << "Used Queries: " << query_count << std::endl;
    }
};



int main(){
    SearchEngine enigne;

    Rescource s1("www.Google.de","Google", 90);
    Rescource s2("ww.gmail.com","Mail", 40);
    Rescource s3("ww.dhbw.de","Mail", 60);
    

    enigne.addResource(s1);
    enigne.addResource(s2);
    enigne.addResource(s3);

    Query search("Mail",10);
    enigne.process(search);
    enigne.displayInfo();
    return 0;
}