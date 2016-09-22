#pragma once

namespace laba1
{
	using namespace System;

	ref class Letter
	{
	public:
		property Char ch;
		property int quantity;
		property double frequency;
		property Char replacement;
		property array<Char> ^maybe;
	public:
		Letter(Char c_);
	};

	int ComparisonLetter(Letter ^a, Letter ^b);
}
