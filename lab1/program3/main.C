#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

/*
 * Function: print
 * Parameters: string text
 * Return: void
 * Prints text using format as shown on camino.
 */
void print(string text) {
    int i, j, k = 0;
    char temp[100];
    text += ' ';
    for(i = 0; i < text.length(); i++) {
        char c = text.at(i);
        if(c != 32) { //search for space in text
            if(c >= 'A' && c <= 'Z') { //if uppercase alphabetic add to char temp[]
                temp[k] = c;
                k++;
            }
            else if(c >= 'a' && c <= 'z') //if lowercase alphabetic make uppercase and add to char temp[]
            {
                temp[k] = c - 32;
                k++;
            }
        } else if(k >= 10) { //once space is found if temp is larger then 10 characters print temp.
            for(j = 0; j < k; j++)
                cout << temp[j];
            cout << endl;
            k = 0; //resets temp index
        } else {
            k = 0;
        }
    }
    return;
}

/*
 * Function: main
 * Parameters: int argc, char *argv[]
 * Gets single text file input and prints contents of file according to example on camino.
 */
int main(int argc, char *argv[]) {
    if(argc != 2){ //if there is more than one file or none at all terminate with error
        cout << "Invalid number of file(s)!" << endl;
        exit(1);
    }
    char *fName = argv[1];
    string text;
    ifstream myFile(fName); //attempts to open file
    if(!myFile) { //if file could not be opened terminate with error
        cout << "Unable to open file!";
        exit(1);
    }
    while(getline(myFile, text)) { //increment through file line by line
        print(text); //prints out line according to example on camino
    }
    myFile.close(); //closes file
    return 0;
}
