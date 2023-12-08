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
				static DataTable^ toDataTable(array<Order^>^);
				static DataSet^ toDataSet(array<Order^>^, String^ tableName);
				static DataGridView^ toDataGridView(array<Order^>^);

				static DataTable^ dataTableSchema();
				static DataRow^ newDataRow();

			public:
				Order();
				Order(int id);
				Order(int id, Order^ order);
				Order(DataRow^);
				Order(DataGridViewRow^);

				int id();
				DateTime^ paymentDate();
				void paymentDate(DateTime^);
				//void paymentDate(String^);
				void paymentDate(Int64);
				DateTime^ creationDate();
				void creationDate(DateTime^);
				//void creationDate(String^);
				void creationDate(Int64);
				DateTime^ deliveryDate();
				void deliveryDate(DateTime^);
				//void deliveryDate(String^);
				void deliveryDate(Int64);
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
				DateTime^ __paymentDate;
				DateTime^ __creationDate;
				DateTime^ __deliveryDate;
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
