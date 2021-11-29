/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 McGreggor Kennison
 */

#include "std_lib_facilities.h"
#include "Name_value.h"

// initialize contestants vector
vector<Name_value> contestants;

// fills contestants vector
void gatherContestants() {

    // initialize variables
    string inputName;
    double inputScore;

    // while input does not = NoName 0
    while(inputName != "NoName" && inputScore != 0) {

        // set sameName flag to 0
        int sameName = 0;
        
        // prompt for new input
        cout << "Input your new name and score seperated by spaces (ex. John 2): ";

        // scan in new input
        cin >> inputName >> inputScore;

        // for size of contestants
        for (int i = 0; i < contestants.size(); i++) {

            // check if inputName = name of contestants at i, if true set sameName to 1
            if (inputName == contestants[i].name)
                sameName = 1;

        }

        // check if input is NoName 0, if true continue
        if (inputName == "NoName" && inputScore == 0)
            continue;

        // check if sameName != 1, if true add input to contestants
        if (sameName != 1) {

            contestants.push_back(Name_value(inputName, inputScore));

        }

        // if sameName = 1 throw error
        else 
            error("A name may only be used once");

    }

}

// prints out values in contestants vector
void printOutput() {

    // for size of contestants
    for (int i = 0; i < contestants.size(); i++) {

        // print out "<name> <score>" and create new line 
        cout << contestants[i].name << " " << contestants[i].score << "\n"; 

    }

}

// main
int main() {

    // call gatherContestants
    gatherContestants();

    // call printOutput
    printOutput();

}

