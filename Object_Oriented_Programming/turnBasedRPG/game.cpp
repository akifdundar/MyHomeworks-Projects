#include "Game.h"
#include <iostream>
#include <cstdlib>

Player::Player() {
    health = 300;
    selectedWeapon = 0;
}

void Player::updateHealth(int amount) {
    health += amount;
}

void Player::attack(Enemy& enemy) {
    if(selectedWeapon) {
        dagger.attack(enemy);
    }
    else {
        sword.attack(enemy);
    }
}

bool Player::isAlive() {
    if(health > 0) return true;
    return false;
}

void Player::selectWeapon(bool selection) {
    selectedWeapon = selection;
}

void ArmoredPlayer::defend(int damage) {
    if(isFirstDefence) {
        isFirstDefence = 0;
        std::cout << "Your first defend, you dodged all damage" << 
        std::endl;
        std::cout << "You have " << health << "hp now" << std::endl;
        return;
    }
    damage = damage * 8.0 / 10;
    updateHealth(-damage);
    std::cout << "You have " << health << "hp now" << std::endl;
}

void HealerPlayer::defend(int damage) {
    if(rand() % 100 < 5) {
        updateHealth(damage);
        std::cout << "Woww you are lucky!! Now you can heal yourself" << std::endl;
        std::cout << "You have " << health << "hp now" << std::endl;
        return;
    }
    updateHealth(-damage);
    std::cout << "You have " << health << "hp now" << std::endl;
}

Enemy::Enemy() {
    health = 300;
    baseDamage = 40;
}

void Enemy::defend(int damage) {
    updateHealth(-damage);
    std::cout << "Your enemy has " << health << "hp now" << std::endl;
}

bool Enemy::isAlive() {
    if(health > 0) return true;
    return false;
}

int Enemy::getBaseDamage() {
    return baseDamage;
}

void Enemy::updateHealth(int amount) {
    health += amount;
}

Weapon::Weapon() {
    damage = 40;
}

void Weapon::updateDamage(int amount) {
    damage += amount;
}

Sword::Sword() {
    damage = 60;
}

void Sword::attack(Enemy& enemy) { 
    std::cout << "Your strike: " << damage << std::endl;
    enemy.defend(damage);
    if(damage > 30) {
        updateDamage(-5);
    }
}

Dagger::Dagger() {
    damage = 30;
}

void Dagger::attack(Enemy& enemy) {  
    std::cout << "Your strike: " << damage << std::endl;
    enemy.defend(damage); 
    if(rand() % 2 == 1) {
        std::cout << "Woww you hit again\n your strike: " << damage << std::endl;
        enemy.defend(damage);
    }
}

Game::Game(ArmoredPlayer& a, HealerPlayer& h) {
    selectedPlayer = 0;
    gameEnded = 0;
    armoredPlayer = a;
    healerPlayer = h;
}

void Game::selectPlayer(bool selection) {
    selectedPlayer = selection;  
}

void Game::playTurn() {
    // (selectedPlayer == 0) ? armoredPlayer.attack(enemy) : healerPlayer.attack(enemy);
    if(selectedPlayer) {                      
        healerPlayer.attack(enemy);
    }
    else {
        armoredPlayer.attack(enemy);
    }

    if(!enemy.isAlive()) {
        std::cout << "Game ended you won!!" << std::endl;
        gameEnded = true;
        return;
    }

    if(selectedPlayer) {
        std::cout << "Enemy strike: " << enemy.getBaseDamage() << std::endl;
        healerPlayer.defend(enemy.getBaseDamage());
    }
    else {
        std::cout << "Enemy strike: " << enemy.getBaseDamage() << std::endl;
        armoredPlayer.defend(enemy.getBaseDamage());
    }

    bool playerIsAlive = selectedPlayer == 0 ? armoredPlayer.isAlive() : healerPlayer.isAlive();

    if(!playerIsAlive) {
        std::cout << "Game ended you lost!!" << std::endl;
        return;
    }
} 

bool Game::getGameStatus() {
    return gameEnded;
}