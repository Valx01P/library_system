#pragma once
#ifndef VALDES_BOOK_H
#define VALDES_BOOK_H
#include <iostream>
#include <string>
using namespace std;

class Book {
private: //state private variable members
    string title;
    string author;
    int edition;
    int year;
    double cost;
    string publisher;
    string subject;

public: 
    //constructor and overloaded constructor
    Book();
    Book(string t);
    //public setter and access functions for book information
    void setTitle(string t);
    void setAuthor(string a);
    void setEdition(int e);
    void setYear(int y);
    void setCost(double c);
    void setSubject(string s);
    void setPublisher(string p);
    string getTitle() const;
    string getAuthor() const;
    int getEdition() const;
    int getYear() const;
    double getCost() const;
    string getSubject() const;
    string getPublisher() const;

};

#endif