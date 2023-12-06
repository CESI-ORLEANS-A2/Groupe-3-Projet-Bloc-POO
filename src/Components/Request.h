#pragma once

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		ref class Request {
		public:
			Request(String^ sql);
			Request(MySqlCommand^ cmd);
			String^ sql();

		private:
			String^ __sql;
		};
	}
}
