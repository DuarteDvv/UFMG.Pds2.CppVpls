# Figuras
O objetivo desse exercício é praticar alguns conceitos básicos de classes e herança.

Você foi contratado para auxiliar no desenvolvimento de uma interface gráfica de um novo sistema operacional. Sua tarefa inicial é montar uma hierarquia de classes para representação de figuras geométricas e fazer alguns testes iniciais. 

Você deverá criar uma superclasse chamada FiguraGeometrica, e três classes herdeiras: Retângulo, Triângulo e Círculo. A sua superclasse deve ser uma classe abstrata. Ela possui os atributos inteiros x e y com as coordenadas do centro da figura geométrica e um método chamado "Desenha" que imprime essas coordenadas e que pode ser redefinido nas classes herdeiras. Além disso, a sua classe possui um método virtual puro chamado "CalculaArea" que calcula a área ocupada pelas figuras geométricas (retornando um valor float) e será implementado nas classes herdeiras.

A classe Retângulo tem como os atributos os dois lados do retângulo. O seu método Desenha chama o método da classe pai e depois imprime a palavra "RETANGULO". Já o seu método CalculaArea retorna a área do retângulo.

A classe Círculo tem como o atributo o raio do círculo. O seu método Desenha chama o método da classe pai e depois imprime a palavra "CIRCULO", e o seu método CalculaArea retorna a área do circulo.

Por fim, a classe Triângulo tem como atributos a base e altura do triangulo. O seu método Desenha chama o método da classe pai e depois imprime a palavra "TRIANGULO", e o seu método CalculaArea retorna a sua área.

Use adequadamente os modificadores de acesso (public, protected e private) em suas classes e implemente os métodos construtores e destrutores conforme necessário. 

O seu programa principal deverá armazenar um vetor de figuras geométricas e receber comandos para a sua manipulação. Mais especificamente, ele vai ser um  loop que lê comandos da entrada (R, C, T, D, A, E) juntamente com eventuais parâmetros e faz as operações de acordo.  Os comandos são:

R <C1> <C2> <L1> <L2>: Cria um retângulo com lados L1 e L2 com centro em C1, C2.

C <C1> <C2> <R>: Cria um círculo de raio R com centro em C1, C2.

T <C1> <C2> <B> <A>: Cria um triângulo de base B e altura A com centro em C1, C2.

D:  "Desenha" todas as figuras geométricas armazenadas, imprimindo as coordenadas do seu centro e o texto especificado para cada tipo.

A: calcula e imprime a área total ocupada por todas as figuras geométricas.

E: termina a execução do programa.
