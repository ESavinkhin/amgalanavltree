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
		 k = m_tree->Depth;
		 this->traverse(m_tree->Top, f.Width / 2, 10, g, 1);
	  }
  private:
	 static int s_size_font = 10;
	 Tree^ m_tree;
	 int k;
	 void traverse(Node^ node, int x, int y, Graphics^ g, int level) {		
		if (node == nullptr) 
		{
			return;
		}
	 	if (node->Left != nullptr) 
		{			
			int nx = x - 100 * (k - 2) / (level * level);
			int ny = y + 40;
			g->DrawLine(gcnew Pen(Color::Green), x + 10, y + 10, nx + 10, ny + 10);
			traverse(node->Left, nx, ny , g, level + 1);			
		}
		if (node->Right != nullptr) 
		{	
			int nx = x + 100 * (k - 2) / (level * level);
			int ny = y + 40;
			g->DrawLine(gcnew Pen(Color::Green), x + 10, y + 10, nx + 10, ny + 10);
			traverse(node->Right, nx, ny , g, level + 1);						
		}
		Rectangle rect = Rectangle(x, y, 30, 30);
		SolidBrush^ redBrush = gcnew SolidBrush( node->Last ?Color::Green:Color::Red  );
		g->FillEllipse(redBrush, rect);		
		g->DrawString( Convert::ToString(node->Value), gcnew System::Drawing::Font( "Arial", s_size_font ), gcnew SolidBrush( Color::Blue ), x + 12 - Convert::ToString(node->Value)->Length * 2.5, y + 7 );
	}
 };
}

