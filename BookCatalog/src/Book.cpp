#include "Book.h"

using namespace std;

/**
* Default constructor.
*/
Book::Book()
{
	this->category = Book::Category::NONE;
	this->first = "";
	this->last = "";
	this->title = "";
	this->isbn = "";
}
/**
 * Constructor.
 */
Book::Book(string isbn, string last, string first, string title, Category category)
{
	this->category = category;
	this->first = first;
	this->last = last;
	this->isbn = isbn;
	this->title = title;
}

/**
 * Destructor.
 */
Book::~Book()
{
	cout << "Removed " << *this;
}
//Gets ISBN number of book
string Book::get_isbn()
{
	return isbn;
}

//Gets last name of the author
string Book::get_author_lastname()
{
	return last;
}

//Gets first name of the author
string Book::get_author_firstname()
{
	return first;
}

//Gets title of the book
string Book::get_title()
{
	return title;
}

//Gets category of the book
Book::Category Book::get_category()
{
	return category;
}
//overloading output stream for enum category
ostream & operator << (ostream &os, const Book::Category &category)
{
	switch( category )
	{
	  case Book::Category::NONE: os << "NONE"; break;
	  case Book::Category::FICTION: os << "FICTION"; break;
	  case Book::Category::HISTORY: os << "HISTORY"; break;
	  case Book::Category::TECHNICAL: os << "TECHNICAL"; break;
	}
	return os;
}

//overloading output stream
ostream & operator << (ostream &os, const Book &book)
{
	os << "Book{ISBN=" << book.isbn << ", last=" << book.last << ", first=" << book.first << ", title=" << book.title << ", category=" << book.category << "}"<< endl;
	return os;
}
//overloading input stream for enum
Book::Category convert (string &category)
{
	for (auto & c: category) c = toupper(c);

	if( category == "NONE") return Book::Category::NONE;
	if( category == "FICTION") return Book::Category::FICTION;
	if( category == "HISTORY") return Book::Category::HISTORY;
	if( category == "TECHNICAL") return Book::Category::TECHNICAL;

	return Book::Category::NONE;
}

//overloading input stream
istream & operator >> (istream &is, Book &book)
{
	string category;
	getline(is, book.isbn, ',');
	getline(is, book.last, ',');
	getline(is, book.first, ',');
	getline(is, book.title, ',');
	getline(is, category, '\n');
	book.category = convert(category);

	return is;
}









