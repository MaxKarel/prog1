#include <iostream>
#include "../../SVGdraw.h"

using namespace std;
struct farba { int r, g, b; };

int main() {
  int N,R,D; //N=level, R=size, D=
  cin >> N >> D >> R;

  return 0;
}


void stvorec(SVGdraw &drawing, double x, double y, double d,
  farba &f, bool paralelny) {
  /** do obrazku drawing vykresli stvorec so stredom na suradniciach x,y
  * s dlzkou strany d a farbou f, ktoreho strany budu paralelne s osami
  * ak paralelny=true alebo bude o 45 stupnov otoceny ak
  * paralelny=false */

    drawing.setFillColor(f.r, f.g, f.b);
    if (paralelny) {
        drawing.drawRectangle(x - d / 2, y - d / 2, d, d);
    } else {
        double offset = d / sqrt(2);
        drawing.startPolygon(x - offset, y);
        drawing.addPolygonPoint(x, y - offset);
        drawing.addPolygonPoint(x + offset, y);
        drawing.addPolygonPoint(x, y + offset);
        drawing.drawPolygon();
    }
}
