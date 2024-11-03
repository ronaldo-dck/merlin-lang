
«program»        → "tome" "id_puro" {«cmd_init»}
«cmd_init»       → "ingredients" {«declare-sq»} «cmd-sq» | «cmd-sq»

«declare-sq»     → «type» "id_puro";«declare-sq»| «type» "id_puro": «value»;«declare-sq»| λ

«cmd-sq»         → «operation»;«cmd-sq» | λ

«operation»      → «assign-sq» | «control» | «for-sq» | «summon-sq» | «echo-sq»

«assign-sq»      → «id» : «logic»  
«for-sq»         → for («assign-sq»; «logic»; int) «block»

«summon-sq»      → summon(«id») 
«echo-sq»        → echo(string) | echo(«id»)

«control»        → «control-struc»  «expression» «block» 
«control-struc»  → if | while 

«block»          → {«cmd-sq»}

«expression»     → («logic»)

«logic»          → «logic» «op-logic» «bool-op» | «bool-op» 
«bool-op»        → «relacional» | !«relacional» 
«relacional»     → «relacional» «op-rel» «relacional-op» | «relacional-op» 
«relacional-op»  → «expr» | («relacional») 

«expr»           → «expr» «op-art-pr» «term» | «term» 
«term»           → «term» «op-art-sc» «factor» | «factor»
«factor»         → («expr») | «value» | «id» 


«id»             → id_puro | id_puro[«expr»]
«op-logic»       → '&' | '|' 
«op-rel»         → '>' | '<' | '='
«op-art-pr»      → + | -
«op-art-sc»      → * | /
«value»          → int | float | string
«type»           → type_int | type_int[int] | type_float | type_float[int] | type_string


•

===========================================================

«logic»          → «logic» «op-logic» «bool-op» | «bool-op» 
«bool-op»        → «relacional» | !«relacional» | «expression»  | !«expression» 

«relacional»     → «relacional» «op-rel» «relacional-op» | «relacional-op» 
«relacional-op»  → «expr» | («relacional») 

«expr»           → «expr» «op-art-pr» «term» | «term» 
«term»           → «term» «op-art-sc» «factor» | «factor»
«factor»         → («expr») | «value» | «id» 


«id»             → id_puro | «id»[«expr»]
«op-logic»       → '&' | '|' 
«op-rel»         → '>' | '<' | '='
«op-art-pr»      → + | -
«op-art-sc»      → * | /
«value»          → int | float | string
«type»           → type_int | type_int[int] | type_float | type_float[int] | type_string


s1
«expression»     → (•«logic»)
«logic»          → •«logic» «op-logic» «bool-op» 
«logic»          → •«bool-op» 
«bool-op»        → •«relacional» 
«bool-op»        → •!«relacional» 
«relacional»     → •«relacional» «op-rel» «relacional-op» 
«relacional»     → •«relacional-op» 
«relacional-op»  → •«expr» 
«relacional-op»  → •(«relacional»)
«expr»           → •«expr» «op-art-pr» «term» 
«expr»           → •term» 
«term»           → •«term» «op-art-sc» «factor» 
«term»           → •«factor»
«factor»         → •(«expr») 
«factor»         → •«value» 
«factor»         → •«id» 
«value»          → •int 
«value»          → •float 
«value»          → •string
«id»             → •id_puro 
«id»             → •«id»[«expr»]



s1
«expression»     → («logic»•)

s2
«expression»     → («logic»)•

s3
«logic»          → «logic» •«op-logic» «bool-op» 
«op-logic»       → •'&'  
«op-logic»       → •'|' 

s4
«logic»          → «logic» «op-logic» •«bool-op» 
«bool-op»        → •«relacional» 
«bool-op»        → •!«relacional» 
«bool-op»        → •«expression» 
«bool-op»        → •!«expression»
«expression»     → •(«logic») 
«relacional»     → •«relacional» «op-rel» «relacional-op» 
«relacional»     → •«relacional-op» 
«relacional-op»  → •«expr» 
«relacional-op»  → •(«relacional»)
«expr»           → •«expr» «op-art-pr» «term» 
«expr»           → •term» 
«term»           → •«term» «op-art-sc» «factor» 
«term»           → •«factor»
«factor»         → •(«expr») 
«factor»         → •«value» 
«factor»         → •«id» 
«value»          → •int 
«value»          → •float 
«value»          → •string
«id»             → •id_puro 
«id»             → •«id»[«expr»]


