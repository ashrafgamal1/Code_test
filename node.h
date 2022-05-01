#ifndef NODE_H_INCLUDED
#define NODE_H_INCLUDED
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
class Node         // class  to make a node for bst
{
    public:
    char data;
    Node* left;
    Node* right;
};


#endif // NODE_H_INCLUDED
