//This creates a "christmas tree" with a "trunk" of colour A and "branches" of colour B and then continuously flips the colours
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
  //Makes all enable pins low to transfer data than second for loop sets each row high and each column high to make all LEDs off
    for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(layer[thisPin],LOW);
    };
    for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],HIGH);
      digitalWrite(column[thisPin],HIGH);
    };
    
  //Makes a "trunk" of colour A and "branches" of colour B
  
  //Makes all layers high for only individual layers will have data transferred
    for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(layer[thisPin],HIGH);
    };
  //layer 1 to form the bottom of the "trunk" of the tree as colour A, consisting of middle 9 LEDs
    digitalWrite(layer[0],LOW);
    for(int thisPin = 1; thisPin < 4; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
    };
  //layer 2 to form next layer as part of the "trunk" of the tree as colour A, consisting of middle 9 LEDs
    digitalWrite(layer[0],HIGH);
    digitalWrite(layer[1],LOW);
    for(int thisPin = 1; thisPin < 4; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
    };
  //layer 3 to form next layer as bottom of the "branches" part of the tree as colour B, consisting of middle 9 LEDs
    digitalWrite(layer[1],HIGH);
    digitalWrite(layer[2],LOW);
    for(int thisPin = 1; thisPin < 4; thisPin++){
      digitalWrite(row[thisPin],HIGH);
      digitalWrite(column[thisPin],LOW);
    };
  //layer 4 to form next layer as the next portion of the "branches" part of the tree as colour B, consisting of all LEDs
    digitalWrite(layer[2],HIGH);
    digitalWrite(layer[3],LOW);
    for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],HIGH);
      digitalWrite(column[thisPin],LOW);
    };
  //layer 5 to form next layer as the next portion of the "branches" part of the tree as colour B, consisting of middle 9 LEDs
    digitalWrite(layer[3],HIGH);
    digitalWrite(layer[4],LOW);
    for(int thisPin = 1; thisPin < 4; thisPin++){
      digitalWrite(row[thisPin],HIGH);
      digitalWrite(column[thisPin],LOW);
    };
  //layer 6 to form next layer as the top of the "branches" part of the tree as colour B, consisting of middle 1 LED
    digitalWrite(layer[4],HIGH);
    digitalWrite(layer[5],LOW);
    digitalWrite(row[2],HIGH);
    digitalWrite(column[2],LOW);
  //Pauses for 5 seconds
    delay(5000);
    
  //This section flips the colours around
  
  //layer 1 to form the bottom of the "trunk" of the tree as colour B, consisting of middle 9 LEDs
    digitalWrite(layer[5],HIGH);
    digitalWrite(layer[0],LOW);
    for(int thisPin = 1; thisPin < 4; thisPin++){
      digitalWrite(row[thisPin],HIGH);
      digitalWrite(column[thisPin],LOW);
    };
  //layer 2 to form next layer as part of the "trunk" of the tree as colour B, consisting of middle 9 LEDs
    digitalWrite(layer[0],HIGH);
    digitalWrite(layer[1],LOW);
    for(int thisPin = 1; thisPin < 4; thisPin++){
      digitalWrite(row[thisPin],HIGH);
      digitalWrite(column[thisPin],LOW);
    };
  //layer 3 to form next layer as bottom of the "branches" part of the tree as colour A, consisting of middle 9 LEDs
    digitalWrite(layer[1],HIGH);
    digitalWrite(layer[2],LOW);
    for(int thisPin = 1; thisPin < 4; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
    };
  //layer 4 to form next layer as the next portion of the "branches" part of the tree as colour A, consisting of all LEDs
    digitalWrite(layer[2],HIGH);
    digitalWrite(layer[3],LOW);
    for(int thisPin = 0; thisPin < pinCount; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
    };
  //layer 5 to form next layer as the next portion of the "branches" part of the tree as colour A, consisting of middle 9 LEDs
    digitalWrite(layer[3],HIGH);
    digitalWrite(layer[4],LOW);
    for(int thisPin = 1; thisPin < 4; thisPin++){
      digitalWrite(row[thisPin],LOW);
      digitalWrite(column[thisPin],HIGH);
    };
  //layer 6 to form next layer as the top of the "branches" part of the tree as colour A, consisting of middle 1 LED
    digitalWrite(layer[4],HIGH);
    digitalWrite(layer[5],LOW);
    digitalWrite(row[2],LOW);
    digitalWrite(column[2],HIGH);
  //Pauses for 5 seconds
    delay(5000);
};
