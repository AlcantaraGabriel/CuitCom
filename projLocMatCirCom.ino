//Include the SoftwareSerial library
//Autor: Gabriel Alcântara Silva
//para entender o seguinte código é neccessário ver a Aula 4: http://redeetec.mec.gov.br/images/stories/pdf/eixo_ctrl_proc_indust/tec_autom_ind/tec_digi/161012_tec_dig.pdf
#include "SoftwareSerial.h"

SoftwareSerial bluetooth(11, 12); //TX, RX (Bluetooth)
String rString;//String for serial data

void setup() {
   //Initialize the hardware serial
  Serial.begin(9600);
  //Serial.println(F("Type the AT commands:"));
  //Initialize the software serial
  bluetooth.begin(38400);
        
  pinMode(2, OUTPUT);//Segmento A  
  pinMode(3, OUTPUT);//Segmento B
  pinMode(4, OUTPUT);//Segmento C
  pinMode(5, OUTPUT);//Segmento D
  pinMode(6, OUTPUT);//Segmento E
  pinMode(7, OUTPUT);//Segmento F
  pinMode(8, OUTPUT);//Segmento G
  pinMode(9, OUTPUT);//Segmento Ponto

}

int A,B,C,D; // Variáveis de controle

void loop() {
  
  //Read character and sum in rString
  while (bluetooth.available()>0) {
    char r = bluetooth.read();
    rString += r;
  }

  
   if(bluetooth.available()<1){
    Serial.print(rString);//printing in Serial Arduino
    bluetooth.print(rString); // printing data in Serial in the Bluetooth
    if(rString=="0000") A =0,B=0,C=0,D=0;//Número 0
    if(rString=="0001") A =0,B=0,C=0,D=1;//Número 1
    
    if(rString=="0010")A =0,B=0,C=1,D=0;//Número 2
    if(rString=="0011") A =0,B=0,C=1,D=1;//Número 3
    
    if(rString=="0100") A =0,B=1,C=0,D=0;//Número 4
    if(rString=="0101") A =0,B=1,C=0,D=1;//Número 5

    if(rString=="0110") A =0,B=1,C=1,D=0;//Número 6
    if(rString=="0111") A =0,B=1,C=1,D=1;//Número 7
    if(rString=="1000") A =1,B=0,C=0,D=0;//Número 8
    if(rString=="1001") A =1,B=0,C=0,D=1;//Número 9   
  }
  rString ="";
  
  if(A || C || (B && D || !B && !D))//Expressão lógica para para ligar o segmento "a" a partir dos valores lógicos de 4 variáveis(A,B,C,D)
      digitalWrite(2,0);//ligado
  else
    digitalWrite(2,1);//desligado
    //////////////
  if(!B|| (C && D || !C && !D)) //Expressão lógica para para ligar o segmento "b" a partir dos valores lógicos de 4 variáveis(A,B,C,D)
      digitalWrite(3,0);
  else
    digitalWrite(3,1); 
        //////////////
  if(B || !C || D) // //Expressão lógica para para ligar o segmento "c" a partir dos valores lógicos de 4 variáveis(A,B,C,D)
     digitalWrite(4,0);
  else
    digitalWrite(4,1);
        //////////////
  if(A || (!B && !D) || (!B && C)  || (C && !D) ||(B && !C && D))//Expressão lógica para para ligar o segmento "d" a partir dos valores lógicos de 4 variáveis(A,B,C,D)
     digitalWrite(5,0);
  else
    digitalWrite(5,1);
    //////////////   
  if(!B && !D || C && !D)//E/Expressão lógica para para ligar o segmento "e" a partir dos valores lógicos de 4 variáveis(A,B,C,D)
     digitalWrite(6,0);
  else
    digitalWrite(6,1);
    //////////////
  if(A || !C && !D || B && !C || B && !D)//Expressão lógica para para ligar o segmento "f" a partir dos valores lógicos de 4 variáveis(A,B,C,D)
    digitalWrite(7,0);
  else
    digitalWrite(7,1);
    //////////////  
  if(A || C && !D || (B && !C || !B && C))//Expressão lógica para para ligar o segmento "g" a partir dos valores lógicos de 4 variáveis(A,B,C,D)
    digitalWrite(8,0);
  else
    digitalWrite(8,1);
    //////////////
}