#include <iostream>
#include <ctime>
#include<windows.h>




int main() {


int tank = 1;
int dps = 1;
int supp = 1;

std::string answer;
int number;
int characters;

std::cout << "Welcome to the Randomizer" << '\n';
Sleep(2000);

while(true){

std::cout << "Pick a number for the role you want randomized" << '\n' << '\n' << "1. Tank | 2. DPS | 3. Support" << '\n' << '\n';
std::cin >> number;
while(number != 1 && number != 2 && number != 3){
    std::cout << "Please select a number from the listing." << '\n';
    std::cout << "Pick a number for the role you want randomized" << '\n' << '\n' << "1. Tank | 2. DPS | 3. Support" << '\n'<< '\n';
    std::cin >> number;
}
std::cout << "How many characters are in the role you selected?" << '\n' << '\n';
std::cin >> characters;

if(number == 1){
    srand(time(NULL));
    tank = (rand() % characters) + 1;
    std::cout << "Your chosen tank is #: " << tank << '\n';
} else if(number == 2){
    srand(time(NULL));
    dps = (rand() % characters) + 1;
    std::cout << "Your chosen dps is #: " << dps << '\n';
} else if(number == 3){
    srand(time(NULL));
    supp = (rand() % characters) + 1;
    std::cout << "Your chosen support is #: " << supp << '\n';
}

std::cout << '\n' << "Next random character?" << '\n' << "Yes or no?";
std::cin >> answer;

if(answer == "no"){
    break; 
}
}

return 0;
}
