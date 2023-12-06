#include "./Order.h"

array<Groupe3ProjetBlocPOO::Components::DataType::Order^>^ Groupe3ProjetBlocPOO::Components::DataType::Order::toArray(DataRowCollection^ collection) {
	array<Order^>^ Orders = gcnew array<Order^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		Orders[i] = gcnew Order(collection[i]);
	}
	return Orders;
}
array<Groupe3ProjetBlocPOO::Components::DataType::Order^>^ Groupe3ProjetBlocPOO::Components::DataType::Order::toArray(DataGridViewRowCollection^ collection) {
	array<Order^>^ Orders = gcnew array<Order^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		Orders[i] = gcnew Order(collection[i]);
	}
	return Orders;
}
DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Order::toDataTable(array<Order^>^ Orders) {
	DataTable^ dataTable = gcnew DataTable();

	dataTable->Columns->Add("id", int::typeid);
	dataTable->Columns->Add("firstname", String::typeid);
	dataTable->Columns->Add("lastname", String::typeid);
	dataTable->Columns->Add("email", String::typeid);
	dataTable->Columns->Add("phone", String::typeid);
	dataTable->Columns->Add("birthdate", Int64::typeid);
	dataTable->Columns->Add("logo", String::typeid);
	dataTable->Columns->Add("company", String::typeid);

	for (int i = 0; i < Orders->Length; i++) {
		dataTable->Rows->Add(Orders[i]->toDataRow());
	}
	return dataTable;
}
DataGridView^ Groupe3ProjetBlocPOO::Components::DataType::Order::toDataGridView(array<Order^>^ Orders) {
	DataGridView^ dataGridView = gcnew DataGridView();

	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("firstname", "firstname");
	dataGridView->Columns->Add("lastname", "lastname");
	dataGridView->Columns->Add("email", "email");
	dataGridView->Columns->Add("phone", "phone");
	dataGridView->Columns->Add("birthdate", "birthdate");
	dataGridView->Columns->Add("logo", "logo");
	dataGridView->Columns->Add("company", "company");

	for (int i = 0; i < Orders->Length; i++) {
		dataGridView->Rows->Add(Orders[i]->toDataGridViewRow());
	}
	return dataGridView;
}

Groupe3ProjetBlocPOO::Components::DataType::Order::Order() {
	this->__id = -1;
}
Groupe3ProjetBlocPOO::Components::DataType::Order::Order(DataRow^ row) {
	this->__id = Convert::ToInt32(row->ItemArray[0]);
	this->__paymentDate = Utils::fromTimestamp(Convert::ToInt64(row->ItemArray[1]));
	this->__creationDate = Utils::fromTimestamp(Convert::ToInt64(row->ItemArray[2]));
	this->__deliveryDate = Utils::fromTimestamp(Convert::ToInt64(row->ItemArray[3]));
	this->__amount = Convert::ToDouble(row->ItemArray[4]);
	this->__paymentMethod = Convert::ToString(row->ItemArray[5]);
	this->__facturationAddress = Convert::ToInt32(row->ItemArray[6]);
	this->__deliveryAddress = Convert::ToInt32(row->ItemArray[7]);
	this->__customer = Convert::ToInt32(row->ItemArray[8]);

}
Groupe3ProjetBlocPOO::Components::DataType::Order::Order(DataGridViewRow^ row) {
	this->__id = Convert::ToInt32(row->Cells[0]->Value);
	this->__paymentDate = Utils::fromTimestamp(Convert::ToInt64(row->Cells[1]->Value));
	this->__creationDate = Utils::fromTimestamp(Convert::ToInt64(row->Cells[2]->Value));
	this->__deliveryDate = Utils::fromTimestamp(Convert::ToInt64(row->Cells[3]->Value));
	this->__amount = Convert::ToDouble(row->Cells[4]->Value);
	this->__paymentMethod = Convert::ToString(row->Cells[5]->Value);
	this->__facturationAddress = Convert::ToInt32(row->Cells[6]->Value);
	this->__deliveryAddress = Convert::ToInt32(row->Cells[7]->Value);
	this->__customer = Convert::ToInt32(row->Cells[8]->Value);
}

int Groupe3ProjetBlocPOO::Components::DataType::Order::id() {
	return this->__id;
}
DateTime^ Groupe3ProjetBlocPOO::Components::DataType::Order::paymentDate() {
	return this->__paymentDate;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::paymentDate(DateTime^ paymentDate) {
	this->__paymentDate = paymentDate;
}
//void Groupe3ProjetBlocPOO::Components::DataType::Order::paymentDate(String^ paymentDate) {
//	this->__paymentDate = gcnew DateTime(paymentDate);
//}
void Groupe3ProjetBlocPOO::Components::DataType::Order::paymentDate(Int64 paymentDate) {
	this->__paymentDate = Utils::fromTimestamp(paymentDate);
}
DateTime^ Groupe3ProjetBlocPOO::Components::DataType::Order::creationDate() {
	return this->__creationDate;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::creationDate(DateTime^ creationDate) {
	this->__creationDate = creationDate;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::creationDate(Int64 creationDate) {
	this->__creationDate = Utils::fromTimestamp(creationDate);
}
DateTime^ Groupe3ProjetBlocPOO::Components::DataType::Order::deliveryDate() {
	return this->__deliveryDate;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::deliveryDate(DateTime^ deliveryDate) {
	this->__deliveryDate = deliveryDate;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::deliveryDate(Int64 deliveryDate) {
	this->__deliveryDate = Utils::fromTimestamp(deliveryDate);
}
double Groupe3ProjetBlocPOO::Components::DataType::Order::amount() {
	return this->__amount;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::amount(double amount) {
	this->__amount = amount;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Order::paymentMethod() {
	return this->__paymentMethod;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::paymentMethod(String^ paymentMethod) {
	this->__paymentMethod = paymentMethod;
}
int Groupe3ProjetBlocPOO::Components::DataType::Order::facturationAddress() {
	return this->__facturationAddress;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::facturationAddress(int facturationAddress) {
	this->__facturationAddress = facturationAddress;
}
int Groupe3ProjetBlocPOO::Components::DataType::Order::deliveryAddress() {
	return this->__deliveryAddress;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::deliveryAddress(int deliveryAddress) {
	this->__deliveryAddress = deliveryAddress;
}
int Groupe3ProjetBlocPOO::Components::DataType::Order::customer() {
	return this->__customer;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::customer(int customer) {
	this->__customer = customer;
}

DataRow^ Groupe3ProjetBlocPOO::Components::DataType::Order::toDataRow() {
	DataTable^ dataTable = gcnew DataTable();
	dataTable->Columns->Add("id", int::typeid);
	dataTable->Columns->Add("paymentDate", Int64::typeid);
	dataTable->Columns->Add("creationDate", Int64::typeid);
	dataTable->Columns->Add("deliveryDate", Int64::typeid);
	dataTable->Columns->Add("amount", double::typeid);
	dataTable->Columns->Add("paymentMethod", String::typeid);
	dataTable->Columns->Add("facturationAddress", int::typeid);
	dataTable->Columns->Add("deliveryAddress", int::typeid);
	dataTable->Columns->Add("customer", int::typeid);

	DataRow^ dataRow = dataTable->NewRow();

	dataRow->ItemArray[0] = this->__id;
	dataRow->ItemArray[1] = Utils::toTimestamp(this->__paymentDate);
	dataRow->ItemArray[2] = Utils::toTimestamp(this->__creationDate);
	dataRow->ItemArray[3] = Utils::toTimestamp(this->__deliveryDate);
	dataRow->ItemArray[4] = this->__amount;
	dataRow->ItemArray[5] = this->__paymentMethod;
	dataRow->ItemArray[6] = this->__facturationAddress;
	dataRow->ItemArray[7] = this->__deliveryAddress;
	dataRow->ItemArray[8] = this->__customer;

	return dataRow;
}
DataGridViewRow^ Groupe3ProjetBlocPOO::Components::DataType::Order::toDataGridViewRow() {
	DataGridView^ dataGridView = gcnew DataGridView();
	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("paymentDate", "paymentDate");
	dataGridView->Columns->Add("creationDate", "creationDate");
	dataGridView->Columns->Add("deliveryDate", "deliveryDate");
	dataGridView->Columns->Add("amount", "amount");
	dataGridView->Columns->Add("paymentMethod", "paymentMethod");
	dataGridView->Columns->Add("facturationAddress", "facturationAddress");
	dataGridView->Columns->Add("deliveryAddress", "deliveryAddress");
	dataGridView->Columns->Add("customer", "customer");

	DataGridViewRow^ dataGridViewRow = dataGridView->Rows[0];

	dataGridViewRow->Cells[0]->Value = this->__id;
	dataGridViewRow->Cells[1]->Value = Utils::toTimestamp(this->__paymentDate);
	dataGridViewRow->Cells[2]->Value = Utils::toTimestamp(this->__creationDate);
	dataGridViewRow->Cells[3]->Value = Utils::toTimestamp(this->__deliveryDate);
	dataGridViewRow->Cells[4]->Value = this->__amount;
	dataGridViewRow->Cells[5]->Value = this->__paymentMethod;
	dataGridViewRow->Cells[6]->Value = this->__facturationAddress;
	dataGridViewRow->Cells[7]->Value = this->__deliveryAddress;
	dataGridViewRow->Cells[8]->Value = this->__customer;

	return dataGridViewRow;
}
