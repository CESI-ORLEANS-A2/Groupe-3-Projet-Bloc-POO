#include "Main.h"

int WinMain() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew App());
}

App::App() {
	App::__clientsPropertiesRegex->Add("firstname", "^[a-z0-9\\s\\-'`]+$");
	App::__clientsPropertiesRegex->Add("lastname", "^[a-z0-9\\s\\-'`]+$");
	App::__clientsPropertiesRegex->Add("phone", "^[0-9\s]+$");
	App::__clientsPropertiesRegex->Add("email", "^[a-z0-9\\.-_]+@[a-z0-9\\.]+\\.[a-z0-9]{2,3}$");
	App::__clientsPropertiesRegex->Add("birthdate", "^(?:(?:(?:(?<dayoftheweek>lundi|mardi|mercredi|jeudi|vendredi|samedi|dimanche) )?(?:(?<day>0[1-9]|[1-2][0-9]|3[0-1]) (?<month>janvier|mars|mai|juillet|ao[uû]t|octobre|d[ée]cembre)|(?<day>0[1-9]|[1-2][0-9]) (?<month>f[ée]vrier)|(?<day>0[1-9]|[1-2][0-9]|30) (?<month>avril|juin|septembre|novembre))(?: (?<year>[0-9]{4}))?)|(?:(?:(?<day>0?[1-9]|[1-2][0-9]|3[0-1])/(?<month>0?[13578]|1[02])|(?<day>0?[1-9]|[1-2][0-9])/(?<month>0?2)|(?<day>0?[1-9]|[1-2][0-9]|30)/(?<month>0?[469]|11))/(?<year>(?:19|20)?[0-9]{2})))$");
	App::__clientsPropertiesRegex->Add("logo", "^[^']*$");
	App::__clientsPropertiesRegex->Add("company", "^[^']*$");

	App::__addressesPropertiesRegex->Add("number", "^[0-9a-z\\s]+$");
	App::__addressesPropertiesRegex->Add("street", "^[^']+$");
	App::__addressesPropertiesRegex->Add("city", "^[^']+$");
	App::__addressesPropertiesRegex->Add("zip", "^[0-9]{5}$");
	App::__addressesPropertiesRegex->Add("country", "^[^']+$");

	App::__productsPropertiesRegex->Add("name", "^[^']+$");
	App::__productsPropertiesRegex->Add("cost", "^[0-9]+$");
	App::__productsPropertiesRegex->Add("quantity", "^[0-9]+$");
	App::__productsPropertiesRegex->Add("producttype", "^[1-4]{1}$");

	// Initialisation de la connexion à la base de données
	this->__database = gcnew Database(ConfigurationManager::AppSettings["connection_string"]);

	// Initialisation des services
	this->__clientService = gcnew ClientService(this->__database);
	this->__productService = gcnew ProductService(this->__database);

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
	gcnew ElementsCustomization::SearchInputBox(this->textBox_StockSearch, "Search", this->dataGridView_Stock);
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
			this->button_ClientsAdd->Enabled = true;
			this->dataGridView_Clients->Enabled = true;
		}
		break;
	case 2:
		if (!this->dataGridView_Stock->DataSource) {
			this->__updateProducts();

			this->textBox_StockSearch->Enabled = true;
			this->button_StockUpdate->Enabled = true;
			this->button_StockAdd->Enabled = true;
			this->dataGridView_Stock->Enabled = true;
		}
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
	if (this->__isClientEditing && ((
		this->dataGridView_Clients->SelectedRows->Count != 0 &&
		!this->dataGridView_Clients->SelectedRows[0]->Equals(this->__selectedClientRow)
		) || (
			this->dataGridView_Clients->SelectedCells->Count == 1 &&
			!this->dataGridView_Clients->Rows[this->dataGridView_Clients->SelectedCells[0]->RowIndex]->Equals(this->__selectedClientRow)
			))) {
		if (MessageBox::Show("Editing a current customer, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelClientEdition();
		}
		else {
			return;
		}
	}

	if (this->dataGridView_Clients->SelectedRows->Count > 0) {
		if (!this->dataGridView_Clients->SelectedRows[0]->IsNewRow) {
			this->button_ClientsDelete->Enabled = true;
		}
		this->__selectedClients = Client::toArray(this->dataGridView_Clients->SelectedRows);
		this->__selectedClientRow = this->dataGridView_Clients->SelectedRows[0];
	}
}
void App::button_ClientsAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isClientEditing) {
		if (MessageBox::Show("Editing a current customer, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelClientEdition();
		}
		else {
			return;
		}
	}

	this->dataGridView_Clients->ClearSelection();
	this->dataGridView_Clients->Rows[this->dataGridView_Clients->Rows->Count - 1]->Selected = true;
}
void App::button_ClientsDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isClientEditing) {
		if (MessageBox::Show("Editing a current customer, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelClientEdition();
		}
		return;
	}

	if (this->dataGridView_Clients->SelectedRows->Count > 0) {
		if (MessageBox::Show("Do you REALLY want to remove these customers?", "Deleting", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			array<DataGridViewRow^>^ rows = gcnew array<DataGridViewRow^>(this->dataGridView_Clients->SelectedRows->Count);
			this->dataGridView_Clients->SelectedRows->CopyTo(rows, 0);

			for (int i = 0; i < rows->Length; i++) {
				if (rows[i]->IsNewRow) continue;

				int clientId = (gcnew  Client(rows[i]))->id();
				this->__clientService->deleteClient(clientId);

				this->dataGridView_Clients->Rows->Remove(rows[i]);
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

	this->__isClientEditing = false;

	this->__updateClients();
	this->__updateClientsAddresses();
}
void App::__finishClientEdition() {
	if (!this->__isClientEditing) return;

	this->button_ClientsDelete->Enabled = false;
	this->button_ClientsDelete->Text = "Delete";
	this->button_ClientsSubmit->Enabled = false;

	this->__isClientEditing = false;
}

void App::dataGridView_Clients_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
	this->__selectedClientRow = this->dataGridView_Clients->Rows[e->RowIndex];
	this->__startClientEdition();
}
void App::dataGridView_ClientsAddresses_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
	this->__startClientEdition();
}
void App::__updateClients() {
	if (this->__isClientEditing) {
		if (MessageBox::Show("Editing a current customer, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelClientEdition();
		}
		else {
			return;
		}
	}

	this->dataGridView_Clients->DataSource = Client::toDataSet(this->__clientService->getClients(), "clients");
	if (!this->dataGridView_Clients->DataMember->Length) {
		this->dataGridView_Clients->DataMember = "clients";
	}
	this->dataGridView_Clients->Refresh();

	if (this->dataGridView_ClientsAddresses->DataSource) {
		((DataSet^)this->dataGridView_ClientsAddresses->DataSource)->Clear();
	}
	this->dataGridView_ClientsAddresses->Enabled = false;
	this->button_ClientsSubmit->Enabled = false;
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
	DataGridViewRow^ row;
	if (this->dataGridView_Clients->SelectedRows->Count == 0) {
		if (this->dataGridView_Clients->SelectedCells->Count != 1) return;
		row = this->dataGridView_Clients->Rows[this->dataGridView_Clients->SelectedCells[0]->RowIndex];
	}
	else {
		row = this->dataGridView_Clients->SelectedRows[0];
	}


	if (!this->__isClientEditing) return;

	// ========= Vérification du client =========
	for (int j = 0; j < this->dataGridView_Clients->Columns->Count; j++) {
		if (j == 0) continue; // On ne vérifie pas l'id (auto-incrémenté)

		// Récupération de la valeur de la cellule (en string)
		String^ value = row->Cells[j]->Value->ToString()->Trim();
		String^ regex = App::__clientsPropertiesRegex[this->dataGridView_Clients->Columns[j]->DataPropertyName];

		if (!Regex::IsMatch(value,
			regex,
			RegexOptions::IgnoreCase)) {
			MessageBox::Show(
				"The value \"" + value + "\" is not valid for the property \"" + this->dataGridView_Clients->Columns[j]->HeaderText + "\" of Client.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
	}

	// ========= Vérification des adresses =========
	for (int i = 0; i < this->dataGridView_ClientsAddresses->Rows->Count; i++) {
		if (this->dataGridView_ClientsAddresses->Rows[i]->IsNewRow) continue;

		for (int j = 0; j < this->dataGridView_ClientsAddresses->Columns->Count; j++) {
			if (j == 0) continue; // On ne vérifie pas l'id (auto-incrémenté)
			if (j == 1) continue; // On ne vérifie pas l'id du client (Ajouté aprèsà

			// Récupération de la valeur de la cellule (en string)
			String^ value = this->dataGridView_ClientsAddresses->Rows[i]->Cells[j]->Value->ToString()->Trim();
			String^ regex = App::__addressesPropertiesRegex[this->dataGridView_ClientsAddresses->Columns[j]->DataPropertyName];

			if (!Regex::IsMatch(value,
				regex,
				RegexOptions::IgnoreCase)) {
				MessageBox::Show(
					"The value \"" + value + "\" is not valid for the property \"" + this->dataGridView_ClientsAddresses->Columns[j]->HeaderText + "\" of Address " + (i + 1) + ".",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}
		}
	}

	// ========= Vérification des adresses =========
	// Check de la ville et du pays
	for (int i = 0; i < this->dataGridView_ClientsAddresses->Rows->Count; i++) {
		if (this->dataGridView_ClientsAddresses->Rows[i]->IsNewRow) continue;

		String^ city = this->dataGridView_ClientsAddresses->Rows[i]->Cells[4]->Value->ToString()->Trim();
		String^ country = this->dataGridView_ClientsAddresses->Rows[i]->Cells[6]->Value->ToString()->Trim();

		int rsp = __clientService->getCityId(city);

		if (rsp == -1) {
			MessageBox::Show(
				"The city \"" + city + "\" does not exist.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
		if (__clientService->getCountryId(country) == -1) {
			MessageBox::Show(
				"The country \"" + country + "\" does not exist.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
		if (__clientService->getCityInCountry(city, country) == -1) {
			MessageBox::Show(
				"The city \"" + city + "\" does not exist in the country \"" + country + "\".",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
	}

	Client^ client = gcnew Client(row);

	client = this->__clientService->updateClient(client);

	for (int i = 0; i < this->dataGridView_ClientsAddresses->Rows->Count; i++) {
		if (this->dataGridView_ClientsAddresses->Rows[i]->IsNewRow) continue;
		this->dataGridView_ClientsAddresses->Rows[i]->Cells[1]->Value = client->id();
	}

	array<Address^>^ addresses = Address::toArray(this->dataGridView_ClientsAddresses->Rows);
	
	this->__clientService->updateAddresses(addresses);

	this->__finishClientEdition();
}


void App::dataGridView_Clients_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isClientEditing && ((
		this->dataGridView_Clients->SelectedRows->Count != 0 &&
		!this->dataGridView_Clients->SelectedRows[0]->Equals(this->__selectedClientRow)
		) || (
			this->dataGridView_Clients->SelectedCells->Count == 1 &&
			!this->dataGridView_Clients->Rows[this->dataGridView_Clients->SelectedCells[0]->RowIndex]->Equals(this->__selectedClientRow)
			))) {
		if (MessageBox::Show("Editing a current customer, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelClientEdition();
		}
		else {
			if (this->dataGridView_Clients->SelectedRows->Count > 0) {
				this->dataGridView_Clients->Rows[this->dataGridView_Clients->SelectedRows[0]->Index]->Selected = true;
			}
			else {
				this->dataGridView_Clients->Rows[this->dataGridView_Clients->SelectedCells[0]->RowIndex]->Selected = true;
			}
			return;
		}
	}
	if (this->dataGridView_Clients->SelectedRows->Count > 0) {
		this->__selectedClients = Client::toArray(this->dataGridView_Clients->SelectedRows);
		this->__selectedClientRow = this->dataGridView_Clients->SelectedRows[0];

		if (!this->dataGridView_Clients->SelectedRows[0]->IsNewRow) {
			this->button_ClientsDelete->Enabled = true;
			this->dataGridView_ClientsAddresses->Enabled = true;

			this->__updateClientsAddresses();
		}
	}
}

// ========================================================
// =                      STOCK TAB                       =
// ========================================================

void App::dataGridView_Stock_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {

	if (this->__isProductEditing && ((
		this->dataGridView_Stock->SelectedRows->Count != 0 &&
		!this->dataGridView_Stock->SelectedRows[0]->Equals(this->__selectedProductRow)
		) || (
			this->dataGridView_Stock->SelectedCells->Count == 1 &&
			!this->dataGridView_Stock->Rows[this->dataGridView_Stock->SelectedCells[0]->RowIndex]->Equals(this->__selectedProductRow)
			))) {
		if (MessageBox::Show("Editing a current product, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelProductEdition();
		}
		else {
			if (this->dataGridView_Stock->SelectedRows->Count > 0) {
				this->dataGridView_Stock->Rows[this->dataGridView_Stock->SelectedRows[0]->Index]->Selected = false;
			}
			else {
				this->dataGridView_Stock->Rows[this->dataGridView_Stock->SelectedCells[0]->RowIndex]->Selected = false;
			}
			return;
		}
	}
	if (this->dataGridView_Stock->SelectedRows->Count > 0) {
		if (!this->dataGridView_Stock->SelectedRows[0]->IsNewRow) {
			this->button_StockDelete->Enabled = true;
		}
		this->__selectedProduct = gcnew Product();
		this->__selectedProductRow = this->dataGridView_Stock->SelectedRows[0];
	}
}

void App::dataGridView_Stock_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
	this->__selectedProductRow = this->dataGridView_Stock->Rows[e->RowIndex];

	this->__startProductEdition();
}

void App::__startProductEdition() {
	if (this->__isProductEditing) return;

	this->button_StockDelete->Enabled = true;
	this->button_StockDelete->Text = "Cancel";
	this->button_StockSubmit->Enabled = true;

	this->__isProductEditing = true;
}

void App::__cancelProductEdition() {
	if (!this->__isProductEditing) return;

	this->button_StockDelete->Enabled = false;
	this->button_StockDelete->Text = "Delete";
	this->button_StockSubmit->Enabled = false;

	this->__isProductEditing = false;

	this->__updateProducts();
}

void App::__finishProductEdition() {
	if (!this->__isProductEditing) return;

	this->button_StockDelete->Enabled = false;
	this->button_StockDelete->Text = "Delete";
	this->button_StockSubmit->Enabled = false;

	this->__isProductEditing = false;
}

void App::__updateProducts() {
	if (this->__isProductEditing) {
		if (MessageBox::Show("Editing a current product, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelProductEdition();
		}
		else {
			return;
		}
	}

	if (this->dataGridView_Stock->DataSource) {
		((DataSet^)this->dataGridView_Stock->DataSource)->Clear();
	}
	this->dataGridView_Stock->DataSource = Product::toDataSet(this->__productService->getProducts(), "products");
	if (!this->dataGridView_Stock->DataMember->Length) {
		this->dataGridView_Stock->DataMember = "products";
	}
	this->dataGridView_Stock->Refresh();
}

void App::button_StockUpdate_Click(System::Object^ sender, System::EventArgs^ e){
	this->__updateProducts();
}

void App::button_StockAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isProductEditing) {
		if (MessageBox::Show("Editing a current product, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelProductEdition();
		}
		else {
			return;
		}
	}

	this->dataGridView_Stock->ClearSelection();
	this->dataGridView_Stock->Rows[this->dataGridView_Stock->Rows->Count - 1]->Selected = true;
}

void App::button_StockDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isProductEditing) {
		if (MessageBox::Show("Editing a current product, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelProductEdition();
		}
		return;
	}

	if (this->dataGridView_Stock->SelectedRows->Count > 0) {
		if (MessageBox::Show("Do you REALLY want to remove this product?", "Deleting", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			int productId = (gcnew Product(this->__selectedProductRow))->id();
			this->__productService->removeProduct(productId);

			this->dataGridView_Stock->Rows->Remove(this->__selectedProductRow);
		}
	}
}

void Groupe3ProjetBlocPOO::App::button_StockSubmit_Click(System::Object^ sender, System::EventArgs^ e){
	DataGridViewRow^ row;
	if (this->dataGridView_Stock->SelectedRows->Count == 0) {
		if (this->dataGridView_Stock->SelectedCells->Count != 1) return;
		row = this->dataGridView_Stock->Rows[this->dataGridView_Stock->SelectedCells[0]->RowIndex];
	}
	else {
		row = this->dataGridView_Stock->SelectedRows[0];
	}

	if (!this->__isProductEditing) return;

	// ========= Vérification du produit =========
	for (int j = 0; j < this->dataGridView_Stock->Columns->Count; j++) {
		if (j == 0) continue; // On ne vérifie pas l'id (auto-incrémenté)

		// Récupération de la valeur de la cellule (en string)
		String^ value = row->Cells[j]->Value->ToString()->Trim();
		String^ regex = App::__productsPropertiesRegex[this->dataGridView_Stock->Columns[j]->DataPropertyName];

		if (!Regex::IsMatch(value,
			regex,
			RegexOptions::IgnoreCase)) {
			MessageBox::Show(
				"The value \"" + value + "\" is not valid for the property \"" + this->dataGridView_Stock->Columns[j]->HeaderText + "\" of Product.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
	}

	Product^ product = gcnew Product(row);

	this->__productService->addProduct(product);

	this->__finishProductEdition();

	this->__updateProducts();
}
