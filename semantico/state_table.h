// Arquivo: state_table.h
#ifndef STATE_TABLE_H
#define STATE_TABLE_H

#include <vector>
#include <map>
#include <string>
#include "token.h" // Incluindo o arquivo de tokens

// Define o tipo de dado para a stateTable
using StateTable = std::vector<std::map<token_type, std::string>>;

// Declara uma função para inicializar a stateTable
StateTable initStateTable();

#endif // STATE_TABLE_H
