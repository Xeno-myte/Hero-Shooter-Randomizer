#include <iostream>
#include <ctime>
#include<windows.h>

void sup();
void DPS();
void tank1();

void apex();

void vanguard();
void duelist();
void strategist();


int main() {


srand(time(NULL));
int name;
std::string answer;

std::cout << "Welcome to the Randomizer" << '\n';

Sleep(500);

while(true){
std::cout << "Which game are you playing?" << '\n';
std::cout << "1. Overwatch | 2. Apex Legends | 3. Marvel Rivals" << '\n';
std::cin >> name;
std::cout << '\n';

if(name == 1){

    std::string answer;
    int number;

    while(true){

    std::cout << "Pick a number for the role you want randomized" << '\n' << '\n' << "1. Tank | 2. DPS | 3. Support" << '\n' << '\n';
    std::cin >> number;
    
    if(number == 1){

        tank1();

    } else if(number == 2){

        DPS();

    }else if(number == 3){
        sup();
    }
    
    std::cout << '\n' << "Next random character?" << '\n' << "Yes or no?";
    std::cin >> answer;

    if(answer == "no"){
        break; 
    }
  }
}

if(name == 2){

    apex();

}

if(name == 3){
    int number;
    std::string answer;
    
    
    while(true){
        std::cout << "Pick a number for the role you want randomized" << '\n' << '\n' << "1. Vanguard | 2. Duelist | 3. Strategist" << '\n' << '\n';
        std::cin >> number;

        if(number == 1){
            vanguard();
        }else if(number == 2){
            duelist();
        }else if(number == 3){
            strategist();
        }
        
        std::cout << '\n' << "Next random character?" << '\n' << "Yes or no?";
        std::cin >> answer;

        if(answer == "no"){
            break; 
        }
    }
}

    std::cout << "Do you want to pick another game?" << '\n';
    std::cout << "Yes or No?" << '\n';
    std::cin >> answer;

    if(answer == "no"){
        return 0;
    }


}





return 0;
}

void sup(){
    std::string answer;
    srand(time(NULL));
    int supp = 1; 
    
    
    while(true){
    supp = (rand() % 14) + 1;

    if(supp == 1){
        std::cout << "The supp chosen was Ana" << '\n';
    }else if(supp == 2){
        std::cout << "The supp chosen was Baptiste" << '\n';
    }else if(supp == 3){
        std::cout << "The supp chosen was Brigitte" << '\n';
    }else if(supp == 4){
        std::cout << "The supp chosen was Illari" << '\n';
    }else if(supp == 5){
        std::cout << "The supp chosen was Jetpack Cat" << '\n';
    }else if(supp == 6){
        std::cout << "The supp chosen was Juno" << '\n';
    }else if(supp == 7){
        std::cout << "The supp chosen was Kiriko" << '\n';
    }else if(supp == 8){
        std::cout << "The supp chosen was Lifeweaver" << '\n';
    }else if(supp == 9){
        std::cout << "The supp chosen was Lúcio" << '\n';
    }else if(supp == 10){
        std::cout << "The supp chosen was Mercy" << '\n';
    }else if(supp == 11){
        std::cout << "The supp chosen was Mizuki" << '\n';
    }else if(supp == 12){
        std::cout << "The supp chosen was Moira" << '\n';
    }else if(supp == 13){
        std::cout << "The supp chosen was Wuyang" << '\n';
    }else if(supp == 14){
        std::cout << "The supp chosen was Zenyatta" << '\n';
    }
    std::cout << "Do you want to reroll your Tank?" << '\n' << '\n';
    std::cin >> answer;
    
    if(answer == "no"){
        break;
    }
}

}

void tank1(){
    std::string answer;
    srand(time(NULL)); 
    int tank = 1;
   
    while(true){

    tank = (rand() % 15) + 1;


    if(tank == 1){
        std::cout << "The tank chosen was Ramattra" << '\n';
    }else if(tank == 2){
        std::cout << "The tank chosen was D.VA" << '\n';
    }else if(tank == 3){
        std::cout << "The tank chosen was Domina" << '\n';
    }else if(tank == 4){
        std::cout << "The tank chosen was Doomfist" << '\n';
    }else if(tank == 5){
        std::cout << "The tank chosen was Hazard" << '\n';
    }else if(tank == 6){
        std::cout << "The tank chosen was Junker Queen" << '\n';
    }else if(tank == 7){
        std::cout << "The tank chosen was Mauga" << '\n';
    }else if(tank == 8){
        std::cout << "The tank chosen was Orisa" << '\n';
    }else if(tank == 9){
        std::cout << "The tank chosen was Reinhardt" << '\n';
    }else if(tank == 10){
        std::cout << "The tank chosen was Roadhog" << '\n';
    }else if(tank == 11){
        std::cout << "The tank chosen was Sigma" << '\n';
    }else if( tank == 12){
        std::cout << "The tank chosen was Winston" << '\n';
    }else if(tank == 13){
        std::cout << "The tank chosen was Wrecking Ball" << '\n';
    }else if(tank == 14){
        std::cout << "The tank chosen was Zarya" << '\n' << '\n';
    }
    
    std::cout << "Do you want to reroll your Tank?" << '\n' << '\n';
    std::cin >> answer;
    
    if(answer == "no"){
        break;
    }
}
}

void DPS(){
    std::string answer;
    srand(time(NULL)); 
    int dps = 1;
    
    while(true){

    
    dps = (rand() % 23) + 1;
    
    if(dps == 1){
        std::cout << "The dps chosen was Sierra" << '\n';
    }else if(dps == 2){
        std::cout << "The dps chosen was Anran" << '\n';
    }else if(dps == 3){
        std::cout << "The dps chosen was Ashe" << '\n';
    }else if(dps == 4){
        std::cout << "The dps chosen was Bastion" << '\n';
    }else if(dps == 5){
        std::cout << "The dps chosen was Cassidy" << '\n';
    }else if(dps == 6){
        std::cout << "The dps chosen was Echo" << '\n';
    }else if(dps == 7){
        std::cout << "The dps chosen was Emre" << '\n';
    }else if(dps == 8){
        std::cout << "The dps chosen was Freja" << '\n';
    }else if(dps == 9){
        std::cout << "The dps chosen was Genji" << '\n';
    }else if(dps == 10){
        std::cout << "The dps chosen was Hanzo" << '\n';
    }else if(dps == 11){
        std::cout << "The dps chosen was Junkrat" << '\n';
    }else if(dps == 12){
        std::cout << "The dps chosen was Mei" << '\n';
    }else if(dps == 13){
        std::cout << "The dps chosen was Pharah" << '\n';
    }else if(dps == 14){
        std::cout << "The dps chosen was Reaper" << '\n';
    }else if(dps == 15){
        std::cout << "The dps chosen was Sojourn" << '\n';
    }else if(dps == 16){
        std::cout << "The dps chosen was Soldier: 76" << '\n';
    }else if(dps == 17){
        std::cout << "The dps chosen was Sombra" << '\n';
    }else if(dps == 18){
        std::cout << "The dps chosen was Symmetra" << '\n';
    }else if(dps == 19){
        std::cout << "The dps chosen was Torbjörn" << '\n';
    }else if(dps == 20){
        std::cout << "The dps chosen was Tracer" << '\n';
    }else if(dps == 21){
        std::cout << "The dps chosen was Vendetta" << '\n';
    }else if(dps == 22){
        std::cout << "The dps chosen was Venture" << '\n';
    }else if(dps == 23){
        std::cout << "The dps chosen was Widowmaker" << '\n';
    }

    std::cout << "Do you want to reroll your DPS?" << '\n' << '\n';
    std::cin >> answer;
    
    if(answer == "no"){
        break;
    }
}
}

void apex(){

    std::string answer;
    int apex = 1;
    srand(time(NULL));
    
    while(true){

        apex = (rand() % 28) + 1;
        

        if(apex == 1){
            std::cout << "The character chosen was Mirage" << '\n';
        }else if(apex == 2){
            std::cout << "The character chosen was Newcastle" << '\n';
        }else if(apex == 3){
            std::cout << "The character chosen was Octane" << '\n';
        }else if(apex == 4){
            std::cout << "The character chosen was Pathfinder" << '\n';
        }else if(apex == 5){
            std::cout << "The character chosen was Rampart" << '\n';
        }else if(apex == 6){
            std::cout << "The character chosen was Revenant" << '\n';
        }else if(apex == 7){
            std::cout << "The character chosen was Seer" << '\n';
        }else if(apex == 8){
            std::cout << "The character chosen was Sparrow" << '\n';
        }else if(apex == 9){
            std::cout << "The character chosen was Valkyrie" << '\n';
        }else if(apex == 10){
            std::cout << "The character chosen was Vantage" << '\n';
        }else if(apex == 11){
            std::cout << "The character chosen was Wattson" << '\n';
        }else if(apex == 12){
            std::cout << "The character chosen was Wraith" << '\n';
        }else if(apex == 13){
            std::cout << "The character chosen was Alter" << '\n';
        }else if(apex == 14){
            std::cout << "The character chosen was Ash" << '\n';
        }else if(apex == 15){
            std::cout << "The character chosen was Axle" << '\n';
        }else if(apex == 16){
            std::cout << "The character chosen was Ballistic" << '\n';
        }else if(apex == 17){
            std::cout << "The character chosen was Bangalore" << '\n';
        }else if(apex == 18){
            std::cout << "The character chosen was Bloodhound" << '\n';
        }else if(apex == 19){
            std::cout << "The character chosen was Catalyst" << '\n';
        }else if(apex == 20){
            std::cout << "The character chosen was Caustic" << '\n';
        }else if(apex == 21){
            std::cout << "The character chosen was Conduit" << '\n';
        }else if(apex == 22){
            std::cout << "The character chosen was Crypto" << '\n';
        }else if(apex == 23){
            std::cout << "The character chosen was Fuse" << '\n';
        }else if(apex == 24){
            std::cout << "The character chosen was Gibraltar" << '\n';
        }else if(apex == 25){
            std::cout << "The character chosen was Horizon" << '\n';
        }else if(apex == 26){
            std::cout << "The character chosen was Lifeline" << '\n';
        }else if(apex == 27){
            std::cout << "The character chosen was Loba" << '\n';
        }else if(apex == 28){
            std::cout << "The character chosen was Mad Maggie" << '\n';
        }

        std::cout << "Do you want to reroll your character?" << '\n';
        std::cout << "Yes or no?" << '\n';
        std::cin >> answer;

        if(answer == "no"){
        break;
    }
    }
    
}


void vanguard(){

    std::string answer;
    int vanguard = 1;
    srand(time(NULL));
    
    while(true){

        vanguard = (rand() % 28) +1;

        if(vanguard == 1){
            std::cout << "The chosen Vanguard is Angela" << '\n';
        }else if(vanguard == 2){
            std::cout << "The chosen Vanguard is Captain America" << '\n';
        }else if(vanguard == 3){
            std::cout << "The chosen Vanguard is Deadpool" << '\n';
        }else if(vanguard == 4){
            std::cout << "The chosen Vanguard is Doctor Strange" << '\n';
        }else if(vanguard == 5){
            std::cout << "The chosen Vanguard is Emma Frost" << '\n';
        }else if(vanguard == 6){
            std::cout << "The chosen Vanguard is Groot" << '\n';
        }else if(vanguard == 7){
            std::cout << "The chosen Vanguard is Hulk" << '\n';
        }else if(vanguard == 8){
            std::cout << "The chosen Vanguard is Magneto" << '\n';
        }else if(vanguard == 9){
            std::cout << "The chosen Vanguard is Peni Parker" << '\n';
        }else if(vanguard == 10){
            std::cout << "The chosen Vanguard is Rogue" << '\n';
        }else if(vanguard == 11){
            std::cout << "The chosen Vanguard is The Thing" << '\n';
        }else if(vanguard == 12){
            std::cout << "The chosen Vanguard is Thor" << '\n';
        }else{
            std::cout << "The chosen Vanguard is Venom" << '\n';
        }
    
        std::cout << "Do you want to reroll your character?" << '\n';
        std::cout << "Yes or no?" << '\n';
        std::cin >> answer;

        if(answer == "no"){
        break;
    }
    
    
    }
}

void duelist(){

    std::string answer;
    int duelist = 1;
    srand(time(NULL));

    while(true){

        duelist = (rand() % 25) +1;

        if(duelist == 1){
            std::cout << "The chosen Duelist is Black Cat" << '\n';
        }else if(duelist == 2){
            std::cout << "The chosen Duelist is Black Panther" << '\n';
        }else if(duelist == 3){
            std::cout << "The chosen Duelist is Black Widow" << '\n';
        }else if(duelist == 4){
            std::cout << "The chosen Duelist is Blade" << '\n';
        }else if(duelist == 5){
            std::cout << "The chosen Duelist is Daredevil" << '\n';
        }else if(duelist == 6){
            std::cout << "The chosen Duelist is Deadpool" << '\n';
        }else if(duelist == 7){
            std::cout << "The chosen Duelist is Elsa Bloodstone" << '\n';
        }else if(duelist == 8){
            std::cout << "The chosen Duelist is Hawkeye" << '\n';
        }else if(duelist == 9){
            std::cout << "The chosen Duelist is Hela" << '\n';
        }else if(duelist == 10){
            std::cout << "The chosen Duelist is Human Torch" << '\n';
        }else if(duelist == 11){
            std::cout << "The chosen Duelist is Iron Fist" << '\n';
        }else if(duelist == 12){
            std::cout << "The chosen Duelist is Iron Man" << '\n';
        }else if(duelist == 13){
            std::cout << "The chosen Duelist is Magik" << '\n';
        }else if(duelist == 14){
            std::cout << "The chosen Duelist is Mister Fantastic" << '\n';
        }else if(duelist == 15){
            std::cout << "The chosen Duelist is Moon Knight" << '\n';
        }else if(duelist == 16){
            std::cout << "The chosen Duelist is Namor" << '\n';
        }else if(duelist == 17){
            std::cout << "The chosen Duelist is Phoenix" << '\n';
        }else if(duelist == 18){
            std::cout << "The chosen Duelist is Psylocke" << '\n';
        }else if(duelist == 19){
            std::cout << "The chosen Duelist is Scarlett Witch" << '\n';
        }else if(duelist == 20){
            std::cout << "The chosen Duelist is Spider-Man" << '\n';
        }else if(duelist == 21){
            std::cout << "The chosen Duelist is Squirrel Girl" << '\n';
        }else if(duelist == 22){
            std::cout << "The chosen Duelist is Star-Lord" << '\n';
        }else if(duelist == 23){
            std::cout << "The chosen Duelist is Storm" << '\n';
        }else if(duelist == 24){
            std::cout << "The chosen Duelist is The Punisher" << '\n';
        }else if(duelist == 25){
            std::cout << "The chosen Duelist is Winter Soldier" << '\n';
        }else{
            std::cout << "The chosen Duelist is Wolverine" << '\n';
        }

        std::cout << "Do you want to reroll your character?" << '\n';
        std::cout << "Yes or no?" << '\n';
        std::cin >> answer;

        if(answer == "no"){
        break;
    }


}
}

void strategist(){

    std::string answer;
    int strategist = 1;
    srand(time(NULL));

    while(true){

        strategist = (rand() % 8) +1;

        if(strategist == 1){
            std::cout << "The chosen Strategist is White Fox" << '\n';
        }else if(strategist == 2){
            std::cout << "The chosen Strategist is Luna Snow" << '\n';
        }else if(strategist == 3){
            std::cout << "The chosen Strategist is Gambit" << '\n';
        }else if(strategist == 4){
            std::cout << "The chosen Strategist is Deadpool" << '\n';
        }else if(strategist == 5){
            std::cout << "The chosen Strategist is Invisible Woman" << '\n';
        }else if(strategist == 6){
            std::cout << "The chosen Strategist is Jeff the Land Shark" << '\n';
        }else if(strategist == 7){
            std::cout << "The chosen Strategist is Cloak & Dagger" << '\n';
        }else{
            std::cout << "The chosen Strategist is Adam Warlock" << '\n';
        }

        std::cout << "Do you want to reroll your character?" << '\n';
        std::cout << "Yes or no?" << '\n';
        std::cin >> answer;

        if(answer == "no"){
        break;
    }
}
}
