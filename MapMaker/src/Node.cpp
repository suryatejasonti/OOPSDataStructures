#include <math.h>
#include "Node.h"

Node::Node():next(nullptr), name(""), state(""), row(0), col(0) { }

Node::Node(City city)
{
	name = city.get_name();
	state = city.get_state();
	convert_coordinate(city.get_coordinate());
	next = nullptr;
}

Node::Node(Coordinate coordinate)
{
	name = "";
	state = "";
	convert_coordinate(coordinate);
	next = nullptr;
}

void Node::convert_coordinate(const Coordinate& coordinate)
{
    row = round(2*(Coordinate::MAX_LATITUDE - coordinate.get_latitude()));
    col = round(2*(coordinate.get_longitude() - Coordinate::MIN_LONGITUDE));
}

bool Node::operator >(const Node& other)
{
	return row > other.row
			|| (!(other.row > row) && col > other.col);
	//return row > other.row && col == other.col;
	//return row * row + col * col > other.row * other.row + other.col * other.col;
}

int Node::get_row()
{
	return row;
}

int Node::get_col()
{
	return col;
}

ostream& operator <<(ostream& outs, const Node& node)
{
	outs  << setfill(' ') << setw(node.col) << "#" << node.row << " " << node.col;
	return outs;
}
