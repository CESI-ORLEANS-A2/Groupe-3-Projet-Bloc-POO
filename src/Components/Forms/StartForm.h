#pragma once

#include "SettingsForm.h"
#include "../../Main.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

enum class UserTypes {
	ADMIN = 0,
	STOCK_EMPLOYEE = 1,
	CLIENT_EMPLOYEE = 2,
	ORDER_EMPLOYEE = 3,
	UNDEFINED = 4,
};

namespace Groupe3ProjetBlocPOO {
	/// <summary>
	/// Summary for StartForm
	/// </summary>
	public ref class StartForm : public System::Windows::Forms::Form {

	public:
		StartForm(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~StartForm()
		{
			if (components)
			{
				delete components;
			}
		}

	public: UserTypes types = UserTypes::UNDEFINED;
	protected: System::Windows::Forms::Button^ button_connect;
	protected: System::Windows::Forms::ComboBox^ comboBox_userBox;
	protected: System::Windows::Forms::Label^ label_login;
	protected: System::Windows::Forms::Panel^ panel_settingsButton;

	protected:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void) {
			int winHeight = 460;
			int winWidth = 430;

			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(StartForm::typeid));
			this->button_connect = (gcnew System::Windows::Forms::Button());
			this->comboBox_userBox = (gcnew System::Windows::Forms::ComboBox());
			this->label_login = (gcnew System::Windows::Forms::Label());
			this->panel_settingsButton = (gcnew System::Windows::Forms::Panel());
			this->SuspendLayout();
			// 
			// button_connect
			// 
			int buttonWidth = (int)(0.4 * winWidth);
			int buttonHeight = (int)(0.1 * winHeight);
			this->button_connect->Name = L"button_connect";
			this->button_connect->Size = System::Drawing::Size(buttonWidth, buttonHeight);
			this->button_connect->Location = System::Drawing::Point(
				(winWidth / 2) - (buttonWidth / 2), (winWidth / 1.3));
			this->button_connect->TabIndex = 1;
			this->button_connect->Text = L"Connect";
			this->button_connect->UseVisualStyleBackColor = true;
			this->button_connect->Click += gcnew System::EventHandler(this, &StartForm::button_connect_Click);
			// 
			// comboBox_userBox
			// 
			int comboWidth = (int)(0.5 * winWidth);
			this->comboBox_userBox->DrawMode = System::Windows::Forms::DrawMode::OwnerDrawVariable;
			this->comboBox_userBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox_userBox->DropDownWidth = 1;
			this->comboBox_userBox->FormattingEnabled = true;
			this->comboBox_userBox->Name = L"comboBox_userBox";
			this->comboBox_userBox->Size = System::Drawing::Size(comboWidth, 24);
			this->comboBox_userBox->Location = System::Drawing::Point(
				(winWidth / 2) - (comboWidth / 2) - 1, (winHeight / 2.8));
			this->comboBox_userBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20));
			array<String^>^ elements = { "Admin", "Stock", "Client", "Order" };
			this->comboBox_userBox->Items->AddRange(elements);
			this->comboBox_userBox->SelectedIndex = 0;
			this->comboBox_userBox->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &StartForm::comboBox_userBox_DrawItem);
			this->comboBox_userBox->MeasureItem += gcnew System::Windows::Forms::MeasureItemEventHandler(this, &StartForm::comboBox_userBox_MeasureItem);

			// 
			// label_login
			//
			this->label_login->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label_login->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 40));
			this->label_login->Location = System::Drawing::Point(0, 0);
			this->label_login->Name = L"label_login";
			this->label_login->Padding = System::Windows::Forms::Padding(0, (winWidth / 8), 0, 0);
			this->label_login->Size = System::Drawing::Size(460, 460);
			this->label_login->TabIndex = 2;
			this->label_login->Text = L"Login";
			this->label_login->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			// 
			// panel_settingsButton
			// 
			this->panel_settingsButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"SettingsIcon_48x48")));
			this->panel_settingsButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel_settingsButton->Location = System::Drawing::Point(13, 12);
			this->panel_settingsButton->Name = L"panel_settingsButton";
			this->panel_settingsButton->Size = System::Drawing::Size(48, 48);
			this->panel_settingsButton->TabIndex = 3;
			this->panel_settingsButton->Click += gcnew System::EventHandler(this, &StartForm::panel_settingsButton_Click);
			// 
			// StartForm
			// 
			//this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(winWidth, winHeight);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Resize += gcnew System::EventHandler(this, &StartForm::onResize);
			this->Controls->Add(this->panel_settingsButton);
			this->Controls->Add(this->comboBox_userBox);
			this->Controls->Add(this->button_connect);
			this->Controls->Add(this->label_login);
			this->Name = L"StartForm";
			this->Text = L"Login";
			this->ResumeLayout(false);

		}
#pragma endregion
		void button_connect_Click(System::Object^ sender, System::EventArgs^ e) {
			this->types = (UserTypes)comboBox_userBox->SelectedIndex;
			this->Close();
		}
		void panel_settingsButton_Click(System::Object^ sender, System::EventArgs^ e) {
			SettingsForm^ settingsForm = gcnew SettingsForm();
			settingsForm->ShowDialog();
		}
		void comboBox_userBox_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) {
			e->DrawBackground();
			System::Drawing::Font^ font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16));
			e->Graphics->DrawString(
				this->comboBox_userBox->Items[e->Index]->ToString(), font, gcnew SolidBrush(e->ForeColor), e->Bounds);
			e->DrawFocusRectangle();
		}
		void comboBox_userBox_MeasureItem(System::Object^ sender, System::Windows::Forms::MeasureItemEventArgs^ e) {
		}

		void onResize(System::Object^ sender, System::EventArgs^ e) {
			if (this->WindowState == FormWindowState::Minimized){
				return;
			}
			this->WindowState = FormWindowState::Normal;
			this->ClientSize = System::Drawing::Size(430, 460);
		}
		
	};
}