#include "game1.h"
void daka::Welcome_NewPlayer(string Name) // function includes welcome message for players
{
    cout<<"Welcome to our nice puzzle game "<<Name<<endl;
    cout<<"You have to guess the word in this puzzle"<<endl;
    cout<<"You can also take help for hint from the system"<<endl<<endl;
}

string daka::getLetters() //function to get a correct name of the player without any number
{
    string input;
    bool valid;

    do
    {
        getline(cin,input);       // get a line of input
        valid = true;                       // assume it's valid
        for(auto& i : input)                // check each character in the input string
        {
            if(!isalpha(i))            // is it an alphabetical character?
            {
                valid = false;              // if not, mark it as invalid
                                    // print an error to the user
                cout << "Invalid input.  Please input only alphabetical characters." << endl;
                break;              // break out of the for() loop, as we have already established the input is invalid
            }
        }
    }while(!valid);     // keep going until we get input that's valid

    return input;       // once we have valid input, return it
}

int daka::Enter_Age() //function to get age of the player which is only numbers Positive , >0 & <100
{
    int Age;
    string line;
    while (getline(cin, line)) // get a line of input & repaeat if you enter invalid Age
    {
        stringstream ss(line); /* stringstream here to treat a string as stream for cin & cout &
                                to convert that string into numerical data specially Positive integers*/
        if (ss >> Age)    // >> extraction operator to display ss stringstream data
        {
            if (ss.eof()&& Age>0 && Age<100)/* eof indicates end of input of ss stringstream
                                        & indicate if input number is negative or not & range of Age */
            {   // Success
                break;
            }
        }
        cout<<"Enter Positive Numbers & >0 &<100 ... "<<endl; // A hint for the player
    }
    return Age;
}
