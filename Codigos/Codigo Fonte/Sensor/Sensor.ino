#define pino_sensor 3

int milisegundos, decimas, segundos, minutos,  horas;

String ini();
void cronometro();
void zera_cronometro();
 
void setup()
{
  Serial.begin(9600);
  // Define o pino do sensor como entrada
  pinMode(pino_sensor, INPUT);
}
 
void loop()
{
   if(!digitalRead(pino_sensor) && Serial.read() == 'a')Serial.println(ini());
}

void cronometro(){

 
    milisegundos = millis();
    if(milisegundos % 1000 == 0)decimas++;
    if(decimas == 50)
    { 
      decimas = 0;
      segundos++;
      if(segundos == 1)segundos += 3;
    }
    if(segundos == 60)
    { 
      segundos = 0;
      minutos++;
    }
    if(minutos == 60)
    {
      minutos = 0;
      horas++;
    }
}

void zera_cronometro(){

  decimas = 0;
  segundos = 0;
  minutos = 0;
  horas = 0;
}

String ini()
{
  zera_cronometro();
  while(!digitalRead(pino_sensor)){}
  while(digitalRead(pino_sensor))
  {
    cronometro();
  }

  String hora = "";

  hora.concat(String(minutos));
  hora.concat(String(":"));
  hora.concat(String(segundos));
  hora.concat(String(":"));
  hora.concat(String(decimas));

  zera_cronometro();

  return hora;
}