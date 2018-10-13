/*
 * DynamicStack.h
 *
 *  Created on: Oct 12, 2018
 *      Author: suryasonti
 */

#ifndef DYNAMICSTACK_H_
#define DYNAMICSTACK_H_

#include <stdio.h>
#include <iostream>
#include "DynamicArray.h"

template <class T>
class DynamicStack: public DynamicArray<T>{

	public:
		DynamicStack(){
			srand(time(0));
			for(int i =0; i< 100; i++){
				int value = rand() % 100 + 1;
				this->set(value, i);
			}
		}
		DynamicArray<int> histogram(){
			DynamicArray<int> a;
		  for (int i = 0; i < 100; i++){
			int j;
			for (j = 0; j < i; j++){
					if(this->get(i) == this->get(j))
					break;
			}
			if (i == j){
				for (int k = 0; k < 10; k++)
				{
					for (int l = this->getArraySize(); l>= 0; l--)
					{
						if (this->get(k) >= l)
							a.set(1, l);
						else
							cout << " ";
					}
				}
			}
		  }
		  return a;
		}
		~DynamicStack(){
			this->~DynamicArray();
		}
};




#endif /* DYNAMICSTACK_H_ */
