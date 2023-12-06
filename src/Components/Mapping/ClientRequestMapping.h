#pragma once

#include "../Request.h"
#include "../../Utils.h"
#include "../DataType/Client.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace Mapping {
			class ClientRequestMapping {
				static Request^ getClients();
				static Request^ getClients(int limit);
				static Request^ getClients(int limit, int offset);
				static Request^ getClient(int id);
				static Request^ addClient(DataType::Client^ client);
				static Request^ addClient(String^ firstname, String^ lastname, String^ phone, String^ email, DateTime^ birthdate, String^ logo, String^ company);
				static Request^ updateClient(DataType::Client^ client);
				static Request^ updateClient(int id, String^ firstname, String^ lastname, String^ phone, String^ email, DateTime^ birthdate, String^ logo, String^ company);
				static Request^ deleteClient(int id);
				static Request^ emptyClient();
				static Request^ deleteClients(array<int>^ ids);
			};
		}
	}
}