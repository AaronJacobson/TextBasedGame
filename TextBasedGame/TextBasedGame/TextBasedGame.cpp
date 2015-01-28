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

void battle(){
	cout << "Prepare to fight! " << enemy.name << " approaches!\n";
	while (user.health > 0 && enemy.health > 0){
		cout << "It's your turn! Your health is " << user.health << " Here are your options:" << endl;
		cout << "1.) " << user.attack1name << endl << "2.) " << user.attack2name << "\n3.) Run like a wimp" << endl << "4.) Pray to the Flying Spaghetti Monster" << endl;
		string userInput;
		cin >> userInput;
		for (int i = 0; i < 100; i++){
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

void setEnemyStats(string name, int health, string a1n, string a2n, int a1d, int a2d){
	enemy.name = name;
	enemy.health = health;
	enemy.attack1name = a1n;
	enemy.attack2name = a2n;
	enemy.attack1damage = a1d;
	enemy.attack2damage = a2d;
}

void askChangeAttack(string attackName, int attackDamage){
	cout << user.name << " has leveled up!\n";
	cout << "...\n";
	for (int i = 0; i < 1000000; i++){
	}
	cout << "...\n";
	for (int i = 0; i < 1000000; i++){
	}
	cout << "...\n";
	reAsk:
	cout << user.name << " wants to learn a new move, " << attackName << ". Should " << user.name << " learn " << attackName << "?\n";
	cout << "1.) Yes" << "\n 2.) No\n";
	string input;
	cin >> input;
	if (input == "1"){

		cout << "Which move should " << user.name << " forget?\n";
		cout << "1.) " << user.attack1name << endl << "2.) " << user.attack2name << endl << "3.) Nevermind...\n";
		string secIn;
		cin >> secIn;
		if (secIn == "1"){

		}
		else if(secIn == "2"){

		}
		else{

		}
	}
	else if (input == "2"){
		cout << user.name << " did not learn " << attackName << endl;
	}
	else{
		goto reAsk;
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	start:
	user.health = 15;
	user.attack1name = "Punch";
	user.attack1damage = 2;
	user.attack2name = "Kick";
	user.attack2damage = 3;
	setEnemyStats("Jim the Peasant", 10, "Punch", "Kick",2,3);
	cout << "Please enter your name.  ";
	cin >> user.name;
	cout << user.name << ", you are a gladiator in an unknown land..." << endl;
	battle();
	setEnemyStats("A wimpy kobold", 5, "Feather Slap", "Paper", 0, 1);
	if (user.health > 0){
		battle();
	}
	setEnemyStats("A towering ogre", 30, "Club", "Stomp", 4, 3);
	user.attack1name = "The feather of the Flying Spaghetti Monster";
	user.attack1damage = 5;
	if (user.health > 0){
		battle();
	}
	user.attack2name = "An ogre's club";
	user.attack2damage = 6;
	setEnemyStats("A wall of flesh", 50, "Lazor Eye Beam", "Flying Eye", 5, 2);
	if (user.health > 0){
		battle();
		cout << "Inside the remains of the wall of flesh you find some kind of gun. Do you take it?\n";
		//cout << "1.) Take it"
	}

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