#pragma once

#include "../Request.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;
using namespace Groupe3ProjetBlocPOO::Components;
ref class ProductRequestMapping {

public :
	static Request^ getProducts(int);
	static Request^ getProduct(int);
	static Request^ addProduct(String^, String^,float);
	static Request^ updateProduct(int,String^, String^, float);
	static Request^ deleteProduct(int);
};