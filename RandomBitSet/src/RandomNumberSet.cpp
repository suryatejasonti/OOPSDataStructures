//============================================================================
// Name        : RandomBitSet.cpp
// Author      : SuryaTSonti
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "RandomNumberSet.h"

using namespace std;


RandomNumberSet::RandomNumberSet(){
	this->range = 39;
	srand(time(0));
	for(int i = 0; i < 5; i++){
		this->bitsetsize = rand() % range + 1;
		vector<bool> number;
		for(int i = 0; i < this->bitsetsize; i++){
			number.push_back(0);
		}
		numbers.push_back(number);
	}
}

RandomNumberSet::RandomNumberSet(int range){
	this->range = range;
	srand(time(0));
	for(int i = 0; i < 5; i++){
		this->bitsetsize = rand() % range + 1;
		vector<bool> number;
		for(int i = 0; i < this->bitsetsize; i++){
			number.push_back(0);
		}
		numbers.push_back(number);
	}
}

bool RandomNumberSet::set(int number){
	vector<bool> bits; int bin;
	while (number > 0)
	{
		bin = number % 2;
		bits.push_back(bin);
		number /= 2;
	}
	vector<vector<bool>>::iterator it = std::find(numbers.begin(), numbers.end(), bits);
	if(it != numbers.end() && this->getsize() < 5){
		this->numbers.push_back(bits);
		return true;
	}
	else{
		return false;
	}
}

int RandomNumberSet::getsize(){
	return numbers.size();
}

void RandomNumberSet::reset(){
	numbers.clear();
}

ostream & operator << (ostream &os, const RandomNumberSet &bitset){
	for(int i = 0; i < bitset.numbers.size(); i++){
		for(int j=0; j< bitset.numbers[i].size(); j++){
			cout << bitset.numbers[i][j];
		}
		cout<<endl;
	}
	return os;
}




