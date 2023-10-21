#include <iostream>
#include <string>
#include "Valdes_Book.h" //header file to base functions off of
using namespace std;

//default setting constructor
Book::Book() {      //default information as stated
    title = "default";
    author = "default";
    edition = -1;
    year = -1;
    cost = 0;
    publisher = "default";
    subject = "default";
}

//default setting constructor WITH TITLE (for basic search purposes)
Book::Book(string t) {//default information except with title
    title = t;
    author = "default";
    edition = -1;
    year = -1;
    cost = 0;
    publisher = "default";
    subject = "default";
}

//basic setter functions to access private vars
void Book::setTitle(string t) {
    title = t;
}


void Book::setAuthor(string a) {
    author = a;
}

void Book::setEdition(int e) {
    edition = e;
}

void Book::setYear(int y) {
    year = y;
}

void Book::setCost(double c) {
    cost = c;
}

void Book::setSubject(string s) {
    subject = s;
}

void Book::setPublisher(string p) {
    publisher = p;
}

//basic gettrer functions to access private variables
string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

int Book::getEdition() const {
    return edition;
}

int Book::getYear() const {
    return year;
}

double Book::getCost() const {
    return cost;
}

string Book::getSubject() const {
    return subject;
}

string Book::getPublisher() const {
    return publisher;
}
