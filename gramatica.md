

<<bool-op>>        -> <<relacional>>
<<bool-op>>        -> !<<relacional>>
<<bool-op>>        -> (<<logic>>)
<<bool-op>>        -> !(<<logic>>)



<<relacional>>     -> <<relacional>> > <<relacional-op>> 
<<relacional>>      -> <<relacional>> < <<relacional-op>> 
<<relacional>>      -> <<relacional>> = <<relacional-op>> 
<<relacional>>      -> <<relacional-op>> 


<<expr>>           -> <<expr>> + <<term>> 
<<expr>>           ->  <<expr>> - <<term>> 
<<expr>>           ->  <<term>> 


<<term>>           -> <<term>> * <<factor>> 
<<term>>           -> <<term>> / <<factor>> 
<<term>>           ->  <<factor>>

<<factor>>         -> (<<expr>>) 
<<factor>>         ->int 
<<factor>>         -> float 
<<factor>>         -> <<id>>

===================================================

<<program>>        -> tome id_puro {<<cmd_init>>}
<<cmd_init>>       -> <<ingredients-sq>> <<cmd-sq>> | <<cmd-sq>>
<<ingredients-sq>> -> ingredients {<<declare-sq>>}
<<declare-sq>>    -> <<type>> id_puro;<<declare-sq>>| <<type>> id_puro: <<value>>;<<declare-sq >>| λ
<<type>>           -> type_int | type_int[int] | type_float | type_float[int] | type_string

<<cmd-sq>>         -> <<operation>>;<<cmd-sq>> | λ


<<operation>>      -> <<assign-sq>> | <<if-sq>> | <<while-sq>> | <<for-sq>> | <<summon-sq>> | <<echo-sq>>

<<assign-sq>>      -> <<id>> : <<logic>>
<<if-sq>>          -> if (<<logic>>) {<<cmd-sq>>}
<<while-sq>>       -> while (<<logic>>) {<<cmd-sq>>}
<<for-sq>>         -> for (<<assign-sq>>; <<logic>>; int) {<<cmd-sq>>}
<<summon-sq>>      -> summon(<<id>>) 
<<echo-sq>>        -> echo(string) | echo(<<id>>)
<<value>>          -> int | float | string

<<logic>>          -> <<logic>> & <<bool-op>> | <<logic>> `|` <<bool-op>> | <<bool-op>> 
<<bool-op>>        -> <<relacional>> | !<<relacional>> | (<<logic>>) | !(<<logic>>)

<<relacional>>     -> <<relacional>> > <<relacional-op>> | <<relacional>> < <<relacional-op>> | <<relacional>> = <<relacional-op>> | <<relacional-op>> 
<<relacional-op>>  -> <<expr>> | (<<relacional>>) 

<<expr>>           -> <<expr>> + <<term>> | <<expr>> - <<term>> | <<term>> 
<<term>>           -> <<term>> * <<factor>> | <<term>> / <<factor>> | <<factor>>
<<factor>>         -> (<<expr>>) | int | float | <<id>>

<<id>>             -> id_puro | <<id>>[<<expr>>]




EXPRESSÔES LÓGICAS <- `| & !`

<<logic>> ->  <<logic>> & <<bool-op>> | <<logic>> | <<bool-op>> 
<<bool-op>> -> <<relacional>> | !<<relacional>> | (<<logic>>) | !(<<logic>>)


ada & !5+19 < ada | ada


`exemplos lógicos: `
* ada & !ada
* ada & !ada | ada
* complic & ada


EXPRESSÔES RELACIONAIS <- `= > <`

<<relacional>> ->  <<relacional>> > <<relacional-op>> | <<relacional>> < <<relacional-op>> | <<relacional>> = <<relacional-op>> 
<<relacional-op>> -> <<expr>> | (relacional) 

`exemplos relacionais: `
* ada > (ada > ada) < ada
* (7+3) > 8
* ada > ada < ada 
* ada > ada > ada 
* ada > (ada > ada)


EXPRESSÔES ARITMÉTICAS <- `+ - * /`


E -> E + T | E - T | T 
T -> T * F | T / F | F
F -> (E) | num | <<id>>

<<expr>> -> <<expr>> + <<term>> | <<expr>> - <<term>> | <<term>> 
<<term>> -> <<term>> * <<factor>> | <<term>> / <<factor>> | <<factor>>
<<factor>> -> (<<expr>>) | num | <<id>>



GRAMATICA DE IDS

<<id>> -> id_puro | <<id>>[E]



`exemplos aritmética: `
* 5 + 1
* 3 + 5 * 2 / 4 - (9 * 2)
* 3 + 5 * 2 / 4 - 9 * 2
* 3 + 5 * 2 / 4 - 9 + 2


E --> E - T --> E - F --> E - (E) --> E - (T) --> E - (T * F)  --> E - (9 * 2)

E --> E + T --> E + T/F --> E + T*F/F - (9 * 2)

3 + 5 * 2 / 4 - (9 * 2)


•



s4
<<program>>    ─> tome id_puro {•<<cmd_init>>}
<<cmd_init>>      ─> •<<ingredients-sq>> <<cmd-sq>>
<<cmd_init>>      ─> •<<cmd-sq>>
<<ingredients-sq>>  ─> •ingredients {<<declare-sq>>}

<<cmd-sq>>     ─> •<<operation>>;<<cmd-sq>> 
<<operation>>  ─> •<<assign-sq>>
<<operation>>  ─> •<<if-sq>>
<<operation>>  ─> •<<while-sq>>
<<operation>>  ─> •<<for-sq>>
<<operation>>  ─> •<<summon-sq>>
<<operation>>  ─> •<<echo-sq>>

<<assign-sq>>   ─> •<<id>> : <<logic>>
<<if-sq>>      ─> •if (<<logic>>) {<<cmd-sq>>}
<<while-sq>>   ─> •while (<<logic>>) {<<cmd-sq>>}
<<for-sq>>     ─> •for (<<assign-sq>>; <<logic>>; int) {<<cmd-sq>>}
<<summon-sq>> ─> •summon(<<id>>)
<<echo-sq>> ─> •echo(string)
<<echo-sq>> ─> •echo(<<id>>)
<<id>>        ─> •id_puro
<<relacional>> 
<<id>>        ─> •<<id>>[<<expr>>]