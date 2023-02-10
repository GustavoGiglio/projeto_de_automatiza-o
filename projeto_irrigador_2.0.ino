

//Definição dos pinos
const int pino_sensor = 2; //pino conencatdo ao sensor de umidade
int leitura_sensor = 0;
const int pino_bomba = 15; //pino conectado ao rele da bomba
int n1 = 33; //pino conencatdo ao sensor de nivel agua mais baixo
int n2 = 32; //pino conencatdo ao sensor de nivel agua baixo
int n3 = 35; //pino conencatdo ao sensor de nivel agua meio
int n4 = 34; //pino conencatdo ao sensor de nivel agua alto

void setup(){
  Serial.begin(9600); //Inicializa a serial com taxa de 9600 bauds
  pinMode(pino_sensor, INPUT); //Define o sensor de umidade como entrada do sistema
  pinMode(pino_bomba, OUTPUT); //Define a bomba como saída do sistema
  pinMode(n1, INPUT); //Define o sensor de nivel agua como entrada do sistema
  pinMode(n2, INPUT); //Define o sensor de nivel agua como entrada do sistema
  pinMode(n3, INPUT); //Define o sensor de nivel agua como entrada do sistema
  pinMode(n4, INPUT); //Define o sensor de nivel agua como entrada do sistema
}

void loop(){
  leitura_sensor = analogRead(pino_sensor); //Sensor de umidade faz leitura do solo
  Serial.print("Status: "); 
  if(leitura_sensor >= 1500){  //Verifica se o solo está seco ou umido
    Serial.print("Solo Seco ");
    digitalWrite (pino_bomba, LOW); //Se estiver seco, desliga o relé e aciona a bomba    
  } else {
    Serial.print("Solo umido");
    digitalWrite (pino_bomba, HIGH); //Se estiver umido, mantêm o relé da bomba desligada
  }
  Serial.print(" | Leitura: ");
  Serial.print(leitura_sensor);

  //Realiza as leituras dos sensores e as armazena em duas variaveis
  int leitura_sensor_1 = digitalRead(n1); 
  int leitura_sensor_2 = digitalRead(n2);
  int leitura_sensor_3 = digitalRead(n3);
  int leitura_sensor_4 = digitalRead(n4);
  
  
  Serial.print(" | Quantidade Agua: ");

  //Verifica se o primeiro sensor esta na ausencia de liquido
  if(leitura_sensor_4 == HIGH) {
    Serial.print("100% Cheio"); //Printa a mensagem mostrando que o balde está 100% Cheio
    Serial.println("");
  }

  //Verifica se o segundo sensor esta na ausencia de liquido
  else if(leitura_sensor_3 == HIGH) {
    Serial.print("75% Cheio"); //Printa a mensagem mostrando que o balde está 75% Cheio
    Serial.println("");
  }

  //Verifica se o terceiro sensor esta na ausencia de liquido
  else if(leitura_sensor_2 == HIGH) {
    Serial.print("50% Cheio"); //Printa a mensagem mostrando que o balde está 50% Cheio
    Serial.println("");
  }
  
  //Verifica se o quarto sensor esta na ausencia de liquido
  else if(leitura_sensor_1 == HIGH) {
    Serial.print("25% Cheio"); //Printa a mensagem mostrando que o balde está 25% Cheio
    Serial.println("");
  }

  //Avisa que acabou o liquido e precisa encher
  else if(leitura_sensor_1 == LOW) {
    Serial.print("Encher balde"); //Printa a mensagem mostrando que o balde está com a água quase acabando
    Serial.println("");
  }

  delay(1000); //Aguarda 10 segundos para outra leitura  
}

