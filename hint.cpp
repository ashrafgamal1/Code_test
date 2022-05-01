#include "game1.h"
int daka::Check_for_Hint_Number() //function to get help in word search of puzzle
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

void daka::call(int& Player_Score, int& Computer_Score, string PlayerName, int roundsOfGame, unordered_map<int,string>a,double &t)
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












