#include "Main.h"

int WinMain() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	App^ app = gcnew App();
	if (app->IsDisposed) {
		return 0;
	}
	Application::Run(app);
}

App::App() {
	StartForm^ form = gcnew StartForm();
	Application::Run(form);
	if (form->types == UserTypes::UNDEFINED) {
		this->Close();
		return;
	}

	App::__clientsPropertiesRegex->Add("firstname", "^[a-z0-9\\s\\-'`]+$");
	App::__clientsPropertiesRegex->Add("lastname", "^[a-z0-9\\s\\-'`]+$");
	App::__clientsPropertiesRegex->Add("phone", "^[0-9\\s]+$");
	App::__clientsPropertiesRegex->Add("email", "^[a-z0-9\\.-_]+@[a-z0-9\\.]+\\.[a-z0-9]{2,3}$");
	App::__clientsPropertiesRegex->Add("birthdate", App::__dateRegex);
	App::__clientsPropertiesRegex->Add("logo", "^[^']*$");
	App::__clientsPropertiesRegex->Add("company", "^[^']*$");

	App::__addressesPropertiesRegex->Add("number", "^[0-9a-z\\s]+$");
	App::__addressesPropertiesRegex->Add("street", "^[^']+$");
	App::__addressesPropertiesRegex->Add("city", "^[^']+$");
	App::__addressesPropertiesRegex->Add("zip", "^[0-9]{5}$");
	App::__addressesPropertiesRegex->Add("country", "^[^']+$");

	App::__ordersPropertiesRegex->Add("paymentDate", App::__dateRegex);
	App::__ordersPropertiesRegex->Add("deliveryDate", App::__dateRegex);
	App::__ordersPropertiesRegex->Add("paymentMethod", "^[^']+$");

	App::__productsPropertiesRegex->Add("name", "^[^']+$");
	App::__productsPropertiesRegex->Add("description", "^[^']*$");
	App::__productsPropertiesRegex->Add("cost", "^[0-9]+$");
	App::__productsPropertiesRegex->Add("type", "^[^']+$");
	App::__productsPropertiesRegex->Add("tax", "^[0-9]+$");
	App::__productsPropertiesRegex->Add("stock", "^[0-9]+$");
	App::__productsPropertiesRegex->Add("quantity", "^[0-9]+$");
	App::__productsPropertiesRegex->Add("producttype", "^[0-9]+$");

	// Initialisation de la connexion à la base de données
	this->__database = gcnew Database(ConfigurationManager::AppSettings["connection_string"]);

	// Initialisation des services
	this->__clientService = gcnew ClientService(this->__database);
	this->__productService = gcnew ProductService(this->__database);
	this->__orderService = gcnew OrderService(this->__database);

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

	this->label_OrdersPriceUnit->Text = L"\u20ac";
	this->label_OrdersDiscountUnit2->Text = L"\u20ac";
	this->label_OrdersTaxUnit->Text = L"\u20ac";
	this->label_OrdersTotalUnit->Text = L"\u20ac";

	// Modification des textBox pour ajouter un placeholder et une sortie de focus lors de l'appui sur la touche entrée
	gcnew ElementsCustomization::SearchInputBox(this->textBox_ClientsSearch, "Search", this->dataGridView_Clients);
	gcnew ElementsCustomization::SearchInputBox(this->textBox_StockSearch, "Search", this->dataGridView_Stock);
	gcnew ElementsCustomization::SearchInputBox(this->textBox_OrdersSearch, "Search", this->dataGridView_Orders);
	gcnew ElementsCustomization::SearchInputBox(this->textBox_OrdersClientsSearch, "Search", this->dataGridView_OrdersClients);
	gcnew ElementsCustomization::SearchInputBox(this->textBox_OrdersStockSearch, "Search", this->dataGridView_OrdersStock);

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
		if (!this->dataGridView_Orders->DataSource) {
			this->__updateOrders();

			this->textBox_OrdersSearch->Enabled = true;
			this->button_OrdersUpdate->Enabled = true;
			this->dataGridView_Orders->Enabled = true;
			this->button_OrdersAdd->Enabled = true;
		}
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

void App::button_StockUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
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

void Groupe3ProjetBlocPOO::App::button_StockSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
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
		if (j == 3 || j == 4 || j == 6) continue;

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

// ========================================================
// =                      ORDER TAB                       =
// ========================================================

void App::__updateOrders() {
	if (this->__isOrderEditing) {
		if (MessageBox::Show("Editing a current order, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelOrderEdition();
		}
		else {
			return;
		}
	}

	// Désactivation des éléments spécifiques à l'édition d'une commande
	if (this->dataGridView_OrdersClients->DataSource) {
		((DataSet^)this->dataGridView_OrdersClients->DataSource)->Clear();
	}
	if (this->dataGridView_OrdersStock->DataSource) {
		((DataSet^)this->dataGridView_OrdersStock->DataSource)->Clear();
	}
	if (this->dataGridView_OrdersAddresses->DataSource) {
		((DataSet^)this->dataGridView_OrdersAddresses->DataSource)->Clear();
	}

	this->textBox_OrdersClientsSearch->Enabled = false;
	this->textBox_OrdersStockSearch->Enabled = false;
	this->button_OrdersClientsUpdate->Enabled = false;
	this->button_OrdersStockUpdate->Enabled = false;
	this->dataGridView_OrdersClients->Enabled = false;
	this->dataGridView_OrdersStock->Enabled = false;
	this->dataGridView_OrdersAddresses->Enabled = false;
	this->button_OrdersQuote->Enabled = false;
	this->button_OrdersSubmit->Enabled = false;
	this->textBox_OrdersEuroDiscount->Enabled = false;
	this->textBox_OrdersPercentageDiscount->Enabled = false;
	this->textBox_OrdersNumberOfProducts->Enabled = false;
	this->textBox_OrdersPrice->Enabled = false;
	this->textBox_OrdersTax->Enabled = false;
	this->textBox_OrdersTotal->Enabled = false;

	this->dataGridView_Orders->DataSource = Order::toDataSet(this->__orderService->getOrders(), "orders");
	if (!this->dataGridView_Orders->DataMember->Length) {
		this->dataGridView_Orders->DataMember = "orders";
	}

	this->textBox_OrdersNumberOfProducts->Text = "0";
	this->textBox_OrdersPrice->Text = "0";
	this->textBox_OrdersPercentageDiscount->Text = "0";
	this->textBox_OrdersEuroDiscount->Text = "0";
	this->textBox_OrdersTax->Text = "0";
	this->textBox_OrdersTotal->Text = "0";
}

void App::__cancelOrderEdition() {
	this->__isOrderEditing = false;
	this->__isNewOrder = false;

	this->textBox_OrdersNumberOfProducts->Enabled = false;
	this->textBox_OrdersPrice->Enabled = false;
	this->textBox_OrdersPercentageDiscount->Enabled = false;
	this->textBox_OrdersEuroDiscount->Enabled = false;
	this->textBox_OrdersTax->Enabled = false;
	this->textBox_OrdersTotal->Enabled = false;

	this->button_OrdersSubmit->Enabled = false;
	this->button_OrdersQuote->Enabled = false;

	this->dataGridView_OrdersAddresses->Enabled = false;
	this->dataGridView_OrdersClients->Enabled = false;
	this->dataGridView_OrdersStock->Enabled = false;

	this->dataGridView_OrdersAddresses->DataSource = nullptr;
	this->dataGridView_OrdersClients->DataSource = nullptr;
	this->dataGridView_OrdersStock->DataSource = nullptr;

	this->button_OrdersDelete->Text = "Delete";
	this->button_OrdersDelete->Enabled = false;
	this->button_OrdersAdd->Enabled = true;
}

void App::__finishOrderEdition() {
	this->__isOrderEditing = false;
	this->__isNewOrder = false;

	this->button_OrdersDelete->Text = "Delete";
	this->button_OrdersDelete->Enabled = true;
	this->button_OrdersAdd->Enabled = true;

	this->__cancelOrderEdition();
}

void App::button_OrdersUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isOrderEditing) {
		if (MessageBox::Show("Editing a current order, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelOrderEdition();
		}
		else {
			return;
		}
	}

	this->__updateOrders();
}

void App::dataGridView_Orders_RowHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
	if (this->__isOrderEditing) {
		if (MessageBox::Show("Editing a current order, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelOrderEdition();
		}
		else return;
	}

	if (this->dataGridView_Orders->SelectedRows->Count == 0) return;
	if (!this->dataGridView_Orders->SelectedRows[0]->IsNewRow) {
		this->__isNewOrder = false;
		this->__selectedOrderRowBeforeEdition = this->dataGridView_Orders->SelectedRows[0];

		this->dataGridView_Orders->ClearSelection();
		this->__selectedOrderRowBeforeEdition->Selected = true;

		this->__showOrdersDetails();

		this->button_OrdersAdd->Enabled = true;
		this->button_OrdersDelete->Enabled = true;
		this->button_OrdersDelete->Text = "Delete";
	}
	else {
		this->__isNewOrder = true;
		this->__selectedOrderRowBeforeEdition = nullptr;

		this->dataGridView_Orders->ClearSelection();
		this->dataGridView_Orders->Rows[this->dataGridView_Orders->NewRowIndex]->Selected = true;

		this->__showNewOrdersDetails();

		this->button_OrdersAdd->Enabled = false;
		this->button_OrdersDelete->Enabled = true;
		this->button_OrdersDelete->Text = "Cancel";
	}
}

void App::button_OrdersClientsUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isNewOrder) {
		DataGridViewRow^ row = nullptr;
		if (this->dataGridView_OrdersClients->SelectedRows->Count > 0) {
			row = this->dataGridView_Orders->SelectedRows[0];
		}

		this->dataGridView_OrdersClients->DataSource = Client::toDataSet(this->__clientService->getClients(), "clients");

		if (row) {
			for (int i = 0; i < this->dataGridView_OrdersClients->Rows->Count; i++) {
				if (this->dataGridView_OrdersClients->Rows[i]->Cells[0]->Value->ToString() == row->Cells[0]->Value->ToString()) {
					this->dataGridView_OrdersClients->Rows[i]->Selected = true;
					break;
				}
			}
		}
	}
	else {
		int clientId = Convert::ToInt32(this->__selectedOrderRowBeforeEdition->Cells[8]->Value->ToString());

		Client^ client = this->__clientService->getClient(clientId);
		DataSet^ clientDataSet = Client::toDataSet(gcnew array<Client^>{ client }, "clients");

		this->dataGridView_OrdersClients->DataSource = clientDataSet;
	}
}

void App::button_OrdersStockUpdate_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isOrderEditing) {
		if (MessageBox::Show("Editing a current order, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelOrderEdition();
		}
		else return;
	}

	if (this->__isNewOrder) {
		this->dataGridView_OrdersStock->DataSource = Product::toDataSet(this->__productService->getOrderProducts(), "products");

		if (this->dataGridView_OrdersClients->SelectedRows->Count > 0) {
			this->__showOrderPriceDetails(gcnew Client(this->dataGridView_OrdersClients->SelectedRows[0]), Product::toArray(this->dataGridView_OrdersStock->Rows));
		}
	}
	else {
		int orderId = Convert::ToInt32(this->__selectedOrderRowBeforeEdition->Cells[0]->Value->ToString());

		this->dataGridView_OrdersStock->DataSource = Product::toDataSet(this->__productService->getOrderProducts(orderId), "products");

		this->__showOrderPriceDetails(gcnew Client(this->dataGridView_OrdersClients->Rows[0]), Product::toArray(this->dataGridView_OrdersStock->Rows));
	}
}

void App::dataGridView_OrdersStock_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (!this->__isOrderEditing) return;

	DataGridViewRow^ row = this->dataGridView_OrdersStock->Rows[e->RowIndex];
	int value = Convert::ToInt32(row->Cells[e->ColumnIndex]->Value->ToString());
	int productId = Convert::ToInt32(row->Cells[0]->Value->ToString());

	if (this->__isNewOrder) {
		row->DefaultCellStyle->BackColor = Color::FromArgb(252, 214, 99);
		return;
	}

	Product^ product = nullptr;
	for (int i = 0; i < this->__orderProductsBeforeEdition->Length; i++) {
		if (this->__orderProductsBeforeEdition[i]->id() == productId) {
			product = this->__orderProductsBeforeEdition[i];
			break;
		}
	}

	if (product && value == product->quantity()) {
		row->DefaultCellStyle->BackColor = Color::White;
	}
	else {
		row->DefaultCellStyle->BackColor = Color::FromArgb(252, 214, 99);
	}
	this->dataGridView_OrdersStock->Refresh();
}

void App::dataGridView_OrdersStock_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
	this->__isOrderEditing = true;
	this->button_OrdersDelete->Text = "Cancel";

	this->button_OrdersSubmit->Enabled = true;
	this->button_OrdersQuote->Enabled = true;
}

void App::button_OrdersAdd_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isOrderEditing) {
		if (MessageBox::Show("Editing a current order, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelOrderEdition();
		}
		else return;
	}

	this->__isNewOrder = true;
	this->__selectedOrderRowBeforeEdition = nullptr;

	this->dataGridView_Orders->ClearSelection();
	this->dataGridView_Orders->Rows[this->dataGridView_Orders->NewRowIndex]->Selected = true;

	this->__showNewOrdersDetails();

	this->button_OrdersAdd->Enabled = false;
	this->button_OrdersDelete->Enabled = true;
	this->button_OrdersDelete->Text = "Cancel";
}

void App::dataGridView_OrdersStock_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (!this->__isOrderEditing) return;
	if (!this->__selectedOrderClientRow) return;

	this->__showOrderPriceDetails(gcnew Client(this->__selectedOrderClientRow), Product::toArray(this->dataGridView_OrdersStock->Rows));
}

void App::dataGridView_OrdersClients_RowHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) {
	if (!this->__isNewOrder) return;

	this->__selectedOrderClientRow = this->dataGridView_OrdersClients->SelectedRows[0];

	this->dataGridView_OrdersClients->ClearSelection();
	this->__selectedOrderClientRow->Selected = true;

	this->button_OrdersSubmit->Enabled = true;
	this->button_OrdersQuote->Enabled = true;

	this->__showOrderPriceDetails(gcnew Client(this->__selectedOrderClientRow), Product::toArray(this->dataGridView_OrdersStock->Rows));
}

void App::dataGridView_OrdersAddresses_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	if (!this->__isOrderEditing) return;

	if (!this->__orderAddressesBeforeEdition[0]) return;
	if (!this->__orderAddressesBeforeEdition[1]) return;

	DataRow^ oldBillingAddress = this->__orderAddressesBeforeEdition[0]->toDataRow();
	DataRow^ oldDeliveryAddress = this->__orderAddressesBeforeEdition[1]->toDataRow();

	this->dataGridView_OrdersAddresses->Rows[0]->DefaultCellStyle->BackColor = Color::White;
	for (int i = 3; i < this->dataGridView_OrdersAddresses->Columns->Count; i++) {
		String^ newValue = this->dataGridView_OrdersAddresses->Rows[0]->Cells[i]->Value->ToString();
		String^ oldValue = oldBillingAddress[i - 1]->ToString();

		if (newValue != oldValue) {
			this->dataGridView_OrdersAddresses->Rows[0]->DefaultCellStyle->BackColor = Color::FromArgb(252, 214, 99);
			break;
		}
	}

	this->dataGridView_OrdersAddresses->Rows[1]->DefaultCellStyle->BackColor = Color::White;
	for (int i = 3; i < this->dataGridView_OrdersAddresses->Columns->Count; i++) {
		String^ newValue = this->dataGridView_OrdersAddresses->Rows[1]->Cells[i]->Value->ToString();
		String^ oldValue = oldDeliveryAddress[i - 1]->ToString();

		if (newValue != oldValue) {
			this->dataGridView_OrdersAddresses->Rows[1]->DefaultCellStyle->BackColor = Color::FromArgb(252, 214, 99);
			break;
		}
	}

	this->dataGridView_OrdersAddresses->Refresh();
}

void App::dataGridView_OrdersAddresses_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
	this->__isOrderEditing = true;
	this->button_OrdersDelete->Text = "Cancel";

	this->button_OrdersSubmit->Enabled = true;
	this->button_OrdersQuote->Enabled = true;
}

void App::button_OrdersSubmit_Click(System::Object^ sender, System::EventArgs^ e) {
	if (!this->__isOrderEditing) return;

	DataTable^ cities = this->__clientService->getCities();

	// ========= Vérification des adresses =========
	for (int i = 0; i < this->dataGridView_OrdersAddresses->Rows->Count; i++) {
		for (int j = 3; j < this->dataGridView_OrdersAddresses->Columns->Count; j++) {

			// Récupération de la valeur de la cellule (en string)
			String^ value = this->dataGridView_OrdersAddresses->Rows[i]->Cells[j]->Value->ToString()->Trim();
			String^ columnName = this->dataGridView_OrdersAddresses->Columns[j]->DataPropertyName;

			if (!App::__addressesPropertiesRegex->ContainsKey(columnName)) continue;

			String^ regex = App::__addressesPropertiesRegex[columnName];

			if (!Regex::IsMatch(value,
				regex,
				RegexOptions::IgnoreCase)) {
				MessageBox::Show(
					"The value \"" + value + "\" is not valid for the property \"" + this->dataGridView_OrdersAddresses->Columns[j]->HeaderText + "\" of Address " + (i + 1) + ".",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}

			if (columnName == "city" && !cities->Select("name = '" + value + "'")->Length) {
				MessageBox::Show(
					"The city \"" + value + "\" does not exist.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}
		}
	}

	if (this->__isNewOrder) {
		// ======== Vérification du client =========
		if (this->dataGridView_OrdersClients->SelectedRows->Count == 0) {
			MessageBox::Show(
				"You must select a client.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
	}

	// ========= Vérification des produits =========
	for (int i = 0; i < this->dataGridView_OrdersStock->Rows->Count; i++) {

		String^ quantityString = this->dataGridView_OrdersStock->Rows[i]->Cells[5]->Value->ToString();

		if (!Regex::IsMatch(quantityString,
			this->__productsPropertiesRegex["quantity"],
			RegexOptions::IgnoreCase)) {
			MessageBox::Show(
				"The value \"" + quantityString + "\" is not valid for the property \"quantity\" of Product " + (i + 1) + ".",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}

		int stock = Convert::ToInt32(this->dataGridView_OrdersStock->Rows[i]->Cells[6]->Value->ToString());
		int quantity = Convert::ToInt32(quantityString);

		if (stock < quantity) {
			MessageBox::Show(
				"The quantity of the product " + this->dataGridView_OrdersStock->Rows[i]->Cells[1]->Value->ToString() + " is too high.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
	}

	// ======== Vérification de la commande =========
	for (int i = 1; i < this->__selectedOrderRowBeforeEdition->Cells->Count - 1; i++) {

		String^ columnName = this->__selectedOrderRowBeforeEdition->DataGridView->Columns[i]->DataPropertyName;
		if (!this->__selectedOrderRowBeforeEdition->Cells[i]->Value) {
			if (App::__ordersPropertiesRegex->ContainsKey(columnName)) {
				MessageBox::Show(
					"You must fill the property \"" + this->__selectedOrderRowBeforeEdition->DataGridView->Columns[i]->HeaderText + "\" of Order.",
					"Error",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error
				);
				return;
			}
			continue;
		}
		String^ value = this->__selectedOrderRowBeforeEdition->Cells[i]->Value->ToString()->Trim();

		if (!App::__ordersPropertiesRegex->ContainsKey(columnName)) continue;

		String^ regex = App::__ordersPropertiesRegex[columnName];

		if (!Regex::IsMatch(value,
			regex,
			RegexOptions::IgnoreCase)) {
			MessageBox::Show(
				"The value \"" + value + "\" is not valid for the property \"" + this->__selectedOrderRowBeforeEdition->DataGridView->Columns[i]->HeaderText + "\" of Order.",
				"Error",
				MessageBoxButtons::OK,
				MessageBoxIcon::Error
			);
			return;
		}
	}

	if (this->__isNewOrder) {
		// Création des adresses
		Address^ billingAddress = gcnew Address(((DataRowView^)this->dataGridView_OrdersAddresses->Rows[0]->DataBoundItem)->Row);
		Address^ deliveryAddress = gcnew Address(((DataRowView^)this->dataGridView_OrdersAddresses->Rows[1]->DataBoundItem)->Row);

		billingAddress = this->__clientService->createAddress(billingAddress);
		deliveryAddress = this->__clientService->createAddress(deliveryAddress);

		// Création de la commande
		DateTime^ now = DateTime::Now;

		Order^ order = gcnew Order(this->dataGridView_Orders->Rows[this->__selectedOrderRowBeforeEdition->Index - 1]);
		order->customer(Convert::ToInt32(this->__selectedOrderClientRow->Cells[0]->Value->ToString()));
		order->creationDate(now->Day + "/" + now->Month + "/" + now->Year);
		order->amount(Convert::ToDouble(this->textBox_OrdersTotal->Text->Replace(".", ",")));
		order->billingAddress(billingAddress->id());
		order->deliveryAddress(deliveryAddress->id());

		order = this->__orderService->addOrder(order);

		// Association des produits à la commande
		array<Product^>^ products = Product::toArray(this->dataGridView_OrdersStock->Rows);

		for (int i = 0; i < products->Length; i++) {
			if (products[i]->quantity() == 0) continue;

			this->__orderService->linkProductToOrder(order->id(), products[i]->id(), products[i]->quantity());
		}
	}
	else {
		// Mise à jour des adresses
		Address^ billingAddress = gcnew Address(((DataRowView^)this->dataGridView_OrdersAddresses->Rows[0]->DataBoundItem)->Row);
		Address^ deliveryAddress = gcnew Address(((DataRowView^)this->dataGridView_OrdersAddresses->Rows[1]->DataBoundItem)->Row);

		billingAddress = this->__clientService->updateAddress(billingAddress);
		deliveryAddress = this->__clientService->updateAddress(deliveryAddress);

		// Mise à jour de la commande
		Order^ order = gcnew Order(this->dataGridView_Orders->Rows[this->__selectedOrderRowBeforeEdition->Index]);
		order->billingAddress(billingAddress->id());
		order->deliveryAddress(deliveryAddress->id());

		this->__orderService->updateOrder(order);

		// Mise à jour des produits de la commande
		array<Product^>^ oldProducts = this->__orderProductsBeforeEdition;
		array<Product^>^ newProducts = Product::toArray(this->dataGridView_OrdersStock->Rows);
		array<Product^>^ products = gcnew array<Product^> {};

		for (int i = 0; i < newProducts->Length; i++) {
			if (newProducts[i]->quantity() == oldProducts[i]->quantity()) continue;

			if (newProducts[i]->quantity() == 0) {
				this->__orderService->unlinkProductToOrder(order->id(), newProducts[i]->id());
			}
			else if (oldProducts[i]->quantity() == 0) {
				this->__orderService->linkProductToOrder(order->id(), newProducts[i]->id(), newProducts[i]->quantity());
			}
			else {
				this->__orderService->updateProductToOrder(order->id(), newProducts[i]->id(), newProducts[i]->quantity());
			}
		}
	}

	this->__finishOrderEdition();
}

void App::button_OrdersDelete_Click(System::Object^ sender, System::EventArgs^ e) {
	if (this->__isOrderEditing || this->__isNewOrder) {
		if (MessageBox::Show("Editing a current order, do you want to abandon it?", "Cancel", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			this->__cancelOrderEdition();
		}
		return;
	}

	if (this->dataGridView_Orders->SelectedRows->Count > 0) {
		if (MessageBox::Show("Do you REALLY want to remove these orders?", "Deleting", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
			array<DataGridViewRow^>^ rows = gcnew array<DataGridViewRow^>(this->dataGridView_Orders->SelectedRows->Count);
			this->dataGridView_Orders->SelectedRows->CopyTo(rows, 0);

			for (int i = 0; i < rows->Length; i++) {
				if (rows[i]->IsNewRow) continue;

				int orderId = Convert::ToInt32(rows[i]->Cells[0]->Value->ToString());
				this->__orderService->removeOrder(orderId);

				this->dataGridView_Orders->Rows->Remove(rows[i]);
			}

			this->__orderService->cleanAddresses();
		}
	}
}

void App::dataGridView_Orders_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) {
	this->__isOrderEditing = true;
	this->button_OrdersDelete->Text = "Cancel";

	this->button_OrdersSubmit->Enabled = true;
	this->button_OrdersQuote->Enabled = true;

	if (this->__isNewOrder) this->__selectedOrderRowBeforeEdition = this->dataGridView_Orders->Rows[this->dataGridView_Orders->NewRowIndex];
	else if (!this->__selectedOrderRowBeforeEdition) this->__selectedOrderRowBeforeEdition = this->dataGridView_Orders->Rows[e->RowIndex];
}

void App::__showOrdersDetails() {
	if (!this->__selectedOrderRowBeforeEdition) return;

	int orderId = Convert::ToInt32(this->__selectedOrderRowBeforeEdition->Cells[0]->Value->ToString());
	int clientId = Convert::ToInt32(this->__selectedOrderRowBeforeEdition->Cells[8]->Value->ToString());

	// ========= Client =========
	Client^ client = this->__clientService->getClient(clientId);
	DataSet^ clientDataSet = Client::toDataSet(gcnew array<Client^>{ client }, "clients");

	this->dataGridView_OrdersClients->DataSource = clientDataSet;
	if (!this->dataGridView_OrdersClients->DataMember->Length) {
		this->dataGridView_OrdersClients->DataMember = "clients";
	}

	this->dataGridView_OrdersClients->Enabled = true;
	this->textBox_OrdersClientsSearch->Enabled = true;
	this->button_OrdersClientsUpdate->Enabled = true;

	// ========= Produits =========
	array<Product^>^ products = this->__productService->getOrderProducts(orderId);
	DataSet^ productsDataSet = Product::toDataSet(products, "products");

	this->dataGridView_OrdersStock->DataSource = productsDataSet;
	if (!this->dataGridView_OrdersStock->DataMember->Length) {
		this->dataGridView_OrdersStock->DataMember = "products";
	}

	this->dataGridView_OrdersStock->Enabled = true;
	this->textBox_OrdersStockSearch->Enabled = true;
	this->button_OrdersStockUpdate->Enabled = true;

	this->__orderProductsBeforeEdition = products;

	// ========== Addresses ==========
	Address^ billingAddress = this->__clientService->getAddress(Convert::ToInt32(this->__selectedOrderRowBeforeEdition->Cells[6]->Value->ToString()));
	Address^ deliveryAddress = this->__clientService->getAddress(Convert::ToInt32(this->__selectedOrderRowBeforeEdition->Cells[7]->Value->ToString()));

	DataSet^ addressesDataSet = gcnew DataSet("addresses");
	addressesDataSet->Tables->Add("addresses");
	addressesDataSet->Tables["addresses"]->Columns->Add("name");
	addressesDataSet->Tables["addresses"]->Columns->Add("id");
	addressesDataSet->Tables["addresses"]->Columns->Add("clientId");
	addressesDataSet->Tables["addresses"]->Columns->Add("number");
	addressesDataSet->Tables["addresses"]->Columns->Add("street");
	addressesDataSet->Tables["addresses"]->Columns->Add("city");
	addressesDataSet->Tables["addresses"]->Columns->Add("zip");
	addressesDataSet->Tables["addresses"]->Columns->Add("country");

	addressesDataSet->Tables["addresses"]->Rows->Add(gcnew array<String^> {
		"Billing",
			Convert::ToString(billingAddress->id()),
			Convert::ToString(billingAddress->clientId()),
			billingAddress->number(),
			billingAddress->street(),
			billingAddress->city(),
			Convert::ToString(billingAddress->zip()),
			billingAddress->country(),
	});
	addressesDataSet->Tables["addresses"]->Rows->Add(gcnew array<String^> {
		"Delivery",
			Convert::ToString(deliveryAddress->id()),
			Convert::ToString(deliveryAddress->clientId()),
			deliveryAddress->number(),
			deliveryAddress->street(),
			deliveryAddress->city(),
			Convert::ToString(deliveryAddress->zip()),
			deliveryAddress->country(),
	});

	this->dataGridView_OrdersAddresses->DataSource = addressesDataSet;
	this->dataGridView_OrdersAddresses->DataMember = "addresses";

	this->__orderAddressesBeforeEdition = gcnew array<Address^>{ billingAddress, deliveryAddress };

	this->dataGridView_OrdersAddresses->Enabled = true;

	// ========= Details =========
	this->__showOrderPriceDetails(client, products);
}

void App::__showNewOrdersDetails() {
	// ========= Clients =========
	array<Client^>^ clients = this->__clientService->getClients();
	DataSet^ clientDataSet = Client::toDataSet(clients, "clients");

	this->dataGridView_OrdersClients->DataSource = clientDataSet;
	if (!this->dataGridView_OrdersClients->DataMember->Length) {
		this->dataGridView_OrdersClients->DataMember = "clients";
	}

	this->dataGridView_OrdersClients->Enabled = true;
	this->textBox_OrdersClientsSearch->Enabled = true;
	this->button_OrdersClientsUpdate->Enabled = true;

	// ========= Produits =========
	array<Product^>^ products = this->__productService->getOrderProducts();
	DataSet^ productsDataSet = Product::toDataSet(products, "products");

	this->__orderProductsBeforeEdition = products;

	this->dataGridView_OrdersStock->DataSource = productsDataSet;
	if (!this->dataGridView_OrdersStock->DataMember->Length) {
		this->dataGridView_OrdersStock->DataMember = "products";
	}

	this->dataGridView_OrdersStock->Enabled = true;
	this->textBox_OrdersStockSearch->Enabled = true;
	this->button_OrdersStockUpdate->Enabled = true;

	// ========== Addresses ==========


	DataSet^ addressesDataSet = gcnew DataSet("addresses");
	addressesDataSet->Tables->Add("addresses");
	addressesDataSet->Tables["addresses"]->Columns->Add("name");
	addressesDataSet->Tables["addresses"]->Columns->Add("id");
	addressesDataSet->Tables["addresses"]->Columns->Add("clientId");
	addressesDataSet->Tables["addresses"]->Columns->Add("number");
	addressesDataSet->Tables["addresses"]->Columns->Add("street");
	addressesDataSet->Tables["addresses"]->Columns->Add("city");
	addressesDataSet->Tables["addresses"]->Columns->Add("zip");
	addressesDataSet->Tables["addresses"]->Columns->Add("country");

	addressesDataSet->Tables["addresses"]->Rows->Add(gcnew array<String^> {
		"Billing"
	});
	addressesDataSet->Tables["addresses"]->Rows->Add(gcnew array<String^> {
		"Delivery"
	});

	this->dataGridView_OrdersAddresses->DataSource = addressesDataSet;
	this->dataGridView_OrdersAddresses->DataMember = "addresses";

	this->__orderAddressesBeforeEdition = gcnew array<Address^>{ nullptr, nullptr };

	this->dataGridView_OrdersAddresses->Enabled = true;

	// ========= Details =========
	this->textBox_OrdersNumberOfProducts->Text = "0";
	this->textBox_OrdersPrice->Text = "0";
	this->textBox_OrdersPercentageDiscount->Text = "0";
	this->textBox_OrdersEuroDiscount->Text = "0";
	this->textBox_OrdersTax->Text = "0";
	this->textBox_OrdersTotal->Text = "0";

	this->__isOrderEditing = true;
}

void App::__showOrderPriceDetails(Client^ client, array<Product^>^ products) {
	double numberOfProducts = 0, price = 0, discoundPercent = 0, discountEuro = 0, tax = 0, total = 0;

	for (int i = 0; i < products->Length; i++) {
		Product^ product = products[i];

		numberOfProducts += product->quantity();
		price += product->cost() * product->quantity();
		tax += product->tax() / 100 * product->cost() * product->quantity();
	}

	String^ birthdateString = client->birthdate();
	DateTime^ birthdate = nullptr;
	Match^ match = Regex::Match(birthdateString, App::__dateRegex, RegexOptions::IgnoreCase);

	if (match->Success) {
		int day = Convert::ToInt32(match->Groups["day"]->Value);
		String^ monthString = match->Groups["month"]->Value;
		String^ yearString = Convert::ToString(match->Groups["year"]->Value);

		int month = 1;
		try {
			month = Convert::ToInt32(monthString);
		}
		catch (FormatException^) {
			for (int i = 0; i < App::__months->Length; i++) {
				if (Regex::IsMatch(monthString, App::__months[i], RegexOptions::IgnoreCase)) {
					month = i + 1;
					break;
				}
			}
		}

		int year = 2000;
		if (yearString != "") {
			if (yearString->Length == 2) {
				year = Convert::ToInt32("19" + year);
			}
			else {
				year = Convert::ToInt32(yearString);
			}
		}
		else {
			year = DateTime::Now.Year;
		}

		birthdate = gcnew DateTime(year, month, day);

		if (birthdate->Day == DateTime::Now.Day && birthdate->Month == DateTime::Now.Month) {
			discoundPercent = 10;
			discountEuro = price * discoundPercent / 100;

		}
	}

	tax -= discoundPercent / 100 * tax;
	total = price + tax - discountEuro;

	this->textBox_OrdersNumberOfProducts->Text = Convert::ToString(numberOfProducts);
	this->textBox_OrdersPrice->Text = Convert::ToString(price);
	this->textBox_OrdersPercentageDiscount->Text = Convert::ToString(discoundPercent);
	this->textBox_OrdersEuroDiscount->Text = Convert::ToString(discountEuro);
	this->textBox_OrdersTax->Text = Convert::ToString(tax);
	this->textBox_OrdersTotal->Text = Convert::ToString(total);

	this->textBox_OrdersNumberOfProducts->Enabled = true;
	this->textBox_OrdersPrice->Enabled = true;
	this->textBox_OrdersPercentageDiscount->Enabled = true;
	this->textBox_OrdersEuroDiscount->Enabled = true;
	this->textBox_OrdersTax->Enabled = true;
	this->textBox_OrdersTotal->Enabled = true;
}