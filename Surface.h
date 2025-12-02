#ifndef SURFACE_H
#define SURFACE_H

class Surface {
public:
  Surface(int idPointA, int idPointB)
      : idPointA(idPointA), idPointB(idPointB) {};
  int idPointA;
  int idPointB;
};

#endif
