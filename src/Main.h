#pragma once

#include "./Utils.h"
#include "./Components/Database.h"
#include "./Services/OrdersService.h"
#include "./Services/ClientsService.h"
#include "./Services/ProductsService.h"
#include "./Components/Forms/MainForm.h"

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

	private:
		Database^ __database;

		ClientService^ __clientService;
		//ProductService^ __productService;
		//OrderService^ __orderService;

		array<Client^>^ __selectedClients;
		DataGridViewRow^ __selectedClientRow;

		void __startClientEdition();
		void __cancelClientEdition();
		void __finishClientEdition();
		void __updateClients();
		void __updateClientsAddresses();

		bool __isClientEditing;

		static Dictionary<String^, String^>^ __clientsPropertiesRegex = gcnew Dictionary<String^, String^>();
		static Dictionary<String^, String^>^ __addressesPropertiesRegex = gcnew Dictionary<String^, String^>();
	};

}

