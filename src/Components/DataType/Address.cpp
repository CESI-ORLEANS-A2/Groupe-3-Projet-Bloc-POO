#include "./Address.h"

array<Groupe3ProjetBlocPOO::Components::DataType::Address^>^ Groupe3ProjetBlocPOO::Components::DataType::Address::toArray(DataRowCollection^ collection) {
	array<Address^>^ addresses = gcnew array<Address^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		addresses[i] = gcnew Address(collection[i]);
	}
	return addresses;
}
array<Groupe3ProjetBlocPOO::Components::DataType::Address^>^ Groupe3ProjetBlocPOO::Components::DataType::Address::toArray(DataGridViewRowCollection^ collection) {
	array<Address^>^ addresses = gcnew array<Address^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		addresses[i] = gcnew Address(collection[i]);
	}
	return addresses;
}
array<Groupe3ProjetBlocPOO::Components::DataType::Address^>^ Groupe3ProjetBlocPOO::Components::DataType::Address::toArray(DataGridViewSelectedRowCollection^ collection) {
	array<Address^>^ addresses = gcnew array<Address^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		addresses[i] = gcnew Address(collection[i]);
	}
	return addresses;
}
DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataTable(array<Address^>^ addresses) {
	DataTable^ dataTable = Address::dataTableSchema();
	dataTable->Clear();

	for (int i = 0; i < addresses->Length; i++) {
		dataTable->Rows->Add(addresses[i]->toDataRow());
	}
	return dataTable->Copy();
}
DataSet^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataSet(array<Address^>^ addresses, String^ tableName) {
	DataSet^ dataSet = gcnew DataSet();
	dataSet->Tables->Add(Address::toDataTable(addresses));
	dataSet->Tables[0]->TableName = tableName;
	return dataSet;
}
DataGridView^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataGridView(array<Address^>^ addresses) {
	DataGridView^ dataGridView = gcnew DataGridView();

	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("number", "number");
	dataGridView->Columns->Add("street", "street");
	dataGridView->Columns->Add("city", "city");
	dataGridView->Columns->Add("zip", "zip");
	dataGridView->Columns->Add("country", "country");

	for (int i = 0; i < addresses->Length; i++) {
		dataGridView->Rows->Add(addresses[i]->toDataGridViewRow());
	}
	return dataGridView;
}

DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Address::dataTableSchema() {
	if (Address::__dataTableSchema->Columns->Count == 0) {
		Address::__dataTableSchema->Columns->Add("id", int::typeid);
		Address::__dataTableSchema->Columns->Add("number", String::typeid);
		Address::__dataTableSchema->Columns->Add("street", String::typeid);
		Address::__dataTableSchema->Columns->Add("city", String::typeid);
		Address::__dataTableSchema->Columns->Add("zip", int::typeid);
		Address::__dataTableSchema->Columns->Add("country", String::typeid);
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
	this->__zip = Convert::ToInt32(row->ItemArray[4]);
	this->__country = Convert::ToString(row->ItemArray[5]);
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
	DataRow^ dataRow = Address::newDataRow();

	dataRow[0] = this->__id;
	dataRow[1] = this->__number;
	dataRow[2] = this->__street;
	dataRow[3] = this->__city;
	dataRow[4] = this->__zip;
	dataRow[5] = this->__country;

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