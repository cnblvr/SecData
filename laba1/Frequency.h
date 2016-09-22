#pragma once
#include "Letter.h"
#include "RussianStatistical.h"

namespace laba1
{
	using namespace System;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Text::RegularExpressions;
	using namespace System::Collections::Generic;

	ref class Frequency
	{
	private:
		array<Letter^> ^letters;
		int quantity;
		String ^text;
	public:
		Frequency(String ^language);
		void CheckText(String ^text, double precision);
		void PrintFrequency(DataGridView ^table);
		String^ Decode();
		void SetReplacement(Char ch, Char rep);
	};
}