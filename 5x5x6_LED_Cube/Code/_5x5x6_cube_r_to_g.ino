//For the purposes of this series of code, the entire cube will begin colour "A" and steadily become colour "B"

//Initlizing the pins
int row[]={1,2,3,4,5};
int column[]={6,7,8,9,10};
int layer[]={A0,A1,A2,A3,A4,A5};
int pinCount=6;

//Declaring the pins as output
void setup(){
  for(int thisPin = 0; thisPin < pinCount; thisPin++){
    pinMode(row[thisPin],OUTPUT);
    pinMode(column[thisPin],OUTPUT);
    pinMode(layer[thisPin],OUTPUT);
  }
}

//Now the actual code
void loop(){
  //The code which uses for loops and the above arrays
    //Makes all enable pins low to transfer data then second for loop sets each row high and each column low to make all LEDs colour "A"
    for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(layer[thisPin],LOW);
    };
    for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],HIGH);
      digitalWrite(column[thisPin],LOW);
    };
    delay(5000);
   //Now to start the turning of colour "A" to colour "B". We begin by making all layers high for data will only be transfercolour "A" as we turn each layer back on
   for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(layer[thisPin],HIGH);
   };
   //We continue by making layer 1 low. Then we use the for loop to gradually change each LED from colour "A" to colour "B"
   digitalWrite(layer[0],LOW);
   for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
      delay(2000);
   };
   //We continue by making layer 2 low and the previous layer high. Then we use the for loop to gradually change each LED from colour "A" to colour "B"
   digitalWrite(layer[0],HIGH);
   digitalWrite(layer[1],LOW);
   for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
      delay(2000);
   };
   //We continue by making layer 3 low and the previous layer high. Then we use the for loop to gradually change each LED from colour "A" to colour "B"
   digitalWrite(layer[1],HIGH);
   digitalWrite(layer[2],LOW);
   for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
      delay(2000);
   };
   //We continue by making layer 4 low and the previous layer high. Then we use the for loop to gradually change each LED from colour "A" to colour "B"
   digitalWrite(layer[2],HIGH);
   digitalWrite(layer[3],LOW);
   for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
      delay(2000);
   };
   //We continue by making layer 5 low and the previous layer high. Then we use the for loop to gradually change each LED from colour "A" to colour "B"
   digitalWrite(layer[3],HIGH);
   digitalWrite(layer[4],LOW);
   for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
      delay(2000);
   };
   //We continue by making layer 6 low and the previous layer high. Then we use the for loop to gradually change each LED from colour "A" to colour "B"
   digitalWrite(layer[4],HIGH);
   digitalWrite(layer[5],LOW);
   for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
      delay(2000);
   };
}
    
