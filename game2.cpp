#include "game2.h"

double Find_Number_Occurrences::Display_2DArray(char arr2D[N][N],double& time2)     //function to display random matrix
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

double Find_Number_Occurrences::Copy_Elements(char arr2D[N][N],char arr1D[N*N],double& time3) /* function to Copy Elements
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

double Find_Number_Occurrences::bubbleSort_Array(char arr1D[N*N],double& time4) //function for sorting
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

Node* Find_Number_Occurrences::newNode(char data)//binary search tree
    {
    Node* node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
    }

Node* Find_Number_Occurrences::sortedArrayToBST(char arr1D[N*N],int start, int end,double& time5)//function takes the elements in the array and put them in binary search tree
    {
    clock_t start5,end5;
    start5=clock();//start calculation the time taken in the function
    if (start > end) // Base Case
    return NULL;
    int mid = (start + end)/2; // Get the middle element and make it root
    Node *root = newNode(arr1D[mid]);
    root->left = sortedArrayToBST(arr1D, start,mid - 1,time5); /* Recursively construct the left subtree
                                                                and make it left child of root */
    root->right = sortedArrayToBST(arr1D, mid + 1, end,time5);/* Recursively construct the right subtree
                                                                and make it right child of root */
    end5=clock();//end calculation
    time5 =double(end5-start5)/double(CLOCKS_PER_SEC);
    return root;
    }

double Find_Number_Occurrences::preOrder_And_FindOccurrence(Node* node,char y,int& counts,double& time6)//function includes second puzzle game which is number of occurrence game
    {
    clock_t start6,end6;
    start6=clock();//start calculation the time taken in the function
    if (node == NULL)
       return 0 ;
    else
    {
    if ((node->data)==y)
        counts++; //count its occurrence
    preOrder_And_FindOccurrence(node->left,y,counts,time6);   //function calls itself with left node
    preOrder_And_FindOccurrence(node->right,y,counts,time6);  //function calls itself with right node
    }
    end6=clock();//end calculation
    time6 =double(end6-start6)/double(CLOCKS_PER_SEC);
    return time6;
    return counts;
    }

