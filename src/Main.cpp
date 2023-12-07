#include "Main.h"

int WinMain() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew App());
}

App::App() {
	App::__clientsPropertiesRegex->Add("id", "^[0-9]+$");
	App::__clientsPropertiesRegex->Add("firstname", "^[a-z0-9\\s\\-'`]+$");
	App::__clientsPropertiesRegex->Add("lastname", "^[a-z0-9\\s\\-'`]+$");
	App::__clientsPropertiesRegex->Add("phone", "^[0-9\s]+$");
	App::__clientsPropertiesRegex->Add("email", "^[a-z0-9\\.-_]+@[a-z0-9\\.]+\\.[a-z0-9]{2,3}$");
	App::__clientsPropertiesRegex->Add("birthdate", "^(?:(?:(?:(?<dayoftheweek>lundi|mardi|mercredi|jeudi|vendredi|samedi|dimanche) )?(?:(?<day>0[1-9]|[1-2][0-9]|3[0-1]) (?<month>janvier|mars|mai|juillet|ao[uû]t|octobre|d[ée]cembre)|(?<day>0[1-9]|[1-2][0-9]) (?<month>f[ée]vrier)|(?<day>0[1-9]|[1-2][0-9]|30) (?<month>avril|juin|septembre|novembre))(?: (?<year>[0-9]{4}))?)|(?:(?:(?<day>0?[1-9]|[1-2][0-9]|3[0-1])/(?<month>0?[13578]|1[02])|(?<day>0?[1-9]|[1-2][0-9])/(?<month>0?2)|(?<day>0?[1-9]|[1-2][0-9]|30)/(?<month>0?[469]|11))/(?<year>(?:19|20)?[0-9]{2})))$");
	App::__clientsPropertiesRegex->Add("logo", "^.+$");
	App::__clientsPropertiesRegex->Add("company", "^.+$");

	App::__addressesPropertiesRegex->Add("id", "^[0-9]+$");
	App::__addressesPropertiesRegex->Add("number", "^[0-9a-z\\s]+$");
	App::__addressesPropertiesRegex->Add("street", "^.+$");
	App::__addressesPropertiesRegex->Add("city", "^[0-9]+$");
	App::__addressesPropertiesRegex->Add("zip", "^[0-9]{5}$");
	App::__addressesPropertiesRegex->Add("country", "^[0-9]+$");

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
			this->__updateClients();

			this->textBox_ClientsSearch->Enabled = true;
			this->button_ClientsUpdate->Enabled = true;
			//this->button_ClientsDelete->Enabled = true;
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
	if (this->__isClientEditing) {
		if (MessageBox::Show("Editing a current customer, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelClientEdition();
		}
		else {
			return;
		}
	}

	this->__updateClients();
}
void App::dataGridView_Clients_RowHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
	if (this->__isClientEditing) {
		if (MessageBox::Show("Editing a current customer, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelClientEdition();
		}
		else {
			return;
		}

	}

	if (this->dataGridView_Clients->SelectedRows->Count > 0) {
		if (this->dataGridView_Clients->SelectedRows[0]->IsNewRow) return;

		this->button_ClientsDelete->Enabled = true;

		this->__selectedClients = Client::toArray(this->dataGridView_Clients->SelectedRows);

		this->__updateClientsAddresses();

		this->button_ClientsDelete->Enabled = true;
		this->dataGridView_ClientsAddresses->Enabled = true;
	}
}
void App::button_ClientsAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	// TODO Vérification de l'édition

	this->dataGridView_Clients->ClearSelection();

	this->dataGridView_Clients->Rows[this->dataGridView_Clients->Rows->Count - 1]->Selected = true;
}
void App::button_ClientsDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	// TODO Vérification de l'édition
	if (this->__isClientEditing) {
		if (MessageBox::Show("Editing a current customer, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelClientEdition();
		}
		return;
	}

	if (this->dataGridView_Clients->SelectedRows->Count > 0) {
		if (MessageBox::Show("Do you REALLY want to remove these customers?", "Deleting", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			for (int i = 0; i < this->dataGridView_Clients->SelectedRows->Count; i++) {
				if (this->dataGridView_Clients->SelectedRows[0]->IsNewRow) continue;

				int clientId = this->__selectedClients[i]->id();
				this->__clientService->deleteClient(clientId);

				this->dataGridView_Clients->Rows->Remove(this->dataGridView_Clients->SelectedRows[0]);
			}
		}
	}
}

void App::__startClientEdition() {
	if (this->__isClientEditing) return;

	this->button_ClientsDelete->Enabled = true;
	this->button_ClientsDelete->Text = "Cancel";
	this->button_ClientsSubmit->Enabled = true;

	this->__isClientEditing = true;
}
void App::__cancelClientEdition() {
	if (!this->__isClientEditing) return;

	this->button_ClientsDelete->Enabled = false;
	this->button_ClientsDelete->Text = "Delete";
	this->button_ClientsSubmit->Enabled = false;

	this->__updateClients();
	this->__updateClientsAddresses();

	this->__isClientEditing = false;
}

void App::dataGridView_Clients_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
	this->__startClientEdition();
}
void App::dataGridView_ClientsAddresses_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
	this->__startClientEdition();
}
void App::__updateClients() {
	this->dataGridView_Clients->DataSource = Client::toDataSet(this->__clientService->getClients(), "clients");
	if (!this->dataGridView_Clients->DataMember->Length) {
		this->dataGridView_Clients->DataMember = "clients";
	}
	this->dataGridView_Clients->Refresh();
}
void App::__updateClientsAddresses() {
	if (this->dataGridView_Clients->SelectedRows->Count > 0) {
		if (this->dataGridView_Clients->SelectedRows[0]->IsNewRow) return;

		int clientId = this->__selectedClients[0]->id();
		array<Address^>^ addresses = this->__clientService->getAddresses(clientId);

		this->dataGridView_ClientsAddresses->DataSource = Address::toDataSet(addresses, "addresses");
		if (!this->dataGridView_ClientsAddresses->DataMember->Length) {
			this->dataGridView_ClientsAddresses->DataMember = "addresses";
		}
	}
}
void App::button_ClientsSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->dataGridView_Clients->SelectedRows->Count > 0) {
		if (!this->__isClientEditing) return;
		if (this->dataGridView_Clients->SelectedRows[0]->IsNewRow) return;


	}
}