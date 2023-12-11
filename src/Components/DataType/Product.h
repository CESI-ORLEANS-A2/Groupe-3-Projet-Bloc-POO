#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace DataType {
			ref class Product {
			private:
				int __id;
				String^ __name;
				//String^ __description;
				float __cost;
				String^ __type;
				int __productType;
				float __tax;
				int __quantity;
				int __stock;

				static DataTable^ __dataTableSchema = gcnew DataTable("product");

			public:
				Product();
				Product(int id);
				Product(DataRow^);
				Product(DataGridViewRow^);
				Product(int id, Product^ product);
				Product(int id, String^ name/*, String^ description*/, float cost, String^ type, float tax, int quantity, int stock);

				int id(void);
				void name(String^);
				String^ name();
				//void description(String^);
				//String^ description();
				void cost(float);
				float cost();
				void type(String^);
				String^ type();
				void productType(int);
				int productType();
				void tax(float);
				float tax();
				void quantity(int);
				int quantity(void);
				void stock(int);
				int stock(void);

				DataRow^ toDataRow();

				static array<Product^>^ toArray(DataTable^);
				static array<Product^>^ toArray(DataRowCollection^);
				static array<Product^>^ toArray(DataGridViewRowCollection^);
				static DataTable^ toDataTable(array<Product^>^);
				static DataSet^ toDataSet(array<Product^>^, String^ tableName);

				static DataTable^ dataTableSchema();
				static DataRow^ newDataRow();
				Windows::Forms::DataGridView^ toDataGridView(array<Product^>^ product);
				Windows::Forms::DataGridViewRow^ toDataGridViewRow();
			};
		}
	}
}

using namespace Groupe3ProjetBlocPOO;
using namespace Groupe3ProjetBlocPOO::Components;
using namespace Groupe3ProjetBlocPOO::Components::DataType;

