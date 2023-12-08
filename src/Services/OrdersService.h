#pragma once

#include "../Components/Mapping/OrderRequestMapping.h"
#include "../Components/Database.h"
#include "../Components/DataType/Order.h"

using namespace System;
using namespace MySql::Data::MySqlClient;
using namespace Groupe3ProjetBlocPOO::Components::DataType;
using namespace Groupe3ProjetBlocPOO::Components::Mappings;

// OrderService.h

namespace Groupe3ProjetBlocPOO {
	namespace Services{
		ref class OrderService {
		public:
			OrderService();
			OrderService(Database^ db);
			Order^ getOrder(int id);
			array<Order^>^ getOrders();
			array<Order^>^ getOrders(int limit);
			Order^ addOrder(Order^ order);
			Order^ addOrder(DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, paymentType type);
			Order^ updateOrder(Order^ order);
			Order^ updateOrder(int id, DateTime^ paymentDay, DateTime^ emissionDate, DateTime^ deliveryDate, float cost, paymentType type);
			Order^ removeOrder(Order^ order);
			Order^ removeOrder(int id);
		private:
			Database^ __database;
		};
	}
}