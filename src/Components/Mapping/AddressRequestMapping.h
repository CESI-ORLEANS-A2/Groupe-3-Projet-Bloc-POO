#pragma once

#include "../Request.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace Groupe3ProjetBlocPOO::Components;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace Mapping {
			ref class AddressRequestMapping {
			public:
				static Request^ getAddresses();
				static Request^ getAddresses(int client);
				static Request^ getAddressesWithLimit(int limit);
				static Request^ getAddress(int id);
				static Request^ addAddress(int client_id, String^ number, String^ street, String^ city, int zipCode, String^ country);
				static Request^ updateAddress(int id, String^ number, String^ street, String^ city, int zipCode, String^ country);
				static Request^ deleteAddress(int id);
				static Request^ deleteAddresses(int client);
				static Request^ deleteAddresses();
				static Request^ getCityId(String^ city);
				static Request^ getCountryId(String^ country);
				static Request^ getCityInCountry(String^ city, String^ country);

				static Request^ cleanAddresses();

				static Request^ getCities();
			};
		}
	}
}