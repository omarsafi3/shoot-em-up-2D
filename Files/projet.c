#include <MLV/MLV_all.h>
#include <stdio.h>
#include <stdlib.h>

void start (MLV_Image* start_background){
	int width = MLV_get_window_width();
	int height = MLV_get_window_height();
	int taille_interlinge = 9;
	
	MLV_draw_image(start_background,0,0);
	
	MLV_draw_text(
		(width/2)-60, height/4, 
		"Press START To Play",
		MLV_COLOR_WHITE
		);
		
		

	MLV_draw_text_box(
		width/2-350,height/2-50,
		300,100,
		"START",
		taille_interlinge,
		MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
		MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
		);


	MLV_draw_text_box(
		width/2+50,height/2-50,
		300,100,
		"EXIT",
		taille_interlinge,	
		MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
		MLV_TEXT_LEFT,
		MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
		);}
	
void countdown(MLV_Image* fond) {
	int width = MLV_get_window_width();
	int height = MLV_get_window_height();
	MLV_clear_window( MLV_COLOR_BLACK );
	MLV_draw_image(fond,0,0);
	MLV_draw_text(
	width/2, height/2, 
	"3",
	MLV_COLOR_BLACK
	);
	MLV_actualise_window();
	
	
	MLV_wait_seconds(1);
	
	MLV_clear_window( MLV_COLOR_BLACK );
	MLV_draw_image(fond,0,0);
	MLV_draw_text(
	width/2, height/2, 
	"2",
	MLV_COLOR_BLACK);
	MLV_actualise_window();
	
	MLV_wait_seconds(1);
	
	MLV_clear_window( MLV_COLOR_BLACK );
	MLV_draw_image(fond,0,0);
	MLV_draw_text(
	width/2, height/2, 
	"1",
	MLV_COLOR_BLACK
	);
	MLV_actualise_window();

	MLV_wait_seconds(1);
	
	MLV_clear_window( MLV_COLOR_BLACK );
	MLV_draw_image(fond,0,0);
	MLV_draw_text(
	width/2, height/2, 
	"GO",
	MLV_COLOR_BLACK
	);
	MLV_actualise_window();

	MLV_wait_seconds(1); }

	
int pause(MLV_Image* fond){
	int width = MLV_get_window_width();
	int height = MLV_get_window_height();
	int taille_interlinge = 9;
	int quit=0;

	do {
		int x=0,y=0;
		
		MLV_clear_window( MLV_COLOR_BLACK );
		MLV_draw_image(fond,0,0);
		MLV_draw_text(
			(width/2)-20, height/4, 
			"Pause",
			MLV_COLOR_WHITE
			);

		MLV_draw_text_box(
			width/2-350,height/2-50,
			300,100,
			"RESUME",
			taille_interlinge,
			MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
			MLV_TEXT_LEFT,
			MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
			);


		MLV_draw_text_box(
			width/2+50,height/2-50,
			300,100,
			"EXIT",
			taille_interlinge,	
			MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
			MLV_TEXT_LEFT,
			MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
			); 	
		MLV_actualise_window();		
		
		MLV_wait_mouse(&x, &y);
		if (((x>width/2+50) && (x<width/2+350)) && ((y>height/2-50) && (y<height/2+50)))
		{
			MLV_clear_window( MLV_COLOR_BLACK );
			MLV_draw_image(fond,0,0);
			MLV_draw_text(
				(width/2)-40, height/4, 
				"Are you sure !",
				MLV_COLOR_WHITE
				);

			MLV_draw_text_box(
				width/2-350,height/2-50,
				300,100,
				"YES",
				taille_interlinge,
				MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
				MLV_TEXT_LEFT,
				MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
				);


			MLV_draw_text_box(
				width/2+50,height/2-50,
				300,100,
				"CANCEL",
				taille_interlinge,	
				MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
				MLV_TEXT_LEFT,
				MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
				); 
			MLV_actualise_window();
			
			do {
				x=0,y=0;
				MLV_wait_mouse(&x, &y);
				if (((x>width/2-200) && (x<width/2-50)) && ((y>height/2-30) && (y<height/2+30)))
					MLV_free_window(); 
				else if (((x>width/2+50) && (x<width/2+200)) && ((y>height/2-30) && (y<height/2+30)))
					break ; 
				} while (x<0) ;
		
		}
		else if (((x>width/2-350) && (x<width/2-50)) && ((y>height/2-50) && (y<height/2+50)))
		{ quit=1 ;}
		
	} while (!quit);
	return quit ;
}

void player_shooting( MLV_Animation_player* animated_player_shot , int pos_x, int pos_y ) {
		int layer= 0;
		MLV_update_animation_player( animated_player_shot );
		MLV_draw_image_from_animation_player( animated_player_shot, layer, pos_x, pos_y );}

void enemy_movement (MLV_Animation_player* animated_enemy , int movement , int position_x , int nb_enemy ) {
	int layer = 0;
	int height = MLV_get_window_height();
	MLV_update_animation_player( animated_enemy );
	for ( int i=0 ; i<=nb_enemy ; i++ ) {
		if ( movement < height - 50 ) {
			MLV_draw_image_from_animation_player( animated_enemy, layer, position_x, movement ); }}}
			
void missile_movement (MLV_Animation_player* animated_missile_player , double x, double y) 
{ 	
	int layer = 0;
	int height = MLV_get_window_height();
	if (y<height-25) {
		MLV_draw_image_from_animation_player( animated_missile_player, layer, x, y  );
		MLV_update_animation_player( animated_missile_player );
	}
}
	

void player_movement( MLV_Animation_player* animation_player , int avance , MLV_Image* game ) { 
		int layer = 0;
		int height = MLV_get_window_height();
		int position_y = height-50;
		
		MLV_update_animation_player( animation_player );
		MLV_clear_window( MLV_COLOR_BLACK);
		MLV_draw_image(game,0,0);
		MLV_draw_image_from_animation_player( animation_player, layer, avance, position_y ); 
		MLV_delay_according_to_frame_rate(); 
		
			}

int game_over (MLV_Image* fond,MLV_Image* gov) {
	int width = MLV_get_window_width();
	int height = MLV_get_window_height();
	int taille_interlinge = 9;
	int back=0;

	do {
		int x=0,y=0;
		MLV_clear_window( MLV_COLOR_BLACK );
		MLV_draw_image(gov,150,-80);
		MLV_actualise_window();	
		MLV_wait_seconds(6);
		MLV_clear_window( MLV_COLOR_BLACK );
		MLV_draw_image(fond,0,0);
		
		MLV_draw_text_box(
			width/2-350,height/2-50,
			300,100,
			"RESTART",
			taille_interlinge,
			MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
			MLV_TEXT_LEFT,
			MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
			);


		MLV_draw_text_box(
			width/2+50,height/2-50,
			300,100,
			"EXIT",
			taille_interlinge,	
			MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
			MLV_TEXT_LEFT,
			MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
			); 	
		MLV_actualise_window();		
		
		MLV_wait_mouse(&x, &y);
		if (((x>width/2+50) && (x<width/2+350)) && ((y>height/2-50) && (y<height/2+50)))
			MLV_free_window();
		else if (((x>width/2-350) && (x<width/2-50)) && ((y>height/2-50) && (y<height/2+50)))
			back=1 ;
	} while (!back);
	return back;
}

int victoire (MLV_Image* win,MLV_Image* fond) {
	int width = MLV_get_window_width();
	int height = MLV_get_window_height();
	int taille_interlinge = 9;
	int back=0;

	do {
		int x=0,y=0;
		
		MLV_clear_window( MLV_COLOR_BLACK );
		MLV_draw_image(win,100,0);
		MLV_actualise_window();
		MLV_wait_seconds(7);
		MLV_clear_window( MLV_COLOR_BLACK );
		MLV_draw_image(fond,0,0);
		
		MLV_draw_text_box(
			width/2-350,height/2-50,
			300,100,
			"REPLAY",
			taille_interlinge,
			MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
			MLV_TEXT_LEFT,
			MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
			);


		MLV_draw_text_box(
			width/2+50,height/2-50,
			300,100,
			"EXIT",
			taille_interlinge,	
			MLV_COLOR_PURPLE, MLV_COLOR_PURPLE, MLV_COLOR_BLACK,
			MLV_TEXT_LEFT,
			MLV_HORIZONTAL_CENTER, MLV_VERTICAL_CENTER
			); 	
		MLV_actualise_window();		
		
		MLV_wait_mouse(&x, &y);
		if (((x>width/2+50) && (x<width/2+350)) && ((y>height/2-50) && (y<height/2+50)))
			MLV_free_window();
		else if (((x>width/2-350) && (x<width/2-50)) && ((y>height/2-50) && (y<height/2+50)))
			back=1 ;
	} while (!back);
	return back;
}

int main(int argc, char *argv[])
{ 
	int x,y;
	MLV_init_audio( );
	
	MLV_Music* music = MLV_load_music( "SMBSS_OV_02.ogg" );
	
	MLV_play_music( music, 1.0, -1 );
	
	MLV_create_window("shoot'em up", "shoot'em up", 1280,720);
	int width = MLV_get_window_width();
	int height = MLV_get_window_height();
	
	MLV_Image* start_background;
	MLV_Image* fond;
	MLV_Image *full_image;
	MLV_Image *exit_full_image;
	MLV_Image* game;
	MLV_Image* gov;
	MLV_Image* win;
	
	start_background = MLV_load_image("startup.png");
	full_image = MLV_load_image( "fullscreen.png" );
	exit_full_image = MLV_load_image( "fullscreen-exit.png" );
	fond = MLV_load_image("fond.png");
	game=MLV_load_image("game.jpeg");
	gov = MLV_load_image("gov.png");
	win = MLV_load_image("win.png");
	
	MLV_resize_image_with_proportions(start_background,width,height);
	MLV_resize_image_with_proportions( full_image, 24, 24);
	MLV_resize_image_with_proportions( exit_full_image, 19, 19);
	MLV_resize_image_with_proportions(fond,width,height);
	MLV_resize_image_with_proportions(game,width,height);
	MLV_resize_image_with_proportions(gov,width*1.3,height*1.3);
	MLV_resize_image_with_proportions(win,width,height);
	
	start(start_background);
	MLV_draw_image( full_image, 1240, 10 );
	
	MLV_draw_text(
		1150, 15, 
		"Fullscreen",
		MLV_COLOR_WHITE
		);
	
	MLV_actualise_window();
	

	
	int quit=0,f=0;
	while (!quit){
		MLV_wait_mouse(&x, &y);
		
		// the fullscreen choose
		if (!f) {
			if (((x>1240) && (x<1264)) && ((y>10) && (y<34)))
				{
				 f=1;
				 x=0;
				 y=0;
				 MLV_enable_full_screen( );
				 start(start_background);
				 MLV_draw_text(
					1135, 15, 
					"Exit Fullscreen",
					MLV_COLOR_WHITE
					);
				 MLV_draw_image( exit_full_image, 1240, 10 );	
				 MLV_actualise_window(); } }
		
		if (f) {
			if (((x>1240) && (x<1264)) && ((y>10) && (y<34)))
				{
				 f=0;
				 x=0;
				 y=0;
				 MLV_disable_full_screen( );
				 start(start_background);
				 MLV_draw_text(
					1150, 15, 
					"Fullscreen",
					MLV_COLOR_WHITE
					);

				 MLV_draw_image( full_image, 1240, 10 );
				 MLV_actualise_window(); } }

		
		if (((x>width/2+50) && (x<width/2+350)) && ((y>height/2-50) && (y<height/2+50))) 
			{ MLV_free_window();} 
			
		else if (((x>width/2-350) && (x<width/2-50)) && ((y>height/2-50) && (y<height/2+50)))
			{
			MLV_free_music( music );
			
			music = MLV_load_music( "countdown.wav" );		
			MLV_play_music( music, 1.0, 1);
			
			
			countdown(fond);
			
			MLV_free_music( music );

			music = MLV_load_music( "game.mp3" );		
			MLV_play_music( music, 1.0, -1 );
			
			//le depart du jeu
			// On charge les données multimédias en mémoire
			MLV_Image* spacecraft = MLV_load_image( "spacecraft.png" );
			MLV_resize_image_with_proportions( spacecraft, 50, 50);
			
			MLV_Image* projectile = MLV_load_image( "projectile.png" );
			MLV_resize_image_with_proportions( projectile, 50, 50);
			
			MLV_Image* enemy = MLV_load_image( "enemy.png" );
			MLV_resize_image_with_proportions( enemy, 50, 50);
			
			MLV_Image* missile = MLV_load_image( "bomb.png" );
			MLV_resize_image_with_proportions( missile, 50, 50);
			
			MLV_Image* lives = MLV_load_image( "spacecraft.png" );
			MLV_resize_image_with_proportions( lives, 30, 30);
			

			// On construit une animation avec les donnée multimédias
			// précédement chargées.
			MLV_Animation* animation;
			MLV_Animation* animated;
			MLV_Animation* player_shot;
			MLV_Animation* animated_missile;
			
			int nb_frames = 6;
			int nb_layers = 1;
			int nb_channels = 1;
			int h = 50;
			
			MLV_Image* image_enemy[1];
			image_enemy[0] = MLV_copy_image( enemy );
			
			MLV_Image* image_spacecraft[1];
			image_spacecraft[0]= MLV_copy_image( spacecraft );
			
			MLV_Image* image_projectile[1];
			image_projectile[0]= MLV_copy_image( projectile );

			MLV_Image* image_missile[1];
			image_missile[0]= MLV_copy_image( missile );
			
			MLV_Image* image_lives[5];
			image_lives[0] = MLV_copy_image( lives );
			image_lives[1] = MLV_copy_image( lives );
			image_lives[2] = MLV_copy_image( lives );
			image_lives[3] = MLV_copy_image( lives );
			image_lives[4] = MLV_copy_image( lives );
			
			animation = MLV_create_animation(
				nb_frames, nb_layers, nb_channels
			);

			animated = MLV_create_animation(
				nb_frames, nb_layers, nb_channels
			);
			
			player_shot = MLV_create_animation(
				nb_frames, nb_layers, nb_channels
			);
			
			animated_missile = MLV_create_animation(
				nb_frames, nb_layers, nb_channels
			);

			MLV_add_frame_in_animation( 
				image_spacecraft, NULL, 4, animation
			);
			
			MLV_add_frame_in_animation( 
				image_enemy, NULL, 4, animated
			);
			
			MLV_add_frame_in_animation( 
				image_projectile, NULL, 4, player_shot
			);
			
			MLV_add_frame_in_animation (
				image_missile, NULL, 4, animated_missile
			);

			// Création d'un lecteur d'animation
			MLV_Animation_player* animation_player = MLV_create_animation_player( animation );

			MLV_Animation_player* animated_enemy = MLV_create_animation_player( animated );
			
			MLV_Animation_player* animated_player_shot = MLV_create_animation_player( player_shot );
			
			MLV_Animation_player* animated_missile_player = MLV_create_animation_player( animated_missile );
			
			// On lance la lecture de l'animation
			MLV_play_animation_player( animation_player );
			
			MLV_play_animation_player( animated_enemy );
			
			MLV_play_animation_player( animated_player_shot );
			
			MLV_play_animation_player( animated_missile_player );

			// On fice le nombre d'image par seconde
			MLV_change_frame_rate( 60 );

			//Déclaration evenement clavier
			MLV_Keyboard_button touche;
			MLV_Button_state state;
			
			//Déclaration player movement
			int avance = width/2-h/2;
			int pas = 8;
			
			//Déclaration enemy movement
			int position_x [20] ; // la position x 
			int movement[20]; // le mouvement suivant y 
			for (int i=0 ; i<=19 ; i++) {
				position_x [i] = MLV_get_random_integer(140,width-190) ;
				movement [i] = 0; } //inistialisation de 20 coordonné
			int pas_enemy=1 ;
			int nb_enemy = 0; //nb_enemy est le nombre d'enemies affiché a l'écran  
			int time = MLV_get_time() ;
			int spawn_time ; //le temps pris pour apparaitre un autre enemy
			spawn_time = time + 3000 ;
			
			int exit=0 ; //pour crée un boucle infini
			int p=0 ; //la valeur de retour du menu pause
			
			int pos_y [3];
			int pos_x [3];
			int proj [3];
			for ( int i=0 ; i<3 ; i++ )
				{ pos_x[i] = avance ; 
				  pos_y[i] = height-100 ;
				  proj[i] = 0 ; } //prend une valeur 1 (true) s'il y a une action de shoot sinon 0 s'il n'y a pas ou hors du fenétre 
			int nb_shoot = 0 ; // nombre de shoot par le joueur ( max 3 )
			int enemy_killed=0;
			
			//missile enemy
			int timing [20] ,t[20]  ;
			double xb[20],yb[20];
			float x1[20] ;
			float a[20] ;
			float b=(620.0/4000) ;
			int test[20] ;//test d'existance
			for (int i=0 ; i<=19 ; i++) {
				xb[i]=position_x[i],yb[i]=h ;
				x1[i]=position_x[i];
				test[i]=0 ; }
				
			int nb_lives=5;
			int g=0 ,v=0 ;
			
			do
			{
				time = MLV_get_time() ;	
				if ( time > spawn_time && nb_enemy < 19)
					{ nb_enemy++ ;
					  timing[nb_enemy-1] = MLV_get_time();
					  a[nb_enemy-1]=(((avance)-x1[nb_enemy-1])/4000) ;
					  spawn_time = time + 3000 ;}
				
				MLV_get_event (
					&touche, NULL, NULL,
					NULL, NULL,
					NULL, NULL, NULL,
					&state );
					
				
				// animation du joueur
				player_movement( animation_player , avance , game);
				for (int i=0 ; i<nb_lives ;i++)
					MLV_draw_image(image_lives[i] , width-80 , 90+30*i );
				//enemy movement part
				for ( int i=0 ; i<=nb_enemy-1 ; i++ ) {	
					enemy_movement ( animated_enemy ,  movement[i] , position_x[i] ,nb_enemy ) ;
					movement [i] += pas_enemy ; 
					if ((position_x[i]<= avance+25 && position_x[i]>= avance-25) && movement[i]>=height-100 ){
						nb_lives--;
						movement[i]=-50000;
						position_x[i]=-500;
						enemy_killed++;
					}
					if (movement[i]>=height-50 && position_x[i]<width-190 && position_x[i]>140 )
						{nb_lives--;
						movement[i]=-50000;
						position_x[i]=-2000;
						enemy_killed++;}
					}
				
				//player_shooting part
				if ( touche == MLV_KEYBOARD_SPACE && state != MLV_RELEASED && nb_shoot<3 ) 
						{
						touche = MLV_KEYBOARD_NONE;
						nb_shoot++ ;
						int i=0;
						int test=0 ; 
						while ( i<nb_shoot && test==0 ) {
							if ( proj[i] == 0 ) {
								proj[i] = 1 ;
					 			pos_x[i] = avance ;
					 			test=1 ;}
					 		i++;}
					 	 }
				for (int i=0 ; i< nb_shoot ; i++) {
					if ( proj[i] == 1 )
						{ player_shooting( animated_player_shot , pos_x[i], pos_y[i] ) ;
						  pos_y[i] -= pas/2 ; }

					for (int j=0; j<=nb_enemy-1;j++){
						if ((position_x[j]-25<=pos_x[i] && position_x[j]+25>=pos_x[i]) && pos_y[i]-20<=movement[j]){
							movement[j]=-50000;
							position_x[j]=-2000;
							pos_x[i]=-500;
							pos_y[i]=-500;
							enemy_killed++;
							}
						}}
				if ( pos_y[0] < h/5 )
					{ proj[0] = 0 ;
					  nb_shoot-- ;
					  pos_y[0]=height-100;
					  for (int j=0 ; j<3 ; j++)
					  	{
					  	if (proj[j]==1){
					  		proj[j-1]=1;
					  		proj[j]=0;
					  		pos_x[j-1]=pos_x[j];
					  		pos_y[j-1]=pos_y[j] ;
					  		pos_y[j]=height-100; }
					  	}
					 }
				//animation du missiles des ennemy
				for (int i=0 ; i <= nb_enemy-1 ; i++) {
					t[i] = MLV_get_time()-timing[i];			
					if ((xb[i]<avance || yb[i] < height-25 ) ){
						test[i]=1;
						xb[i] = x1[i] + a[i]*t[i];
						yb[i] = 50 + b*t[i];
						}
					else if (xb[i]>avance || yb[i] < height-25 ){
						test[i]=1;
						xb[i] = x1[i] - a[i]*t[i];
						yb[i] = 50 + b*t[i];
						}
					else test[i]=0;
					
					if ( yb[i] > height-25 )
						{yb[i] = -2000;
						test[i]=0;}
					
					if (test[i]) {
							missile_movement (animated_missile_player, xb[i], yb[i]); 
							if((xb[i]+25>=avance && xb[i]-25<=avance) && yb[i]>=height-100){
								test[i]=0 ;
								xb[i] = -5000;
								a[i] = -5000;
								t[i]= -5000;
								nb_lives--;}
						}
						}
				MLV_actualise_window();
				
				
				
				while ((MLV_get_keyboard_state( MLV_KEYBOARD_RIGHT ) == MLV_PRESSED) && avance < width-190) 
				{
					MLV_get_event (
					&touche, NULL, NULL,
					NULL, NULL,
					NULL, NULL, NULL,
					&state );
					
					if (MLV_get_keyboard_state( MLV_KEYBOARD_LEFT ) == MLV_PRESSED && ( MLV_get_keyboard_state( MLV_KEYBOARD_RIGHT ) == MLV_PRESSED)) 
					{
						if ( touche == MLV_KEYBOARD_SPACE && state != MLV_RELEASED && nb_shoot<3 ) 
						{
							touche = MLV_KEYBOARD_NONE;
							nb_shoot++ ;
							int i=0;
							int test=0 ; 
							while ( i<nb_shoot && test==0 ) {
								if ( proj[i] == 0 ) {
									proj[i] = 1 ;
						 			pos_x[i] = avance ;
						 			test=1 ;}
						 		i++;}
							 	 }

						break;
					}	
					
					avance += pas; 
					//l'animation
					player_movement( animation_player , avance , game );
					for (int i=0 ; i<nb_lives ;i++)
						MLV_draw_image(image_lives[i] , width-80 , 90+30*i );
					
					for ( int i=0 ; i<=nb_enemy-1 ; i++ ) {	
						enemy_movement ( animated_enemy ,  movement[i] , position_x[i] ,nb_enemy ) ;
						movement [i] += pas_enemy ; 
						if ((position_x[i]<= avance+25 && position_x[i]>= avance-25) && movement[i]>=height-100 ){
							nb_lives--;
							movement[i]=-50000;
							position_x[i]=-500;
							enemy_killed++;
						}
						if (movement[i]>=height-50 && position_x[i]<width-190 && position_x[i]>140 )
								{nb_lives--;
								movement[i]=-50000;
								position_x[i]=-2000;
								enemy_killed++;}
						}
					
					//player_shooting part
					if ( touche == MLV_KEYBOARD_SPACE && state != MLV_RELEASED && nb_shoot<3 ) 
						{
						touche = MLV_KEYBOARD_NONE;
						nb_shoot++ ;
						int i=0;
						int test=0 ; 
						while ( i<nb_shoot && test==0 ) {
							if ( proj[i] == 0 ) {
								proj[i] = 1 ;
					 			pos_x[i] = avance ;
					 			test=1 ;}
					 		i++;}
					 	 }
					for (int i=0 ; i< nb_shoot ; i++) {
						if ( proj[i] == 1 )
							{ player_shooting( animated_player_shot , pos_x[i], pos_y[i] ) ;
							  pos_y[i] -= pas/2 ; }
							  
						for (int j=0; j<=nb_enemy-1;j++){
							if ((position_x[j]-25<=pos_x[i] && position_x[j]+25>=pos_x[i]) && pos_y[i]-20<=movement[j]){
								movement[j]=-20000;
								position_x[j]=-2000;
								pos_x[i]=-500;
								pos_y[i]=-500;
								enemy_killed++;
								}	
								}}
							  
							  
					if ( pos_y[0] < h/5 )
						{ proj[0] = 0 ;
						  nb_shoot-- ;
						  pos_y[0]=height-100;
						  for (int j=0 ; j<3 ; j++)
						  	{
						  	if (proj[j]==1){
						  		proj[j-1]=1;
						  		proj[j]=0;
						  		pos_x[j-1]=pos_x[j];
						  		pos_y[j-1]=pos_y[j] ;
						  		pos_y[j]=height-100; }
						  	}
					 }
					 //animation du missiles
					for (int i=0 ; i <= nb_enemy-1 ; i++) {
						t[i] = MLV_get_time()-timing[i];			
						if ((xb[i]<avance || yb[i] < height-25 ) ){
							test[i]=1;
							xb[i] = x1[i] + a[i]*t[i];
							yb[i] = 50 + b*t[i];
							}
						else if ((xb[i]>avance || yb[i] < height-25 ) ){
							test[i]=1;
							xb[i] = x1[i] - a[i]*t[i];
							yb[i] = 50 + b*t[i];
							}
						else test[i]=0;
						
						if ( yb[i] > height-25 )
							{yb[i] = -2000;
							test[i]=0;}

						if (test[i]) {
							missile_movement (animated_missile_player, xb[i], yb[i]); 
							if((xb[i]+25>=avance && xb[i]-25<=avance) && yb[i]>=height-100){
								test[i]=0 ;
								xb[i] = -5000;
								a[i] = -5000;
								t[i]= -5000;
								nb_lives--;}
						}}
					 
					MLV_actualise_window();	} 
						
					
				while (( MLV_get_keyboard_state( MLV_KEYBOARD_LEFT ) == MLV_PRESSED && avance > 140 ))
				{
					MLV_get_event (
					&touche, NULL, NULL,
					NULL, NULL,
					NULL, NULL, NULL,
					&state );
					if (MLV_get_keyboard_state( MLV_KEYBOARD_LEFT ) == MLV_PRESSED && ( MLV_get_keyboard_state( MLV_KEYBOARD_RIGHT ) == MLV_PRESSED)) 
					{
						if ( touche == MLV_KEYBOARD_SPACE && state != MLV_RELEASED && nb_shoot<3 ) 
						{
							touche = MLV_KEYBOARD_NONE;
							nb_shoot++ ;
							int i=0;
							int test=0 ; 
							while ( i<nb_shoot && test==0 ) {
								if ( proj[i] == 0 ) {
									proj[i] = 1 ;
						 			pos_x[i] = avance ;
						 			test=1 ;}
						 		i++;}
						 }
						break;
					}	
				
					avance -= pas;
					player_movement( animation_player , avance , game );
					for (int i=0 ; i<nb_lives ;i++)
						MLV_draw_image(image_lives[i] , width-80 , 90+30*i );
					
					//l'animation d'ennemy
					for ( int i=0 ; i<=nb_enemy-1 ; i++ ) {	
						enemy_movement ( animated_enemy ,  movement[i] , position_x[i] ,nb_enemy ) ;
						movement [i] += pas_enemy ; 
						if ((position_x[i]<= avance+25 && position_x[i]>= avance-25) && movement[i]>=height-100 ){
							nb_lives--;
							movement[i]=-50000;
							position_x[i]=-500;
							enemy_killed++;
						}
						if (movement[i]>=height-50 && position_x[i]<width-190 && position_x[i]>140 )
								{nb_lives--;
								movement[i]=-50000;
								position_x[i]=-2000;
								enemy_killed++;}
						}
						
					//player_shooting part
					if ( touche == MLV_KEYBOARD_SPACE && state != MLV_RELEASED && nb_shoot<3 ) 
						{
						touche = MLV_KEYBOARD_NONE;
						nb_shoot++ ;
						int i=0;
						int test=0 ; 
						while ( i<nb_shoot && test==0 ) {
							if ( proj[i] == 0 ) {
								proj[i] = 1 ;
					 			pos_x[i] = avance ;
					 			test=1 ;}
					 		i++;}
					 	 }
					for (int i=0 ; i< nb_shoot ; i++) {
						if ( proj[i] == 1 )
							{ player_shooting( animated_player_shot , pos_x[i], pos_y[i] ) ;
							  pos_y[i] -= pas/2 ; }
							
						for (int j=0; j<=nb_enemy-1;j++){
							if ((position_x[j]-25<=pos_x[i] && position_x[j]+25>=pos_x[i]) && pos_y[i]-20<=movement[j]){
								movement[j]=-20000;
								position_x[j]=-2000;
								pos_x[i]=-500;
								pos_y[i]=-500;
								enemy_killed++;
								}
							
							}}
								
					if ( pos_y[0] < h/5 )
						{ proj[0] = 0 ;
						  nb_shoot-- ;
						  pos_y[0]=height-100;
						  for (int j=0 ; j<3 ; j++)
						  	{
						  	if (proj[j]==1){
						  		proj[j-1]=1;
						  		proj[j]=0;
						  		pos_x[j-1]=pos_x[j];
						  		pos_y[j-1]=pos_y[j] ;
						  		pos_y[j]=height-100; }
						  	}
						 }
					
					//animation du missiles
					for (int i=0 ; i <= nb_enemy-1 ; i++) {
						t[i] = MLV_get_time()-timing[i];			
						if ((xb[i]<avance || yb[i] < height-25 ) ){
							test[i]=1;
							xb[i] = x1[i] + a[i]*t[i];
							yb[i] = 50 + b*t[i];
							}
						else if ((xb[i]>avance || yb[i] < height-25) ){
							test[i]=1;
							xb[i] = x1[i] - a[i]*t[i];
							yb[i] = 50 + b*t[i];
							}
						else test[i]=0;
						
						if ( yb[i] > height-25 )
							{yb[i] = -2000;
							test[i]=0;}

						if (test[i]) {
							missile_movement (animated_missile_player, xb[i], yb[i]); 
							if((xb[i]+25>=avance && xb[i]-25<=avance) && yb[i]>=height-100){
								test[i]=0 ;
								xb[i] = -5000;
								a[i] = -5000;
								t[i]= -5000;
								nb_lives--;}
						}}
						
					MLV_actualise_window();
				} 
				
				
	
				if (touche == MLV_KEYBOARD_ESCAPE ) 
					p=pause(fond); 
				touche = MLV_KEYBOARD_NONE;
				if (p) {
					p=0;
					continue ;}
				
				if (nb_lives==0){
					MLV_free_music( music );
					music = MLV_load_music( "Game Over.mp3" );
					MLV_play_music( music, 1.0, 1 );
					g=game_over(fond,gov);
					if (g) 
						exit=1;	}		
				if (enemy_killed==19) {
					exit=1; }	
	
			}
			while ( !exit );
			if (g) 
				continue ;
			
			else {
				MLV_free_music( music );
				music = MLV_load_music( "win.mp3" );
				MLV_play_music( music, 1.0, 1 );
				v=victoire(win,fond);
				if (v)
					continue ;
				 }	
			}
	}
	
	
	return 0;
}
