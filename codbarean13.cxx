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
	int d1;
	bool b1;
	bool Vguardzone [3];
	bool blockA [70];
	bool blockB [70];
	bool blockC [70];
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
	Sprite drawnumberleft(int, int, int);
	Sprite drawnumberright(int, int);
	Sprite firstnumber (int, int);
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
d1 = 50;

recpath = "/home/pi/Documents/codbar/";


Vguardzone[0]=1;
Vguardzone[1]=0;
Vguardzone[2]=1;

//0
blockA[0] = 0; 
blockA[1] = 0; 
blockA[2] = 0; 
blockA[3] = 1; 
blockA[4] = 1; 
blockA[5] = 0; 
blockA[6] = 1; 
//1
blockA[7] = 0; 
blockA[8] = 0; 
blockA[9] = 1; 
blockA[10] = 1; 
blockA[11] = 0; 
blockA[12] = 0; 
blockA[13] = 1; 
//2
blockA[14] = 0; 
blockA[15] = 0; 
blockA[16] = 1; 
blockA[17] = 0; 
blockA[18] = 0; 
blockA[19] = 1; 
blockA[20] = 1; 
//3
blockA[21] = 0; 
blockA[22] = 1; 
blockA[23] = 1; 
blockA[24] = 1; 
blockA[25] = 1; 
blockA[26] = 0; 
blockA[27] = 1; 
//4
blockA[28] = 0; 
blockA[29] = 1; 
blockA[30] = 0; 
blockA[31] = 0; 
blockA[32] = 0; 
blockA[33] = 1; 
blockA[34] = 1; 
//5
blockA[35] = 0; 
blockA[36] = 1; 
blockA[37] = 1; 
blockA[38] = 0; 
blockA[39] = 0; 
blockA[40] = 0; 
blockA[41] = 1; 
//6
blockA[42] = 0; 
blockA[43] = 1; 
blockA[44] = 0; 
blockA[45] = 1; 
blockA[46] = 1; 
blockA[47] = 1; 
blockA[48] = 1; 
//7
blockA[49] = 0; 
blockA[50] = 1; 
blockA[51] = 1; 
blockA[52] = 1; 
blockA[53] = 0; 
blockA[54] = 1; 
blockA[55] = 1; 
//8
blockA[56] = 0; 
blockA[57] = 1; 
blockA[58] = 1; 
blockA[59] = 0; 
blockA[60] = 1; 
blockA[61] = 1; 
blockA[62] = 1; 
//9
blockA[63] = 0; 
blockA[64] = 0; 
blockA[65] = 0; 
blockA[66] = 1; 
blockA[67] = 0; 
blockA[68] = 1; 
blockA[69] = 1; 

//0
blockB[0] = 0; 
blockB[1] = 1; 
blockB[2] = 0; 
blockB[3] = 0; 
blockB[4] = 1; 
blockB[5] = 1; 
blockB[6] = 1; 
//1
blockB[7] = 0; 
blockB[8] = 1; 
blockB[9] = 1; 
blockB[10] =0; 
blockB[11] = 0; 
blockB[12] = 1; 
blockB[13] = 1; 
//2
blockB[14] = 0; 
blockB[15] = 0; 
blockB[16] = 1; 
blockB[17] = 1; 
blockB[18] = 0; 
blockB[19] = 1; 
blockB[20] = 1; 
//3
blockB[21] = 0; 
blockB[22] = 1; 
blockB[23] = 0; 
blockB[24] = 0; 
blockB[25] = 0; 
blockB[26] = 0; 
blockB[27] = 1; 
//4
blockB[28] = 0; 
blockB[29] = 0; 
blockB[30] = 1; 
blockB[31] = 1; 
blockB[32] = 1; 
blockB[33] = 0; 
blockB[34] = 1; 
//5
blockB[35] = 0; 
blockB[36] = 1; 
blockB[37] = 1; 
blockB[38] = 1; 
blockB[39] = 0; 
blockB[40] = 0; 
blockB[41] = 1; 
//6
blockB[42] = 0; 
blockB[43] = 0; 
blockB[44] = 0; 
blockB[45] = 0; 
blockB[46] = 1; 
blockB[47] = 0; 
blockB[48] = 1; 
//7
blockB[49] = 0; 
blockB[50] = 0; 
blockB[51] = 1; 
blockB[52] = 0; 
blockB[53] = 0; 
blockB[54] = 0; 
blockB[55] = 1; 
//8
blockB[56] = 0; 
blockB[57] = 0; 
blockB[58] = 0; 
blockB[59] = 1; 
blockB[60] = 0; 
blockB[61] = 0; 
blockB[62] = 1; 
//9
blockB[63] = 0; 
blockB[64] = 0; 
blockB[65] = 1; 
blockB[66] = 0; 
blockB[67] = 1; 
blockB[68] = 1; 
blockB[69] = 1; 

Vmiddle[0] = 0;
Vmiddle[1] = 1;
Vmiddle[2] = 0;
Vmiddle[3] = 1;
Vmiddle[4] = 0;


//0

blockC[0] = 1; 
blockC[1] = 1; 
blockC[2] = 1; 
blockC[3] = 0; 
blockC[4] = 0; 
blockC[5] = 1; 
blockC[6] = 0; 
//1
blockC[7] = 1; 
blockC[8] = 1; 
blockC[9] = 0; 
blockC[10] = 0; 
blockC[11] = 1; 
blockC[12] = 1; 
blockC[13] = 0; 
//2
blockC[14] = 1; 
blockC[15] = 1; 
blockC[16] = 0; 
blockC[17] = 1; 
blockC[18] = 1; 
blockC[19] = 0; 
blockC[20] = 0; 
//3
blockC[21] = 1; 
blockC[22] = 0; 
blockC[23] = 0; 
blockC[24] = 0; 
blockC[25] = 0; 
blockC[26] = 1; 
blockC[27] = 0; 
//4
blockC[28] = 1; 
blockC[29] = 0; 
blockC[30] = 1; 
blockC[31] = 1; 
blockC[32] = 1; 
blockC[33] = 0; 
blockC[34] = 0; 
//5
blockC[35] = 1; 
blockC[36] = 0; 
blockC[37] = 0; 
blockC[38] = 1; 
blockC[39] = 1; 
blockC[40] = 1; 
blockC[41] = 0; 
//6
blockC[42] = 1; 
blockC[43] = 0; 
blockC[44] = 1; 
blockC[45] = 0; 
blockC[46] = 0; 
blockC[47] = 0; 
blockC[48] = 0; 
//7
blockC[49] = 1; 
blockC[50] = 0; 
blockC[51] = 0; 
blockC[52] = 0; 
blockC[53] = 1; 
blockC[54] = 0; 
blockC[55] = 0; 
//8
blockC[56] = 1; 
blockC[57] = 0; 
blockC[58] = 0; 
blockC[59] = 1; 
blockC[60] = 0; 
blockC[61] = 0; 
blockC[62] = 0; 
//9
blockC[63] = 1; 
blockC[64] = 1; 
blockC[65] = 1; 
blockC[66] = 0; 
blockC[67] = 1; 
blockC[68] = 0; 
blockC[69] = 0; 

posx = 150;
posy = 300;


}

Sprite codbar::background ()
{
	Iimage1.create(550, 260, Color::White);
	Ttexture1.loadFromImage(Iimage1);
    Ssprite1.setTexture(Ttexture1);
    Ssprite1.setPosition(posx, posy);
    return Ssprite1;
}

Sprite codbar::drawguardzone (int val1)
{


for (m=0;m<3;m++)

{
  for (n=((val1*sizex) +d1+((m-1)*sizex));n<((val1*sizex) + d1 +(m*sizex));n++)
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
  for (n=(d1 + (45*sizex) +((m-1)*sizex));n<(d1 +(45*sizex)+(m*sizex));n++)
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

Sprite codbar::drawnumberleft (int val2, int val3, int val4)
{
	for (m=0;m<7;m++)
    
{
  for (n=((3*sizex) + (7*val3*sizex) +d1+((m-1)*sizex));n<((3*sizex) + (7*val3*sizex) + d1 + (m*sizex));n++)
    {
      for (i=0;i<sizey2;i++)
       {
		 if (val4==0)
		    {
		     if (blockA[m+(val2*7)]==1)
             Iimage1.setPixel(n, i, Color::Black);
		     if (blockA[m+(val2*7)]==0)
		     Iimage1.setPixel(n, i, Color::White);
	        }
	     if (val4==1)
		    {
		     if (blockB[m+(val2*7)]==1)
             Iimage1.setPixel(n, i, Color::Black);
		     if (blockB[m+(val2*7)]==0)
		     Iimage1.setPixel(n, i, Color::White);
	     }
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
  for (n=((50*sizex) + (7*val5*sizex) +d1+((m-1)*sizex));n<((50*sizex) + (7*val5*sizex) + d1+(m*sizex));n++)
    {
      for (i=0;i<sizey2;i++)
       {
		 if (blockC[m+(val4*7)]==1)
         Iimage1.setPixel(n, i, Color::Black);
		 if (blockC[m+(val4*7)]==0)
		 Iimage1.setPixel(n, i, Color::White);
       }	  
     }   
 }
Ttexture1.loadFromImage(Iimage1);
Ssprite1.setTexture(Ttexture1);
return Ssprite1;
}

Sprite codbar::firstnumber(int val6, int val7)
{

	Iimage2.loadFromFile("nombres10a9.png");

	Ttexture2.loadFromImage(Iimage2);
    Ssprite2.setTexture(Ttexture2);
    Ssprite2.setPosition((157+(val7*35)), 470);
    Ssprite2.setTextureRect(IntRect((val6*35), 0, 35, 50));
    Iimage1.copy(Iimage2, (8 + (val7*35)), sizey2+11, IntRect((val6*35),0, 35, 50) );
    Ttexture1.loadFromImage(Iimage1);
    Ssprite1.setTexture(Ttexture1);
    return Ssprite2;
}


Sprite codbar::drawtextleft(int val6, int val7)
{

	Iimage2.loadFromFile("nombres10a9.png");

	Ttexture2.loadFromImage(Iimage2);
    Ssprite2.setTexture(Ttexture2);
    Ssprite2.setPosition((212+(val7*35)), 470);
    Ssprite2.setTextureRect(IntRect((val6*35), 0, 35, 50));
    Iimage1.copy(Iimage2, (48+(3*sizex)+ (val7*35)), sizey2+11, IntRect((val6*35),0, 35, 50) );
    Ttexture1.loadFromImage(Iimage1);
    Ssprite1.setTexture(Ttexture1);
    return Ssprite2;
}

Sprite codbar::drawtextright(int val6, int val7)
{

	Iimage2.loadFromFile("nombres10a9.png");

	Ttexture2.loadFromImage(Iimage2);
    Ssprite2.setTexture(Ttexture2);
    Ssprite2.setPosition((227+(val7*35)+(43*sizex)), 470);
    Ssprite2.setTextureRect(IntRect((val6*35), 0, 35, 50));
    Iimage1.copy(Iimage2, (48+(49*sizex)+ (val7*35)), sizey2+11, IntRect((val6*35),0, 35, 50) );
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

vector<bool> setchoice (6); //0: set A    1: set B 
setchoice[0] = 0;
setchoice[1] = 0;
setchoice[2] = 0;
setchoice[3] = 0;
setchoice[4] = 0;
setchoice[5] = 0;

Color col2 (54, 122, 78, 255);

RenderWindow window(VideoMode(Width, Heigth), "code EAN13");  //pour utilisation sur une TV  1080p

Font font1;
if (!font1.loadFromFile("DroidSans.ttf"))

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
Tenter.setPosition(150,195);
Tenter.setColor(Color::White);
Tenter.setString ("");

string strenter2; 
Text Tenter2;
Tenter2.setFont(font1);
Tenter2.setCharacterSize(70);
Tenter2.setPosition(150,70);
Tenter2.setColor(Color::White);
Tenter2.setString ("");

string strinfo;
Text Tinfo;
Tinfo.setFont(font1);
Tinfo.setCharacterSize(50);
Tinfo.setPosition(100,830);
Tinfo.setColor(Color::Blue);
Tinfo.setString ("rien");

string strmde;
Text Tmde;
Tmde.setFont(font1);
Tmde.setCharacterSize(45);
Tmde.setPosition(780,50);
Tmde.setColor(Color::Blue);
Tmde.setString (L"Entrez un nom pour identifier\nplus facilement le code-barre : a - z\n\nEntrez les 12 premiers chiffres : 0 - 9 \n\nPour valider le choix des 12 premiers charactères \net calculer le code de controle : tab \n\nPour afficher le code-barre : right shift\n\nPour enregistrer l'image : left arrow");

string strmde2;
Text Tmde2;
Tmde2.setFont(font1);
Tmde2.setCharacterSize(45);
Tmde2.setPosition(780,650);
Tmde2.setColor(Color::Blue);

strmde2 = "choix du format de l'image : [left/right] now png";

Tmde2.setString (strmde2);

vector<int> code (13);
code[0] = 7;
code[1] = 6;
code[2] = 0;
code[3] = 0;
code[4] = 0;
code[5] = 0;
code[6] = 0;
code[7] = 0;
code[8] = 0;
code[9] = 0;
code[10] = 0;
code[11] = 0;
code[12] = 0;


stringstream ss2;

Color bg (190, 170, 115);
Color color1 (255, 165, 0, 255);
Color trsp (0, 0, 0, 0);

RectangleShape rectdel1;
rectdel1.setPosition(90, 90);
rectdel1.setFillColor(bg);
rectdel1.setSize(Vector2f(700, 150));

int format = 0;

vector<int> xcoordbm(3);
xcoordbm[0]= 800;
xcoordbm[1]= 920;
xcoordbm[2]= 1040;

vector<int> ycoordbm(3);
ycoordbm[0]= 750;
ycoordbm[1]= 750;
ycoordbm[2]= 750;

RectangleShape *pTboutonmenu;
pTboutonmenu = new RectangleShape[3];
for (i=0;i<3;i++)
{
pTboutonmenu[i];
pTboutonmenu[i].setSize(Vector2f(100,50));
pTboutonmenu[i].setPosition(xcoordbm[i], ycoordbm[i]);
pTboutonmenu[i].setFillColor(color1);
}

vector<string> formatfile(3);
formatfile[0]="png";
formatfile[1]="bmp";
formatfile[2]="jpg";
Text *pTtextboutonmenu;
pTtextboutonmenu = new Text[3];
for (i=0;i<3;i++)
{
	pTtextboutonmenu[i];
	pTtextboutonmenu[i].setFont(font1);
	pTtextboutonmenu[i].setCharacterSize(35);
	pTtextboutonmenu[i].setPosition(xcoordbm[i]+20, ycoordbm[i]+5);
	pTtextboutonmenu[i].setColor(Color::Black);
	pTtextboutonmenu[i].setString (formatfile[i]);
	
	}

RectangleShape Rselectformat;
Rselectformat.setPosition(xcoordbm[0], ycoordbm[0]);
Rselectformat.setFillColor(trsp);
Rselectformat.setSize(Vector2f(100, 50));
Rselectformat.setOutlineThickness(4);
Rselectformat.setOutlineColor(Color::White);

RectangleShape Rselectnom;
Rselectnom.setPosition(140, 70);
Rselectnom.setFillColor(trsp);
Rselectnom.setSize(Vector2f(600, 80));
Rselectnom.setOutlineThickness(4);
Rselectnom.setOutlineColor(Color::White);

RectangleShape Rselectcode;
Rselectcode.setPosition(140, 200);
Rselectcode.setFillColor(trsp);
Rselectcode.setSize(Vector2f(600, 80));
Rselectcode.setOutlineThickness(4);
Rselectcode.setOutlineColor(Color::White);

    
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
					  if (event.key.code >=48 and event.key.code <=57 and strenter.size() <12)
					    {
					      strenter += event.key.code;
					      Tenter.setString(strenter);
					      ss2 << strenter.size() << "/" << event.key.code;
					      strinfo = ss2.str();
					      ss2.str("");
					      code[strenter.size()-1] = event.key.code - 48;
					      rectdel1.setPosition(50, 820);
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
					      code[strenter2.size()-1] = event.key.code;
					      rectdel1.setPosition(50, 820);
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
							
							for (i=0;i<13;i++)
							{
							cout << "code[" << i << "] :"<< code[i] << "\n";  
						    }
						    code[12] = (10 - (code[0] + code[1] * 3 + code[2] + code[3] * 3 + code[4] + code[5] * 3 + code[6] + code[7] * 3 + code[8] + code[9] * 3 + code[10] + code[11] * 3)%10);
						    if (code[12] == 10)
						    code[12]=0;
						    cout << "code control :" << code[12] << "\n";
						    ss2.str("");
						    ss2 << code[12];
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
						 format --;
						 if (format < 0)
						 format=0;
						 rectdel1.setPosition(600, 640);
						 rectdel1.setSize(Vector2f(1200, 350));
						 window.draw(rectdel1);
						 strmde2 = L"choix du format de l'image : [left/right] now  " + formatfile[format];

						 Tmde2.setString (strmde2);
						 Rselectformat.setPosition(xcoordbm[format], ycoordbm[format]);
						 Rselectformat.setPosition(xcoordbm[format], ycoordbm[format]);
						 sleep(milliseconds(150));
						 break;	
						}//fin left
						if (Keyboard::isKeyPressed(Keyboard::Right))
						{
						 format ++;
						 if (format>2)
						 format = 2;
						 rectdel1.setPosition(600, 640);
						 rectdel1.setSize(Vector2f(1200, 350));
						 window.draw(rectdel1);
						 strmde2 = L"choix du format de l'image : [left/right] now " + formatfile[format];
						 Tmde2.setString (strmde2);
						 Rselectformat.setPosition(xcoordbm[format], ycoordbm[format]);
						 sleep(milliseconds(150));
						 break;	
						}//fin right
						
						if (Keyboard::isKeyPressed(Keyboard::Up))
						{
                         strpath.erase();	
						 ss2.str("");
						 ss2 << code[0] << code[1] << code[2] << code[3] << code[4] << code[5] << code[6] << code[7] << code[8] << code[9] << code[10] << code[11] << code[12] << strenter2 <<  "." << formatfile[format]; 
						 strpath = ss2.str();
						 rectdel1.setPosition(80, 830);
						 rectdel1.setSize(Vector2f(1500, 150));
						 window.draw(rectdel1);
						 cb1.savepic(strpath);
						 Tinfo.setString(L"image sauvgardée  filename : " + strpath); 
						 sleep(milliseconds(150));	
						 break;	
						}//fin up
						if (Keyboard::isKeyPressed(Keyboard::Down))
						{
				 		 
						 break;	
						}//fin down
						
						if (event.key.code==(Keyboard::RShift))
						{
		switch (code[0])
		  {
			 
			 case 0:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 0;
				  setchoice[2] = 0;
				  setchoice[3] = 0;
				  setchoice[4] = 0;
				  setchoice[5] = 0;
				  break;
			   }//fin case 1
			 case 1:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 0;
				  setchoice[2] = 1;
				  setchoice[3] = 0;
				  setchoice[4] = 1;
				  setchoice[5] = 1;
				  break;
			   }//fin case 1
			 case 2:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 0;
				  setchoice[2] = 1;
				  setchoice[3] = 1;
				  setchoice[4] = 0;
				  setchoice[5] = 1;
				  break;
			   }//fin case 2
			 case 3:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 0;
				  setchoice[2] = 1;
				  setchoice[3] = 1;
				  setchoice[4] = 1;
				  setchoice[5] = 0;
				  break;
			   }//fin case 3
			 case 4:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 1;
				  setchoice[2] = 0;
				  setchoice[3] = 0;
				  setchoice[4] = 1;
				  setchoice[5] = 1;
				  break;
			   }//fin case 4
			 case 5:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 1;
				  setchoice[2] = 1;
				  setchoice[3] = 0;
				  setchoice[4] = 0;
				  setchoice[5] = 1;
				  break;
			   }//fin case 5
			 case 6:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 1;
				  setchoice[2] = 1;
				  setchoice[3] = 1;
				  setchoice[4] = 0;
				  setchoice[5] = 0;
				  break;
			   }//fin case 6
			 case 7:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 1;
				  setchoice[2] = 0;
				  setchoice[3] = 1;
				  setchoice[4] = 0;
				  setchoice[5] = 1;
				  break;
			   }//fin case 7
			 case 8:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 1;
				  setchoice[2] = 0;
				  setchoice[3] = 1;
				  setchoice[4] = 1;
				  setchoice[5] = 0;
				  break;
			   }//fin case 8
			 case 9:
			   {  
				  setchoice[0] = 0;
				  setchoice[1] = 1;
				  setchoice[2] = 1;
				  setchoice[3] = 0;
				  setchoice[4] = 1;
				  setchoice[5] = 0;
				  break;
			   }//fin case 9 
			  
		  }//fin switch code 0
		  
		window.draw(cb1.background());
		
		window.draw(cb1.drawguardzone(0));
		
		window.draw(cb1.drawnumberleft(code[1],0, setchoice[0]));
		window.draw(cb1.drawnumberleft(code[2],1, setchoice[1]));
		window.draw(cb1.drawnumberleft(code[3],2, setchoice[2]));
		window.draw(cb1.drawnumberleft(code[4],3, setchoice[3]));
		window.draw(cb1.drawnumberleft(code[5],4, setchoice[4]));
		window.draw(cb1.drawnumberleft(code[6],5, setchoice[5]));
		
		window.draw(cb1.drawmidzone());
		
		window.draw(cb1.drawnumberright(code[7],0));
		window.draw(cb1.drawnumberright(code[8],1));
		window.draw(cb1.drawnumberright(code[9],2));
		window.draw(cb1.drawnumberright(code[10],3));
		window.draw(cb1.drawnumberright(code[11],4));
		window.draw(cb1.drawnumberright(code[12],5));
		
		window.draw(cb1.drawguardzone(92));
		
		window.draw(cb1.firstnumber(code[0], 0));		
		window.draw(cb1.drawtextleft(code[1], 0));
		window.draw(cb1.drawtextleft(code[2], 1));
		window.draw(cb1.drawtextleft(code[3], 2));
		window.draw(cb1.drawtextleft(code[4], 3));
		window.draw(cb1.drawtextleft(code[5], 4));
		window.draw(cb1.drawtextleft(code[6], 5));
		
		window.draw(cb1.drawtextright(code[7], 0));
		window.draw(cb1.drawtextright(code[8], 1));
		window.draw(cb1.drawtextright(code[9], 2));
		window.draw(cb1.drawtextright(code[10], 3));
		window.draw(cb1.drawtextright(code[11], 4));
		window.draw(cb1.drawtextright(code[12], 5));
		
		/*
		ss2.str("");
		ss2 << code[0] << code[1] << code[2] << code[3] << "  " << code[4] << code[5] << code[6] << code[7];				 
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
		for (i=0;i<3;i++)
		  {
		    window.draw(pTboutonmenu[i]);
		    window.draw(pTtextboutonmenu[i]);
	      }
		window.draw(Rselectformat);
		window.draw(Rselectnom);
		window.draw(Rselectcode);

		window.draw(Tenter);
		window.draw(Tenter2);
		window.draw(Tmde);
		window.draw(Tmde2);
		//window.draw(Tcodbar);
		window.draw(Tinfo);
		
		window.display();
	}
	return 0;
}

