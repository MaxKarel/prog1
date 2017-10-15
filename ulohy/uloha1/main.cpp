#include <cmath>
#include <iostream>
#include "../../SVGdraw.h"

using namespace std;

const int N_POSTS = 10;
const int N_HOUSE = 100;

const char *farby[N_POSTS] = {"red", "green", "blue", "white", "black", "gray",
"yellow", "brown", "orange", "purple"};

struct point {
  double x, y; // suradnice pointu v rovine
};
typedef point image_size;

double distance(point &point1, point &point2);
void print_point(point &b);
int nearest_post(point house_location, point *posts, int p);

int main() {
  point posts[N_POSTS];
  point house[N_HOUSE];
  int hp_ptr[N_HOUSE]; // House to post pointer
  int h_operates[N_POSTS];
  int p, h; // Number of posts and houses in input
  image_size image;
  int point_size;
  for (int i = 0; i < N_POSTS; i++) {
    h_operates[i] = 0;
  }
  // INPUTS
  cin >> h;
  cin >> p;
  for (int i = 0; i < h; i++) {
    cin >> house[i].x;
    cin >> house[i].y;
  }
  for (int i = 0; i < p; i++) {
    cin >> posts[i].x;
    cin >> posts[i].y;
  }
  cin >> image.x;
  cin >> image.y;
  cin >> point_size;
  // NON GRAPHICAL PART
  for (int i = 0; i < h; i++) {
    hp_ptr[i] = nearest_post(house[i], posts, p);
    h_operates[hp_ptr[i]]++;
    cout << "dom " << i << " posta " << hp_ptr[i] << endl;
  }
  for (int i = 0; i < p; i++) {
    cout << "posta " << i << " pocet domov " << h_operates[i] << endl;
  }
  // SVG stuff
  SVGdraw drawing(image.x, image.y, "posty.svg");
  drawing.setFillColor("black");
  for(int i = 0 ; i < h; i++) {
    drawing.drawLine(house[i].x, house[i].y, posts[hp_ptr[i]].x, posts[hp_ptr[i]].y);
  }
  for(int i = 0 ; i < p; i++) {
    drawing.setFillColor(farby[i]);
    drawing.drawRectangle(posts[i].x-point_size/2, posts[i].y-point_size/2, point_size, point_size);
  }
  for(int i = 0 ; i < h; i++) {
    drawing.setFillColor(farby[hp_ptr[i]]);
    drawing.drawEllipse(house[i].x, house[i].y, point_size/2, point_size/2);
  }
  drawing.finish();
  return 0;
}

double distance(point &point1, point &point2) {
  // funkcia vrati dlzku usecky z pointu 1 do pointu 2
  double dx = point1.x - point2.x;
  double dy = point1.y - point2.y;
  return sqrt(dx * dx + dy * dy);
}
void print_point(point &b) {
  // funkcia vypise surandice pointu v zatvorke a koniec riadku
  cout << "(" << b.x << "," << b.y << ")" << endl;
}
int nearest_post(point house_location, point *posts, int p) {
  int index = 0;
  int min, dist;
  min = distance(house_location, posts[0]);

  for (int i = 1; i < p; i++) {
    dist = distance(house_location, posts[i]);
    if (min > dist) {
      index = i;
      min = dist;
    }
  }

  return index;
}
