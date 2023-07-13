#include <FastLED.h>

#define NUM_LEDS 64
#define BRIGHTNESS 30
#define LH 8
#define LW 8

#define PIN_LED 2
#define PIN_B1 7
#define PIN_B2 6
#define PIN_B3 5
#define PIN_B4 4

CRGB leds[NUM_LEDS], gaba[NUM_LEDS];
CRGB color1, color2, color3, color4, corAntiga[8];

int b1, b2, b3, b4, randNumber;
int tempo;

int seed_;

int state;
// state = 0 -> menu do jogo
// state = 1 -> mostra o gabarito
// state = 2 -> player joga

int lc, lb, ld, le;

void copia(struct CRGB *a, struct CRGB *b) {
  for(int i = 0; i < 64; i++) {
    a[i] = b[i];
  }
}

void gera_gaba(){
  int r;

  // apaga tudo no gaba
  for(int i = 0; i < 64; i++) gaba[i] = CRGB::Black;
    
  while(!acabou(gaba)) {
    // gerar uma cor
    r = random() % 4;
    r++;
    switch(r) {
      case 1:
        cima_gaba();
        break;
      case 2:
        direita_gaba();
        break;
      case 3:
        baixo_gaba();
        break;
      case 4:
        esquerda_gaba();
        break;
    }
  }

  // copia gaba em leds
  copia(leds, gaba);

  FastLED.show();
}

void cima_gaba() {
  if (lb == -1) return;
  
  for(int i=0; i<8; i++) {
    // Colore a linha com a cor
    for(int j=0; j<8; j++) {
      if(j>=le && j<=ld && gaba[i*LW + j] == CRGB::Black) {
        gaba[i*LW + j] = color1; 
      }
    }
    
    if (i >= lb) break;

    // Apaga a linha
    for(int j=0; j<8; j++) {
      if(j>=le && j<=ld && gaba[i*LW + j] == color1) {
        gaba[i*LW + j] = CRGB::Black;
      }
    }
  }
  lb--;
}

void direita_gaba() {
  if (le == 8) return;
  for(int i=7; i>=0; i--) {
    //Colore a coluna com a cor
    for(int j=0; j<8; j++) {
      if(j>=lc && j<=lb && gaba[j*LW + i] == CRGB::Black) {
        gaba[j*LW + i] = color2;
      }
    }
    if (i <= le) break;
    //Apaga a coluna
    for(int j=0; j<8; j++) {
      if(j>=lc && j<=lb && gaba[j*LW + i] == color2) {
        gaba[j*LW + i] = CRGB::Black;
      }
    }
    
  }
  le++;
}

void baixo_gaba() {
  if(lc == 8) return;
  for(int i=7; i>=0; i--) {
    for(int j=0; j<8; j++) {
      if(j>=le && j<=ld && gaba[i*LW + j] == CRGB::Black) {
        gaba[i*LW + j] = color3; 
      }
    }
    if (i <= lc) break;
    for(int j=0; j<8; j++) {
      if(j>=le && j<=ld && gaba[i*LW + j] == color3) {
        gaba[i*LW + j] = CRGB::Black;
      }
    }
  }
  lc++;
}

void esquerda_gaba() {
  if(ld == -1) return;
  for(int i=0; i<8; i++) {
    for(int j=0; j<8; j++) {
      if(j>=lc && j<=lb && gaba[j*LW + i] == CRGB::Black) {
        gaba[j*LW + i] = color4;
      }
    }
    if(i >= ld) break;
    for(int j=0; j<8; j++) {
      if(j>=lc && j<=lb && gaba[j*LW + i] == color4) {
        gaba[j*LW + i] = CRGB::Black; 
      }
    }
  }
  ld--;
}


void cima() {
  int i, j;

  if (lb == -1) return;
  
  for(i=0; i<8; i++) {
    // Colore a linha com a cor
    for(j=0; j<8; j++) {
      if(j>=le && j<=ld && leds[i*LW + j] == CRGB::Black) {
        leds[i*LW + j] = color1; 
      } else if(j>=le && j<=ld && leds[i*LW + j] != CRGB::Black) {
        corAntiga[j] = leds[i*LW + j];
        leds[i*LW + j] = CRGB::White; 
      }
    }
    FastLED.show();
    
    if (i >= lb) break;
    
    delay(tempo);

    // Apaga a linha
    for(j=0; j<8; j++) {
      if(j>=le && j<=ld && leds[i*LW + j] == color1) {
        leds[i*LW + j] = CRGB::Black;
      } else if (j>=le && j<=ld && leds[i*LW + j] == CRGB::White) {
        leds[i*LW + j] = corAntiga[j];
      }
    }
    
    FastLED.show();
  }
  lb--;
}

void direita() {
  int i, j;
  if (le == 8) return;
  for(i=7; i>=0; i--) {
    //Colore a coluna com a cor
    for(j=0; j<8; j++) {
      if(j>=lc && j<=lb && leds[j*LW + i] == CRGB::Black) {
        leds[j*LW + i] = color2;
      } else if(j>=lc && j<=lb && leds[j*LW + i] != CRGB::Black) {
        corAntiga[j] = leds[j*LW + i];
        leds[j*LW + i] = CRGB::White;
      }
    }
    FastLED.show();
    if (i <= le) break;
    delay(tempo);
    //Apaga a coluna
    for(j=0; j<8; j++) {
      if(j>=lc && j<=lb && leds[j*LW + i] == color2) {
        leds[j*LW + i] = CRGB::Black;
      } else if(j>=lc && j<=lb && leds[j*LW + i] == CRGB::White) {
        leds[j*LW + i] = corAntiga[j];
      }
    }
    FastLED.show();
    
  }
  le++;
}

void baixo() {
  int i, j;
  if(lc == 8) return;
  for(i=7; i>=0; i--) {
    for(j=0; j<8; j++) {
      if(j>=le && j<=ld && leds[i*LW + j] == CRGB::Black) {
        leds[i*LW + j] = color3; 
      } else if(j>=le && j<=ld && leds[i*LW + j] != CRGB::Black) {
        corAntiga[j] = leds[i*LW + j];
        leds[i*LW + j] = CRGB::White;
      }
    }
    FastLED.show();
    if (i <= lc) break;
    delay(tempo);
    for(j=0; j<8; j++) {
      if(j>=le && j<=ld && leds[i*LW + j] == color3) {
        leds[i*LW + j] = CRGB::Black;
      } else if(j>=le && j<=ld && leds[i*LW + j] == CRGB::White) {
        leds[i*LW + j] = corAntiga[j];
      }
    }
    FastLED.show();
  }
  lc++;
}

void esquerda() {
  int i, j;
  if(ld == -1) return;
  for(i=0; i<8; i++) {
    for(j=0; j<8; j++) {
      if(j>=lc && j<=lb && leds[j*LW + i] == CRGB::Black) {
        leds[j*LW + i] = color4;
      } else if(j>=lc && j<=lb && leds[j*LW + i] != CRGB::Black) {
        corAntiga[j] = leds[j*LW + i];
        leds[j*LW + i] = CRGB::White;
      }
    }
    FastLED.show();
    if(i >= ld) break;
    delay(tempo);
    for(j=0; j<8; j++) {
      if(j>=lc && j<=lb && leds[j*LW + i] == color4) {
        leds[j*LW + i] = CRGB::Black; 
      } else if(j>=lc && j<=lb && leds[j*LW + i] == CRGB::White) {
        leds[j*LW + i] = corAntiga[j];
      }
    }
    FastLED.show();
  }
  ld--;
}

int acabou(struct CRGB *mat) {
  int i;
  for(i=0; i<64; i++) {
    if(mat[i] == CRGB::Black) {
      return 0;
    }
  }
  return 1;
}

void reiniciar() {
  FastLED.setBrightness(BRIGHTNESS);
  
  lb = ld = 7;
  le = lc = 0;

  b1=b2=b3=b4 = LOW;
}

void setup() {
  randomSeed(seed_%1000000000);
  FastLED.addLeds<NEOPIXEL, PIN_LED>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();

  tempo = 100;  state = 0;

  seed_=0;

  color1 = CRGB(255,0,30);
  color2 = CRGB(200,0,255);
  color3 = CRGB(222,79,11);
  color4 = CRGB(0,255,120);

  pinMode(PIN_B1, INPUT);
  pinMode(PIN_B2, INPUT);
  pinMode(PIN_B3, INPUT);
  pinMode(PIN_B4, INPUT);

  b1 = b2 = b3 = b4 = LOW;

  lb = ld = 7;
  le = lc = 0;
}

void loop() {
  b1 = digitalRead(PIN_B1);
  b2 = digitalRead(PIN_B2);
  b3 = digitalRead(PIN_B3);
  b4 = digitalRead(PIN_B4);

  if (state == 0) {
    seed_+=1;
    randomSeed(seed_%1000000000);
    if(b1 || b2 || b3 || b4) {
      state = 1;
      // começa a mostrar
    }
  }

  if (state == 1) {
    reiniciar();
    gera_gaba();
    delay(15000);
    for(int i = 0; i < 64; i++) leds[i] = CRGB::Black;
    FastLED.show();

    reiniciar(); // voltar os valores de l_
    
    state = 2;
  }

  if (state == 2) {
    while(!acabou(leds)) {
      b1 = digitalRead(PIN_B1);
      b2 = digitalRead(PIN_B2);
      b3 = digitalRead(PIN_B3);
      b4 = digitalRead(PIN_B4);
      
      if(b1) {
        cima();
      } 
      if(b2) {
        direita();
      } 
      if(b3) {
        baixo();
      }
      if(b4) {
        esquerda();
      }
    }
    state = 3;
  }

  if (state == 3) {
    int i;
    delay(2000);
    for(i=0; i<64; i++) {
      if(leds[i] != gaba[i]) {
        leds[i] = CRGB::Black;
      }
    }
    state = 4;
  }

  if(state == 4) {
    int i;
    for(i=5; i<=65; i++) {
      b1 = digitalRead(PIN_B1);
      b2 = digitalRead(PIN_B2);
      b3 = digitalRead(PIN_B3);
      b4 = digitalRead(PIN_B4);
      if (b1 || b2 || b3 || b4) state = 0;
      FastLED.setBrightness(i);
      FastLED.show();
      delay(1);
    }
    for(i=65; i>=5; i--) {
      b1 = digitalRead(PIN_B1);
      b2 = digitalRead(PIN_B2);
      b3 = digitalRead(PIN_B3);
      b4 = digitalRead(PIN_B4);
      if (b1 || b2 || b3 || b4) state = 0;
      FastLED.setBrightness(i);
      FastLED.show();
      delay(1);
    }
    if (b1 || b2 || b3 || b4) state = 0;
  }
}
