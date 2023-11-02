
#include <Arduino.h>

// Variáveia para armazenar os resultados

unsigned long tempo_inicio;

unsigned long tempo_fim;

unsigned long valor;

// constante para configuração do prescaler
const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);

void setup() {
  Serial.begin(9600);
  // configura o preescaler do ADC
  ADCSRA &= ~PS_128;  //limpa configuração da biblioteca do arduino
  // valores possiveis de prescaler só deixar a linha com prescaler desejado
  // PS_16, PS_32, PS_64 or PS_128
  // ADCSRA |= PS_128; // 128 prescaler
  ADCSRA |= PS_64; // 64 prescaler
  //  ADCSRA |= PS_32; // 32 prescaler
  // ADCSRA |= PS_16; // 16 prescaler
}

void loop() {  
  // leitura
  tempo_inicio = micros(); //marca tempo de inicio de leitura
  valor = analogRead(A0);  //le valor convertido
  tempo_fim = micros();
    // valor = valor * 0.004882812;
  // valor = valor - 2.47;
  // valor = valor * 1000;
  // valor = valor / 185;         //sensibilidade : 66mV/A para ACS712 30A / 185mV/A para ACS712 5A
  // valor = valor / 1.41421356;
  // tempo_fim = micros();   //le tempo no fim da conversão

  //exibe valor lido e tempo de conversão
  Serial.print(valor);
  Serial.print(";");
  Serial.println(tempo_fim);
  // delayMicroseconds(100);
  // Serial.println(" us");
  // delay(500);
}
