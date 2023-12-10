#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
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
				SearchInputBox(TextBox^ textBox, String^ placeholder, DataGridView^ dataGridView);

			protected:
				DataGridView^ __dataGridView;
				//DataSet^ __originalDataSet;

				void __onKeyDown(Object^ sender, KeyEventArgs^ e);
				void __onTextChanged(Object^ sender, EventArgs^ e);

				static String^ __searchRegex = "(?<=\\s+|^)(?:(?<property>[a-z0-9_]+=(?:(?<!\\\\)'(?:[^']|\\\\')+(?<!\\\\)'|(?:\\\\\\s|[^\\s])+))|(?<keywords>(?<!\\\\)'(?:[^']|\\\\')+(?<!\\\\)')|(?<keyword>(?:\\\\\\s|[^\\s])+))(?=\\s+|$)";
				static String^ __searchPropertyRegex = "^(?<name>[a-z0-9_]+)=(?<value>(?:(?<!\\\\)'(?:[^']|\\\\'|[\\s\\t])+(?<!\\\\)'|(?:\\\\\\s|[^\\s])+))$";
				static String^ __searchRemoveCharsRegex = "(?<!\\\\)'|\\\\";
				static String^ __searchPrefixRegex = "[()[\\]?*.+|{}^$]";
				static String^ __searchPrefixReplace = "\\$&";
				static int __searchCompare(array<int>^ a, array<int>^ b);
			};

			private ref class SearchComparer : System::Collections::IComparer {
			public:
				SearchComparer(array<array<int>^>^ scores) {
					this->__scores = scores;
				}

				virtual int Compare(Object^ a, Object^ b) {
					return 0;
				}
			private:
				array<array<int>^>^ __scores;
			};
		}
	}
}