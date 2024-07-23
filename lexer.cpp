#include <fstream>
#include <iostream>
#include <string>
#include <vector>

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


token_type get_token(string lexema){
    if (lexema == "int") return token_type_int;
    if (lexema == "float") return token_type_float;
    if (lexema == "string") return token_type_string;
    if (lexema == "if") return token_if;
    if (lexema == "for") return token_for;
    if (lexema == "while") return token_while;
    if (lexema == "summon") return token_summon;
    if (lexema == "echo") return token_echo;
    if (lexema == "tome") return token_tome;
    if (lexema == "ingredients") return token_ingredients;

    return token_id;
}

token_type get_op_or_del(char c){
    if (c == '?') return token_endline;
    if (c == '+') return token_add;
    if (c == '-') return token_sub;
    if (c == '*') return token_mul;
    if (c == '/') return token_div;
    if (c == '|') return token_or;
    if (c == '&') return token_and;
    if (c == '!') return token_not;
    if (c == '=') return token_eq;
    if (c == '<') return token_le;
    if (c == '>') return token_gr;
    if (c == ':') return token_atr;
    if (c == '(') return token_par_esq;
    if (c == ')') return token_par_dir;
    if (c == '[') return token_col_esq;
    if (c == ']') return token_col_dir;
    if (c == '{') return token_chv_esq;
    if (c == '}') return token_chv_dir;

    return token_ignore;
}

int main()
{
    ifstream inputFile("overview.ml");
    vector<t_token> tokens;

    string text;
    char c;
    int pos = 0;
    while (1)
    {
        c = inputFile.get();
        cout << c << ' ' << pos++ << endl;
        if (c == EOF)
            break;

        if (c == '"')
        {
            string tmp;
            while (c = inputFile.get()) {
                if(c == '"') break;
                tmp += c;
            }

            tokens.push_back({token_string, tmp});
            continue;
        }

        if (c == ' ' || c == '\n' || c == '\t' || c == '\r')
        {
            // while (c = inputFile.get() && (c == ' ' || c == '\n' || c == '\t' || c == '\r')){};
            // tokens.push_back({token_ignore, ""});
            continue;
        }

        if (c == '~')
        {
            while (c = inputFile.get() )
            {
                cout << c;

                if (c == '\n') break;
            };

            tokens.push_back({token_ignore, ""});
            continue;
        }

        if (isdigit(c))
        {
            string tmp;
            tmp += c;
            c = inputFile.get();
            while (isdigit(c))
            {
                tmp += c;
                c = inputFile.get();
            }
            if (c == '.')
            {
                tmp += c;
                c = inputFile.get();
                if (isdigit(c))
                {
                    while (isdigit(c))
                    {
                        tmp += c;
                        c = inputFile.get();
                    }
                    tokens.push_back({token_float, tmp});
                    inputFile.seekg(-1, ios::cur);
                    continue;
                } else {
                    throw "Invalid float"s;
                }
            }
            else
            {
                tokens.push_back({token_int, tmp});
                inputFile.seekg(-1, ios::cur);
                continue;
            }
        }

        if (isalpha(c))
        {
            string tmp;
            tmp += c;
            c = inputFile.get();
            while (isalnum(c))
            {
                tmp += c;
                c = inputFile.get();
            }
            tokens.push_back({get_token(tmp), tmp});
            inputFile.seekg(-1, ios::cur);
            continue;
        }

        if (c == '?' || c == '+' || c == '-' || c == '*' || c == '/' || c == '|' || c == '&' || c == '!' || c == '=' || c == '<' || c == '>' || c == ':' || c == '(' || c == ')' || c == '[' || c == ']' || c == '{' || c == '}')
        {
            tokens.push_back({get_op_or_del(c), ""});
            continue;
        }

        // throw "Invalid character"s;
        cout << "Invalid character: " << c << endl;
    }

    for(const auto& token : tokens){
        cout << "Token Type: " << token.type << ", Value: " << token.data << endl;
        }
    

    return 0;
}