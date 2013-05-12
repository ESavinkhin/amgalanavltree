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
		int get ()  {
			if (m_top == nullptr) {
				return 0;
			} else {
				return getDepth(m_top);
			}			
		}
	}
	Tree(void) {		
		for (int i = 1;i <= 30;i++) {
			AddNode(i);
		}
	}
	void AddNode(int value)  {
		resetLast(m_top);		
		this->insert((int^) value, m_top);
	}

	void Remove(int value) {
		resetLast(m_top);
		remove((int^)value, m_top);
		value = 1;
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
		if (node == nullptr) {
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
	   k1->Parent = k2->Parent;
       k2->Left = k1->Right;
	   if (k2->Left != nullptr) {
		   k2->Left->Parent = k2;
	   }	     	   
       k1->Right = k2;
	   k2->Parent = k1;

	   if (k1->Parent!=nullptr && k1->Parent->Left == k2) {
		   k1->Parent->Left = k1;
	   }
	   if (k1->Parent!=nullptr && k1->Parent->Right == k2) {
		   k1->Parent->Right = k1;
	   }
       k2->Height = max(height( k2->Left ), height( k2->Right )) + 1;
       k1->Height = max( height( k1->Left ), k2->Height) + 1;
       return k1;
    }
	Node^ rotateWithRightChild( Node^ k1 )
	{
      Node^ k2 = k1->Right;
	  k2->Parent = k1->Parent;
      k1->Right = k2->Left;
	  if (k1->Right != nullptr) {
		  k1->Right->Parent = k1;
	  }	  
      k2->Left = k1;
	  k1->Parent = k2;
	   if (k2->Parent!=nullptr && k2->Parent->Left == k1) {
		   k2->Parent->Left = k2;
	   }
	   if (k2->Parent!=nullptr && k2->Parent->Right == k1) {
		   k2->Parent->Right = k2;
	   }

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
	 Node^ newNode(IComparable^ x, Node ^ k) {
		Node^ t = gcnew Node((int)x);
	    t->Parent = k;
		t->Last = true;
		return t;
	 }
	 void insert( IComparable^ x, Node^ t) {		
          if (m_top == nullptr) {
				 m_top = newNode(x,nullptr);
				 return;
	      } else if( x->CompareTo((int^)t->Value ) < 0 ) {
				if (t->Left == nullptr) {
					t->Left = newNode(x,t);
				} else {
					insert(x, t->Left);								
				}                         
          } else if( x->CompareTo( t->Value ) > 0)  {
				if (t->Right == nullptr) {
					t->Right = newNode(x,t);
				} else {
					insert( x, t->Right);				
				}                            
          } else if (t == nullptr) {				 
				 return;
	      }            
		  recursiveBalance(t);
	 }
	 void remove(IComparable^ x, Node^ t) {
         if (t == nullptr) {
			 return;
		 } else if (x->CompareTo((int^) t->Value) < 0 ) {
			remove(x,t->Left);
		 } else if (x->CompareTo((int^) t->Value) > 0 ) {
			remove(x,t->Right);
		 } else if (x->CompareTo((int^) t->Value) == 0 ) {
            removeFoundNode(t);
		 }
	 }
	 void removeFoundNode(Node^ t) {
		 Node^ r;
		 if (t->Right == nullptr || t->Left == nullptr) {
			 if (t->Parent == nullptr && t->Right == nullptr && t->Left == nullptr) {
				 m_top->Clear();
				 m_top = nullptr;
			 }
			 r = t;
		 } else {
			 r = successor(t);
			 t->Value = r->Value;
		 }
		 Node^ p;
		 if (r->Left != nullptr) {
			 p = r->Left;
		 } else {
			 p = r->Right;
		 }
		 if (p != nullptr) {
			 p->Parent = r->Parent;
		 }
		 if (r->Parent == nullptr) {
			 m_top = p;
		 } else {
           if(r->Parent->Left == r) {
               r->Parent->Left = p;
           } else {
               r->Parent->Right = p;
           }
	     }
		 if (r->Parent!= nullptr) {
			p = r->Parent;			 	
		    recursiveBalance(p);
		 }
		 r->Clear();		 
	 }
	 void recursiveBalance(Node^ t) {       			
         if( height( t->Left ) - height( t->Right ) == 2 ) {
             if( height(t->Left->Left) >= height(t->Left->Right) ) {
                t = rotateWithLeftChild( t );
  		     }
             else {
                t = doubleWithLeftChild( t );
			 }
		 } else if( height( t->Right ) - height( t->Left ) == 2 )  {
            if( height(t->Right->Right) >= height(t->Right->Left))  {
                  t = rotateWithRightChild( t );					
			 } else {
                  t = doubleWithRightChild( t );
			 }		  
         }
         t->Height = max( height( t->Left ), height( t->Right ) ) + 1;         
         if(t->Parent != nullptr) {			
            recursiveBalance(t->Parent);
         } else {
          m_top = t;   
         }
     }	 
	 Node^ successor(Node^ k) {
        if(k->Right!=nullptr) {
          Node^ r = k->Right;
           while(r->Left != nullptr) {
               r = r->Left;
           }
           return r;
        } else {//That is case ????
          Node^ p = k->Parent;
          while(p != nullptr && k == p->Right) {
            k = p;
            p = k->Parent;
          }
         return p;
       }
     }
};
}

