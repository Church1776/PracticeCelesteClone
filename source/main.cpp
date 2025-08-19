#include <iostream>
#include <fstream>

int main(){
    
    std::ofstream myfile;

    myfile.open ("Testing.txt");

    myfile << "Hello World!\n";

    myfile.close();

    myfile << "Did this line make it???\n";

    return 0;
}