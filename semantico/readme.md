# Analisador sintático SLR1 para Merlin-Lang

O analisador sintático, juntamente ao léxico que o provê tokens, se encontram no arquivo `sintatico.cpp`. Os demais arquivos `tokens`, `productions` e `state_table`contém estruturas essenciais para o funcionamento do programa principal, fazendo-se necessária a seguinte linha de compilação: 

`g++ sintatico.cpp state_table.cpp productions.cpp token.h -o sintatico.x`

O executável gerado toma por padrão a leitura do arquivo `overview.ml`, o que pode ser alterado por meio do primeiro parâmetro da linha de execução, por exemplo:

`./sintatico.x erro.ml`