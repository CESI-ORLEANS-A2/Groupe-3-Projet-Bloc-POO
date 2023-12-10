#include "./Product.h"


Product::Product() {}

Product::Product(int id) {
	this->__id = id;
}

Product::Product(int id, Product^ product)
{
	this->__id = id;
	this->__name = product->name();
	this->__cost = product->cost();
	this->__quantity = product->quantity();
	this->__productType = product->productType();
}

Product::Product(Data::DataRow^ row) {
	this->__id = Convert::ToInt32(row->ItemArray[0]);
	this->__name = row->ItemArray[1]->ToString();
	this->__cost = Convert::ToInt32(row->ItemArray[3]);
	this->__quantity = Convert::ToInt32(row->ItemArray[4]);
	this->__productType = Convert::ToInt32(row->ItemArray[5]);
}

Product::Product(Windows::Forms::DataGridViewRow^ row) {
	this->__id = -1;
	if (row->Cells[0]->Value->ToString()->Length != 0) {
		this->__id = Convert::ToInt32(row->Cells[0]->Value->ToString());
	}

	this->__name = row->Cells[1]->Value->ToString();
	this->__cost = Convert::ToInt32(row->Cells[3]->Value->ToString());
	this->__quantity = Convert::ToInt32(row->Cells[4]->Value->ToString());
	this->__productType = Convert::ToInt32(row->Cells[5]->Value->ToString());
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

void Product::cost(float cost) {
	__cost = cost;
}

float Product::cost() {
	return __cost;
}

void Product::quantity(int stock) {
	__quantity = stock;
}

int Product::quantity(void) {
	return __quantity;
}

void Product::productType(int productType) {
	__productType = productType;
}

int Product::productType(void) {
	return __productType;
}

Data::DataRow^ Product::newDataRow(){
	return Product::dataTableSchema()->NewRow();
}


Data::DataTable^ Product::dataTableSchema() {

	if (Product::__dataTableSchema->Columns->Count == 0) {
		Product::__dataTableSchema->Columns->Add("id", int::typeid);
		Product::__dataTableSchema->Columns->Add("name", String::typeid);
		Product::__dataTableSchema->Columns->Add("cost", int::typeid);
		Product::__dataTableSchema->Columns->Add("quantity", int::typeid);
		Product::__dataTableSchema->Columns->Add("productType", int::typeid);
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
	for (int i = 0; i < product->Length; i++) {
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
	table->Columns->Add("name", "name");
	table->Columns->Add("cost", "cost");
	table->Columns->Add("quantity", "quantity");
	table->Columns->Add("productType", "productType");

	for (int i = 0; i < product->Length; i++) {
		table->Rows->Add(product[i]->toDataGridViewRow());
	}
	return table;
}

Data::DataRow^ Product::toDataRow(){
	Data::DataRow^ dataRow = Product::newDataRow();

	dataRow[0] = this->__id;
	dataRow[1] = this->__name;
	dataRow[2] = this->__cost;
	dataRow[3] = this->__quantity;
	dataRow[4] = this->__productType;

	return dataRow;
}

Windows::Forms::DataGridViewRow^ Product::toDataGridViewRow(){
	Windows::Forms::DataGridView^ dataGridView = gcnew Windows::Forms::DataGridView();
	dataGridView->Columns->Add("id", "id");
	dataGridView->Columns->Add("name", "name");
	dataGridView->Columns->Add("cost", "cost");
	dataGridView->Columns->Add("quantity", "quantity");
	dataGridView->Columns->Add("productType", "productType");

	Windows::Forms::DataGridViewRow^ dataGridViewRow = dataGridView->Rows[0];

	dataGridViewRow->Cells[0]->Value = this->__id;
	dataGridViewRow->Cells[1]->Value = this->__name;
	dataGridViewRow->Cells[3]->Value = this->__cost;
	dataGridViewRow->Cells[4]->Value = this->__quantity;
	dataGridViewRow->Cells[5]->Value = this->__productType;

	return dataGridViewRow;
}


