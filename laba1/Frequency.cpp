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

void Frequency::CheckText(String ^t, double precision)
{
	text = t;
	Regex ^rx = gcnew Regex("[^à-ÿ¸]", RegexOptions::IgnoreCase);
	t = rx->Replace(t, "");
	quantity = t->Length;
	for(int i=0; i<t->Length; i++)
		for(int ch=0; ch<letters->Length; ch++)
			if(String::Compare(t[i].ToString(), letters[ch]->ch.ToString(), true) == 0)
			{
				letters[ch]->quantity++;
				break;
			}
	for(int i=0; i<letters->Length; i++)
		letters[i]->frequency = double(letters[i]->quantity)/double(quantity);
	Array::Sort(letters, gcnew Comparison<Letter^>(ComparisonLetter));
	array<Letter^> ^statistical = gcnew array<Letter^>(letters->Length);
	for(int i=0; i<statistical->Length; i++)
	{
		statistical[i] = gcnew Letter(letters[i]->ch);
		statistical[i]->frequency = RussianStatistical::getFrequency(letters[i]->ch);
	}
	Array::Sort(statistical, gcnew Comparison<Letter^>(ComparisonLetter));
	for(int i=0; i<statistical->Length; i++)
		letters[i]->replacement = statistical[i]->ch;
	for(int i=0; i<letters->Length; i++)
	{
		List<Char> ^maybe = gcnew List<Char>;
		for(int j=0; j<statistical->Length; j++)
			if(statistical[j]->frequency >= letters[i]->frequency-precision
				&& statistical[j]->frequency <= letters[i]->frequency+precision)
				maybe->Add(statistical[j]->ch);
		letters[i]->maybe = maybe->ToArray(); //gcnew array<Char>(statistical->Length);
		//for(int i=0; i<
	}
}
void Frequency::PrintFrequency(DataGridView ^table)
{
	table->Rows->Clear();
	for(int i=0; i<letters->Length; i++)
	{
		String ^maybe = "";
		for(int j=0; j<letters[i]->maybe->Length; j++)
			maybe += letters[i]->maybe[j].ToString() + ", ";
		maybe = maybe->Trim(' ')->Trim(',');
		table->Rows->Add(
			letters[i]->ch.ToString(),
			letters[i]->quantity.ToString(),
			letters[i]->frequency.ToString("0.0000"),
			nullptr,
			maybe
		);
		
		DataGridViewComboBoxCell ^cell = (DataGridViewComboBoxCell^)table->Rows[table->RowCount-1]->Cells["dgv_c_Replacement"];
		Char ch = L'à';
		for(int j=0; j<33; j++)
		{
			cell->Items->Add(ch.ToString());
			if(ch == L'å')
				ch = L'¸';
			else if(ch == L'¸')
				ch = L'æ';
			else
				ch++;
		}
		//MessageBox::Show(letters[i]->replacement.ToString());
		cell->Value = letters[i]->replacement.ToString();
	}
}
String^ Frequency::Decode()
{
	String ^decoded = "";
	for(int i=0; i<text->Length; i++)
	{
		bool found = false;
		for(int j=0; j<letters->Length; j++)
		{
			if(String::Compare(letters[j]->ch.ToString(), text[i].ToString()) == 0)
			{
				decoded += letters[j]->replacement.ToString();
				found = true;
				break;
			}
			else if(String::Compare(letters[j]->ch.ToString()->ToUpper(), text[i].ToString()) == 0)
			{
				decoded += letters[j]->replacement.ToString()->ToUpper();
				found = true;
				break;
			}
		}
		if(!found)
			decoded += text[i];
	}
	return decoded;
}
void Frequency::SetReplacement(Char ch, Char rep)
{
	for(int i=0; i<letters->Length; i++)
		if(letters[i]->ch == ch)
		{
			letters[i]->replacement = rep;
			return;
		}
}