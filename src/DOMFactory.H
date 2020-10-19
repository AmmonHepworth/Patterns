#ifndef DOM_FACTORY_H
#define DOM_FACTORY_H

#include "Node.H"
#include "Document.H"
#include <string>

/** ABSRACT FACTORY PATTERN - AbstractFactory
 * Defines interface for DOMFactories
 */
class AbstractDOMFactory
{
    public:
    virtual dom::Document * createDocument() = 0;
    virtual dom::Element * createElement(const std::string &, dom::Document * ) = 0;
    virtual dom::Attr * createAttribute(const std::string &,  dom::Document * ) = 0;
    virtual dom::Text * createText(const std::string &, dom::Document * ) = 0;
};

/** ABSRACT FACTORY PATTERN - ConcreteFactory
 * Implements interface for DOMFactories
 */
class DOMFactory: public AbstractDOMFactory
{
    public:
    virtual dom::Document * createDocument();
    virtual dom::Element * createElement(const std::string &, dom::Document * );
    virtual dom::Attr * createAttribute(const std::string &,  dom::Document * );
    virtual dom::Text * createText(const std::string &, dom::Document * );
};

#endif