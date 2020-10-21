#if !defined(XERCESC_INCLUDE_GUARD_DOMDOCUMENT_HPP)
#define XERCESC_INCLUDE_GUARD_DOMDOCUMENT_HPP

#include <xercesc/dom/DOMNode.hpp>

namespace XERCES
{

typedef int XMLFileLoc;

class DOMNode;


/**ADAPTER PATTERN - Target
 */
class DOMDocument: public DOMNode
{


protected:
    // -----------------------------------------------------------------------
    //  Hidden constructors
    // -----------------------------------------------------------------------
    /** @name Hidden constructors */
    //@{
    DOMDocument() {};
    //@}

private:
    // -----------------------------------------------------------------------
    // Unimplemented constructors and operators
    // -----------------------------------------------------------------------
    /** @name Unimplemented constructors and operators */
    //@{
    DOMDocument(const DOMDocument &);

public:
    // -----------------------------------------------------------------------
    //  All constructors are hidden, just the destructor is available
    // -----------------------------------------------------------------------
    /** @name Destructor */
    //@{
    /**
     * Destructor
     *
     */
    virtual ~DOMDocument() {};
    virtual DOMElement     *createElement(const XMLCh *tagName) = 0;

    /**
     * Creates a <code>DOMText</code> node given the specified string.
     * @param data The data for the node.
     * @return The new <code>DOMText</code> object.
     * @since DOM Level 1
     */
    virtual DOMText         *createTextNode(const XMLCh *data) = 0;


    virtual DOMAttr     *createAttribute(const XMLCh *name) = 0;

    /**
     * This is a convenience attribute that allows direct access to the child
     * node that is the root element of the document.
     * @since DOM Level 1
     */
    virtual DOMElement     *getDocumentElement() const = 0;

};


}; // namespace XERCES

#endif
