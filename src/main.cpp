#include <ros/ros.h>
#include "cubesolve.hpp"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "cubesolve");

  //  /node_namespace/node_name
  ros::NodeHandle nodeHandle("~");

  if (!nodeHandle.param<string>("cube", cube,"N"))
  ROS_WARN_STREAM("Did not load node_rate.");

  cubesolve cube("000011112222333344445555");
  cube.turnF();
  cube.show();

  treeRoot root;
  treeCreate(root,0,'N');
  //treeDisplay(root);
  
  return 0;
}

void treeCreate(treeRoot &root, int depth, char type){
  if(depth<=11) {
    root = new treeNode;
    root -> depth = depth;
    root -> type = type;
    treeCreate(root -> F, depth+1,'F');
    treeCreate(root -> U, depth+1,'U');
    treeCreate(root -> R, depth+1,'R');
  }
  else root = nullptr;
}

void treeDisplay(treeRoot root){
  if(root){
    cout<<root -> type<< endl;
    treeDisplay(root -> F);
    treeDisplay(root -> U);
    treeDisplay(root -> R);
  }
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