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
				static Request^ addAddress(int number, String^ street, int zipCode, String^ city, String^ country);
				static Request^ updateAddress(int id, int number, String^ street, int zipCode, String^ city, String^ country);
				static Request^ deleteAddress(int id);
				static Request^ deleteAddresses(int client);
				static Request^ deleteAddresses();
			};
		}
	}
}