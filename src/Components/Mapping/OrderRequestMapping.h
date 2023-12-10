#pragma once

#include "../Request.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace Groupe3ProjetBlocPOO::Components;

namespace Groupe3ProjetBlocPOO {
	namespace Components {
		namespace Mapping {
			enum class paymentType { cash, check, transfer, creditCard };

			ref class OrderRequestMapping {
			public:
				static Request^ getOrders();
				static Request^ getOrders(int limit);
				static Request^ getOrder(int id);
				static Request^ addOrder(String^ paymentDay, String^ emissionDate, String^ deliveryDate, float cost, String^ type, int deliveryAddress, int billingAddress, int customer);
				static Request^ updateOrder(int id, String^ paymentDay, String^ emissionDate, String^ deliveryDate, float cost, String^ type);
				static Request^ deleteOrder(int id);

				static Request^ linkProductToOrder(int orderId, int productId, int quantity);
				static Request^ unlinkProductToOrder(int orderId, int productId);
				static Request^ updateProductToOrder(int orderId, int productId, int quantity);
			};
		}
	}
}