
#include "Main.hpp"


Vector::Vector()
{
	for (auto i = 0; i < 3; i++) {
		this->v[i] = 0;
	}
}

std::ostream& operator<<(std::ostream& os, const Vector& v)
{
	os << "<" << v.v[0] << "," << v.v[1] << "," << v.v[2] << ">\n";
	
	return os;
}
