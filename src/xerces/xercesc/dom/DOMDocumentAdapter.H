#include "xerces/xercesc/DOMDocument.hpp"


/**ADAPTER PATTERN - Adapter
 */
class W3CDocumentAdapter : public DOMDocument
{
    private:
    dom::Document* impl;

    public:
    virtual DOMDocument(dom::Document* d):impl(d) {};
    virtual DOMElement     *createElement(const XMLCh *tagName)
    {
        //assuming DOMElement exists elsewhere
        return new DOMElement(impl->createElement());
    }

    /**
     * Creates a <code>DOMText</code> node given the specified string.
     * @param data The data for the node.
     * @return The new <code>DOMText</code> object.
     * @since DOM Level 1
     */
    virtual DOMText         *createTextNode(const XMLCh *data)
    {
        //assuming DOMText exists elsewhere
        return new DOMText(impl->createText());
    }


    virtual DOMAttr     *createAttribute(const XMLCh *name)
    {
        //assuming DOMAttribute exists elsewhere
        return new DOMAttribute(impl->createAttribute());
    }

    /**
     * This is a convenience attribute that allows direct access to the child
     * node that is the root element of the document.
     * @since DOM Level 1
     */
    virtual DOMElement     *getDocumentElement() const
    {
        //assuming DOMElement exists elsewhere
        return new DOMElement(impl->getDocumentElement());
    }

}