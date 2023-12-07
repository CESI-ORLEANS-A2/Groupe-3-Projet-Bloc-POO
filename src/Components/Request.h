#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		public ref class Request {
		public:
			Request(String^ sql);
			Request(MySqlCommand^ cmd);
			String^ sql();
			MySqlCommand^ mySqlCmd();

		private:
			String^ __sql;
			MySqlCommand^ __mySqlCmd;
		};
	}
}