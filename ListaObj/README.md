O objetivo desse exercício é praticar alguns conceitos básicos de classes e objetos, bem como do container list da VPL.

Você deverá criar uma classe com um nome a sua escolha. Cada objeto dessa classe tem um atributo id do tipo inteiro. O valor desse campo deverá ser gerado de forma automática e incremental quando um novo objeto for criado (O primeiro objeto vai ter o id 1, o segundo o id 2, etc). Além disso, a sua classe deverá ter um atributo que conta o número de objetos existentes. Esse atributo deverá ser incrementado no construtor e decrementado do destrutor. Todos os atributos da sua classe devem ser privados. Sua classe deverá ter métodos para retornar o id de um objeto e também o número de objetos existentes no momento. Sua classe também deve ter um método que retorna o endereço de memória no qual o objeto está alocado.  

O seu programa principal deverá criar uma lista de objetos e receber comando para manipular essa lista. Mas especificamente, ele vai ser um  loop que lê comandos da entrada (A, R, C, P, L, E) juntamente com eventuais parâmetros e faz as operações de acordo. Para cada comando, o sistema imprime uma mensagem com uma quebra de linha (endln) no final. Importante: as mensagens devem ser exatamente como especificado abaixo para evitar erros na correção automática.  As operações são:

A: adiciona um novo objeto no final da lista. Deve ser impresso o id e o endereço de memória do objeto criado.

R: remove (e deleta) um objeto da frente da lista. Deve ser impresso o id e o endereço endereço de memória do objeto removido. Caso a lista esteja vazia deve ser impresso "ERRO"

C: imprime o valor do contador com número de objetos existentes.

P <n>: imprime o id e o endereço de memória do n-ésimo elemento da lista. Se n for um valor inválido (menor que 1 ou maior que o número de elementos) seu programa deverá imprimir "ERRO"

L: Imprime, para todos os elementos da lista, o id e o endereço de memória do objeto, sendo um elemento por linha com quebra de linha no final. 

E: termina a execução do programa.
