#ifndef CUBESOLVE_HPP
#define CUBESOLVE_HPP

#include <string>

using namespace std;

string cube;



typedef struct node
{
  /* data */
  struct node *F;
  struct node *U;
  struct node *R;

  int depth;
  string type;
}treeNode,*treeRoot;

class cubesolve
{
private:
  /* data */
  string F,B,U,D,L,R;
  string operate;
public:
  cubesolve(string cube_origin);
  void turnF();
  void turnU();
  void turnR();
  void turn(string type);
  void cubeSwitch(char &a,char &b,char &c,char &d);
  void show();
  bool check();
  bool checkEach(string str);
  string showOperate();
  void addOperate(string type);

};

void treeCreate(treeRoot &root, int depth,char type);
void treeDisplay(treeRoot root);
cubesolve cubeSearch(treeRoot &root,cubesolve cube);

void cubesolve::addOperate(string type){
  operate.append(type);
}


string cubesolve::showOperate(){
  return operate;
}

cubesolve::cubesolve(string cube_origin)
{
  F.assign(cube_origin,0,4);cube_origin.erase(0,4);
  R.assign(cube_origin,0,4);cube_origin.erase(0,4);
  B.assign(cube_origin,0,4);cube_origin.erase(0,4);
  L.assign(cube_origin,0,4);cube_origin.erase(0,4);
  U.assign(cube_origin,0,4);cube_origin.erase(0,4);
  D.assign(cube_origin,0,4);cube_origin.erase(0,4);
}

void cubesolve::turn(string type){
  if(type == "F") turnF();
  if(type == "U") turnU();
  if(type == "R") turnR();
}

void cubesolve::turnF(){
  cubeSwitch(U[3],R[0],D[1],L[2]);
  cubeSwitch(U[2],R[3],D[0],L[1]);
  cubeSwitch(F[0],F[1],F[2],F[3]);
}

void cubesolve::turnR(){
  cubeSwitch(U[2],B[0],D[2],F[2]);
  cubeSwitch(U[1],B[2],D[1],F[1]);
  cubeSwitch(R[0],R[1],R[2],R[3]);
}

void cubesolve::turnU(){
  cubeSwitch(B[1],R[1],F[1],L[1]);
  cubeSwitch(B[0],R[0],F[0],L[0]);
  cubeSwitch(U[0],U[1],U[2],U[3]);
}

void cubesolve::show(){
  cout<<F+R+B+L+U+D<<endl;
}

void cubesolve::cubeSwitch(char &a,char &b,char &c,char &d){
    char e;
    e = a;
    a = d;
    d = c;
    c = b;
    b = e;
}

bool cubesolve::checkEach(string str){
  if(str[0] == str[1] == str[2] == str[3])
    return true;
  else return false;
}
bool cubesolve::check(){
  if(checkEach(F)&&checkEach(B)&&checkEach(U)&&
      checkEach(D)&&checkEach(L)&&checkEach(R))
    return true;
  else return false;
}
#endif //CUBESOLVE_HPP
