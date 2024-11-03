# Definição da gramática e tabelas para o analisador SLR(1)
grammar = {
    "E": [["T", "E'"]],
    "E'": [["+", "T", "E'"], ["ε"]],
    "T": [["F", "T'"]],
    "T'": [["*", "F", "T'"], ["ε"]],
    "F": [["(", "E", ")"], ["id"]]
}

# Conjuntos First e Follow pré-calculados para a gramática
first_sets = {
    "E": {"(", "id"},
    "E'": {"+", "ε"},
    "T": {"(", "id"},
    "T'": {"*", "ε"},
    "F": {"(", "id"}
}

follow_sets = {
    "E": {"$", ")"},
    "E'": {"$", ")"},
    "T": {"+", "$", ")"},
    "T'": {"+", "$", ")"},
    "F": {"*", "+", "$", ")"}
}

# Definindo a tabela SLR(1) manualmente para essa gramática
parsing_table = {
    (0, "id"): ("s", 5),
    (0, "("): ("s", 4),
    (1, "+"): ("s", 6),
    (1, "$"): ("acc", None),
    (2, "+"): ("r", 2),
    (2, "*"): ("s", 7),
    (2, ")"): ("r", 2),
    (2, "$"): ("r", 2),
    (3, "+"): ("r", 4),
    (3, "*"): ("r", 4),
    (3, ")"): ("r", 4),
    (3, "$"): ("r", 4),
    (4, "id"): ("s", 5),
    (4, "("): ("s", 4),
    (5, "+"): ("r", 6),
    (5, "*"): ("r", 6),
    (5, ")"): ("r", 6),
    (5, "$"): ("r", 6),
    (6, "id"): ("s", 5),
    (6, "("): ("s", 4),
    (7, "id"): ("s", 5),
    (7, "("): ("s", 4),
    (8, "+"): ("s", 6),
    (8, ")"): ("s", None),
    (9, "+"): ("r", 1),
    (9, "*"): ("s", 7),
    (9, ")"): ("r", 1),
    (10, "+"): ("r", 3),
    (10, "*"): ("r", 3),
    (10, ")"): ("r", 3),
    (10, "$"): ("r", 3)
}

# Produções associadas a índices (usadas na tabela)
productions = {
    1: ("E", ["T", "E'"]),
    2: ("E'", ["+", "T", "E'"]),
    3: ("E'", ["ε"]),
    4: ("T", ["F", "T'"]),
    5: ("T'", ["*", "F", "T'"]),
    6: ("T'", ["ε"]),
    7: ("F", ["(", "E", ")"]),
    8: ("F", ["id"])
}

# Função para realizar a análise sintática usando a tabela SLR(1)
def parse(input_tokens):
    # Adiciona o símbolo de final de entrada $
    input_tokens.append("$")
    stack = [0]  # Estado inicial na pilha
    pointer = 0  # Ponteiro para os tokens de entrada

    while True:
        state = stack[-1]
        token = input_tokens[pointer]
        
        action = parsing_table.get((state, token))
        
        if not action:
            print(f"Erro de sintaxe no token '{token}' na posição {pointer}.")
            return False
        
        if action[0] == "s":
            # Shift: coloca o próximo estado na pilha
            stack.append(action[1])
            pointer += 1
        
        elif action[0] == "r":
            # Reduce: aplica uma produção e retira símbolos da pilha
            production = productions[action[1]]
            lhs, rhs = production
            if rhs != ["ε"]:  # Se não for produção vazia
                stack = stack[:-len(rhs)]
            goto_state = parsing_table.get((stack[-1], lhs))[1]
            stack.append(goto_state)
        
        elif action[0] == "acc":
            print("A entrada foi aceita pela gramática.")
            return True

# Exemplo de uso do analisador com uma expressão de entrada
input_tokens = ["id", "+", "id", "*", "id"]
parse(input_tokens)
