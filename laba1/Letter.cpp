#include "Letter.h"
using namespace laba1;

Letter::Letter(Char c_)
{
	ch = c_;
	quantity = 0;
	frequency = 0;
}

int laba1::ComparisonLetter(Letter ^a, Letter ^b)
{
	if(a->quantity < b->quantity)
		return 1;
	else if(a->quantity > b->quantity)
		return -1;
	else
		return 0;
}