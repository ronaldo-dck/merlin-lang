tome tomename {
    ingredients {
        int numero;
        float numero1 : 0.0;
        int num : 1;
        string num1 : "1";
        int[2] vetor;
        float[2] vetor2;
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

    _num : 10 * 11 + 12 < 13 * 14 + 15 & 10;
    _num : 12 + 13 * 14;
    _num : numero + 15;
    _num : numero + 16 + 17;
    _vetor[1] : vetor[0] + numero;
    numero : vetor[num] + vetor[numero];
    numero : numero + vetor[numero];
    numero : vetor[num] + numero;
    _numero1 : 1.1;
    _vetor[1] : 9;
    _vetor2[1] : 3.2;
    _vetor[num] : 9;
    _vetor2[num] : 3.2;

    _if (num = 10) {
    _    num : numero * 2;
    _};
_
    _while (num < 10 & num > 5) {
    _    num : (10 + 5) / 2;
    _};
}
