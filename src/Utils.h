#pragma once

using namespace System;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Text::RegularExpressions;

namespace Groupe3ProjetBlocPOO {
	namespace Utils {
		void openLink(String^ link);
		void openLink(String^ link, LinkLabel^ label);
		Int64^ toTimestamp();
		Int64^ toTimestamp(DateTime^);
		DateTime^ fromTimestamp(Int64^ timestamp);

		namespace ElementsCustomization {
			public ref class CustomizeTextBox {
			public:
				CustomizeTextBox();
				CustomizeTextBox(TextBox^ textBox, String^ placeholder);
				CustomizeTextBox(TextBox^ textBox, String^ placeholder, String^ regexValidation, RegexOptions regexOptions);

			protected:
				void __onFocus(Object^ sender, EventArgs^ e);
				void __onUnfocus(Object^ sender, EventArgs^ e);
				void __onTextChanged(Object^ sender, EventArgs^ e);

				TextBox^ __textBox;
				String^ __placeholder;
				String^ __regexValidation;
				RegexOptions __regexOptions;
			};

			public ref class SearchInputBox : public CustomizeTextBox {
			public:
				SearchInputBox();
				SearchInputBox(TextBox^ textBox, String^ placeholder);

			protected:
				void __onKeyDown(Object^ sender, KeyEventArgs^ e);
			};
		}
	}
}