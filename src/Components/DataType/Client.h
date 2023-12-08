#pragma once

#include "../../Utils.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace DataType {
			public ref class Client {
			public:
				static array<Client^>^ toArray(DataRowCollection^);
				static array<Client^>^ toArray(DataGridViewRowCollection^);
				static array<Client^>^ toArray(DataGridViewSelectedRowCollection^);
				static DataTable^ toDataTable(array<Client^>^);
				static DataSet^ toDataSet(array<Client^>^, String^ tableName);
				static DataGridView^ toDataGridView(array<Client^>^);

				static DataTable^ dataTableSchema();
				static DataRow^ newDataRow();

				Client();
				Client(int id);
				Client(DataRow^);
				Client(DataGridViewRow^);
				Client(int id, Client^ client);

				int id();
				String^ firstname();
				void firstname(String^);
				String^ lastname();
				void lastname(String^);
				String^ phone();
				void phone(String^);
				String^ email();
				void email(String^);
				String^ birthdate();
				void birthdate(String^);
				String^ logo();
				void logo(String^);
				String^ company();
				void company(String^);

				DataRow^ toDataRow();
				DataGridViewRow^ toDataGridViewRow();

			private:
				int __id;
				String^ __firstname;
				String^ __lastname;
				String^ __phone;
				String^ __email;
				String^ __birthdate;
				String^ __logo;
				String^ __company;

				static DataTable^ __dataTableSchema = gcnew DataTable();
			};
		}
	}
}
