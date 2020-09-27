#
# Requires boost regex library.
# Set the include_directories argument to the path to the root of your
# boost installation directory.  This is "./regexxp5" in my example.
#
cmake_minimum_required (VERSION 3.12)
project (Patterns)

include_directories(regexpp5)
add_executable(Patterns Test.C)
target_sources(Patterns PUBLIC
	Attr.C
	Attr.H
	Document.C
	Document.H
	Element.C
	Element.H
	NamedNodeMap.C
	NamedNodeMap.H
	Node.C
	Node.H
	NodeList.H
	Test.C
	Text.C
	Text.H
	XMLSerializer.C
	XMLSerializer.H
	XMLTokenizer.C
	XMLTokenizer.H
	XMLValidator.C
	XMLValidator.H
	)
target_link_libraries(Patterns boost_regex)
