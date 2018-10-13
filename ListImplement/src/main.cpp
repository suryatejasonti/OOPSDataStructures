#include<iostream>
#include "RandomNumberBucket.h"

using namespace std;

int main(){
	RandomNumberBucket randombucket;
	cout << "Now my size is: " <<randombucket.Size() << endl;
	cout << "Am i empty?: " <<randombucket.Empty() << endl;
	for(int i =0; i< 39; i++){
		cout<< "I am deleted from list: "<< randombucket.Pop() << endl;
	}
	cout << "Now my size is: " <<randombucket.Size() << endl;
	cout << "I am deleting after empty: " << randombucket.Pop() << endl;
	cout << "Am i empty?: " <<randombucket.Empty() << endl;
	cout << "I am deleting and refilling: " <<randombucket.PopwithRefill() << endl;
	cout << "Now my size is: " <<randombucket.Size() << endl;
}
