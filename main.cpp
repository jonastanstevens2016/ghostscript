/**
 * Authors:
	Chushen Tan,
	Lijin Shen
 */
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Postscript {
private:
	ofstream f;
public:
	Postscript(char *filename) {
		f.open(filename);
	}


	void line(int x1, int y1, int x2, int y2) {
		f << 'newpath\n' << x1 << ' ' << y1 << " moveto " << x2 << ' ' << y2 << " lineto stroke\n";
	}

	void setColor(int r, int g, int b) {
		f << r << ' ' << g << ' ' << b << ' ' << "setrgbcolor\n";
	}

	void drawRect(int x, int y, int w, int h) {
		f << "newpath " << x << ' ' << y << " moveto " << x << ' ' << y + h << " lineto " << x + w << ' ' << y + h
		  << " lineto " << x + w << ' ' << y << " lineto closepath stroke\n";
	}

	void fillRect(int x, int y, int w, int h) {
		f << "newpath\n" << x << ' ' << y << " moveto " << x << ' ' << y + h << " lineto " << x + w << ' ' << y + h
		  << " lineto " << x + w << ' ' << y << " lineto closepath fill\n";
	}



	~Postscript(){
		f.flush();
		f.close();
	}

	void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
		f << "newpath\n" << x1 << ' ' << y1 << " moveto " << x2 << ' ' << y2 << " moveto " <<
			x3 << ' ' << y3 << " lineto closepath stroke\n";
	}

	void fillTriangle(int x1, int y1, int x2, int y2, int x3, int y3) {
		f << "newpath\n" << x1 << ' ' << y1 << " moveto " << x2 << ' ' << y2 << " lineto " <<
			x3 << ' ' << y3 << " lineto closepath fill\n";
	}

	void drawCircle (int x, int y, int r) {
		f << "newpath\n" << x << ' ' << y << " 5 0 360 " << r << " arc stroke\n";
	}

	void text (int x, int y, string words) {
		f << "/Times-Roman findfont 12 scalefont setfont newpath " << x << " " << y << " moveto (" << words <<") show\n";
	}

	void setFillColor (int r, int g, int b) {
		setColor(r, g, b);
	}

	void setStrokeColor (int r, int g, int b) {
		setColor(r, g, b);
	}
};

int main() {

	Postscript p("test.ps");
	p.line(0, 0, 300, 400);  // 0 0 moveto 300 400 lineto stroke
	int r = 255, g = 0, b = 0;
	p.setColor(r, g, b);
	p.drawRect(0, 0, 200, 200);   // x y moveto x+w y lineto x+w y+h lineto ... closepath stroke
	p.fillRect(0, 0, 200, 200);   // x y moveto x+w y lineto x+w y+h lineto ... closepath fill

 	p.setFillColor(10, 10, 10); // 1.0 0.5 0 setrgbcolor
//
//  // optional, figure out how you want to manage color
 	p.setStrokeColor(10, 10, 10);
	p.drawTriangle(10, 10, 50, 50, 10, 30);
	p.fillTriangle(10, 10, 50, 50, 10, 30);
	p.drawCircle(10, 10, 20); // x y 0 360 r arc stroke
	p.text(0, 0, "testing testing 123"); // look it up  setfont  (ABC) show
//
//  p.grid(300, 50, 500, 400, 50, 700);
}
