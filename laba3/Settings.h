#pragma once
#include <cstring>

namespace laba3
{
	using namespace System;
	using namespace System::Collections::Generic;
	using namespace System::Text::RegularExpressions;
	using namespace System::IO;
	using namespace System::Windows::Forms;
	using namespace System::Runtime::InteropServices;

	static ref class Settings
	{
		static array<String^> ^required = gcnew array<String^>{}; //"des_key", "des_iv"};
	public:
		static Dictionary<String^,String^>^ ReadFile(String ^path);
		static void WriteFile(String ^path, Dictionary<String^,String^> ^settings);
	};
}