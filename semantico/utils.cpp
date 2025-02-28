#include "utils.h"
#include <iostream>

// int soma(int a, int b) {
//     return a + b;
// }

// void mensagem() {
//     std::cout << "Olá do utils!" << std::endl;
// }

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
