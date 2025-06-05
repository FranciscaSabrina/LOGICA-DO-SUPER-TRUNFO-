# LOGICA-DO-SUPER-TRUNFO-

# Objetivo Geral
O objetivo deste programa em linguagem C é simular uma comparação entre duas cartas do jogo Super Trunfo, com tema voltado para cidades brasileiras. Cada carta contém diversas informações sobre uma cidade, como população, área, PIB, entre outros. O programa permite comparar essas cartas com base em um atributo numérico e determina qual cidade vence de acordo com as regras definidas.

# Estrutura do Programa
O programa é dividido em três partes principais:
1. Estrutura struct CartaCidade
Define o molde para cada carta, com os seguintes atributos:
estado (char): letra de A a H representando o estado.
codigo (string): código da carta (ex: A01).
nomeCidade (string): nome da cidade.
populacao (int): número de habitantes.
area (float): área da cidade em km².
pib (float): Produto Interno Bruto da cidade (em bilhões).
pontosTuristicos (int): número de atrações turísticas.
densidadePopulacional (float): calculada como população / área.
pibPerCapita (float): calculado como PIB / população.
2. Funções Principais
lerCarta: Lê os dados digitados pelo usuário e preenche os campos da struct. Também realiza os cálculos de densidade populacional e PIB per capita.
exibirCarta: Mostra todos os dados de uma carta de forma organizada e legível.
3. Função main
É o corpo principal do programa. Suas responsabilidades são:
Chamar a função lerCarta para cadastrar duas cartas.
Exibir as cartas com exibirCarta.
Comparar as duas cartas com base em um único atributo, definido diretamente no código.
Exibir o resultado da comparação, mostrando:
Nome da cidade em cada carta.
Valor do atributo comparado.
Qual cidade venceu.

# Lógica de Comparação
O atributo de comparação é escolhido por meio da variável atributo. O código suporta 5 opções:
Valor da variável atributo	Atributo Comparado	Regra de Vitória
1	População	Vence a cidade com maior valor
2	Área	Vence a cidade com maior valor
3	PIB	Vence a cidade com maior valor
4	Densidade Populacional	Vence a cidade com menor valor
5	PIB per Capita	Vence a cidade com maior valor
A comparação é feita com estruturas de decisão if e if-else, como exige o desafio.

# Pontos de Destaque do Código
Utiliza struct para organizar os dados de cada cidade.
Permite cálculo de atributos derivados (densidade e PIB per capita).
Código limpo e bem comentado.
Comparação lógica com if simples, facilitando a leitura e aprendizado.
Pode ser facilmente expandido para adicionar mais cartas ou interações com o usuário.

# Possíveis Expansões
Permitir ao usuário escolher o atributo de comparação via menu.
Implementar várias rodadas de jogo.
Guardar pontuação dos jogadores.
Cadastrar várias cartas com listas ou arquivos.