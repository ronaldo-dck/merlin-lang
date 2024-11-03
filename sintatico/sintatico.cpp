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
using namespace std;

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

void sintax_analysis(vector<token_type> tokens)
{
    StateTable stateTable = initStateTable();
    ProductionsMap productions = initProductions();

    stack<int> pilha;
    pilha.push(0);
    pilha.push(gtoken_end);

    int current_state = 8; // PARA TESTES em real sempre ZERO
    int ip = 0;

    // for (const auto &map : stateTable)
    // {
    //     cout << "---" << index++ << endl;
    //     for (const auto &pair : map)
    //     {
    //         cout << pair.first << ": " << pair.second << endl;
    //     }
    // }
    while (!pilha.empty() || ip < 4)
    {
        cout << get_token_type_name(tokens[ip]) << endl;
        for (const auto &entry : stateTable[current_state])
        {
            
            if (entry.first == tokens[ip])
            {
                map<char, int> action = get_action(entry.second);
                char task;
                int next_state;

                // Desmontando o mapa em duas variáveis
                for (const auto &pair : action)
                {
                    task = pair.first;    // Atribui a chave à variável key
                    next_state = pair.second; // Atribui o valor à variável value
                    break;               // Sai do loop após o primeiro par
                }
                current_state = next_state;
                pilha.push(tokens[ip]);
                pilha.push(next_state);

                std::cout << "  Token: " << get_token_type_name(entry.first) << ", Ação: " << entry.second << "\n";
                cout << current_state << "   ip:" << ip<< endl;
            }
        }
        ip++;
        if(ip == 4)
            exit(0);
    }
    /*


        stack: 0
        tokens:
            token_tome

        stateTable[0].at(token_tome) -> "S2"

        stack: 0 token_tome 2
        tokens:
            token_id

        stateTable[2].at(token_id) -> "S3"
        stack: 0 token_tome 2 token_id 3

        ...

        stack: 0 token_tome 2 token_id 3 token_chv_esq 4 gtoken_cmd_sq 5
        stack: 0 token_tome 2 token_id 3 token_chv_esq 4 gtoken_cmd_init 5
        stack: 0 token_tome 2 token_id 3 token_chv_esq 4 gtoken_cmd_init 5 token_chv_dir 6

    // «program»        → "tome" "id_puro" {«cmd_init»}
    "prod:gtoken_program,token_tome,token_id,token_chv_esq,gtoken_cmd_init,token_chv_dir"


    s
    0
    prod:

    acessa tabela
    (processa string) | acessa algo
    -
    -
    -


    numerar produções
    transformá-las em map<int, prod> ->

        stack: 0 program 1
        aceita
     */
}

int main(int argc, char const *argv[2])
{

    vector<token_type> tokens = {token_type_int, token_col_esq, token_int, token_col_dir};
    sintax_analysis(tokens);
    return 0;
}