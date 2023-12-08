#include "../Request.h"
#include <string>
#pragma once
using namespace System;
using namespace System::Windows::Forms;

using namespace MySql::Data::MySqlClient;
ref class ProductRequestMapping {

public :
	static Request^ getProducts();
	static Request^ getProducts(int);
	static Request^ getProducts(int,int);
	static Request^ getProduct(int);
	static Request^ addProduct(String^, String^, float);
	static Request^ addProduct(String^, String^,float,int);
	static Request^ updateProduct(int,String^, String^, float,int);
	static Request^ deleteProduct(int);
};