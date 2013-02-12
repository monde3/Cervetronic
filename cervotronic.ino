************ a ver **********
***** ETAPA 1 *************************
*********** Muele y prepara el agua *************************
****************************************************
int plataforma = 5;
int colador = 3;
int moler = 2;
int remover = 0;
int ev_grifo = 0;
int ev_olla = 0;
int ETAPA = 0;
int START = 0;
unsigned long time;
  plataforma = 0;
	colador = 0; // posicion inicial de servo
boolean MOLIDO = false;
	
void Moler (){
		if(!MOLIDO)
			moler = 1;
		if(!MOLIDO && millis() > time+(30 * 1000)){
			MOLIDO = true;
			moler = 0;
			plataforma = 1;
		}
		
		if(sensor_ta == 67º){
			resistencia = 0;
			colador = 1;
			delay(2 * 1000);
			colador = 0;
			delay(1000);
			plataforma = 0;
			ETAPA = 1;
			time = millis();
		}
}

void Llenar (){
	if(sensor_agua == 0)
		ev_grifo = 1;
	else if(sensor_agua == 1){
		ev_grifo = 0;
		resistencia = 1;
}

void Calentar (){
	if(millis() < time + (90 * 60 * 1000)){
		if(millis() < time + (15 * 60 * 1000)
			remover = 1;
		else
			remover = 0;
		if(temperatura < 67)
			resistencia = 1;
		else
			resistencia = 0;
	}
	else{
		resistencia = 0;
		vaciar_olla = 1;
		ETAPA = 2;
	}
}

void Hervir(){

}

void loop () {
	if(digitalRead(BotonStart) == HIGH){
		if(START == 0){
			START = 1;
			time = millis();
		}else
			START = 0;
	}
	if(START == 1){
		switch(ETAPA){
			case 0:
				Llenar();
				Moler();
				break;
			case 1:
				Calentar();
				break;
			case 2:
				Hervir();
				break;
		}
	}
}
