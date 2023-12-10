#pragma once

#include "../Components/Mapping/OrderRequestMapping.h"
#include "../Components/Mapping/AddressRequestMapping.h"
#include "../Components/Database.h"
#include "../Components/DataType/Order.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace Groupe3ProjetBlocPOO::Components::DataType;
using namespace Groupe3ProjetBlocPOO::Components::Mapping;

namespace Groupe3ProjetBlocPOO {
	namespace Services {
		ref class OrderService {
		public:
			OrderService();
			OrderService(Database^ db);
			Order^ getOrder(int id);
			array<Order^>^ getOrders();
			array<Order^>^ getOrders(int limit);
			Order^ addOrder(Order^ order);
			Order^ addOrder(String^ paymentDay, String^ emissionDate, String^ deliveryDate, float cost, String^ type, int deliveryAddress, int billingAddress, int customer);
			Order^ updateOrder(Order^ order);
			Order^ updateOrder(int id, String^ paymentDay, String^ emissionDate, String^ deliveryDate, float cost, String^ type);
			Order^ removeOrder(Order^ order);
			Order^ removeOrder(int id);

			void linkProductToOrder(int orderId, int productId, int quantity);
			void unlinkProductToOrder(int orderId, int productId);
			void updateProductToOrder(int orderId, int productId, int quantity);

			void cleanAddresses();
		private:
			Database^ __database;
		};
	}
}