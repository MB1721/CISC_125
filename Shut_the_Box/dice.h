#pragma once

#include <string>

class Dice{
private:
int dice[10];
int numdice;
public:
Dice();
Dice(int n_dice);//Dice(int n_dice=2) gets rid of default constructors

void roll();
int total()const;
int count()const {return numdice;}//number of dice in function
int count(int value)const;//number of dice in collection with the parameter number
int die(int index)const{return dice[index];}
std::string str()const; 
};
