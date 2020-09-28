#ifndef WHITESPACESTRATEGY_H
#define WHITESPACESTRATEGY_H

#include <sstream>

/** STRATEGY PATTERN - Strategy
 *  WhiteSpaceStrategy operates as the abstract "Strategy" class in this pattern
 *  Below we see the common interface methods getWhiteSpace and getIndent that 
 *   the ConcreteStrategies (PrettySpacingStrategy, MinimalSpacingStrategy) will implement
 *  This will then be used by the Nodes to get the appropriate whitespace
 * 
 *  This strategy has two methods to avoid having different whitespace strategies
 *  for each of the nodes. This way, their serialize functions can just get the correct
 *  whitespace where and when they need it.
 **/
class WhiteSpaceStrategy
{
    public:
    virtual std::string getWhiteSpace() = 0;
    virtual std::string getIndent(int) = 0;
};

/** STRATEGY PATTERN - ConcreteStrategy
 *  Here we have an implementation of a whitespace strategy, where the whitespace
 *   is set to be pretty
 **/
class PrettySpacingStrategy: public WhiteSpaceStrategy
{
    public:
    virtual std::string getWhiteSpace();
    virtual std::string getIndent(int);
};

/** STRATEGY PATTERN - ConcreteStrategy
 *  Here we have an implementation of a whitespace strategy, where the whitespace
 *   is set to be minimal
 **/
class MinimalSpacingStrategy: public WhiteSpaceStrategy
{
    public:
    virtual std::string getWhiteSpace();
    virtual std::string getIndent(int);
};
#endif