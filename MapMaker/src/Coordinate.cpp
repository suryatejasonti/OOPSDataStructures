#include "Coordinate.h"

/**
 * Maximum latitude and minimum longitude for this app's input data.
 */
const double Coordinate::MAX_LATITUDE  =   49.373112;
const double Coordinate::MIN_LONGITUDE = -124.769867;


Coordinate::Coordinate():latitude(0), longitude(0) { }

Coordinate::Coordinate(double latitude, double longitude):latitude(latitude), longitude(longitude) { }

double Coordinate::get_latitude() const
{
	return latitude;
}

double Coordinate::get_longitude() const
{
	return longitude;
}

void stringparse(vector<string> &dataout, string &datain, const string &delimiter)
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

istream& operator >>(istream& ins, Coordinate& coordinate)
{
	/* read line and parse string to get two variables*/
	string data;
	vector<string> vecdata;
	getline(ins, data, '\n');
	stringparse(vecdata, data, ",");
	if(vecdata.size() == 2)
	{
		coordinate.latitude = stod(vecdata[0]);
		coordinate.longitude = stod(vecdata[1]);
	}
	return ins;
}
ostream& operator <<(ostream& outs, const Coordinate& coordinate)
{
	/* print # */
	outs << "#";
	return outs;
}
