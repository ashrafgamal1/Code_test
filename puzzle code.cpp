// Word Search Puzzle Game
// Find Number of occurrences of certain letter in a puzzle
// Data Structures used : Hash tables , Binary Search Tree with preorder traversal & 2d arrays
#include<iostream>
#include<cstdlib>        // rand & srand
#include<cstring>
#include<ctime>          // clock()
#include<limits>
#include<unordered_map>  // Hash tables
#include<sstream>        // stringstream
#include<cctype>         // isalpha()
#include<time.h>         // setprecision
#include<bits/stdc++.h>

using namespace std;

const int N=10;  // puzzle matrix size
string getLetters(); //function to get a correct name of the player without any number
int Enter_Number();  //function to get only numbers Positive integers and greater than 0
int Enter_Age();     //function to get age of the player which is only numbers Positive , >0 & <100
int Check_for_Hint_Number();   //function to get help in word search of puzzle
int Choose_Game();            //function to choose which game to play
int call(int& , int& , string ,int,unordered_map<int,string>a,double &);   /*function includes first
                                                                           puzzle game which is Countries or general words*/
void Welcome_NewPlayer(string);     // function includes welcome message for players
class Node         // class  to make a node for bst
{
    public:
    char data;
    Node* left;
    Node* right;
};
class Find_Number_Occurrences  // Second Game Find the Number of Occurrences in a matrix puzzle
{
  public:
  double Display_2DArray(char arr2D[N][N],double& time2)     //function to display random matrix
  {
    clock_t start2,end2; // Create the start and end to measure the execution time of certain block of code
    start2=clock();      //clock() returns the approximate processor time that is consumed by the code
    srand(time(0));      //function to get random numbers and characters in the matrix in each attempt
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            char c;
            int r;
            r= rand() % 26;   // generate a random number
            c= 'a' + r;       // Convert to a character from a-z
            arr2D[i][j]=c;
        }}
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
          cout<<arr2D[i][j]<<" "; // display our puzzle to Players
        }
        cout<<endl;
    }
     end2=clock();       //end time calculation
     time2 =double(end2-start2)/double(CLOCKS_PER_SEC); // time in seconds
      return time2;  // return time of dispalying puzzle matrix to our main program
    }
   double Copy_Elements(char arr2D[N][N],char arr1D[N*N],double& time3) /* function to Copy Elements
                                                                            of our puzzle matrix */
  {
    clock_t start3,end3;
    start3=clock();  //start calculatimg the time
        int index=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            arr1D[index++]=arr2D[i][j]; //Copy Elements to a 1D Array
        } }
    cout<<endl;
    end3=clock();    //end calculation
    time3 =double(end3-start3)/double(CLOCKS_PER_SEC);
      return time3;  // return time of copy elements of our matrix
    }
   double bubbleSort_Array(char arr1D[N*N],double& time4) //function for sorting
   {
    clock_t start4,end4;
    start4=clock();//start calculation the time taken in the function
    for(int i=0;i<(N*N);i++)
    {
        for(int j=i+1;j<(N*N);j++)
        {
            if(arr1D[i]>arr1D[j])
            {
                int temp = arr1D[i];
                arr1D[i]=arr1D[j];
                arr1D[j]=temp;
            } } }
    end4=clock();//end calculation
    time4 =double(end4-start4)/double(CLOCKS_PER_SEC);
    return time4;
   }
    Node* newNode(char data)//binary search tree
    {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
    }
    Node* sortedArrayToBST(char arr1D[N*N],int start, int end,double& time5)//function takes the elements in the array and put them in binary search tree
    {
    clock_t start5,end5;
    start5=clock();//start calculation the time taken in the function
    /* Base Case */
    if (start > end)
    return NULL;
    /* Get the middle element and make it root */
    int mid = (start + end)/2;
    Node *root = newNode(arr1D[mid]);
    /* Recursively construct the left subtree
    and make it left child of root */
    root->left = sortedArrayToBST(arr1D, start,mid - 1,time5);
    /* Recursively construct the right subtree
    and make it right child of root */
    root->right = sortedArrayToBST(arr1D, mid + 1, end,time5);
    end5=clock();//end calculation
    time5 =double(end5-start5)/double(CLOCKS_PER_SEC);
    return root;
    }
    double preOrder_And_FindOccurrence(Node* node,char y,int& counts,double& time6)//function includes second puzzle game which is number of occurrence game
    {
    clock_t start6,end6;
    start6=clock();//start calculation the time taken in the function
    if (node == NULL)
       return 0 ;
    else
    {
    if ((node->data)==y)
        counts++;
    preOrder_And_FindOccurrence(node->left,y,counts,time6);//function calls itself with left node
    preOrder_And_FindOccurrence(node->right,y,counts,time6);//function calls itself with right node
    }
    end6=clock();//end calculation
    time6 =double(end6-start6)/double(CLOCKS_PER_SEC);
    return time6;
    return counts;
    }
};
int main()
{   double Total_Time_taken1=0.0,Total_Time_taken2=0.0,Total_Time_taken3=0.0,Total_Time_taken4=0.0,Total_Time_taken5=0.0,Total_Time_taken6=0.0;
    int Age,rounds;
    char a;
    char decision;
    int Scores1=0,Scores2=0;
    string PlayerName;
    cout<<"\t\t\t*Word Search Puzzle Game*\n\n"<<endl;
    cout<<"Enter name  :      ";
    PlayerName=getLetters();
    cout<<endl;
    cout<<"Enter Your Age :       "<<endl;
    Age=Enter_Age();
    srand(time(0));//function to get random numbers and characters in the matrix in each attempt
    do
    {
    Welcome_NewPlayer(PlayerName);
    cout<<"Choose Game You Want "<<endl;
    cout<<"Enter 1 for States & Countries or 2 for General Words or 3 for Cars"<<endl;
    cout<<"Enter 4 for Number of Occurrence Game "<<endl;
    int Game=Choose_Game();
    if(Game==1)
    {
    unordered_map<int,string>states{{0,"Egypt"},{1,"England"},{2,"Palestine"},{3,"France"},{4,"Germany"},{5,"China"},{6,"Morocco"},{7,"Italy"},{8,"Japan"},{9,"Brazil"}};
   //Hash table
    cout<<"Enter Number of rounds :  "<<endl;
    rounds=Enter_Number();//take number of rounds the user wants to play
    cout<<endl;
    call(Scores1,Scores2,PlayerName,rounds,states,Total_Time_taken1);
    }
    else if(Game==2)
    {
    unordered_map<int,string>general{{0,"Efficient"},{1,"Learning"},{2,"World"},{3,"Hello"},{4,"Name"},{5,"Jani"},{6,"Share"},{7,"Complete"},{8,"Global"},{9,"Comment"}};
   //Hash table
    cout<<"Enter Number of rounds :  "<<endl;
    rounds=Enter_Number();//take number of rounds the user wants to play
    cout<<endl;
    call(Scores1,Scores2,PlayerName,rounds,general,Total_Time_taken1);
    }
    else if(Game==3)
    {
    unordered_map<int,string>cars{{0,"Kia"},{1,"Honda"},{2,"Mercedes"},{3,"Bmw"},{5,"Dodge"},{6,"Ford"},{7,"Hyundai"},{9,"Toyota"}};
   //Hash table
    cars[7]="Suzuki";
    cars[4]="Chevrolet";
    cout<<"Enter Number of rounds :  "<<endl;
    rounds=Enter_Number();//take number of rounds the user wants to play
    cout<<endl;
    call(Scores1,Scores2,PlayerName,rounds,cars,Total_Time_taken1);
    }
    else
    {
    Find_Number_Occurrences Game2;
    char arr2D[N][N];
    char arr1D[N*N];
    int counts=0;
    Game2.Display_2DArray(arr2D,Total_Time_taken2);//function to display random matrix
    Game2.Copy_Elements(arr2D,arr1D,Total_Time_taken3);//
    Game2.bubbleSort_Array(arr1D,Total_Time_taken4);//function for sorting
    Node *root = Game2.sortedArrayToBST(arr1D,0,N*N-1,Total_Time_taken5);//function takes the elements in the array and put them in binary search tree
    srand(time(0));//function to get random numbers and characters in the matrix in each attempt
    int x=rand()%26;
    char key= 'a' + x;
    Game2.preOrder_And_FindOccurrence(root,key,counts,Total_Time_taken6);//function includes second puzzle game which is number of occurrence game
    int Number_Of_Occurrences=counts;
    cout<<endl<<endl;
    cout<<"Enter Your Guess About Number Of Occurrences Of "<<key<<" :   "<<endl;
    int Guess_Occurrence=Enter_Number();
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

int call(int& Player_Score, int& Computer_Score, string PlayerName, int roundsOfGame, unordered_map<int,string>a,double &t)
{   clock_t start2,end2,start3,end3;
    t=0.0;
    start2=clock();
    string lines;
    string output;
    for(int final_round=1; final_round<=roundsOfGame; final_round++)
    {
        cout<<" Round :  "<<final_round<<endl;
    char arr[N][N];
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            char c;
            int r;
            r= rand() % 26;   // generate a random number
            c= 'a' + r;            // Convert to a character from a-z
            arr[i][j]=c;
        }
    }
    int index=rand()%10;
    output=a[index];
    if(a[index].length()%2==0)
    {
        // for even string length case
            int row=rand()%10;
            int col=rand()%3;
            for(int i=0;a[index][i]!='\0';i++,col++)
            {
                arr[row][col]=a[index][i];
            }
    }
    else
    {
        // for odd string length case
            int row=rand()%3;
            int col=rand()%10;
            for(int i=0;a[index][i]!='\0';i++,row++)
            {
                arr[row][col]=a[index][i];
            }
    }
     for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
          cout<<" "<<arr[i][j];
        }
        cout<<endl;
    }

    string guess,Computer_Guess;
    cout<<"Player Turn"<<endl;
	cout<<"Press 1 for Guess word without Help	"<<endl;
	cout<<"Press 2 for Size Hint and then guess word	"<<endl;
	cout << "Enter an int 1 or 2: "<<endl;
    end2=clock();

	int hint=Check_for_Hint_Number();
	cout<<"you entered valid hint number : "<< hint <<endl;
	if(hint==1)

	{
      cout<<"Enter word you guess         :       ";
      cin>>guess;
      cout<<endl;
	}
    else
    {
       cout<<"Guessed word in puzzle size is  :       ";
       cout<<output.size();
       cout<<endl;
       cout<<"Enter word you guess         :       ";
       cin>>guess;
       cout<<endl;
    }
    start3=clock();
    if(guess==a[index])
    {
        cout<<"Congratulations ! You have guessed correct word  "<<endl;
        Player_Score+=5;
    }
    else
    {
        cout<<"Sorry ! Your guessed word is incorrect.Try again next turn "<<endl;
    }
    Computer_Guess=a[rand()%10];
    cout<<endl;
    cout<<"Computer Turn "<<endl;
    cout<<"Computer Guess   :      "<<Computer_Guess<<endl;
    if(Computer_Guess==a[index])
    {
       cout<<"Oops computer Guess as You Be careful! "<<endl;
       Computer_Score+=5;
    }
    else
    {
       cout<<"Lucky Player computer guess is incorrect "<<endl;
    }
    cout<<endl;
    cout<<PlayerName<<" Score   : "<<Player_Score<<endl<<"Computer Score   : "<<Computer_Score<<"\n";
    }
    end3=clock();
    double time_2=double(end2-start2)/double(CLOCKS_PER_SEC);
    double time_3=double(end3-start3)/double(CLOCKS_PER_SEC);
    t=time_2+time_3;

}

void Welcome_NewPlayer(string Name) // function includes welcome message for players
{
    cout<<"Welcome to our nice puzzle game "<<Name<<endl;
    cout<<"You have to guess the word in this puzzle"<<endl;
    cout<<"You can also take help for hint from the system"<<endl<<endl;
}
int Enter_Number()  //function to get only numbers Positive integers and greater than 0
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
int Enter_Age() //function to get age of the player which is only numbers Positive , >0 & <100
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
string getLetters() //function to get a correct name of the player without any number
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
int Check_for_Hint_Number() //function to get help in word search of puzzle
{
    int hint;
    string line1;
    while (getline(cin, line1)) // get a line of input & repaeat if you enter invalid Hint Number
    {
        stringstream ss(line1);/* stringstream here to treat a string as stream for cin & cout &
                                to convert that string into numerical data specially Positive integers*/
        if (ss >> hint) // >> extraction operator to display ss stringstream data
        {
            if (ss.eof()&&(hint==1||hint==2)&&hint>0) /* eof indicates end of input of ss stringstream
                                & indicate if input number is negative or not & Options of hint to the player */
            {   // Success
                break;
            }
        }
        cout<<"Enter Only 1 or 2... "<<endl; // A hint for the player
    }
    return hint;
}
int Choose_Game() //function to choose which game to play
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
