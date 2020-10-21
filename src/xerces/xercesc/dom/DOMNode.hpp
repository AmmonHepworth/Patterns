
#if !defined(XERCESC_INCLUDE_GUARD_DOMNODE_HPP)
#define XERCESC_INCLUDE_GUARD_DOMNODE_HPP

#include "NodeList.H"
#include "DOMDocument.hpp"
namespace XERCES
{

typedef char XMLCh;

class DOMDocument;

/**ADAPTER PATTERN - Target
 */
class  DOMNode {
protected:
    // -----------------------------------------------------------------------
    //  Hidden constructors
    // -----------------------------------------------------------------------
    /** @name Hidden constructors */
    //@{
    DOMNode() {}
    DOMNode(const DOMNode &) {}
    //@}

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
    virtual ~DOMNode() {};
    //@}

    // -----------------------------------------------------------------------
    //  Class Types
    // -----------------------------------------------------------------------
    /** @name Public Constants */
    //@{
    /**
     * NodeType
     *
     * @since DOM Level 1
     */
    enum NodeType {
        ELEMENT_NODE                = 1,
        ATTRIBUTE_NODE              = 2,
        TEXT_NODE                   = 3,
        CDATA_SECTION_NODE          = 4,
        ENTITY_REFERENCE_NODE       = 5,
        ENTITY_NODE                 = 6,
        PROCESSING_INSTRUCTION_NODE = 7,
        COMMENT_NODE                = 8,
        DOCUMENT_NODE               = 9,
        DOCUMENT_TYPE_NODE          = 10,
        DOCUMENT_FRAGMENT_NODE      = 11,
        NOTATION_NODE               = 12
    };

    /**
     * DocumentPosition:
     *
     * <p><code>DOCUMENT_POSITION_CONTAINED_BY:</code>
     * The node is contained by the reference node. A node which is contained is always following, too.</p>
     * <p><code>DOCUMENT_POSITION_CONTAINS:</code>
     * The node contains the reference node. A node which contains is always preceding, too.</p>
     * <p><code>DOCUMENT_POSITION_DISCONNECTED:</code>
     * The two nodes are disconnected. Order between disconnected nodes is always implementation-specific.</p>
     * <p><code>DOCUMENT_POSITION_FOLLOWING:</code>
     * The node follows the reference node.</p>
     * <p><code>DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC:</code>
     * The determination of preceding versus following is implementation-specific.</p>
     * <p><code>DOCUMENT_POSITION_PRECEDING:</code>
     * The second node precedes the reference node.</p>
     *
     * @since DOM Level 3
     */
    enum DocumentPosition {
        DOCUMENT_POSITION_DISCONNECTED            = 0x01,
        DOCUMENT_POSITION_PRECEDING               = 0x02,
        DOCUMENT_POSITION_FOLLOWING               = 0x04,
        DOCUMENT_POSITION_CONTAINS                = 0x08,
        DOCUMENT_POSITION_CONTAINED_BY            = 0x10,
        DOCUMENT_POSITION_IMPLEMENTATION_SPECIFIC = 0x20
    };
    //@}

    // -----------------------------------------------------------------------
    //  Virtual DOMNode interface
    // -----------------------------------------------------------------------
    /** @name Functions introduced in DOM Level 1 */
    //@{
    // -----------------------------------------------------------------------
    //  Getter methods
    // -----------------------------------------------------------------------
    /**
     * The name of this node, depending on its type; see the table above.
     * @since DOM Level 1
     */
    virtual const XMLCh *   getNodeName() const = 0;

    /**
     * Gets the value of this node, depending on its type.
     *
     * @exception DOMException
     *   NO_MODIFICATION_ALLOWED_ERR: Raised when the node is readonly.
     * @since DOM Level 1
     */
    virtual const XMLCh *       getNodeValue() const = 0;

    /**
     * An enum value representing the type of the underlying object.
     * @since DOM Level 1
     */
    virtual NodeType            getNodeType() const = 0;

    /**
     * Gets the parent of this node.
     *
     * All nodes, except <code>DOMDocument</code>,
     * <code>DOMDocumentFragment</code>, and <code>DOMAttr</code> may have a parent.
     * However, if a node has just been created and not yet added to the tree,
     * or if it has been removed from the tree, a <code>null</code> DOMNode
     * is returned.
     * @since DOM Level 1
     */
    virtual DOMNode        *getParentNode() const = 0;

    /**
     * Gets a <code>DOMNodeList</code> that contains all children of this node.
     *
     * If there
     * are no children, this is a <code>DOMNodeList</code> containing no nodes.
     * The content of the returned <code>DOMNodeList</code> is "live" in the sense
     * that, for instance, changes to the children of the node object that
     * it was created from are immediately reflected in the nodes returned by
     * the <code>DOMNodeList</code> accessors; it is not a static snapshot of the
     * content of the node. This is true for every <code>DOMNodeList</code>,
     * including the ones returned by the <code>getElementsByTagName</code>
     * method.
     * @since DOM Level 1
     */
    virtual DOMNodeList    *getChildNodes() const = 0;
    /**
     * Gets the first child of this node.
     *
     * If there is no such node, this returns <code>null</code>.
     * @since DOM Level 1
     */
    virtual DOMNode        *getFirstChild() const = 0;

    /**
     * Gets the last child of this node.
     *
     * If there is no such node, this returns <code>null</code>.
     * @since DOM Level 1
     */
    virtual DOMNode        *getLastChild() const = 0;

    /**
     * Gets the node immediately preceding this node.
     *
     * If there is no such node, this returns <code>null</code>.
     * @since DOM Level 1
     */
    virtual DOMNode        *getPreviousSibling() const = 0;

    /**
     * Gets the node immediately following this node.
     *
     * If there is no such node, this returns <code>null</code>.
     * @since DOM Level 1
     */
    virtual DOMNode        *getNextSibling() const = 0;


    virtual DOMDocument      *getOwnerDocument() const = 0;

    virtual DOMNode        * cloneNode(bool deep) const {};

    virtual DOMNode       *insertBefore(DOMNode *newChild,
                                          DOMNode *refChild) = 0;


    virtual DOMNode  *replaceChild(DOMNode *newChild,
                                     DOMNode *oldChild) = 0;
    virtual DOMNode        *removeChild(DOMNode *oldChild) = 0;

    virtual DOMNode        *appendChild(DOMNode *newChild) = 0;

    // -----------------------------------------------------------------------
    //  Query methods
    // -----------------------------------------------------------------------
    /**
     *  This is a convenience method to allow easy determination of whether a
     * node has any children.
     *
     * @return  <code>true</code> if the node has any children,
     *   <code>false</code> if the node has no children.
     * @since DOM Level 1
     */
    virtual bool             hasChildNodes() const = 0;
    virtual void              setNodeValue(const XMLCh  *nodeValue) = 0;
    //@}
    /**
     * Returns the local part of the <em>qualified name</em> of this node.
     * <p>
     * For nodes created with a DOM Level 1 method, such as
     * <code>createElement</code> from the <code>DOMDocument</code> interface,
     * it is null.
     *
     * @since DOM Level 2
     */
    virtual const XMLCh *          getLocalName() const = 0;
    //@}



}; // namespace XERCES

#endif