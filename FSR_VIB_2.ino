const int PIN_FRS_INDEX_R_GLOVE_I = A0; 
const int PIN_FRS_MIDDLE_R_GLOVE_I = A1;
const int PIN_FRS_RING_R_GLOVE_I   = A2;


const int PIN_VBR_I = 3;
const int PIN_VBR_II = 5; 
const int PIN_VBR_III = 6; 

 

int VALUE_FRS_INDEX_R_GLOVE_I, VALUE_FRS_MIDDLE_R_GLOVE_I, VALUE_FRS_RING_R_GLOVE_I;
int intensity = 0;
int threshold = 100;

void setup() 


{
  Serial.begin(9600);
  pinMode(PIN_VBR_I, OUTPUT);
}

void loop() 
{
  VALUE_FRS_INDEX_R_GLOVE_I = analogRead(PIN_FRS_INDEX_R_GLOVE_I);
  VALUE_FRS_MIDDLE_R_GLOVE_I = analogRead(PIN_FRS_MIDDLE_R_GLOVE_I);
  VALUE_FRS_RING_R_GLOVE_I = analogRead(PIN_FRS_RING_R_GLOVE_I);
  
  //Serial.println(VALUE_FRS_INDEX_R_GLOVE_I);
  //Serial.println(PIN_FRS_MIDDLE_R_GLOVE_I);
  //Serial.println(PIN_FRS_RING_R_GLOVE_I);

  if (VALUE_FRS_INDEX_R_GLOVE_I > threshold)
  {
    Serial.println("Index FSR triggerd");
    analogWrite(PIN_VBR_II, 0);
    analogWrite(PIN_VBR_III, 0);
    intensity = map (VALUE_FRS_INDEX_R_GLOVE_I, 0, 1023, 0, 255);
    analogWrite(PIN_VBR_I, intensity);
  }

  else if (VALUE_FRS_MIDDLE_R_GLOVE_I > threshold)
  {
    Serial.println("Middle FSR triggerd");
    analogWrite(PIN_VBR_I, 0);
    analogWrite(PIN_VBR_III, 0);
    intensity = map (VALUE_FRS_MIDDLE_R_GLOVE_I, 0, 1023, 0, 255);
    analogWrite(PIN_VBR_II, intensity);
  }
  else if (VALUE_FRS_RING_R_GLOVE_I > threshold)
  {
    Serial.println("Ring FSR triggered");
    analogWrite(PIN_VBR_I, 0);
    analogWrite(PIN_VBR_II, 0);
    intensity = map (VALUE_FRS_RING_R_GLOVE_I, 0, 1023, 0, 255);
    analogWrite(PIN_VBR_III, intensity);    
  }
  else
  {
    Serial.println("No FSR triggered");
    analogWrite(PIN_VBR_I, 0);
    analogWrite(PIN_VBR_II, 0);
    analogWrite(PIN_VBR_III, 0);
 
  }

delay(200);
}
