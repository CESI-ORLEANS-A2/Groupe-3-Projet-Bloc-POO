#pragma once

#include "../Request.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace MySql::Data::MySqlClient;
using namespace Groupe3ProjetBlocPOO::Components;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace Mapping {
			ref class ProductRequestMapping {
			public:
				static Request^ getProducts();
				static Request^ getProducts(int);
				static Request^ getProduct(int);
				static Request^ addProduct(String^, float, int);
				static Request^ addProduct(String^, float);
				static Request^ updateProduct(int, String^, float, int);
				static Request^ deleteProduct(int);
				static Request^ getOrderProducts(int);
				static Request^ getOrderProducts();
				static Request^ addOrderProduct(int, int);
				static Request^ deleteOrderProduct(int);
			};
		}
	}
}