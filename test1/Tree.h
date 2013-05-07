#pragma once
#include "Node.h"
namespace test1 {
		using namespace System;
public ref class Tree
{
public:
	property Node^ Top 
	{
		Node^ get() 
		{
			return m_top;
		}
	}
	property int Depth 
	{
		int get () 
		{
			if (m_top == nullptr) {
				return 0;
			} else {
				return getDepth(m_top);
			}			
		}
	}
	Tree(void)
	{		
		for (int i = 1;i < 100;i++) {
			AddNode(i);
		}
	}
	void AddNode(int value) 
	{
		resetLast(m_top);		
		m_top = this->insert((int^) value, m_top);
	}

	void Remove(int value) {

	}

	void Clear() {
		m_top = nullptr;
	}	
private:
	Node^ m_top;
	int getDepth(Node^ node) 
	{
		if (node == nullptr) 
		{
			return 0;
		}
		int level;
		int levelL = getDepth(node->Left);
		int levelR = getDepth(node->Right);
		if (levelL > levelR) {
			level = levelL;
		} else {
			level = levelR;
		}
		return level + 1;
	}
	void resetLast (Node^ node) 
	{
		if (node == nullptr) 
		{
			return;
		}
		node->Last = false;
		resetLast(node->Left);
		resetLast(node->Right);
	}
    int max( int lhs, int rhs )
    {
        return lhs > rhs ? lhs : rhs;
    }
	int height( Node^ node )
    {
        return node == nullptr ? -1 : node->Height;
    }
	Node^ rotateWithLeftChild( Node^ k2 )
    {
       Node^ k1 = k2->Left;
       k2->Left = k1->Right;
       k1->Right = k2;
       k2->Height = max(height( k2->Left ), height( k2->Right )) + 1;
       k1->Height = max( height( k1->Left ), k2->Height) + 1;
       return k1;
    }
	Node^ rotateWithRightChild( Node^ k1 )
	{
      Node^ k2 = k1->Right;
      k1->Right = k2->Left;
      k2->Left = k1;
      k1->Height = max( height( k1->Left ), height( k1->Right ) ) + 1;
      k2->Height = max( height( k2->Right ), k1->Height ) + 1;
      return k2;
     }
	 Node^ doubleWithLeftChild( Node^ k3 )
     {
        k3->Left = rotateWithRightChild( k3->Left );
        return rotateWithLeftChild( k3 );
     }
	 Node^ doubleWithRightChild( Node^ k1 )
     {
        k1->Right = rotateWithLeftChild( k1->Right );
        return rotateWithRightChild( k1 );
     }

	 Node^ insert( IComparable^ x, Node^ t )
     {		
          if( t == nullptr ) {
			  t = gcnew Node((int)x);
			  t->Last = true;
			} else if( x->CompareTo((int^)t->Value ) < 0 ) {
                t->Left = insert(x, t->Left );
                if( height( t->Left ) - height( t->Right ) == 2 )
                    if( x->CompareTo((int^)t->Left->Value) < 0 ) {
                        t = rotateWithLeftChild( t );
					}
                    else {
                        t = doubleWithLeftChild( t );
					}
            }
            else if( x->CompareTo( t->Value ) > 0)  {
                t->Right = insert( x, t->Right );
                if( height( t->Right ) - height( t->Left ) == 2 )  {
                    if( x->CompareTo( t->Right->Value ) > 0)  {
                        t = rotateWithRightChild( t );					
					} else {
                        t = doubleWithRightChild( t );
					}
				}
            }
            t->Height = max( height( t->Left ), height( t->Right ) ) + 1;
            return t;
	 }
};
}

