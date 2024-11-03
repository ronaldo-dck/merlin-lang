// Arquivo: productions.h
#ifndef PRODUCTIONS_H
#define PRODUCTIONS_H

#include <map>
#include <vector>
#include "token.h" // Incluindo o arquivo de tokens

// Define o tipo de dado para um mapa de produções
using ProductionsMap = std::map<int, prod>;

// Declara uma função para inicializar as produções
ProductionsMap initProductions();

#endif // PRODUCTIONS_H
