#include <IRremote.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>
#define liga    0x1010F00F
#define zero    0x1010906F
#define um      0x101000FF
#define dois    0x1010807F
#define tres    0x101040BF
#define quatro  0x1010C03F
#define cinco   0x101020DF
#define seis    0x1010A05F
#define sete    0x1010609F
#define oito    0x1010E01F
#define nove    0x1010906F
#define ON      0x1010A857


int RECV_PIN = 7;
int cont1 = 1, cont2 = 2;
IRrecv irrecv(RECV_PIN);
decode_results results;

Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        display.begin();
        display.setContrast(50); //Ajusta o contraste do display
        display.clearDisplay();   //Apaga o buffer e o display 
        display.setTextColor(WHITE, BLACK); 
        display.println("MAURICIO");
        display.setTextSize(2); 
        display.setTextColor(BLACK);
        display.print("PROJECT");
        display.display();
        delay(2000);  
}


void loop() {
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    
    if(results.value == liga){
        display.clearDisplay();   //Apaga o buffer e o display
        display.setTextSize(1);  //Seta o tamanho do texto
        display.println("Arduino!");
        display.display();
      }

     if(results.value == ON){
        display.clearDisplay();  //Apaga o buffer e o display
        display.display();
        display.println("CANAL ");
        cont1 = 1;
        cont2 = 2;
      }

        if(results.value == um){
        cont2 = 2;
        display.begin();
        display.clearDisplay();
        display.setTextSize(2);
        display.print(cont1, DEC);
        display.display();
        cont1 = (cont1*10)+1;
        if(cont1 > 111){
          cont1 = 1;
        }
       
      }

        if(results.value == dois){
        cont1 = 1;
        display.begin();
        display.clearDisplay();
        display.setTextSize(2); 
        display.print(cont2, DEC);
        display.display();
        cont2 = (cont2*10)+2;
        if(cont2 > 222){
          cont2 = 2;
        }
      }
    delay(100);
  }
}
