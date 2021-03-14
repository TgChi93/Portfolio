int LX,LY,RX,RY,TL,TR=500;

byte buf[13] ;

void setup() {
  
  buf[12] = 255;

  Serial.begin(9600);
  
}

int fillBuffer(int x1, int x2, int x3, int x4, int x5, int x6) { 
  
  x1 = x1 << 3; 
  x2 = x2 << 3;
  x3 = x3 <<3;
  x4 = x4 <<3;
  x5 = x5 <<3;
  x6 = x6 <<3;

  buf[0] = lowByte(x1);
  buf[1] = highByte(x1);
  buf[2] = lowByte(x2);
  buf[3] = highByte(x2);
  buf[4] = lowByte(x3);
  buf[5] = highByte(x3);
  buf[6] = lowByte(x4);
  buf[7] = highByte(x4);
  buf[8] = lowByte(x5);
  buf[9] = highByte(x5);
  buf[10] = lowByte(x6);
  buf[11] = highByte(x6);
} 
 

void loop() {
  LX=analogRead(A5);
  LY=analogRead(A4);
  RX=analogRead(A1);
  RY=analogRead(A0);
  TL=analogRead(A3);
  TR=analogRead(A2);

  LX=map(LX,325,700,1,6);
  LY=map(LY,1025,670,1,6);
  RX=map(RX,345,700,1,6);
  RY=map(RY,1035,670,1,6);
  TL=map(TL,310,723,1,6);
  TR=map(TR,725,300,1,6);

  fillBuffer(LX,LY,RX,RY,TL,TR);

  Serial.write(buf,13);
  
  delay(50);

}
