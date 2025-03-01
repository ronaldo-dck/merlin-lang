#ifndef SEMANTICO_H
#define SEMANTICO_H
#include <map>
#include <vector>
#include <functional>
#include <unordered_map>
#include "token.h"

class Semantico {
public:
    Semantico();  // Constructor
    std::map<int, std::function<t_token(std::vector<t_token>)>> actions;
    std::map<int, std::function<void(std::vector<t_token>)>> code;
    t_token execute(int next_state, std::vector<t_token> tokens);
    void readTable();
    bool success = true;

private:
    std::unordered_map<std::string, token_type> symbolTable;
    bool insertSymbol(std::string name, token_type type);
    token_type getSymbolType(std::string name);
    bool checkAssignment(t_token left, t_token right);
    token_type Coercion(t_token left, t_token right);
    token_type BoolCoercion(t_token left, t_token right);

    std::vector<std::string> generatedCode;
};

#endif // SEMANTICO_H
