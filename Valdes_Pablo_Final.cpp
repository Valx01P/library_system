/*
Credit by exam: COP1334

Write a program that uses a Book class to store book information.
In your header file define the Book class from the UML provided.

Implement the class defined in the header file in its own source file.
Note:  Remember to include the header file in the implementation file.
	   Pay attention to the default values indicated in the UML diagram
	   and use them for your constructor(s).  Handle them however you wish.

In your driver source file(the one with main) you will have the following
functions:  main, menu, loadBooks, editBook, displayBook, sortBooks

When your program starts it will load the books from a book.dat file (provided)
and then present you with a menu to Add a Book, Edit a Book, Display all Books
and show the number of and cost of the books we have in our library.

Write all necessary functions and prototypes. All parameters must be passed by
reference except for the size. Make sure to use proper indentation and comments
within your code.

You will submit three files :
LastName_Book.h( class UML provided)
LastName_Book.cpp(The source file implementing the Book Class)
LName_FName_Final.cpp(your driver program)


Make sure to submit the correct files.If you submit incorrectly(for whatever reason),
you will fail the exam.  Therefore, take your time and do not wait to the absolute
deadline to start submitting.
*/

//BY PABLO VALDES COP1334 10/18/23

//#includes go here
#include <iostream> //input output stream
#include <fstream> //files
#include <iomanip> //io stream manipulation
#include <string> //string vars
#include "Valdes_Book.h" //header file
using namespace std;



//function prototypes for menu, loadBooks, searchByName, editBook, and displayBook go here
//make non mutating functions const, keep int SIZE const as it will never be changed
void bubbleSortArray(Book array[], const int SIZE); //sorting algo for books
void menu();	//menu func
void loadBooks(Book array[], const int SIZE);	//fill up the books with file data
void searchByName(const Book array[], const int SIZE);	//linear search algo to find specific book by name
void editBook(Book& book);	//edit a specific book func
void displayBook(const Book& book); //display enter contents of book



//In main call the menu function
//main goes here
int main() {//init const var SIZE
	const int SIZE = 10;
	Book library[SIZE]; //form the initial array of books

	loadBooks(library, SIZE); //pass the array of books, library so we can load the books from the .dat file
	//run the menu once the library array of books has been filled with the .dat file data
	menu();
	//end program when menu is exited
	return 0;
}



void searchByName(const Book array[], const int SIZE) {
	string searchTitle;	//search using the title of the book
	cout << "Enter the title to search for: ";
	cin.ignore(); // clear input buffer before getline
	getline(cin, searchTitle); //getline to get mutiple lines of text

	bool found = false; //to say if book was found or not

	// search the books array for the specific book, use a linear search algorithm to match inputted title with the book title
	for (int i = 0; i < SIZE; i++) {
		if (array[i].getTitle() == searchTitle) {
			cout << "Book Found: " << endl;
			displayBook(array[i]); // show the information for the specificf found book
			found = true; //make found = true so we can output a potential error message
		}
	}

	if (!found) { //if the book was not found print this out, otherwise if it was, it won't!
		cout << "The book was not found, sorry!" << endl;
	}
}




/*loadBooks function instructions

* This function does not return a value and takes an array of Books and an integer, SIZE, as parameters.
* It opens a file and read the contents into the passed array.
*
* Declare an integer called counter and initialize it to 0
* Declare variables for title, author, edition, year, cost, subject, and publisher
* Declare an ifstream object, name it fin, and open the book.dat file. (Remember to include <fstream>)
* While not fin.eof() and counter < SIZE
*		using getline, read the title
*		using getline, read the author
*		using >> read edition, year, and cost
*		using fin.ignore clear the buffer
*		using getline, read the subject
*		using getline, read the publisher
*		call the appropriate setter function to set the values for
*		   each array object using counter as the index
*          (Note: Multiple statements)
*		increment counter
* close fin
* end the initializeArray function
*/
void loadBooks(Book array[], const int SIZE) {
	ifstream fin; //open the data file, .dat file, if .dat is not working try and open it in a text format and put the contents in a .txt file
	fin.open("book.dat");	//and simply change this line to fin.open("book.txt") if the text file is a resource file, otherwise specify the file path
	//i used .txt in testing, it was successful, .dat will work aswell
	//vars for book data
	int counter = 0;
	string title, author, subject, publisher;
	int edition, year;
	double cost;
	//get data from file until there is no more
	while (!fin.eof() && counter < SIZE) {
		getline(fin, title);
		getline(fin, author);
		fin >> edition >> year >> cost;
		fin.ignore(numeric_limits<streamsize>::max(), '\n'); //clear the entire line buffer after reading in the cost
		getline(fin, subject);
		getline(fin, publisher);

		// call the setter functions to set the values for the new book object being added to the array
		// use the counter as the index
		array[counter].setTitle(title);
		array[counter].setAuthor(author);
		array[counter].setEdition(edition);
		array[counter].setYear(year);
		array[counter].setCost(cost);
		array[counter].setSubject(subject);
		array[counter].setPublisher(publisher);

		counter++; //increase counter for next new book object
	}
	//close data file
	fin.close();
}

/* Edit a book function
*  This function takes a Book object as a parameter passed by reference and sets the values.
*
*	Declare variables for title, author, edition, year, cost, subject, and publisher
*
*   Display the current information for the title
*	Ask the user to enter the new title
*   Display the current information for the author
*	Ask the user to enter the new author
*   Display the current information for the subject
*	Ask the user to enter the new subject
*   Display the current information for the publisher
*	Ask the user to enter the new publisher
*   Display the current information for the edition
*	Ask the user to enter the new edition
*   Display the current information for the year
*	Ask the user to enter the new year
*	Display the current information for the cost
*   Ask the user to enter the new cost
*
*   Set each of the values for the object (note: multiple statements)
*
*/
//pass a specific book object to edit, this is located specifically via the main menu and the index search algo
void editBook(Book& book) {
	//declare the variables to edit the book info later
	string title, author, subject, publisher;
	int edition, year;
	double cost;

	// Display the current information for the title
	cout << "Current Title: " << book.getTitle() << endl;
	cout << "Enter new Title: ";
	cin.ignore(); // clear the buffer to avoid errors with getline
	getline(cin, title); //get the new title

	// Display the current information for the author
	cout << "Current Author: " << book.getAuthor() << endl;
	cout << "Enter new Author: ";
	getline(cin, author); // same as above

	// Display the current information for the subject
	cout << "Current Subject: " << book.getSubject() << endl;
	cout << "Enter new Subject: ";
	getline(cin, subject); // same as above

	// Display the current information for the publisher
	cout << "Current Publisher: " << book.getPublisher() << endl;
	cout << "Enter new Publisher: ";
	getline(cin, publisher); // same as above

	// Display the current information for the edition
	cout << "Current Edition: " << book.getEdition() << endl;
	cout << "Enter new Edition: ";
	cin >> edition; //get new info

	// Display the current information for the year
	cout << "Current Year: " << book.getYear() << endl;
	cout << "Enter new Year: ";
	cin >> year; //get new info

	// Display the current information for the cost
	cout << "Current Cost: " << book.getCost() << endl;
	cout << "Enter new Cost: ";
	cin >> cost; //get new info

	// Set the new values for the edited book object
	book.setTitle(title);
	book.setAuthor(author);
	book.setSubject(subject);
	book.setPublisher(publisher);
	book.setEdition(edition);
	book.setYear(year);
	book.setCost(cost);
}
/*	Menu function instructions
*	Menu
*	1: Add Book
*	2: Edit Book
*	3: Display Books
*	4: exit
*	The menu function does not take any parameters and does not return any values.  You must use
*	the switch statement to implement your menu.
*	Declare an integer constant SIZE and assign it a value of 10
*	Declare an array of Books using SIZE
*	Declare a variable to hold the index of a book (you may use this variable for case 1, 2, and 3).
*	  In case 3, use this variable in your for loop to count the number of books.
*	Declare a variable to sum the cost of the book(s).
*
*	Call the loadBooks function and pass it the array of Books and SIZE
*
*	Menu:
*		Display the menu
*
*		case the user selects 1:
*			display, Functionality not yet implemented.
*
*		case the user selects 2:
*			call the bubbleSortArray() function.  Be sure to include the appropriate parameters.
*
*			using a for loop iterate through the array of Books
*				if the title of the book is not equal to "default"
*					Display the index of the object. (something like:  item #: 0, where 0 is the index)
*					call the displayBook() function passing the array object
*			ask the user to enter the index to edit and use that to pass the array object to the edit function
*
*		case the user selects 3:
*			call the bubbleSortArray() function.  Besure to include the appropriate parameters.
*			set the variable to hold the index to 0;
*			set the variable to hold the sum of the cost of the books to 0;
*			use a for loop for i less than SIZE
*				if the title of the book is not equal to "default"
*					call the displayBook() function passing the array object
*					 add the cost of the object to the sum (i.e. accumulate the cost)
*					increment the variable declared to hold the index at the top of the function
*			display a message that there are x number of books in the list and the total cost of the books is y.
*			  (Note: x is the variable incremented in the for loop and y is the sum of all the books)
*
*		case the user selects 4:
*			display a goodbye message
*			end the the menu function
*
*		case the user default:
*			display a message
*
Note:  don't forget the default for your switch statement
*/
//main menu using switch and sentinal while loop
void menu() {
	const int SIZE = 10; //declare constant int
	Book books[SIZE]; //array of books
	int index = 0; //index for books
	double totalCost = 0.0;

	loadBooks(books, SIZE);

	bool exit = false;
	while (exit != true) { //while loop to keep the menu going until the user quits, sentinal while loop
		int choice;
		// menu options
		cout << "Menu" << endl;
		cout << "1: Add Book" << endl;
		cout << "2: Edit Book" << endl;
		cout << "3: Display Books" << endl;
		cout << "4: Exit" << endl;
		cout << "Enter your choice: ";
		cin >> choice;

		switch (choice) { //switch statement to implement menu
			case 1:
				cout << "Functionality not yet implemented." << endl;
				break;
			case 2:
				bubbleSortArray(books, SIZE); //call sorting func

				for (int i = 0; i < SIZE; i++) { //go through the books array based on it's max size
					if (books[i].getTitle() != "default") { //if the title is not default then get it
						cout << "Item Index #" << i << ": "; //display the index with the forammt
						displayBook(books[i]); //display the book so a user may see it's index and other values
					}
				}

				int editIndex;		//find the specific book to edit via it's index
				cout << "\nEnter the Item Index # to edit: ";
				cin >> editIndex;	//get the specified book
				if (editIndex >= 0 && editIndex < SIZE) {	//find the book
					editBook(books[editIndex]);	//edit the book by passing in it's index to the editBook function
				}
				break;
			case 3:
				bubbleSortArray(books, SIZE); // Call a sorting function here if needed
				index = 0;
				totalCost = 0.0; //accumulator

				for (int i = 0; i < SIZE; i++) { //calculating total cost of books for loop
					if (books[i].getTitle() != "default") { //display only non-default books
						displayBook(books[i]);	//display the books
						totalCost += books[i].getCost(); //accumulate the cost of each book
						index++;	//increase the index to display the total number of books in the list
					}
				}
				//display the info about the books
				cout << "There are " << index << " books in the list, and the total cost of the books is $" << totalCost << endl;
				break;
			case 4:
				cout << "Goodbye!" << endl;
				exit = true; //end the loop
				break;
			default: //default invalid response
				cout << "Invalid response, please enter a valid response!" << endl;
				break;
		}
	}
}

/*displayBooks function instructions
* This function does not return a value and takes a Book object a parameter passed by reference
*
* Display the values of the Book object as follows.  Be sure to leave a blank line above and below to set
* information apart from other data
*
*     Title :
*    Author :
*	   Year :      Edition:		Cost: $
* Publisher :
*   Subject :
*
*/

//pass a specific book object by reference to the function
void displayBook(const Book& book) {
	// access the book values and display them in the correct format
	cout << endl << "    Title : " << book.getTitle() << endl;
	cout << "    Author : " << book.getAuthor() << endl;										//show 2 decimal points for the cost
	cout << "       Year : " << book.getYear() << "   Edition: " << book.getEdition() << "   Cost: $" << fixed << setprecision(2) << book.getCost() << endl;
	cout << " Publisher : " << book.getPublisher() << endl;
	cout << "   Subject : " << book.getSubject() << endl;
}


//This function sorts the array of book objects by lastname
//Do not change anything is this function
void bubbleSortArray(Book array[], const int SIZE)
{
	Book temp; //variable to temporarily hold array item
	bool madeAswap; //trackd if a swap was made

	do
	{
		madeAswap = false;  //reset each round 
		for (int count = 0; count < (SIZE - 1); count++)
		{
			if (array[count].getTitle() > array[count + 1].getTitle())
			{
				temp = array[count];
				array[count] = array[count + 1];
				array[count + 1] = temp;
				madeAswap = true;
			}
		}
	} while (madeAswap);
}