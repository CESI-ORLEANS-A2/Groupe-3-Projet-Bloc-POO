#include "./Client.h"

array<Groupe3ProjetBlocPOO::Components::DataType::Client^>^ Groupe3ProjetBlocPOO::Components::DataType::Client::toArray(DataRowCollection^ collection) {
	array<Client^>^ clients = gcnew array<Client^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		clients[i] = gcnew Client(collection[i]);
	}
	return clients;
}
array<Groupe3ProjetBlocPOO::Components::DataType::Client^>^ Groupe3ProjetBlocPOO::Components::DataType::Client::toArray(DataGridViewRowCollection^ collection) {
	array<Client^>^ clients = gcnew array<Client^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		clients[i] = gcnew Client(collection[i]);
	}
	return clients;
}
array<Groupe3ProjetBlocPOO::Components::DataType::Client^>^ Groupe3ProjetBlocPOO::Components::DataType::Client::toArray(DataGridViewSelectedRowCollection^ collection) {
	array<Client^>^ clients = gcnew array<Client^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		clients[i] = gcnew Client(collection[i]);
	}
	return clients;
}
DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Client::toDataTable(array<Client^>^ clients) {
	DataTable^ dataTable = Client::dataTableSchema();
	dataTable->Clear();

	for (int i = 0; i < clients->Length; i++) {
		dataTable->Rows->Add(clients[i]->toDataRow());
	}
	return dataTable->Copy();
}
DataSet^ Groupe3ProjetBlocPOO::Components::DataType::Client::toDataSet(array<Client^>^ clients, String^ tableName) {
	DataSet^ dataSet = gcnew DataSet();
	dataSet->Tables->Add(Client::toDataTable(clients));
	dataSet->Tables[0]->TableName = tableName;
	return dataSet;
}
DataGridView^ Groupe3ProjetBlocPOO::Components::DataType::Client::toDataGridView(array<Client^>^ clients) {
	DataGridView^ dataGridView = gcnew DataGridView();

	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("firstname", "firstname");
	dataGridView->Columns->Add("lastname", "lastname");
	dataGridView->Columns->Add("email", "email");
	dataGridView->Columns->Add("phone", "phone");
	dataGridView->Columns->Add("birthdate", "birthdate");
	dataGridView->Columns->Add("logo", "logo");
	dataGridView->Columns->Add("company", "company");

	for (int i = 0; i < clients->Length; i++) {
		dataGridView->Rows->Add(clients[i]->toDataGridViewRow());
	}
	return dataGridView;
}

DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Client::dataTableSchema() {
	if (Client::__dataTableSchema->Columns->Count == 0) {
		Client::__dataTableSchema->Columns->Add("id", int::typeid);
		Client::__dataTableSchema->Columns->Add("firstname", String::typeid);
		Client::__dataTableSchema->Columns->Add("lastname", String::typeid);
		Client::__dataTableSchema->Columns->Add("phone", String::typeid);
		Client::__dataTableSchema->Columns->Add("email", String::typeid);
		Client::__dataTableSchema->Columns->Add("birthdate", String::typeid);
		Client::__dataTableSchema->Columns->Add("logo", String::typeid);
		Client::__dataTableSchema->Columns->Add("company", String::typeid);
	}

	return Client::__dataTableSchema;
}
DataRow^ Groupe3ProjetBlocPOO::Components::DataType::Client::newDataRow() {
	return Client::dataTableSchema()->NewRow();
}

Groupe3ProjetBlocPOO::Components::DataType::Client::Client() {
	this->__id = -1;
}
Groupe3ProjetBlocPOO::Components::DataType::Client::Client(int id) {
	this->__id = id;
}
Groupe3ProjetBlocPOO::Components::DataType::Client::Client(DataRow^ row) {
	this->__id = Convert::ToInt32(row->ItemArray[0]);
	this->__firstname = Convert::ToString(row->ItemArray[1]);
	this->__lastname = Convert::ToString(row->ItemArray[2]);
	this->__phone = Convert::ToString(row->ItemArray[4]);
	this->__email = Convert::ToString(row->ItemArray[3]);
	this->__birthdate = Convert::ToString(row->ItemArray[5]);
	this->__logo = Convert::ToString(row->ItemArray[6]);
	this->__company = Convert::ToString(row->ItemArray[7]);
}
Groupe3ProjetBlocPOO::Components::DataType::Client::Client(DataGridViewRow^ row) {
	if (!row->IsNewRow) {
		if (row->Cells[0]->Value->ToString()->Length)
			this->__id = Convert::ToInt32(row->Cells[0]->Value);
		this->__firstname = Convert::ToString(row->Cells[1]->Value);
		this->__lastname = Convert::ToString(row->Cells[2]->Value);
		this->__phone = Convert::ToString(row->Cells[3]->Value);
		this->__email = Convert::ToString(row->Cells[4]->Value);
		this->__birthdate = Convert::ToString(row->Cells[5]->Value);
		this->__logo = Convert::ToString(row->Cells[6]->Value);
		this->__company = Convert::ToString(row->Cells[7]->Value);
	}
}
Groupe3ProjetBlocPOO::Components::DataType::Client::Client(int id, Client^ client) {
	this->__id = id;
	this->__firstname = client->__firstname;
	this->__lastname = client->__lastname;
	this->__phone = client->__phone;
	this->__email = client->__email;
	this->__birthdate = client->__birthdate;
	this->__logo = client->__logo;
	this->__company = client->__company;
}

int Groupe3ProjetBlocPOO::Components::DataType::Client::id() {
	return this->__id;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Client::firstname() {
	return this->__firstname;
}
void Groupe3ProjetBlocPOO::Components::DataType::Client::firstname(String^ firstname) {
	this->__firstname = firstname;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Client::lastname() {
	return this->__lastname;
}
void Groupe3ProjetBlocPOO::Components::DataType::Client::lastname(String^ lastname) {
	this->__lastname = lastname;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Client::phone() {
	return this->__phone;
}
void Groupe3ProjetBlocPOO::Components::DataType::Client::phone(String^ phone) {
	this->__phone = phone;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Client::email() {
	return this->__email;
}
void Groupe3ProjetBlocPOO::Components::DataType::Client::email(String^ email) {
	this->__email = email;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Client::birthdate() {
	return this->__birthdate;
}
void Groupe3ProjetBlocPOO::Components::DataType::Client::birthdate(String^ birthdate) {
	this->__birthdate = Convert::ToString(birthdate);
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Client::logo() {
	return this->__logo;
}
void Groupe3ProjetBlocPOO::Components::DataType::Client::logo(String^ logo) {
	this->__logo = logo;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Client::company() {
	return this->__company;
}
void Groupe3ProjetBlocPOO::Components::DataType::Client::company(String^ company) {
	this->__company = company;
}

DataRow^ Groupe3ProjetBlocPOO::Components::DataType::Client::toDataRow() {
	DataRow^ dataRow = Client::newDataRow();

	dataRow[0] = this->__id;
	dataRow[1] = this->__firstname;
	dataRow[2] = this->__lastname;
	dataRow[3] = this->__email;
	dataRow[4] = this->__phone;
	dataRow[5] = this->__birthdate;
	dataRow[6] = this->__logo;
	dataRow[7] = this->__company;

	return dataRow;
}
DataGridViewRow^ Groupe3ProjetBlocPOO::Components::DataType::Client::toDataGridViewRow() {
	DataGridView^ dataGridView = gcnew DataGridView();
	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("firstname", "firstname");
	dataGridView->Columns->Add("lastname", "lastname");
	dataGridView->Columns->Add("email", "email");
	dataGridView->Columns->Add("phone", "phone");
	dataGridView->Columns->Add("birthdate", "birthdate");
	dataGridView->Columns->Add("logo", "logo");
	dataGridView->Columns->Add("company", "company");

	DataGridViewRow^ dataGridViewRow = dataGridView->Rows[0];

	dataGridViewRow->Cells[0]->Value = this->__id;
	dataGridViewRow->Cells[1]->Value = this->__firstname;
	dataGridViewRow->Cells[2]->Value = this->__lastname;
	dataGridViewRow->Cells[3]->Value = this->__email;
	dataGridViewRow->Cells[4]->Value = this->__phone;
	dataGridViewRow->Cells[5]->Value = this->__birthdate;
	dataGridViewRow->Cells[6]->Value = this->__logo;
	dataGridViewRow->Cells[7]->Value = this->__company;

	return dataGridViewRow;
}