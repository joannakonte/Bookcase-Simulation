#include <iostream>
#include <string>
#include <fstream>  // file operations
#include <cstdlib>  // for EXIT_FAILURE

#include "../include/classes.h"

using namespace std;


int main (int argc, char *argv[]){ 

    /* Read N Max, L, K1 from command Line */
    if (argc != 5) {   /*Error check */
        cerr << "\nUsage:\t" << argv[0] 
        << " <N_Max> <L> <K1> <K2>\n" << endl;
        exit(EXIT_FAILURE); 
    }

    unsigned int N_Max, L, K1, K2;

    N_Max = atoi(argv[1]);          // Max capacity of shelves
    L = atoi(argv[2]);              // L Books
    K1 = atoi(argv[3]);             // K1 placements
    K2 = atoi(argv[4]);             // K2 removals

    cout << endl;

    Library *lib = new Library(N_Max, L, K1, K2);

    ifstream file_titles; file_titles.open("./input/titles.txt");
    ifstream file_names; file_names.open("./input/names.txt");
    ifstream file_surnames; file_surnames.open("./input/surnames.txt");
    ifstream file_isbn; file_isbn.open("./input/ISBN.txt");

    string namesList[20]; 
    string surnamesList[20]; 
    string titlesList[20]; 
    unsigned int ISBNList[20];
    
    unsigned int namesCount = 0;
    unsigned int surnamesCount = 0;
    unsigned int titlesCount = 0;
    unsigned int ISBNCount = 0;

    /* Read everything provided by the files */
    string tmp1;
    while(getline(file_titles, tmp1)){
        titlesList[titlesCount++] = tmp1;
    }
    file_titles.close();
    
    string tmp2; 
    while (getline(file_names, tmp2)) {
        namesList[namesCount++] = tmp2;
    }
    file_names.close();

    string tmp3;
    while (getline(file_surnames, tmp3)) {
        surnamesList[surnamesCount++] = tmp3;
    }
    file_surnames.close();

    while(file_isbn){
        int tmp;
        file_isbn >> tmp;
        ISBNList[ISBNCount++] = tmp;
    }
    file_isbn.close();
    
    /* Generating random numbers for positions to put the books in the shelves */
    int pos;
    srand(time(NULL));

    Book *tempbook; 
    Book **mybooks = new Book * [L];

    for (int i = 0; i < L; i++) {
        tempbook = new Book(titlesList[i], namesList[i], surnamesList[i], ISBNList[i]);
        mybooks[i] = tempbook;
    }

    for (int i = 0; i < K1; i++) {
        pos = rand() % 5 + 1;
        lib->place_book(mybooks[i], pos);
    }

    for (int i = 0; i < K2; i++) {
        lib->take_book(i+1);
    }
    
    lib->print();

    delete lib;

}