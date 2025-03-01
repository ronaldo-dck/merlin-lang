
// MyClass.cpp
#include "semantico.h"
#include "utils.h"
#include <iostream>

#define LAMBDAFUNC [this](std::vector<t_token> tokens)

t_token Semantico::execute(int next_state, std::vector<t_token> tokens) {
    t_token token = actions[next_state](tokens);
    code[next_state](tokens);
    return token;
}

Semantico::Semantico() {
    // Constructor implementation
    actions = {
        // {0, {gtoken_program, {token_tome, token_id, token_chv_esq, gtoken_cmd_init, token_chv_dir}}},
        { 0,LAMBDAFUNC->t_token { tokens[0].type = gtoken_program; return tokens[0]; }},
        // {1, {gtoken_cmd_init, {token_ingredients, token_chv_esq, gtoken_declare_sq, token_chv_dir, gtoken_cmd_sq}}},
        { 1,LAMBDAFUNC->t_token { tokens[0].type = gtoken_cmd_init; return tokens[0]; }},
        // {2, {gtoken_cmd_init, {gtoken_cmd_sq}}},
        { 2,LAMBDAFUNC->t_token { tokens[0].type = gtoken_cmd_sq; return tokens[0]; }},
        // {3, {gtoken_declare_sq, {gtoken_type, token_id, token_endline, gtoken_declare_sq}}},
        { 3,LAMBDAFUNC->t_token { insertSymbol(tokens[1].data, tokens[0].type); tokens[0].type = gtoken_declare_sq; return tokens[0];}},
        // {4, {gtoken_declare_sq, {gtoken_type, token_id, token_atr, gtoken_value, token_endline, gtoken_declare_sq}}},
        { 4,LAMBDAFUNC->t_token { checkAssignment(tokens[0], tokens[3]); insertSymbol(tokens[1].data, tokens[0].type); tokens[0].type = gtoken_declare_sq; return tokens[0];}},
        // {5, {gtoken_cmd_sq, {gtoken_operation, token_endline, gtoken_cmd_sq}}},
        { 5,LAMBDAFUNC->t_token { tokens[0].type = gtoken_cmd_sq; return tokens[0];}},
        // {6, {gtoken_operation, {gtoken_assign_sq}}},
        { 6,LAMBDAFUNC->t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {7, {gtoken_operation, {gtoken_control}}},
        { 7,LAMBDAFUNC->t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {8, {gtoken_operation, {gtoken_for_sq}}},
        { 8,LAMBDAFUNC->t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {9, {gtoken_operation, {gtoken_summon_sq}}},
        { 9,LAMBDAFUNC->t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {10, {gtoken_operation, {gtoken_echo_sq}}},
        {10,LAMBDAFUNC->t_token { tokens[0].type = gtoken_operation; return tokens[0];}},
        // {11, {gtoken_assign_sq, {token_id, token_atr, gtoken_logic}}},
        {11,LAMBDAFUNC->t_token { tokens[0].type = getSymbolType(tokens[0].data); checkAssignment(tokens[0], tokens[2]); return tokens[0];}},
        // {12, {gtoken_for_sq, {token_for, token_par_esq, gtoken_assign_sq, token_endline, gtoken_logic, token_endline, token_int, token_par_dir, gtoken_block}}},
        {12,LAMBDAFUNC->t_token { tokens[0].type = gtoken_for_sq; return tokens[0];}},
        // {13, {gtoken_summon_sq, {token_summon, token_par_esq, gtoken_id, token_par_dir}}},
        {13,LAMBDAFUNC->t_token { tokens[0].type = gtoken_summon_sq; return tokens[0];}},
        // {14, {gtoken_echo_sq, {token_echo, token_par_esq, token_string, token_par_dir}}},
        {14,LAMBDAFUNC->t_token { tokens[0].type = gtoken_echo_sq; return tokens[0];}},
        // {15, {gtoken_echo_sq, {token_echo, token_par_esq, gtoken_id, token_par_dir}}},
        {15,LAMBDAFUNC->t_token { tokens[0].type = gtoken_echo_sq; return tokens[0];}},
        // {16, {gtoken_control, {gtoken_control_struc, gtoken_expression, gtoken_block}}},
        {16,LAMBDAFUNC->t_token { tokens[0].type = gtoken_control; return tokens[0];}},
        // {17, {gtoken_control_struc, {token_if}}},
        {17,LAMBDAFUNC->t_token { tokens[0].type = gtoken_control_struc; return tokens[0];}},
        // {18, {gtoken_control_struc, {token_while}}},
        {18,LAMBDAFUNC->t_token { tokens[0].type = gtoken_control_struc; return tokens[0];}},
        // {19, {gtoken_block, {token_chv_esq, gtoken_cmd_sq, token_chv_dir}}},
        {19,LAMBDAFUNC->t_token { tokens[0].type = gtoken_block; return tokens[0];}},
        // {20, {gtoken_expression, {token_par_esq, gtoken_logic, token_par_dir}}},
        {20,LAMBDAFUNC->t_token { tokens[0].type = gtoken_expression; return tokens[0];}},
        // {21, {gtoken_logic, {gtoken_logic, gtoken_op_logic, gtoken_bool_op}}},
        {21,LAMBDAFUNC->t_token { tokens[0].type = BoolCoercion(tokens[0], tokens[2]); return tokens[0]; }},
        // {22, {gtoken_logic, {gtoken_bool_op}}},
        {22,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {23, {gtoken_bool_op, {gtoken_relacional}}},
        {23,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {24, {gtoken_bool_op, {token_not, gtoken_relacional}}},
        {24,LAMBDAFUNC->t_token { return tokens[1]; }},
        // {25, {gtoken_relacional, {gtoken_relacional, gtoken_op_rel, gtoken_relacional_op}}},
        {25,LAMBDAFUNC->t_token { tokens[0].type = BoolCoercion(tokens[0], tokens[2]); return tokens[0]; }},
        // {26, {gtoken_relacional, {gtoken_relacional_op}}},
        {26,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {27, {gtoken_relacional_op, {gtoken_expr}}},
        {27,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {28, {gtoken_relacional_op, {token_par_esq, gtoken_relacional, token_par_dir}}},
        {28,LAMBDAFUNC->t_token { return tokens[1]; }},
        // {29, {gtoken_expr, {gtoken_expr, gtoken_op_art_pr, gtoken_term}}},
        {29,LAMBDAFUNC->t_token { tokens[0].type = Coercion(tokens[0], tokens[2]); return tokens[0]; }},
        // {30, {gtoken_expr, {gtoken_term}}},
        {30,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {31, {gtoken_term, {gtoken_term, gtoken_op_art_sc, gtoken_factor}}},
        {31,LAMBDAFUNC->t_token { tokens[0].type = Coercion(tokens[0], tokens[2]); return tokens[0]; }},
        // {32, {gtoken_term, {gtoken_factor}}},
        {32,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {33, {gtoken_factor, {token_par_esq, gtoken_expr, token_par_dir}}},
        {33,LAMBDAFUNC->t_token { return tokens[1]; }},
        // {34, {gtoken_factor, {gtoken_value}}},
        {34,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {35, {gtoken_factor, {gtoken_id}}},
        {35,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {36, {gtoken_id, {token_id}}}, // gtoken_id.value = token_id.data
        {36,LAMBDAFUNC->t_token { tokens[0].type = getSymbolType(tokens[0].data); return tokens[0]; }},
        // {37, {gtoken_id, {token_id, token_col_esq, token_int, token_col_dir}}},
        {37,LAMBDAFUNC->t_token { tokens[0].type = getSymbolType(tokens[0].data); return tokens[0]; }},
        // {38, {gtoken_op_logic, {token_and}}},
        {38,LAMBDAFUNC->t_token { tokens[0].type = gtoken_op_logic; return tokens[0]; }},
        // {39, {gtoken_op_logic, {token_or}}},
        {39,LAMBDAFUNC->t_token { tokens[0].type = gtoken_op_logic; return tokens[0]; }},
        // {40, {gtoken_op_rel, {token_gr}}},
        {40,LAMBDAFUNC->t_token { tokens[0].type = gtoken_op_rel; return tokens[0]; }},
        // {41, {gtoken_op_rel, {token_le}}},
        {41,LAMBDAFUNC->t_token { tokens[0].type = gtoken_op_rel; return tokens[0]; }},
        // {42, {gtoken_op_rel, {token_eq}}},
        {42,LAMBDAFUNC->t_token { tokens[0].type = gtoken_op_rel; return tokens[0]; }},
        // {43, {gtoken_op_art_pr, {token_add}}},
        {43,LAMBDAFUNC->t_token { tokens[0].type = gtoken_op_art_pr; return tokens[0]; }},
        // {44, {gtoken_op_art_pr, {token_sub}}},
        {44,LAMBDAFUNC->t_token { tokens[0].type = gtoken_op_art_pr; return tokens[0]; }},
        // {45, {gtoken_op_art_sc, {token_mul}}},
        {45,LAMBDAFUNC->t_token { tokens[0].type = gtoken_op_art_sc; return tokens[0]; }},
        // {46, {gtoken_op_art_sc, {token_div}}},
        {46,LAMBDAFUNC->t_token { tokens[0].type = gtoken_op_art_sc; return tokens[0]; }},
        // {47, {gtoken_value, {token_int}}},
        {47,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {48, {gtoken_value, {token_float}}},
        {48,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {49, {gtoken_value, {token_string}}},
        {49,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {50, {gtoken_type, {token_type_int}}},
        {50,LAMBDAFUNC->t_token { tokens[0].type = token_int; tokens[0].data = "1"; return tokens[0]; }},
        // {51, {gtoken_type, {token_type_int, token_col_esq, token_int, token_col_dir}}},
        {51,LAMBDAFUNC->t_token { tokens[0].type = token_int; tokens[0].data = tokens[2].data; return tokens[0]; }},
        // {52, {gtoken_type, {token_type_float}}},
        {52,LAMBDAFUNC->t_token { tokens[0].type = token_float; tokens[0].data = "1"; return tokens[0]; }},
        // {53, {gtoken_type, {token_type_float, token_col_esq, token_int, token_col_dir}}},
        {53,LAMBDAFUNC->t_token { tokens[0].type = token_float; tokens[0].data = tokens[2].data; return tokens[0]; }},
        // {54, {gtoken_type, {token_type_string}}},
        {54,LAMBDAFUNC->t_token { tokens[0].type = token_string; tokens[0].data = "1"; return tokens[0]; }},
        // {55, {gtoken_declare_sq, {gtoken_type, token_id, token_endline}}},
        {55,LAMBDAFUNC->t_token { insertSymbol(tokens[1].data, tokens[0].type); tokens[0].type = gtoken_declare_sq; return tokens[0];}},
        // {56, {gtoken_declare_sq, {gtoken_type, token_id, token_atr, gtoken_value, token_endline}}},
        {56,LAMBDAFUNC->t_token { checkAssignment(tokens[0], tokens[3]); insertSymbol(tokens[1].data, tokens[0].type); tokens[0].type = gtoken_declare_sq; return tokens[0];}},
        // {57, {gtoken_id, {token_id, token_col_esq, token_id, token_col_dir}}},
        {57,LAMBDAFUNC->t_token { return tokens[0]; }},
        // {58, {gtoken_cmd_sq, {gtoken_operation, token_endline}}},
        {58,LAMBDAFUNC->t_token { tokens[0].type = gtoken_cmd_sq; return tokens[0]; }},
        // {59, {gtoken_cmd_sq, {}}},
        { 59,LAMBDAFUNC->t_token { return t_token{gtoken_cmd_sq}; } },
        // {60, {gtoken_block, {token_chv_esq, token_chv_dir}}},
        {60,LAMBDAFUNC->t_token { tokens[0].type = gtoken_block; return tokens[0]; }},
        // {61, {gtoken_cmd_init, {token_ingredients, token_chv_esq, gtoken_declare_sq, token_chv_dir}}},
        {61,LAMBDAFUNC->t_token { tokens[0].type = gtoken_cmd_init; return tokens[0]; }},
    };

    code = {
        // {0, {gtoken_program, {token_tome, token_id, token_chv_esq, gtoken_cmd_init, token_chv_dir}}},
        {0,LAMBDAFUNC -> void {}},
        // {1, {gtoken_cmd_init, {token_ingredients, token_chv_esq, gtoken_declare_sq, token_chv_dir, gtoken_cmd_sq}}},
        {1,LAMBDAFUNC -> void {}},
        // {2, {gtoken_cmd_init, {gtoken_cmd_sq}}},
        {2,LAMBDAFUNC -> void {}},
        // {3, {gtoken_declare_sq, {gtoken_type, token_id, token_endline, gtoken_declare_sq}}},
        {3,LAMBDAFUNC  -> void {int index = std::stoi(tokens[0].data); for (int i = 0; i < index; i++) std::cout << tokens[1].data << "_" << i << ": " << get_type_TAC(tokens[0].type) << "= 0" << std::endl;}},
        // {4, {gtoken_declare_sq, {gtoken_type, token_id, token_atr, gtoken_value, token_endline, gtoken_declare_sq}}},
        {4,LAMBDAFUNC  -> void {tokens[0].type == token_string ? std::cout << tokens[1].data << ':' << get_type_TAC(tokens[0].type) << "=" << "\"" << tokens[3].data << "\"" << std::endl : std::cout << tokens[1].data << ':' << get_type_TAC(tokens[0].type) << "=" << tokens[3].data << std::endl;}},
        // {5, {gtoken_cmd_sq, {gtoken_operation, token_endline, gtoken_cmd_sq}}},
        {5,LAMBDAFUNC  -> void {}},
        // {6, {gtoken_operation, {gtoken_assign_sq}}},
        {6,LAMBDAFUNC  -> void {}},
        // {7, {gtoken_operation, {gtoken_control}}},
        {7,LAMBDAFUNC  -> void {}},
        // {8, {gtoken_operation, {gtoken_for_sq}}},
        {8,LAMBDAFUNC  -> void {}},
        // {9, {gtoken_operation, {gtoken_summon_sq}}},
        {9,LAMBDAFUNC  -> void {}},
        // {10, {gtoken_operation, {gtoken_echo_sq}}},
        {10,LAMBDAFUNC -> void {}},
        // {11, {gtoken_assign_sq, {token_id, token_atr, gtoken_logic}}},
        {11,LAMBDAFUNC -> void {}},
        // {12, {gtoken_for_sq, {token_for, token_par_esq, gtoken_assign_sq, token_endline, gtoken_logic, token_endline, token_int, token_par_dir, gtoken_block}}},
        {12,LAMBDAFUNC -> void {}},
        // {13, {gtoken_summon_sq, {token_summon, token_par_esq, gtoken_id, token_par_dir}}},
        {13,LAMBDAFUNC -> void {}},
        // {14, {gtoken_echo_sq, {token_echo, token_par_esq, token_string, token_par_dir}}},
        {14,LAMBDAFUNC -> void {}},
        // {15, {gtoken_echo_sq, {token_echo, token_par_esq, gtoken_id, token_par_dir}}},
        {15,LAMBDAFUNC -> void {}},
        // {16, {gtoken_control, {gtoken_control_struc, gtoken_expression, gtoken_block}}},
        {16,LAMBDAFUNC -> void {}},
        // {17, {gtoken_control_struc, {token_if}}},
        {17,LAMBDAFUNC -> void {}},
        // {18, {gtoken_control_struc, {token_while}}},
        {18,LAMBDAFUNC -> void {}},
        // {19, {gtoken_block, {token_chv_esq, gtoken_cmd_sq, token_chv_dir}}},
        {19,LAMBDAFUNC -> void {}},
        // {20, {gtoken_expression, {token_par_esq, gtoken_logic, token_par_dir}}},
        {20,LAMBDAFUNC -> void {}},
        // {21, {gtoken_logic, {gtoken_logic, gtoken_op_logic, gtoken_bool_op}}},
        {21,LAMBDAFUNC -> void {}},
        // {22, {gtoken_logic, {gtoken_bool_op}}},
        {22,LAMBDAFUNC -> void {}},
        // {23, {gtoken_bool_op, {gtoken_relacional}}},
        {23,LAMBDAFUNC -> void {}},
        // {24, {gtoken_bool_op, {token_not, gtoken_relacional}}},
        {24,LAMBDAFUNC -> void {}},
        // {25, {gtoken_relacional, {gtoken_relacional, gtoken_op_rel, gtoken_relacional_op}}},
        {25,LAMBDAFUNC -> void {}},
        // {26, {gtoken_relacional, {gtoken_relacional_op}}},
        {26,LAMBDAFUNC -> void {}},
        // {27, {gtoken_relacional_op, {gtoken_expr}}},
        {27,LAMBDAFUNC -> void {}},
        // {28, {gtoken_relacional_op, {token_par_esq, gtoken_relacional, token_par_dir}}},
        {28,LAMBDAFUNC -> void {}},
        // {29, {gtoken_expr, {gtoken_expr, gtoken_op_art_pr, gtoken_term}}},
        {29,LAMBDAFUNC -> void {}},
        // {30, {gtoken_expr, {gtoken_term}}},
        {30,LAMBDAFUNC -> void {}},
        // {31, {gtoken_term, {gtoken_term, gtoken_op_art_sc, gtoken_factor}}},
        {31,LAMBDAFUNC -> void {}},
        // {32, {gtoken_term, {gtoken_factor}}},
        {32,LAMBDAFUNC -> void {}},
        // {33, {gtoken_factor, {token_par_esq, gtoken_expr, token_par_dir}}},
        {33,LAMBDAFUNC -> void {}},
        // {34, {gtoken_factor, {gtoken_value}}},
        {34,LAMBDAFUNC -> void {}},
        // {35, {gtoken_factor, {gtoken_id}}},
        {35,LAMBDAFUNC -> void {}},
        // {36, {gtoken_id, {token_id}}}, // gtoken_id.value = token_id.data
        {36,LAMBDAFUNC -> void {}},
        // {37, {gtoken_id, {token_id, token_col_esq, token_int, token_col_dir}}},
        {37,LAMBDAFUNC -> void {}},
        // {38, {gtoken_op_logic, {token_and}}},
        {38,LAMBDAFUNC -> void {}},
        // {39, {gtoken_op_logic, {token_or}}},
        {39,LAMBDAFUNC -> void {}},
        // {40, {gtoken_op_rel, {token_gr}}},
        {40,LAMBDAFUNC -> void {}},
        // {41, {gtoken_op_rel, {token_le}}},
        {41,LAMBDAFUNC -> void {}},
        // {42, {gtoken_op_rel, {token_eq}}},
        {42,LAMBDAFUNC -> void {}},
        // {43, {gtoken_op_art_pr, {token_add}}},
        {43,LAMBDAFUNC -> void {}},
        // {44, {gtoken_op_art_pr, {token_sub}}},
        {44,LAMBDAFUNC -> void {}},
        // {45, {gtoken_op_art_sc, {token_mul}}},
        {45,LAMBDAFUNC -> void {}},
        // {46, {gtoken_op_art_sc, {token_div}}},
        {46,LAMBDAFUNC -> void {}},
        // {47, {gtoken_value, {token_int}}},
        {47,LAMBDAFUNC -> void {}},
        // {48, {gtoken_value, {token_float}}},
        {48,LAMBDAFUNC -> void {}},
        // {49, {gtoken_value, {token_string}}},
        {49,LAMBDAFUNC -> void {}},
        // {50, {gtoken_type, {token_type_int}}},
        {50,LAMBDAFUNC -> void {}},
        // {51, {gtoken_type, {token_type_int, token_col_esq, token_int, token_col_dir}}},
        {51,LAMBDAFUNC -> void {}},
        // {52, {gtoken_type, {token_type_float}}},
        {52,LAMBDAFUNC -> void {}},
        // {53, {gtoken_type, {token_type_float, token_col_esq, token_int, token_col_dir}}},
        {53,LAMBDAFUNC -> void {}},
        // {54, {gtoken_type, {token_type_string}}},
        {54,LAMBDAFUNC -> void {}},
        // {55, {gtoken_declare_sq, {gtoken_type, token_id, token_endline}}},
        { 55,LAMBDAFUNC -> void {int index = std::stoi(tokens[0].data); for (int i = 0; i < index; i++) std::cout << tokens[1].data << "_" << i << ": " << get_type_TAC(tokens[0].type) << "= 0" << std::endl;} },
        // {56, {gtoken_declare_sq, {gtoken_type, token_id, token_atr, gtoken_value, token_endline}}},
        {56,LAMBDAFUNC -> void {tokens[0].type == token_string ? std::cout << tokens[1].data << ':' << get_type_TAC(tokens[0].type) << "=" << "\"" << tokens[3].data << "\"" << std::endl : std::cout << tokens[1].data << ':' << get_type_TAC(tokens[0].type) << "=" << tokens[3].data << std::endl;}},
        // {57, {gtoken_id, {token_id, token_col_esq, token_id, token_col_dir}}},
        {57,LAMBDAFUNC -> void {}},
        // {58, {gtoken_cmd_sq, {gtoken_operation, token_endline}}},
        {58,LAMBDAFUNC -> void {}},
        // {59, {gtoken_cmd_sq, {}}},
        {59,LAMBDAFUNC -> void {}},
        // {60, {gtoken_block, {token_chv_esq, token_chv_dir}}},
        {60,LAMBDAFUNC -> void {}},
        // {61, {gtoken_cmd_init, {token_ingredients, token_chv_esq, gtoken_declare_sq, token_chv_dir}}},
        {61,LAMBDAFUNC -> void {}},
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
    if (left.type == right.type) {
        return left.type;
    }

    if (left.type == token_string || right.type == token_string) {
        throw std::runtime_error("ERROR: cannot coerce string");
    }

    if (left.type == token_float || right.type == token_float) {
        return token_float;
    }
    return token_int;
}

token_type Semantico::BoolCoercion(t_token left, t_token right) {
    if (left.type == token_string || right.type == token_string) {
        throw std::runtime_error("ERROR: cannot coerce string");
    }

    return token_int;
}

token_type Semantico::getSymbolType(std::string name) {
    if (symbolTable.find(name) != symbolTable.end()) {
        return symbolTable[name];
    }
    std::cout << "ERROR: symbol " << name << " not found" << std::endl;
    success = false;
    return token_id;
}

bool Semantico::insertSymbol(std::string name, token_type type) {
    if (symbolTable.find(name) == symbolTable.end()) {
        symbolTable.insert({ name, type });
        return true;
    }
    std::cout << "ERROR: symbol " << name << " already exists" << std::endl;
    success = false;
    return false;
}

bool Semantico::checkAssignment(t_token left, t_token right) {
    if (left.type == right.type) {
        return true;
    }
    else {
        std::cout << "ERROR: type mismatch at line" << left.line << " col" << left.col << " data: " << left.data << " " << right.data << std::endl;
        success = false;
    }
    return left.type == right.type;
}

