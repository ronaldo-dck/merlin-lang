# Analisador Semântico e gerador de código ETAC para Merlin-Lang

O analisador semântico se encontra no arquivo `semantico.cpp`, ele é executado a partir do analisador sintático, que se encontra no arquivo `sintatico.cpp`. Os demais arquivos `tokens`, `utils`, `productions` e `state_table` contém estruturas essenciais para o funcionamento do programa principal.

A compilação do código pode ser realizada através da linha de execução:

`g++ sintatico.cpp -o sintatico.x`

O executável gerado toma por padrão a leitura do arquivo `overview.ml`, o que pode ser alterado por meio do primeiro parâmetro da linha de execução, por exemplo:

`./sintatico.x erro.ml`

A saída de código ETAC é gerada por padrão no arquivo `output.etac`, mas pode ser alterada como o segundo argumento de execução, por exemplo:

`./sintatico.x erro.ml erro.etac`