#pragma once

#include "../Components/Database.h"
#include "../Components/DataType/Product.h"
#include "../Components/Mapping/ProductRequestMapping.h"
#include "../Components/Request.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace Groupe3ProjetBlocPOO {
	namespace Services {
		ref class ProductService {
		private:
			Groupe3ProjetBlocPOO::Components::Database^ __database;
		public:
			ProductService(Groupe3ProjetBlocPOO::Components::Database^);
			Product^ getProduct(int);
			Product^ getProduct(Product^);
			array<Product^>^ getProducts();
			array<Product^>^ getProducts(int);
			Product^ addProduct(Product^);
			Product^ addProduct(String^, float);
			Product^ addProduct(String^, float, int);
			Product^ addOrderProduct(int, int);
			array<Product^>^ getOrderProducts(int orderId);
			array<Product^>^ getOrderProducts();
			Product^ updateProduct(Product^);
			Product^ updateProduct(int, String^/*, String^*/, float, int);
			Product^ removeProduct(Product^);
			Product^ removeProduct(int);
			Product^ removeOrderProduct(int);
		};
	}
}

using namespace Groupe3ProjetBlocPOO::Components;
using namespace Groupe3ProjetBlocPOO::Components::DataType;
using namespace Groupe3ProjetBlocPOO::Components::Mapping;
using namespace Groupe3ProjetBlocPOO::Services;