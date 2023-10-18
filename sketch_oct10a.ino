int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int numLeds = 10;

long long itc_bin_num(int number)
{
    long long a = 0, b = 1;
    while (number)
    {
        a += number % 2 * b;
        number /= 2;
        b *= 10;
    }
    return a;
}

void setup()
{
    Serial.begin(9600);
    for (int i = 0; i < numLeds; i++) 
    {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop()
{
      while(Serial.available() > 0)
      {
      int number = Serial.parseInt();
      if(number != 0){
      long long numbin = itc_bin_num(number);
      for(int i = 0; i < 10; i++){
        int d= numbin % 10;
        if(d == 1)
        {
          digitalWrite(ledPins[i], HIGH);
        }
        else{
          digitalWrite(ledPins[i], LOW);
        }
        numbin /= 10;
      }  
      }
      }    
  }
