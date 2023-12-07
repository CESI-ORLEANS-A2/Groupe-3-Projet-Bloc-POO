#pragma once

#include "../Components/Database.h"
#include "../Components/Mapping/ClientRequestMapping.h"
#include "../Components/Mapping/AddressRequestMapping.h"
#include "../Components/DataType/Client.h"
#include "../Components/DataType/Address.h"

using namespace Groupe3ProjetBlocPOO::Components;
using namespace Groupe3ProjetBlocPOO::Components::DataType;
using namespace Groupe3ProjetBlocPOO::Components::Mapping;

namespace Groupe3ProjetBlocPOO {
	namespace Services {
		public ref class ClientService {
		public:
			ClientService(Database^ database);

			Client^ createClient(Client^ client);
			Client^ createClient(String^ firstname, String^ lastname, String^ phone, String^ email, String^ birthdate, String^ logo, String^ company);
			Client^ updateClient(Client^ client);
			Client^ updateClient(int id, String^ firstname, String^ lastname, String^ phone, String^ email, String^ birthdate, String^ logo, String^ company);
			Client^ deleteClient(Client^ client);
			Client^ deleteClient(int id);
			Client^ getClient(int id);
			Client^ getClient(Client^ client);
			array<Client^>^ getClients();
			array<Client^>^ getClients(int limit);
			array<Client^>^ getClients(int limit, int offset);

			Address^ createAddress(Address^ address);
			Address^ createAddress(Client^ client, String^ number, String^ street, String^ city, int zipCode, String^ country);
			Address^ createAddress(int clientId, String^ number, String^ street, String^ city, int zipCode, String^ country);
			Address^ updateAddress(Address^ address);
			Address^ updateAddress(int id, String^ number, String^ street, String^ city, int zipCode, String^ country);
			Address^ deleteAddress(Address^ address);
			Address^ deleteAddress(int id);
			array<Address^>^ getAddresses(Client^ client);
			array<Address^>^ getAddresses(int clientId);
			array<Address^>^ updateAddresses(array<Address^>^ addresses);
			array<Address^>^ deleteAddresses(Client^ client);
			array<Address^>^ deleteAddresses(int clientId);
			array<Address^>^ deleteAddresses(array<Address^>^ addresses);

			int getCityId(String^ city);
			int getCountryId(String^ country);

		private:
			Database^ __database;
		};
	}
}