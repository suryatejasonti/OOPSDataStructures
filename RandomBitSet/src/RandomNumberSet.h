/*
 * RandomBitSet.h
 *
 *  Created on: Oct 11, 2018
 *      Author: suryasonti
 */

#ifndef RANDOMNUMBERSET_H_
#define RANDOMNUMBERSET_H_


#include <stdlib.h>
#include <iostream>
#include <vector>
#include <bitset>


using namespace std;

class RandomNumberSet{

public:
	RandomNumberSet();

	RandomNumberSet(int range);

	~RandomNumberSet();

	void reset();

	bool set(int number);

	int getsize();

	friend ostream & operator << (ostream &os, const RandomNumberSet &bitset);

private:
	int range;
	int bitsetsize;
	vector<vector<bool>> numbers;
	void printon(ostream &out);
};


#endif /* RANDOMNUMBERSET_H_ */
