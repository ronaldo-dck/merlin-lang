
// MyClass.cpp
#include "semantico.h"
#include <iostream>

Semantico::Semantico() {
    // Constructor implementation
    actions = {
        // {0, {gtoken_program, {token_tome, token_id, token_chv_esq, gtoken_cmd_init, token_chv_dir}}},
        {0, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_program; return tokens[0]; }},
        // {1, {gtoken_cmd_init, {token_ingredients, token_chv_esq, gtoken_declare_sq, token_chv_dir, gtoken_cmd_sq}}},
        {0, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_cmd_init; return tokens[0]; }},
        // {2, {gtoken_cmd_init, {gtoken_cmd_sq}}},
        {2, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_cmd_sq; return tokens[0]; }},
        // {3, {gtoken_declare_sq, {gtoken_type, token_id, token_endline, gtoken_declare_sq}}},
        {3,[this](std::vector<t_token> tokens)  ->  t_token { insertSymbol(tokens[1].data, tokens[0].type); tokens[0].type = gtoken_declare_sq; return tokens[0];}},
        // {4, {gtoken_declare_sq, {gtoken_type, token_id, token_atr, gtoken_value, token_endline, gtoken_declare_sq}}},
        {4,[this](std::vector<t_token> tokens)  ->  t_token { checkAssignment(tokens[0], tokens[3]); insertSymbol(tokens[1].data, tokens[0].type); tokens[0].type = gtoken_declare_sq; return tokens[0];}},
        // {5, {gtoken_cmd_sq, {gtoken_operation, token_endline, gtoken_cmd_sq}}},
        {5,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_cmd_sq; return tokens[0];}},
        // {6, {gtoken_operation, {gtoken_assign_sq}}},
        {6,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {7, {gtoken_operation, {gtoken_control}}},
        {7,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {8, {gtoken_operation, {gtoken_for_sq}}},
        {8,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {9, {gtoken_operation, {gtoken_summon_sq}}},
        {9,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {10, {gtoken_operation, {gtoken_echo_sq}}},
        {10,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {11, {gtoken_assign_sq, {token_id, token_atr, gtoken_logic}}},
        {11,[this](std::vector<t_token> tokens)  ->  t_token { checkAssignment(tokens[0], tokens[2]); tokens[0].type = gtoken_assign_sq; return tokens[0];}},
        // {12, {gtoken_for_sq, {token_for, token_par_esq, gtoken_assign_sq, token_endline, gtoken_logic, token_endline, token_int, token_par_dir, gtoken_block}}},
        {12,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_for_sq; return tokens[0];}},
        // {13, {gtoken_summon_sq, {token_summon, token_par_esq, gtoken_id, token_par_dir}}},
        {13,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_summon_sq; return tokens[0];}},
        // {14, {gtoken_echo_sq, {token_echo, token_par_esq, token_string, token_par_dir}}},
        {14,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_echo_sq; return tokens[0];}},
        // {15, {gtoken_echo_sq, {token_echo, token_par_esq, gtoken_id, token_par_dir}}},
        {15,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_echo_sq; return tokens[0];}},
        // {16, {gtoken_control, {gtoken_control_struc, gtoken_expression, gtoken_block}}},
        {16,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_control; return tokens[0];}},
        // {17, {gtoken_control_struc, {token_if}}},
        {17,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_control_struc; return tokens[0];}},
        // {18, {gtoken_control_struc, {token_while}}},
        {18,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_control_struc; return tokens[0];}},
        // {19, {gtoken_block, {token_chv_esq, gtoken_cmd_sq, token_chv_dir}}},
        {19,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_block; return tokens[0];}},
        // {20, {gtoken_expression, {token_par_esq, gtoken_logic, token_par_dir}}},
        {20,[this](std::vector<t_token> tokens)  ->  t_token { tokens[0].type = gtoken_expression; return tokens[0];}},
        // {21, {gtoken_logic, {gtoken_logic, gtoken_op_logic, gtoken_bool_op}}},
        /////////////////
        // {22, {gtoken_logic, {gtoken_bool_op}}},
        {22, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {23, {gtoken_bool_op, {gtoken_relacional}}},
        {23, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {24, {gtoken_bool_op, {token_not, gtoken_relacional}}},
        {24, [this](std::vector<t_token> tokens) -> t_token { return tokens[1]; }},
        // {25, {gtoken_relacional, {gtoken_relacional, gtoken_op_rel, gtoken_relacional_op}}},
        ///////////////////// so int
        // {26, {gtoken_relacional, {gtoken_relacional_op}}},
        {26, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {27, {gtoken_relacional_op, {gtoken_expr}}},
        {27, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {28, {gtoken_relacional_op, {token_par_esq, gtoken_relacional, token_par_dir}}},
        {28, [this](std::vector<t_token> tokens) -> t_token { return tokens[1]; }},
        // {29, {gtoken_expr, {gtoken_expr, gtoken_op_art_pr, gtoken_term}}},
        ////////////
        // {30, {gtoken_expr, {gtoken_term}}},
        {30, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {31, {gtoken_term, {gtoken_term, gtoken_op_art_sc, gtoken_factor}}},
        //////////
        // {32, {gtoken_term, {gtoken_factor}}},
        {32, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {33, {gtoken_factor, {token_par_esq, gtoken_expr, token_par_dir}}},
        {33, [this](std::vector<t_token> tokens) -> t_token { return tokens[1]; }},
        // {34, {gtoken_factor, {gtoken_value}}},
        {34, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {35, {gtoken_factor, {gtoken_id}}},
        {35, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {36, {gtoken_id, {token_id}}}, // gtoken_id.value = token_id.data
        {36, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = getSymbolType(tokens[0].data); return tokens[0]; }},
        // {37, {gtoken_id, {token_id, token_col_esq, token_int, token_col_dir}}},
        {37, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = getSymbolType(tokens[0].data); return tokens[0]; }},
        // {38, {gtoken_op_logic, {token_and}}},
        {38, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_op_logic; return tokens[0]; }},
        // {39, {gtoken_op_logic, {token_or}}},
        {39, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_op_logic; return tokens[0]; }},
        // {40, {gtoken_op_rel, {token_gr}}},
        {40, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_op_rel; return tokens[0]; }},
        // {41, {gtoken_op_rel, {token_le}}},
        {41, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_op_rel; return tokens[0]; }},
        // {42, {gtoken_op_rel, {token_eq}}},
        {42, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_op_rel; return tokens[0]; }},
        // {43, {gtoken_op_art_pr, {token_add}}},
        {43, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_op_art_pr; return tokens[0]; }},
        // {44, {gtoken_op_art_pr, {token_sub}}},
        {44, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_op_art_pr; return tokens[0]; }},
        // {45, {gtoken_op_art_sc, {token_mul}}},
        {45, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_op_art_sc; return tokens[0]; }},
        // {46, {gtoken_op_art_sc, {token_div}}},
        {46, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_op_art_sc; return tokens[0]; }},
        // {47, {gtoken_value, {token_int}}},
        {47, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {48, {gtoken_value, {token_float}}},
        {48, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {49, {gtoken_value, {token_string}}},
        {49, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {50, {gtoken_type, {token_type_int}}},
        {50, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = token_int; return tokens[0]; }},
        // {51, {gtoken_type, {token_type_int, token_col_esq, token_int, token_col_dir}}},
        {51, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = token_int; return tokens[0]; }},
        // {52, {gtoken_type, {token_type_float}}},
        {52, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = token_float; return tokens[0]; }},
        // {53, {gtoken_type, {token_type_float, token_col_esq, token_int, token_col_dir}}},
        {53, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = token_float; return tokens[0]; }},
        // {54, {gtoken_type, {token_type_string}}},
        {54, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = token_string; return tokens[0]; }},
        // {55, {gtoken_declare_sq, {gtoken_type, token_id, token_endline}}},
        {55,[this](std::vector<t_token> tokens)  ->  t_token { insertSymbol(tokens[1].data, tokens[0].type); tokens[0].type = gtoken_declare_sq; return tokens[0];}},
        // {56, {gtoken_declare_sq, {gtoken_type, token_id, token_atr, gtoken_value, token_endline}}},
        {56,[this](std::vector<t_token> tokens)  ->  t_token { checkAssignment(tokens[0], tokens[3]); insertSymbol(tokens[1].data, tokens[0].type); tokens[0].type = gtoken_declare_sq; return tokens[0];}},
        // {57, {gtoken_id, {token_id, token_col_esq, token_id, token_col_dir}}},
        {57, [this](std::vector<t_token> tokens) -> t_token { return tokens[0]; }},
        // {58, {gtoken_cmd_sq, {gtoken_operation, token_endline}}},
        {58, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_cmd_sq; return tokens[0]; }},
        // {59, {gtoken_cmd_sq, {}}},
        { 59, [this](std::vector<t_token> tokens) -> t_token { return t_token{gtoken_cmd_sq}; } },
        // {60, {gtoken_block, {token_chv_esq, token_chv_dir}}},
        {60, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_block; return tokens[0]; }},
        // {61, {gtoken_cmd_init, {token_ingredients, token_chv_esq, gtoken_declare_sq, token_chv_dir}}},
        {61, [this](std::vector<t_token> tokens) -> t_token { tokens[0].type = gtoken_cmd_init; return tokens[0]; }},
    };
}

void Semantico::readTable() {
    std::cout << "Reading table" << std::endl;
    std::cout << symbolTable.size() << " variables" << std::endl;
    for (auto& entry : symbolTable) {
        std::cout << entry.first << " is a " << entry.second << std::endl;
    }
}

token_type Semantico::Coercion(t_token left, t_token right) {
    if(left.type == right.type){
        return left.type;
    }
    
}

token_type Semantico::getSymbolType(std::string name) {
    if (symbolTable.find(name) != symbolTable.end()) {
        return symbolTable[name];
    }
    std::cout << "ERROR: symbol " << name << " not found" << std::endl;
    return token_id;
}

bool Semantico::insertSymbol(std::string name, token_type type) {
    std::cout << "inserting " << name << std::endl;
    if (symbolTable.find(name) == symbolTable.end()) {
        symbolTable.insert({ name, type });
        return true;
    }
    std::cout << "ERROR: symbol " << name << " already exists" << std::endl;
    return false;
}

bool Semantico::checkAssignment(t_token left, t_token right) {
    if (left.type == right.type) {
        return true;
    }
    else {
        std::cout << "ERROR: type mismatch at " << left.line << " " << left.col << " " << left.data << " " << left.data << std::endl;
        // cout << "inesperado: " << get_token_type_name(source) << " l:" << tokens[ip].line << " c:" << tokens[ip].col << " info:" << tokens[ip].data << endl;
    }
    return left.type == right.type;
}

