#ifndef STACK_H
#define STACK_H
#include <utility>

class Stack
{

public:
    Stack();
    ~Stack();
    void push(double element);
    double pop();
    bool isEmpty() const;
    std::size_t size() const;

private:
    struct Element
    {
        Element();
        Element(double element);
        Element(const Element& other);
        Element(Element&& other);

        Element& operator=(Element other);
        friend void swap(Element& e1, Element& e2)
        {
            std::swap(e1.value, e2.value);
            std::swap(e1.previous, e2.previous);
        }

        Element* previous;

        double value;
    };
    Element bottom, *top;

    // debug method
    //Element callAssignment();
};

#endif
