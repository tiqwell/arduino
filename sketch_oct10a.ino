int ledPins[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
int numLeds = 10;
long long itc_bin_num(long long number) {
    int a = 0, b = 1;
    while (number) {
        a += number % 2 * b;
        number /= 2;
        b *= 10;
    }
    return a;
}

void setup() {
    Serial.begin(9600);
    for (int i = 0; i < numLeds; i++) {
        pinMode(ledPins[i], OUTPUT);
    }
}

void loop() {
    int number = Serial.parseInt();
    int numbin = itc_bin_num(number);
    while(numbin > 0) {
        int s = numbin % 10;
        for (int i = 0; i < numLeds; i++) 
        {
            if (s == 1) {
                digitalWrite(ledPins[i], HIGH);
            } else {
                digitalWrite(ledPins[i], LOW);
            }
            numbin /= 10;
        }
    }
}
