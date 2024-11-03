#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <map>

using namespace std;

enum token_type
{
    token_id = 0,
    token_int,
    token_float,
    token_string,
    token_ignore,
    token_if,
    token_type_int,
    token_type_float,
    token_type_string,
    token_for,
    token_while,
    token_summon,
    token_echo,
    token_tome,
    token_ingredients,
    token_endline,
    token_add,
    token_sub,
    token_mul,
    token_div,
    token_or,
    token_and,
    token_not,
    token_eq,
    token_le,
    token_gr,
    token_atr,
    token_par_esq,
    token_par_dir,
    token_col_esq,
    token_col_dir,
    token_chv_esq,
    token_chv_dir,
    gtoken_program = 100,
    gtoken_cmd_init,
    gtoken_declare_sq,
    gtoken_cmd_sq,
    gtoken_operation,
    gtoken_assign_sq,
    gtoken_for_sq,
    gtoken_summon_sq,
    gtoken_echo_sq,
    gtoken_control,
    gtoken_control_struc,
    gtoken_block,
    gtoken_expression,
    gtoken_logic,
    gtoken_bool_op,
    gtoken_relacional,
    gtoken_relacional_op,
    gtoken_expr,
    gtoken_term,
    gtoken_factor,
    gtoken_id,
    gtoken_op_logic,
    gtoken_op_rel,
    gtoken_op_art_pr,
    gtoken_op_art_sc,
    gtoken_value,
    gtoken_type,
    gtoken_end
};



struct t_token
{
    token_type type;
    string data;
};




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

struct prod{
    token_type red;
    vector<token_type> derivados;
};

map<int, prod> productions = {
    {0, {gtoken_program, {token_tome, token_chv_esq, gtoken_cmd_init, token_chv_dir}}},
    {1, {gtoken_cmd_init, {token_ingredients, token_chv_esq, gtoken_declare_sq, token_chv_dir, gtoken_cmd_sq}}},
    {2, {gtoken_cmd_init, {gtoken_cmd_sq}}},
    {3, {gtoken_declare_sq, {gtoken_type, token_id, token_endline, gtoken_declare_sq}}},
    {4, {gtoken_declare_sq, {gtoken_type, token_id, token_atr, gtoken_value, token_endline, gtoken_declare_sq}}},
    {5, {gtoken_cmd_sq, {gtoken_operation, token_endline, gtoken_cmd_sq}}},
    {6, {gtoken_operation, {gtoken_assign_sq}}},
    {7, {gtoken_operation, {gtoken_control}}},
    {8, {gtoken_operation, {gtoken_for_sq}}},
    {9, {gtoken_operation, {gtoken_summon_sq}}},
    {10, {gtoken_operation, {gtoken_echo_sq}}},
    {11, {gtoken_assign_sq, {token_id, token_atr, gtoken_logic}}},
    {12, {gtoken_for_sq, {token_for, token_par_esq, gtoken_assign_sq, token_endline, gtoken_logic, token_endline, token_int, token_par_dir, gtoken_block}}},
    {13, {gtoken_summon_sq, {token_summon, token_par_esq, gtoken_id, token_par_dir}}},
    {14, {gtoken_echo_sq, {token_echo, token_par_esq, token_string, token_par_dir}}},
    {15, {gtoken_echo_sq, {token_echo, token_par_esq, gtoken_id, token_par_dir}}},
    {16, {gtoken_control, {gtoken_control_struc, gtoken_expression, gtoken_block}}},
    {17, {gtoken_control_struc, {token_if}}},
    {18, {gtoken_control_struc, {token_while}}},
    {19, {gtoken_block, {token_chv_esq, gtoken_cmd_sq, token_chv_dir}}},
    {20, {gtoken_expression, {token_par_esq, gtoken_logic, token_par_dir}}},
    {21, {gtoken_logic, {gtoken_logic, gtoken_op_logic, gtoken_bool_op}}},
    {22, {gtoken_logic, {gtoken_bool_op}}},
    {23, {gtoken_bool_op, {gtoken_relacional}}},
    {24, {gtoken_bool_op, {token_not, gtoken_relacional}}},
    {25, {gtoken_relacional, {gtoken_relacional, gtoken_op_rel, gtoken_relacional_op}}},
    {26, {gtoken_relacional, {gtoken_relacional_op}}},
    {27, {gtoken_relacional_op, {gtoken_expr}}},
    {28, {gtoken_relacional_op, {token_par_esq, gtoken_relacional, token_par_dir}}},
    {29, {gtoken_expr, {gtoken_expr, gtoken_op_art_pr, gtoken_term}}},
    {30, {gtoken_expr, {gtoken_term}}},
    {31, {gtoken_term, {gtoken_term, gtoken_op_art_sc, gtoken_factor}}},
    {32, {gtoken_term, {gtoken_factor}}},
    {33, {gtoken_factor, {token_par_esq, gtoken_expr, token_par_dir}}},
    {34, {gtoken_factor, {gtoken_value}}},
    {35, {gtoken_factor, {gtoken_id}}},
    {36, {gtoken_id, {token_id}}},
    {37, {gtoken_id, {token_id, token_col_esq, gtoken_expr, token_col_dir}}},
    {38, {gtoken_op_logic, {token_and}}},
    {39, {gtoken_op_logic, {token_or}}},
    {40, {gtoken_op_rel, {token_gr}}},
    {41, {gtoken_op_rel, {token_le}}},
    {42, {gtoken_op_rel, {token_eq}}},
    {43, {gtoken_op_art_pr, {token_add}}},
    {44, {gtoken_op_art_pr, {token_sub}}},
    {45, {gtoken_op_art_sc, {token_mul}}},
    {46, {gtoken_op_art_sc, {token_div}}},
    {47, {gtoken_value, {token_int}}},
    {48, {gtoken_value, {token_float}}},
    {49, {gtoken_value, {token_string}}},
    {50, {gtoken_type, {token_type_int}}},
    {51, {gtoken_type, {token_type_int, token_col_esq, token_int, token_col_dir}}},
    {52, {gtoken_type, {token_type_float}}},
    {53, {gtoken_type, {token_type_float, token_col_esq, token_int, token_col_dir}}},
    {54, {gtoken_type, {token_type_string}}}
};

void sintax_analysis(vector<t_token> tokens)
{
    vector<map<token_type, string>> stateTable(10);
    stateTable[0] = {{token_tome, "S2"}, {gtoken_program, "1"}};
    stateTable[2] = {{token_id, "S3"}};
    stateTable[3] = {{token_chv_esq, "S4"}, {gtoken_cmd_init, "5"}};
    stateTable[4] = {{gtoken_cmd_sq, "113"}};
    stateTable[5] = {{token_chv_dir, "algo"}};

    // «cmd_init» → «cmd-sq»
    // gtoken_cmd_init => gtoken_cmd_sq;

    cout << stateTable[0].at(token_tome) << endl;
    int index = 0;
    for (const auto &map : stateTable)
    {
        cout << "---" << index++ << endl;
        for (const auto &pair : map)
        {
            cout << pair.first << ": " << pair.second << endl;
        }
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
    string filename = argv[1];
    string verbose = argc > 2 ? argv[2] : "";
    vector<t_token> tokens = lexical_analysis(filename);
    if (verbose == "--verbose")
        for (const auto &token : tokens)
            cout << "<<" << setw(18) << get_token_type_name(token.type) << ", " << token.data << "  >>" << endl;

    sintax_analysis(tokens);
    return 0;
}