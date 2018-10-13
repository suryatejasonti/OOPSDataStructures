//============================================================================
// Name        : RandomNumberBucket.cpp
// Author      : RishikaMachina
// Version     :
// Copyright   : Your copyright notice
// Description : List implementation in C++, Ansi-style
//============================================================================

#include "RandomNumberBucket.h"

RandomNumberBucket::RandomNumberBucket(){
	srand(time(0));
	size = 39;
	for(int i=0; i< size; i++){
		m_list.push_back(i);
	}
}

RandomNumberBucket::RandomNumberBucket(int size){
	srand(time(0));
	this->size = size;
	for(int i=0; i< size; i++){
		m_list.push_back(i);
	}
}

RandomNumberBucket::~RandomNumberBucket(){
	m_list.clear();
}

int RandomNumberBucket::Size(){
	return m_list.size();
}

int RandomNumberBucket::Pop(){
	int deleted_value;
	if(m_list.size() != 0){
		int position = rand() % m_list.size() + 1;
		list<int>::iterator begin = m_list.begin();
		advance(begin, position -1);
		deleted_value = *begin;
		begin = m_list.erase(begin);
	}
	else{
		deleted_value = -1;
	}
	return deleted_value;
}

bool RandomNumberBucket::Empty(){
	return m_list.empty();
}

void RandomNumberBucket::Refill(){
	while(m_list.size() != size){
		int value = rand() % size + 1;
		list<int>::iterator findIter = find(m_list.begin(), m_list.end(), value);
		if (findIter == m_list.end()){
			m_list.push_back(value);
		}
	}
}

int RandomNumberBucket::PopwithRefill(){
	int deleted;
	if(m_list.size() == 0){
		this->Refill();
		deleted = -1;
	}
	else{
		deleted = this->Pop();
	}
	return deleted;
}

