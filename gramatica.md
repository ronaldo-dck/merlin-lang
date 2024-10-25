
program ->  tome id_puro {cmd_init}
cmd_init -> ingredients-sq cmd-sq; | cmd-sq;cmd-sq
ingredients-sq -> ingredients {declare-sq;declare-sq}
declare-sq -> type id_puro | type assign-sq | λ
type -> type_int | type_int[int] | type_float | type_float[int] | type_string

assign-sq -> id : value
value -> int | float | string





EXPRESSÔES LÓGICAS <- `| & !`

L ->  L & B | L | B 
B -> R | !R | (L) | !(L)

ada & !5+19 < ada | ada


`exemplos lógicos: `
* ada & !ada
* ada & !ada | ada
* complic & ada


EXPRESSÔES RELACIONAIS <- `= > <`

R ->  R > P | R < P | R = P 
P -> E | (R) 

`exemplos relacionais: `
* ada > (ada > ada) < ada
* (7+3) > 8
* ada > ada < ada 
* ada > ada > ada 
* ada > (ada > ada)


EXPRESSÔES ARITMÉTICAS <- `+ - * /`


E -> E + T | E - T | T 
T -> T * F | T / F | F
F -> (E) | num | id


GRAMATICA DE IDS

id -> id_puro | id[E]



`exemplos aritmética: `
* 5 + 1
* 3 + 5 * 2 / 4 - (9 * 2)
* 3 + 5 * 2 / 4 - 9 * 2
* 3 + 5 * 2 / 4 - 9 + 2


E --> E - T --> E - F --> E - (E) --> E - (T) --> E - (T * F)  --> E - (9 * 2)

E --> E + T --> E + T/F --> E + T*F/F - (9 * 2)

3 + 5 * 2 / 4 - (9 * 2)