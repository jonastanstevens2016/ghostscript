#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Postscript {
private:
	ofstream f;
public:
	Postscript (char* filename) {
		f.open(filename);
	}

	void line (int x1, int y1, int x2, int y2) {
		f << 'newpath\n' << x1 << ' ' << y1 << " moveto " << x2 << ' ' << y2 << " lineto stroke\n";
	}

	void setColor(int r, int g, int b){
		f << r << ' ' << g << ' ' << b << ' ' << "setrgbcolor\n";
	}

	void drawRect(int x, int y, int w, int h){
		f << "newpath " << x << ' '<< y << " moveto " << x << ' ' << y + h << " lineto " << x + w << ' ' << y + h << " lineto " << x + w << ' ' << y << " lineto closepath stroke\n";
	}

	void fillRect(int x, int y, int w, int h){
		f << "newpath\n" << x << ' '<< y << " moveto " << x << ' ' << y + h << " lineto " << x + w << ' ' << y + h << " lineto " << x + w << ' ' << y << " lineto closepath fill\n";
	}
};

int main() {
  Postscript p("test.ps");
  p.line(0,0, 300,400);  // 0 0 moveto 300 400 lineto stroke
  int r = 255, g = 0, b = 0;
  p.setColor(r, g, b);
  p.drawRect(0, 0, 200, 200);   // x y moveto x+w y lineto x+w y+h lineto ... closepath stroke
//  p.fillRect(x, y, w, h);   // x y moveto x+w y lineto x+w y+h lineto ... closepath fill
//  p.setFillColor(int r, int g, int b); // 1.0 0.5 0 setrgbcolor
//
//  // optional, figure out how you want to manage color
//  p.setStrokeColor(int r, int g, int b);
//  p.drawTriangle(x1,y1, x2,y2, x3,y3);
//  p.fillTriangle(x1,y1, x2,y2, x3,y3);
//  p.drawCircle(x,y,r); // x y 0 360 r arc stroke
//  p.text(x,y, "testing testing 123"); // look it up  setfont  (ABC) show
//
//  p.grid(300, 50, 500, 400, 50, 700);
}
