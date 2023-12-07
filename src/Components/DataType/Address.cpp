#include "./Address.h"

array<Groupe3ProjetBlocPOO::Components::DataType::Address^>^ Groupe3ProjetBlocPOO::Components::DataType::Address::toArray(DataRowCollection^ collection) {
	array<Address^>^ clients = gcnew array<Address^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		clients[i] = gcnew Address(collection[i]);
	}
	return clients;
}
array<Groupe3ProjetBlocPOO::Components::DataType::Address^>^ Groupe3ProjetBlocPOO::Components::DataType::Address::toArray(DataGridViewRowCollection^ collection) {
	array<Address^>^ clients = gcnew array<Address^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		clients[i] = gcnew Address(collection[i]);
	}
	return clients;
}
array<Groupe3ProjetBlocPOO::Components::DataType::Address^>^ Groupe3ProjetBlocPOO::Components::DataType::Address::toArray(DataGridViewSelectedRowCollection^ collection) {
	array<Address^>^ clients = gcnew array<Address^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		clients[i] = gcnew Address(collection[i]);
	}
	return clients;
}
DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataTable(array<Address^>^ clients) {
	DataTable^ dataTable = Address::dataTableSchema();
	dataTable->Clear();

	for (int i = 0; i < clients->Length; i++) {
		dataTable->Rows->Add(clients[i]->toDataRow());
	}
	return dataTable->Copy();
}
DataSet^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataSet(array<Address^>^ clients, String^ tableName) {
	DataSet^ dataSet = gcnew DataSet();
	dataSet->Tables->Add(Address::toDataTable(clients));
	dataSet->Tables[0]->TableName = tableName;
	return dataSet;
}
DataGridView^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataGridView(array<Address^>^ clients) {
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

DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Address::dataTableSchema() {
	if (Address::__dataTableSchema->Columns->Count == 0) {
		Address::__dataTableSchema->Columns->Add("id", int::typeid);
		Address::__dataTableSchema->Columns->Add("firstname", String::typeid);
		Address::__dataTableSchema->Columns->Add("lastname", String::typeid);
		Address::__dataTableSchema->Columns->Add("email", String::typeid);
		Address::__dataTableSchema->Columns->Add("phone", String::typeid);
		Address::__dataTableSchema->Columns->Add("birthdate", String::typeid);
		Address::__dataTableSchema->Columns->Add("logo", String::typeid);
		Address::__dataTableSchema->Columns->Add("company", String::typeid);
	}

	return Address::__dataTableSchema;
}
DataRow^ Groupe3ProjetBlocPOO::Components::DataType::Address::newDataRow() {
	return Address::dataTableSchema()->NewRow();
}

Groupe3ProjetBlocPOO::Components::DataType::Address::Address() {
	this->__id = -1;
}
Groupe3ProjetBlocPOO::Components::DataType::Address::Address(DataRow^ row) {
	this->__id = Convert::ToInt32(row->ItemArray[0]);
	this->__number = Convert::ToString(row->ItemArray[1]);
	this->__street = Convert::ToString(row->ItemArray[2]);
	this->__city = Convert::ToString(row->ItemArray[3]);
	this->__zip = Convert::ToInt32(row->ItemArray[5]);
	this->__country = Convert::ToString(row->ItemArray[4]);
}
Groupe3ProjetBlocPOO::Components::DataType::Address::Address(DataGridViewRow^ row) {
	this->__id = Convert::ToInt32(row->Cells[0]->Value);
	this->__number = Convert::ToString(row->Cells[1]->Value);
	this->__street = Convert::ToString(row->Cells[2]->Value);
	this->__city = Convert::ToString(row->Cells[3]->Value);
	this->__zip = Convert::ToInt32(row->Cells[5]->Value);
	this->__country = Convert::ToString(row->Cells[4]->Value);
}

int Groupe3ProjetBlocPOO::Components::DataType::Address::id() {
	return this->__id;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Address::number() {
	return this->__number;
}
void Groupe3ProjetBlocPOO::Components::DataType::Address::number(String^ number) {
	this->__number = number;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Address::street() {
	return this->__street;
}
void Groupe3ProjetBlocPOO::Components::DataType::Address::street(String^ street) {
	this->__street = street;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Address::city() {
	return this->__city;
}
void Groupe3ProjetBlocPOO::Components::DataType::Address::city(String^ city) {
	this->__city = city;
}
int Groupe3ProjetBlocPOO::Components::DataType::Address::zip() {
	return this->__zip;
}
void Groupe3ProjetBlocPOO::Components::DataType::Address::zip(int zip) {
	this->__zip = zip;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Address::country() {
	return this->__country;
}
void Groupe3ProjetBlocPOO::Components::DataType::Address::country(String^ country) {
	this->__country = country;
}

DataRow^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataRow() {
	DataTable^ dataTable = gcnew DataTable();
	dataTable->Columns->Add("id", int::typeid);
	dataTable->Columns->Add("number", String::typeid);
	dataTable->Columns->Add("street", String::typeid);
	dataTable->Columns->Add("city", String::typeid);
	dataTable->Columns->Add("zip", int::typeid);
	dataTable->Columns->Add("country", String::typeid);

	DataRow^ dataRow = dataTable->NewRow();

	dataRow->ItemArray[0] = this->__id;
	dataRow->ItemArray[1] = this->__number;
	dataRow->ItemArray[2] = this->__street;
	dataRow->ItemArray[3] = this->__city;
	dataRow->ItemArray[4] = this->__zip;
	dataRow->ItemArray[5] = this->__country;

	return dataRow;
}
DataGridViewRow^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataGridViewRow() {
	DataGridView^ dataGridView = gcnew DataGridView();
	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("number", "number");
	dataGridView->Columns->Add("street", "street");
	dataGridView->Columns->Add("city", "city");
	dataGridView->Columns->Add("zip", "zip");
	dataGridView->Columns->Add("country", "country");

	DataGridViewRow^ dataGridViewRow = dataGridView->Rows[0];

	dataGridViewRow->Cells[0]->Value = this->__id;
	dataGridViewRow->Cells[1]->Value = this->__number;
	dataGridViewRow->Cells[2]->Value = this->__street;
	dataGridViewRow->Cells[3]->Value = this->__city;
	dataGridViewRow->Cells[4]->Value = this->__zip;
	dataGridViewRow->Cells[5]->Value = this->__country;

	return dataGridViewRow;
}