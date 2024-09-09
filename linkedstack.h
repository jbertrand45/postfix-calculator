#ifndef LINKED_STACK
#define LINKED_STACK

#include "StackInterface.h"
#include "Node.h"

template<class ItemType>
class linkedstack : public StackInterface<int> {
    private:
       Node<ItemType>* topPtr;

    public:
        linkedstack();
        linkedstack(const linkedstack<ItemType>& aStack);

        bool isEmpty() const;
        bool push(const ItemType& newEntry);
        bool pop();
        ItemType peek() const;

        ~linkedstack();

};
#endif