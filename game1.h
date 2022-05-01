#ifndef GAME1_H_INCLUDED
#define GAME1_H_INCLUDED
#include "node.h"

class daka {
    public:
void Welcome_NewPlayer(string);     // function includes welcome message for players
int Enter_Number();  //function to get only numbers Positive integers and greater than 0
string getLetters(); //function to get a correct name of the player without any number
int Enter_Age();     //function to get age of the player which is only numbers Positive , >0 & <100
int Check_for_Hint_Number();   //function to get help in word search of puzzle
int Choose_Game();            //function to choose which game to play
void call(int& , int& , string ,int,unordered_map<int,string>a,double &);   /*function includes firs tpuzzle game which is Countries or general words*/
};

#endif // GAME1_H_INCLUDED
