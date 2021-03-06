#pragma once
namespace test1 {
public ref class Node
{
public:
	property int Value {
		int get() {
			return m_value;
		}
		void set(int x) {
			m_value = x;
		}
	}
	property Node^ Left {
		Node^ get() {
			return m_left;
		}
		void set(Node^ node) 
		{
			m_left = node;
		}
	}
	property Node^ Right  {
		Node^ get() {
			return m_right;
		}
		void set(Node^ node)
		{
			m_right = node;
		}
	}
	property bool Last  {
		bool get() 
		{
			return m_last;
		}
		void set(bool last) 
		{
			m_last = last;
		}
	}
	property int Height {
		int get() {
			return m_height;
		}
		void set(int h) {
			m_height = h;
		}
	}
	
	Node(int value) {
	  m_value = value;
	}
	
	Node (int value, Node^ left, Node^ right) {
		m_value = value;
		m_left = left;
		m_right = right;		
	}
	void Clear() {		
		m_left = nullptr;
		m_right = nullptr;
	}
private:
	 bool m_last;
	 int m_height;
	 int m_value;
	 Node^ m_left;
	 Node^ m_right;	
};
}

