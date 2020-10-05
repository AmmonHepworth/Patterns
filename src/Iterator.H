#ifndef DOM_ITERATOR_H
#define DOM_ITERATOR_H

#include <stack>
#include <utility>
#include "Node.H"
#include "NodeList.H"

//Iterator
class Iterator
{

    public:
    virtual dom::Node * begin() = 0;
    virtual bool isDone() = 0;
    virtual dom::Node * next() = 0;
    virtual dom::Node * currentItem() = 0;

    protected:
    Iterator();

};

//ConcreteIterator
class DomIterator
{
    public:
    DomIterator(dom::Node *);
    dom::Node * begin();
    bool isDone();
    dom::Node * next();
    dom::Node * currentItem();
    

    private:
    dom::Node * _root;
    dom::Node * curNode;
    std::stack<std::pair<dom::Node *, int> >treeStack;
    int curListIndex;
    bool done;

};

#endif