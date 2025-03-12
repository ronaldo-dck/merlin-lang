tome tomename {
    ingredients {
        int numero : 0;
        float naoinicializado;
        int[3] vetorexemplo;
        string texto : "abc";
        int i;
    }

    for (i : 0; i < 3; 1){
        numero = i * 10;
    };

_%

    summon(numero);
    naoinicializado : ~2.102 - numero; _  id : expr    ..... expr -> expr op term
    while(numero + 1 < 13 & numero > 0 ) {
        if (numero / 2 = 0) {
            numero : (numero) / 2;
        };
        if (numero / 2 > 0 | !naoinicializado) {
            numero : numero * (3 + 1);
        };
    };
    
_    @

    echo("numero = ");
    echo(numero);
}
