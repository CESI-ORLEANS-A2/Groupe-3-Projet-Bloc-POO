#include "./Product.h"

Product::Product() {}

Product::Product(Data::DataRow^row) {
	this->__id = Convert::ToInt32(row->ItemArray[0]);
	//à continuer
}

Product::Product(Windows::Forms::DataGridViewRow^row) {
	this->__id = Convert::ToInt32(row->Cells[0]->Value->ToString());
	//à continuer
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

Data::DataRow^ Product::toDataRow() {}

Windows::Forms::DataGridViewRow^ Product::toDataGridViewRow() {}

array<Product^>^ Product::toArray(Data::DataTable^) {}

array<Product^>^ Product::toArray(Windows::Forms::DataGridViewRowCollection^) {}

Data::DataTable^ Product::toDataTable(array<Product^>^) {}

Windows::Forms::DataGridViewRowCollection^ Product::toDataGridViewRowCollection(array<Product^>^) {}

