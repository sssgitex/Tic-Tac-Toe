
#include "MainForm.h"
#include <windows.h>

using namespace System;
using namespace System::Windows::Forms;

int main(array<String^>^ args)
{
	FreeConsole();
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	krestiki::MainForm form;
	Application::Run(% form);
	
	return 0;
}