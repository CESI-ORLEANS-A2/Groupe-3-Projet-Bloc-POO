#pragma once

#include "../Request.h"

using namespace System;
using namespace MySql::Data::MySqlClient;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace Mapping {
			ref class AdressRequestMapping{
				public:
				static Request^ getAdresses();
				static Request^ getAdresses(int limit);
				static Request^ getAdresse(int id);
				static Request^ addAdresse(int number, String^ street, int zipCode, String^ city, String^ country);
				static Request^ updateAdresse(int id, int number, String^ street, int zipCode, String^ city, String^ country);
				static Request^ deleteAdresse(int id);
			};
		}
	}
}

