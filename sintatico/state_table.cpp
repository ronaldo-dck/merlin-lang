// Arquivo: state_table.cpp
#include "state_table.h"

// Função para inicializar a stateTable
StateTable initStateTable() {
    StateTable stateTable(117); // Inicializa a stateTable com 114 mapas
  stateTable[0] = {
        {token_tome, "S2"},
        {gtoken_program, "1.0"}};
    stateTable[1] = {
        {gtoken_end, "ACEITA"}};
    stateTable[2] = {
        {token_id, "S3"},
        {token_type_string, " "}};
    stateTable[3] = {
        {token_chv_esq, "S4"}};
    stateTable[4] = {
        {token_ingredients, "S7"},
        {token_id, "S48"},
        {token_for, "S82"},
        {token_summon, "S91"},
        {token_echo, "S95"},
        {token_if, "S104"},
        {token_while, "S105"},
        {gtoken_cmd_init, "5.0"},
        {gtoken_cmd_sq, "113.0"},
        {gtoken_operation, "29.0"},
        {gtoken_assign_sq, "71.0"},
        {gtoken_for_sq, "73.0"},
        {gtoken_summon_sq, "74.0"},
        {gtoken_echo_sq, "75.0"},
        {gtoken_control, "72.0"},
        {gtoken_control_struc, "101.0"},
        {gtoken_id, "79.0"},
        {token_chv_dir, "R59"}};
    stateTable[5] = {
        {token_chv_dir, "S6"}};
    stateTable[6] = {
        {gtoken_end, "R0"}};
    stateTable[7] = {
        {token_chv_esq, "S8"},
        {token_summon, " "},
        {token_mul, " "}};
    stateTable[8] = {
        {token_type_int, "S22"},
        {token_type_float, "S18"},
        {token_type_string, "S17"},
        {gtoken_declare_sq, "26.0"},
        {gtoken_type, "9.0"}};
    stateTable[9] = {
        {token_id, "S10"}};
    stateTable[10] = {
        {token_endline, "S15"},
        {token_atr, "S11"}};
    stateTable[11] = {
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {gtoken_value, "12.0"}};
    stateTable[12] = {
        {token_endline, "S13"}};
    stateTable[13] = {
        {token_type_int, "S22"},
        {token_type_float, "S18"},
        {token_type_string, "S17"},
        {gtoken_declare_sq, "14.0"},
        {gtoken_type, "9.0"}, {token_chv_dir, "R56"}};
    stateTable[14] = {
        {token_chv_dir, "R4"}};
    stateTable[15] = {
        {token_type_int, "S22"},
        {token_type_float, "S18"},
        {token_type_string, "S17"},
        {gtoken_declare_sq, "16.0"},
        {gtoken_type, "9.0"}, {token_chv_dir, "R55"}};
    stateTable[16] = {
        {token_chv_dir, "R3"}};
    stateTable[17] = {
        {token_id, "R54"}};
    stateTable[18] = {
        {token_id, "R52"},
        {token_col_esq, "S19"}};
    stateTable[19] = {
        {token_int, "S20"}};
    stateTable[20] = {
        {token_col_dir, "S21"}};
    stateTable[21] = {
        {token_id, "R53"}};
    stateTable[22] = {
        {token_id, "R50"},
        {token_col_esq, "S23"}};
    stateTable[23] = {
        {token_int, "S24"}};
    stateTable[24] = {
        {token_col_dir, "S25"}};
    stateTable[25] = {
        {token_id, "R51"}};
    stateTable[26] = {
        {token_chv_dir, "S27"}};
    stateTable[27] = {
        {token_id, "S48"},
        {token_for, "S82"},
        {token_summon, "S91"},
        {token_echo, "S95"},
        {token_if, "S104"},
        {token_while, "S105"},
        {gtoken_cmd_sq, "28.0"},
        {gtoken_operation, "29.0"},
        {gtoken_assign_sq, "71.0"},
        {gtoken_for_sq, "73.0"},
        {gtoken_summon_sq, "74.0"},
        {gtoken_echo_sq, "75.0"},
        {gtoken_control, "72.0"},
        {gtoken_control_struc, "101.0"},
        {gtoken_id, "79.0"},
        {token_chv_dir, "R61"}};
    stateTable[28] = {
        {token_chv_dir, "R1"}};
    stateTable[29] = {
        {token_endline, "S30"}};
    stateTable[30] = {
        {token_id, "S48"},
        {token_for, "S82"},
        {token_summon, "S91"},
        {token_echo, "S95"},
        {token_if, "S104"},
        {token_while, "S105"},
        {gtoken_cmd_sq, "112.0"},
        {gtoken_operation, "29.0"},
        {gtoken_assign_sq, "71.0"},
        {gtoken_for_sq, "73.0"},
        {gtoken_summon_sq, "74.0"},
        {gtoken_echo_sq, "75.0"},
        {gtoken_control, "72.0"},
        {gtoken_control_struc, "101.0"},
        {gtoken_id, "79.0"},
        {token_chv_dir, "R58"}};
    stateTable[31] = {};
    stateTable[32] = {
        {token_id, "S48"},
        {token_par_esq, "S41"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {token_not, "S57"},
        {gtoken_logic, "33.0"},
        {gtoken_bool_op, "69"},
        {gtoken_relacional, "38.0"},
        {gtoken_relacional_op, "40.0"},
        {gtoken_expr, "39.0"},
        {gtoken_term, "49.0"},
        {gtoken_factor, "45.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"}};
    stateTable[33] = {
        {token_par_dir, "S70"},
        {token_and, "S34"},
        {token_or, "S35"},
        {gtoken_op_logic, "36.0"}};
    stateTable[34] = {
        {token_id, "R38"},
        {token_par_esq, "R38"},
        {token_int, "R38"},
        {token_float, "R38"},
        {token_string, "R38"},
        {token_not, "R38"}};
    stateTable[35] = {
        {token_id, "R39"},
        {token_par_esq, "R39"},
        {token_int, "R39"},
        {token_float, "R39"},
        {token_string, "R39"},
        {token_not, "R39"}};
    stateTable[36] = {
        {token_id, "S48"},
        {token_par_esq, "S41"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {token_not, "S57"},
        {gtoken_bool_op, "37"},
        {gtoken_relacional, "38.0"},
        {gtoken_relacional_op, "40.0"},
        {gtoken_expr, "39.0"},
        {gtoken_term, "49.0"},
        {gtoken_factor, "45.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"}};
    stateTable[37] = {
        {token_endline, "R21"},
        {token_par_dir, "R21"}};
    stateTable[38] = {
        {token_endline, "R23"},
        {token_par_dir, "R23"},
        {token_le, "S66"},
        {token_gr, "S67"},
        {token_eq, "S68"},
        {gtoken_op_rel, "106.0"},
        {token_or, "R23"},
        {token_and, "R23"}};
    stateTable[39] = {
        {token_endline, "R27"},
        {token_par_dir, "R27"},
        {token_and, "R27"},
        {token_or, "R27"},
        {token_le, "R27"},
        {token_gr, "R27"},
        {token_eq, "R27"},
        {token_add, "S59"},
        {token_sub, "S60"},
        {gtoken_op_art_pr, "61.0"}};
    stateTable[40] = {
        {token_endline, "R26"},
        {token_par_dir, "R26"},
        {token_and, "R26"},
        {token_or, "R26"},
        {token_le, "R26"},
        {token_gr, "R26"},
        {token_eq, "R26"}};
    stateTable[41] = {
        {token_par_esq, "S41"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {gtoken_relacional, "107.0"},
        {gtoken_relacional_op, "40.0"},
        {gtoken_expr, "108.0"},
        {gtoken_term, "49.0"},
        {gtoken_factor, "45.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"},
        {token_id, "S48"}};
    stateTable[42] = {
        {token_id, "R45"},
        {token_par_esq, "R45"},
        {token_int, "R45"},
        {token_float, "R45"},
        {token_string, "R45"}};
    stateTable[43] = {
        {token_endline, "R33"},
        {token_par_dir, "R33"},
        {token_and, "R33"},
        {token_or, "R33"},
        {token_le, "R33"},
        {token_gr, "R33"},
        {token_eq, "R33"},
        {token_add, "R33"},
        {token_sub, "R33"},
        {token_mul, "R33"},
        {token_div, "R33"}};
    stateTable[44] = {
        {token_id, "R46"},
        {token_par_esq, "R46"},
        {token_int, "R46"},
        {token_float, "R46"},
        {token_string, "R46"}};
    stateTable[45] = {
        {token_endline, "R32"},
        {token_par_dir, "R32"},
        {token_and, "R32"},
        {token_or, "R32"},
        {token_le, "R32"},
        {token_gr, "R32"},
        {token_eq, "R32"},
        {token_add, "R32"},
        {token_sub, "R32"},
        {token_mul, "R32"},
        {token_div, "R32"}};
    stateTable[46] = {
        {token_endline, "R34"},
        {token_par_dir, "R34"},
        {token_and, "R34"},
        {token_or, "R34"},
        {token_le, "R34"},
        {token_gr, "R34"},
        {token_eq, "R34"},
        {token_add, "R34"},
        {token_sub, "R34"},
        {token_mul, "R34"},
        {token_div, "R34"}};
    stateTable[47] = {
        {token_id, "S48"},
        {token_par_esq, "S109"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {gtoken_factor, "63.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"}};
    stateTable[48] = {
        {token_endline, "R36"},
        {token_atr, "R36"},
        {token_par_dir, "R36"},
        {token_and, "R36"},
        {token_or, "R36"},
        {token_le, "R36"},
        {token_gr, "R36"},
        {token_eq, "R36"},
        {token_add, "R36"},
        {token_sub, "R36"},
        {token_mul, "R36"},
        {token_div, "R36"},
        {token_col_esq, "S54"}};
    stateTable[49] = {
        {token_endline, "R30"},
        {token_par_dir, "R30"},
        {token_and, "R30"},
        {token_or, "R30"},
        {token_le, "R30"},
        {token_gr, "R30"},
        {token_eq, "R30"},
        {token_add, "R30"},
        {token_sub, "R30"},
        {token_mul, "S42"},
        {token_div, "S44"},
        {gtoken_op_art_sc, "47.0"}};
    stateTable[50] = {
        {token_endline, "R47"},
        {token_par_dir, "R47"},
        {token_and, "R47"},
        {token_or, "R47"},
        {token_le, "R47"},
        {token_gr, "R47"},
        {token_eq, "R47"},
        {token_add, "R47"},
        {token_sub, "R47"},
        {token_mul, "R47"}};
    stateTable[51] = {
        {token_endline, "R48"},
        {token_par_dir, "R48"},
        {token_and, "R48"},
        {token_or, "R48"},
        {token_le, "R48"},
        {token_gr, "R48"},
        {token_eq, "R48"},
        {token_add, "R48"},
        {token_sub, "R48"},
        {token_mul, "R48"},
        {token_div, "R48"}};
    stateTable[52] = {
        {token_endline, "R49"},
        {token_par_dir, "R49"},
        {token_and, "R49"},
        {token_or, "R49"},
        {token_le, "R49"},
        {token_gr, "R49"},
        {token_eq, "R49"},
        {token_add, "R49"},
        {token_sub, "R49"},
        {token_mul, "R49"},
        {token_div, "R49"}};
    stateTable[53] = {
        {token_endline, "R35"},
        {token_par_dir, "R35"},
        {token_and, "R35"},
        {token_or, "R35"},
        {token_le, "R35"},
        {token_gr, "R35"},
        {token_eq, "R35"},
        {token_add, "R35"},
        {token_sub, "R35"},
        {token_mul, "R35"},
        {token_div, "R35"}};
    stateTable[54] = {
        {token_id, "S114"},
        {token_int, "S55"}},
    stateTable[55] = {
        {token_col_dir, "S56"}};
    stateTable[56] = {
        {token_endline, "R37"},
        {token_atr, "R37"},
        {token_par_dir, "R37"},
        {token_and, "R37"},
        {token_or, "R37"},
        {token_le, "R37"},
        {token_gr, "R37"},
        {token_eq, "R37"},
        {token_add, "R37"},
        {token_sub, "R37"},
        {token_mul, "R37"},
        {token_div, "R37"}};
    stateTable[57] = {
        {token_id, "S48"},
        {token_par_esq, "S41"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {gtoken_relacional, "58.0"},
        {gtoken_relacional_op, "40.0"},
        {gtoken_expr, "39.0"},
        {gtoken_term, "49.0"},
        {gtoken_factor, "45.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"}};
    stateTable[58] = {
        {token_endline, "R24"},
        {token_par_dir, "R24"},
        {token_le, "S66"},
        {token_gr, "S67"},
        {token_eq, "S68"},
        {gtoken_op_rel, "106.0"}};
    stateTable[59] = {
        {token_id, "R43"},
        {token_par_esq, "R43"},
        {token_int, "R43"},
        {token_float, "R43"},
        {token_string, "R43"}};
    stateTable[60] = {
        {token_id, "R44"},
        {token_par_esq, "R44"},
        {token_int, "R44"},
        {token_float, "R44"},
        {token_string, "R44"}};
    stateTable[61] = {
        {token_id, "S48"},
        {token_par_esq, "S109"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {gtoken_term, "62.0"},
        {gtoken_factor, "45.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"}};
    stateTable[62] = {
        {token_endline, "R29"},
        {token_par_dir, "R29"},
        {token_and, "R29"},
        {token_or, "R29"},
        {token_le, "R29"},
        {token_gr, "R29"},
        {token_eq, "R29"},
        {token_add, "R29"},
        {token_sub, "R29"},
        {token_mul, "S42"},
        {token_div, "S44"},
        {gtoken_op_art_sc, "47.0"}};
    stateTable[63] = {
        {token_endline, "R31"},
        {token_par_dir, "R31"},
        {token_and, "R31"},
        {token_or, "R31"},
        {token_le, "R31"},
        {token_gr, "R31"},
        {token_eq, "R31"},
        {token_add, "R31"},
        {token_sub, "R31"},
        {token_mul, "R31"},
        {token_div, "R31"}};
    stateTable[64] = {
        {token_endline, "R25"},
        {token_par_dir, "R25"},
        {token_and, "R25"},
        {token_or, "R25"},
        {token_le, "R25"},
        {token_gr, "R25"},
        {token_eq, "R25"}};
    stateTable[65] = {
        {token_endline, "R28"},
        {token_par_dir, "R28"},
        {token_and, "R28"},
        {token_or, "R28"},
        {token_le, "R28"},
        {token_gr, "R28"},
        {token_eq, "R28"}};
    stateTable[66] = {
        {token_id, "R41"},
        {token_par_esq, "R41"},
        {token_int, "R41"},
        {token_float, "R41"},
        {token_string, "R41"}};
    stateTable[67] = {
        {token_id, "R40"},
        {token_par_esq, "R40"},
        {token_int, "R40"},
        {token_float, "R40"},
        {token_string, "R40"}};
    stateTable[68] = {
        {token_id, "R42"},
        {token_par_esq, "R42"},
        {token_int, "R42"},
        {token_float, "R42"},
        {token_string, "R42"}};
    stateTable[69] = {
        {token_endline, "R22"},
        {token_par_dir, "R22"},
        {token_and, "R22"},
        {token_or, "R22"},};
    stateTable[70] = {
        {token_chv_esq, "R20"}};
    stateTable[71] = {
        {token_endline, "R6"}};
    stateTable[72] = {
        {token_endline, "R7"}};
    stateTable[73] = {
        {token_endline, "R8"}};
    stateTable[74] = {
        {token_endline, "R9"}};
    stateTable[75] = {
        {token_endline, "R10"}};
    stateTable[76] = {
        {token_id, "S48"},
        {token_for, "S82"},
        {token_summon, "S91"},
        {token_echo, "S95"},
        {token_if, "S104"},
        {token_while, "S105"},
        {gtoken_cmd_sq, "77.0"},
        {gtoken_operation, "29.0"},
        {gtoken_assign_sq, "71.0"},
        {gtoken_for_sq, "73.0"},
        {gtoken_summon_sq, "74.0"},
        {gtoken_echo_sq, "75.0"},
        {gtoken_control, "72.0"},
        {gtoken_control_struc, "101.0"},
        {gtoken_id, "79.0"},
        {token_chv_dir, "S116"}};
    stateTable[77] = {
        {token_chv_dir, "S78"}};
    stateTable[78] = {
        {token_endline, "R19"}};
    stateTable[79] = {
        {token_atr, "S80"}};
    stateTable[80] = {
        {token_id, "S48"},
        {token_par_esq, "S41"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {token_not, "S57"},
        {gtoken_logic, "81.0"},
        {gtoken_bool_op, "69"},
        {gtoken_relacional, "38.0"},
        {gtoken_relacional_op, "40.0"},
        {gtoken_expr, "39.0"},
        {gtoken_term, "49.0"},
        {gtoken_factor, "45.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"}};
    stateTable[81] = {
        {token_and, "S34"},
        {token_or, "S35"},
        {gtoken_op_logic, "36.0"},
        {token_endline, "R11"}};
    stateTable[82] = {
        {token_par_esq, "S83"}};
    stateTable[83] = {
        {token_id, "S48"},
        {gtoken_assign_sq, "84.0"},
        {gtoken_id, "79.0"}};
    stateTable[84] = {
        {token_endline, "S85"}};
    stateTable[85] = {
        {token_id, "S48"},
        {token_par_esq, "S41"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {token_not, "S57"},
        {gtoken_logic, "86.0"},
        {gtoken_bool_op, "69"},
        {gtoken_relacional, "38.0"},
        {gtoken_relacional_op, "40.0"},
        {gtoken_expr, "39.0"},
        {gtoken_term, "49.0"},
        {gtoken_factor, "45.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"}};
    stateTable[86] = {
        {token_endline, "S87"},
        {token_and, "S34"},
        {token_or, "S35"},
        {gtoken_op_logic, "36.0"}};
    stateTable[87] = {
        {token_int, "S88"}};
    stateTable[88] = {
        {token_par_dir, "S89"}};
    stateTable[89] = {
        {token_chv_esq, "S76"},
        {gtoken_block, "90.0"}};
    stateTable[90] = {
        {token_endline, "R12"}};
    stateTable[91] = {
        {token_par_esq, "S92"},
        {gtoken_bool_op, " "}};
    stateTable[92] = {
        {token_id, "S48"},
        {gtoken_id, "93.0"}};
    stateTable[93] = {
        {token_par_dir, "S94"}};
    stateTable[94] = {
        {token_endline, "R13"}};
    stateTable[95] = {
        {token_par_esq, "S96"}};
    stateTable[96] = {
        {token_id, "S48"},
        {token_string, "S97"},
        {gtoken_id, "99.0"}};
    stateTable[97] = {
        {token_par_dir, "S98"}};
    stateTable[98] = {
        {token_endline, "R14"}};
    stateTable[99] = {
        {token_par_dir, "S100"}};
    stateTable[100] = {
        {token_endline, "R15"}};
    stateTable[101] = {
        {token_par_esq, "S32"},
        {gtoken_expression, "102.0"}};
    stateTable[102] = {
        {gtoken_block, "103.0"},
        {token_chv_esq, "S76"}};
    stateTable[103] = {
        {token_endline, "R16"}};
    stateTable[104] = {
        {token_par_esq, "R17"}};
    stateTable[105] = {
        {token_par_esq, "R18"}};
    stateTable[106] = {
        {token_id, "S48"},
        {token_par_esq, "S41"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {gtoken_relacional_op, "64.0"},
        {gtoken_expr, "39.0"},
        {gtoken_term, "49.0"},
        {gtoken_factor, "45.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"}};
    stateTable[107] = {
        {token_par_dir, "S65"},
        {token_le, "S66"},
        {token_gr, "S67"},
        {token_eq, "S68"},
        {gtoken_op_rel, "106.0"}};
    stateTable[108] = {
        {token_par_dir, "S43"},
        // {token_par_dir, "R27"},
        {token_add, "S59"},
        {token_sub, "S60"},
        {gtoken_op_art_pr, "61.0"},
        {token_endline, "R27"},
        {token_and, "R27"},
        {token_or, "R27"},
        {token_le, "R27"},
        {token_gr, "R27"},
        {token_eq, "R27"},
    };
    stateTable[109] = {
        {token_id, "S48"},
        {token_par_esq, "S109"},
        {token_int, "S50"},
        {token_float, "S51"},
        {token_string, "S52"},
        {gtoken_expr, "110.0"},
        {gtoken_term, "49.0"},
        {gtoken_factor, "45.0"},
        {gtoken_id, "53.0"},
        {gtoken_value, "46.0"}};
    stateTable[110] = {
        {token_par_dir, "S111"},
        {token_add, "S59"},
        {token_sub, "S60"},
        {gtoken_op_art_pr, "61.0"}};
    stateTable[111] = {
        {token_endline, "R33"},
        {token_par_dir, "R33"},
        {token_and, "R33"},
        {token_or, "R33"},
        {token_le, "R33"},
        {token_gr, "R33"},
        {token_eq, "R33"},
        {token_add, "R33"},
        {token_sub, "R33"},
        {token_mul, "R33"},
        {token_div, "R33"}};
    stateTable[112] = {
        {token_chv_dir, "R5"}};
    stateTable[113] = {
        {token_chv_dir, "R2"}};
    stateTable[114] = {
        {token_col_dir, "S115"},
    };
    stateTable[115] = {
    {token_endline, "R57"},
    {token_atr, "R57"},
    {token_par_dir, "R57"},
    {token_and, "R57"},
    {token_or, "R57"},
    {token_le, "R57"},
    {token_gr, "R57"},
    {token_eq, "R57"},
    {token_add, "R57"},
    {token_sub, "R57"},
    {token_mul, "R57"},
    {token_div, "R57"}
    };

    stateTable[116] = {
        {token_endline, "R60"}
    };

    return stateTable;
}
