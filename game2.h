#ifndef GAME2_H_INCLUDED
#define GAME2_H_INCLUDED
#include "node.h"

class Find_Number_Occurrences  // Second Game Find the Number of Occurrences in a matrix puzzle
{
  public:

  double Copy_Elements(char arr2D[N][N],char arr1D[N*N],double& time3); /* function to Copy Elements
                                                                        of our puzzle matrix */
  double Display_2DArray(char arr2D[N][N],double& time2) ;    //function to display random matrix
  double bubbleSort_Array(char arr1D[N*N],double& time4); //function for sorting
  Node* newNode(char data);//binary search tree
  Node* sortedArrayToBST(char arr1D[N*N],int start, int end,double& time5);//function takes the elements in the array and put them in binary search tree
  double preOrder_And_FindOccurrence(Node* node,char y,int& counts,double& time6);//function includes second puzzle game which is number of occurrence game

};

#endif // GAME2_H_INCLUDED
