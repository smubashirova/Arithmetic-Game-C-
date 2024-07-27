// Author: Shokhsanam Mubashirova
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 3 Task A
// This program is about arithmetic game


#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

int main()
{
    char ops[] = {'+', '-', '*', '/', '%'};
    int size = sizeof(ops) / sizeof(ops[0]);
    int index = rand()%5;
    char currOp = ops[index];
    int num = rand() % 10; //generate a random int in [0, 9]
    int num2;
    if (currOp == '/' || currOp == '%')
       num2 = rand() % 9 + 1;  //a random int in [1, 9]
    else 
       num2 = rand() % 10; //random int in [0, 9]
    cout<<"what is "<<num<<" "<<currOp<<" "<<num2<<"? ";
    int input;
    cin>>input;
    int answer;
    if(currOp == '+')
    {
        answer=num+num2;
    }
    if(currOp == '-')
    {
        answer=num-num2;
    }
    if(currOp == '*')
    {
        answer=num*num2;
    }
    if(currOp == '/')
    {
        answer=num/num2;
    }
    if(currOp == '%')
    {
        answer=num%num2;
    }
    cout << boolalpha << (input == answer) << endl;
    return 0;
}







