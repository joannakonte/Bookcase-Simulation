/* File: classes.h */
#pragma once

#include <iostream>
#include <string>

using namespace std;

class Base {
    public:
        Base(){}
        ~Base(){}
};


class Book {
    private:
        string title;
        string author_name;
        string author_surname;
        unsigned int ISBN;
        int position;
    public:
        Book(string title, string name, string surname, unsigned int isbn) :
            title(title), author_name(name), author_surname(surname), ISBN(isbn) {
            this->title = title;
            this->author_name = name;
            this->author_surname = surname;
            this->ISBN = isbn;
        }
        ~Book();
        void print();
};

class Shelf {
    private:
        int NoOfBooks;
        int maxCap; 
        Book **books;
    public:
        Shelf(const unsigned int N_Max);
        ~Shelf();
        bool place_book(Book *book);
        bool take_book();
        bool isFull() { return (NoOfBooks == maxCap);}
        bool isEmpty() { return (NoOfBooks <= 0);}
        void print();
};

class Cabinet {
    protected:
        int NoOfBooks;
        Shelf *shelves[2];
    public: 
        Cabinet(const unsigned int N_Max);
        ~Cabinet();
        bool place_book(int pos, Book *book);
        bool take_book(int pos);
        void print();
};

class Library {
    private:
        int NoOfBooks; // Indicates the number of books CURRENTLY in the library. Initially 0
        Base *base;
        Cabinet *cabinet;
        Shelf *shelves[3];
    public:
        Library(const unsigned int N_Max, const unsigned int L, const unsigned int K1, const unsigned int K2);
        ~Library();
        bool place_book(Book *book, int pos);
        bool take_book(int pos);
        void print();
};


