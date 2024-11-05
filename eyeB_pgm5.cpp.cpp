// eyeB_pgm5.cpp.cpp : This file contains the 'main' function. Program execution begins and ends there.


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;






int main()
{

    ifstream outFile;
    outFile.open("pgm5.txt");

    if (!outFile)
    {
        cout << "error opening file";

        return 1;
    }
    
    

    while (!outFile.eof())
    {
        string stateName[50];
        int statePopulation[50];
        double stateBudget[50];
        double stateRevenue[50];
        double stateSurplus[50];

        int numStates = 50;
        double totalBudget = 0;

        double totalRevenue = 0;

       cout << left << setw(20) 
            << "State Name" 
            << setw(15) << "Population" 
            << setw(10) << "Budget" 
            << setw(10) << "Revenue" << endl;
       cout << string(65, '-') << endl;


        for (int i = 0; i < 50; i++)
        {
            getline(outFile >> ws, stateName[i]);
            outFile >> statePopulation[i];
            outFile >> stateBudget[i];
            outFile >> stateRevenue[i];

            totalBudget += stateBudget[i];
            totalRevenue += stateRevenue[i];
            
            stateSurplus[i] = stateRevenue[i] - stateBudget[i];

            cout << left << setw(20) << stateName[i]
                << setw(15) << statePopulation[i]
                << setw(10) << stateBudget[i]
                << setw(10) << stateRevenue[i] << endl;
        }

        outFile.close();

        double averageBudget = totalBudget / numStates;
        cout << endl;
        cout << "the average budget is " << averageBudget << " billion USD" << endl;
        
        int arraySize = sizeof(stateBudget) / sizeof(stateBudget[0]);
        double highestBudget = *max_element(stateBudget, stateBudget + arraySize);
        cout << endl;
        cout << "the state with the highest Budget is California with a budget of " << highestBudget 
             << " billion USD" << endl;

        int surplusArrraySize = sizeof(stateSurplus) / sizeof(stateSurplus[0]);
        double highestSurplus = *max_element(stateSurplus, stateSurplus + surplusArrraySize);
        cout << endl;
        cout << "the state with the highest surplus is  California with a surplus of " << highestSurplus 
             << " billion USD" << endl;

        int populationArraySize = sizeof(statePopulation) / sizeof(statePopulation[0]);
        int lowestPopulation = *min_element(statePopulation, statePopulation + populationArraySize);
        cout << endl;
        cout << "the state with the lowest population is Wyoming with a population of " << lowestPopulation 
            <<  " billion people" << endl;
        
        ofstream inFile;
        inFile.open("doc for states info.txt");

        if(!inFile)
        {
            cout << "error opening file";
        }

        inFile << "The average budget is " << averageBudget 
               << " billion USD" << endl;
        inFile << "The state with the highest budget is California with a budget of " << highestBudget 
               << " billion USD" << endl;
        inFile << "The state with the highest surplus is California with a surplus of " << highestSurplus 
               << " billion USD" << endl;
        inFile << "The state with the lowest population is Wyoming with a population of " << lowestPopulation 
               << " billion people" << endl;
        inFile.close();
    }
}