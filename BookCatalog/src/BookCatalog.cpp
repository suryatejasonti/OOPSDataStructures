//============================================================================
// Name        : BookCatalog.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Book Catalog in C++, Ansi-style
//============================================================================

#include <vector>
#include "Book.h"

using namespace std;

// Status codes.
enum class StatusCode {OK, DUPLICATE, NOT_FOUND, INVALID_COMMAND};

const string INPUT_FILE_NAME = "commands.in";

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param book the book with ISBN to search.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
vector<int> & binarysearch(const vector<Book>& catalog, const Book & book, vector<int> &indeces);

/**
 * Find the book in the catalog with the given search key.
 * Use a binary search.
 * @param book with search key Ex: name of author, title, category and respective value.
 * @param catalog the vector of book records.
 * @param indeces the vector to store indexes.
 * @return the vector indeces of the books if found, else return -1.
 */
vector<int> & linearsearch(const vector<Book>& catalog, const Book & book, vector<int> &indeces);

/**
 * Inserts element to catalog
 * @param catalog address
 * @param book to insert
 */
vector<Book> & insert(vector<Book> &catalog, const Book& book);

/**
 * Removes element to catalog
 * @param catalog address
 * @param book to insert
 */
vector<Book> & remove(vector<Book> &catalog, const Book & book);

vector<int> & binarysearch(const vector<Book>& catalog, const Book & book, vector<int> &indeces)
{
	int lowerBound = 0;
	int upperBound = catalog.size() -1;
	int midPoint = -1;
	indeces.push_back(-1);
	int data = stoi(book.get_isbn().substr(4));
	int middata;
	while(lowerBound <= upperBound)
	{
		// compute the mid point
		// midPoint = (lowerBound + upperBound) / 2;
		midPoint = lowerBound + (upperBound - lowerBound) / 2;
		middata = stoi(catalog[midPoint].get_isbn().substr(4));
		// data found
		if(middata == data)
		{
			indeces[0] = midPoint;
			break;
		}
		else
		{
			// if data is larger
			if(middata < data)
			{
				// data is in upper half
				lowerBound = midPoint + 1;
			}
			// data is smaller
			else
			{
				// data is in lower half
				upperBound = midPoint -1;
			}
		}
	}
	return indeces;
}

vector<int> & linearsearch(const vector<Book>& catalog, const Book & book, vector<int> &indeces)
{
	int size = catalog.size();
	int i;
	// navigate through all items
	for(i = 0;i < size;i++)
	{
	  // if data found, break the loop
	  if(book.get_author_firstname() == catalog[i].get_author_firstname()
			  || book.get_author_lastname() == catalog[i].get_author_lastname()
			  || book.get_title() == catalog[i].get_title()
			  || book.get_category() == catalog[i].get_category())
		{
		  // count the comparisons made
		  indeces.push_back(i);
		}
	}
	return indeces;
}

vector<Book> & insert(vector<Book> &catalog, const Book& book)
{
	int size = catalog.size();
	if(size == 0 || size ==1)
	{
		catalog.insert(catalog.begin() + size, book);
		cout << "Inserted at index " << size << ": " << book;
		return catalog;
	}

	int bookisbn, leftisbn, rightisbn;
	for(int i = 0; i < size; i++)
	{
		bookisbn = stoi(book.get_isbn().substr(4));
		leftisbn = stoi(catalog[i].get_isbn().substr(4));
		rightisbn = stoi(catalog[i+1].get_isbn().substr(4));
		if(leftisbn < bookisbn && rightisbn > bookisbn)
		{
			catalog.insert(catalog.begin() + i+1, book);
			cout << "Inserted at index " << i+1 << ": " << book;
			return catalog;
		}
		if(leftisbn == bookisbn || rightisbn == bookisbn)
		{
			cout << "Inserted at index " << i+1 << ": " << book;
			cout << "*** Duplicate ISDN ***" << endl;
			return catalog;
		}
	}
	return catalog;
}

vector<Book> & remove(vector<Book> &catalog, const Book & book)
{
	vector<int> indeces;
	indeces = binarysearch(catalog, book, indeces);
	cout << "Removed " << book;
	if(indeces[0] > -1)
	{
		catalog.erase(catalog.begin() + indeces[0]);
	}
	else
	{
		cout << "*** Book not found ***" << endl;
	}
	return catalog;
}

void search(const vector<Book> &catalog, const Book & book)
{
	bool singlesearch = false; vector<int> indeces;
	if(book.get_isbn() != "" && book.get_isbn() != "all")
	{
		indeces = binarysearch(catalog, book, indeces);
		singlesearch = true;
	}
	else if (book.get_isbn() == "")
	{
		indeces = linearsearch(catalog, book, indeces);
		singlesearch = true;
	}
	if(singlesearch)
	{
		string temp1 = indeces.size() > 1 ? "Books " : "Book ";
		string temp2, temp3;
		if(book.get_isbn() != "" && book.get_isbn() != "all")
			temp2 = "with ISBN ";
		if(book.get_author_lastname() != "" && book.get_author_lastname() != "all")
			temp2 = "by author ";
		if(book.get_category() != Book::Category::NONE)
			temp2 = "in category ";
		if(book.get_isbn() != "" && book.get_isbn() != "all")
			temp3 = book.get_isbn();
		if(book.get_author_lastname() != "" && book.get_author_lastname() != "all")
			temp3 = book.get_author_lastname();
		if(book.get_category() != Book::Category::NONE)
		{
			stringstream cat;
			cat << book.get_category();
			cat >> temp3;
		}

		cout << temp1 << temp2 << temp3 << ":"<< endl;

		if(indeces[0] > -1)
		{
			for(auto const& value: indeces)
				cout << catalog[value];
		}
	}
	else if(book.get_isbn() == "all")
	{
		cout << "All books in the catalog:" << endl;
		int size = catalog.size();
		for(int i = 0; i < size; i++)
		{
			cout << catalog[i];
		}
	}
}
/**
 * The main. Open the command input file and loop to process commands.
 */
vector<Book> catalog;// book catalog

    Book book;
int main()
{
    // Open the input file.
    ifstream input;
    input.open(INPUT_FILE_NAME);
    if (input.fail())
    {
        cout << "Failed to open " << INPUT_FILE_NAME << endl;
        return -1;
    }
    catalog.reserve(10);

    /**
     * Loop to read commands until the end of file.
     */
	char command;
	input >> command;  // read the first command
	/**
	 * Loop to read commands until the end of file.
	 */
	while (!input.fail())
	{
		cout << endl << command << " ";

		switch(command)
		{
		case '+':
			input >> book;
			catalog = insert(catalog, book);
			break;
		case '-':
			input >> book;
			catalog = remove(catalog, book);
			break;
		case '?':
			input >> book;
			search(catalog, book);
			break;
		default:
			input >> book;
			cout << "*** Invalid command ***" << endl;
			break;
		}
		input >> command;
    }
    return 0;
}
