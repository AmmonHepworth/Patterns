#ifndef COMMAND_H
#define COMMAND_H
#include "Document.H"

//COMMAND PATTERN - Command
class Command
{
    public:
    virtual void execute() = 0;

};

//COMMAND PATTERN - ConcreteCommand
class SerializePrettyCommand: public Command
{
    private:
    dom::Document* document;
    public:
    SerializePrettyCommand(dom::Document*);
    virtual void execute();

};

//COMMAND PATTERN - ConcreteCommand
class SerializeMinimalCommand: public Command
{
    private:
    dom::Document* document;
    public:
    SerializeMinimalCommand(dom::Document*);
    virtual void execute();

};

//COMMAND PATTERN - ConcreteCommand
//kills the program, as an example
class QuitCommand: public Command
{
    public:
    virtual void execute() { exit(1337); }
};
#endif