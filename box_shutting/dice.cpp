#include "dice.h"
#include <cstdlib>
using namespace std ;

Dice::Dice()
{
numdice=2; 
  roll();
}

Dice::Dice(int n_dice)
{
  if (n_dice< 1 || n_dice>10)
    numdice=2;
      else
    numdice=n_dice;
  roll();
}

void  Dice::roll(){
  srand(time(0));
for (int i=0; i<numdice; i++){
dice[i]= rand()%6+1;}
}

int Dice::total() const{
  int sum=0;
  for (int i=0; i<numdice; i++)
    sum+=dice[i];
  return sum;
  
}

string Dice:: str() const{
string s;
    for (int i=0; i<numdice; i++){
      if(i)
        s+='-';
      s+=to_string(dice[i]);
      }
  return s;
}

int Dice::count(int x) const{
  int sum=0;
  for (int i=0; i<numdice; i++)
    if(dice[i]== x)
    sum++;
  return sum;}
