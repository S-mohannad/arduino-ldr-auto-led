int v=0;
void setup() {
pinMode(13,OUTPUT);
}
void loop() {
v=analogRead(A0);
if (v>450)
{digitalWrite(13,LOW);}
else 
{ digitalWrite(13,HIGH);}
}