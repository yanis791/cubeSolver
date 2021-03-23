#ifndef CUBESOLVE_HPP
#define CUBESOLVE_HPP

#include <string>

using namespace std;

typedef struct node
{
  /* data */
  struct node *F;
  struct node *U;
  struct node *R;

  int depth;
  char type;
}treeNode,*treeRoot;

class cubesolve
{
private:
  /* data */
  string F,B,U,D,L,R;
  string operate;
public:
  cubesolve(string cubeOrigin);
  void turnF();
  void turnU();
  void turnR();
  void cubeSwitch(char &a,char &b,char &c,char &d);
  void show();
};

cubesolve::cubesolve(string cubeOrigin)
{
  F.assign(cubeOrigin,0,4);
  cubeOrigin.erase(0,4);

  R.assign(cubeOrigin,0,4);
  cubeOrigin.erase(0,4);

  B.assign(cubeOrigin,0,4);
  cubeOrigin.erase(0,4);

  L.assign(cubeOrigin,0,4);
  cubeOrigin.erase(0,4);

  U.assign(cubeOrigin,0,4);
  cubeOrigin.erase(0,4);

  D.assign(cubeOrigin,0,4);
  cubeOrigin.erase(0,4);
}



string cube;


void treeCreate(treeRoot &root, int depth,char type);
void treeDisplay(treeRoot root);

#endif //CUBESOLVE_HPP
