#ifndef SEMANTICO_H
#define SEMANTICO_H
#include <map>
#include <vector>
#include <functional>
#include <stack>
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
    void start_for();
    void mid_for();


private:
    std::unordered_map<std::string, token_type> symbolTable;
    bool insertSymbol(std::vector<t_token> tokens);
    token_type getSymbolType(std::string name);

    bool checkAssignment(t_token left, t_token right);
    token_type Coercion(t_token left, t_token right);
    token_type BoolCoercion(t_token left, t_token right);

    void call_echo(std::vector<t_token>  tokens);
    void call_summon(std::vector<t_token>  tokens);
    void call_assign(std::vector<t_token>  tokens);
    void call_control_start(std::vector<t_token>  tokens);
    void call_control_end(std::vector<t_token>  tokens);
    void call_expression(std::vector<t_token>  tokens);
    void call_expression_bool(std::vector<t_token>  tokens);
    void end_for(std::vector<t_token>  tokens);

    int globalCounter = 1;
    int indexCounter = 1;
    int labelCounter = 1;
    std::stack<int> falseLabels;
    std::stack<int> loopLabels;
    std::vector<std::string> generatedCode;
};

#endif // SEMANTICO_H
