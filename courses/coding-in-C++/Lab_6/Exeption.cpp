#include <iostream>
#include <stdexcept>

class ConfigLoader{
    public:
    void load( std::string filename){
    if(filename.empty())
        throw std::invalid_argument("Leeres Dokument");
    
    if(filename=="missing.cfg"){
        throw std::runtime_error("Datei kann nicht geöffnet werden");
    }
    if (filename=="invalid.cfg")
    {
       throw std::runtime_error("Datei hat falsche config");
    }
    if(filename.find(".cfg")==true){
        throw std::invalid_argument("Datei hat kein .cfg");
    }
    
    }
};

int main(){
    ConfigLoader config;
    config.load("filename.cfg");
    try
    {
        config.load("invalid");
    }
    catch(const std::invalid_argument& e)
    {
        std::cout << e.what() << '\n';
    }
    catch(const std::runtime_error& e){
        std::cout << e.what()<<'\n';
    }
    
    return 0;
}