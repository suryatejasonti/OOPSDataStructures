#ifndef BOOK_H_
#define BOOK_H_

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;


/**
 * The Book class.
 */
class Book
{
public:
    /**
     * Book categories.
     */
    enum class Category { FICTION, HISTORY, TECHNICAL, NONE };

    /**
     * Default constructor.
     */
    Book();

    /**
     * Constructor.
     */
    Book(string isbn, string last, string first, string title, Category category);

    /**
     * Destructor.
     */
    ~Book();

    //Gets ISBN number of book
    string get_isbn() const;

    //Gets last name of the author
    string get_author_lastname() const;

    //Gets first name of the author
	string get_author_firstname() const;

	//Gets title of the book
	string get_title() const;

	//Gets category of the book
	Category get_category() const;

	//overloading output stream
	friend ostream & operator << (ostream &os, const Book &book);

	//overloading output stream for enum
	friend ostream & operator << (ostream &os, const Category &category);

	//overloading input stream
	friend istream & operator >> (istream &is, Book &book);


private:

    string isbn, last, first, title;
    Category category;
};

#endif /* EMPLOYEE_H_ */
