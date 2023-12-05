#include "Utils.h"

void Groupe3ProjetBlocPOO::openLink(String^ link) {
	Diagnostics::Process::Start(link);
}
void Groupe3ProjetBlocPOO::openLink(String^ link, LinkLabel^ label) {
	Diagnostics::Process::Start(link);
	label->LinkVisited = true;
}

Groupe3ProjetBlocPOO::ElementsCustomization::CustomizeTextBox::CustomizeTextBox() {};
Groupe3ProjetBlocPOO::ElementsCustomization::CustomizeTextBox::CustomizeTextBox(TextBox^ textBox, String^ placeholder)
{
	this->__textBox = textBox;
	this->__placeholder = placeholder;

	textBox->Text = placeholder;
	textBox->ForeColor = Color::Gray;

	textBox->GotFocus += gcnew EventHandler(this, &ElementsCustomization::CustomizeTextBox::__onFocus);
	textBox->LostFocus += gcnew EventHandler(this, &ElementsCustomization::CustomizeTextBox::__onUnfocus);
}
void Groupe3ProjetBlocPOO::ElementsCustomization::CustomizeTextBox::__onFocus(Object^ sender, EventArgs^ e) {
	if (!this->__textBox->Text->Equals(this->__placeholder)) return;

	this->__textBox->ForeColor = Color::Black;
	this->__textBox->Text = "";
}
void Groupe3ProjetBlocPOO::ElementsCustomization::CustomizeTextBox::__onUnfocus(Object^ sender, EventArgs^ e) {
	if (!this->__textBox->Text->Equals("")) return;

	this->__textBox->ForeColor = Color::Gray;
	this->__textBox->Text = this->__placeholder;
}

Groupe3ProjetBlocPOO::ElementsCustomization::SearchInputBox::SearchInputBox() { }
Groupe3ProjetBlocPOO::ElementsCustomization::SearchInputBox::SearchInputBox(TextBox^ textBox, String^ placeholder) : CustomizeTextBox(textBox, placeholder) {
	textBox->KeyDown += gcnew KeyEventHandler(this, &SearchInputBox::__onKeyDown);
}
void Groupe3ProjetBlocPOO::ElementsCustomization::SearchInputBox::__onKeyDown(Object^ sender, KeyEventArgs^ e) {
	if (e->KeyCode == Keys::Enter) {
		e->SuppressKeyPress = true;
		this->__textBox->Parent->Focus();
	}
}
