# merlin-lang

Para compilação do analisador léxico, recomenda-se o uso do compilador g++ versão 17 ou superior.
```bash
g++ lexer.cpp -o lexer.x
```

A partir do executável, é possivel analisar o código da linguagem `Merlin`, passando rodando ele e passando como primeiro argumento o nome do arquivo, ou seu caminho.

```bash
./lexer.cpp [filename]
```

Ainda é possível passar a flag `--verbose`, para visualização da tabela de tokens, já sem os tokens ignorados



```bash
./lexer [filename] --verbose

#Resultado
<<              Tome, tome  >>
<<                ID, tomename  >>
<<        Left Brace,   >>
<<       Ingredients, ingredients  >>
<<        Left Brace,   >>
<<      Type Integer, int  >>
<<                ID, numero  >>
<<            Assign,   >>
<<           Integer, 0  >>
<<           Endline,   >>
<<        Type Float, float  >>
.
.
.
```

