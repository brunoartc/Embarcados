#include <asf.h>

#include "gfx_mono_ug_2832hsweg04.h"
#include "gfx_mono_text.h"
#include "sysfont.h"
#include "musicas.h"

//perifericos

#define BUZZ_PIO           PIOD                  // periferico que controla o LED
#define BUZZ_PIO_ID        16                    // ID do periférico PIOC (controla LED)
#define BUZZ_PIO_IDX      20u                    // ID do LED no PIO
#define BUZZ_PIO_IDX_MASK  (1u << BUZZ_PIO_IDX)   // Mascara para CONTROLARMOS o LED

#define LED_PIO           PIOC                  // periferico que controla o LED
#define LED_PIO_ID        12                    // ID do periférico PIOC (controla LED)
#define LED_PIO_IDX		8u                    // ID do LED no PIO
#define LED_PIO_IDX_MASK  (1u << LED_PIO_IDX)   // Mascara para CONTROLARMOS o LED

#define ELED1_PIO           PIOA                  // periferico que controla o LED
#define ELED1_PIO_ID        10                    // ID do periférico PIOC (controla LED)
#define ELED1_PIO_IDX		0u                    // ID do LED no PIO
#define ELED1_PIO_IDX_MASK  (1u << ELED1_PIO_IDX)   // Mascara para CONTROLARMOS o LED ;; 7 PA0

#define ELED2_PIO           PIOC                  // periferico que controla o LED
#define ELED2_PIO_ID        12                 // ID do periférico PIOC (controla LED)
#define ELED2_PIO_IDX		30u                    // ID do LED no PIO
#define ELED2_PIO_IDX_MASK  (1u << ELED2_PIO_IDX)   // Mascara para CONTROLARMOS o LED ;;8 PC30

#define ELED3_PIO           PIOB                // periferico que controla o LED
#define ELED3_PIO_ID        11                  // ID do periférico PIOC (controla LED)
#define ELED3_PIO_IDX		2u                    // ID do LED no PIO
#define ELED3_PIO_IDX_MASK  (1u << ELED3_PIO_IDX)   // Mascara para CONTROLARMOS o LED ;;6 PB2




#define BUT_PIO PIOA
#define BUT_PIO_ID 10
#define BUT_PIO_IDX 11
#define BUT_PIO_IDX_MASK (1u << BUT_PIO_IDX)



#define EBUT1_PIO PIOD //start EXT 9 PD28
#define EBUT1_PIO_ID 16
#define EBUT1_PIO_IDX 28
#define EBUT1_PIO_IDX_MASK (1u << EBUT1_PIO_IDX)


#define EBUT2_PIO PIOA //pause  Ext 4 PA19 PA = 10
#define EBUT2_PIO_ID 10
#define EBUT2_PIO_IDX 19
#define EBUT2_PIO_IDX_MASK (1u << EBUT2_PIO_IDX)


#define EBUT3_PIO PIOC //sei la EXT 3 PC31
#define EBUT3_PIO_ID 12 // piod ID
#define EBUT3_PIO_IDX 31
#define EBUT3_PIO_IDX_MASK (1u << EBUT3_PIO_IDX)



int atual_led = 0;

int check_board_button(){ // checa se o bottao da placa foi pressionado
	return pio_get(BUT_PIO,PIO_INPUT,BUT_PIO_IDX_MASK);
}

void bizz(int frequencia, int tempo_ms, int w_led){
	int us_delay = 1000000/frequencia; //quantos microsegundos entre as notas para definir a frequencia
	int tempo = tempo_ms * 1000; //ms -> us
	
	int i = 0;
	
	if(w_led) { //testar se quer o led juntamente com o som
		switch(atual_led) { //checa o led que esta sendo controlado

			case 0:
			pio_clear(ELED2_PIO, ELED2_PIO_IDX_MASK);
			break;
			
			case 2:
			pio_clear(ELED1_PIO, ELED1_PIO_IDX_MASK);
			break;
			
			default :
			pio_clear(ELED3_PIO, ELED3_PIO_IDX_MASK);
			
		}

		
		
	}
	while (i<tempo/us_delay){
		pio_set(BUZZ_PIO, BUZZ_PIO_IDX_MASK);      // Coloca 1 no pino LED
		delay_us(us_delay/2);
		pio_clear(BUZZ_PIO, BUZZ_PIO_IDX_MASK);    // Coloca 0 no pino do LED
		delay_us(us_delay/2);
		i++;
	}
	if(w_led) { //"traduz" a musica para os leds
		switch(atual_led) {

			case 0:
			pio_set(ELED2_PIO, ELED2_PIO_IDX_MASK);
			atual_led++;
			atual_led= atual_led%3;
			break; /* optional */
			
			case 2:
			pio_set(ELED1_PIO, ELED1_PIO_IDX_MASK);
			atual_led++;
			atual_led= atual_led%3;
			break; /* optional */
			
			/* you can have any number of case statements */
			default : /* Optional */
			pio_set(ELED3_PIO, ELED3_PIO_IDX_MASK);
			atual_led++;
			atual_led= atual_led%3;
			
		}
		
		
	}
	
	
}



void sing(int sang[], int sang_tempo[], int n, double velocity) {
	// iterate over the notes of the melody:
	int size = n;
	for (int thisNote = 0; thisNote < size; thisNote++) {
		
		// to calculate the note duration, take one second
		// divided by the note type.
		//e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
		int noteDuration = sang_tempo[thisNote]*velocity;
		
		bizz(sang[thisNote], noteDuration,1);
		
		// to distinguish the notes, set a minimum time between them.
		// the note's duration + 30% seems to work well:
		int pauseBetweenNotes = noteDuration * 1.30;
		delay_ms(pauseBetweenNotes);
		
		// stop the tone playing:
		bizz(0, noteDuration,1);
		if (!check_board_button()) {
			bizz(3000,100,0);
			break;
		}
		
	}
}

void blink_led(int n,int ms_delay){ //funcao para piscar um numero n x o led da placa
	for (int j=0; j<=n; j++){
		pio_clear(PIOC, LED_PIO_IDX_MASK);
		delay_ms(ms_delay/2);
		pio_set(PIOC, LED_PIO_IDX_MASK);
		delay_ms(ms_delay/2);
	}
	
	
}


void init(){
	/* Insert system clock initialization code here (sysclk_init()). */

	board_init();
	sysclk_init();
	
	pmc_enable_periph_clk(LED_PIO_ID);
	
	pmc_enable_periph_clk(ELED1_PIO_ID);
	
	pmc_enable_periph_clk(ELED2_PIO_ID);
	
	pmc_enable_periph_clk(ELED3_PIO_ID);
	
	pmc_enable_periph_clk(BUT_PIO_ID);
	
	pmc_enable_periph_clk(EBUT2_PIO_ID);

	//Inicializa PC8 como saída
	pio_set_output(BUZZ_PIO, BUZZ_PIO_IDX_MASK, 0, 0, 0);
	
	pio_set_output(LED_PIO, LED_PIO_IDX_MASK, 0, 0, 0);
	
	pio_set_output(ELED1_PIO, ELED1_PIO_IDX_MASK, 0, 0, 0);
	
	pio_set_output(ELED2_PIO, ELED2_PIO_IDX_MASK, 0, 0, 0);
	
	pio_set_output(ELED3_PIO, ELED3_PIO_IDX_MASK, 0, 0, 0);
	
	pio_set_input(BUT_PIO,BUT_PIO_IDX_MASK,PIO_DEFAULT);
	
	pio_set_input(EBUT2_PIO,EBUT2_PIO_IDX_MASK,PIO_DEFAULT);
	
	pio_pull_up(BUT_PIO,BUT_PIO_IDX_MASK,PIO_PULLUP);
	pio_pull_up(EBUT2_PIO,EBUT2_PIO_IDX_MASK,PIO_PULLUP);
	
	pio_set(PIOC, LED_PIO_IDX_MASK);
	pio_set(ELED1_PIO, ELED1_PIO_IDX_MASK);
	pio_set(ELED2_PIO, ELED2_PIO_IDX_MASK);
	pio_set(ELED3_PIO, ELED3_PIO_IDX_MASK);
	

	delay_init();

	gfx_mono_ssd1306_init();
	gfx_mono_draw_string("BRUNOARTC", 10,20, &sysfont);
}


int main (void)
{
	init();
	int music=1;
	while (1)
	{
		if (!pio_get(EBUT2_PIO,PIO_INPUT,EBUT2_PIO_IDX_MASK)) {
			music++;
			music %= 5;
			blink_led(music,200);
		}
		if (!check_board_button()){
			bizz(600,100,0);
			while (!check_board_button()){ //botao da placa multi-funcao
				delay_ms(10);
			}
			bizz(600,100,0);
		
			for (int i=0; i<2000000; i++)
			{
				if (!check_board_button()) {
					music++;
					music %= 5;
					blink_led(music,200);
					break;
				}
			}
			delay_ms(1000);
			if (check_board_button()){
				switch(music) {

					case 0:
					gfx_mono_draw_string("P CARIBE", 10,20, &sysfont);
					sing(pirate_notes,pirate_tempo,sizeof(pirate_notes) / sizeof(int),TRESQUARTOSTEMPO);
					break; /* optional */
				
					case 2:
					gfx_mono_draw_string("ST WARS", 10,20, &sysfont);
					sing(imperial_march_notes,imperial_march_tempo,sizeof(imperial_march_notes) / sizeof(int),TRESQUARTOSTEMPO);
					break; /* optional */
				
					case 3:
					gfx_mono_draw_string("MARIO", 10,20, &sysfont);
					sing(underworld_melody,underworld_tempo,sizeof(underworld_melody) / sizeof(int),TEMPOCOMPLETO);
					break;
				
					case 4:
					gfx_mono_draw_string("TOP GEAR", 10,20, &sysfont);
					sing(ba1,te1,sizeof(ba1) / sizeof(int),TEMPOCOMPLETO);
					break;
				
					default :
					gfx_mono_draw_string("LIVING T", 10,20, &sysfont);
					sing(ba,te,sizeof(ba) / sizeof(int),MEADETEMPO);
				
				}
				delay_ms(1000);
				} else {
				bizz(3000,100,0);
				delay_ms(1000);
			}
		
		
		
		}
	
	}
}
