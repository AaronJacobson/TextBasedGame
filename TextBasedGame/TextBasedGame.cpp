// TextBasedGame.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;

struct Monster{
	string name;
	int health;
	string attack1name;
	string attack2name;
	int attack1damage;
	int attack2damage;
};
Monster user;
Monster enemy;

int randomNumber;


void waitABit(){
	for (int i = 0; i < 500000000; i++){
	}
	cout << "...\n";
	for (int i = 0; i < 500000000; i++){
	}
	cout << "...\n";
	for (int i = 0; i < 500000000; i++){
	}
	cout << "...\n";
	for (int i = 0; i < 500000000; i++){
	}
}

void battle(){
	if (user.health > 0){
		cout << "Prepare to fight! " << enemy.name << " approaches!\n";
		while (user.health > 0 && enemy.health > 0){
			cout << "It's your turn! Your health is " << user.health << " Here are your options:" << endl;
			cout << "1.) " << user.attack1name << endl << "2.) " << user.attack2name << "\n3.) Run like a wimp" << endl << "4.) Pray to the Flying Spaghetti Monster" << endl;
			string userInput;
			cin >> userInput;
			for (int i = 0; i < 25; i++){
				cout << endl;
			}
			if (userInput == "1"){
				cout << "You used " << user.attack1name << " dealing " << user.attack1damage << " damage!\n";
				enemy.health -= user.attack1damage;
			}
			else if (userInput == "2"){
				cout << "You used " << user.attack2name << " dealing " << user.attack2damage << " damage!\n";
				enemy.health -= user.attack2damage;
			}
			else if (userInput == "3"){
				cout << "Can't escape you coward!\n";
			}
			else if (userInput == "4"){
				if (user.health >= enemy.health * 1.5){
					cout << "His noodlyness has smited you! You lose 3 health! ";
					user.health -= 3;
				}
				else{
					cout << "His noodlyness has graced you! You gain some health. ";
					user.health += enemy.health * .25;
				}
			}
			else{
				cout << "You fail to do anything!\n";
			}
			randomNumber = rand() % 2 + 1;
			if (randomNumber == 1){
				cout << enemy.name << " used " << enemy.attack1name << " dealing " << enemy.attack1damage << " damage!\n";
				user.health -= enemy.attack1damage;
			}
			else{
				cout << enemy.name << " used " << enemy.attack2name << " dealing " << enemy.attack2damage << " damage!\n";
				user.health -= enemy.attack2damage;
			}
		}
		if (user.health > 0){
			cout << "You have defeated " << enemy.name << "!\n";
		}
		else{
			cout << "U r ded.\n";
		}
	}
}

void setEnemyStats(string name, int health, string a1n, string a2n, int a1d, int a2d){
	enemy.name = name;
	enemy.health = health;
	enemy.attack1name = a1n;
	enemy.attack2name = a2n;
	enemy.attack1damage = a1d;
	enemy.attack2damage = a2d;
}

void askChangeAttack(string attackName, int attackDamage){
	if (user.health > 0){
		cout << user.name << " has leveled up!\n";
		waitABit();
	reAsk:
		cout << user.name << " wants to learn a new move, " << attackName << ".\nShould " << user.name << " learn " << attackName << "?\n";
		cout << "1.) Yes" << "\n2.) No\n";
		string input;
		cin >> input;
		if (input == "1"){
		forget:
			cout << "Which move should " << user.name << " forget?\n";
			cout << "1.) " << user.attack1name << endl << "2.) " << user.attack2name << endl << "3.) Nevermind...\n";
			string secIn;
			cin >> secIn;
			if (secIn == "1"){
				cout << user.name << " has forgotten " << user.attack1name << " and has learned " << attackName << " in its place.\n";
				user.attack1name = attackName;
				user.attack1damage = attackDamage;
			}
			else if (secIn == "2"){
				cout << user.name << " has forgotten " << user.attack2name << " and has learned " << attackName << " in its place.\n";
				user.attack2name = attackName;
				user.attack2damage = attackDamage;
			}
			else if (secIn == "3"){
				goto nevermind;
			}
			else{
				goto forget;
			}
		}
		else if (input == "2"){
		nevermind:
			cout << user.name << " did not learn " << attackName << endl;
		}
		else{
			goto reAsk;
		}
	}
}

void resetUserStats(){
	user.health = 15;
	user.attack1name = "Punch";
	user.attack1damage = 2;
	user.attack2name = "Kick";
	user.attack2damage = 3;
}

void beginGame(){
	cout << "Please enter your name.  ";
	cin >> user.name;
	cout << user.name << ", you are a gladiator in an unknown land..." << endl;
	cout << "Type the number of the option which you wish to use.\n";
}
int _tmain(int argc, _TCHAR* argv[])
{
	start:
	resetUserStats();
	beginGame();
	setEnemyStats("Jim the Peasant", 10, "Punch", "Kick",2,3);
	battle();
	setEnemyStats("A wimpy kobold", 5, "Feather Slap", "Paper", 0, 1);
	battle();
	setEnemyStats("A towering ogre", 30, "Club", "Stomp", 4, 3);
	askChangeAttack("Feather swipe of the Flying Spaghetti Monster", 5);
	battle();
	askChangeAttack("Ogre's club smash", 6);
	setEnemyStats("A wall of flesh", 50, "Lazor Eye Beam", "Flying Eye", 5, 2);
	battle();
	if (user.health > 0){
		cout << "As the wall of flesh collapses a glow appears around you.\nA bright flash blinds you for half a second.\nAs you come to your senses you see a minishark machine gun.\n";
	}
	askChangeAttack("Minishark barrage", 8);
	setEnemyStats("A mindless zombie", 15, "Bite", "Punch", 5, 3);
	battle();
	if (user.health > 0){
		cout << "After you slay the zombie which jumped down on you, you look up to find that a horde of zombies is approaching.\n";
		cout << "You start running in the oppisite direction to find a pirate airship off in the distance, you decide it's best to go there.\n";
		cout << "Even if they are filthy pirates.\n";
	}
	setEnemyStats("Avian pirate", 30, "Cutlass", "Pistol", 4, 6);
	battle();
	if (user.health > 0){
		cout << "You make your way to the helm of the ship to find the captain, he takes his hands off the wheel and charges at you.\n";
	}
	setEnemyStats("Avian pirate captain", 50, "Glowing Cutlass", "Pistol", 7, 5);
	battle();
	askChangeAttack("Glowing Cutlass", 9);
	if (user.health > 0){
		cout << "You take the helm and fly the ship away from the horde of zombies.\n";
		waitABit();
		cout << "Due to your excellent piloting skills, you crash the ship into a river.\n";
	}
	setEnemyStats("Boat Elemental", 60, "Smash", "Smash", 8, 6);
	battle();

	if (user.health > 0){
		cout << "You have fought your way to freedom!\n";
	}
	question:
	cout << "Do you want to play again?\n1. Yes\n2. No\n";
	string userInput;
	cin >> userInput;
	if (userInput == "1"){
		goto start;
	}
	else if (userInput == "2"){
		return 0;
	}
	else{
		goto question;
	}
}