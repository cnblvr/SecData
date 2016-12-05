#include "Settings.h"
using namespace laba3;

Dictionary<String^,String^>^ Settings::ReadFile(String ^path)
{
	String ^file = String::Empty;
	if(File::Exists(path))
	{
		StreamReader ^sr = File::OpenText(path);
		try { file = sr->ReadToEnd(); }
		catch(...) { throw gcnew Exception("Ошибка при чтении файла настроек."); }
		finally { if(sr) sr->Close(); }
	}
	else
		throw gcnew Exception("Файл "+path+" не найден.");
	Regex ^rx = gcnew Regex("\\[(?<key>[a-z0-9_]+)\\] (?<value>[^\\r\\n]*)\\r?\\n?");
	MatchCollection ^matches = rx->Matches(file);
	Dictionary<String^,String^> ^settings = gcnew Dictionary<String^,String^>();
	for each(Match ^match in matches)
		settings->Add(match->Groups["key"]->Value, match->Groups["value"]->Value);
	for each(String ^r in required)
		if(!settings->ContainsKey(r))
			throw gcnew Exception("Значения для ключа "+r+" нет.");
	return settings;
}
void Settings::WriteFile(String ^path, Dictionary<String^,String^> ^settings)
{
	String ^file = "";
	for each (KeyValuePair<String^,String^> pair in settings)
	{
		file += "["+pair.Key+"] "+pair.Value+Environment::NewLine;
	}
	char *ch = (char*)(void*)Marshal::StringToHGlobalAnsi(file);
	array<unsigned char> ^arr = gcnew array<unsigned char>(strlen(ch));
	for(int i=0; i<arr->Length; i++)
		arr[i] = ch[i];

	if(File::Exists(path))
	{
		FileStream ^fs;
		try
		{
			fs = File::OpenWrite(path);
			fs->Write(arr, 0, arr->Length);
		}
		catch(...) { throw gcnew Exception("Ошибка при записи файла настроек."); }
		finally { if(fs) fs->Close(); }
	}
	else
		throw gcnew Exception("Файл "+path+" не найден.");
}