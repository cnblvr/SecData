#pragma once
#include "Letter.h"
#include "RussianStatistical.h"

namespace laba1
{
	using namespace System;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Text::RegularExpressions;

	ref class Frequency
	{
	private:
		array<Letter^> ^letters;
		int quantity;
	public:
		Frequency(String ^language);
		void CheckText(String ^text);
		void PrintFrequency(DataGridView ^table);
		void Decode();
	};
}