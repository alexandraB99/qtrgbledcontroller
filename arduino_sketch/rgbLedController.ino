int redPin = 11;
int greenPin = 10;
int bluePin =  9;

void setup()
{
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  if (Serial.available()){
    char colorIdentifier = Serial.read();
    int value = Serial.parseInt();
    setColors(colorIdentifier, value);
  }
}

void setColors(char color, int value)
{
  if (color == 'r'){
    analogWrite(redPin, value);
    return;
  }
  if (color == 'g'){
    analogWrite(greenPin, value);
    return;
  }
  if (color == 'b'){
    analogWrite(bluePin, value);
    return;
  }
  return;
}
