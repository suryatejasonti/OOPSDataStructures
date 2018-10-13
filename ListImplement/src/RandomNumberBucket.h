/*
 * RandomNumberBucket.h
 *
 *  Created on: Oct 3, 2018
 *      Author: RishikaMachina
 */

#ifndef RANDOMNUMBERBUCKET_H_
#define RANDOMNUMBERBUCKET_H_

#include <stdlib.h>
#include <list>

using namespace std;

class RandomNumberBucket{

public:

	RandomNumberBucket(int numberofdigits);

	RandomNumberBucket();

	~RandomNumberBucket();

	int Pop();

	void Refill();

	int PopwithRefill();

	int Size();

	bool Empty();

private:
	int size;
	list<int> m_list;
};

#endif /* RANDOMNUMBERBUCKET_H_ */
