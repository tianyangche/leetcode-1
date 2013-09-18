#include "Sum.h"


Sum::Sum(void)
{
}

Sum::Sum(int value) {
	this->value = value;
}

Sum::Sum(int value, int x, int y) {
	this->value = value;
	this->x		= x;
	this->y		= y;
}

bool Sum::operator < (const Sum &comp) const {
	return this->value < comp.value;
}

Sum::~Sum(void)
{
}
