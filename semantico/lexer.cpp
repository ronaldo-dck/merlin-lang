#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

/*
TODO

número negativo
modo erros
regex
.
.
.

 */
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
    token_chv_dir
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

    vector<t_token>  lexical_analysis(string filename)
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

int main(int argc, char const *argv[2])
{
    string filename = argv[1];
    string verbose = argc > 2 ? argv[2] : "";
    vector<t_token> tokens = lexical_analysis(filename);
    if (verbose == "--verbose")
        for (const auto &token : tokens)
            cout << "<<" << setw(18) << get_token_type_name(token.type) << ", " << token.data << "  >>" << endl;

    return 0;
}
