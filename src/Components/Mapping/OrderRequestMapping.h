#pragma once

#include "../Request.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace Groupe3ProjetBlocPOO::Components;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace Mappings {
			enum class paymentType { cash, check, transfer, creditCard };

			ref class OrderRequestMapping {
			public:
				static Request^ getOrders();
				static Request^ getOrders(int limit);
				static Request^ getOrder(int id);
				static Request^ addOrder(DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, paymentType type);
				static Request^ updateOrder(int id, DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, paymentType type);
				static Request^ addOrder(DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, String^ type);
				static Request^ updateOrder(int id, DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, String^ type);
				static Request^ deleteOrder(int id);
			};
		}
	}
}