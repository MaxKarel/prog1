#include "../../SVGdraw.h"
#include <cassert>
#include <cmath>
#include <iostream>

using namespace std;
struct farba {
  int r, g, b;
};
struct params {
  double x, y;
  int N;
  double R, D;
  farba *colours;
  SVGdraw *drawing;
};

const int NMAX = 6;
void stvorec(SVGdraw *drawing, double x, double y, double d, farba &f,
             bool paralelny);
double fraktal(params p, int i, double *area);

int main() {
  int N;
  double R, D; // N=level, R=size, D=
  farba colours[NMAX];
  double area[NMAX];

  cin >> N >> D >> R;
  assert((N >= 1) && (N <= 6));
  assert((D >= 10) && (D <= 100));
  assert((R >= 0.1) && (R <= 0.5));
  for (int i = 0; i < N; i++) {
    cin >> colours[i].r >> colours[i].g >> colours[i].b;
    area[N] = 0;
  }
  SVGdraw drawing(3 * D, 3 * D, "fraktal.svg");

  params init_parameters = {3.0 / 2 * D, 3.0 / 2 * D, N, R, D, colours, &drawing};

  area[N - 1] = fraktal(init_parameters, N, area);
  for (int i = 0; i < N; i++) {
    cout << area[i] << endl;
  }
  drawing.finish();
  return 0;
}

double fraktal(params p, int i, double *area) {
  if (i > 0) {
    bool paralelny = (i % 2 ==  p.N % 2) ? true : false;
    
    stvorec(p.drawing, p.x, p.y, p.D, p.colours[i - 1], paralelny);
    params tmp = p;
    tmp.D *= tmp.R;
    if (!paralelny) {
      tmp.x = p.x - p.D / sqrt(2); //tmp.y = p.y;
      area[i - 2] += fraktal(tmp, i-1, area);
      tmp.x = p.x + p.D / sqrt(2); //tmp.y = p.y;
      area[i - 2] += fraktal(tmp, i-1, area);
      tmp.y = p.y - p.D / sqrt(2); tmp.x = p.x;
      area[i - 2] += fraktal(tmp, i-1, area);
      tmp.y = p.y + p.D / sqrt(2); //tmp.x = p.x;
      area[i - 2] += fraktal(tmp, i-1, area);
    } else {
      tmp.x = p.x - p.D / 2; tmp.y = p.y - p.D / 2;
      area[i - 2] += fraktal(tmp, i-1, area);
      tmp.x = p.x - p.D / 2; tmp.y = p.y + p.D / 2;
      area[i - 2] += fraktal(tmp, i-1, area);
      tmp.x = p.x + p.D / 2; tmp.y = p.y - p.D / 2;
      area[i - 2] += fraktal(tmp, i-1, area);
      tmp.x = p.x + p.D / 2; tmp.y = p.y + p.D / 2;
      area[i - 2] += fraktal(tmp, i-1, area);
    }
  }
  return p.D * p.D; // return area of drawn stvorec
}

void stvorec(SVGdraw *drawing, double x, double y, double d, farba &f,
             bool paralelny) {
  /** do obrazku drawing vykresli stvorec so stredom na suradniciach x,y
   * s dlzkou strany d a farbou f, ktoreho strany budu paralelne s osami
   * ak paralelny=true alebo bude o 45 stupnov otoceny ak
   * paralelny=false */

  drawing->setFillColor(f.r, f.g, f.b);
  if (paralelny) {
    drawing->drawRectangle(x - d / 2, y - d / 2, d, d);
  } else {
    double offset = d / sqrt(2);
    drawing->startPolygon(x - offset, y);
    drawing->addPolygonPoint(x, y - offset);
    drawing->addPolygonPoint(x + offset, y);
    drawing->addPolygonPoint(x, y + offset);
    drawing->drawPolygon();
  }
}
