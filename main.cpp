#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;
using namespace sf;
#define pantalla_x 600
#define pantalla_y 600
/////////////////////////////////////////////////
class nodo{
public:
	int x,y;
	Sprite img;
	Texture textura;
	////////////////////
	Font font;
	Text texto;
	////////////////////
	nodo(int pos_x,int pos_y,string valor){
		x=pos_x;y=pos_y;
		textura.loadFromFile("nodo_1.png");
		img.setTexture(textura);
		img.setPosition(100*x,100*y);
		if(!font.loadFromFile("arial.ttf")){
			cout<<"error"<<endl;
		}
		texto.setFont(font);
		texto.setColor(Color::White);
		texto.setString(valor);
		texto.setPosition(Vector2f((x*100)+30,(y*100)+30));
		//texto.setPosition(Vector2f(30,230));
	}
	void dibujar(RenderWindow &pantalla){
		pantalla.draw(img);
		pantalla.draw(texto);
	}
};
/////////////////////////////////////////////////
int main(int argc, char *argv[]){
	RenderWindow w(VideoMode(pantalla_x,pantalla_y),"Ejemplo de SFML");
	Texture t;
	Sprite s;
	
	//menu m(pantalla_x,pantalla_y);
	nodo c(2,2,"125");
	while(w.isOpen()) {
		Event e;
		while(w.pollEvent(e)) {
			if(e.type == Event::Closed)
				w.close();	
		}
		
		w.clear(Color(0,0,0));
		//m.dibujar(w);
		c.dibujar(w);
		w.display();
	}
	return 0;
}

