// Author: Shokhsanam Mubashirova
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 3 Task B
// This program is about arithmetic game


#include <iostream>
#include <cstdlib>
#include <random>
using namespace std;

int main()
{
    char ops[] = {'+', '-', '*', '/', '%'};
    int size = sizeof(ops) / sizeof(ops[0]);
    
    int numQuestions;
    cout<<"Enter the total number of questions to ask: ";
    cin>>numQuestions;


    while(numQuestions<=0)
    {
        cout << "The number of questions cannot be zero or negative. Re-enter: ";
        cin>>numQuestions;
    }

        int correct=0;

    for(int i=0; i<numQuestions; i++)
    {
        int index = rand()%5;
        char currOp = ops[index];
        int num = rand() % 10; //generate a random int in [0, 9]
        int num2;
        if (currOp == '/' || currOp == '%')
            num2 = rand() % 9 + 1;  //a random int in [1, 9]
        else 
             num2 = rand() % 10; //random int in [0, 9]
        
        cout<<"what is "<<num<<" "<<currOp<<" "<<num2<<"? ";

        int reply;
        cin>>reply;
        int answer;

        if(currOp == '+')
        {
            answer=num+num2;
        }
        else if(currOp == '-')
        {
            answer=num-num2;
        }
        else if(currOp == '*')
        {
            answer=num*num2;
        }
        else if(currOp == '/')
        {
            answer=num/num2;
        }
        else if(currOp == '%')
        {
            answer=num%num2;
        }

        if(reply==answer)
            correct++;

        cout << boolalpha << (reply == answer) << endl;
    }
       
    double percentage;
    char grade;

    percentage=(double) correct/numQuestions*100;

    if(percentage>=90)
    {
        grade='A';
    }
    else if(percentage>=80)
    {
        grade='B';
    }
    else if(percentage>=70)
    {
        grade='C';
    }
    else if(percentage>=60)
    {
        grade='D';
    }
    else
    {
        grade='F';
    }
    

    cout<<"percentage correct: "<<percentage<<"%"<<endl;
    cout<<"letter grade: "<<grade<<endl;
    return 0;

}
