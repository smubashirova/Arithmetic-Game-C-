// Author: Shokhsanam Mubashirova
// Course: CSCI-135
// Instructor: Tong Yi
// Assignment: Project 3 Task D
// This program is about arithmetic game


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

const int CAPACITY=20;
string txt[CAPACITY];
string ans[CAPACITY];

int main()
{
    srand(time(nullptr));
    int size=0;
    string fileName = "problems.csv";
    ifstream fin(fileName);
    if (fin.fail()) 
    {
        cerr << "File cannot be opened for reading." << endl;
        exit(1); 
    }

    string line;
    while (getline(fin, line) && size < CAPACITY)
    { 
        size_t pos = line.find(','); 
        if (pos != string::npos) {
            txt[size] = line.substr(0, pos); 
            ans[size] = line.substr(pos + 1); 
            size++; 
        }
    }
    fin.close();

    int problemsToWork = size;
    int numCorr = 0;
    double percent = 0.0;
    int chosen;
    string reply; 

    while (problemsToWork > 0 && percent < 60)
    {
    chosen = rand() % problemsToWork; 
    cout << txt[chosen] << endl; 
    cout << "Your answer: ";
    cin >> reply; 
    if (reply == ans[chosen])
    {
    cout << "true" << endl;
    numCorr++; 
    percent = static_cast<double>(numCorr) / size * 100;
    } 
    else
    {
        cout<<"false"<<endl;
    }

    swap(txt[chosen], txt[problemsToWork - 1]); 
    swap(ans[chosen], ans[problemsToWork - 1]); 
    problemsToWork--; 
    }
    cout << "percent: " << percent << "%"<< endl; 

    return 0;

}


   


    