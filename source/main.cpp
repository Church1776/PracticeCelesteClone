#include <iostream>

static bool running{true};

int main(){
    
    while(running){
        
        // Update
        std::cout << "Want to stop?(0. Yes, 1. No)\n";
        std::cin >> running;
    }
    
    std::cout << "\nProgram ended with no errors.\n";
    return 0;
}