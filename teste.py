import pandas as pd


# Carregar o arquivo CSV
sintaxe_table = pd.read_csv('./sintatico/tabela .csv')

# Fazer uma cópia do DataFrame
st = sintaxe_table.copy()

# Remover colunas específicas 'BAR' e 'BAR2' (se existirem)
colunas_para_remover = ['BAR', 'BAR2']
st = st.drop(columns=[col for col in colunas_para_remover if col in st.columns])

# Remover colunas cujo nome começa com "Unnamed"
st = st.loc[:, ~st.columns.str.contains('^Unnamed')]

# Verificar o resultado das colunas após remoções
# print("Colunas após remoções:", st.columns)

with open("encode.cpp", "w+") as file:
    for i in range(len(st)):
        cmd = f"stateTable[{i}] = {"
        for c in st.columns:
            if c == 'I':
                continue
            if pd.notna(st.iloc[i][c]):
                print(st.iloc[i][c])
                cmd += 
        
        break