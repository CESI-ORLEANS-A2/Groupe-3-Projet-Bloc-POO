#pragma once

#include "../../Utils.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace DataType {
			public ref class Order {
			public:
				static array<Order^>^ toArray(DataRowCollection^);
				static array<Order^>^ toArray(DataGridViewRowCollection^);
				static array<Order^>^ toArray(DataGridViewSelectedRowCollection^);
				static DataTable^ toDataTable(array<Order^>^);
				static DataSet^ toDataSet(array<Order^>^, String^ tableName);
				static DataGridView^ toDataGridView(array<Order^>^);

				static DataTable^ dataTableSchema();
				static DataRow^ newDataRow();

				Order();
				Order(int id);
				Order(DataRow^);
				Order(DataGridViewRow^);
				Order(int id, Order^ order);

				int id();
				String^ paymentDate();
				void paymentDate(String^);
				String^ creationDate();
				void creationDate(String^);
				String^ deliveryDate();
				void deliveryDate(String^);
				double amount();
				void amount(double);
				String^ paymentMethod();
				void paymentMethod(String^);
				int billingAddress();
				void billingAddress(int);
				int deliveryAddress();
				void deliveryAddress(int);
				int customer();
				void customer(int);

				DataRow^ toDataRow();
				DataGridViewRow^ toDataGridViewRow();

			private:
				int __id;
				String^ __paymentDate;
				String^ __creationDate;
				String^ __deliveryDate;
				double __amount;
				String^ __paymentMethod;
				int __billingAddress;
				int __deliveryAddress;
				int __customer;

				static DataTable^ __dataTableSchema = gcnew DataTable();
			};
		}
	}
}
