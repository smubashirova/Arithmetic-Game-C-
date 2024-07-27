// Author: Shokhsanam Mubashirova
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 3 Task C
// This program is about arithmetic game


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

int main()
{
    string fileName = "problems.csv";
    ifstream fin(fileName);
    if (fin.fail()) 
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); 
    }
    string txt;
    string ans;
    int numQuestions = 0;
    int numCorrect = 0;
    while (getline(fin, txt, ',') && getline(fin, ans))
    {
        cout<<"Question "<<numQuestions<<": "<<txt<<endl;
        double reply;
        cout<<"Your answer: ";
        cin>>reply;
        double correctAnswer = stof(ans);
        cout << boolalpha << (reply == correctAnswer) << endl;
        if(reply==correctAnswer)
        {
            numCorrect++;
        }
        numQuestions++;
    }

    fin.close();

    double percentage;
    char grade;

    percentage=(double) numCorrect/numQuestions*100;

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





