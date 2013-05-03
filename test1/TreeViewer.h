//#pragma once
#include "Tree.h"
namespace test1 {
using namespace System::Drawing;
using namespace System;
 public ref class TreeViewer
 {
  public:
	 TreeViewer(Tree^ tree)
	  {
		 this->m_tree = tree;
	  }

	  void Build(Graphics^ g) {
		 g->Clear(SystemColors::Control);
		 SizeF f = g->VisibleClipBounds.Size;
		 this->traverse(m_tree->Top, f.Width / 2, 10, g);
	  }
  private:
	 static int s_size_font = 10;
	 Tree^ m_tree;
	 void traverse(Node^ node, int x, int y, Graphics^ g) {
		if (node == nullptr) 
		{
			return;
		}
	 	if (node->Left != nullptr) 
		{
			g->DrawLine(gcnew Pen(Color::Green), x + 10, y + 10, x - 40 + 10, y + 40 + 10);
			traverse(node->Left,x-40, y + 40, g);
		}
		if (node->Right != nullptr) 
		{
			g->DrawLine(gcnew Pen(Color::Green), x + 10, y + 10, x + 40 + 10, y + 40 + 10);
			traverse(node->Right, x + 40, y + 40, g);
		}
		Rectangle rect = Rectangle(x,y,30,30);
		SolidBrush^ redBrush = gcnew SolidBrush( node->Last ?Color::Green:Color::Red  );
		g->FillEllipse(redBrush, rect);		
		g->DrawString( Convert::ToString(node->Value), gcnew System::Drawing::Font( "Arial", s_size_font ), gcnew SolidBrush( Color::Blue ), x + 12 - Convert::ToString(node->Value)->Length * 2.5, y + 7 );
		
	}
 };
}

