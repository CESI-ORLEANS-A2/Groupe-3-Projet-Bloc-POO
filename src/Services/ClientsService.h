#pragma once

#include "../Components/Database.h"
#include "../Components/DataType/Client.h"
#include "../Components/DataType/Address.h"

using namespace Groupe3ProjetBlocPOO::Components;
using namespace Groupe3ProjetBlocPOO::Components::DataType;

namespace Groupe3ProjetBlocPOO {
	namespace Services {
		public ref class ClientService {
		public:
			ClientService(Components::Database^ database);

			Components::DataType::Client^ createClient(Components::DataType::Client^ client);
			Components::DataType::Client^ createClient(String^ firstname, String^ lastname, String^ phone, String^ email, DateTime^ birthdate, String^ logo, String^ company);
			Components::DataType::Client^ updateClient(Components::DataType::Client^ client);
			Components::DataType::Client^ updateClient(int id, String^ firstname, String^ lastname, String^ phone, String^ email, DateTime^ birthdate, String^ logo, String^ company);
			Components::DataType::Client^ deleteClient(Components::DataType::Client^ client);
			Components::DataType::Client^ deleteClient(int id);
			Components::DataType::Client^ getClient(int id);
			Components::DataType::Client^ getClient(Components::DataType::Client^ client);
			array<Client^>^ getClients();
			array<Client^>^ getClients(int limit);
			array<Client^>^ getClients(int limit, int offset);

		private:
			Components::Database^ __database;
		};
	}
}