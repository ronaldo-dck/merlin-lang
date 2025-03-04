tome tomename {
    ingredients {
        int numero : 0;  
        float naoinicializado : 0.0; 
        float[2] testeF;
        int[3] vetorexemplo;
        string texto : "abc";
        int i;
    }

    _ Exemplo de como preencher um vetor


_    echo("numero = ");
_    echo(numero);
_    i : 2;
_    echo(vetorexemplo[i]);
_    testeF[1] : 0.1;


    
    for (i : 2; i < 3; 1){
        echo(vetorexemplo[i]);
    };
_
__%
_
_    summon(numero);
_    naoinicializado : ~2.102 - numero; _  id : expr    ..... expr -> expr op term
_    while(numero + 1 < 13 & numero > 0 ) {
_        if (numero / 2 = 0) {
_            numero : (numero) / 2;
_        };
_        if (numero / 2 > 0 | !naoinicializado) {
_            numero : numero * (3 + 1);
_        };
_    };
_    
__    @
_
_    echo("numero = ");
_    echo(numero);
_    echo(vetorexemplo[1]);

}
