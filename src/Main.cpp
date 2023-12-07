#include "Main.h"

int WinMain() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew App());
}

App::App() {
	// Initialisation de la connexion à la base de données
	this->__database = gcnew Database(ConfigurationManager::AppSettings["connection_string"]);

	// Initialisation des services
	this->__clientService = gcnew ClientService(this->__database);

	// Initialisation des composants de la fenêtre
	this->InitializeComponent();
}

// ========================================================
// =				      GENERAL                         =
// ========================================================

void App::InitializeComponent() {
	// On rappelle le constructeur de la classe mère
	__super::InitializeComponent();

	// Modification du titre de la fenêtre pour correspondre à l'onget sélectionné
	this->Text = "Client - " + ConfigurationManager::AppSettings["app_name"];
	// Modification du titre de l'application
	this->label_Logo->Text = ConfigurationManager::AppSettings["app_name"];

	// Modification des textBox pour ajouter un placeholder et une sortie de focus lors de l'appui sur la touche entrée
	gcnew ElementsCustomization::SearchInputBox(this->textBox_ClientsSearch, "Search", this->dataGridView_Clients);
	gcnew ElementsCustomization::SearchInputBox(this->textBox_StockSearch, "Search");
	gcnew ElementsCustomization::SearchInputBox(this->textBox_OrdersSearch, "Search");
	gcnew ElementsCustomization::SearchInputBox(this->textBox_OrdersClientsSearch, "Search");
	gcnew ElementsCustomization::SearchInputBox(this->textBox_OrdersStockSearch, "Search");

	if (ConfigurationManager::AppSettings["start_maximized"] == "true") {
		this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
	}
}

// Permet de changer le nom de la fenêtre en fonction de l'onglet sélectionné
void App::tabControl_Tabs_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	this->Text = this->tabControl_Tabs->SelectedTab->Text + " - " + "FirmManager";

	switch (this->tabControl_Tabs->SelectedIndex) {
	case 1:
		if (!this->dataGridView_Clients->DataSource) {
			this->dataGridView_Clients->DataSource = Client::toDataSet(this->__clientService->getClients(), "clients");
			this->dataGridView_Clients->DataMember = "clients";

			this->textBox_ClientsSearch->Enabled = true;
			this->button_ClientsUpdate->Enabled = true;
			this->button_ClientsDelete->Enabled = true;
			this->button_ClientsAdd->Enabled = true;
			this->dataGridView_Clients->Enabled = true;
		}
		break;
	case 2:

		break;
	case 3:

		break;
	}
}

// ========================================================
// =                      HOME TAB                        =
// ========================================================

// Ouverture des liens de la page d'accueil
void App::linkLabel_Help_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	openLink("https://github.com/CESI-ORLEANS-A2/Groupe-3-Projet-Bloc-POO", this->linkLabel_Help);
}
void App::linkLabel_AuthorAbepan_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	openLink("https://github.com/ultrasonicytb", this->linkLabel_AuthorAbepan);
}
void App::linkLabel_AuthorBeboudu32_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	openLink("https://github.com/Beboudu32", this->linkLabel_AuthorBeboudu32);
}
void App::linkLabel_Author0xybo_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	openLink("https://github.com/0xybo", this->linkLabel_Author0xybo);
}

// ========================================================
// =                      CLIENTS TAB                     =
// ========================================================

// Mise à jour de la liste des clients
void App::button_ClientsUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	this->dataGridView_Clients->DataSource = Client::toDataSet(this->__clientService->getClients(), "clients");
	if (!this->dataGridView_Clients->DataMember) {
		this->dataGridView_Clients->DataMember = "clients";
	}
}