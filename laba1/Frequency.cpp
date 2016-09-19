#include "Frequency.h"
using namespace laba1;

Frequency::Frequency(String ^language)
{
	quantity = 0;
	if(language == "russian")
	{
		letters = gcnew array<Letter^>(33);
		Char ch = L'à';
		for(int i=0; i<33; i++)
		{
			letters[i] = gcnew Letter(ch);
			if(ch == L'å')
				ch = L'¸';
			else if(ch == L'¸')
				ch = L'æ';
			else
				ch++;
		}
	}
}

void Frequency::CheckText(String ^text)
{
	Regex ^rx = gcnew Regex("[^à-ÿ]", RegexOptions::IgnoreCase);
	text = rx->Replace(text, "");
	quantity = text->Length;
	for(int i=0; i<text->Length; i++)
		for(int ch=0; ch<letters->Length; ch++)
			if(String::Compare(text[i].ToString(), letters[ch]->ch.ToString(), true) == 0)
			{
				letters[ch]->quantity++;
				break;
			}
	for(int i=0; i<letters->Length; i++)
		letters[i]->frequency = double(letters[i]->quantity)/double(quantity);
	Array::Sort(letters, gcnew Comparison<Letter^>(ComparisonLetter));
}
void Frequency::PrintFrequency(DataGridView ^table)
{
	table->Rows->Clear();
	for(int i=0; i<letters->Length; i++)
		table->Rows->Add(letters[i]->ch.ToString(),
			letters[i]->quantity.ToString(),
			letters[i]->frequency.ToString("0.0000"),
			RussianStatistical::getFrequency(letters[i]->ch).ToString("0.0000")
		);
}
void Frequency::Decode()
{
	//todo
}