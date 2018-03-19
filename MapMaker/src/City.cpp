#include "City.h"

City::City()
{
	name = "";
	state = "";
	Coordinate coor;
	coordinate = coor;
}

City::City(string name, string state, Coordinate coordinate):name(name), state(state), coordinate(coordinate) { }

string City::get_name()
{
	return name;
}

string City::get_state()
{
	return state;
}

Coordinate City::get_coordinate()
{
	return coordinate;
}

void parsestring(vector<string> &dataout, string &datain, const string &delimiter)
{
	dataout.clear();
	size_t pos = 0;
	std::string token;
	while ((pos = datain.find(delimiter)) != std::string::npos) {
	    token = datain.substr(0, pos);
	    dataout.push_back(token);
	    datain.erase(0, pos + delimiter.length());
	}
	dataout.push_back(datain);
}

istream& operator >>(istream& ins, City& city)
{
	string data;
	getline(ins, data, '\n');
	vector<string> vecdata;
	parsestring(vecdata, data, ",");
	if(vecdata.size() == 4)
	{
		city.name = vecdata[0];
		city.state = vecdata[1];
		Coordinate coor(stod(vecdata[2]), stod(vecdata[3]));
		city.coordinate = coor;
	}
	return ins;
}

ostream& operator <<(ostream& outs, const City& city)
{
	outs << "*" << city.name << " " << city.state << endl;
	return outs;
}
