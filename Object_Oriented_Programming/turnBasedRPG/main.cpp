#include "Game.h"
#include <iostream>
#include <cstdlib>  
#include <ctime> 

int main() {
    srand(time(0));

    bool weaponChoice, playerChoice;
    std::cout << "Select weapon (0 for Sword, 1 for Dagger): ";
    std::cin >> weaponChoice;
    ArmoredPlayer armoredPlayer;
    HealerPlayer healerPlayer;
    armoredPlayer.selectWeapon(weaponChoice);
    healerPlayer.selectWeapon(weaponChoice);
    Game game(armoredPlayer, healerPlayer);
    std::cout << "Select player (0 for Armored, 1 for Healer): ";
    std::cin >> playerChoice;
    game.selectPlayer(playerChoice);
    while (true) {
        game.playTurn();
        if (game.getGameStatus()) break;
        char cont;
        std::cout << "Do you want to quit(press 'q') or continue(press c): ";
        std::cin >> cont;
        if(cont == 'q') break;
        else if(cont == 'c') continue;
    }
    return 0;
 }