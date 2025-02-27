// Arquivo: actions.h
#ifndef ACTIONS_H
#define ACTIONS_H

#include <map>
#include <vector>
#include <functional>
#include "token.h"

// Define o tipo de dado para um mapa de ações
using ActionsMap = std::map<int, std::function<t_token(std::vector<t_token>)>>;

// Declara uma função para inicializar as ações
ActionsMap initActions();

#endif // ACTIONS_H
