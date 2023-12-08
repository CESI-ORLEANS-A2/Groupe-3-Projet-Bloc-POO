#pragma once

#include "../../Utils.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace DataType {
			public ref class Address {
			public:
				static array<Address^>^ toArray(DataRowCollection^);
				static array<Address^>^ toArray(DataGridViewRowCollection^);
				static array<Address^>^ toArray(DataGridViewSelectedRowCollection^);
				static DataTable^ toDataTable(array<Address^>^);
				static DataSet^ toDataSet(array<Address^>^, String^ tableName);
				static DataGridView^ toDataGridView(array<Address^>^);

				static DataTable^ dataTableSchema();
				static DataRow^ newDataRow();

				Address();
				Address(DataRow^);
				Address(DataGridViewRow^);
				Address(int id, Address^ address);
				Address(int id, int client_id, String^ number, String^ street, String^ city, int zipCode, String^ country);

				int id();
				void clientId(int);
				int clientId();
				void number(String^);
				String^ number();
				void street(String^);
				String^ street();
				void city(String^);
				String^ city();
				void zip(int);
				int zip();
				void country(String^);
				String^ country();

				DataRow^ toDataRow();
				DataGridViewRow^ toDataGridViewRow();

			private:
				int __id;
				int __clientId;
				String^ __number;
				String^ __street;
				String^ __city;
				int __zip;
				String^ __country;

				static DataTable^ __dataTableSchema = gcnew DataTable();
			};
		}
	}
}
