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

	if (Regex::IsMatch(this->__textBox->Text, this->__regexValidation, this->__regexOptions)) {
		this->__textBox->ForeColor = Color::Black;
	}
	else {
		this->__textBox->ForeColor = Color::Red;
	}
}

Groupe3ProjetBlocPOO::Utils::ElementsCustomization::SearchInputBox::SearchInputBox() { }
Groupe3ProjetBlocPOO::Utils::ElementsCustomization::SearchInputBox::SearchInputBox(TextBox^ textBox, String^ placeholder) : CustomizeTextBox(textBox, placeholder) {
	textBox->KeyDown += gcnew KeyEventHandler(this, &SearchInputBox::__onKeyDown);
}
void Groupe3ProjetBlocPOO::Utils::ElementsCustomization::SearchInputBox::__onKeyDown(Object^ sender, KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter) {
		e->SuppressKeyPress = true;
		this->__textBox->Parent->Focus();
	}
}
