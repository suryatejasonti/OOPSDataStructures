#include "DataAllZeros.h"

DataAllZeros::DataAllZeros() : DataGenerator("All zeroes") {}


DataAllZeros::~DataAllZeros() {}


void DataAllZeros::generate_data(vector<Element>& data, int size)
{
    for (int i = 0; i < size; i++) data.push_back(Element(0));
}
