#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;

namespace Groupe3ProjetBlocPOO {
	void openLink(String^ link);
	void openLink(String^ link, LinkLabel^ label);

	namespace ElementsCustomization {
		public ref class CustomizeTextBox {
		public:
			CustomizeTextBox();
			CustomizeTextBox(TextBox^ textBox, String^ placeholder);

		protected:
			void __onFocus(Object^ sender, EventArgs^ e);
			void __onUnfocus(Object^ sender, EventArgs^ e);

			TextBox^ __textBox;
			String^ __placeholder;
		};

		public ref class SearchInputBox : public CustomizeTextBox {
		public :
			SearchInputBox();
			SearchInputBox(TextBox^ textBox, String^ placeholder);

		protected:
			void __onKeyDown(Object^ sender, KeyEventArgs^ e);
		};
	}
}