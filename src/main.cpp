#include <ros/ros.h>
#include "cubesolve.hpp"


int main(int argc, char **argv)
{

  cubesolve cube("000011112222333344445555");
  cube.turnF();
  cube.show();

  treeRoot root;
  treeCreate(root,0,'N');
  //treeDisplay(root);
  cubesolve finish_cude = cubeSearch(root,cube);
  cout<<cube.showOperate()<< endl;
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

cubesolve cubeSearch(treeRoot &root,cubesolve cube){
  if(root){
    if(root -> type != "N"){
      cube.turn(root -> type);
      cube.addOperate(root -> type);
    }
      
    if(cube.check())  return cube;
    cubeSearch(root -> F, cube);
    cubeSearch(root -> U, cube);
    cubeSearch(root -> R, cube);
  }
}