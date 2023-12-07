#include "Utils.h"

void Groupe3ProjetBlocPOO::Utils::openLink(String^ link) {
	Diagnostics::Process::Start(link);
}
void Groupe3ProjetBlocPOO::Utils::openLink(String^ link, LinkLabel^ label) {
	Diagnostics::Process::Start(link);
	label->LinkVisited = true;
}
Int64^ Groupe3ProjetBlocPOO::Utils::toTimestamp() {
	return (gcnew DateTimeOffset(DateTime::Now))->ToUnixTimeMilliseconds();
}
Int64^ Groupe3ProjetBlocPOO::Utils::toTimestamp(DateTime^ date) {
	return (gcnew DateTimeOffset(*date))->ToUnixTimeMilliseconds();
}
DateTime^ Groupe3ProjetBlocPOO::Utils::fromTimestamp(Int64^ timestamp) {
	return (gcnew DateTimeOffset(*timestamp, TimeSpan::Zero))->DateTime;
}

Groupe3ProjetBlocPOO::Utils::ElementsCustomization::CustomizeTextBox::CustomizeTextBox() { };
Groupe3ProjetBlocPOO::Utils::ElementsCustomization::CustomizeTextBox::CustomizeTextBox(TextBox^ textBox, String^ placeholder) {
	this->__textBox = textBox;
	this->__placeholder = placeholder;

	textBox->Text = placeholder;
	textBox->ForeColor = Color::Gray;

	textBox->GotFocus += gcnew EventHandler(this, &CustomizeTextBox::__onFocus);
	textBox->LostFocus += gcnew EventHandler(this, &CustomizeTextBox::__onUnfocus);
}
Groupe3ProjetBlocPOO::Utils::ElementsCustomization::CustomizeTextBox::CustomizeTextBox(
	TextBox^ textbox,
	String^ placeholder,
	String^ regexValidation,
	RegexOptions regexOptions
) : CustomizeTextBox(textbox, placeholder) {
	this->__regexValidation = regexValidation;
	this->__regexOptions = regexOptions;

	this->__textBox->TextChanged += gcnew EventHandler(this, &CustomizeTextBox::__onTextChanged);
}
void Groupe3ProjetBlocPOO::Utils::ElementsCustomization::CustomizeTextBox::__onFocus(Object^ sender, EventArgs^ e) {
	if (!this->__textBox->Text->Equals(this->__placeholder)) return;

	this->__textBox->ForeColor = Color::Black;
	this->__textBox->Text = "";
}
void Groupe3ProjetBlocPOO::Utils::ElementsCustomization::CustomizeTextBox::__onUnfocus(Object^ sender, EventArgs^ e) {
	if (!this->__textBox->Text->Equals("")) return;

	this->__textBox->ForeColor = Color::Gray;
	this->__textBox->Text = this->__placeholder;
}
void Groupe3ProjetBlocPOO::Utils::ElementsCustomization::CustomizeTextBox::__onTextChanged(Object^ sender, EventArgs^ e) {
	if (this->__regexValidation == nullptr) return;
	if (this->__textBox->Text == this->__placeholder) return;

	if (Regex::IsMatch(this->__textBox->Text, this->__regexValidation, this->__regexOptions)) {
		this->__textBox->ForeColor = Color::Black;
	}
	else {
		this->__textBox->ForeColor = Color::Red;
	}
}

// ========================================================
// =                      SearchBox                       =
// ========================================================

Groupe3ProjetBlocPOO::Utils::ElementsCustomization::SearchInputBox::SearchInputBox() {
	if (!SearchInputBox::__searchRegexMatchGroups->Count) {
		SearchInputBox::__searchRegexMatchGroups->Add("property");
		SearchInputBox::__searchRegexMatchGroups->Add("keyword");
		SearchInputBox::__searchRegexMatchGroups->Add("keywords");
	}
}
Groupe3ProjetBlocPOO::Utils::ElementsCustomization::SearchInputBox::SearchInputBox(TextBox^ textBox, String^ placeholder) : CustomizeTextBox(textBox, placeholder) {
	SearchInputBox::SearchInputBox();

	textBox->KeyDown += gcnew KeyEventHandler(this, &SearchInputBox::__onKeyDown);
}
Groupe3ProjetBlocPOO::Utils::ElementsCustomization::SearchInputBox::SearchInputBox(TextBox^ textBox, String^ placeholder, DataGridView^ dataGridView) :
	CustomizeTextBox(textBox, placeholder), __dataGridView(dataGridView) {
	SearchInputBox::SearchInputBox();

	this->__textBox->KeyDown += gcnew KeyEventHandler(this, &SearchInputBox::__onKeyDown);

	this->__textBox->TextChanged += gcnew EventHandler(this, &SearchInputBox::__onTextChanged);
}
void Groupe3ProjetBlocPOO::Utils::ElementsCustomization::SearchInputBox::__onKeyDown(Object^ sender, KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter) {
		e->SuppressKeyPress = true;
		this->__textBox->Parent->Focus();
	}
}
void Groupe3ProjetBlocPOO::Utils::ElementsCustomization::SearchInputBox::__onTextChanged(Object^ sender, EventArgs^ e) {
	__super::__onTextChanged(sender, e);

	if (this->__dataGridView == nullptr) return;

	if (this->__textBox->TextLength == 0) {
		for (int i = 0; i < this->__dataGridView->RowCount; i++) {
			this->__dataGridView->Rows[i]->Visible = true;
		}
		return;
	}
	if (this->__textBox->Text == this->__placeholder) return;

	array<array<int>^>^ scores = gcnew array<array<int>^>(this->__dataGridView->RowCount-1);
	for (int i = 0; i < this->__dataGridView->RowCount-1; i++) {
		scores[i] = gcnew array<int>(2) { i, 0 };
	}

	MatchCollection^ matches = Regex::Matches(this->__textBox->Text, SearchInputBox::__searchRegex, RegexOptions::IgnoreCase);
	for each (Match ^ match in matches) {
		for (int i = 0; i < this->__dataGridView->RowCount; i++) {
			DataGridViewRow^ row = this->__dataGridView->Rows[i];
			if (row->IsNewRow) continue;

			String^ keyword = "";

			for (int j = 1; j < match->Groups->Count; j++) {
				if (SearchInputBox::__searchRegexMatchGroups->Contains(match->Groups[j]->Name)) {
					keyword = match->Groups[j]->Value;
					break;
				}
			}

			Match^ propertyMatch = Regex::Match(keyword, SearchInputBox::__searchPropertyRegex, RegexOptions::IgnoreCase);

			if (propertyMatch->Success) {
				String^ propertyName = propertyMatch->Groups[1]->Value;
				String^ propertyValue = propertyMatch->Groups[2]->Value;

				propertyValue = Regex::Replace(propertyValue, SearchInputBox::__searchRemoveQuotesRegex, "");

				for (int j = 0; j < row->Cells->Count; j++) {
					DataGridViewCell^ cell = row->Cells[j];
					if (cell->Value == nullptr) continue;

					String^ columnName = this->__dataGridView->Columns[i]->Name;

					if (columnName->Equals(propertyName, StringComparison::OrdinalIgnoreCase)) {
						if (Regex::IsMatch(cell->Value->ToString(), propertyValue, RegexOptions::IgnoreCase)) {
							scores[i][1]++;
						}
					}
				}
			}
			else {
				for (int j = 0; j < row->Cells->Count; j++) {
					DataGridViewCell^ cell = row->Cells[j];
					if (cell->Value == nullptr) continue;

					keyword = Regex::Replace(keyword, SearchInputBox::__searchRemoveQuotesRegex, "");

					if (Regex::IsMatch(cell->Value->ToString(), keyword, RegexOptions::IgnoreCase)) {
						scores[i][1]++;
					}
				}
			}

		}
	}

	Array::Sort(scores, gcnew Comparison<array<int>^>(SearchInputBox::__searchCompare));

	for (int i = 0; i < scores->Length; i++) {
		this->__dataGridView->Rows[scores[i][0]]->Visible = !!scores[i][1];
	}
}

int Groupe3ProjetBlocPOO::Utils::ElementsCustomization::SearchInputBox::__searchCompare(array<int>^ a, array<int>^ b) {
	return b[1] - a[1];
}