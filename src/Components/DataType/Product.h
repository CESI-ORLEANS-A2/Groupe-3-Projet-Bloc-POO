#pragma once
using namespace System;
ref class Product {
private :
	int __id;
	String^ __name;
	String^ __description;
	float __cost;
	int __quantity;
public :
	Product();
	Product(Data::DataRow^);
	Product(Windows::Forms::DataGridViewRow^);
	int id(void);
	void name(String^);
	String^ name();
	void description(String^);
	String^ description();
	void cost(float);
	float cost();
	void quantity(int);
	int quantity(void);
	Data::DataRow^ toDataRow();
	Windows::Forms::DataGridViewRow^ toDataGridViewRow();
	static array<Product^>^ toArray(Data::DataTable^);
	static array<Product^>^ toArray(Windows::Forms::DataGridViewRowCollection^);
	static Data::DataTable^ toDataTable(array<Product^>^);
	static Windows::Forms::DataGridViewRowCollection^ toDataGridViewRowCollection(array<Product^>^);
};