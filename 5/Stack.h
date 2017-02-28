#include <exception>

template <class T>
class Stack {

	struct Node {
		T value;
		Node* next;

		Node(){
			this->next = nullptr;
		}

		Node(const T& value, Node* next = nullptr){
			this->value = value;
			this->next = next;
		}

		~Node(){
			delete next;
		}
	};

	Node* top;

public:
	Stack() : top(nullptr) {}

	~Stack(){
		delete top;
	}

	bool isEmpty(){
		return !top;
	}

	void push(const T& value){
		if (!top){
			top = new Node();
			try {
				top->value = value;
			}
			catch (std::exception ex){
				try {
					delete top;
				}
				catch (std::exception delEx){
					top = nullptr;
				}
				top = nullptr;
				throw;
			}
		}
		else {
			Node* newTop = new Node();
			try {
				newTop->value = value;
			}
			catch(std::exception ex){
				delete newTop;
				throw;
			}
			newTop->next = top;
			top = newTop;
		}
	}

	void pop(){
		if (!top) throw std::exception();
		Node* newTop = top->next;
		top->next = nullptr;
		try {
			delete top;
		}
		catch (std::exception ex){
			top = newTop;
			throw;
		}
		top = newTop;
	}

	T& getTop(){
		if (!top) throw std::exception();
		return top->value;
	}
};