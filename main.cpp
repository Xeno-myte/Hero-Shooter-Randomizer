#include <iostream>
#include <ctime>
#include<windows.h>

void sup();
void DPS();
void tank1();


int main() {

    srand(time(NULL));

    int name;


    std::cout << "Welcome to the Randomizer" << '\n';

    Sleep(2000);

    std::cout << "Which game are you playing?" << '\n';
    std::cout << "1. Overwatch | 2. Apex Legends | 3. Marvel Rivals" << '\n';
    std::cin >> name;
    std::cout << '\n';



    std::string answer;
    int number;

    while (true) {

        std::cout << "Pick a number for the role you want randomized" << '\n' << '\n' << "1. Tank | 2. DPS | 3. Support" << '\n' << '\n';
        std::cin >> number;
        while (number != 1 && number != 2 && number != 3) {
            std::cout << "Please select a number from the listing." << '\n';
            std::cout << "Pick a number for the role you want randomized" << '\n' << '\n' << "1. Tank | 2. DPS | 3. Support" << '\n' << '\n';
            std::cin >> number;
        }


        if (number == 1) {

            tank1();

        }
        else if (number == 2) {

            DPS();

        }
        else if (number == 3) {
            sup();
        }

        std::cout << '\n' << "Next random character?" << '\n' << "Yes or no?";
        std::cin >> answer;

        if (answer == "no") {
            break;
        }
    }


    return 0;
}

void sup() {
    std::string answer;
    srand(time(NULL));
    int supp = 1;


    while (true) {
        supp = (rand() % 14) + 1;

        if (supp == 1) {
            std::cout << "The supp chosen was Ana" << '\n';
        }
        else if (supp == 2) {
            std::cout << "The supp chosen was Baptiste" << '\n';
        }
        else if (supp == 3) {
            std::cout << "The supp chosen was Brigitte" << '\n';
        }
        else if (supp == 4) {
            std::cout << "The supp chosen was Illari" << '\n';
        }
        else if (supp == 5) {
            std::cout << "The supp chosen was Jetpack Cat" << '\n';
        }
        else if (supp == 6) {
            std::cout << "The supp chosen was Juno" << '\n';
        }
        else if (supp == 7) {
            std::cout << "The supp chosen was Kiriko" << '\n';
        }
        else if (supp == 8) {
            std::cout << "The supp chosen was Lifeweaver" << '\n';
        }
        else if (supp == 9) {
            std::cout << "The supp chosen was Lúcio" << '\n';
        }
        else if (supp == 10) {
            std::cout << "The supp chosen was Mercy" << '\n';
        }
        else if (supp == 11) {
            std::cout << "The supp chosen was Mizuki" << '\n';
        }
        else if (supp == 12) {
            std::cout << "The supp chosen was Moira" << '\n';
        }
        else if (supp == 13) {
            std::cout << "The supp chosen was Wuyang" << '\n';
        }
        else if (supp == 14) {
            std::cout << "The supp chosen was Zenyatta" << '\n';
        }
        std::cout << "Do you want to reroll your support?" << '\n' << '\n';
        std::cin >> answer;

        if (answer == "no") {
            break;
        }
    }

}

void tank1() {
    std::string answer;
    srand(time(NULL));
    int tank = 1;

    while (true) {

        tank = (rand() % 15) + 1;


        if (tank == 1) {
            std::cout << "The tank chosen was Ramattra" << '\n';
        }
        else if (tank == 2) {
            std::cout << "The tank chosen was D.VA" << '\n';
        }
        else if (tank == 3) {
            std::cout << "The tank chosen was Domina" << '\n';
        }
        else if (tank == 4) {
            std::cout << "The tank chosen was Doomfist" << '\n';
        }
        else if (tank == 5) {
            std::cout << "The tank chosen was Hazard" << '\n';
        }
        else if (tank == 6) {
            std::cout << "The tank chosen was Junker Queen" << '\n';
        }
        else if (tank == 7) {
            std::cout << "The tank chosen was Mauga" << '\n';
        }
        else if (tank == 8) {
            std::cout << "The tank chosen was Orisa" << '\n';
        }
        else if (tank == 9) {
            std::cout << "The tank chosen was Reinhardt" << '\n';
        }
        else if (tank == 10) {
            std::cout << "The tank chosen was Roadhog" << '\n';
        }
        else if (tank == 11) {
            std::cout << "The tank chosen was Sigma" << '\n';
        }
        else if (tank == 12) {
            std::cout << "The tank chosen was Winston" << '\n';
        }
        else if (tank == 13) {
            std::cout << "The tank chosen was Wrecking Ball" << '\n';
        }
        else if (tank == 14) {
            std::cout << "The tank chosen was Zarya" << '\n' << '\n';
        }

        std::cout << "Do you want to reroll your Tank?" << '\n' << '\n';
        std::cin >> answer;

        if (answer == "no") {
            break;
        }
    }
}

void DPS() {
    std::string answer;
    srand(time(NULL));
    int dps = 1;

    while (true) {


        dps = (rand() % 23) + 1;

        if (dps == 1) {
            std::cout << "The dps chosen was Sierra" << '\n';
        }
        else if (dps == 2) {
            std::cout << "The dps chosen was Anran" << '\n';
        }
        else if (dps == 3) {
            std::cout << "The dps chosen was Ashe" << '\n';
        }
        else if (dps == 4) {
            std::cout << "The dps chosen was Bastion" << '\n';
        }
        else if (dps == 5) {
            std::cout << "The dps chosen was Cassidy" << '\n';
        }
        else if (dps == 6) {
            std::cout << "The dps chosen was Echo" << '\n';
        }
        else if (dps == 7) {
            std::cout << "The dps chosen was Emre" << '\n';
        }
        else if (dps == 8) {
            std::cout << "The dps chosen was Freja" << '\n';
        }
        else if (dps == 9) {
            std::cout << "The dps chosen was Genji" << '\n';
        }
        else if (dps == 10) {
            std::cout << "The dps chosen was Hanzo" << '\n';
        }
        else if (dps == 11) {
            std::cout << "The dps chosen was Junkrat" << '\n';
        }
        else if (dps == 12) {
            std::cout << "The dps chosen was Mei" << '\n';
        }
        else if (dps == 13) {
            std::cout << "The dps chosen was Pharah" << '\n';
        }
        else if (dps == 14) {
            std::cout << "The dps chosen was Reaper" << '\n';
        }
        else if (dps == 15) {
            std::cout << "The dps chosen was Sojourn" << '\n';
        }
        else if (dps == 16) {
            std::cout << "The dps chosen was Soldier: 76" << '\n';
        }
        else if (dps == 17) {
            std::cout << "The dps chosen was Sombra" << '\n';
        }
        else if (dps == 18) {
            std::cout << "The dps chosen was Symmetra" << '\n';
        }
        else if (dps == 19) {
            std::cout << "The dps chosen was Torbjörn" << '\n';
        }
        else if (dps == 20) {
            std::cout << "The dps chosen was Tracer" << '\n';
        }
        else if (dps == 21) {
            std::cout << "The dps chosen was Vendetta" << '\n';
        }
        else if (dps == 22) {
            std::cout << "The dps chosen was Venture" << '\n';
        }
        else if (dps == 23) {
            std::cout << "The dps chosen was Widowmaker" << '\n';
        }

        std::cout << "Do you want to reroll your DPS?" << '\n' << '\n';
        std::cin >> answer;

        if (answer == "no") {
            break;
        }
    }
}
