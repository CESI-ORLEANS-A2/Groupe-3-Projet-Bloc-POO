#pragma once

#include "../../Utils.h"

using namespace System;
using namespace System::Data;
using namespace System::Windows::Forms;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace DataType {
			public ref class Client {
				static array<Client^>^ toArray(DataRowCollection^);
				static array<Client^>^ toArray(DataGridViewRowCollection^);
				static DataTable^ toDataTable(array<Client^>^);
				static DataGridView^ toDataGridView(array<Client^>^);

			public:
				Client();
				Client(DataRow^);
				Client(DataGridViewRow^);

				int id();
				String^ firstname();
				void firstname(String^);
				String^ lastname();
				void lastname(String^);
				String^ phone();
				void phone(String^);
				String^ email();
				void email(String^);
				DateTime^ birthdate();
				void birthdate(DateTime^);
				void birthdate(String^);
				void birthdate(long);
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
				DateTime^ __birthdate;
				String^ __logo;
				String^ __company;

			};
		}
	}
}