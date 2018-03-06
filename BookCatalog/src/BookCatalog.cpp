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

/**
 * Find the book in the catalog with the given ISBN.
 * Use a binary search.
 * @param isbn the ISBN.
 * @param catalog the vector of book records.
 * @return the vector index of the book if found, else return -1.
 */
int find(const string isbn, const vector<Book>& catalog);

/**
 * Inserts element to catalog
 * @param catalog address
 * @param book to insert
 */
void insert(vector<Book> &catalog, Book & book);

/**
 * Removes element to catalog
 * @param catalog address
 * @param book to insert
 */
void remove(vector<Book> &catalog, Book & book);



const string INPUT_FILE_NAME = "commands.in";

void insert(vector<Book> &catalog, Book& book)
{
	int index;
	int lastbookisbn = stoi(catalog.back().get_isbn().substr(4));
	int newbookisbn = stoi(book.get_isbn().substr(4));
	for(int i = 0; i < catalog.size() -1; i++)
	{
		stoi(catalog.back().get_isbn().substr(4));
	}
	if(index == -1)
	{
		//index = catalog.
		//catalog.push_back(book);
		//else
		//	catalog.insert(catalog.begin(),book);
		cout << "Inserted at index " << index << ": " << book;
	}
	else
	{
		cout << "*** Duplicate ISDN ***" << endl;
	}
}

int convert(string command)
{
	if(command == "+") return 0;
	if(command == "-") return 1;
	if(command == "?") return 2;
	return -1;
}

/**
 * The main. Open the command input file and loop to process commands.
 */
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

    vector<Book> catalog;  // book catalog
    /**
     * Loop to read commands until the end of file.
     */
    string command;Book book;
    while (getline(input, command, ' '))
    {
    		string key = "", value = "";
        cout << endl << command << " ";
        switch(convert(command))
        	{
			case 0:
			{

				input >> book;
				cout << book;
				//insert(catalog, book);
				break;
			}
			case 1:
			{
				string isbn;
				getline(input, isbn, '\n');
				//remove(catalog, book);
				break;
			}
			case 2:
			{
				getline(input, key, '=');
				getline(input, value, '\n');
				if(value != "")
				{
					//remove(catalog, book);
					break;
				}
				cout << "All books in the catalog:" << endl;
				break;
			}
			default:
			{
				string temp;
				getline(input, temp, '\n');
				cout << "*** Invalid command ***";
				break;
			}
        	}
        /*** Complete this main. *****/
    }

    return 0;
}
