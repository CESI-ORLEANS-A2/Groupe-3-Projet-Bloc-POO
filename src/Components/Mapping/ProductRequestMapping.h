#include "../Request.h"
#include <string>
#pragma once
using namespace System;
using namespace System::Windows::Forms;

using namespace MySql::Data::MySqlClient;
ref class ProductRequestMapping {

public :
	static Groupe3ProjetBlocPOO::Components::Request^ getProducts();
	static Groupe3ProjetBlocPOO::Components::Request^ getProducts(int);
	static Groupe3ProjetBlocPOO::Components::Request^ getOrderProducts(int);
	static Groupe3ProjetBlocPOO::Components::Request^ getOrderProducts(int,int);
	static Groupe3ProjetBlocPOO::Components::Request^ getProduct(int);
	static Groupe3ProjetBlocPOO::Components::Request^ addOrderProduct(int,int);
	static Groupe3ProjetBlocPOO::Components::Request^ addProduct(String^, float);
	static Groupe3ProjetBlocPOO::Components::Request^ addProduct(String^,float,int);
	static Groupe3ProjetBlocPOO::Components::Request^ updateProduct(int, String^, float,int);
	static Groupe3ProjetBlocPOO::Components::Request^ deleteProduct(int);
	static Groupe3ProjetBlocPOO::Components::Request^ deleteOrderProduct(int);
};