#pragma once

#include "./Utils.h"
#include "./Components/DataType/Address.h"
#include "./Components/DataType/Client.h"
#include "./Components/DataType/Order.h"
#include "./Components/DataType/Product.h"
#include "./Components/Database.h"
#include "./Services/OrdersService.h"
#include "./Services/ClientsService.h"
#include "./Services/ProductsService.h"
#include "./Components/Forms/MainForm.h"
#include "./Components/Forms/SettingsForm.h"
#include "./Components/Forms/StartForm.h"

using namespace System::Data;
using namespace Groupe3ProjetBlocPOO;
using namespace System::Configuration;
using namespace System::Collections::Generic;

using namespace Groupe3ProjetBlocPOO;
using namespace Groupe3ProjetBlocPOO::Utils;
using namespace Groupe3ProjetBlocPOO::Services;
using namespace Groupe3ProjetBlocPOO::Components;

namespace Groupe3ProjetBlocPOO {
	public ref class App : public MainForm {
	public:
		App(void);

	protected:
		void InitializeComponent(void);

		void tabControl_Tabs_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) override;

		void linkLabel_Help_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) override;
		void linkLabel_AuthorAbepan_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) override;
		void linkLabel_AuthorBeboudu32_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) override;
		void linkLabel_Author0xybo_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) override;
		void button_ClientsUpdate_Click(System::Object^ sender, System::EventArgs^ e) override;
		void dataGridView_Clients_RowHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) override;
		void button_ClientsAdd_Click(System::Object^ sender, System::EventArgs^ e) override;
		void button_ClientsDelete_Click(System::Object^ sender, System::EventArgs^ e) override;
		void dataGridView_Clients_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) override;
		void dataGridView_ClientsAddresses_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) override;
		void button_ClientsSubmit_Click(System::Object^ sender, System::EventArgs^ e) override;
		void dataGridView_Clients_SelectionChanged(System::Object^ sender, System::EventArgs^ e) override;

		void button_StockUpdate_Click(System::Object^ sender, System::EventArgs^ e) override;
		void button_StockAdd_Click(System::Object^ sender, System::EventArgs^ e) override;
		void button_StockDelete_Click(System::Object^ sender, System::EventArgs^ e) override;
		void button_StockSubmit_Click(System::Object^ sender, System::EventArgs^ e) override;
		void dataGridView_Stock_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) override;
		void dataGridView_Stock_SelectionChanged(System::Object^ sender, System::EventArgs^ e) override;

		void button_OrdersUpdate_Click(System::Object^ sender, System::EventArgs^ e) override;
		void dataGridView_Orders_RowHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) override;
		void button_OrdersClientsUpdate_Click(System::Object^ sender, System::EventArgs^ e) override;
		void button_OrdersStockUpdate_Click(System::Object^ sender, System::EventArgs^ e) override;
		void dataGridView_OrdersStock_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) override;
		void dataGridView_OrdersStock_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) override;
		void button_OrdersAdd_Click(System::Object^ sender, System::EventArgs^ e) override;
		void dataGridView_OrdersStock_CellEndEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) override;
		void dataGridView_OrdersClients_RowHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^ e) override;
		void dataGridView_OrdersAddresses_CellValueChanged(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) override;
		void dataGridView_OrdersAddresses_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) override;
		void button_OrdersSubmit_Click(System::Object^ sender, System::EventArgs^ e) override;
		void button_OrdersDelete_Click(System::Object^ sender, System::EventArgs^ e) override;
		void dataGridView_Orders_CellBeginEdit(System::Object^ sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^ e) override;

	private:
		Database^ __database;

		ClientService^ __clientService;
		ProductService^ __productService;
		OrderService^ __orderService;

		array<Client^>^ __selectedClients;
		DataGridViewRow^ __selectedClientRow;

		array<Order^>^ __selectedOrders;
		DataGridViewRow^ __selectedOrderRow;

		void __startClientEdition();
		void __cancelClientEdition();
		void __finishClientEdition();
		void __updateClients();
		void __updateClientsAddresses();

		bool __isClientEditing;

		void __startProductEdition();
		void __cancelProductEdition();
		void __finishProductEdition();
		void __updateProducts();

		bool __isProductEditing;

		void __updateOrders();
		void __cancelOrderEdition();
		void __finishOrderEdition();
		void __showOrdersDetails();
		void __showNewOrdersDetails();
		void __showOrderPriceDetails(Client^ client, array<Product^>^ products);

		bool __isOrderEditing;
		bool __isNewOrder;
		DataGridViewRow^ __selectedOrderRowBeforeEdition;
		DataGridViewRow^ __selectedOrderClientRow;
		array<Product^>^ __orderProductsBeforeEdition;
		array<Address^>^ __orderAddressesBeforeEdition;

		static Dictionary<String^, String^>^ __clientsPropertiesRegex = gcnew Dictionary<String^, String^>();
		static Dictionary<String^, String^>^ __addressesPropertiesRegex = gcnew Dictionary<String^, String^>();
		static Dictionary<String^, String^>^ __ordersPropertiesRegex = gcnew Dictionary<String^, String^>();
		static Dictionary<String^, String^>^ __productsPropertiesRegex = gcnew Dictionary<String^, String^>();
		static String^ __dateRegex = "^(?:(?:(?:(?<dayoftheweek>lundi|mardi|mercredi|jeudi|vendredi|samedi|dimanche) )?(?:(?<day>0[1-9]|[1-2][0-9]|3[0-1]) (?<month>janvier|mars|mai|juillet|ao[uû]t|octobre|d[ée]cembre)|(?<day>0[1-9]|[1-2][0-9]) (?<month>f[ée]vrier)|(?<day>0[1-9]|[1-2][0-9]|30) (?<month>avril|juin|septembre|novembre))(?: (?<year>[0-9]{4}))?)|(?:(?:(?<day>0?[1-9]|[1-2][0-9]|3[0-1])/(?<month>0?[13578]|1[02])|(?<day>0?[1-9]|[1-2][0-9])/(?<month>0?2)|(?<day>0?[1-9]|[1-2][0-9]|30)/(?<month>0?[469]|11))/(?<year>(?:19|20)?[0-9]{2})))$";
		static array<String^>^ __months = gcnew array<String^> { "janvier", "f[ée]vrier", "mars", "avril", "mai", "juin", "juillet", "ao[uû]t", "septembre", "octobre", "novembre", "d[ée]cembre" };
	};

}