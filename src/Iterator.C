#include "Iterator.H"

DomIterator::DomIterator(dom::Node * root):_root(root), curListIndex(0), done(false) {}

dom::Node * DomIterator::begin()
{
    curNode = _root;
    return curNode;
}

bool DomIterator::isDone()
{
   return done; 
}

dom::Node * DomIterator::next()
{
    if ( curNode->getChildNodes()->size() > 0 && curListIndex < curNode->getChildNodes()->size())
    {
        //go to children
        treeStack.push({curNode, curListIndex+1});
        curNode = *std::next(curNode->getChildNodes()->begin(),curListIndex);
        curListIndex = 0;
        return curNode;
    }
    else
    {
        if (curNode == _root)
        {
            //back at root, cant have more than one child so must be done
            done = true;
            return curNode;
        }
        //pop off node and go to next child
        std::pair<dom::Node *, int> parentNodeIdxPair = treeStack.top();
        treeStack.pop();
        curNode = parentNodeIdxPair.first;
        curListIndex = parentNodeIdxPair.second;
        next();
    }
}

dom::Node * DomIterator::currentItem()
{
    return curNode;
}