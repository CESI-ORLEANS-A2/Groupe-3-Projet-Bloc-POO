#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

namespace Groupe3ProjetBlocPOO {

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void) { }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	protected: System::Windows::Forms::TabControl^ tabControl_Tabs;
	protected: System::Windows::Forms::TabPage^ tabPage_Home;
	protected: System::Windows::Forms::TabPage^ tabPage_Clients;
	protected: System::Windows::Forms::TabPage^ tabPage_Stock;
	protected: System::Windows::Forms::TabPage^ tabPage_Orders;
	protected: System::Windows::Forms::Label^ label_AuthorText;
	protected: System::Windows::Forms::LinkLabel^ linkLabel_AuthorAbepan;
	protected: System::Windows::Forms::LinkLabel^ linkLabel_AuthorBeboudu32;
	protected: System::Windows::Forms::LinkLabel^ linkLabel_Author0xybo;
	protected: System::Windows::Forms::LinkLabel^ linkLabel_HomeGap;
	protected: System::Windows::Forms::Panel^ panel_ClientSearch;
	protected: System::Windows::Forms::Button^ button_ClientsUpdate;
	protected: System::Windows::Forms::TextBox^ textBox_ClientsSearch;
	protected: System::Windows::Forms::LinkLabel^ linkLabel_Help;
	protected: System::Windows::Forms::Label^ label_Welcome;
	protected: System::Windows::Forms::Label^ label_Logo;
	protected: System::Windows::Forms::Panel^ panel_StockSearch;
	protected: System::Windows::Forms::Button^ button_StockUpdate;
	protected: System::Windows::Forms::TextBox^ textBox_StockSearch;
	protected: System::Windows::Forms::Panel^ panel_OrdersSearch;
	protected: System::Windows::Forms::Button^ button_OrdersUpdate;
	protected: System::Windows::Forms::TextBox^ textBox_OrdersSearch;
	protected: System::Windows::Forms::SplitContainer^ splitContainer_Clients;
	protected: System::Windows::Forms::DataGridView^ dataGridView_Clients;
	protected: System::Windows::Forms::Panel^ panel_Client;
	protected: System::Windows::Forms::DataGridView^ dataGridView_ClientsAddresses;
	protected: System::Windows::Forms::Button^ button_ClientsAdd;
	protected: System::Windows::Forms::Button^ button_ClientsDelete;
	protected: System::Windows::Forms::Panel^ panel_ClientsGap;
	protected: System::Windows::Forms::Button^ button_ClientsSubmit;

	protected:












	private: System::Windows::Forms::Panel^ panel_Stock;
	private: System::Windows::Forms::Button^ button_StockAdd;

	private: System::Windows::Forms::DataGridView^ dataGridView_Stock;
	private: System::Windows::Forms::Button^ button_StockDelete;

	private: System::Windows::Forms::Panel^ panel_StockGap;
	private: System::Windows::Forms::Button^ button_StockSubmit;







	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsAddressId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsAddressNumber;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsAddressStreet;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsAddressCity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsAddressZip;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsAddressCountry;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsFirstname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsLastname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsPhone;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsEmail;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsBirthday;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_ClientsCompany;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_StockId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_StockName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_StockCost;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_StockQuantity;
	private: System::Windows::Forms::SplitContainer^ splitContainer_Orders;
	private: System::Windows::Forms::DataGridView^ dataGridView_Orders;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersCreationDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersCost;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersDeliveryDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersPaymentDate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersPaymentMethod;
	private: System::Windows::Forms::SplitContainer^ splitContainer_OrdersEdit;
	private: System::Windows::Forms::Panel^ panel_OrdersInfos;
	private: System::Windows::Forms::DataGridView^ dataGridView_OrdersClients;
	protected: System::Windows::Forms::Panel^ panel_OrdersClientsSearch;
	private:
	protected: System::Windows::Forms::Button^ button_OrdersClientsUpdate;
	protected: System::Windows::Forms::TextBox^ textBox_OrdersClientsSearch;
	private: System::Windows::Forms::DataGridView^ dataGridView_OrdersStock;
	protected:

	protected:
	protected: System::Windows::Forms::Panel^ panel_OrdersStockSearch;
	private:
	protected: System::Windows::Forms::Button^ button_OrdersStockUpdate;
	protected: System::Windows::Forms::TextBox^ textBox_OrdersStockSearch;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersClientsID;
	protected:
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersClientsFirstname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersClientsLastname;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersClientsBirthdate;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersStockID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersStockName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn_OrdersStockCost;
	private: System::Windows::Forms::Panel^ panel_OrdersNumberOfProducts;


	private: System::Windows::Forms::Label^ label_OrdersNumberOfProducts;
	private: System::Windows::Forms::Panel^ panel_OrdersPrice;


	private: System::Windows::Forms::Label^ label_OrdersPrice;
	private: System::Windows::Forms::Panel^ panel_OrdersGap1;
	private: System::Windows::Forms::Panel^ panel_OrdersGap2;
	private: System::Windows::Forms::TextBox^ textBox_OrdersPrice;
	private: System::Windows::Forms::Label^ label_OrdersUnit2;

	private: System::Windows::Forms::TextBox^ textBox_OrdersNumberOfProducts;
	private: System::Windows::Forms::Label^ label_OrdersUnit1;
	private: System::Windows::Forms::Panel^ panel_OrdersGap3;
	private: System::Windows::Forms::Panel^ panel_OrdersDiscount;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label_OrderUnit3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label_OrdersUnit4;
	private: System::Windows::Forms::Label^ label_OrdersDiscout;






















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
		void InitializeComponent(void)
		{
			this->tabControl_Tabs = (gcnew System::Windows::Forms::TabControl());
			this->tabPage_Home = (gcnew System::Windows::Forms::TabPage());
			this->linkLabel_Help = (gcnew System::Windows::Forms::LinkLabel());
			this->label_Welcome = (gcnew System::Windows::Forms::Label());
			this->label_Logo = (gcnew System::Windows::Forms::Label());
			this->label_AuthorText = (gcnew System::Windows::Forms::Label());
			this->linkLabel_AuthorAbepan = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel_AuthorBeboudu32 = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel_Author0xybo = (gcnew System::Windows::Forms::LinkLabel());
			this->linkLabel_HomeGap = (gcnew System::Windows::Forms::LinkLabel());
			this->tabPage_Clients = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer_Clients = (gcnew System::Windows::Forms::SplitContainer());
			this->dataGridView_Clients = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn_ClientsId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsFirstname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsLastname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsPhone = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsEmail = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsBirthday = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsCompany = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel_Client = (gcnew System::Windows::Forms::Panel());
			this->button_ClientsSubmit = (gcnew System::Windows::Forms::Button());
			this->button_ClientsDelete = (gcnew System::Windows::Forms::Button());
			this->panel_ClientsGap = (gcnew System::Windows::Forms::Panel());
			this->button_ClientsAdd = (gcnew System::Windows::Forms::Button());
			this->dataGridView_ClientsAddresses = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn_ClientsAddressId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsAddressNumber = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsAddressStreet = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsAddressCity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsAddressZip = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_ClientsAddressCountry = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel_ClientSearch = (gcnew System::Windows::Forms::Panel());
			this->button_ClientsUpdate = (gcnew System::Windows::Forms::Button());
			this->textBox_ClientsSearch = (gcnew System::Windows::Forms::TextBox());
			this->tabPage_Stock = (gcnew System::Windows::Forms::TabPage());
			this->panel_Stock = (gcnew System::Windows::Forms::Panel());
			this->button_StockSubmit = (gcnew System::Windows::Forms::Button());
			this->button_StockDelete = (gcnew System::Windows::Forms::Button());
			this->panel_StockGap = (gcnew System::Windows::Forms::Panel());
			this->button_StockAdd = (gcnew System::Windows::Forms::Button());
			this->dataGridView_Stock = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn_StockId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_StockName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_StockCost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_StockQuantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel_StockSearch = (gcnew System::Windows::Forms::Panel());
			this->button_StockUpdate = (gcnew System::Windows::Forms::Button());
			this->textBox_StockSearch = (gcnew System::Windows::Forms::TextBox());
			this->tabPage_Orders = (gcnew System::Windows::Forms::TabPage());
			this->splitContainer_Orders = (gcnew System::Windows::Forms::SplitContainer());
			this->dataGridView_Orders = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn_OrdersID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersCreationDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersCost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersDeliveryDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersPaymentDate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersPaymentMethod = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->splitContainer_OrdersEdit = (gcnew System::Windows::Forms::SplitContainer());
			this->dataGridView_OrdersClients = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn_OrdersClientsID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersClientsFirstname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersClientsLastname = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersClientsBirthdate = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel_OrdersClientsSearch = (gcnew System::Windows::Forms::Panel());
			this->button_OrdersClientsUpdate = (gcnew System::Windows::Forms::Button());
			this->textBox_OrdersClientsSearch = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView_OrdersStock = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn_OrdersStockID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersStockName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn_OrdersStockCost = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel_OrdersStockSearch = (gcnew System::Windows::Forms::Panel());
			this->button_OrdersStockUpdate = (gcnew System::Windows::Forms::Button());
			this->textBox_OrdersStockSearch = (gcnew System::Windows::Forms::TextBox());
			this->panel_OrdersInfos = (gcnew System::Windows::Forms::Panel());
			this->panel_OrdersSearch = (gcnew System::Windows::Forms::Panel());
			this->button_OrdersUpdate = (gcnew System::Windows::Forms::Button());
			this->textBox_OrdersSearch = (gcnew System::Windows::Forms::TextBox());
			this->panel_OrdersNumberOfProducts = (gcnew System::Windows::Forms::Panel());
			this->label_OrdersNumberOfProducts = (gcnew System::Windows::Forms::Label());
			this->panel_OrdersGap1 = (gcnew System::Windows::Forms::Panel());
			this->panel_OrdersPrice = (gcnew System::Windows::Forms::Panel());
			this->label_OrdersPrice = (gcnew System::Windows::Forms::Label());
			this->panel_OrdersGap2 = (gcnew System::Windows::Forms::Panel());
			this->textBox_OrdersNumberOfProducts = (gcnew System::Windows::Forms::TextBox());
			this->label_OrdersUnit1 = (gcnew System::Windows::Forms::Label());
			this->label_OrdersUnit2 = (gcnew System::Windows::Forms::Label());
			this->textBox_OrdersPrice = (gcnew System::Windows::Forms::TextBox());
			this->panel_OrdersDiscount = (gcnew System::Windows::Forms::Panel());
			this->label_OrdersUnit4 = (gcnew System::Windows::Forms::Label());
			this->label_OrdersDiscout = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label_OrderUnit3 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->panel_OrdersGap3 = (gcnew System::Windows::Forms::Panel());
			this->tabControl_Tabs->SuspendLayout();
			this->tabPage_Home->SuspendLayout();
			this->tabPage_Clients->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer_Clients))->BeginInit();
			this->splitContainer_Clients->Panel1->SuspendLayout();
			this->splitContainer_Clients->Panel2->SuspendLayout();
			this->splitContainer_Clients->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Clients))->BeginInit();
			this->panel_Client->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_ClientsAddresses))->BeginInit();
			this->panel_ClientSearch->SuspendLayout();
			this->tabPage_Stock->SuspendLayout();
			this->panel_Stock->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Stock))->BeginInit();
			this->panel_StockSearch->SuspendLayout();
			this->tabPage_Orders->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer_Orders))->BeginInit();
			this->splitContainer_Orders->Panel1->SuspendLayout();
			this->splitContainer_Orders->Panel2->SuspendLayout();
			this->splitContainer_Orders->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Orders))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer_OrdersEdit))->BeginInit();
			this->splitContainer_OrdersEdit->Panel1->SuspendLayout();
			this->splitContainer_OrdersEdit->Panel2->SuspendLayout();
			this->splitContainer_OrdersEdit->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_OrdersClients))->BeginInit();
			this->panel_OrdersClientsSearch->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_OrdersStock))->BeginInit();
			this->panel_OrdersStockSearch->SuspendLayout();
			this->panel_OrdersInfos->SuspendLayout();
			this->panel_OrdersSearch->SuspendLayout();
			this->panel_OrdersNumberOfProducts->SuspendLayout();
			this->panel_OrdersPrice->SuspendLayout();
			this->panel_OrdersDiscount->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl_Tabs
			// 
			this->tabControl_Tabs->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl_Tabs->Controls->Add(this->tabPage_Home);
			this->tabControl_Tabs->Controls->Add(this->tabPage_Clients);
			this->tabControl_Tabs->Controls->Add(this->tabPage_Stock);
			this->tabControl_Tabs->Controls->Add(this->tabPage_Orders);
			this->tabControl_Tabs->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tabControl_Tabs->Location = System::Drawing::Point(0, 0);
			this->tabControl_Tabs->Name = L"tabControl_Tabs";
			this->tabControl_Tabs->SelectedIndex = 0;
			this->tabControl_Tabs->Size = System::Drawing::Size(689, 404);
			this->tabControl_Tabs->SizeMode = System::Windows::Forms::TabSizeMode::FillToRight;
			this->tabControl_Tabs->TabIndex = 0;
			// 
			// tabPage_Home
			// 
			this->tabPage_Home->Controls->Add(this->linkLabel_Help);
			this->tabPage_Home->Controls->Add(this->label_Welcome);
			this->tabPage_Home->Controls->Add(this->label_Logo);
			this->tabPage_Home->Controls->Add(this->label_AuthorText);
			this->tabPage_Home->Controls->Add(this->linkLabel_AuthorAbepan);
			this->tabPage_Home->Controls->Add(this->linkLabel_AuthorBeboudu32);
			this->tabPage_Home->Controls->Add(this->linkLabel_Author0xybo);
			this->tabPage_Home->Controls->Add(this->linkLabel_HomeGap);
			this->tabPage_Home->Location = System::Drawing::Point(4, 22);
			this->tabPage_Home->Name = L"tabPage_Home";
			this->tabPage_Home->Size = System::Drawing::Size(681, 378);
			this->tabPage_Home->TabIndex = 0;
			this->tabPage_Home->Text = L"Home";
			this->tabPage_Home->UseVisualStyleBackColor = true;
			// 
			// linkLabel_Help
			// 
			this->linkLabel_Help->Dock = System::Windows::Forms::DockStyle::Top;
			this->linkLabel_Help->LinkArea = System::Windows::Forms::LinkArea(30, 3);
			this->linkLabel_Help->Location = System::Drawing::Point(0, 169);
			this->linkLabel_Help->Name = L"linkLabel_Help";
			this->linkLabel_Help->Size = System::Drawing::Size(681, 20);
			this->linkLabel_Help->TabIndex = 22;
			this->linkLabel_Help->TabStop = true;
			this->linkLabel_Help->Text = L"Pour une page d\'aide, cliquez ici";
			this->linkLabel_Help->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->linkLabel_Help->UseCompatibleTextRendering = true;
			// 
			// label_Welcome
			// 
			this->label_Welcome->Dock = System::Windows::Forms::DockStyle::Top;
			this->label_Welcome->Font = (gcnew System::Drawing::Font(L"Segoe UI", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Welcome->Location = System::Drawing::Point(0, 123);
			this->label_Welcome->Margin = System::Windows::Forms::Padding(0);
			this->label_Welcome->Name = L"label_Welcome";
			this->label_Welcome->Size = System::Drawing::Size(681, 46);
			this->label_Welcome->TabIndex = 21;
			this->label_Welcome->Text = L"Welcome";
			this->label_Welcome->TextAlign = System::Drawing::ContentAlignment::BottomCenter;
			// 
			// label_Logo
			// 
			this->label_Logo->Dock = System::Windows::Forms::DockStyle::Top;
			this->label_Logo->Font = (gcnew System::Drawing::Font(L"Audiowide", 60, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label_Logo->ForeColor = System::Drawing::Color::Maroon;
			this->label_Logo->Location = System::Drawing::Point(0, 0);
			this->label_Logo->Margin = System::Windows::Forms::Padding(0);
			this->label_Logo->Name = L"label_Logo";
			this->label_Logo->Size = System::Drawing::Size(681, 123);
			this->label_Logo->TabIndex = 20;
			this->label_Logo->Text = L"FirmManager";
			this->label_Logo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_AuthorText
			// 
			this->label_AuthorText->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label_AuthorText->Location = System::Drawing::Point(0, 253);
			this->label_AuthorText->Name = L"label_AuthorText";
			this->label_AuthorText->Size = System::Drawing::Size(681, 25);
			this->label_AuthorText->TabIndex = 17;
			this->label_AuthorText->Text = L"Fait par :";
			this->label_AuthorText->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// linkLabel_AuthorAbepan
			// 
			this->linkLabel_AuthorAbepan->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->linkLabel_AuthorAbepan->LinkArea = System::Windows::Forms::LinkArea(11, 14);
			this->linkLabel_AuthorAbepan->Location = System::Drawing::Point(0, 278);
			this->linkLabel_AuthorAbepan->Name = L"linkLabel_AuthorAbepan";
			this->linkLabel_AuthorAbepan->Size = System::Drawing::Size(681, 25);
			this->linkLabel_AuthorAbepan->TabIndex = 16;
			this->linkLabel_AuthorAbepan->TabStop = true;
			this->linkLabel_AuthorAbepan->Text = L"Mattéo V. <@ultrasonicytb>";
			this->linkLabel_AuthorAbepan->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->linkLabel_AuthorAbepan->UseCompatibleTextRendering = true;
			this->linkLabel_AuthorAbepan->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::linkLabel_AuthorAbepan_LinkClicked);
			// 
			// linkLabel_AuthorBeboudu32
			// 
			this->linkLabel_AuthorBeboudu32->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->linkLabel_AuthorBeboudu32->LinkArea = System::Windows::Forms::LinkArea(9, 10);
			this->linkLabel_AuthorBeboudu32->Location = System::Drawing::Point(0, 303);
			this->linkLabel_AuthorBeboudu32->Name = L"linkLabel_AuthorBeboudu32";
			this->linkLabel_AuthorBeboudu32->Size = System::Drawing::Size(681, 25);
			this->linkLabel_AuthorBeboudu32->TabIndex = 14;
			this->linkLabel_AuthorBeboudu32->TabStop = true;
			this->linkLabel_AuthorBeboudu32->Text = L"Noah V. <@Beboudu32>";
			this->linkLabel_AuthorBeboudu32->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->linkLabel_AuthorBeboudu32->UseCompatibleTextRendering = true;
			this->linkLabel_AuthorBeboudu32->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::linkLabel_AuthorBeboudu32_LinkClicked);
			// 
			// linkLabel_Author0xybo
			// 
			this->linkLabel_Author0xybo->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->linkLabel_Author0xybo->LinkArea = System::Windows::Forms::LinkArea(10, 6);
			this->linkLabel_Author0xybo->Location = System::Drawing::Point(0, 328);
			this->linkLabel_Author0xybo->Name = L"linkLabel_Author0xybo";
			this->linkLabel_Author0xybo->Size = System::Drawing::Size(681, 25);
			this->linkLabel_Author0xybo->TabIndex = 10;
			this->linkLabel_Author0xybo->TabStop = true;
			this->linkLabel_Author0xybo->Text = L"Alban G. <@0xybo>";
			this->linkLabel_Author0xybo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->linkLabel_Author0xybo->UseCompatibleTextRendering = true;
			this->linkLabel_Author0xybo->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &MainForm::linkLabel_Author0xybo_LinkClicked);
			// 
			// linkLabel_HomeGap
			// 
			this->linkLabel_HomeGap->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->linkLabel_HomeGap->Location = System::Drawing::Point(0, 353);
			this->linkLabel_HomeGap->Name = L"linkLabel_HomeGap";
			this->linkLabel_HomeGap->Size = System::Drawing::Size(681, 25);
			this->linkLabel_HomeGap->TabIndex = 7;
			this->linkLabel_HomeGap->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// tabPage_Clients
			// 
			this->tabPage_Clients->Controls->Add(this->splitContainer_Clients);
			this->tabPage_Clients->Controls->Add(this->panel_ClientSearch);
			this->tabPage_Clients->Location = System::Drawing::Point(4, 22);
			this->tabPage_Clients->Name = L"tabPage_Clients";
			this->tabPage_Clients->Size = System::Drawing::Size(681, 378);
			this->tabPage_Clients->TabIndex = 1;
			this->tabPage_Clients->Text = L"Clients";
			this->tabPage_Clients->UseVisualStyleBackColor = true;
			// 
			// splitContainer_Clients
			// 
			this->splitContainer_Clients->Cursor = System::Windows::Forms::Cursors::HSplit;
			this->splitContainer_Clients->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer_Clients->Location = System::Drawing::Point(0, 34);
			this->splitContainer_Clients->Name = L"splitContainer_Clients";
			this->splitContainer_Clients->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer_Clients.Panel1
			// 
			this->splitContainer_Clients->Panel1->Controls->Add(this->dataGridView_Clients);
			this->splitContainer_Clients->Panel1MinSize = 100;
			// 
			// splitContainer_Clients.Panel2
			// 
			this->splitContainer_Clients->Panel2->Controls->Add(this->panel_Client);
			this->splitContainer_Clients->Panel2->Controls->Add(this->dataGridView_ClientsAddresses);
			this->splitContainer_Clients->Panel2MinSize = 150;
			this->splitContainer_Clients->Size = System::Drawing::Size(681, 344);
			this->splitContainer_Clients->SplitterDistance = 179;
			this->splitContainer_Clients->SplitterWidth = 10;
			this->splitContainer_Clients->TabIndex = 1;
			// 
			// dataGridView_Clients
			// 
			this->dataGridView_Clients->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->dataGridView_Clients->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView_Clients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Clients->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(7) {
				this->dataGridViewTextBoxColumn_ClientsId,
					this->dataGridViewTextBoxColumn_ClientsFirstname, this->dataGridViewTextBoxColumn_ClientsLastname, this->dataGridViewTextBoxColumn_ClientsPhone,
					this->dataGridViewTextBoxColumn_ClientsEmail, this->dataGridViewTextBoxColumn_ClientsBirthday, this->dataGridViewTextBoxColumn_ClientsCompany
			});
			this->dataGridView_Clients->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_Clients->Enabled = false;
			this->dataGridView_Clients->Location = System::Drawing::Point(0, 0);
			this->dataGridView_Clients->Name = L"dataGridView_Clients";
			this->dataGridView_Clients->Size = System::Drawing::Size(681, 179);
			this->dataGridView_Clients->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn_ClientsId
			// 
			this->dataGridViewTextBoxColumn_ClientsId->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsId->FillWeight = 10;
			this->dataGridViewTextBoxColumn_ClientsId->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn_ClientsId->Name = L"dataGridViewTextBoxColumn_ClientsId";
			this->dataGridViewTextBoxColumn_ClientsId->ReadOnly = true;
			this->dataGridViewTextBoxColumn_ClientsId->Width = 43;
			// 
			// dataGridViewTextBoxColumn_ClientsFirstname
			// 
			this->dataGridViewTextBoxColumn_ClientsFirstname->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn_ClientsFirstname->HeaderText = L"Firstname";
			this->dataGridViewTextBoxColumn_ClientsFirstname->MinimumWidth = 80;
			this->dataGridViewTextBoxColumn_ClientsFirstname->Name = L"dataGridViewTextBoxColumn_ClientsFirstname";
			// 
			// dataGridViewTextBoxColumn_ClientsLastname
			// 
			this->dataGridViewTextBoxColumn_ClientsLastname->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn_ClientsLastname->HeaderText = L"Lastname";
			this->dataGridViewTextBoxColumn_ClientsLastname->MinimumWidth = 80;
			this->dataGridViewTextBoxColumn_ClientsLastname->Name = L"dataGridViewTextBoxColumn_ClientsLastname";
			// 
			// dataGridViewTextBoxColumn_ClientsPhone
			// 
			this->dataGridViewTextBoxColumn_ClientsPhone->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsPhone->HeaderText = L"Phone Number";
			this->dataGridViewTextBoxColumn_ClientsPhone->Name = L"dataGridViewTextBoxColumn_ClientsPhone";
			// 
			// dataGridViewTextBoxColumn_ClientsEmail
			// 
			this->dataGridViewTextBoxColumn_ClientsEmail->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsEmail->HeaderText = L"Email";
			this->dataGridViewTextBoxColumn_ClientsEmail->Name = L"dataGridViewTextBoxColumn_ClientsEmail";
			this->dataGridViewTextBoxColumn_ClientsEmail->Width = 59;
			// 
			// dataGridViewTextBoxColumn_ClientsBirthday
			// 
			this->dataGridViewTextBoxColumn_ClientsBirthday->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsBirthday->FillWeight = 50;
			this->dataGridViewTextBoxColumn_ClientsBirthday->HeaderText = L"Birthday";
			this->dataGridViewTextBoxColumn_ClientsBirthday->Name = L"dataGridViewTextBoxColumn_ClientsBirthday";
			this->dataGridViewTextBoxColumn_ClientsBirthday->Width = 74;
			// 
			// dataGridViewTextBoxColumn_ClientsCompany
			// 
			this->dataGridViewTextBoxColumn_ClientsCompany->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsCompany->HeaderText = L"Company";
			this->dataGridViewTextBoxColumn_ClientsCompany->Name = L"dataGridViewTextBoxColumn_ClientsCompany";
			this->dataGridViewTextBoxColumn_ClientsCompany->Width = 80;
			// 
			// panel_Client
			// 
			this->panel_Client->Controls->Add(this->button_ClientsSubmit);
			this->panel_Client->Controls->Add(this->button_ClientsDelete);
			this->panel_Client->Controls->Add(this->panel_ClientsGap);
			this->panel_Client->Controls->Add(this->button_ClientsAdd);
			this->panel_Client->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel_Client->Location = System::Drawing::Point(0, 0);
			this->panel_Client->Name = L"panel_Client";
			this->panel_Client->Padding = System::Windows::Forms::Padding(20);
			this->panel_Client->Size = System::Drawing::Size(149, 155);
			this->panel_Client->TabIndex = 1;
			// 
			// button_ClientsSubmit
			// 
			this->button_ClientsSubmit->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->button_ClientsSubmit->Enabled = false;
			this->button_ClientsSubmit->Location = System::Drawing::Point(20, 112);
			this->button_ClientsSubmit->Name = L"button_ClientsSubmit";
			this->button_ClientsSubmit->Size = System::Drawing::Size(109, 23);
			this->button_ClientsSubmit->TabIndex = 4;
			this->button_ClientsSubmit->Text = L"Submit";
			this->button_ClientsSubmit->UseVisualStyleBackColor = true;
			// 
			// button_ClientsDelete
			// 
			this->button_ClientsDelete->Dock = System::Windows::Forms::DockStyle::Top;
			this->button_ClientsDelete->Enabled = false;
			this->button_ClientsDelete->Location = System::Drawing::Point(20, 53);
			this->button_ClientsDelete->Name = L"button_ClientsDelete";
			this->button_ClientsDelete->Size = System::Drawing::Size(109, 23);
			this->button_ClientsDelete->TabIndex = 3;
			this->button_ClientsDelete->Text = L"Delete";
			this->button_ClientsDelete->UseVisualStyleBackColor = true;
			// 
			// panel_ClientsGap
			// 
			this->panel_ClientsGap->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_ClientsGap->Location = System::Drawing::Point(20, 43);
			this->panel_ClientsGap->Name = L"panel_ClientsGap";
			this->panel_ClientsGap->Size = System::Drawing::Size(109, 10);
			this->panel_ClientsGap->TabIndex = 2;
			// 
			// button_ClientsAdd
			// 
			this->button_ClientsAdd->Dock = System::Windows::Forms::DockStyle::Top;
			this->button_ClientsAdd->Enabled = false;
			this->button_ClientsAdd->Location = System::Drawing::Point(20, 20);
			this->button_ClientsAdd->Name = L"button_ClientsAdd";
			this->button_ClientsAdd->Size = System::Drawing::Size(109, 23);
			this->button_ClientsAdd->TabIndex = 0;
			this->button_ClientsAdd->Text = L"Add";
			this->button_ClientsAdd->UseVisualStyleBackColor = true;
			// 
			// dataGridView_ClientsAddresses
			// 
			this->dataGridView_ClientsAddresses->AllowUserToDeleteRows = false;
			this->dataGridView_ClientsAddresses->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView_ClientsAddresses->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->dataGridView_ClientsAddresses->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView_ClientsAddresses->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_ClientsAddresses->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->dataGridViewTextBoxColumn_ClientsAddressId,
					this->dataGridViewTextBoxColumn_ClientsAddressNumber, this->dataGridViewTextBoxColumn_ClientsAddressStreet, this->dataGridViewTextBoxColumn_ClientsAddressCity,
					this->dataGridViewTextBoxColumn_ClientsAddressZip, this->dataGridViewTextBoxColumn_ClientsAddressCountry
			});
			this->dataGridView_ClientsAddresses->Enabled = false;
			this->dataGridView_ClientsAddresses->Location = System::Drawing::Point(155, 0);
			this->dataGridView_ClientsAddresses->Name = L"dataGridView_ClientsAddresses";
			this->dataGridView_ClientsAddresses->Size = System::Drawing::Size(526, 149);
			this->dataGridView_ClientsAddresses->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn_ClientsAddressId
			// 
			this->dataGridViewTextBoxColumn_ClientsAddressId->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsAddressId->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn_ClientsAddressId->Name = L"dataGridViewTextBoxColumn_ClientsAddressId";
			this->dataGridViewTextBoxColumn_ClientsAddressId->ReadOnly = true;
			this->dataGridViewTextBoxColumn_ClientsAddressId->Visible = false;
			// 
			// dataGridViewTextBoxColumn_ClientsAddressNumber
			// 
			this->dataGridViewTextBoxColumn_ClientsAddressNumber->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsAddressNumber->FillWeight = 30;
			this->dataGridViewTextBoxColumn_ClientsAddressNumber->HeaderText = L"Number";
			this->dataGridViewTextBoxColumn_ClientsAddressNumber->Name = L"dataGridViewTextBoxColumn_ClientsAddressNumber";
			this->dataGridViewTextBoxColumn_ClientsAddressNumber->Width = 73;
			// 
			// dataGridViewTextBoxColumn_ClientsAddressStreet
			// 
			this->dataGridViewTextBoxColumn_ClientsAddressStreet->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn_ClientsAddressStreet->HeaderText = L"Street";
			this->dataGridViewTextBoxColumn_ClientsAddressStreet->MinimumWidth = 200;
			this->dataGridViewTextBoxColumn_ClientsAddressStreet->Name = L"dataGridViewTextBoxColumn_ClientsAddressStreet";
			// 
			// dataGridViewTextBoxColumn_ClientsAddressCity
			// 
			this->dataGridViewTextBoxColumn_ClientsAddressCity->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsAddressCity->FillWeight = 80;
			this->dataGridViewTextBoxColumn_ClientsAddressCity->HeaderText = L"City";
			this->dataGridViewTextBoxColumn_ClientsAddressCity->Name = L"dataGridViewTextBoxColumn_ClientsAddressCity";
			this->dataGridViewTextBoxColumn_ClientsAddressCity->Width = 51;
			// 
			// dataGridViewTextBoxColumn_ClientsAddressZip
			// 
			this->dataGridViewTextBoxColumn_ClientsAddressZip->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsAddressZip->FillWeight = 30;
			this->dataGridViewTextBoxColumn_ClientsAddressZip->HeaderText = L"ZIP Code";
			this->dataGridViewTextBoxColumn_ClientsAddressZip->Name = L"dataGridViewTextBoxColumn_ClientsAddressZip";
			this->dataGridViewTextBoxColumn_ClientsAddressZip->Width = 77;
			// 
			// dataGridViewTextBoxColumn_ClientsAddressCountry
			// 
			this->dataGridViewTextBoxColumn_ClientsAddressCountry->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_ClientsAddressCountry->FillWeight = 50;
			this->dataGridViewTextBoxColumn_ClientsAddressCountry->HeaderText = L"Country";
			this->dataGridViewTextBoxColumn_ClientsAddressCountry->Name = L"dataGridViewTextBoxColumn_ClientsAddressCountry";
			this->dataGridViewTextBoxColumn_ClientsAddressCountry->Width = 73;
			// 
			// panel_ClientSearch
			// 
			this->panel_ClientSearch->Controls->Add(this->button_ClientsUpdate);
			this->panel_ClientSearch->Controls->Add(this->textBox_ClientsSearch);
			this->panel_ClientSearch->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_ClientSearch->Location = System::Drawing::Point(0, 0);
			this->panel_ClientSearch->Name = L"panel_ClientSearch";
			this->panel_ClientSearch->Size = System::Drawing::Size(681, 34);
			this->panel_ClientSearch->TabIndex = 0;
			// 
			// button_ClientsUpdate
			// 
			this->button_ClientsUpdate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_ClientsUpdate->Location = System::Drawing::Point(579, 6);
			this->button_ClientsUpdate->Name = L"button_ClientsUpdate";
			this->button_ClientsUpdate->Size = System::Drawing::Size(99, 23);
			this->button_ClientsUpdate->TabIndex = 1;
			this->button_ClientsUpdate->Text = L"Update";
			this->button_ClientsUpdate->UseVisualStyleBackColor = true;
			// 
			// textBox_ClientsSearch
			// 
			this->textBox_ClientsSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_ClientsSearch->ForeColor = System::Drawing::SystemColors::MenuBar;
			this->textBox_ClientsSearch->Location = System::Drawing::Point(6, 6);
			this->textBox_ClientsSearch->Name = L"textBox_ClientsSearch";
			this->textBox_ClientsSearch->Size = System::Drawing::Size(563, 22);
			this->textBox_ClientsSearch->TabIndex = 0;
			// 
			// tabPage_Stock
			// 
			this->tabPage_Stock->Controls->Add(this->panel_Stock);
			this->tabPage_Stock->Controls->Add(this->dataGridView_Stock);
			this->tabPage_Stock->Controls->Add(this->panel_StockSearch);
			this->tabPage_Stock->Location = System::Drawing::Point(4, 22);
			this->tabPage_Stock->Name = L"tabPage_Stock";
			this->tabPage_Stock->Size = System::Drawing::Size(681, 378);
			this->tabPage_Stock->TabIndex = 2;
			this->tabPage_Stock->Text = L"Stock";
			this->tabPage_Stock->UseVisualStyleBackColor = true;
			// 
			// panel_Stock
			// 
			this->panel_Stock->Controls->Add(this->button_StockSubmit);
			this->panel_Stock->Controls->Add(this->button_StockDelete);
			this->panel_Stock->Controls->Add(this->panel_StockGap);
			this->panel_Stock->Controls->Add(this->button_StockAdd);
			this->panel_Stock->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel_Stock->Location = System::Drawing::Point(0, 333);
			this->panel_Stock->Name = L"panel_Stock";
			this->panel_Stock->Padding = System::Windows::Forms::Padding(10);
			this->panel_Stock->Size = System::Drawing::Size(681, 45);
			this->panel_Stock->TabIndex = 3;
			// 
			// button_StockSubmit
			// 
			this->button_StockSubmit->Dock = System::Windows::Forms::DockStyle::Right;
			this->button_StockSubmit->Location = System::Drawing::Point(561, 10);
			this->button_StockSubmit->Name = L"button_StockSubmit";
			this->button_StockSubmit->Size = System::Drawing::Size(110, 25);
			this->button_StockSubmit->TabIndex = 4;
			this->button_StockSubmit->Text = L"Submit";
			this->button_StockSubmit->UseVisualStyleBackColor = true;
			// 
			// button_StockDelete
			// 
			this->button_StockDelete->Dock = System::Windows::Forms::DockStyle::Left;
			this->button_StockDelete->Location = System::Drawing::Point(140, 10);
			this->button_StockDelete->Name = L"button_StockDelete";
			this->button_StockDelete->Size = System::Drawing::Size(110, 25);
			this->button_StockDelete->TabIndex = 3;
			this->button_StockDelete->Text = L"Delete";
			this->button_StockDelete->UseVisualStyleBackColor = true;
			// 
			// panel_StockGap
			// 
			this->panel_StockGap->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel_StockGap->Location = System::Drawing::Point(120, 10);
			this->panel_StockGap->Name = L"panel_StockGap";
			this->panel_StockGap->Size = System::Drawing::Size(20, 25);
			this->panel_StockGap->TabIndex = 2;
			// 
			// button_StockAdd
			// 
			this->button_StockAdd->Dock = System::Windows::Forms::DockStyle::Left;
			this->button_StockAdd->Location = System::Drawing::Point(10, 10);
			this->button_StockAdd->Name = L"button_StockAdd";
			this->button_StockAdd->Size = System::Drawing::Size(110, 25);
			this->button_StockAdd->TabIndex = 0;
			this->button_StockAdd->Text = L"Add";
			this->button_StockAdd->UseVisualStyleBackColor = true;
			// 
			// dataGridView_Stock
			// 
			this->dataGridView_Stock->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dataGridView_Stock->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->dataGridView_Stock->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Stock->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn_StockId,
					this->dataGridViewTextBoxColumn_StockName, this->dataGridViewTextBoxColumn_StockCost, this->dataGridViewTextBoxColumn_StockQuantity
			});
			this->dataGridView_Stock->Location = System::Drawing::Point(0, 34);
			this->dataGridView_Stock->Name = L"dataGridView_Stock";
			this->dataGridView_Stock->Size = System::Drawing::Size(681, 293);
			this->dataGridView_Stock->TabIndex = 2;
			// 
			// dataGridViewTextBoxColumn_StockId
			// 
			this->dataGridViewTextBoxColumn_StockId->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_StockId->FillWeight = 20;
			this->dataGridViewTextBoxColumn_StockId->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn_StockId->Name = L"dataGridViewTextBoxColumn_StockId";
			this->dataGridViewTextBoxColumn_StockId->ReadOnly = true;
			this->dataGridViewTextBoxColumn_StockId->Width = 43;
			// 
			// dataGridViewTextBoxColumn_StockName
			// 
			this->dataGridViewTextBoxColumn_StockName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn_StockName->HeaderText = L"Name";
			this->dataGridViewTextBoxColumn_StockName->MinimumWidth = 400;
			this->dataGridViewTextBoxColumn_StockName->Name = L"dataGridViewTextBoxColumn_StockName";
			// 
			// dataGridViewTextBoxColumn_StockCost
			// 
			this->dataGridViewTextBoxColumn_StockCost->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_StockCost->FillWeight = 20;
			this->dataGridViewTextBoxColumn_StockCost->HeaderText = L"Cost";
			this->dataGridViewTextBoxColumn_StockCost->Name = L"dataGridViewTextBoxColumn_StockCost";
			this->dataGridViewTextBoxColumn_StockCost->Width = 55;
			// 
			// dataGridViewTextBoxColumn_StockQuantity
			// 
			this->dataGridViewTextBoxColumn_StockQuantity->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_StockQuantity->FillWeight = 20;
			this->dataGridViewTextBoxColumn_StockQuantity->HeaderText = L"Quantity";
			this->dataGridViewTextBoxColumn_StockQuantity->Name = L"dataGridViewTextBoxColumn_StockQuantity";
			this->dataGridViewTextBoxColumn_StockQuantity->Width = 76;
			// 
			// panel_StockSearch
			// 
			this->panel_StockSearch->Controls->Add(this->button_StockUpdate);
			this->panel_StockSearch->Controls->Add(this->textBox_StockSearch);
			this->panel_StockSearch->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_StockSearch->Location = System::Drawing::Point(0, 0);
			this->panel_StockSearch->Name = L"panel_StockSearch";
			this->panel_StockSearch->Size = System::Drawing::Size(681, 34);
			this->panel_StockSearch->TabIndex = 1;
			// 
			// button_StockUpdate
			// 
			this->button_StockUpdate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_StockUpdate->Location = System::Drawing::Point(579, 6);
			this->button_StockUpdate->Name = L"button_StockUpdate";
			this->button_StockUpdate->Size = System::Drawing::Size(99, 23);
			this->button_StockUpdate->TabIndex = 1;
			this->button_StockUpdate->Text = L"Update";
			this->button_StockUpdate->UseVisualStyleBackColor = true;
			// 
			// textBox_StockSearch
			// 
			this->textBox_StockSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_StockSearch->ForeColor = System::Drawing::SystemColors::MenuBar;
			this->textBox_StockSearch->Location = System::Drawing::Point(6, 6);
			this->textBox_StockSearch->Name = L"textBox_StockSearch";
			this->textBox_StockSearch->Size = System::Drawing::Size(563, 22);
			this->textBox_StockSearch->TabIndex = 0;
			// 
			// tabPage_Orders
			// 
			this->tabPage_Orders->Controls->Add(this->splitContainer_Orders);
			this->tabPage_Orders->Controls->Add(this->panel_OrdersSearch);
			this->tabPage_Orders->Location = System::Drawing::Point(4, 22);
			this->tabPage_Orders->Name = L"tabPage_Orders";
			this->tabPage_Orders->Size = System::Drawing::Size(681, 378);
			this->tabPage_Orders->TabIndex = 3;
			this->tabPage_Orders->Text = L"Orders";
			this->tabPage_Orders->UseVisualStyleBackColor = true;
			// 
			// splitContainer_Orders
			// 
			this->splitContainer_Orders->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer_Orders->Location = System::Drawing::Point(0, 34);
			this->splitContainer_Orders->Name = L"splitContainer_Orders";
			this->splitContainer_Orders->Orientation = System::Windows::Forms::Orientation::Horizontal;
			// 
			// splitContainer_Orders.Panel1
			// 
			this->splitContainer_Orders->Panel1->Controls->Add(this->dataGridView_Orders);
			this->splitContainer_Orders->Panel1->Cursor = System::Windows::Forms::Cursors::Default;
			// 
			// splitContainer_Orders.Panel2
			// 
			this->splitContainer_Orders->Panel2->Controls->Add(this->splitContainer_OrdersEdit);
			this->splitContainer_Orders->Panel2->Controls->Add(this->panel_OrdersInfos);
			this->splitContainer_Orders->Size = System::Drawing::Size(681, 344);
			this->splitContainer_Orders->SplitterDistance = 165;
			this->splitContainer_Orders->TabIndex = 2;
			// 
			// dataGridView_Orders
			// 
			this->dataGridView_Orders->AllowUserToDeleteRows = false;
			this->dataGridView_Orders->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->dataGridView_Orders->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_Orders->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->dataGridViewTextBoxColumn_OrdersID,
					this->dataGridViewTextBoxColumn_OrdersCreationDate, this->dataGridViewTextBoxColumn_OrdersCost, this->dataGridViewTextBoxColumn_OrdersDeliveryDate,
					this->dataGridViewTextBoxColumn_OrdersPaymentDate, this->dataGridViewTextBoxColumn_OrdersPaymentMethod
			});
			this->dataGridView_Orders->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_Orders->Location = System::Drawing::Point(0, 0);
			this->dataGridView_Orders->Name = L"dataGridView_Orders";
			this->dataGridView_Orders->Size = System::Drawing::Size(681, 165);
			this->dataGridView_Orders->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn_OrdersID
			// 
			this->dataGridViewTextBoxColumn_OrdersID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_OrdersID->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn_OrdersID->Name = L"dataGridViewTextBoxColumn_OrdersID";
			this->dataGridViewTextBoxColumn_OrdersID->ReadOnly = true;
			this->dataGridViewTextBoxColumn_OrdersID->Width = 43;
			// 
			// dataGridViewTextBoxColumn_OrdersCreationDate
			// 
			this->dataGridViewTextBoxColumn_OrdersCreationDate->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn_OrdersCreationDate->HeaderText = L"Creation Date";
			this->dataGridViewTextBoxColumn_OrdersCreationDate->MinimumWidth = 100;
			this->dataGridViewTextBoxColumn_OrdersCreationDate->Name = L"dataGridViewTextBoxColumn_OrdersCreationDate";
			this->dataGridViewTextBoxColumn_OrdersCreationDate->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn_OrdersCost
			// 
			this->dataGridViewTextBoxColumn_OrdersCost->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_OrdersCost->HeaderText = L"Cost";
			this->dataGridViewTextBoxColumn_OrdersCost->Name = L"dataGridViewTextBoxColumn_OrdersCost";
			this->dataGridViewTextBoxColumn_OrdersCost->ReadOnly = true;
			this->dataGridViewTextBoxColumn_OrdersCost->Width = 55;
			// 
			// dataGridViewTextBoxColumn_OrdersDeliveryDate
			// 
			this->dataGridViewTextBoxColumn_OrdersDeliveryDate->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_OrdersDeliveryDate->HeaderText = L"Delivery Date";
			this->dataGridViewTextBoxColumn_OrdersDeliveryDate->Name = L"dataGridViewTextBoxColumn_OrdersDeliveryDate";
			this->dataGridViewTextBoxColumn_OrdersDeliveryDate->Width = 91;
			// 
			// dataGridViewTextBoxColumn_OrdersPaymentDate
			// 
			this->dataGridViewTextBoxColumn_OrdersPaymentDate->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_OrdersPaymentDate->HeaderText = L"Payment Date";
			this->dataGridViewTextBoxColumn_OrdersPaymentDate->Name = L"dataGridViewTextBoxColumn_OrdersPaymentDate";
			this->dataGridViewTextBoxColumn_OrdersPaymentDate->ReadOnly = true;
			this->dataGridViewTextBoxColumn_OrdersPaymentDate->Width = 94;
			// 
			// dataGridViewTextBoxColumn_OrdersPaymentMethod
			// 
			this->dataGridViewTextBoxColumn_OrdersPaymentMethod->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_OrdersPaymentMethod->HeaderText = L"Payment Method";
			this->dataGridViewTextBoxColumn_OrdersPaymentMethod->Name = L"dataGridViewTextBoxColumn_OrdersPaymentMethod";
			this->dataGridViewTextBoxColumn_OrdersPaymentMethod->ReadOnly = true;
			this->dataGridViewTextBoxColumn_OrdersPaymentMethod->Width = 109;
			// 
			// splitContainer_OrdersEdit
			// 
			this->splitContainer_OrdersEdit->Dock = System::Windows::Forms::DockStyle::Fill;
			this->splitContainer_OrdersEdit->Location = System::Drawing::Point(0, 0);
			this->splitContainer_OrdersEdit->Name = L"splitContainer_OrdersEdit";
			// 
			// splitContainer_OrdersEdit.Panel1
			// 
			this->splitContainer_OrdersEdit->Panel1->Controls->Add(this->dataGridView_OrdersClients);
			this->splitContainer_OrdersEdit->Panel1->Controls->Add(this->panel_OrdersClientsSearch);
			// 
			// splitContainer_OrdersEdit.Panel2
			// 
			this->splitContainer_OrdersEdit->Panel2->Controls->Add(this->dataGridView_OrdersStock);
			this->splitContainer_OrdersEdit->Panel2->Controls->Add(this->panel_OrdersStockSearch);
			this->splitContainer_OrdersEdit->Size = System::Drawing::Size(431, 175);
			this->splitContainer_OrdersEdit->SplitterDistance = 211;
			this->splitContainer_OrdersEdit->TabIndex = 3;
			// 
			// dataGridView_OrdersClients
			// 
			this->dataGridView_OrdersClients->AllowUserToAddRows = false;
			this->dataGridView_OrdersClients->AllowUserToDeleteRows = false;
			this->dataGridView_OrdersClients->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->dataGridView_OrdersClients->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_OrdersClients->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn_OrdersClientsID,
					this->dataGridViewTextBoxColumn_OrdersClientsFirstname, this->dataGridViewTextBoxColumn_OrdersClientsLastname, this->dataGridViewTextBoxColumn_OrdersClientsBirthdate
			});
			this->dataGridView_OrdersClients->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_OrdersClients->Location = System::Drawing::Point(0, 34);
			this->dataGridView_OrdersClients->Name = L"dataGridView_OrdersClients";
			this->dataGridView_OrdersClients->ReadOnly = true;
			this->dataGridView_OrdersClients->Size = System::Drawing::Size(211, 141);
			this->dataGridView_OrdersClients->TabIndex = 3;
			// 
			// dataGridViewTextBoxColumn_OrdersClientsID
			// 
			this->dataGridViewTextBoxColumn_OrdersClientsID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_OrdersClientsID->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn_OrdersClientsID->Name = L"dataGridViewTextBoxColumn_OrdersClientsID";
			this->dataGridViewTextBoxColumn_OrdersClientsID->ReadOnly = true;
			this->dataGridViewTextBoxColumn_OrdersClientsID->Width = 43;
			// 
			// dataGridViewTextBoxColumn_OrdersClientsFirstname
			// 
			this->dataGridViewTextBoxColumn_OrdersClientsFirstname->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn_OrdersClientsFirstname->FillWeight = 125;
			this->dataGridViewTextBoxColumn_OrdersClientsFirstname->HeaderText = L"Firstname";
			this->dataGridViewTextBoxColumn_OrdersClientsFirstname->MinimumWidth = 80;
			this->dataGridViewTextBoxColumn_OrdersClientsFirstname->Name = L"dataGridViewTextBoxColumn_OrdersClientsFirstname";
			this->dataGridViewTextBoxColumn_OrdersClientsFirstname->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn_OrdersClientsLastname
			// 
			this->dataGridViewTextBoxColumn_OrdersClientsLastname->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn_OrdersClientsLastname->FillWeight = 75;
			this->dataGridViewTextBoxColumn_OrdersClientsLastname->HeaderText = L"Lastname";
			this->dataGridViewTextBoxColumn_OrdersClientsLastname->MinimumWidth = 80;
			this->dataGridViewTextBoxColumn_OrdersClientsLastname->Name = L"dataGridViewTextBoxColumn_OrdersClientsLastname";
			this->dataGridViewTextBoxColumn_OrdersClientsLastname->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn_OrdersClientsBirthdate
			// 
			this->dataGridViewTextBoxColumn_OrdersClientsBirthdate->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_OrdersClientsBirthdate->HeaderText = L"Birthdate";
			this->dataGridViewTextBoxColumn_OrdersClientsBirthdate->Name = L"dataGridViewTextBoxColumn_OrdersClientsBirthdate";
			this->dataGridViewTextBoxColumn_OrdersClientsBirthdate->ReadOnly = true;
			this->dataGridViewTextBoxColumn_OrdersClientsBirthdate->Width = 79;
			// 
			// panel_OrdersClientsSearch
			// 
			this->panel_OrdersClientsSearch->Controls->Add(this->button_OrdersClientsUpdate);
			this->panel_OrdersClientsSearch->Controls->Add(this->textBox_OrdersClientsSearch);
			this->panel_OrdersClientsSearch->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_OrdersClientsSearch->Location = System::Drawing::Point(0, 0);
			this->panel_OrdersClientsSearch->Name = L"panel_OrdersClientsSearch";
			this->panel_OrdersClientsSearch->Size = System::Drawing::Size(211, 34);
			this->panel_OrdersClientsSearch->TabIndex = 2;
			// 
			// button_OrdersClientsUpdate
			// 
			this->button_OrdersClientsUpdate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_OrdersClientsUpdate->Location = System::Drawing::Point(152, 6);
			this->button_OrdersClientsUpdate->Name = L"button_OrdersClientsUpdate";
			this->button_OrdersClientsUpdate->Size = System::Drawing::Size(56, 23);
			this->button_OrdersClientsUpdate->TabIndex = 1;
			this->button_OrdersClientsUpdate->Text = L"Update";
			this->button_OrdersClientsUpdate->UseVisualStyleBackColor = true;
			// 
			// textBox_OrdersClientsSearch
			// 
			this->textBox_OrdersClientsSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_OrdersClientsSearch->ForeColor = System::Drawing::SystemColors::MenuBar;
			this->textBox_OrdersClientsSearch->Location = System::Drawing::Point(6, 6);
			this->textBox_OrdersClientsSearch->Name = L"textBox_OrdersClientsSearch";
			this->textBox_OrdersClientsSearch->Size = System::Drawing::Size(140, 22);
			this->textBox_OrdersClientsSearch->TabIndex = 0;
			// 
			// dataGridView_OrdersStock
			// 
			this->dataGridView_OrdersStock->AllowUserToAddRows = false;
			this->dataGridView_OrdersStock->AllowUserToDeleteRows = false;
			this->dataGridView_OrdersStock->BackgroundColor = System::Drawing::SystemColors::Menu;
			this->dataGridView_OrdersStock->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView_OrdersStock->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn_OrdersStockID,
					this->dataGridViewTextBoxColumn_OrdersStockName, this->dataGridViewTextBoxColumn_OrdersStockCost
			});
			this->dataGridView_OrdersStock->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView_OrdersStock->Location = System::Drawing::Point(0, 34);
			this->dataGridView_OrdersStock->Name = L"dataGridView_OrdersStock";
			this->dataGridView_OrdersStock->ReadOnly = true;
			this->dataGridView_OrdersStock->Size = System::Drawing::Size(216, 141);
			this->dataGridView_OrdersStock->TabIndex = 4;
			// 
			// dataGridViewTextBoxColumn_OrdersStockID
			// 
			this->dataGridViewTextBoxColumn_OrdersStockID->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_OrdersStockID->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn_OrdersStockID->Name = L"dataGridViewTextBoxColumn_OrdersStockID";
			this->dataGridViewTextBoxColumn_OrdersStockID->ReadOnly = true;
			this->dataGridViewTextBoxColumn_OrdersStockID->Width = 43;
			// 
			// dataGridViewTextBoxColumn_OrdersStockName
			// 
			this->dataGridViewTextBoxColumn_OrdersStockName->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->dataGridViewTextBoxColumn_OrdersStockName->HeaderText = L"Name";
			this->dataGridViewTextBoxColumn_OrdersStockName->MinimumWidth = 80;
			this->dataGridViewTextBoxColumn_OrdersStockName->Name = L"dataGridViewTextBoxColumn_OrdersStockName";
			this->dataGridViewTextBoxColumn_OrdersStockName->ReadOnly = true;
			// 
			// dataGridViewTextBoxColumn_OrdersStockCost
			// 
			this->dataGridViewTextBoxColumn_OrdersStockCost->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::AllCells;
			this->dataGridViewTextBoxColumn_OrdersStockCost->HeaderText = L"Cost";
			this->dataGridViewTextBoxColumn_OrdersStockCost->Name = L"dataGridViewTextBoxColumn_OrdersStockCost";
			this->dataGridViewTextBoxColumn_OrdersStockCost->ReadOnly = true;
			this->dataGridViewTextBoxColumn_OrdersStockCost->Width = 55;
			// 
			// panel_OrdersStockSearch
			// 
			this->panel_OrdersStockSearch->Controls->Add(this->button_OrdersStockUpdate);
			this->panel_OrdersStockSearch->Controls->Add(this->textBox_OrdersStockSearch);
			this->panel_OrdersStockSearch->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_OrdersStockSearch->Location = System::Drawing::Point(0, 0);
			this->panel_OrdersStockSearch->Name = L"panel_OrdersStockSearch";
			this->panel_OrdersStockSearch->Size = System::Drawing::Size(216, 34);
			this->panel_OrdersStockSearch->TabIndex = 3;
			// 
			// button_OrdersStockUpdate
			// 
			this->button_OrdersStockUpdate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_OrdersStockUpdate->Location = System::Drawing::Point(157, 6);
			this->button_OrdersStockUpdate->Name = L"button_OrdersStockUpdate";
			this->button_OrdersStockUpdate->Size = System::Drawing::Size(56, 23);
			this->button_OrdersStockUpdate->TabIndex = 1;
			this->button_OrdersStockUpdate->Text = L"Update";
			this->button_OrdersStockUpdate->UseVisualStyleBackColor = true;
			// 
			// textBox_OrdersStockSearch
			// 
			this->textBox_OrdersStockSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_OrdersStockSearch->ForeColor = System::Drawing::SystemColors::MenuBar;
			this->textBox_OrdersStockSearch->Location = System::Drawing::Point(6, 6);
			this->textBox_OrdersStockSearch->Name = L"textBox_OrdersStockSearch";
			this->textBox_OrdersStockSearch->Size = System::Drawing::Size(145, 22);
			this->textBox_OrdersStockSearch->TabIndex = 0;
			// 
			// panel_OrdersInfos
			// 
			this->panel_OrdersInfos->Controls->Add(this->panel_OrdersGap3);
			this->panel_OrdersInfos->Controls->Add(this->panel_OrdersDiscount);
			this->panel_OrdersInfos->Controls->Add(this->panel_OrdersGap2);
			this->panel_OrdersInfos->Controls->Add(this->panel_OrdersPrice);
			this->panel_OrdersInfos->Controls->Add(this->panel_OrdersGap1);
			this->panel_OrdersInfos->Controls->Add(this->panel_OrdersNumberOfProducts);
			this->panel_OrdersInfos->Dock = System::Windows::Forms::DockStyle::Right;
			this->panel_OrdersInfos->Location = System::Drawing::Point(431, 0);
			this->panel_OrdersInfos->Name = L"panel_OrdersInfos";
			this->panel_OrdersInfos->Padding = System::Windows::Forms::Padding(10, 0, 0, 0);
			this->panel_OrdersInfos->Size = System::Drawing::Size(250, 175);
			this->panel_OrdersInfos->TabIndex = 2;
			// 
			// panel_OrdersSearch
			// 
			this->panel_OrdersSearch->Controls->Add(this->button_OrdersUpdate);
			this->panel_OrdersSearch->Controls->Add(this->textBox_OrdersSearch);
			this->panel_OrdersSearch->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_OrdersSearch->Location = System::Drawing::Point(0, 0);
			this->panel_OrdersSearch->Name = L"panel_OrdersSearch";
			this->panel_OrdersSearch->Size = System::Drawing::Size(681, 34);
			this->panel_OrdersSearch->TabIndex = 1;
			// 
			// button_OrdersUpdate
			// 
			this->button_OrdersUpdate->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button_OrdersUpdate->Location = System::Drawing::Point(579, 6);
			this->button_OrdersUpdate->Name = L"button_OrdersUpdate";
			this->button_OrdersUpdate->Size = System::Drawing::Size(99, 23);
			this->button_OrdersUpdate->TabIndex = 1;
			this->button_OrdersUpdate->Text = L"Update";
			this->button_OrdersUpdate->UseVisualStyleBackColor = true;
			// 
			// textBox_OrdersSearch
			// 
			this->textBox_OrdersSearch->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox_OrdersSearch->ForeColor = System::Drawing::SystemColors::MenuBar;
			this->textBox_OrdersSearch->Location = System::Drawing::Point(6, 6);
			this->textBox_OrdersSearch->Name = L"textBox_OrdersSearch";
			this->textBox_OrdersSearch->Size = System::Drawing::Size(563, 22);
			this->textBox_OrdersSearch->TabIndex = 0;
			// 
			// panel_OrdersNumberOfProducts
			// 
			this->panel_OrdersNumberOfProducts->Controls->Add(this->textBox_OrdersNumberOfProducts);
			this->panel_OrdersNumberOfProducts->Controls->Add(this->label_OrdersUnit1);
			this->panel_OrdersNumberOfProducts->Controls->Add(this->label_OrdersNumberOfProducts);
			this->panel_OrdersNumberOfProducts->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_OrdersNumberOfProducts->Location = System::Drawing::Point(10, 0);
			this->panel_OrdersNumberOfProducts->Name = L"panel_OrdersNumberOfProducts";
			this->panel_OrdersNumberOfProducts->Size = System::Drawing::Size(240, 22);
			this->panel_OrdersNumberOfProducts->TabIndex = 1;
			// 
			// label_OrdersNumberOfProducts
			// 
			this->label_OrdersNumberOfProducts->Dock = System::Windows::Forms::DockStyle::Left;
			this->label_OrdersNumberOfProducts->Location = System::Drawing::Point(0, 0);
			this->label_OrdersNumberOfProducts->Name = L"label_OrdersNumberOfProducts";
			this->label_OrdersNumberOfProducts->Size = System::Drawing::Size(64, 22);
			this->label_OrdersNumberOfProducts->TabIndex = 1;
			this->label_OrdersNumberOfProducts->Text = L"Products";
			this->label_OrdersNumberOfProducts->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel_OrdersGap1
			// 
			this->panel_OrdersGap1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_OrdersGap1->Location = System::Drawing::Point(10, 22);
			this->panel_OrdersGap1->Name = L"panel_OrdersGap1";
			this->panel_OrdersGap1->Size = System::Drawing::Size(240, 10);
			this->panel_OrdersGap1->TabIndex = 3;
			// 
			// panel_OrdersPrice
			// 
			this->panel_OrdersPrice->Controls->Add(this->textBox_OrdersPrice);
			this->panel_OrdersPrice->Controls->Add(this->label_OrdersUnit2);
			this->panel_OrdersPrice->Controls->Add(this->label_OrdersPrice);
			this->panel_OrdersPrice->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_OrdersPrice->Location = System::Drawing::Point(10, 32);
			this->panel_OrdersPrice->Name = L"panel_OrdersPrice";
			this->panel_OrdersPrice->Size = System::Drawing::Size(240, 22);
			this->panel_OrdersPrice->TabIndex = 4;
			// 
			// label_OrdersPrice
			// 
			this->label_OrdersPrice->Dock = System::Windows::Forms::DockStyle::Left;
			this->label_OrdersPrice->Location = System::Drawing::Point(0, 0);
			this->label_OrdersPrice->Name = L"label_OrdersPrice";
			this->label_OrdersPrice->Size = System::Drawing::Size(44, 22);
			this->label_OrdersPrice->TabIndex = 1;
			this->label_OrdersPrice->Text = L"Price";
			this->label_OrdersPrice->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// panel_OrdersGap2
			// 
			this->panel_OrdersGap2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_OrdersGap2->Location = System::Drawing::Point(10, 54);
			this->panel_OrdersGap2->Name = L"panel_OrdersGap2";
			this->panel_OrdersGap2->Size = System::Drawing::Size(240, 10);
			this->panel_OrdersGap2->TabIndex = 5;
			// 
			// textBox_OrdersNumberOfProducts
			// 
			this->textBox_OrdersNumberOfProducts->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox_OrdersNumberOfProducts->Location = System::Drawing::Point(64, 0);
			this->textBox_OrdersNumberOfProducts->Name = L"textBox_OrdersNumberOfProducts";
			this->textBox_OrdersNumberOfProducts->Size = System::Drawing::Size(154, 22);
			this->textBox_OrdersNumberOfProducts->TabIndex = 3;
			// 
			// label_OrdersUnit1
			// 
			this->label_OrdersUnit1->Dock = System::Windows::Forms::DockStyle::Right;
			this->label_OrdersUnit1->Location = System::Drawing::Point(218, 0);
			this->label_OrdersUnit1->Name = L"label_OrdersUnit1";
			this->label_OrdersUnit1->Size = System::Drawing::Size(22, 22);
			this->label_OrdersUnit1->TabIndex = 2;
			this->label_OrdersUnit1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_OrdersUnit2
			// 
			this->label_OrdersUnit2->Dock = System::Windows::Forms::DockStyle::Right;
			this->label_OrdersUnit2->Location = System::Drawing::Point(218, 0);
			this->label_OrdersUnit2->Name = L"label_OrdersUnit2";
			this->label_OrdersUnit2->Size = System::Drawing::Size(22, 22);
			this->label_OrdersUnit2->TabIndex = 3;
			this->label_OrdersUnit2->Text = L"€";
			this->label_OrdersUnit2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox_OrdersPrice
			// 
			this->textBox_OrdersPrice->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox_OrdersPrice->Location = System::Drawing::Point(44, 0);
			this->textBox_OrdersPrice->Name = L"textBox_OrdersPrice";
			this->textBox_OrdersPrice->Size = System::Drawing::Size(174, 22);
			this->textBox_OrdersPrice->TabIndex = 7;
			// 
			// panel_OrdersDiscount
			// 
			this->panel_OrdersDiscount->Controls->Add(this->textBox3);
			this->panel_OrdersDiscount->Controls->Add(this->label_OrderUnit3);
			this->panel_OrdersDiscount->Controls->Add(this->textBox2);
			this->panel_OrdersDiscount->Controls->Add(this->label_OrdersUnit4);
			this->panel_OrdersDiscount->Controls->Add(this->label_OrdersDiscout);
			this->panel_OrdersDiscount->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_OrdersDiscount->Location = System::Drawing::Point(10, 64);
			this->panel_OrdersDiscount->Name = L"panel_OrdersDiscount";
			this->panel_OrdersDiscount->Size = System::Drawing::Size(240, 22);
			this->panel_OrdersDiscount->TabIndex = 6;
			// 
			// label_OrdersUnit4
			// 
			this->label_OrdersUnit4->Dock = System::Windows::Forms::DockStyle::Right;
			this->label_OrdersUnit4->Location = System::Drawing::Point(218, 0);
			this->label_OrdersUnit4->Name = L"label_OrdersUnit4";
			this->label_OrdersUnit4->Size = System::Drawing::Size(22, 22);
			this->label_OrdersUnit4->TabIndex = 3;
			this->label_OrdersUnit4->Text = L"€";
			this->label_OrdersUnit4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_OrdersDiscout
			// 
			this->label_OrdersDiscout->Dock = System::Windows::Forms::DockStyle::Left;
			this->label_OrdersDiscout->Location = System::Drawing::Point(0, 0);
			this->label_OrdersDiscout->Name = L"label_OrdersDiscout";
			this->label_OrdersDiscout->Size = System::Drawing::Size(64, 22);
			this->label_OrdersDiscout->TabIndex = 1;
			this->label_OrdersDiscout->Text = L"Discount";
			this->label_OrdersDiscout->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// textBox2
			// 
			this->textBox2->Dock = System::Windows::Forms::DockStyle::Right;
			this->textBox2->Location = System::Drawing::Point(150, 0);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(68, 22);
			this->textBox2->TabIndex = 8;
			// 
			// label_OrderUnit3
			// 
			this->label_OrderUnit3->Dock = System::Windows::Forms::DockStyle::Right;
			this->label_OrderUnit3->Location = System::Drawing::Point(128, 0);
			this->label_OrderUnit3->Name = L"label_OrderUnit3";
			this->label_OrderUnit3->Size = System::Drawing::Size(22, 22);
			this->label_OrderUnit3->TabIndex = 9;
			this->label_OrderUnit3->Text = L"%";
			this->label_OrderUnit3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox3
			// 
			this->textBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox3->Location = System::Drawing::Point(64, 0);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(64, 22);
			this->textBox3->TabIndex = 10;
			// 
			// panel_OrdersGap3
			// 
			this->panel_OrdersGap3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_OrdersGap3->Location = System::Drawing::Point(10, 86);
			this->panel_OrdersGap3->Name = L"panel_OrdersGap3";
			this->panel_OrdersGap3->Size = System::Drawing::Size(240, 10);
			this->panel_OrdersGap3->TabIndex = 7;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(689, 404);
			this->Controls->Add(this->tabControl_Tabs);
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(2);
			this->MinimumSize = System::Drawing::Size(512, 128);
			this->Name = L"MainForm";
			this->Text = L"FirmManager";
			this->tabControl_Tabs->ResumeLayout(false);
			this->tabPage_Home->ResumeLayout(false);
			this->tabPage_Clients->ResumeLayout(false);
			this->splitContainer_Clients->Panel1->ResumeLayout(false);
			this->splitContainer_Clients->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer_Clients))->EndInit();
			this->splitContainer_Clients->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Clients))->EndInit();
			this->panel_Client->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_ClientsAddresses))->EndInit();
			this->panel_ClientSearch->ResumeLayout(false);
			this->panel_ClientSearch->PerformLayout();
			this->tabPage_Stock->ResumeLayout(false);
			this->panel_Stock->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Stock))->EndInit();
			this->panel_StockSearch->ResumeLayout(false);
			this->panel_StockSearch->PerformLayout();
			this->tabPage_Orders->ResumeLayout(false);
			this->splitContainer_Orders->Panel1->ResumeLayout(false);
			this->splitContainer_Orders->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer_Orders))->EndInit();
			this->splitContainer_Orders->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_Orders))->EndInit();
			this->splitContainer_OrdersEdit->Panel1->ResumeLayout(false);
			this->splitContainer_OrdersEdit->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer_OrdersEdit))->EndInit();
			this->splitContainer_OrdersEdit->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_OrdersClients))->EndInit();
			this->panel_OrdersClientsSearch->ResumeLayout(false);
			this->panel_OrdersClientsSearch->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView_OrdersStock))->EndInit();
			this->panel_OrdersStockSearch->ResumeLayout(false);
			this->panel_OrdersStockSearch->PerformLayout();
			this->panel_OrdersInfos->ResumeLayout(false);
			this->panel_OrdersSearch->ResumeLayout(false);
			this->panel_OrdersSearch->PerformLayout();
			this->panel_OrdersNumberOfProducts->ResumeLayout(false);
			this->panel_OrdersNumberOfProducts->PerformLayout();
			this->panel_OrdersPrice->ResumeLayout(false);
			this->panel_OrdersPrice->PerformLayout();
			this->panel_OrdersDiscount->ResumeLayout(false);
			this->panel_OrdersDiscount->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	protected: virtual System::Void linkLabel_Help_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) { }
	protected: virtual System::Void linkLabel_AuthorAbepan_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) { }
	protected: virtual System::Void linkLabel_AuthorBeboudu32_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) { }
	protected: virtual System::Void linkLabel_Author0xybo_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) { }
	};
}