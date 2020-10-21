#include "xerces/xercesc/DOMNode.hpp"

namespace XERCES
{

/**ADAPTER PATTERN - Adapter
 */
class W3CDOMNodeAdapter: public DOMNode
{
    public:
    W3CDOMNodeAdapter(dom::Node * n): impl(n) {};
    protected:
    dom::Node * impl;
    public:
    virtual const XMLCh *   getNodeName() const { return impl->getNodeName().c_str(); };

    virtual const XMLCh *       getNodeValue() const { return impl->getNodeValue().c_str(); };

    virtual NodeType            getNodeType() const
    {
        int t = (int)impl->getNodeType();
        if(t==0) return DOMNode::ATTRIBUTE_NODE;
        if(t==1) return DOMNode::DOCUMENT_NODE;
        if(t==2) return DOMNode::ELEMENT_NODE;
        if(t==3) return DOMNode::TEXT_NODE;
    };

    virtual DOMNode        *getParentNode() const
    {
        return new W3CDOMNodeAdapter(impl->getParentNode());
    };

    virtual DOMNodeList    *getChildNodes() const
    {
        //Assuming this would exist elsewhere or have a suitable conversion
        return new DOMNodeListAdapter(impl->getChildNodes());
    };

    virtual DOMNode        *getFirstChild() const
    {
        return new W3CDOMNodeAdapter(impl->getFirstChild();
    };

    virtual DOMNode        *getLastChild() const
    {
        return new W3CDOMNodeAdapter(impl->getLastChild());
    };

    virtual DOMNode        *getPreviousSibling() const
    {
        return new W3CDOMNodeAdapter(impl->getPreviousSibling());
    };

    virtual DOMNode        *getNextSibling() const
    {
        return new W3CDOMNodeAdapter(impl->getNextSibling());
    };


    virtual DOMDocument      *getOwnerDocument() const
    {
        return new W3CDOMDocumentAdapter(impl->getOwnerDocument());
    };


    virtual DOMNode       *insertBefore(DOMNode *newChild,
                                          DOMNode *refChild)
    {
        dom::Node* newC = newChild->getImpl(); //or some kind of valid conversion
        dom::Node* refC = refChild->getImpl(); //or some kind of valid conversion
        return new W3CDOMNodeAdapter(impl->insertBefore(newC,refC));
    };


    virtual DOMNode  *replaceChild(DOMNode *newChild,
                                     DOMNode *oldChild)
    {
        dom::Node* newC = newChild->getImpl(); //or some kind of valid conversion
        dom::Node* refC = refChild->getImpl(); //or some kind of valid conversion
        return new W3CDOMNodeAdapter(impl->getreplaceChild(newC,refC));
    };

    virtual DOMNode        *removeChild(DOMNode *oldChild) 
    {
        dom::Node* oldC = oldChild->getImpl(); //or some kind of valid conversion
        return new W3CDOMNodeAdapter(impl->removeChild(oldC));
    };

    virtual DOMNode        *appendChild(DOMNode *newChild)
    {
        dom::Node* newC = newChild->getImpl(); //or some kind of valid conversion
        return new W3CDOMNodeAdapter(impl->appendChild(newC));
    };

    virtual bool             hasChildNodes() const 
    {
        return impl->hasChildNodes();
    };

    virtual void              setNodeValue(const XMLCh  *nodeValue) 
    {
        impl->setNodeValue(nodeValue); //should implicitly convert char* to std::string
        return;
    };

    virtual const XMLCh *          getLocalName() const { return impl->getLocalName().c_str(); };

};

}; // namespace XERCES