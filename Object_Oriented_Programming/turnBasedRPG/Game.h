#ifndef GAME_H
#define GAME_H

#include <iostream>

class Enemy {
    private: 
        int baseDamage;
    
    public:
        Enemy();
        void defend(int damage);
        bool isAlive();
        int getBaseDamage();
    
    protected:
        int health;
        void updateHealth(int amount);
};

class Weapon {
    public: 
        Weapon();

    protected:
        int damage;
        void updateDamage(int amount);  
};

class Sword : public Weapon {
    public:
        Sword();
        void attack(Enemy& enemy);
};

class Dagger : public Weapon {
    public:
        Dagger();
        void attack(Enemy& enemy);
};

class Player {
    protected:
        int health;
        void updateHealth(int amount);
    
    private:
        Sword sword; // 0
        Dagger dagger; // 1
        bool selectedWeapon;
    
    public:
        Player();
        void attack(Enemy& enemy);
        bool isAlive();
        void selectWeapon(bool selection);
};

class ArmoredPlayer : public Player {
    public:
        void defend(int damage);

    protected: 
        bool isFirstDefence;
};

class HealerPlayer : public Player {
    public:
        void defend(int damage);
};

class Game {
    private: 
        ArmoredPlayer armoredPlayer;
        HealerPlayer healerPlayer;
        bool selectedPlayer;
        Enemy enemy;
        bool gameEnded;

    public: 
        Game(ArmoredPlayer& a, HealerPlayer& h);
        void selectPlayer(bool selection);
        void playTurn();
        bool getGameStatus();
};

#endif