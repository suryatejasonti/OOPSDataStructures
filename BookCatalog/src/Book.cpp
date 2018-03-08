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
	//cout << "Removed " << *this;
}

//Gets ISBN number of book
string Book::get_isbn() const
{
	return isbn;
}

//Gets last name of the author
string Book::get_author_lastname() const
{
	return last;
}

//Gets first name of the author
string Book::get_author_firstname() const
{
	return first;
}

//Gets title of the book
string Book::get_title() const
{
	return title;
}

//Gets category of the book
Book::Category Book::get_category() const
{
	return category;
}

//overloading output stream for enum category
ostream & operator << (ostream &os, const Book::Category &category)
{
	switch( category )
	{
	  case Book::Category::NONE: os << "none"; break;
	  case Book::Category::FICTION: os << "fiction"; break;
	  case Book::Category::HISTORY: os << "history"; break;
	  case Book::Category::TECHNICAL: os << "technical"; break;
	}
	return os;
}

//overloading output stream
ostream & operator << (ostream &os, const Book &book)
{
	os << "Book{ISBN=" << book.isbn << ", last=" << book.last << ", first=" << book.first << ", title=" << book.title << ", category=" << book.category << "}"<< endl;
	return os;
}

//helper function stream for enum
Book::Category convert (string &category)
{
	for (auto & c: category) c = toupper(c);

	if( category == "NONE") return Book::Category::NONE;
	if( category == "FICTION") return Book::Category::FICTION;
	if( category == "HISTORY") return Book::Category::HISTORY;
	if( category == "TECHNICAL") return Book::Category::TECHNICAL;

	return Book::Category::NONE;
}

void parsestring(vector<string> &dataout, string &datain, const string &delimiter)
{
	dataout.clear();
	size_t pos = 0;
	std::string token;
	while ((pos = datain.find(delimiter)) != std::string::npos) {
	    token = datain.substr(0, pos);
	    dataout.push_back(token);
	    datain.erase(0, pos + delimiter.length());
	}
	dataout.push_back(datain);
}

//overloading input stream
istream & operator >> (istream &is, Book &book)
{
	string data;

	getline(is, data, '\n');
	if(data == "")
	{
		book.isbn = "all";
		book.last = "all";
		book.first = "all";
		book.title = "all";
		book.category = Book::Category::NONE;
		return is;
	}
	vector<string> vecdata;
	parsestring(vecdata, data, ",");
	if(vecdata.size() == 5)
	{
		book.isbn = vecdata[0].substr(1);
		book.last = vecdata[1];
		book.first = vecdata[2];
		book.title = vecdata[3];
		book.category = convert(vecdata[4]);
		return is;
	}
	parsestring(vecdata, data, "=");
	if(vecdata.size() == 2)
	{
		book.isbn = vecdata[0].substr(1) == "isbn" ? vecdata[1] : "";
		book.last = vecdata[0].substr(1) == "author" ? vecdata[1] : "";
		book.first = vecdata[0].substr(1) == "author" ? vecdata[1] : "";
		book.title = vecdata[0].substr(1) == "title" ? vecdata[1] : "";
		string temp;
		book.category = vecdata[0].substr(1) == "category" ? convert(vecdata[1]) : convert(temp);
		return is;
	}
	parsestring(vecdata, data, "-");
	if(vecdata.size() == 2)
	{
		book.isbn = vecdata[0].substr(1) + "-" + vecdata[1];
		book.last =  "";
		book.first = "";
		book.title = "";
		book.category = Book::Category::NONE;
		return is;
	}
	return is;
}
