tome tomename {
    ingredients {
        int numero;
        float numero1 : ~0.0;
        int num : ~1;
        string num1 : "1";
        int[2] vetor;
        float[2] vetor2;
        int i;
    }

    _echo("teste");
    _echo(num);
    _echo(numero1);
    _echo(num1);
    _echo(vetor[1]);
    _echo(vetor2[1]);
    _echo(vetor[num]);
    _echo(vetor2[num]);

    _summon(num);
    _summon(numero1);
    _summon(num1);
    _summon(vetor[1]);
    _summon(vetor2[1]);
    _summon(vetor[num]);
    _summon(vetor2[num]);

    _num : 10 * 11 < 13 * 14 & 10;
    _num : 0 & 10;
    _num : 12 + 13 * 14;
    _num : numero + 15;
    _num : numero + 16 + 17;
    _vetor[1] : vetor[0] + numero;
    _numero : vetor[num] + vetor[numero];
    _numero : numero + vetor[numero];
    _numero : vetor[num] + numero;
    _numero1 : 1.1;
    _vetor[1] : 9;
    vetor2[1] : 3.2;
    _vetor[num] : 9;
    vetor2[num] : 3.2;


    _for (i : 2; i < 3; 1){
    _    echo("oie");
    _    for (i : 2; i < 3; 2) {
    _        echo("tchau");
    _    };
    _};

    _if (num > 10 & num < 15 ) {
    _    if (numero < 10 | num > 10) {
    _        num1 : numero * 2;
    _    };
    _    echo("oi");
    _};
_
    _while (num > 10 & num < 15 ) {
    _    echo("oi");
    _    while(1) {
    _        echo("loop");
    _    };
    _};
}
