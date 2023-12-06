#pragma once

#include "./Components/Forms/MainForm.h"
#include "./Utils.h"

using namespace System::Data;
using namespace Groupe3ProjetBlocPOO;
using namespace System::Configuration;
using namespace System::Collections::Generic;

using namespace Groupe3ProjetBlocPOO;
using namespace Groupe3ProjetBlocPOO::Utils;

namespace Groupe3ProjetBlocPOO {
	public ref class App : public MainForm {
	public:
		App(void);

	protected:
		void InitializeComponent(void);

		void tabControl_Tabs_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) override;

		void linkLabel_Help_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) override;
		void linkLabel_AuthorAbepan_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) override;
		void linkLabel_AuthorBeboudu32_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) override;
		void linkLabel_Author0xybo_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) override;

	private:
	};

}


