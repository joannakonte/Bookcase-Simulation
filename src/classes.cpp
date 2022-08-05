#include <iostream>
#include <string>

#include "../include/classes.h"

using namespace std;

/* ====================================||  B O O K  F U N C T I O N S  ||======================================== */

void Book::print(){
    cout << "Book title: " << title << endl;
    cout << "Author's Full Name: " << author_name << " " << author_surname << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << endl;
}

/* ====================================||  S H E L F  F U N C T I O N S  ||======================================== */

Shelf::Shelf(unsigned int N_Max){
    this->maxCap = N_Max;
    this->books = new Book * [N_Max];
    NoOfBooks = 0;
}

Shelf::~Shelf(){
    delete[] this->books; 
}

bool Shelf::place_book(Book *book){
    if (isFull()){
        cout << "Can't place book. Shelf is full!\n";
        return false;
    } else {
        books[NoOfBooks++] = book;
        cout << "Book has been placed successfully!\n";
        if (NoOfBooks == 1)
            cout << "Shelf has now " << NoOfBooks << " book.\n";
        else 
            cout << "Shelf has now " << NoOfBooks << " books.\n";
        return true;
    }
}

bool Shelf::take_book(){
    if(isEmpty()){
        cout << "Shelf is empty! Can't take book.\n";
        return false;
    } else {
        int book_pos = rand() % NoOfBooks;  // Choosing a book to take from a random position
        books[book_pos] = NULL;

        if (book_pos != NoOfBooks-1) {            // If the book that was taken out was't the last, move books to the left
            for (int i = book_pos; i < NoOfBooks-1; i++)
                books[i] = books[i+1];
        }

        books[--NoOfBooks] = NULL;

        cout << "Book has been taken out successfully!\n";
        
        if (NoOfBooks == 1)
            cout << "Shelf has now " << NoOfBooks << " book.\n";
        else 
            cout << "Shelf has now " << NoOfBooks << " books.\n";
       
        return true;
    }
}

void Shelf::print(){
    for (int i = 0; i < NoOfBooks; i++){
        books[i]->print();
    }
}

/* ====================================||  L I B R A R Y  F U N C T I O N S  ||======================================== */

Library::Library(unsigned int N_Max, unsigned int L, unsigned int K1, unsigned int K2){
    NoOfBooks = 0;
    this->base = new Base();
    this->cabinet = new Cabinet(N_Max);
    for (int i = 0; i < 3; i++)
        shelves[i] = new Shelf(N_Max);
 
    cout << endl;
}

Library::~Library(){ 
    delete base;
    delete cabinet;
    for(int i = 0; i < 3; i++)
        delete shelves[i];
}

bool Library::place_book(Book* book, int pos){
    switch(pos){
        case 1: {
            bool placed = shelves[0]->place_book(book);
            
            if (placed == true) {         
                cout << "Placed book on the top shelf.\n";      
                if (++NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return placed; 
        }
            break;
        case 2: 
        {
            bool placed = shelves[1]->place_book(book);
           
            if (placed == true) {         
                cout << "Placed book on the middle shelf.\n";      
                if (++NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return placed;
        }
            break;
        case 3: 
        {
            bool placed = shelves[2]->place_book(book);
           if (placed == true) { 
                cout << "Placed book on the bottom shelf.\n";
                if (++NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return placed; 
            
        }
            break;
        case 4: 
        {
            bool placed = cabinet->place_book(pos - 4, book);

            if (placed == true) {   
                cout << "Placed book on the first cabinet shelf.\n";            
                if (++NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return placed;
        }
            break;
        case 5: 
        {
            bool placed = cabinet->place_book(pos - 4, book);

            if (placed == true) {          
                cout << "Placed book on the second cabinet shelf.\n";     
                if (++NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return placed;
        }
            break;
    }
    return false;
}

bool Library::take_book(int pos){
    switch(pos){
        case 1: {
            bool took = shelves[0]->take_book();
            if (took == true) {         
                cout << "Took the book out of the top shelf.\n";      
                if (--NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return took; 
        }
            break;
        case 2: {
            bool took = shelves[1]->take_book();
            if (took == true) {         
                cout << "Took the book out of the middle shelf.\n";      
                if (--NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return took; 
        }
            break;
        case 3: {
            bool took = shelves[2]->take_book();
            if (took == true) {         
                cout << "Took the book out of the bottom shelf.\n";      
                if (--NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return took; 
        }
            break;
        case 4: {
            bool took = cabinet->take_book(pos - 4);
            if (took == true) {         
                cout << "Took the book out of the first cabinet shelf.\n";      
                if (--NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return took; 
        }
            break;
        case 5: {
            bool took = cabinet->take_book(pos - 4);
            if (took == true){
                cout << "Took the book out of the first cabinet shelf.\n";      
                if (--NoOfBooks == 1)
                    cout << "The Library has now " << NoOfBooks << " book.\n";
                else 
                    cout << "The Library has now " << NoOfBooks << " books.\n";
            }
            cout << endl;
            return took; 
        }
            break;
    }
    return false;
}

void Library::print(){
    for (int i = 0; i < 3; i++){
        shelves[i]->print();
    }
        
    cabinet->print();
}

/* ====================================||  C A B I N E T  F U N C T I O N S  ||======================================== */

Cabinet::Cabinet(unsigned int N_Max){ 
    for (int i = 0; i < 2; i++)  
        shelves[i] = new Shelf(N_Max);
    NoOfBooks = 0;
}

Cabinet::~Cabinet(){ 
    for(int i = 0; i < 2; i++)
        delete shelves[i];
}

bool Cabinet::place_book(int pos, Book *book){
    if (shelves[pos]->isFull()) {
        cout << "Can't place book. Cabinet Shelf is full!\n";
        return false;
    }
    else{
        shelves[pos]->place_book(book);
        NoOfBooks++;
        return true;
    }
}

bool Cabinet::take_book(int pos){
    if(shelves[pos]->isEmpty()){
        cout << "Shelf is empty! Can't take book.\n";
        return false;
    } else {
        bool taken = shelves[pos]->take_book();
        if (taken) 
            NoOfBooks--;
    
        return taken;
    }

}
void Cabinet::print(){
    for (int i = 0; i < 2; i++)
        shelves[i]->print();
}