# Mechanic Bouncing Balls - TP1
## Bouncing Ball

### Objetivo

> Este é um projeto da disciplina teoria e prática de programação da UnB do curso de computação. O objetivo principal é aprender e aplicar conceitos de orientação a objeto, construindo um simulador de uma bola (ou mais) caindo e saltando sob a gravidade dentro de um campo limitado.

### Requisitos
- O projeto é feito em C++ compilando no GCC 5.4.0
- OpenGL que pode ser instalado atraves do seguinte comando apt-get no linux:
```sh
$ sudo apt-get install freeglut3 freeglut3-dev
```

### Build
> O projeto contém um arquivo MakeFile que tem instruções para gerar o arquivo binário que executa o software. Atualmente somente o primeiro teste está funcional, que pode ser executado com a linha de comando:

```sh
$ make test-ball
$./test-ball
```
## Estrutura das Classes
* **simulation.h ->** Classe da simulação, que implementa dois métodos virtuais (step,display) que sõo implementados em suas classes filhas;
* **ball.h ->** Classe que define o objeto ball;
* **ball.cpp ->** Implementação do objeto ball;
* **springmass.h ->** Define a classe Mass (massa), Spring (mola) e SpringMass(relção mola -> massa);
* **springmass.cpp ->** Implementa as funções da Mass (massa), da Spring (mola) e da SpringMass de acordo com os parâmetros passados, calculando suas interações e posições.
* **test-ball.cpp ->** Arquivo main que inicia o programa, atualmente gera uma simples saída com as posições da bola em um loop passando dt para o método "step", dada a inicialização padrão da bola que é descrita no arquivo "ball.h", conforme o exemplo a seguir:

```sh
0.252 0.00051
0.255 4e-05
0.258 -0.00141
0.261 -0.00384
0.264 -0.00725
0.267 -0.01164
0.27 -0.01701
0.273 -0.02336
0.276 -0.03069
0.279 -0.039
0.282 -0.04829
0.285 -0.05856
0.288 -0.06981
0.291 -0.08204
```



## Diagrama de Classe

![|Solid](https://gitlab.com/lksalbq/tp1-mechanic-balls/raw/master/img/class_diagram.png)]

## Gráfico do comportamento da bola

> O gráfico a seguir mostra o comportamento da bola a partir da saída exibida acima. Foi gerado usando o software "octave", que a partir de um script contido no arquivo plot_ball.m, cria o gráfico da bola saltando dentro do espaço, dado sua velocidade inicial e posições:

![|Solid](https://gitlab.com/lksalbq/tp1-mechanic-balls/raw/master/img/grafico.png)


## SpringMass

### Objetivo

> Nesta parte do projeto, o objetivo principal é criar as massas da bola e suas funções, bem como a mola que ligará uma massa a outra e a classe SpringMass que consiste dessa relação massa1 -> mola -> massa2, para simular um oscilador harmônico amortecido.

> Para testar a SpringMass, é necessário rodar o comando make com o seguinte argumento:

```sh
$ make test-springmass
$./test-springmass
```
> Que irá gerar a saída, por exemplo:

```sh
-0.766667,0.465767
0.578333,-0.0009
-0.633333,0.529733
0.656667,0.0964
-0.5,0.5919
0.735,0.1919
-0.366667,0.652267
0.813333,0.2856
-0.233333,0.710833
0.891667,0.3775
-0.1,0.7676
```

## Gráfico de trajetória da SpringMass

> O gráfico a seguir mostra a trajetória da bola a partir da saída gera:

