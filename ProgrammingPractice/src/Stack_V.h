/*
 * Q3.h
 *
 *  Created on: Oct 11, 2018
 *      Author: suryasonti
 */

#ifndef STACK_V_H_
#define STACK_V_H_
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <stdexcept>

using namespace std;

template <class T>
class Stack {

   public:
	  Stack(){

	  }
	  Stack(vector<T> vec){
		  elements = vec;
	  }
      void push(T const& elem){
    	     // append copy of passed element
    	  	elements.push_back(elem);
      }
      T pop(){
    	   if (elements.empty()) {
    	      throw out_of_range("Stack<>::pop(): empty stack");
    	  }
    	   int number = elements[elements.size() - 1];
    	   // remove last element
    	   elements.pop_back();
    	   return number;
      }
      T top() const {
    	   if (elements.empty()) {
    	      throw out_of_range("Stack<>::top(): empty stack");
    	  }
    	   // return copy of last element
    	   return elements.back();
      }
      bool size() const {      // return true if empty.
         return elements.size();
      }
   private:
	 vector<T> elements;
};

#endif /* STACK_V_H_ */
