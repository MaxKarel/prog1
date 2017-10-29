#include <iostream>
#include "../../SVGdraw.h"
#include <cassert>
#include <cmath>

using namespace std;
struct farba { int r, g, b; };
const int NMAX = 6;
void stvorec(SVGdraw &drawing, double x, double y, double d,
            farba &f, bool paralelny);
double fraktal(SVGdraw &drawing, double x, double y, int N, double D, double R, farba* colours, double* area);

int main() {
  int N;
  double R,D; //N=level, R=size, D=
  farba colours[NMAX];
  double area[NMAX];

  cin >> N >> D >> R;
  assert((N>=1)&&(N<=6));
  assert((D>=10)&&(D<=100));
  assert((R>=0.1)&&(R<=0.5));
  for(int i = 0 ; i < N ; i++) {
    cin >> colours[i].r >> colours[i].g >> colours[i].b;
    area[N] = 0;
  }
  SVGdraw drawing(3*D, 3*D, "fraktal.svg");
  area[N-1] = fraktal(drawing, 3 /2 *D, 3 /2 *D, N, D, R, colours, area);
  for(int i = 0; i < N; i++) {
    cout << area[i] << endl;
  }
  drawing.finish();
  return 0;
}

double fraktal(SVGdraw &drawing, double x, double y, int N, double D, double R, farba* colours, double* area){
  if(N>0){
    bool paralelny = (N%2==0) ? false : true;
    stvorec(drawing, x, y, D, colours[N-1], paralelny);
    //cout << D*D << "|" << N << "|" << D << "|" << R << "|" << paralelny << endl;
    if(!paralelny) {
      area[N-2] += fraktal(drawing, x - D/sqrt(2), y, N-1, D*R, R, colours, area);
      area[N-2] += fraktal(drawing, x + D/sqrt(2), y, N-1, D*R, R, colours, area);
      area[N-2] += fraktal(drawing, x, y - D/sqrt(2), N-1, D*R, R, colours, area);
      area[N-2] += fraktal(drawing, x, y + D/sqrt(2), N-1, D*R, R, colours, area);
    } else {
      area[N-2] += fraktal(drawing, x - D/2, y - D/2,N-1, D*R, R, colours, area);
      area[N-2] += fraktal(drawing, x - D/2, y + D/2,N-1, D*R, R, colours, area);
      area[N-2] += fraktal(drawing, x + D/2, y - D/2,N-1, D*R, R, colours, area);
      area[N-2] += fraktal(drawing, x + D/2, y + D/2,N-1, D*R, R, colours, area);
    }
    //cout << N << "|" << area[N-1] << endl;
  }
  return D*D;
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
