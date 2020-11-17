#include "Command.H"

//COMMAND PATTERN - Invoker
class Interpreter
{
    private:
    Command* command;
    public:
    void process() { command->execute(); };
    void storeCommand(Command* c) { command = c; }

};