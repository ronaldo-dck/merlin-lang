#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <stack>
#include <map>
#include "token.h"
#include "productions.h"
#include "state_table.h"
// #include <dlfcn.h>
using namespace std;

token_type get_token(string lexema)
{
    if (lexema == "int")
        return token_type_int;
    if (lexema == "float")
        return token_type_float;
    if (lexema == "string")
        return token_type_string;
    if (lexema == "if")
        return token_if;
    if (lexema == "for")
        return token_for;
    if (lexema == "while")
        return token_while;
    if (lexema == "summon")
        return token_summon;
    if (lexema == "echo")
        return token_echo;
    if (lexema == "tome")
        return token_tome;
    if (lexema == "ingredients")
        return token_ingredients;

    return token_id;
}

token_type get_op_or_del(char c)
{
    if (c == ';')
        return token_endline;
    if (c == '+')
        return token_add;
    if (c == '-')
        return token_sub;
    if (c == '*')
        return token_mul;
    if (c == '/')
        return token_div;
    if (c == '|')
        return token_or;
    if (c == '&')
        return token_and;
    if (c == '!')
        return token_not;
    if (c == '=')
        return token_eq;
    if (c == '<')
        return token_le;
    if (c == '>')
        return token_gr;
    if (c == ':')
        return token_atr;
    if (c == '(')
        return token_par_esq;
    if (c == ')')
        return token_par_dir;
    if (c == '[')
        return token_col_esq;
    if (c == ']')
        return token_col_dir;
    if (c == '{')
        return token_chv_esq;
    if (c == '}')
        return token_chv_dir;

    return token_ignore;
}

    vector<t_token> lexical_analysis(string filename)
    {
        ifstream inputFile(filename);
        vector<t_token> tokens;

        string text;
        char c;
        int pos = 0;
        int line = 0;
        while (1)
        {
            c = inputFile.get();
            pos++;
            if (c == EOF)
                break;

            if (c == '"')
            {
                string tmp;
                while (c = inputFile.get())
                {
                    pos++;
                    if (c == '\n')
                    {
                        cout << "Invalid string: " << tmp << " at line " << line + 1 << " col " << pos + 1 << endl;
                        break;
                    }
                    if (c == '"')
                        break;
                    tmp += c;
                }

                tokens.push_back({token_string, tmp});
                continue;
            }

            if (c == ' ' || c == '\n' || c == '\t' || c == '\r')
            {
                if (c == '\n')
                {
                    pos = 0;
                    line++;
                }
                // while (c = inputFile.get() && (c == ' ' || c == '\n' || c == '\t' || c == '\r')){};
                // tokens.push_back({token_ignore, ""});
                continue;
            }

            if (c == '_')
            {
                while (c = inputFile.get())
                {
                    pos++;

                    if (c == '\n')
                    {
                        pos = 0;
                        line++;
                        break;
                    }
                };

                // tokens.push_back({token_ignore, ""});
                continue;
            }

            if (isdigit(c) || c == '~')
            {
                string tmp;
                tmp += c;
                c = inputFile.get();
                pos++;

                if (tmp == "~" && !isdigit(c))
                {
                    cout << "Invalid negative number: " << tmp << " at line " << line + 1 << " col " << pos + 1 << endl;
                    continue;
                }

                while (isdigit(c))
                {
                    tmp += c;
                    c = inputFile.get();
                    pos++;
                }
                if (c == '.')
                {
                    tmp += c;
                    c = inputFile.get();
                    pos++;
                    if (isdigit(c))
                    {
                        while (isdigit(c))
                        {
                            tmp += c;
                            c = inputFile.get();
                            pos++;
                        }
                        tokens.push_back({token_float, tmp});
                        inputFile.seekg(-1, ios::cur);
                        pos--;
                        continue;
                    }
                    else
                    {
                        // throw "Invalid float"s;
                        cout << "Invalid float: " << tmp << " at line " << line + 1 << " col " << pos + 1 << endl;
                        continue;
                    }
                }
                else
                {
                    tokens.push_back({token_int, tmp});
                    inputFile.seekg(-1, ios::cur);
                    pos--;
                    continue;
                }
            }

            if (isalpha(c))
            {
                string tmp;
                tmp += c;
                c = inputFile.get();
                pos++;
                while (isalnum(c))
                {
                    tmp += c;
                    c = inputFile.get();
                    pos++;
                }
                tokens.push_back({get_token(tmp), tmp});
                inputFile.seekg(-1, ios::cur);
                pos--;
                continue;
            }

            if (c == ';' || c == '+' || c == '-' || c == '*' || c == '/' || c == '|' || c == '&' || c == '!' || c == '=' || c == '<' || c == '>' || c == ':' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
            {
                tokens.push_back({get_op_or_del(c), ""});
                continue;
            }

            // throw "Invalid character"s;
            cout << "Invalid character: " << c << " at line " << line + 1 << " col " << pos + 1 << endl;
        }

        return tokens;
    }

/////////////////////////////////////////////////////////////////////////////////////////////

const char *get_token_type_name(token_type type)
{
    switch (type)
    {
    case token_id:
        return "ID";
    case token_int:
        return "Integer";
    case token_float:
        return "Float";
    case token_string:
        return "String";
    case token_ignore:
        return "Ignore";
    case token_if:
        return "If";
    case token_type_int:
        return "Type Integer";
    case token_type_float:
        return "Type Float";
    case token_type_string:
        return "Type String";
    case token_for:
        return "For";
    case token_while:
        return "While";
    case token_summon:
        return "Summon";
    case token_echo:
        return "Echo";
    case token_tome:
        return "Tome";
    case token_ingredients:
        return "Ingredients";
    case token_endline:
        return "Endline";
    case token_add:
        return "Add";
    case token_sub:
        return "Subtract";
    case token_mul:
        return "Multiply";
    case token_div:
        return "Divide";
    case token_or:
        return "Or";
    case token_and:
        return "And";
    case token_not:
        return "Not";
    case token_eq:
        return "Equal";
    case token_le:
        return "Less";
    case token_gr:
        return "Greater";
    case token_atr:
        return "Assign";
    case token_par_esq:
        return "Left Parenthesis";
    case token_par_dir:
        return "Right Parenthesis";
    case token_col_esq:
        return "Left Colon";
    case token_col_dir:
        return "Right Colon";
    case token_chv_esq:
        return "Left Brace";
    case token_chv_dir:
        return "Right Brace";
    case gtoken_program:
        return "Program";
    case gtoken_cmd_init:
        return "cmd_Initialize";
    case gtoken_declare_sq:
        return "Declare-sq";
    case gtoken_cmd_sq:
        return "Command-sq";
    case gtoken_operation:
        return "Operation";
    case gtoken_assign_sq:
        return "Assign-sq";
    case gtoken_for_sq:
        return "For-sq";
    case gtoken_summon_sq:
        return "Summon-sq";
    case gtoken_echo_sq:
        return "Echo-sq";
    case gtoken_control:
        return "Control";
    case gtoken_control_struc:
        return "Control Structure";
    case gtoken_block:
        return "Block";
    case gtoken_expression:
        return "Expression";
    case gtoken_logic:
        return "Logic";
    case gtoken_bool_op:
        return "Boolean Operator";
    case gtoken_relacional:
        return "Relational";
    case gtoken_relacional_op:
        return "Relational Operator";
    case gtoken_expr:
        return "Expression";
    case gtoken_term:
        return "Term";
    case gtoken_factor:
        return "Factor";
    case gtoken_id:
        return "Identifier";
    case gtoken_op_logic:
        return "Logic Operator";
    case gtoken_op_rel:
        return "Relational Operator";
    case gtoken_op_art_pr:
        return "Arithmetic Operator (Primary)";
    case gtoken_op_art_sc:
        return "Arithmetic Operator (Secondary)";
    case gtoken_value:
        return "Value";
    case gtoken_type:
        return "Type";
    case gtoken_end:
        return "End";
    default:
        return "Error";
    }
}

std::map<char, int> get_action(const std::string &input)
{
    std::string numberStr; // Para armazenar a parte numérica
    int number = 0;        // Para armazenar o número final
    char a = 'D';          // Valor padrão se não houver 'S' ou 'R'

    // Verifica se o primeiro caractere é 'S' ou 'R'
    if (!input.empty())
    {
        if (input[0] == 'S' || input[0] == 'R')
        {
            a = input[0]; // Armazena o caractere
            // Começamos a partir do segundo caractere (índice 1)
            for (size_t i = 1; i < input.length(); ++i)
            {
                numberStr += input[i]; // Constrói a string numérica
            }
        }
        else if (isdigit(input[0]))
        {
            // Se o primeiro caractere for um dígito, armazena-o diretamente
            numberStr += input[0];
            a = 'D'; // Define 'D' como padrão, já que não é 'S' ou 'R'
            // E processa o restante da string
            for (size_t i = 1; i < input.length(); ++i)
            {
                numberStr += input[i]; // Constrói a string numérica
            }
        }
    }

    // Converte a string numérica para um número inteiro, se não estiver vazia
    if (!numberStr.empty())
    {
        number = std::stoi(numberStr);
    }

    // Inicializa o mapa corretamente
    std::map<char, int> action = {{a, number}};
    return action;
}

void print_stack(stack<int> pilha)
{
    
    int loop = pilha.size();
    for (int i = loop; i > 0; i--)
    {
        if (i % 2 == 0)
            cout << "state: " << pilha.top() << " ";
        else
        {
            token_type token = static_cast<token_type>(pilha.top());
            cout << get_token_type_name(token) << "| ";
        }
        pilha.pop();
    }
    cout << endl;
}

void sintax_analysis(vector<token_type> tokens)
{
    StateTable stateTable = initStateTable();
    ProductionsMap productions = initProductions();

    stack<int> pilha;
    pilha.push(gtoken_end);
    pilha.push(0);

    int current_state = 0; // PARA TESTES em real sempre ZERO
    int ip = 0;

    while (!pilha.empty())
    {
        token_type source = tokens[ip];
        if (ip >= tokens.size())
            source = gtoken_end;

        cout << get_token_type_name(source) << endl;
        auto entry = stateTable[current_state].at(source);
        if(entry == "ACEITA"){
            cout << "linguagem sintaticamente correta\n";
            exit(0);
        }
        
        map<char, int> action = get_action(entry);
        char task;
        int next_state;

        for (const auto &pair : action)
        {
            task = pair.first;        // Atribui a chave à variável key
            next_state = pair.second; // Atribui o valor à variável value
            break;                    // Sai do loop após o primeiro par
        }
        cout << "action: " << task << " " << next_state << endl;
        if (task == 'S')
        {
            current_state = next_state;
            pilha.push(tokens[ip]);
            pilha.push(next_state);
            ip++;
        }
        if (task == 'R')
        {
            print_stack(pilha);
            for (int i = 0; i < 2 * productions[next_state].derivados.size(); i++)
            {
                pilha.pop();
                // print_stack(pilha);
                // cout << "=========================================================\n";
            }

            current_state = pilha.top();

            pilha.push(productions[next_state].red);
            cout << "=========================================================\n";
            // print_stack(pilha);

            auto entry = stateTable[current_state].at(productions[next_state].red);
            auto action = get_action(entry);
            pilha.push(action.at('D'));
            current_state = pilha.top();

            print_stack(pilha);

            // exit(0);
        }

        // std::cout << "  Token: " << get_token_type_name(tokens[ip]) << ", Ação: " << entry << "\n";
        // cout << current_state << "   ip:" << ip << endl;

    }
    
}

vector<token_type> extract_tokens_from_data(string filename){
    vector<t_token> tokens_and_data = lexical_analysis(filename);
    vector<token_type> tokens_types;
    for(int i = 0; i < tokens_and_data.size(); i++ ){
        tokens_types.push_back(tokens_and_data[i].type);
    }
    return tokens_types;
}

int main(int argc, char const *argv[2])
{
    sintax_analysis(extract_tokens_from_data("/home/ronaldodrecksler/UNIOESTE/comp/merlin-lang/sintatico/overview.ml"));
    return 0;
}