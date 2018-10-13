/*
 * IntArray.h
 *
 *  Created on: Oct 12, 2018
 *      Author: suryasonti
 */

#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

#include <stdio.h>
#include <assert.h>
#include <stdexcept>
#include <cstdlib>

const unsigned int MaxSize=1000; // Need a max size, array can’t grow forever
const unsigned int InitialSize=10; // Initial number of entries in the array
const unsigned int growSize=100; // How much to grow past required size

template <class T>
class DynamicArray {

	public:
		DynamicArray(unsigned int init_size = InitialSize ){
			this->x = new int [init_size];
			assert(this->x != nullptr);
			size = init_size;
		}
		~DynamicArray() {
			delete [] this->x;
		}
		bool set(T value, unsigned int index){
			if (index+1 > size){
				unsigned new_sz = index+1 + growSize;
				if (new_sz > MaxSize) return false;
				bool result = resize(new_sz);
				if (!result)  return false;
			}
			x[index] = value; return true;
		}
		T get(unsigned int index){
			if (index+1 > size){
				return 0;
			}
			return x[index];
		}
	protected:
		int getArraySize(){
			return size;
		}
	private:
		bool resize(unsigned int new_size){
			int *y = new int [new_size];
			if (y == nullptr) return false;
			for (unsigned int n = 0; n < size; n++){
				y[n]=x[n];
			}
			delete [] x;
			x = y;
			return true;
		}
		T *x;
		unsigned int size;
};

#endif /* DYNAMICARRAY_H_ */
