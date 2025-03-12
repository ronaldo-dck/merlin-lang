tome tomename {
    ingredients {
        int numero : 0;
        float num : 0.0;
        float naoinicializado;
        int[3] vetorexemplo : ~1;
        string texto : "abc";
        int i;
        _float i;
    }

    for (i : 0; i < 3; 1){
        numero : i * 10;
    };

_ erros semanticos
    _naoDeclarada : 1;
    _numero : num;
    _num : numero;
    _texto : "123";
    _vetorexemplo[3] : 10;
    _vetorexemplo[num] : 10;
    _num : numero / 2;

_ exemplo de alargamento
    num : numero / 2.0;
    numero : numero > 1;
    num : numero & 1;

    summon(numero);
    naoinicializado : ~2.102 - numero;
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
