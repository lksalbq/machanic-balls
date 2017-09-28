# Mechanic Bouncing Balls - TP1
## Bouncing Ball - Task 1


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
* **ball.cpp ->** Implementação do objeto ball
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

> por enquanto somente esses arquivos estão sendo utilizados no programa, a medida que forem sendo incluídos e evoluídos, haverá uma breve descrição de cada.

## Diagrama de Classe - Task 3


## Gráfico do comportamento da bola

> O gráfico a seguir mostra o comportamento da bola a partir da saída exibida acima. Foi gerado usando o software "octave", que a partir de um script contido no arquivo plot_ball.m, cria o gráfico da bola saltando dentro do espaço, dado sua velocidade inicial e posições:

![alt text1][logo]

[logo]:https://gitlab.com/lksalbq/tp1-mechanic-balls/blob/master/img/grafico.png
