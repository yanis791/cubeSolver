#ifndef CUBESOLVE_HPP
#define CUBESOLVE_HPP

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
public:
  cubesolve(string cubeorigin);
};

cubesolve::cubesolve(string cubeOrigin)
{
    F = 
}



string cube;


void treeCreate(treeRoot &root, int depth,char type);
void treeDisplay(treeRoot root);

#endif //CUBESOLVE_HPP
