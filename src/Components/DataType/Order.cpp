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

array<Groupe3ProjetBlocPOO::Components::DataType::Order^>^ Groupe3ProjetBlocPOO::Components::DataType::Order::toArray(DataGridViewSelectedRowCollection^ collection) {
	array<Order^>^ Orders = gcnew array<Order^>(collection->Count);
	for (int i = 0; i < collection->Count; i++) {
		Orders[i] = gcnew Order(collection[i]);
	}
	return Orders;
}

DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Order::toDataTable(array<Order^>^ Orders) {
	DataTable^ dataTable = Order::dataTableSchema();
	dataTable->Clear();

	for (int i = 0; i < Orders->Length; i++) {
		dataTable->Rows->Add(Orders[i]->toDataRow());
	}
	return dataTable->Copy();
}

DataSet^ Groupe3ProjetBlocPOO::Components::DataType::Order::toDataSet(array<Order^>^ orders, String^ tableName) {
	DataSet^ dataSet = gcnew DataSet();
	dataSet->Tables->Add(Order::toDataTable(orders));
	dataSet->Tables[0]->TableName = tableName;
	return dataSet;
}

DataGridView^ Groupe3ProjetBlocPOO::Components::DataType::Order::toDataGridView(array<Order^>^ Orders) {
	DataGridView^ dataGridView = gcnew DataGridView();

	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("paymentDate", "paymentDate");
	dataGridView->Columns->Add("creationDate", "creationDate");
	dataGridView->Columns->Add("deliveryDate", "deliveryDate");
	dataGridView->Columns->Add("amount", "amount");
	dataGridView->Columns->Add("paymentMethod", "paymentMethod");
	dataGridView->Columns->Add("billingAddress", "billingAddress");
	dataGridView->Columns->Add("deliveryAddress", "deliveryAddress");
	dataGridView->Columns->Add("customer", "customer");

	for (int i = 0; i < Orders->Length; i++) {
		dataGridView->Rows->Add(Orders[i]->toDataGridViewRow());
	}
	return dataGridView;
}
DataTable^ Groupe3ProjetBlocPOO::Components::DataType::Order::dataTableSchema() {
	if (Order::__dataTableSchema->Columns->Count == 0) {
		Order::__dataTableSchema->Columns->Add("id", int::typeid);
		Order::__dataTableSchema->Columns->Add("paymentDate", String::typeid);
		Order::__dataTableSchema->Columns->Add("creationDate", String::typeid);
		Order::__dataTableSchema->Columns->Add("deliveryDate", String::typeid);
		Order::__dataTableSchema->Columns->Add("amount", double::typeid);
		Order::__dataTableSchema->Columns->Add("paymentMethod", String::typeid);
		Order::__dataTableSchema->Columns->Add("billingAddress", int::typeid);
		Order::__dataTableSchema->Columns->Add("deliveryAddress", int::typeid);
		Order::__dataTableSchema->Columns->Add("customer", int::typeid);
	}

	return Order::__dataTableSchema;
}

DataRow^ Groupe3ProjetBlocPOO::Components::DataType::Order::newDataRow() {
	return Order::dataTableSchema()->NewRow();
}

Groupe3ProjetBlocPOO::Components::DataType::Order::Order() {
	this->__id = -1;
}

Groupe3ProjetBlocPOO::Components::DataType::Order::Order(int id) {
	this->__id = id;
}
Groupe3ProjetBlocPOO::Components::DataType::Order::Order(int id, Order^ order) {
	this->__id = id;
	this->__paymentDate = order->__paymentDate;
	this->__creationDate = order->__creationDate;
	this->__deliveryDate = order->__deliveryDate;
	this->__amount = order->__amount;
	this->__paymentMethod = order->__paymentMethod;
	this->__billingAddress = order->__billingAddress;
	this->__deliveryAddress = order->__deliveryAddress;
	this->__customer = order->__customer;
}
Groupe3ProjetBlocPOO::Components::DataType::Order::Order(DataRow^ row) {
	this->__id = Convert::ToInt32(row->ItemArray[0]);
	this->__paymentDate = Convert::ToString(row->ItemArray[1]);
	this->__creationDate = Convert::ToString(row->ItemArray[2]);
	this->__deliveryDate = Convert::ToString(row->ItemArray[3]);
	this->__amount = Convert::ToDouble(row->ItemArray[4]);
	this->__paymentMethod = Convert::ToString(row->ItemArray[5]);
	this->__billingAddress = Convert::ToInt32(row->ItemArray[6]);
	this->__deliveryAddress = Convert::ToInt32(row->ItemArray[7]);
	this->__customer = Convert::ToInt32(row->ItemArray[8]);

}
Groupe3ProjetBlocPOO::Components::DataType::Order::Order(DataGridViewRow^ row) {
	if (row->Cells[0]->Value && row->Cells[0]->Value->ToString() != "")
		this->__id = Convert::ToInt32(row->Cells[0]->Value);
	if (row->Cells[1]->Value && row->Cells[1]->Value->ToString() != "")
		this->__paymentDate = Convert::ToString(row->Cells[1]->Value);
	if (row->Cells[2]->Value && row->Cells[2]->Value->ToString() != "")
		this->__creationDate = Convert::ToString(row->Cells[2]->Value);
	if (row->Cells[3]->Value && row->Cells[3]->Value->ToString() != "")
		this->__deliveryDate = Convert::ToString(row->Cells[3]->Value);
	if (row->Cells[4]->Value && row->Cells[4]->Value->ToString() != "")
		this->__amount = Convert::ToDouble(row->Cells[4]->Value);
	if (row->Cells[5]->Value && row->Cells[5]->Value->ToString() != "")
		this->__paymentMethod = Convert::ToString(row->Cells[5]->Value);
	if (row->Cells[6]->Value && row->Cells[6]->Value->ToString() != "")
		this->__billingAddress = Convert::ToInt32(row->Cells[6]->Value);
	if (row->Cells[7]->Value && row->Cells[7]->Value->ToString() != "")
		this->__deliveryAddress = Convert::ToInt32(row->Cells[7]->Value);
	if (row->Cells[8]->Value && row->Cells[8]->Value->ToString() != "")
		this->__customer = Convert::ToInt32(row->Cells[8]->Value);
}

int Groupe3ProjetBlocPOO::Components::DataType::Order::id() {
	return this->__id;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Order::paymentDate() {
	return this->__paymentDate;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::paymentDate(String^ paymentDate) {
	this->__paymentDate = paymentDate;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Order::creationDate() {
	return this->__creationDate;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::creationDate(String^ creationDate) {
	this->__creationDate = creationDate;
}
String^ Groupe3ProjetBlocPOO::Components::DataType::Order::deliveryDate() {
	return this->__deliveryDate;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::deliveryDate(String^ deliveryDate) {
	this->__deliveryDate = deliveryDate;
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
int Groupe3ProjetBlocPOO::Components::DataType::Order::billingAddress() {
	return this->__billingAddress;
}
void Groupe3ProjetBlocPOO::Components::DataType::Order::billingAddress(int billingAddress) {
	this->__billingAddress = billingAddress;
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
	DataTable^ dataTable = Order::dataTableSchema();

	DataRow^ dataRow = dataTable->NewRow();

	dataRow[0] = this->__id;
	dataRow[1] = this->__paymentDate;
	dataRow[2] = this->__creationDate;
	dataRow[3] = this->__deliveryDate;
	dataRow[4] = this->__amount;
	dataRow[5] = this->__paymentMethod;
	dataRow[6] = this->__billingAddress;
	dataRow[7] = this->__deliveryAddress;
	dataRow[8] = this->__customer;

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
	dataGridView->Columns->Add("billingAddress", "billingAddress");
	dataGridView->Columns->Add("deliveryAddress", "deliveryAddress");
	dataGridView->Columns->Add("customer", "customer");

	DataGridViewRow^ dataGridViewRow = dataGridView->Rows[0];

	dataGridViewRow->Cells[0]->Value = this->__id;
	dataGridViewRow->Cells[1]->Value = this->__paymentDate;
	dataGridViewRow->Cells[2]->Value = this->__creationDate;
	dataGridViewRow->Cells[3]->Value = this->__deliveryDate;
	dataGridViewRow->Cells[4]->Value = this->__amount;
	dataGridViewRow->Cells[5]->Value = this->__paymentMethod;
	dataGridViewRow->Cells[6]->Value = this->__billingAddress;
	dataGridViewRow->Cells[7]->Value = this->__deliveryAddress;
	dataGridViewRow->Cells[8]->Value = this->__customer;

	return dataGridViewRow;
}
