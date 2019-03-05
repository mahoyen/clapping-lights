

int const clappingpattern[] = {1,1,1,0,1,1,0,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,1,0,1,1,1,0,1,1,0,1,0,1,1,0};

int const bluePin = 8;
int const redPin = 7;
int const greenPin = 6;

int const potPin = A0;

int const MAX_BAR_SHIFT = 12;
int const MAX_BARS = 1;

int const offset = 50;

int count = 0;

int readWhileWait(int wait_time) {
  long long int end_millis = millis()+wait_time;
  while (millis()<end_millis){
    if (analogRead(potPin) != wait_time-offset){
      wait_time = offset + analogRead(potPin);
    }
  }
  return wait_time;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(bluePin, OUTPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  //Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
  int wait_time = offset + analogRead(potPin);
  count++;
  for (int bar_shift = 0; bar_shift < MAX_BAR_SHIFT; bar_shift++) {
    for (int bar_nr = 0; bar_nr < MAX_BARS; bar_nr++) {
      for (int note_nr = 0; note_nr < 12; note_nr++){
//        Serial.println(count);
//        Serial.println(bar_shift);
//        Serial.println(bar_nr);
//        Serial.println(note_nr);
        wait_time = readWhileWait(wait_time);
        digitalWrite(greenPin, HIGH);
        wait_time = readWhileWait(wait_time);
        digitalWrite(greenPin, LOW);
        delay(offset);
        if (clappingpattern[note_nr]) {
          digitalWrite(bluePin, HIGH);
        }else {
        digitalWrite(bluePin, LOW);
        }
        if (clappingpattern[note_nr+bar_shift]) {
          digitalWrite(redPin, HIGH);
        }else {
        digitalWrite(redPin, LOW);
        }
      }
    }
  }
}

