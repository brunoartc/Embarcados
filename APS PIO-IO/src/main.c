/**
 * Bruno Arthur Cesconetto (brunoartc)
 *
 */

/************************************************************************/
/* includes                                                             */
/************************************************************************/

#include "asf.h"

/************************************************************************/
/* defines                                                              */
/************************************************************************/

#define BUZZ_PIO           PIOC                  // periferico que controla o LED
#define BUZZ_PIO_ID        12                    // ID do periférico PIOC (controla LED)
#define BUZZ_PIO_IDX      17u                    // ID do LED no PIO
#define BUZZ_PIO_IDX_MASK  (1u << BUZZ_PIO_IDX)   // Mascara para CONTROLARMOS o LED

#define LED_PIO           PIOC                  // periferico que controla o LED
#define LED_PIO_ID        12                    // ID do periférico PIOC (controla LED)
#define LED_PIO_IDX		8u                    // ID do LED no PIO
#define LED_PIO_IDX_MASK  (1u << LED_PIO_IDX)   // Mascara para CONTROLARMOS o LED

#define ELED1_PIO           PIOC                  // periferico que controla o LED
#define ELED1_PIO_ID        12                    // ID do periférico PIOC (controla LED)
#define ELED1_PIO_IDX		19u                    // ID do LED no PIO
#define ELED1_PIO_IDX_MASK  (1u << ELED1_PIO_IDX)   // Mascara para CONTROLARMOS o LED




#define BUT_PIO PIOA
#define BUT_PIO_ID 10
#define BUT_PIO_IDX 11
#define BUT_PIO_IDX_MASK (1u << BUT_PIO_IDX)



#define EBUT1_PIO PIOA //start EXT 9
#define EBUT1_PIO_ID 10
#define EBUT1_PIO_IDX 2
#define EBUT1_PIO_IDX_MASK (1u << EBUT1_PIO_IDX)


#define EBUT2_PIO PIOC //pause  Ext 4
#define EBUT2_PIO_ID 12
#define EBUT2_PIO_IDX 13
#define EBUT2_PIO_IDX_MASK (1u << EBUT2_PIO_IDX)


#define EBUT3_PIO PIOA //sei la EXT 3
#define EBUT3_PIO_ID 10
#define EBUT3_PIO_IDX 11
#define EBUT3_PIO_IDX_MASK (1u << EBUT3_PIO_IDX)



#define NOTE_C4  262   //Defining note frequency
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880
#define NOTE_B5 988


//start wars

#define c  261
#define d  294
#define e  329
#define f  349
#define g  391
#define gS  415
#define a  440
#define aS  455
#define b  466
#define cH  523
#define cSH  554
#define dH  587
#define dSH  622
#define eH  659
#define fH  698
#define fSH  740
#define gH  784
#define gSH  830
#define aH  880

//
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978


 

/************************************************************************/
/* constants                                                            */
/************************************************************************/
const int songspeed = 1;

//piratas do caribe musica
int pirate_notes[] = { 
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
	NOTE_A4, NOTE_G4, NOTE_A4, 0,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
	NOTE_A4, NOTE_G4, NOTE_A4, 0,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
	NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
	NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
	
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_D5, NOTE_E5, NOTE_A4, 0,
	NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
	NOTE_C5, NOTE_A4, NOTE_B4, 0,

	NOTE_A4, NOTE_A4,
	//Repeat of first part
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
	NOTE_A4, NOTE_G4, NOTE_A4, 0,

	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_C5, NOTE_D5, NOTE_B4, NOTE_B4, 0,
	NOTE_A4, NOTE_G4, NOTE_A4, 0,
	
	NOTE_E4, NOTE_G4, NOTE_A4, NOTE_A4, 0,
	NOTE_A4, NOTE_C5, NOTE_D5, NOTE_D5, 0,
	NOTE_D5, NOTE_E5, NOTE_F5, NOTE_F5, 0,
	NOTE_E5, NOTE_D5, NOTE_E5, NOTE_A4, 0,
	
	NOTE_A4, NOTE_B4, NOTE_C5, NOTE_C5, 0,
	NOTE_D5, NOTE_E5, NOTE_A4, 0,
	NOTE_A4, NOTE_C5, NOTE_B4, NOTE_B4, 0,
	NOTE_C5, NOTE_A4, NOTE_B4, 0,
	//End of Repeat

	NOTE_E5, 0, 0, NOTE_F5, 0, 0,
	NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
	NOTE_D5, 0, 0, NOTE_C5, 0, 0,
	NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4,

	NOTE_E5, 0, 0, NOTE_F5, 0, 0,
	NOTE_E5, NOTE_E5, 0, NOTE_G5, 0, NOTE_E5, NOTE_D5, 0, 0,
	NOTE_D5, 0, 0, NOTE_C5, 0, 0,
	NOTE_B4, NOTE_C5, 0, NOTE_B4, 0, NOTE_A4
};
//piratas do caribe tempo
int pirate_tempo[] = {         //duration of each note (in ms) Quarter Note is set to 250 ms
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 125,
	
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 125,
	
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 125, 250, 125,

	125, 125, 250, 125, 125,
	250, 125, 250, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 375,

	250, 125,
	//Rpeat of First Part
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 125,
	
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 125,
	
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 250, 125, 125,
	125, 125, 125, 250, 125,

	125, 125, 250, 125, 125,
	250, 125, 250, 125,
	125, 125, 250, 125, 125,
	125, 125, 375, 375,
	//End of Repeat
	
	250, 125, 375, 250, 125, 375,
	125, 125, 125, 125, 125, 125, 125, 125, 375,
	250, 125, 375, 250, 125, 375,
	125, 125, 125, 125, 125, 500,

	250, 125, 375, 250, 125, 375,
	125, 125, 125, 125, 125, 125, 125, 125, 375,
	250, 125, 375, 250, 125, 375,
	125, 125, 125, 125, 125, 500
};
int mario_theme_notes[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,
  
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
  
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,
  
  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,
  
  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Mario main them tempo
int mario_theme_tempo[] = {
	83, 83, 83, 83,
	83, 83, 83, 83,
	83, 83, 83, 83,
	83, 83, 83, 83,
	
	83, 83, 83, 83,
	83, 83, 83, 83,
	83, 83, 83, 83,
	83, 83, 83, 83,
	
	112, 112, 112,
	83, 83, 83, 83,
	83, 83, 83, 83,
	83, 83, 83, 83,
	
	83, 83, 83, 83,
	83, 83, 83, 83,
	83, 83, 83, 83,
	83, 83, 83, 83,
	
	112, 112, 112,
	83, 83, 83, 83,
	83, 83, 83, 83,
	83, 83, 83, 83,
};
//Underworld melody
int underworld_melody[] = {
	NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
	NOTE_AS3, NOTE_AS4, 0,
	0,
	NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
	NOTE_AS3, NOTE_AS4, 0,
	0,
	NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
	NOTE_DS3, NOTE_DS4, 0,
	0,
	NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
	NOTE_DS3, NOTE_DS4, 0,
	0, NOTE_DS4, NOTE_CS4, NOTE_D4,
	NOTE_CS4, NOTE_DS4,
	NOTE_DS4, NOTE_GS3,
	NOTE_G3, NOTE_CS4,
	NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
	NOTE_GS4, NOTE_DS4, NOTE_B3,
	NOTE_AS3, NOTE_A3, NOTE_GS3,
	0, 0, 0
};
//Underwolrd tempo
int underworld_tempo[] = {
	83, 83, 83, 83,
	83, 83, 166,
	333,
	83, 83, 83, 83,
	83, 83, 166,
	333,
	83, 83, 83, 83,
	83, 83, 166,
	333,
	83, 83, 83, 83,
	83, 83, 166,
	166, 55, 55, 55,
	166, 166,
	166, 166,
	166, 166,
	55, 55, 55, 55, 55, 55,
	100, 100, 100,
	100, 100, 100,
	333, 333, 333
};


/************************************************************************/
/* variaveis globais                                                    */
/************************************************************************/

/************************************************************************/
/* prototypes                                                           */
/************************************************************************/

void init(void);

/************************************************************************/
/* interrupcoes                                                         */
/************************************************************************/

/************************************************************************/
/* funcoes                                                              */
/************************************************************************/

// Função de inicialização do uC
void init(void){
	// Initialize the board clock
	sysclk_init();
	
	// Disativa WatchDog Timer
	WDT->WDT_MR = WDT_MR_WDDIS;

	// Ativa o PIO na qual o LED foi conectado
	// para que possamos controlar o LED.
	pmc_enable_periph_clk(LED_PIO_ID);
	
	pmc_enable_periph_clk(BUT_PIO_ID);
	
	pmc_enable_periph_clk(EBUT2_PIO_ID);

	//Inicializa PC8 como saída
	pio_set_output(BUZZ_PIO, BUZZ_PIO_IDX_MASK, 0, 0, 0);
	
	pio_set_output(LED_PIO, LED_PIO_IDX_MASK, 0, 0, 0);
	
	pio_set_output(ELED1_PIO, ELED1_PIO_IDX_MASK, 0, 0, 0);
	
	pio_set_input(BUT_PIO,BUT_PIO_IDX_MASK,PIO_DEFAULT);
	
	pio_set_input(EBUT2_PIO,EBUT2_PIO_IDX_MASK,PIO_DEFAULT);
	
	pio_pull_up(BUT_PIO,BUT_PIO_IDX_MASK,PIO_PULLUP);
	pio_pull_up(EBUT2_PIO,EBUT2_PIO_IDX_MASK,PIO_PULLUP);
	
	pio_set(PIOC, LED_PIO_IDX_MASK);
	pio_set(PIOC, ELED1_PIO_IDX_MASK);
	
	
}

/************************************************************************/
/* Main                                                                 */
/************************************************************************/

int atual_led = 0;

void bizz(int frequencia, int tempo_ms, int w_led){
	int us_delay = 1000000/frequencia;
	int tempo = tempo_ms * 1000;
	
	int i = 0;
	
	if(w_led) {
		if (atual_led==1){
			pio_clear(PIOC, LED_PIO_IDX_MASK);
		} else {
			pio_clear(PIOC, ELED1_PIO_IDX_MASK);
		}
			
		
	}
	while (i<tempo/us_delay){
		pio_set(PIOC, BUZZ_PIO_IDX_MASK);      // Coloca 1 no pino LED
		delay_us(us_delay/2);
		pio_clear(PIOC, BUZZ_PIO_IDX_MASK);    // Coloca 0 no pino do LED
		delay_us(us_delay/2);
		i++;
	}
	if(w_led) {
		if (atual_led==1){
			pio_set(PIOC, LED_PIO_IDX_MASK);
			atual_led++;
			atual_led= atual_led%3;
		} else {
			pio_set(PIOC, ELED1_PIO_IDX_MASK);
			atual_led++;
			atual_led= atual_led%3;
		}
		
		
	}
	
	
}

//marcha imperial
int imperial_march_notes[] = {
	a,a,a,f,cH,a,f,cH,a,0,eH,eH,eH,fH,cH,gS,f,cH,a,0
};

int imperial_march_tempo[] = {
	500,500,500,350,150,500,350,150,650,500,500,500,500,350,150,500,350,150,650,500
};



int ba[] = {622, 622, 554, 554, 622, 622, 622, 622, 622, 622, 554, 554, 554, 554, 622, 622, 554, 554, 554, 554, 554, 554, 466, 466, 932, 932, 523, 523, 554, 554, 554, 554, 622, 622, 523, 523, 440, 440, 698, 698, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 311, 311, 233, 233, 277, 277, 277, 277, 311, 311, 349, 349, 277, 277, 311, 311, 277, 277, 233, 233, 277, 277, 349, 349, 369, 369, 349, 349, 277, 277, 311, 311, 349, 349, 369, 369, 349, 349, 311, 311, 277, 277, 277, 277, 415, 415, 349, 349, 311, 311, 277, 277, 415, 415, 349, 349, 311, 311, 277, 277, 466, 466, 466, 466, 415, 415, 369, 369, 349, 349, 277, 277, 369, 369, 349, 349, 277, 277, 277, 277, 349, 349, 369, 369, 349, 349, 277, 277, 311, 311, 349, 349, 349, 349, 369, 369, 349, 349, 311, 311, 311, 311, 277, 277, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 311, 311, 233, 233, 233, 233, 277, 277, 277, 277, 311, 311, 311, 311, 349, 349, 277, 277, 311, 311, 277, 277, 233, 233, 277, 277, 349, 349, 349, 349, 369, 369, 349, 349, 277, 277, 311, 311, 349, 349, 349, 349, 349, 349, 369, 369, 349, 349, 311, 311, 277, 277, 277, 277, 415, 415, 349, 349, 311, 311, 277, 277, 415, 415, 349, 349, 311, 311, 277, 277, 466, 466, 415, 415, 369, 369, 277, 277, 369, 369, 349, 349, 277, 277, 277, 277, 349, 349, 369, 369, 349, 349, 277, 277, 311, 311, 349, 349, 349, 349, 369, 369, 349, 349, 311, 311, 277, 277, 466, 466, 554, 554, 622, 622, 523, 523, 466, 466, 554, 554, 466, 466, 493, 493, 466, 466, 587, 587, 493, 493, 493, 493, 466, 466, 415, 415, 369, 369, 369, 369, 369, 369, 349, 349, 369, 369, 349, 349, 311, 311, 311, 311, 277, 277, 466, 466, 554, 554, 622, 622, 523, 523, 466, 466, 466, 466, 554, 554, 554, 554, 466, 466, 493, 493, 466, 466, 587, 587, 493, 493, 493, 493, 466, 466, 415, 415, 369, 369, 369, 369, 349, 349, 349, 349, 369, 369, 349, 349, 311, 311, 311, 311, 277, 277, 466, 466, 554, 554, 698, 466, 698, 466, 554, 554, 739, 739, 466, 466, 415, 415, 523, 523, 622, 622, 739, 523, 739, 523, 622, 622, 830, 830, 622, 622, 523, 523, 554, 554, 698, 698, 830, 554, 830, 554, 698, 698, 932, 932, 830, 830, 554, 554, 523, 523, 622, 622, 830, 523, 830, 523, 932, 932, 830, 830, 466, 466, 554, 554, 698, 466, 698, 466, 554, 554, 739, 739, 466, 466, 415, 415, 523, 523, 622, 622, 739, 523, 739, 523, 622, 622, 830, 830, 622, 622, 523, 523, 554, 554, 698, 698, 830, 554, 830, 554, 698, 698, 932, 932, 830, 830, 554, 554, 523, 523, 622, 622, 830, 523, 830, 523, 932, 932, 830, 830, 466, 466, 554, 554, 698, 466, 698, 466, 554, 554, 739, 739, 466, 466, 415, 415, 523, 523, 622, 622, 739, 523, 739, 523, 622, 622, 830, 830, 622, 622, 523, 523, 554, 554, 698, 698, 830, 554, 830, 554, 698, 698, 932, 932, 830, 830, 554, 554, 523, 523, 622, 622, 830, 1046, 830, 1046, 1108, 1108, 1046, 1046, 932, 932, 830, 830, 466, 466, 554, 554, 698, 466, 698, 466, 554, 554, 739, 739, 466, 466, 415, 415, 523, 523, 622, 622, 739, 523, 739, 523, 622, 622, 830, 830, 622, 622, 523, 523, 554, 554, 698, 698, 830, 554, 830, 554, 698, 698, 932, 932, 830, 830, 554, 554, 523, 523, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 311, 311, 233, 233, 233, 233, 233, 233, 277, 277, 277, 277, 311, 311, 349, 349, 277, 277, 311, 311, 277, 277, 233, 233, 277, 277, 277, 277, 349, 349, 349, 349, 369, 369, 349, 349, 277, 277, 311, 311, 349, 349, 349, 349, 369, 369, 349, 349, 311, 311, 277, 277, 277, 277, 415, 415, 349, 349, 311, 311, 277, 277, 415, 415, 349, 349, 311, 311, 277, 277, 466, 466, 415, 415, 369, 369, 349, 349, 277, 277, 369, 369, 349, 349, 277, 277, 277, 277, 349, 349, 369, 369, 349, 349, 277, 277, 311, 311, 349, 349, 369, 369, 349, 349, 311, 311, 277, 277, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 349, 311, 311, 233, 233, 233, 233, 233, 233, 277, 277, 277, 277, 311, 311, 311, 311, 349, 349, 277, 277, 311, 311, 277, 277, 233, 233, 277, 277, 349, 349, 369, 369, 349, 349, 277, 277, 311, 311, 349, 349, 369, 369, 349, 349, 311, 311, 277, 277, 277, 277, 415, 415, 349, 349, 311, 311, 277, 277, 415, 415, 349, 349, 311, 311, 277, 277, 466, 466, 415, 415, 369, 369, 277, 277, 369, 369, 277, 277, 277, 277, 349, 349, 369, 369, 349, 349, 277, 277, 311, 311, 349, 349, 349, 349, 369, 369, 349, 349, 311, 311, 277, 277, 466, 466, 554, 554, 622, 622, 523, 523, 466, 466, 554, 554, 466, 466, 493, 493, 466, 466, 587, 587, 493, 493, 493, 493, 466, 466, 415, 415, 369, 369, 369, 369, 369, 369, 349, 349, 369, 369, 349, 349, 311, 311, 311, 311, 277, 277, 466, 466, 554, 554, 622, 622, 523, 523, 466, 466, 466, 466, 554, 554, 554, 554, 466, 466, 493, 493, 466, 466, 587, 587, 493, 493, 493, 493, 466, 466, 415, 415, 369, 369, 369, 369, 349, 349, 349, 349, 369, 369, 349, 349, 311, 311, 311, 311, 277, 277, 233, 233, 277, 277, 349, 349, 233, 233, 277, 277, 349, 349, 246, 246, 277, 277, 349, 349, 246, 246, 277, 277, 415, 415, 369, 369, 466, 466, 554, 554, 369, 369, 440, 440, 622, 622, 349, 349, 415, 415, 554, 554, 349, 349, 311, 311, 277, 277, 233, 233, 277, 277, 349, 349, 233, 233, 277, 349, 277, 261, 349, 261, 246, 246, 277, 277, 349, 349, 246, 246, 277, 415, 277, 207, 415, 207, 369, 369, 466, 466, 554, 554, 369, 369, 466, 277, 466, 622, 277, 207, 622, 207, 349, 261, 261, 277, 349, 277, 415, 261, 415, 261, 554, 554, 349, 349, 311, 311, 277, 277, 261, 261, 277, 277, 233, 233};
int te[] = {0, 240, 240, 240, 0, 240, 720, 240, 0, 240, 240, 240, 0, 240, 0, 240, 480, 240, 0, 240, 240, 240, 0, 240, 0, 240, 480, 240, 0, 240, 240, 240, 0, 240, 0, 240, 240, 240, 240, 240, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 360, 0, 480, 120, 240, 0, 120, 0, 240, 0, 240, 0, 120, 0, 240, 0, 120, 0, 480, 0, 240, 0, 240, 0, 240, 0, 240, 0, 120, 0, 360, 0, 240, 0, 240, 0, 120, 0, 360, 0, 960, 480, 120, 0, 360, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 120, 0, 240, 0, 240, 0, 120, 0, 240, 0, 120, 0, 120, 0, 120, 0, 240, 0, 120, 0, 480, 0, 240, 0, 240, 0, 240, 0, 240, 0, 120, 0, 240, 0, 120, 0, 240, 0, 120, 0, 120, 0, 120, 0, 360, 0, 480, 1320, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 360, 0, 480, 0, 120, 0, 240, 0, 120, 0, 120, 0, 120, 0, 240, 0, 120, 0, 240, 0, 120, 0, 480, 0, 120, 0, 240, 0, 120, 0, 240, 0, 240, 0, 120, 0, 240, 0, 120, 0, 120, 0, 120, 0, 240, 0, 120, 0, 360, 0, 480, 960, 120, 0, 360, 0, 240, 0, 240, 0, 120, 0, 360, 0, 240, 0, 240, 0, 120, 0, 360, 0, 240, 0, 240, 0, 120, 0, 240, 0, 120, 0, 360, 240, 120, 0, 240, 0, 240, 0, 240, 0, 120, 0, 240, 0, 240, 0, 120, 0, 240, 0, 120, 0, 360, 0, 480, 960, 240, 0, 480, 0, 240, 0, 480, 480, 240, 0, 240, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 120, 0, 240, 0, 240, 0, 480, 0, 120, 0, 120, 0, 360, 0, 240, 0, 240, 0, 120, 0, 360, 0, 720, 720, 240, 0, 480, 0, 240, 0, 480, 360, 120, 0, 120, 0, 240, 0, 120, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 240, 0, 120, 0, 360, 0, 480, 0, 120, 0, 240, 0, 120, 0, 240, 0, 240, 0, 120, 0, 360, 0, 720, 960, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 240, 0, 240, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 240, 0, 240, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 120, 0, 0, 120, 0, 120, 0, 120, 0, 120, 0, 480, 0, 480, 120, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 360, 0, 360, 0, 120, 0, 120, 0, 240, 0, 120, 0, 240, 0, 240, 0, 120, 0, 240, 0, 120, 0, 360, 0, 120, 0, 120, 0, 240, 0, 120, 0, 240, 0, 120, 0, 240, 0, 240, 0, 240, 0, 120, 0, 120, 0, 240, 0, 360, 0, 480, 960, 240, 0, 240, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 120, 0, 120, 0, 120, 0, 240, 0, 120, 0, 480, 0, 240, 0, 240, 0, 240, 0, 120, 0, 240, 0, 240, 0, 360, 0, 120, 0, 240, 0, 360, 0, 480, 1320, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 120, 0, 240, 0, 120, 0, 480, 0, 120, 0, 240, 0, 120, 0, 120, 0, 120, 0, 240, 0, 120, 0, 240, 0, 120, 0, 480, 0, 120, 0, 360, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 240, 0, 120, 0, 360, 0, 480, 960, 240, 0, 240, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 120, 0, 240, 0, 360, 0, 360, 120, 240, 0, 240, 0, 240, 0, 240, 0, 120, 0, 240, 0, 120, 0, 240, 0, 240, 0, 120, 0, 360, 0, 480, 960, 240, 0, 480, 0, 240, 0, 480, 480, 240, 0, 240, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 120, 0, 240, 0, 240, 0, 480, 0, 120, 0, 120, 0, 360, 0, 240, 0, 240, 0, 120, 0, 360, 0, 720, 720, 240, 0, 480, 0, 240, 0, 480, 360, 120, 0, 120, 0, 240, 0, 120, 0, 240, 0, 120, 0, 240, 0, 360, 0, 240, 0, 240, 0, 120, 0, 360, 0, 480, 0, 120, 0, 240, 0, 120, 0, 240, 0, 240, 0, 120, 0, 360, 0, 720, 960, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 480, 240, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 480, 240, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 480, 240, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 240, 240, 0, 240, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 240, 240, 0, 240, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 0, 240, 0, 240, 0, 240, 240, 0, 0, 120, 0, 120, 0, 0, 0, 240, 0, 0, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 240, 0, 480};

	
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
		if (!pio_get(BUT_PIO,PIO_INPUT,BUT_PIO_IDX_MASK)) {
			bizz(3000,100,0);
			break;
		}
		
	}
}

void blink_led(int n,int ms_delay){
	for (int j=0; j<=n; j++){
		pio_clear(PIOC, LED_PIO_IDX_MASK);
		delay_ms(ms_delay/2);
		pio_set(PIOC, LED_PIO_IDX_MASK);
		delay_ms(ms_delay/2);
	}
	
	
}


// Funcao principal chamada na inicalizacao do uC.
int main(void)
{
	// inicializa sistema e IOs
	init();
	
	int music=1;
	

	// super loop
	// aplicacoes embarcadas não devem sair do while(1).
	while (1)
	{
		
		if (!pio_get(EBUT2_PIO,PIO_INPUT,EBUT2_PIO_IDX_MASK)) {
			music++;
			music %= 4;
			blink_led(music,200);
		}
		
		if (!pio_get(BUT_PIO,PIO_INPUT,BUT_PIO_IDX_MASK)){
			bizz(600,100,0);
			while (!pio_get(BUT_PIO,PIO_INPUT,BUT_PIO_IDX_MASK)){
				delay_ms(10);
			}
			bizz(600,100,0);
			
			for (int i=0; i<2000000; i++)
			{
				if (!pio_get(BUT_PIO,PIO_INPUT,BUT_PIO_IDX_MASK)) {
					music++;
					music %= 4;
					blink_led(music,200);
					break;
				}
			}
			
			delay_ms(1000);
			
			
			if (pio_get(BUT_PIO,PIO_INPUT,BUT_PIO_IDX_MASK)){
				switch(music) {

					case 0:
					sing(pirate_notes,pirate_tempo,sizeof(pirate_notes) / sizeof(int),0.75);
					break; /* optional */
				
					case 2:
					sing(imperial_march_notes,imperial_march_tempo,sizeof(imperial_march_notes) / sizeof(int),0.75);
					break; /* optional */
					
					case 3:
					sing(underworld_melody,underworld_tempo,sizeof(underworld_melody) / sizeof(int),1);
					break;
				
					/* you can have any number of case statements */
					default : /* Optional */
					sing(ba,te,sizeof(ba) / sizeof(int),0.5);
					
				}
				delay_ms(1000);
			} else {
				bizz(3000,100,0);
				delay_ms(1000);
			}
			
			
			
		}
		
	}
	return 0;
}
