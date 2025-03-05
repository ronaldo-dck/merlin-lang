// Arquivo: token.h
#ifndef TOKEN_H
#define TOKEN_H

#include <string>
#include <vector>

// Define a enumeração para os tipos de token
enum token_type {
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
    token_bool,
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

// Estrutura para representar um token com um tipo e um valor
struct t_token {
    token_type type;
    std::string data;
    int line;
    int col;
    int counter = 0;
    int index = 0;
};

// Estrutura para representar uma produção
struct prod {
    token_type red;                   // Tipo de token de redução
    std::vector<token_type> derivados; // Lista de tipos de token derivados
        
};

#endif // TOKEN_H
