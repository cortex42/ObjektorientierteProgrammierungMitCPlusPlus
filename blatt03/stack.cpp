#include "stack.hpp"
#include <cassert>

Stack::Stack() : top{&bottom} {
}

Stack::~Stack() {
	while(!isEmpty()){
		pop();
	}
}

void Stack::push(double element) {
	Element* newElement = new Element(element);
	newElement->previous = top;

	top = newElement;
}

double Stack::pop() {
	assert(!isEmpty());
	
	double retVal = top->value;
	Element previous = *(top->previous);

	delete top;

	top = &previous;

	return retVal;
}

bool Stack::isEmpty() const {
	return top == &bottom;
}

Stack::Element::Element() : Element{13.37} {}

Stack::Element::Element(double element) : previous{nullptr}, value{element} {}

Stack::Element::Element(const Element& other) : previous{other.previous}, value{other.value} {}

Stack::Element::Element(Element&& other) : Element() {
	swap(*this, other);
} 

Stack::Element& Stack::Element::operator=(Element other) {
	swap(*this, other);
	return *this;
}


