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
#define nove    0x101010EF
#define ON      0x1010A857

int RECV_PIN = 7;
int displ = 6;
int sup=0;
int cont1 = 1, cont2 = 2, cont3 = 3, cont4 = 4, cont5 = 5, cont6 = 6, cont7 = 7, cont8 = 8, cont9 = 9; 
IRrecv irrecv(RECV_PIN);
decode_results results;

Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12);

void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); 
  pinMode (displ, OUTPUT);
  digitalWrite (displ, LOW);
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  display.begin();
  display.setContrast(50); //Ajusta o contraste do display
  display.clearDisplay();   //Apaga o buffer e o display 
  display.setTextColor(WHITE, BLACK); 
  display.println("IFBA");
  display.setTextSize(1); 
  display.setTextColor(BLACK);
  display.print("ELETRONICA");
  display.display();
  delay(2000); 
}

void loop() {
  
  
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume();
    
    if(results.value == liga){
       digitalWrite(displ, HIGH);
       sup++;
       if(sup%2==0){
          digitalWrite(displ, LOW);
        }
      }
      

     if(results.value == ON){
       
        display.clearDisplay();  //Apaga o buffer e o display
        display.display();
        display.println("CANAL ");
 
      }

        switch(results.value){
          case um:
        display.begin();
        //display.clearDisplay();
        display.setTextSize(2);
        display.print(cont1, DEC);
        display.display();
        //cont1 = (cont1*10)+1;
        if(cont1 > 111){
       
        }
       break;
       case dois:
        display.begin();
        //display.clearDisplay();
        display.setTextSize(2); 
        display.print(cont2, DEC);
        display.display();
        //cont2 = (cont2*10)+2;
        if(cont2 > 222){
          cont2 = 2;
        }
        break;
        case tres:
        display.begin();
        //display.clearDisplay();
        display.setTextSize(2); 
        display.print(cont3, DEC);
        display.display();
        //cont2 = (cont2*10)+2;
        if(cont3 > 333){
          cont3 = 3;
        }
        break;
        case quatro:
        display.begin();
        //display.clearDisplay();
        display.setTextSize(2); 
        display.print(cont4, DEC);
        display.display();
        //cont2 = (cont2*10)+2;
        if(cont4 > 444){
          cont4 = 4;
        }
        break;
        case cinco:
        display.begin();
        //display.clearDisplay();
        display.setTextSize(2); 
        display.print(cont5, DEC);
        display.display();
        //cont2 = (cont2*10)+2;
        if(cont5 > 555){
          cont5 = 5;
        }
        break;
        case seis:
        display.begin();
        //display.clearDisplay();
        display.setTextSize(2); 
        display.print(cont6, DEC);
        display.display();
        //cont2 = (cont2*10)+2;
        if(cont6 > 666){
          cont6 = 6;
        }
        break;
        case sete:
        display.begin();
        //display.clearDisplay();
        display.setTextSize(2); 
        display.print(cont7, DEC);
        display.display();
        //cont2 = (cont2*10)+2;
        if(cont7 > 777){
          cont7 = 7;
        }
        break;
        case oito:
        display.begin();
        //display.clearDisplay();
        display.setTextSize(2); 
        display.print(cont8, DEC);
        display.display();
        //cont2 = (cont2*10)+2;
        if(cont8 > 888){
          cont8 = 8;
        }
        break;
        case nove:
        cont1 = 1;
        display.begin();
        //display.clearDisplay();
        display.setTextSize(2); 
        display.print(cont9, DEC);
        display.display();
        //cont2 = (cont2*10)+2;
        if(cont9 > 999){
          cont9 = 9;
        }
        break;
      }
    delay(100);
  }
}
