#pragma once
using namespace System;
ref class Product {
private :
	int __id;
	String^ __name;
	float __cost;
	int __quantity;
	
public :
	Product();
	Product(int);
	Product(int, Product^);
	Product(Data::DataRow^);
	Product(Windows::Forms::DataGridViewRow^);
	int id(void);
	void name(String^);
	String^ name();
	void cost(float);
	float cost();
	void quantity(int);
	int quantity(void);
	
	static Data::DataTable^ dataTableSchema();
	static Data::DataRow^ newDataRow();
	static array<Product^>^ toArray(Data::DataRowCollection^);
	static array<Product^>^ toArray(Windows::Forms::DataGridViewRowCollection^);
	static Data::DataTable^ toDataTable(array<Product^>^);
	static Data::DataSet^ toDataSet(array<Product^>^,String^table);
	static Windows::Forms::DataGridView^ toDataGridView(array<Product^>^);
	static Data::DataTable^ __dataTableSchema = gcnew Data::DataTable();
	Data::DataRow^ toDataRow();
	Windows::Forms::DataGridViewRow^ toDataGridViewRow();
};