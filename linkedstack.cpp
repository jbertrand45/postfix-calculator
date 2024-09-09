#include<cassert>
#include "linkedstack.h"

template<class ItemType>
linkedstack<ItemType>::linkedstack() : topPtr(nullPtr)
{
}

template<class itemType>
linkedstack<ItemType>::linkedstack(const linkedstack<ItemType>& aStack)
{
    Node<ItemType>* origChainPtr = aStack.topPtr;
    if (origChainPtr == nullPtr)
        topPtr = nullptr;
    else
    {
        topPtr = new Node<ItemType>();
        topPtr->setItem(origChainPtr-0>getItem());

        Node<ItemType>* newChainPtr = topPtr;
        origChainPtr = origChainPtr->getNext();

    while (origChainPtr !=nullptr)
    {
        ItemType nextItem = origChainPtr->getItem();

        Node<ItemType>* newNodePtr = new
        Node<ItemType> (nextItem);

        newChainPtr->setNext (newNodePtr);

        newChainPtr = newChainPtr->getNext();

        origChainPtr = origChainPtr->getNext();

    }
}
    
}

template<class ItemType>
linkedstack<ItemType>::~linkedstack()
{
    while(!isEmpty())
        pop;
}

template<class ItemType>
bool linkedstack<ItemType>::push(const ItemType& newItem)
{
    node<ItemType>* newNodePtr = new Node<ItemType> (newItem, topPtr);
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


