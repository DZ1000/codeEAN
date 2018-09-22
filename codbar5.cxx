#include <cstdlib>
#include <cstring>
#include <ctime>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> 
#include <SFML/System.hpp> 
#include <wiringPi.h>
#include <wiringPiI2C.h>

#include <mysql/mysql.h>

using namespace sf;
using namespace std;

//**********class**************
class codbar
{
	public :
	int posx;
	int posy;
	int i;
	int n;
	int m;
	int mem10;
	int sizex;
	int sizey1;
	int sizey2;
	bool b1;
	bool Vguardzone [3];
	bool Vblock10 [70];
	bool Vblock20 [70];
	bool Vmiddle [5];
	string recpath;
	string filename;
	Image Iimage1;   
    Texture Ttexture1;
    Sprite Ssprite1;
    Image Iimage2;   
    Texture Ttexture2;
    Sprite Ssprite2;

	public :
	codbar ();
	Sprite background();
	Sprite drawguardzone(int);
	Sprite drawmidzone();
	Sprite drawnumberleft(int, int);
	Sprite drawnumberright(int, int);
	Sprite drawtextleft	(int, int);
	Sprite drawtextright (int, int);
	void savepic(string);
		
};
codbar::codbar ()
{

i=0;
n=0;
m=0;
mem10=0;
sizex = 5;
sizey1 = 200;
sizey2 = 160;

recpath = "/home/pi/Documents/codbar/";


Vguardzone[0]=1;
Vguardzone[1]=0;
Vguardzone[2]=1;

//0
Vblock10[0] = 0; 
Vblock10[1] = 0; 
Vblock10[2] = 0; 
Vblock10[3] = 1; 
Vblock10[4] = 1; 
Vblock10[5] = 0; 
Vblock10[6] = 1; 
//1
Vblock10[7] = 0; 
Vblock10[8] = 0; 
Vblock10[9] = 1; 
Vblock10[10] = 1; 
Vblock10[11] = 0; 
Vblock10[12] = 0; 
Vblock10[13] = 1; 
//2
Vblock10[14] = 0; 
Vblock10[15] = 0; 
Vblock10[16] = 1; 
Vblock10[17] = 0; 
Vblock10[18] = 0; 
Vblock10[19] = 1; 
Vblock10[20] = 1; 
//3
Vblock10[21] = 0; 
Vblock10[22] = 1; 
Vblock10[23] = 1; 
Vblock10[24] = 1; 
Vblock10[25] = 1; 
Vblock10[26] = 0; 
Vblock10[27] = 1; 
//4
Vblock10[28] = 0; 
Vblock10[29] = 1; 
Vblock10[30] = 0; 
Vblock10[31] = 0; 
Vblock10[32] = 0; 
Vblock10[33] = 1; 
Vblock10[34] = 1; 
//5
Vblock10[35] = 0; 
Vblock10[36] = 1; 
Vblock10[37] = 1; 
Vblock10[38] = 0; 
Vblock10[39] = 0; 
Vblock10[40] = 0; 
Vblock10[41] = 1; 
//6
Vblock10[42] = 0; 
Vblock10[43] = 1; 
Vblock10[44] = 0; 
Vblock10[45] = 1; 
Vblock10[46] = 1; 
Vblock10[47] = 1; 
Vblock10[48] = 1; 
//7
Vblock10[49] = 0; 
Vblock10[50] = 1; 
Vblock10[51] = 1; 
Vblock10[52] = 1; 
Vblock10[53] = 0; 
Vblock10[54] = 1; 
Vblock10[55] = 1; 
//8
Vblock10[56] = 0; 
Vblock10[57] = 1; 
Vblock10[58] = 1; 
Vblock10[59] = 0; 
Vblock10[60] = 1; 
Vblock10[61] = 1; 
Vblock10[62] = 1; 
//9
Vblock10[63] = 0; 
Vblock10[64] = 0; 
Vblock10[65] = 0; 
Vblock10[66] = 1; 
Vblock10[67] = 0; 
Vblock10[68] = 1; 
Vblock10[69] = 1; 

Vmiddle[0] = 0;
Vmiddle[1] = 1;
Vmiddle[2] = 0;
Vmiddle[3] = 1;
Vmiddle[4] = 0;


//0

Vblock20[0] = 1; 
Vblock20[1] = 1; 
Vblock20[2] = 1; 
Vblock20[3] = 0; 
Vblock20[4] = 0; 
Vblock20[5] = 1; 
Vblock20[6] = 0; 
//1
Vblock20[7] = 1; 
Vblock20[8] = 1; 
Vblock20[9] = 0; 
Vblock20[10] = 0; 
Vblock20[11] = 1; 
Vblock20[12] = 1; 
Vblock20[13] = 0; 
//2
Vblock20[14] = 1; 
Vblock20[15] = 1; 
Vblock20[16] = 0; 
Vblock20[17] = 1; 
Vblock20[18] = 1; 
Vblock20[19] = 0; 
Vblock20[20] = 0; 
//3
Vblock20[21] = 1; 
Vblock20[22] = 0; 
Vblock20[23] = 0; 
Vblock20[24] = 0; 
Vblock20[25] = 0; 
Vblock20[26] = 1; 
Vblock20[27] = 0; 
//4
Vblock20[28] = 1; 
Vblock20[29] = 0; 
Vblock20[30] = 1; 
Vblock20[31] = 1; 
Vblock20[32] = 1; 
Vblock20[33] = 0; 
Vblock20[34] = 0; 
//5
Vblock20[35] = 1; 
Vblock20[36] = 0; 
Vblock20[37] = 0; 
Vblock20[38] = 1; 
Vblock20[39] = 1; 
Vblock20[40] = 1; 
Vblock20[41] = 0; 
//6
Vblock20[42] = 1; 
Vblock20[43] = 0; 
Vblock20[44] = 1; 
Vblock20[45] = 0; 
Vblock20[46] = 0; 
Vblock20[47] = 0; 
Vblock20[48] = 0; 
//7
Vblock20[49] = 1; 
Vblock20[50] = 0; 
Vblock20[51] = 0; 
Vblock20[52] = 0; 
Vblock20[53] = 1; 
Vblock20[54] = 0; 
Vblock20[55] = 0; 
//8
Vblock20[56] = 1; 
Vblock20[57] = 0; 
Vblock20[58] = 0; 
Vblock20[59] = 1; 
Vblock20[60] = 0; 
Vblock20[61] = 0; 
Vblock20[62] = 0; 
//9
Vblock20[63] = 1; 
Vblock20[64] = 1; 
Vblock20[65] = 1; 
Vblock20[66] = 0; 
Vblock20[67] = 1; 
Vblock20[68] = 0; 
Vblock20[69] = 0; 

posx = 200;
posy = 300;


}

Sprite codbar::background ()
{
	Iimage1.create(370, 260, Color::White);
	Ttexture1.loadFromImage(Iimage1);
    Ssprite1.setTexture(Ttexture1);
    Ssprite1.setPosition(posx, posy);
    return Ssprite1;
}

Sprite codbar::drawguardzone (int val1)
{


for (m=0;m<3;m++)

{
  for (n=((val1*sizex) +20+((m-1)*sizex));n<((val1*sizex) + 20+(m*sizex));n++)
    {
      for (i=0;i<sizey1;i++)
       {
		 if (Vguardzone[m]==1)
         Iimage1.setPixel(n, i, Color::Black);
		 if (Vguardzone[m]==0)
		 Iimage1.setPixel(n, i, Color::White);
       }	  
     }   
 }
Ttexture1.loadFromImage(Iimage1);
Ssprite1.setTexture(Ttexture1);
return Ssprite1;
}

Sprite codbar::drawmidzone ()
{
	for (m=0;m<5;m++)

{
  for (n=(20 + (31*sizex) +((m-1)*sizex));n<(20 +(31*sizex)+(m*sizex));n++)
    {
      for (i=0;i<sizey1;i++)
       {
		 if (Vmiddle[m]==1)
         Iimage1.setPixel(n, i, Color::Black);
		 if (Vmiddle[m]==0)
		 Iimage1.setPixel(n, i, Color::White);
       }	  
     }   
 }
Ttexture1.loadFromImage(Iimage1);
Ssprite1.setTexture(Ttexture1);
return Ssprite1;
}

Sprite codbar::drawnumberleft (int val2, int val3)
{
	for (m=0;m<7;m++)

{
  for (n=((3*sizex) + (7*val3*sizex) +20+((m-1)*sizex));n<((3*sizex) + (7*val3*sizex) + 20+(m*sizex));n++)
    {
      for (i=0;i<sizey2;i++)
       {
		 if (Vblock10[m+(val2*7)]==1)
         Iimage1.setPixel(n, i, Color::Black);
		 if (Vblock10[m+(val2*7)]==0)
		 Iimage1.setPixel(n, i, Color::White);
       }	  
     }   
 }
Ttexture1.loadFromImage(Iimage1);
Ssprite1.setTexture(Ttexture1);
return Ssprite1;
}

Sprite codbar::drawnumberright (int val4, int val5)
{
	for (m=0;m<7;m++)

{
  for (n=((36*sizex) + (7*val5*sizex) +20+((m-1)*sizex));n<((36*sizex) + (7*val5*sizex) + 20+(m*sizex));n++)
    {
      for (i=0;i<sizey2;i++)
       {
		 if (Vblock20[m+(val4*7)]==1)
         Iimage1.setPixel(n, i, Color::Black);
		 if (Vblock20[m+(val4*7)]==0)
		 Iimage1.setPixel(n, i, Color::White);
       }	  
     }   
 }
Ttexture1.loadFromImage(Iimage1);
Ssprite1.setTexture(Ttexture1);
return Ssprite1;
}

Sprite codbar::drawtextleft(int val6, int val7)
{
	Iimage2.loadFromFile("/home/pi/Documents/picture/nombres10a9.png");
	Ttexture2.loadFromImage(Iimage2);
    Ssprite2.setTexture(Ttexture2);
    Ssprite2.setPosition((232+(val7*35)), 470);
    Ssprite2.setTextureRect(IntRect((val6*35), 0, 35, 50));
    Iimage1.copy(Iimage2, (18+(3*sizex)+ (val7*35)), sizey2+11, IntRect((val6*35),0, 35, 50) );
    Ttexture1.loadFromImage(Iimage1);
    Ssprite1.setTexture(Ttexture1);
    return Ssprite2;
}

Sprite codbar::drawtextright(int val6, int val7)
{
	Iimage2.loadFromFile("/home/pi/Documents/picture/nombres10a9.png");
	Ttexture2.loadFromImage(Iimage2);
    Ssprite2.setTexture(Ttexture2);
    Ssprite2.setPosition((230+(val7*35)+(33*sizex)), 470);
    Ssprite2.setTextureRect(IntRect((val6*35), 0, 35, 50));
    Iimage1.copy(Iimage2, (19+(35*sizex)+ (val7*35)), sizey2+11, IntRect((val6*35),0, 35, 50) );
    Ttexture1.loadFromImage(Iimage1);
    Ssprite1.setTexture(Ttexture1);
    return Ssprite2;
}

void codbar::savepic(string str1)
{
	recpath.erase();
	recpath = "/home/pi/Documents/codbar/";
	recpath +=str1;
	cout << recpath;
	
	Iimage1.saveToFile(recpath);
}



int main(int argc, char **argv)
{
//variables
int i, n, m;
int x, y;
int keycode;
int mode = 0;

Vector2i positionmouse (0,0);

int32_t timeint1;        
int32_t timeint2;

int Width = 1900;
int Heigth = 920;

int posx = 20;
int posy = 20;
int posx2 = 200;
int posy2 = 400;

int mem1 = 0, mem2 = 0;

float sizex = 5.0;
int sizex3 = 5;
float sizey1 = 140.0;
float sizey2 = 100.0;
int sizey3 = 100;
Color col2 (54, 122, 78, 255);

RenderWindow window(VideoMode(Width, Heigth), "save image");
Font font1;
if (!font1.loadFromFile("/home/pi/Documents/fonts/DroidSans.ttf"))
{
	window.close();
	return 0x99;
}

Clock clock1;
clock1.restart();
Time time1 = milliseconds(10);
Clock clock2;
clock2.restart();
Time time2 = milliseconds(10);

string strpath;
string strenter; 
Text Tenter;
Tenter.setFont(font1);
Tenter.setCharacterSize(70);
Tenter.setPosition(220,150);
Tenter.setColor(Color::White);
Tenter.setString ("");

string strenter2; 
Text Tenter2;
Tenter2.setFont(font1);
Tenter2.setCharacterSize(70);
Tenter2.setPosition(220,70           );
Tenter2.setColor(Color::White);
Tenter2.setString ("");

string strinfo;
Text Tinfo;
Tinfo.setFont(font1);
Tinfo.setCharacterSize(50);
Tinfo.setPosition(100,680);
Tinfo.setColor(Color::Blue);
Tinfo.setString ("rien");

string strmde;
Text Tmde;
Tmde.setFont(font1);
Tmde.setCharacterSize(45);
Tmde.setPosition(740,50);
Tmde.setColor(Color::Blue);
Tmde.setString (L"Entrez le nom lié au code-barre : a - z\n\nEntrez les 7 premiers chiffres : 0 - 9 \n\nPour valider le choix des 7 premiers charactères \net calculer le code de controle : tab \n\nPour afficher le code-barre : right shift\n\nPour enregistrer l'image : left arrow");

string strcodbar;
Text Tcodbar;
Tcodbar.setFont(font1);
Tcodbar.setCharacterSize(60);
Tcodbar.setPosition(235,460);
Tcodbar.setColor(Color::Blue);
Tcodbar.setString ("0000  0000");

vector<string> valb1(8);
valb1[0] = "0";
valb1[1] = "1";
valb1[2] = "2";
valb1[3] = "3";
valb1[4] = "4";
valb1[5] = "5";
valb1[6] = "6";
valb1[7] = "7";

vector<int> nbrb1 (8);
nbrb1[0] = 0;
nbrb1[1] = 0;
nbrb1[2] = 0;
nbrb1[3] = 0;
nbrb1[4] = 0;
nbrb1[5] = 0;
nbrb1[6] = 0;
nbrb1[7] = 0;

int nbrb2[8];

stringstream ss2;

Color bg (190, 170, 115);

RectangleShape rectdel1;
rectdel1.setPosition(90, 90);
rectdel1.setFillColor(bg);
rectdel1.setSize(Vector2f(700, 150));
    
window.clear(bg);

codbar cb1;

	while(window.isOpen())
	{
		Event event;
		while (window.pollEvent(event));
		{
			switch (event.type)
				{
					case Event::TextEntered:
					{
					  if (event.key.code >=48 and event.key.code <=57 and strenter.size() <7)
					    {
					      strenter += event.key.code;
					      Tenter.setString(strenter);
					      ss2 << strenter.size() << "/" << event.key.code;
					      strinfo = ss2.str();
					      ss2.str("");
					      nbrb1[strenter.size()-1] = event.key.code - 48;
					      rectdel1.setPosition(80, 640);
						  rectdel1.setSize(Vector2f(700, 150));
						  window.draw(rectdel1);
					      Tinfo.setString(strinfo);
					    }
					  if (event.key.code >=60 and event.key.code <=200 and strenter2.size() <10)
					    {
					      strenter2 += event.key.code;
					      Tenter2.setString(strenter2);
					      ss2 << strenter2.size() << "/" << event.key.code;
					      strinfo = ss2.str();
					      ss2.str("");
					      nbrb1[strenter2.size()-1] = event.key.code;
					      rectdel1.setPosition(80, 640);
						  rectdel1.setSize(Vector2f(700, 150));
						  window.draw(rectdel1);
					      Tinfo.setString(strinfo);
					    }
					  if (event.key.code==8)
					    {
							strenter.erase();
							Tenter.setString(strenter);
							ss2.str("");
							rectdel1.setPosition(90, 90);
							rectdel1.setSize(Vector2f(700, 150));
							window.draw(rectdel1);
						}
					 
					 if (event.key.code==9)
					    {
							
							for (i=0;i<7;i++)
							{
							cout << "nbrb1[" << i << "] :"<< nbrb1[i] << "\n";  
						    }
						    nbrb1[7] = (10 - (nbrb1[6] * 3 + nbrb1[5] + nbrb1[4] * 3 + nbrb1[3] + nbrb1[2] * 3 + nbrb1[1] + nbrb1[0] * 3)%10);
						    if (nbrb1[7] == 10)
						    nbrb1[7]=0;
						    cout << "code control :" << nbrb1[7] << "\n";
						    ss2.str("");
						    ss2 << nbrb1[7];
						    strenter += ss2.str();
						    Tenter.setString(strenter);
						}	
					  
					  sleep(milliseconds(150));	
					  break;	
					}
										
					case Event::KeyPressed:
					{
						keycode=event.key.code;
						if (Keyboard::isKeyPressed(Keyboard::Left))
						{
						 strpath.erase();	
						 ss2.str("");
						 ss2 << nbrb1[0] << nbrb1[1] << nbrb1[2] << nbrb1[3] << nbrb1[4] << nbrb1[5] << nbrb1[6] << nbrb1[7] << strenter2 << ".png"; 
						 strpath = ss2.str();
						 rectdel1.setPosition(80, 640);
						 rectdel1.setSize(Vector2f(900, 150));
						 window.draw(rectdel1);
						 cb1.savepic(strpath);
						 Tinfo.setString(L"image sauvgardée  filename : " + strpath); 
						 sleep(milliseconds(150));	
						 break;	
						}//fin left
						if (Keyboard::isKeyPressed(Keyboard::Right))
						{
						 
						 break;	
						}//fin right
						
						if (Keyboard::isKeyPressed(Keyboard::Up))
						{

						 break;	
						}//fin up
						if (Keyboard::isKeyPressed(Keyboard::Down))
						{
				 		 
						 break;	
						}//fin down
						
						if (event.key.code==(Keyboard::RShift))
						{
						 window.draw(cb1.background());
		window.draw(cb1.drawguardzone(0));
		
		window.draw(cb1.drawnumberleft(nbrb1[0],0));
		window.draw(cb1.drawnumberleft(nbrb1[1],1));
		window.draw(cb1.drawnumberleft(nbrb1[2],2));
		window.draw(cb1.drawnumberleft(nbrb1[3],3));
		
		window.draw(cb1.drawmidzone());
		
		window.draw(cb1.drawnumberright(nbrb1[4],0));
		window.draw(cb1.drawnumberright(nbrb1[5],1));
		window.draw(cb1.drawnumberright(nbrb1[6],2));
		window.draw(cb1.drawnumberright(nbrb1[7],3));
		window.draw(cb1.drawguardzone(64));
		window.draw(cb1.drawtextleft(nbrb1[0], 0));
		window.draw(cb1.drawtextleft(nbrb1[1], 1));
		window.draw(cb1.drawtextleft(nbrb1[2], 2));
		window.draw(cb1.drawtextleft(nbrb1[3], 3));
		window.draw(cb1.drawtextright(nbrb1[4], 0));
		window.draw(cb1.drawtextright(nbrb1[5], 1));
		window.draw(cb1.drawtextright(nbrb1[6], 2));
		window.draw(cb1.drawtextright(nbrb1[7], 3));
		//window.draw(cb1.drawtext(1, 3));
		/*
		ss2.str("");
		ss2 << nbrb1[0] << nbrb1[1] << nbrb1[2] << nbrb1[3] << "  " << nbrb1[4] << nbrb1[5] << nbrb1[6] << nbrb1[7];				 
		strcodbar = ss2.str();
		Tcodbar.setString(strcodbar);
		*/
						 break;	
						}//fin d
						
					}//fin keypressed
					case Event::KeyReleased:
					{
						
						
					break;	
					}//fin keyreleased
					case Event::Closed:
					{
						window.close();
					}//fin closed
					case Event::MouseMoved:
					{
						positionmouse = Mouse::getPosition(window);
 						x = positionmouse.x;
						y = positionmouse.y;
						
					    break;	
					}//fin mousemoved 
					case Event::MouseButtonPressed:
					{
						
	   
						
						
					}//fin mousebuttonpressed
				}//fin switch event.type
		   } //fin boucle  while pollevent	
		/*
		window.clear(bg);
		
		window.draw(cb1.background());
		window.draw(cb1.drawguardzone(0));
		
		window.draw(cb1.drawnumberleft(0,0));
		window.draw(cb1.drawnumberleft(0,1));
		window.draw(cb1.drawnumberleft(0,2));
		window.draw(cb1.drawnumberleft(0,3));
		
		window.draw(cb1.drawmidzone());
		
		window.draw(cb1.drawnumberright(0,0));
		window.draw(cb1.drawnumberright(0,1));
		window.draw(cb1.drawnumberright(0,2));
		window.draw(cb1.drawnumberright(0,3));
		
		window.draw(cb1.drawguardzone(64));
		*/
		
		window.draw(Tenter);
		window.draw(Tenter2);
		window.draw(Tmde);
		//window.draw(Tcodbar);
		window.draw(Tinfo);
		
		window.display();
	}
	return 0;
}

