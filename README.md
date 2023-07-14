
# Genius Geométrico

Como projeto da disciplina de Eletrônica para Computação BCC-ICMC, fizemos um jogo em uma placa Arduino Uno, utilizando também 4 botões e um display 8x8 Leds RGB.

# Funcionamento

O jogo funciona da seguinte maneira: O software gera uma imagem aleatória ao ter algum dos botões pressionados formada pelas 4 cores do jogo, o player tem 15 segundos para memorizar a imagem e determinar sua estratégia. Decorrido o tempo, o led apaga e o jogador tem 4 botões à sua disposição para tentar imitar a imagem gerada, quando ele termina de construir sua figura, os pixeis corretos piscam. 

Para reconstruir a imagem, o jogador dispôe de 4 botões: b1 gera uma linha vermelha descendente; b2 gera uma coluna roxa que se desloca da direita para a esquerda; b3 gera uma linha amarela ascendente e por fim, b4 gera uma coluna verde da esquerda para a direita.
As cores não se apagam.

Para controle dos LEDs utilizamos a biblioteca FastLED.

## Imagens

![Projeto-TinkerKad (1)](https://github.com/LVinaud/GeniusGeometrico/assets/128495824/baa43010-b67e-4109-b98d-a34967b11efd)
 Circuito TinkerCad
 
![imagemgenius](https://github.com/LVinaud/GeniusGeometrico/assets/128495824/4dcff247-2cc4-4a11-98ad-43a6ec978ed7)

![caixa](https://github.com/LVinaud/GeniusGeometrico/assets/128495824/9fe2a5bd-2f57-428f-a8a2-2bbe6ac5df79)

![caixa1](https://github.com/LVinaud/GeniusGeometrico/assets/128495824/50fe75b9-76b4-44e6-9159-e25e744f09d9)



## Link - Vídeo



## Alunos
- Lázaro Pereira Vinaud Neto 14675396
- Bruno Figueiredo Lima 14562383
- Gabriel Antunes Afonso de Araujo 14571077
- Pedro Henrique Ferreira Silva 14677526

## Referência

 - [FastLED](http://fastled.io/)


