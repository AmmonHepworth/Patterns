#include "WhiteSpaceStrategy.H"

std::string PrettySpacingStrategy::getWhiteSpace() { return "\n"; }


std::string PrettySpacingStrategy::getIndent(int indentationLevel)
{
    std::stringstream ss;
	for (int i = 0; i < indentationLevel; i++)
		ss << "\t";

    return ss.str();

}

std::string MinimalSpacingStrategy::getWhiteSpace() { return ""; }

std::string MinimalSpacingStrategy::getIndent(int indentationLevel) { return ""; }