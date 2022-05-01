// Word Search Puzzle Game
// Find Number of occurrences of certain letter in a puzzle
// Data Structures used : Hash tables , Binary Search Tree with preorder traversal & 2d arrays
#include "node.h"
#include "game2.h"
#include "game1.h"
using namespace std;

int main()
{   double Total_Time_taken1=0.0,Total_Time_taken2=0.0,Total_Time_taken3=0.0,Total_Time_taken4=0.0,Total_Time_taken5=0.0,Total_Time_taken6=0.0;
    int Age, rounds;
    char decision;
    int Scores1=0,Scores2=0;
    string PlayerName;
    daka gimi ;
    cout<<"\t\t\t*Word Search Puzzle Game*\n\n"<<endl;
    cout<<"Enter name  :      ";
    PlayerName= gimi.getLetters();
    cout<<endl;
    cout<<"Enter Your Age :       "<<endl;
     Age = gimi.Enter_Age();
    srand(time(0));//function to get random numbers and characters in the matrix in each attempt
    do
    {
    gimi.Welcome_NewPlayer(PlayerName);
    cout<<"Choose Game You Want "<<endl;
    cout<<"Enter 1 for States & Countries or 2 for General Words or 3 for Cars"<<endl;
    cout<<"Enter 4 for Number of Occurrence Game "<<endl;
    int Game=gimi.Choose_Game();
    if(Game==1)
    {
    unordered_map<int,string>states{{0,"Egypt"},{1,"England"},{2,"Palestine"},{3,"France"},{4,"Germany"},{5,"China"},{6,"Morocco"},{7,"Italy"},{8,"Japan"},{9,"Brazil"}};
   //Hash table
    cout<<"Enter Number of rounds :  "<<endl;
    rounds=gimi.Enter_Number();//take number of rounds the user wants to play
    cout<<endl;
    gimi.call(Scores1,Scores2,PlayerName,rounds,states,Total_Time_taken1);
    }
    else if(Game==2)
    {
    unordered_map<int,string>general{{0,"Efficient"},{1,"Learning"},{2,"World"},{3,"Hello"},{4,"Name"},{5,"Jani"},{6,"Share"},{7,"Complete"},{8,"Global"},{9,"Comment"}};
   //Hash table
    cout<<"Enter Number of rounds :  "<<endl;
    rounds=gimi.Enter_Number();//take number of rounds the user wants to play
    cout<<endl;
    gimi.call(Scores1,Scores2,PlayerName,rounds,general,Total_Time_taken1);
    }
    else if(Game==3)
    {
    unordered_map<int,string>cars{{0,"Kia"},{1,"Honda"},{2,"Mercedes"},{3,"Bmw"},{5,"Dodge"},{6,"Ford"},{7,"Hyundai"},{9,"Toyota"}};
   //Hash table
    cars[8]="Suzuki";    // insert elements into the hash table
    cars[4]="Chevrolet";
    cout<<"Enter Number of rounds :  "<<endl;
    rounds=gimi.Enter_Number();  //take number of rounds the user wants to play
    cout<<endl;
    gimi.call(Scores1,Scores2,PlayerName,rounds,cars,Total_Time_taken1);
    }
    else
    {
    Find_Number_Occurrences Game2;
    char arr2D[N][N];
    char arr1D[N*N];
    int counts=0;
    Game2.Display_2DArray(arr2D,Total_Time_taken2);     //function to display random matrix
    Game2.Copy_Elements(arr2D,arr1D,Total_Time_taken3); //convert our matrix into sorted array
    Game2.bubbleSort_Array(arr1D,Total_Time_taken4);    //function for sorting
    Node *root = Game2.sortedArrayToBST(arr1D,0,N*N-1,Total_Time_taken5); //function takes the elements in the array and put them in binary search tree
    srand(time(0));   //function to get random numbers and characters in the matrix in each attempt
    int x=rand()%26;
    char key= 'a' + x;
    Game2.preOrder_And_FindOccurrence(root,key,counts,Total_Time_taken6); //function includes second puzzle game which is number of occurrence game
    int Number_Of_Occurrences=counts;
    cout<<endl<<endl;
    cout<<"Enter Your Guess About Number Of Occurrences Of "<<key<<" :   "<<endl;
    int Guess_Occurrence=gimi.Enter_Number();
    if(Guess_Occurrence==Number_Of_Occurrences)
    {
        cout<<"You are a Great Professional Player "<<endl;//correct answer
    }
    else
    {
        cout<<"Bad Luck, Number of Occurrence of "<<key<<" is :   "<<Number_Of_Occurrences<<endl;//false answer
        cout<<"Game Over "<<endl;//end of the game
    }
     goto label2;
    }
        if(Scores1>Scores2)
            cout<<PlayerName<<" Wins"<<endl;
        else if(Scores1<Scores2)
            cout<<"Bad Luck "<<PlayerName<<" You Lose"<<endl;
        else
            cout<<"Draw"<<endl;
        label2:
        cout<<"Write anything to play again otherwise n to exit :   ";//to continue or exit the game
        cin>>decision;
        cout<<endl;
    }while(decision!='n');//leave while loop when user enters n
    cout<<"\n\n\t Good Players Inspire Themselves, Great Players Inspire Others \n\n"<<endl;
    cout<<"time 1 = "<<fixed<<Total_Time_taken1<<setprecision(9)<<"sec."<<endl;
    cout<<"time 2 = "<<fixed<<Total_Time_taken2<<setprecision(9)<<"sec."<<endl;
    cout<<"time 3 = "<<fixed<<Total_Time_taken3<<setprecision(9)<<"sec."<<endl;
    cout<<"time 4 = "<<fixed<<Total_Time_taken4<<setprecision(9)<<"sec."<<endl;
    cout<<"time 5 = "<<fixed<<Total_Time_taken5<<setprecision(9)<<"sec."<<endl;
    cout<<"time 6 = "<<fixed<<Total_Time_taken6<<setprecision(9)<<"sec."<<endl;
    double Total_time_ofProgram=Total_Time_taken1+Total_Time_taken2+Total_Time_taken3+Total_Time_taken4+Total_Time_taken5+Total_Time_taken6;
    //get the total time in code
    cout<<"Total Time of the program = "<<Total_time_ofProgram<<setprecision(9)<<"sec."<<endl; //print all the time taken in code
    return 0;
}
