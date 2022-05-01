#include "game1.h"
int daka::Choose_Game() //function to choose which game to play
{
    int Option;
    string line1;
    while (getline(cin, line1)) // get a line of input & repaeat if you enter invalid Hint Number
    {
        stringstream ss(line1);/* stringstream here to treat a string as stream for cin & cout &
                                to convert that string into numerical data specially Positive integers*/
        if (ss >> Option) // >> extraction operator to display ss stringstream data
        {
            if (ss.eof()&&(Option==1||Option==2||Option==3||Option==4)&&Option>0) /* eof indicates end of input of ss stringstream
                                & indicate if input number is negative or not & Options of hint to the player */
            {   // Success
                break;
            }
        }
        cout<<"Enter Only 1, 2, 3 or 4... "<<endl; // A hint for the player
    }
    return Option;
}

int daka::Enter_Number()  //function to get only numbers Positive integers and greater than 0
{
    int Number;
    string line;
    while (getline(cin, line)) // get a line of input & repaeat if you enter invalid number
    {
        stringstream ss(line); /* stringstream here to treat a string as stream for cin & cout &
                                to convert that string into numerical data specially Positive integers*/
        if (ss >> Number)     // >> extraction operator to display ss stringstream data
        {
            if (ss.eof()&&Number>0) /* eof indicates end of input of ss stringstream
                                     & indicate if input number is negative or not*/
            {   // Success
                break;
            }
        }
        cout<<"Enter Only Positive Numbers & greater than zero... "<<endl; // A hint for the player
    }
    return Number;
}


