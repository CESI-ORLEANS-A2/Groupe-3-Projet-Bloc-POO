#pragma once

//#include "../Database.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text::RegularExpressions;
using namespace System::Configuration;

namespace Groupe3ProjetBlocPOO {

	/// <summary>
	/// Summary for SettingsForm
	/// </summary>
	public ref class SettingsForm : public System::Windows::Forms::Form
	{
	public:
		SettingsForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SettingsForm()
		{
			if (components)
			{
				delete components;
			}
		}

	//protected: Database^ database;
	protected: String^ regexHostname = "^([a-z\\-_0-9]+\\.[a-z]{2,3}|localhost|([0-9]{1,3}\\.){3}[0-9]{1,3})$";
	protected: String^ regexSplit = "server=(?<hostname>[^;]+);database=(?<database>[^;]+);uid=(?<username>[^;]+);pwd=(?<password>[^;]+);";
	protected: String^ dbName;
	protected: System::Windows::Forms::Label^ label_settings;
	protected: System::Windows::Forms::TextBox^ textBox_hostname;
	protected: System::Windows::Forms::TextBox^ textBox_username;
	protected: System::Windows::Forms::TextBox^ textBox_password;
	protected: System::Windows::Forms::Button^ button_test;
	protected: System::Windows::Forms::Button^ button_validate;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			int winHeight = 460;
			int winWidth = 460;
			float textBoxFactor = 0.6;
			float buttonFactor = 0.3;
			float buttonCenter = (winWidth / 2) - ((winWidth * buttonFactor) / 2);

			this->label_settings = (gcnew System::Windows::Forms::Label());
			this->textBox_hostname = (gcnew System::Windows::Forms::TextBox());
			this->textBox_username = (gcnew System::Windows::Forms::TextBox());
			this->textBox_password = (gcnew System::Windows::Forms::TextBox());
			this->button_test = (gcnew System::Windows::Forms::Button());
			this->button_validate = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label_settings
			// 
			this->label_settings->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_settings->Location = System::Drawing::Point(0, 0);
			this->label_settings->Name = L"label_settings";
			this->label_settings->TabIndex = 0;
			this->label_settings->Text = L"Settings";
			this->label_settings->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 20, System::Drawing::FontStyle::Bold);
			this->label_settings->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label_settings->Padding = System::Windows::Forms::Padding(0, (winWidth / 8), 0, 0);
			// 
			// textBox_hostname
			// 
			this->textBox_hostname->Location = System::Drawing::Point(
				(winWidth / 2) - (winWidth * textBoxFactor / 2),
				(winHeight - (winHeight / 1.4))
			);
			this->textBox_hostname->Name = L"textBox_hostname";
			this->textBox_hostname->Size = System::Drawing::Size(winWidth * textBoxFactor, 24);
			this->textBox_hostname->TabIndex = 1;
			this->textBox_hostname->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox_hostname->TextChanged += gcnew System::EventHandler(this, &SettingsForm::textBox_hostname_TextChange);
			this->textBox_hostname->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SettingsForm::OnKeyDown);
			// 
			// textBox_username
			// 
			this->textBox_username->Location = System::Drawing::Point(
				(winWidth / 2) - (winWidth * textBoxFactor / 2),
				(winHeight - (winHeight / 1.8))
			);
			this->textBox_username->Name = L"textBox_username";
			this->textBox_username->Size = System::Drawing::Size(winWidth * textBoxFactor, 24);
			this->textBox_username->TabIndex = 2;
			this->textBox_username->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox_username->TextChanged += gcnew System::EventHandler(this, &SettingsForm::textBox_username_TextChange);
			this->textBox_username->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SettingsForm::OnKeyDown);
			// 
			// textBox_password
			// 
			this->textBox_password->Location = System::Drawing::Point(
				(winWidth / 2) - (winWidth * textBoxFactor / 2),
				(winHeight - (winHeight / 2.55))
			);
			this->textBox_password->Name = L"textBox_password";
			this->textBox_password->Size = System::Drawing::Size(winWidth * textBoxFactor, 24);
			this->textBox_password->TabIndex = 3;
			this->textBox_password->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14));
			this->textBox_password->PasswordChar = '*';
			this->textBox_password->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SettingsForm::OnKeyDown);
			// 
			// button_test
			// 
			this->button_test->Location = System::Drawing::Point(
				buttonCenter - (winWidth * 0.2),
				(winHeight * 0.8)
			);
			this->button_test->Name = L"button_test";
			this->button_test->Size = System::Drawing::Size(
				(winWidth * buttonFactor),
				(winHeight * 0.1)
			);
			this->button_test->TabIndex = 4;
			this->button_test->Text = L"Test";
			this->button_test->UseVisualStyleBackColor = true;
			this->button_test->Enabled = false;
			this->button_test->Click += gcnew System::EventHandler(this, &SettingsForm::button_test_Click);
			this->button_test->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &SettingsForm::OnKeyDown);
			// 
			// button_validate
			// 
			this->button_validate->Location = System::Drawing::Point(
				buttonCenter + (winWidth * 0.2),
				(winHeight * 0.8)
			);
			this->button_validate->Name = L"button_validate";
			this->button_validate->Size = System::Drawing::Size(
				(winWidth * buttonFactor),
				(winHeight * 0.1)
			);
			this->button_validate->TabIndex = 5;
			this->button_validate->Text = L"Validate";
			this->button_validate->UseVisualStyleBackColor = true;
			this->button_validate->Enabled = false;
			this->button_validate->Click += gcnew System::EventHandler(this, &SettingsForm::button_validate_Click);
			// 
			// SettingsForm
			// 
			this->getConfig();
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(winWidth, winHeight);
			this->Controls->Add(this->button_validate);
			this->Controls->Add(this->button_test);
			this->Controls->Add(this->textBox_password);
			this->Controls->Add(this->textBox_username);
			this->Controls->Add(this->textBox_hostname);
			this->Controls->Add(this->label_settings);
			this->Name = L"SettingsForm";
			this->Text = L"Settings";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		System::Void button_test_Click(System::Object^ sender, System::EventArgs^ e) {
			this->initDatabase();
		}
		System::Void OnKeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
			if (e->KeyCode == Keys::Enter) {
				this->initDatabase();
			}
		}
		System::Void textBox_hostname_TextChange(System::Object^ sender, System::EventArgs^ e) {
			checkAllFields();
		}
		System::Void textBox_username_TextChange(System::Object^ sender, System::EventArgs^ e) {
			checkAllFields();
		}
		System::Void button_validate_Click(System::Object^ sender, System::EventArgs^ e) {
			String^ hostname = textBox_hostname->Text->Trim();
			String^ username = textBox_username->Text->Trim();
			String^ password = textBox_password->Text->Trim();

			if (dbName == "") dbName = "projet_poo";

			ConfigurationManager::AppSettings["connection_string"] = "server=" + hostname + ";database=" + dbName + ";uid=" + username + ";pwd=" + password + ";";

			this->Close();
		}
		void initDatabase() {
			if (!checkAllFields()) {
				return;
			}

			String^ hostname = textBox_hostname->Text->Trim();
			String^ username = textBox_username->Text->Trim();
			String^ password = textBox_password->Text->Trim();

			/*database = gcnew Database(hostname, username, password);
			int code = database->testConnection();*/

			int code = 0;

			if (code) {
				button_test->BackColor = Color::Red;
				return;
			}

			this->button_test->BackColor = Color::Green;
			this->button_validate->Enabled = true;

		}
		bool checkAllFields() {
			this->button_validate->Enabled = false;
			this->button_test->Enabled = false;
			if (!Regex::IsMatch(textBox_hostname->Text->Trim(), regexHostname, RegexOptions::IgnoreCase)) {
				textBox_hostname->ForeColor = Color::Red;
				return false;
			}

			bool test = Regex::IsMatch(textBox_hostname->Text->Trim(), regexHostname, RegexOptions::IgnoreCase);

			textBox_hostname->ForeColor = Color::Black;

			if (textBox_username->Text->Trim() == "") {
				return false;
			}

			this->button_test->Enabled = true;
			return true;
		}
		void getConfig() {
			String^ connString = ConfigurationManager::AppSettings["connection_string"];
			Regex^ rgx = gcnew Regex(regexSplit);
			Match^ match_ = rgx->Match(connString);
			Match^ match = Regex::Match(connString, regexSplit, RegexOptions::IgnoreCase);
			if (!match_->Success) {
				return;
			}

			textBox_hostname->Text = match_->Groups["hostname"]->Value;
			textBox_username->Text = match_->Groups["username"]->Value;
			textBox_password->Text = match_->Groups["password"]->Value;
			dbName = match_->Groups["database"]->Value;
		}
	};
}
