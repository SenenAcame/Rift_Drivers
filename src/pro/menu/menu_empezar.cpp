#include "menu_empezar.h"
#include <iostream>

#include <allegro.h>

int main() 
{	
	allegro_init();
	install_keyboard();
	
	set_color_depth(32);
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	
	bool salida = false;
	int paso = 1;
	int ticks;
    int tiempo_ticks;
    int frame = 0;
    int pos = 0; 
    int op = 1;
    int sw = 0;
	
    ticks = CLOCKS_PER_SEC / 20;
    tiempo_ticks=0;
	
	BITMAP *buffer = create_bitmap(640, 480);
	BITMAP *fondo;
	BITMAP *fondo2;	
	
	clear_to_color(buffer, 0x000000);
	
	fondo = load_bitmap("menuc01.bmp",NULL);
	fondo2 = load_bitmap("menuc02.bmp",NULL);	
		
	while ( !salida )
	{
       if ( clock() > tiempo_ticks + ticks )
       { 
           // obtenemos el nuevo tiempo 
           tiempo_ticks=clock();    
           frame++;
          if( !key[KEY_UP] && !key[KEY_DOWN] && sw == 1 )
          {
              sw = 0;
          } 
           
          if ( key[KEY_UP] && sw == 0)
          {
               op--;
               if (op == 0) op = 4;
               sw = 1;
           }
           if ( key[KEY_DOWN] && sw == 0)
          {
               op++;
               if (op == 5) op = 1;
               sw = 1;
           }
           
          if ( op == 4 && key[KEY_ENTER] )
          {
               salida = true;
           } 
          // borramos todo
          clear_to_color(buffer, 0x000000);

          if ( paso == 3 )
          {
              blit(fondo, buffer, 0, 0, 0, 0, 640, 480);
          }
          
          if ( paso >= 4 )
          {
              blit(fondo2, buffer, 0, 0, 0, 0, 640, 480);
          }
          
    textout_ex(buffer, font, "http://devcpp-allegro.blogspot.com/" , 10, 465, 0xFFFFFF, 0x000000);          
    textout_ex(buffer, font, "Allegro V. ", 510, 465, 0xFFFFFF, 0x000000);
 	textout_ex(buffer, font, ALLEGRO_VERSION_STR, 590, 465, 0xFFFFFF, 0x000000);
          
          if ( paso > 0 && paso < 5 )
          {
             // recuadro de los mensajes 
             rectfill(buffer, 40, 20, 600, 60, 0x444455);
             rect(buffer, 40, 20, 600, 60, 0xdddddd);
          }   
          if ( paso == 1 )
          {
             if ( frame > 20 )  
             textout_centre_ex(buffer, font, "NUEVA PARTIDA" , 200, 90, 0xFFFFFF, 0x333333);
             if ( frame > 40 )  
             textout_centre_ex(buffer, font, "CARGAR PARTIDA" , 200, 140, 0xFFFFFF, 0x333333);
             if ( frame > 60 )  
             textout_centre_ex(buffer, font, "OPCIONES" , 200, 190, 0xFFFFFF, 0x333333);
             if ( frame > 80 )  
             textout_centre_ex(buffer, font, "SALIR" , 200, 240, 0xFFFFFF, 0x333333);               
              
           }
          if ( paso == 2 )
          {
               pos = frame;
           }
          
          if ( paso > 1 )
          {
             if ( op == 1 )
             {  
               textout_centre_ex(buffer, font, "NUEVA PARTIDA" , 200+pos, 90+pos, 0xdF4334, 0x333333);
              }else{
               textout_centre_ex(buffer, font, "NUEVA PARTIDA" , 200+pos, 90+pos, 0xFFFFFF, 0x333333);     
              }
             if ( op == 2 )
             {               
             textout_centre_ex(buffer, font, "CARGAR PARTIDA" , 200+pos, 140+pos, 0xdF4334, 0x333333);
              }else{
             textout_centre_ex(buffer, font, "CARGAR PARTIDA" , 200+pos, 140+pos, 0xFFFFFF, 0x333333);                    
              }                   
             if ( op == 3 )
             { 
             textout_centre_ex(buffer, font, "OPCIONES" , 200+pos, 190+pos, 0xdF4334, 0x333333);
              }else{
             textout_centre_ex(buffer, font, "OPCIONES" , 200+pos, 190+pos, 0xFFFFFF, 0x333333);                    
              }
             if ( op == 4 )
             { 
             textout_centre_ex(buffer, font, "SALIR" , 200+pos, 240+pos, 0xdF4334, 0x333333);               
              }else{
             textout_centre_ex(buffer, font, "SALIR" , 200+pos, 240+pos, 0xFFFFFF, 0x333333);                                   
              }
           }
       
          switch ( paso )
          {
               case 1:
                    // Opciones para nuestro menu
                    textout_centre_ex(buffer, font, "Paso 1: Se Definen las opciones que tendra el menu" , 320, 35, 0xFFFFFF, 0x444455);
                    
                    break;
               case 2:
                    // Colocando opciones por pantalla
                    textout_centre_ex(buffer, font, "Paso 2: Se colocan las opciones en la pantalla" , 320, 35, 0xFFFFFF, 0x444455);
                    break;
               case 3:
                    // poniendo imagen de fondo
                    textout_centre_ex(buffer, font, "Paso 3: Decoramos el menu con una imagen de fondo" , 320, 35, 0xFFFFFF, 0x444455);
                    break;
               case 4:
                    // escojer una buena imagen
                    textout_centre_ex(buffer, font, "Paso 3: Segun la imagen, el menu tendra un mejor aspecto" , 320, 35, 0xFFFFFF, 0x444455);
                    break;
               default:;                                                                 
          }
          
          if (frame > 120 && paso < 5 )
          {
               paso++;
               frame=0;     
          }
          

          
       }    

	   blit(buffer, screen, 0, 0, 0, 0, 640, 480);

	      
       if ( key[KEY_ESC] )
       {
           salida = true;
       }
    }
	
	
	destroy_bitmap(buffer);
	destroy_bitmap(fondo);
	destroy_bitmap(fondo2);    	
	
	return 0;
}
END_OF_MAIN();