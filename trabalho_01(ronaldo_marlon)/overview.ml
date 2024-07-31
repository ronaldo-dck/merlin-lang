tome tomename {
    ingredients {
        int numero : 0;
        float naoinicializado;
        int[3] vetorexemplo;
        string texto : "abc";
        int i;
    }

    _ Exemplo de como preencher um vetor
    for (i : 0; i < 3; 1){
        vetorexemplo[i] : 0;
    }

%

    summon(numero);
    naoinicializado : ~2.102 - numero;
    while(numero < 13 & numero > 0 ) {
        if (numero / 2 = 0) {
            numero : numero / 2;
        }
        if (numero / 2 > 0 | !naoinicializado) {
            numero : numero * 3 + 1;
        }
    }
    
_    @

    echo("numero = ");
    echo(numero);
}
