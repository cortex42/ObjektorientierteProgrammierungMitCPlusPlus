#include "stack.hpp"
#include <cassert>
//#include <iostream>

//Stack::Element Stack::callAssignment(){
//    Element e;
//    return e;
//}


Stack::Stack() : top {&bottom}
{

    // call assignment operator
    //Element element1;
    //element1 = callAssignment();

    //std::cout << " --------------- " << std::endl;

    // call move constructor
    //Element element2;
    //Element element3 = std::move(element2);

    //Element element4(666.66);
    //Element element5(element4);


}

Stack::~Stack()
{
    while(!isEmpty())
    {
        pop();
    }
}

void Stack::push(double element)
{
    Element* newElement = new Element(element);
    newElement->previous = top;

    top = newElement;
}

double Stack::pop()
{
    assert(!isEmpty());

    double retVal = top->value;
    Element* previous = top->previous;

    delete top;

    top = previous;

    return retVal;
}

bool Stack::isEmpty() const
{
    return top == &bottom;
}

Stack::Element::Element() : Element {13.37} {
    // std::cout << "default constructor" << std::endl;
}

Stack::Element::Element(double element) : previous {nullptr}, value {element} {
    // std::cout << "constructor with one argument" << std::endl;
}

Stack::Element::Element(const Element& other) : previous {other.previous}, value {other.value} {
    // std::cout << "copy constructor" << std::endl;
}

Stack::Element::Element(Element&& other) : Element()
{
    swap(*this, other);

    //std::cout << "move constructor" << std::endl;
}

Stack::Element& Stack::Element::operator=(Element other)
{
    //std::cout << "assignment operator" << std::endl;

    swap(*this, other);
    return *this;
}

std::size_t Stack::size() const
{
    std::size_t counter = 0;

    Element* currentElement = top;

    while(currentElement != &bottom)
    {
        counter++;
        currentElement = currentElement->previous;
    }

    return counter;
}

