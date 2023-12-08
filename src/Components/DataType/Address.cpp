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
		if (collection[i]->IsNewRow) {
			addresses->Resize(addresses, addresses->Length - 1);
			continue;
		}
		addresses[i] = gcnew Address(collection[i]);
	}
	return addresses;
}
array<Groupe3ProjetBlocPOO::Components::DataType::Address^>^ Groupe3ProjetBlocPOO::Components::DataType::Address::toArray(DataGridViewSelectedRowCollection^ collection) {
	array<Address^>^ addresses = gcnew array<Address^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		if (collection[i]->IsNewRow) {
			continue;
			addresses->Resize(addresses, addresses->Length - 1);
		}
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
	dataGridView->Columns->Add("client_id", "client_id");
	dataGridView->Columns->Add("number", "number");
	dataGridView->Columns->Add("street", "street");
	dataGridView->Columns->Add("city", "city");
	dataGridView->Columns->Add("zip", "zip");
	dataGridView->Columns->Add("country", "country");

	for (int i = 0; i < addresses->Length; i++) {
		dataGridView->Rows->Add(addresses[i]->toDataGridViewRow());=======
	array<Address^>^ Addresss = gcnew array<Address^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		Addresss[i] = gcnew Address(collection[i]);
	}
	return Addresss;
}
array<Groupe3ProjetBlocPOO::Components::DataType::Address^>^ Groupe3ProjetBlocPOO::Components::DataType::Address::toArray(DataGridViewRowCollection^ collection) {
	array<Address^>^ Addresss = gcnew array<Address^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		Addresss[i] = gcnew Address(collection[i]);
	}
	return Addresss;
}
DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataTable(array<Address^>^ Addresss) {
	DataTable^ dataTable = gcnew DataTable();

	dataTable->Columns->Add("id", int::typeid);
	dataTable->Columns->Add("firstname", String::typeid);
	dataTable->Columns->Add("lastname", String::typeid);
	dataTable->Columns->Add("email", String::typeid);
	dataTable->Columns->Add("phone", String::typeid);
	dataTable->Columns->Add("birthdate", Int64::typeid);
	dataTable->Columns->Add("logo", String::typeid);
	dataTable->Columns->Add("company", String::typeid);

	for (int i = 0; i < Addresss->Length; i++) {
		dataTable->Rows->Add(Addresss[i]->toDataRow());
	}
	return dataTable;
}
DataGridView^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataGridView(array<Address^>^ Addresss) {
	DataGridView^ dataGridView = gcnew DataGridView();

	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("firstname", "firstname");
	dataGridView->Columns->Add("lastname", "lastname");
	dataGridView->Columns->Add("email", "email");
	dataGridView->Columns->Add("phone", "phone");
	dataGridView->Columns->Add("birthdate", "birthdate");
	dataGridView->Columns->Add("logo", "logo");
	dataGridView->Columns->Add("company", "company");

	for (int i = 0; i < Addresss->Length; i++) {
		dataGridView->Rows->Add(Addresss[i]->toDataGridViewRow());
	}
	return dataGridView;
}

DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Address::dataTableSchema() {
	if (Address::__dataTableSchema->Columns->Count == 0) {
		Address::__dataTableSchema->Columns->Add("id", int::typeid);
		Address::__dataTableSchema->Columns->Add("client_id", int::typeid);
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
	this->__clientId = Convert::ToInt32(row->ItemArray[1]);
	this->__number = Convert::ToString(row->ItemArray[2]);
	this->__street = Convert::ToString(row->ItemArray[3]);
	this->__city = Convert::ToString(row->ItemArray[4]);
	this->__zip = Convert::ToInt32(row->ItemArray[5]);
	this->__country = Convert::ToString(row->ItemArray[6]);
}
Groupe3ProjetBlocPOO::Components::DataType::Address::Address(DataGridViewRow^ row) {
	if (row->Cells[0]->Value->ToString() != "") {
		this->__id = Convert::ToInt32(row->Cells[0]->Value);
	}
	if (row->Cells[1]->Value->ToString() != "") {
		this->__clientId = Convert::ToInt32(row->Cells[1]->Value);
	}
	this->__number = Convert::ToString(row->Cells[2]->Value);
	this->__street = Convert::ToString(row->Cells[3]->Value);
	this->__city = Convert::ToString(row->Cells[4]->Value);
	this->__zip = Convert::ToInt32(row->Cells[5]->Value);
	this->__country = Convert::ToString(row->Cells[6]->Value);
}
Groupe3ProjetBlocPOO::Components::DataType::Address::Address(int id, Address^ address) {
	this->__id = id;
	this->__clientId = address->clientId();
	this->__number = address->number();
	this->__street = address->street();
	this->__city = address->city();
	this->__zip = address->zip();
	this->__country = address->country();
}
Groupe3ProjetBlocPOO::Components::DataType::Address::Address(int id, int client_id, String^ number, String^ street, String^ city, int zipCode, String^ country) {
	this->__id = id;
	this->__clientId = client_id;
	this->__number = number;
	this->__street = street;
	this->__city = city;
	this->__zip = zipCode;
	this->__country = country;
}

int Groupe3ProjetBlocPOO::Components::DataType::Address::id() {
	return this->__id;
}
void Groupe3ProjetBlocPOO::Components::DataType::Address::clientId(int id) {
	this->__clientId = id;
}
int Groupe3ProjetBlocPOO::Components::DataType::Address::clientId() {
	return this->__clientId;
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
	dataRow[1] = this->__clientId;
	dataRow[2] = this->__number;
	dataRow[3] = this->__street;
	dataRow[4] = this->__city;
	dataRow[5] = this->__zip;
	dataRow[6] = this->__country;

	return dataRow;
}
DataGridViewRow^ Groupe3ProjetBlocPOO::Components::DataType::Address::toDataGridViewRow() {
	DataGridView^ dataGridView = gcnew DataGridView();
	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("client_id", "client_id");
	dataGridView->Columns->Add("number", "number");
	dataGridView->Columns->Add("street", "street");
	dataGridView->Columns->Add("city", "city");
	dataGridView->Columns->Add("zip", "zip");
	dataGridView->Columns->Add("country", "country");

	DataGridViewRow^ dataGridViewRow = dataGridView->Rows[0];

	dataGridViewRow->Cells[0]->Value = this->__id;
	dataGridViewRow->Cells[1]->Value = this->__clientId;
	dataGridViewRow->Cells[2]->Value = this->__number;
	dataGridViewRow->Cells[3]->Value = this->__street;
	dataGridViewRow->Cells[4]->Value = this->__city;
	dataGridViewRow->Cells[5]->Value = this->__zip;
	dataGridViewRow->Cells[6]->Value = this->__country;

	return dataGridViewRow;
}
