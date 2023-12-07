#include "./Product.h"


Product::Product() {}

Product::Product(int id) {
	this->__id = id;
}

Product::Product(Data::DataRow^row) {
	this->__id = Convert::ToInt32(row->ItemArray[0]);
	this->__name = row->ItemArray[1]->ToString();
	this->__description = row->ItemArray[2]->ToString();
	this->__cost = Convert::ToInt32(row->ItemArray[3]);
	this->__quantity = Convert::ToInt32(row->ItemArray[4]);
}

Product::Product(Windows::Forms::DataGridViewRow^row) {
	this->__id = Convert::ToInt32(row->Cells[0]->Value->ToString());
	this->__name = row->Cells[0]->Value->ToString();
	this->__description = row->Cells[0]->Value->ToString();
	this->__cost = Convert::ToInt32(row->Cells[0]->Value->ToString());
	this->__quantity = Convert::ToInt32(row->Cells[0]->Value->ToString());
}

int Product::id(void) {
	return __id;
}

void Product::name(String^name) {
	__name = name;
}

String^ Product::name() {
	return __name;
}

void Product::description(String^description) {
	__description = description;
}

String^ Product::description() {
	return __description;
}

void Product::cost(float cost) {
	__cost = cost;
}

float Product::cost() {
	return __cost;
}

void Product::quantity(int quantity) {
	__quantity = quantity;
}

int Product::quantity(void) {
	return __quantity;
}

Data::DataRow^ Product::newDataRow(){
	return Product::dataTableSchema()->NewRow();
}


Data::DataTable^ Product::dataTableSchema() {

	if (Product::__dataTableSchema->Columns->Count == 0) {
		Product::__dataTableSchema->Columns->Add("id", int::typeid);
		Product::__dataTableSchema->Columns->Add("name", String::typeid);
		Product::__dataTableSchema->Columns->Add("description", String::typeid);
		Product::__dataTableSchema->Columns->Add("cost", int::typeid);
		Product::__dataTableSchema->Columns->Add("quantity", int::typeid);
	}
	return Product::__dataTableSchema;
}

array<Product^>^ Product::toArray(Data::DataRowCollection^rows) {
	array<Product^>^ product = gcnew array<Product^>(rows->Count);
	for (int i = 0; i < rows->Count; i++) {
		product[i] = gcnew Product(rows[i]);
	}
	return product;
}

array<Product^>^ Product::toArray(Windows::Forms::DataGridViewRowCollection^rows) {
	array<Product^>^ product = gcnew array<Product^>(rows->Count);
	for (int i = 0; i < rows->Count; i++) {
		product[i] = gcnew Product(rows[i]);
	}
	return product;
}

Data::DataTable^ Product::toDataTable(array<Product^>^product) {
	Data::DataTable^ table = Product::dataTableSchema();
	table->Clear();
	for (int i ; product->Length; i++) {
		table->Rows->Add(product[i]->toDataRow());
	}
	return table->Copy();
}

Data::DataSet^ Product::toDataSet(array<Product^>^product, String^ table)
{
	Data::DataSet^ dataSet = gcnew Data::DataSet();
	dataSet->Tables->Add(Product::toDataTable(product));
	dataSet->Tables[0]->TableName = table;
	return dataSet;
}


Windows::Forms::DataGridView^ Product::toDataGridView(array<Product^>^product) {
	Windows::Forms::DataGridView^ table = gcnew Windows::Forms::DataGridView;

	table->Columns->Add("id", "id");
	table->Columns->Add("firstname", "firstname");
	table->Columns->Add("lastname", "lastname");
	table->Columns->Add("email", "email");
	table->Columns->Add("phone", "phone");
	table->Columns->Add("birthdate", "birthdate");
	table->Columns->Add("logo", "logo");
	table->Columns->Add("company", "company");

	for (int i = 0; i < product->Length; i++) {
		table->Rows->Add(product[i]->toDataGridViewRow());
	}
	return table;
}

Data::DataRow^ Product::toDataRow(){
	Data::DataRow^ dataRow = Product::newDataRow();

	dataRow[0] = this->__id;
	dataRow[1] = this->__name;
	dataRow[2] = this->__description;
	dataRow[3] = this->__cost;
	dataRow[4] = this->__quantity;

	return dataRow;
}

Windows::Forms::DataGridViewRow^ Product::toDataGridViewRow(){
	Windows::Forms::DataGridView^ dataGridView = gcnew Windows::Forms::DataGridView();
	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("name", "name");
	dataGridView->Columns->Add("descritpion", "descritpion");
	dataGridView->Columns->Add("cost", "cost");
	dataGridView->Columns->Add("quantity", "quantity");

	Windows::Forms::DataGridViewRow^ dataGridViewRow = dataGridView->Rows[0];

	dataGridViewRow->Cells[0]->Value = this->__id;
	dataGridViewRow->Cells[1]->Value = this->__name;
	dataGridViewRow->Cells[2]->Value = this->__description;
	dataGridViewRow->Cells[3]->Value = this->__cost;
	dataGridViewRow->Cells[4]->Value = this->__quantity;

	return dataGridViewRow;
}


