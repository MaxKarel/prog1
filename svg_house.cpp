#include "SVGdraw.h"

int main(void) {
  /* Vytvor obrĂˇzok s rozmermi 200x300 pixelov a 
   * uloĹľ ho do sĂşboru domcek1.svg*/
  SVGdraw drawing(200, 300, "domcek1.svg");

  /* Nakresli obdÄşĹľnik (Ĺˇtvorec) s ÄľavĂ˝m hornĂ˝m rohom v 50, 150
   * a ĹˇĂ­rkou aj dÄşĹľkou 100. */
  drawing.drawRectangle(50, 150, 100, 100);

  /* PreÄŤiarkni Ĺˇtvorec dvomi ÄŤiarami po uhloprieÄŤke. */
  drawing.drawLine(50, 250, 150, 150);
  drawing.drawLine(50, 150, 150, 250);

  /* Nakresli strechu ako dve ÄŤiary. */
  drawing.drawLine(50, 150, 100, 50);
  drawing.drawLine(150, 150, 100, 50);

  /* UkonÄŤi vypisovanie obrĂˇzka. */
  drawing.finish();
}
