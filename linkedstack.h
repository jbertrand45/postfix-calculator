#ifndef LINKED_STACK
#define LINKED_STACK

#include "StackInterface.h"
#include "Node.h"
#include <cassert>

template<class ItemType>
class linkedstack : public StackInterface<ItemType> {
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

template<class ItemType>
linkedstack<ItemType>::linkedstack() : topPtr(nullptr) {}

template<class ItemType>
linkedstack<ItemType>::linkedstack(const linkedstack<ItemType>& aStack)
{
    Node<ItemType>* origChainPtr = aStack.topPtr;
    if (origChainPtr == nullptr)
        topPtr = nullptr;
    else
    {
        topPtr = new Node<ItemType>();
        topPtr->setItem(origChainPtr->getItem());

        Node<ItemType>* newChainPtr = topPtr;
        origChainPtr = origChainPtr->getNext();

        while (origChainPtr != nullptr)
        {
            ItemType nextItem = origChainPtr->getItem();

            Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

            newChainPtr->setNext(newNodePtr);

            newChainPtr = newChainPtr->getNext();

            origChainPtr = origChainPtr->getNext();
        }
    }
}

template<class ItemType>
linkedstack<ItemType>::~linkedstack()
{
    while(!isEmpty())
        pop();
}

template<class ItemType>
bool linkedstack<ItemType>::push(const ItemType& newItem)
{
    Node<ItemType>* newNodePtr = new Node<ItemType>(newItem, topPtr);
    topPtr = newNodePtr;
    newNodePtr = nullptr;
    return true;
}

template<class ItemType>
bool linkedstack<ItemType>::pop()
{
    bool result = false;
    if(!isEmpty())
    {
        Node<ItemType>* nodeToDeletePtr = topPtr;
        topPtr = topPtr->getNext();

        nodeToDeletePtr->setNext(nullptr);
        delete nodeToDeletePtr;
        nodeToDeletePtr = nullptr;
        result = true;
    }
    return result;
}

template<class ItemType>
ItemType linkedstack<ItemType>::peek() const
{
    assert(!isEmpty());
    return topPtr->getItem();
}

template<class ItemType>
bool linkedstack<ItemType>::isEmpty() const
{
    return topPtr == nullptr;
}
#endif
