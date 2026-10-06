#include <iostream>
#include <string>

int main() {
    std::string current{};
    bool isOn = false;
    bool loop = true;

    while(loop) {
        std::cin >> current;
    
        if((current.compare("ON") == 0)) {
            if(isOn) {
                std::cout << "already on" << std::endl;
            } else {
                std::cout << "turned on" << std::endl;
                isOn = true;
            }
        } else if((current.compare("OFF") == 0)) {
            if(!isOn) {
                std::cout << "already off" << std::endl;
            } else {
                std::cout << "turned off" << std::endl;
                isOn = false;
            }  
        } else if((current.compare("STATUS") == 0)) {
            if(isOn) {
                std::cout << "ON" << std::endl;
            } else {
                std::cout << "OFF" << std::endl;
            }
        }  else if((current.compare("EXIT") == 0)) {
            loop = false;
        }
    }
    return 0;
        
}