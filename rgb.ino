

const int rgbPins[] = { 11, 10, 9};  
const int buttonPins[] = { 4, 3, 2}; 
float newStatus = 50.0;              
float filteredStatus = 50.0;        
float x = -0.5;                      
unsigned long previousMillis;
const unsigned long interval = 40; 


void setup() 
{
  for( int i=0; i<3; i++)
    pinMode( rgbPins[i], OUTPUT);

  for( int i=0; i<3; i++)
    pinMode( buttonPins[i], INPUT_PULLUP);
}


void loop() 
{
  unsigned long currentMillis = millis();
  if( digitalRead(buttonPins[0]) == LOW)  
    newStatus = 100.0;
  if( digitalRead(buttonPins[1]) == LOW)  
    newStatus = 50.0;
  if( digitalRead(buttonPins[2]) == LOW) 
    newStatus = 0.0;
  if( currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis;

    const float pct = 1.8;   
    filteredStatus = (( 1.0 - (pct / 100.0)) * filteredStatus) + (pct / 100.0 * newStatus);  

    float r, g, b;     
    float f;      

    if( filteredStatus < 50.0)
    {
      r = 0.0;
      g = filteredStatus / 50.0;
      b = 1.0 - g;
      f = 0.5 + (g / 2);   
    }
    else
    {
      r = (filteredStatus - 50.0) / 50.0;
      g = 1.0 - r;
      b = 0.0;
      f = 1.0 + (2 * r);  
    }
    float y = expf( -50.0 * squaref( x));
    x += f * float( interval) / 1000.0;  
    if( x >= 0.5)
      x -= 1.0;
    int pwmR = (int) round( 1.0 + (r * y * 254.0));
    int pwmG = (int) round( 1.0 + (g * y * 254.0));
    int pwmB = (int) round( 1.0 + (b * y * 254.0));
    analogWrite( rgbPins[0], pwmR);
    analogWrite( rgbPins[1], pwmG);
    analogWrite( rgbPins[2], pwmB);
  }
}
