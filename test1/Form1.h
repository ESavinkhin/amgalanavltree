#pragma once
#include "TreeViewer.h"

namespace test1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;		
	using namespace System::Resources;
	using namespace System::Reflection;
	/// <summary>
	/// Ñâîäêà äëÿ Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			tree = gcnew Tree();
			InitializeComponent();	
			resourceManager = gcnew ResourceManager("test1.Messages",Assembly::GetExecutingAssembly());			
            hScrollBar1->Maximum = this->panelGraph->Width;
            hScrollBar1->Value = 0;
		}

	protected:
		/// <summary>
		/// Îñâîáîäèòü âñå èñïîëüçóåìûå ðåñóðñû.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		/// <summary>
		/// Òðåáóåòñÿ ïåðåìåííàÿ êîíñòðóêòîðà.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Button^  buttonAddNode;


	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Button^  buttonRemoveNode;
	private: System::Windows::Forms::MaskedTextBox^  TextBoxNodeValue;
	private: System::Windows::Forms::Panel^  panelGraph;
	private: System::Windows::Forms::Button^  button1;
  private: ResourceManager^ resourceManager;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: Tree^ tree; 
			 
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Îáÿçàòåëüíûé ìåòîä äëÿ ïîääåðæêè êîíñòðóêòîðà - íå èçìåíÿéòå
		/// ñîäåðæèìîå äàííîãî ìåòîäà ïðè ïîìîùè ðåäàêòîðà êîäà.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->buttonAddNode = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->buttonRemoveNode = (gcnew System::Windows::Forms::Button());
			this->TextBoxNodeValue = (gcnew System::Windows::Forms::MaskedTextBox());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->panelGraph = (gcnew System::Windows::Forms::Panel());
			this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
			this->panel1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->panelGraph->SuspendLayout();
			this->SuspendLayout();
			// 
			// buttonAddNode
			// 
			resources->ApplyResources(this->buttonAddNode, L"buttonAddNode");
			this->buttonAddNode->Name = L"buttonAddNode";
			this->buttonAddNode->UseVisualStyleBackColor = true;
			this->buttonAddNode->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->buttonRemoveNode);
			this->panel1->Controls->Add(this->TextBoxNodeValue);
			this->panel1->Controls->Add(this->buttonAddNode);
			resources->ApplyResources(this->panel1, L"panel1");
			this->panel1->Name = L"panel1";
			// 
			// button1
			// 
			resources->ApplyResources(this->button1, L"button1");
			this->button1->Name = L"button1";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// buttonRemoveNode
			// 
			resources->ApplyResources(this->buttonRemoveNode, L"buttonRemoveNode");
			this->buttonRemoveNode->Name = L"buttonRemoveNode";
			this->buttonRemoveNode->UseVisualStyleBackColor = true;
			// 
			// TextBoxNodeValue
			// 
			resources->ApplyResources(this->TextBoxNodeValue, L"TextBoxNodeValue");
			this->TextBoxNodeValue->Name = L"TextBoxNodeValue";
			// 
			// groupBox1
			// 
			resources->ApplyResources(this->groupBox1, L"groupBox1");
			this->groupBox1->Controls->Add(this->panelGraph);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->TabStop = false;
			// 
			// panelGraph
			// 
			resources->ApplyResources(this->panelGraph, L"panelGraph");
			this->panelGraph->Controls->Add(this->hScrollBar1);
			this->panelGraph->Name = L"panelGraph";
			this->panelGraph->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form1::panelGraph_Paint);
			// 
			// hScrollBar1
			// 
			resources->ApplyResources(this->hScrollBar1, L"hScrollBar1");
			this->hScrollBar1->Name = L"hScrollBar1";
			this->hScrollBar1->ValueChanged += gcnew System::EventHandler(this, &Form1::hScrollBar1_ValueChanged);
			// 
			// Form1
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Name = L"Form1";
			this->ShowInTaskbar = false;
			this->Resize += gcnew System::EventHandler(this, &Form1::Form1_Resize);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->panelGraph->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion	

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {			
			String^ value = this->TextBoxNodeValue->Text;
			try {
			tree->AddNode(Convert::ToInt16(value));
			} catch (FormatException^ e) {
               MessageBox::Show(resourceManager->GetString("invalidNumber"), resourceManager->GetString("invalidNumber"), MessageBoxButtons::OK, MessageBoxIcon::Exclamation, MessageBoxDefaultButton::Button1);
			}
			this->Refresh();
		 }
private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void panelGraph_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e) {
			  Graphics ^ g = e->Graphics;
			  BufferedGraphicsContext^ dc = gcnew BufferedGraphicsContext();
			  SizeF f = g->VisibleClipBounds.Size;
              BufferedGraphics^ backbuffer = dc->Allocate(g, Rectangle( 0, 0, f.Width,f.Height));  			 
			  (gcnew TreeViewer(tree))->Build(backbuffer->Graphics);			
			  backbuffer->Render(g);
		 }
private: System::Void Form1_Resize(System::Object^  sender, System::EventArgs^  e) {			
			 this->Refresh();
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
            tree->Clear();
			this->Refresh();
		 }
private: System::Void hScrollBar1_ValueChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->panelGraph->Left = -this->hScrollBar1->Value;
			 this->Refresh();
		 }
};
}

