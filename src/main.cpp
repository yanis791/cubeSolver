#include <ros/ros.h>
#include "cubesolve.hpp"


int main(int argc, char **argv)
{
  ros::init(argc, argv, "cubesolve");

  //  /node_namespace/node_name
  ros::NodeHandle nodeHandle("~");

  if (!nodeHandle.param<string>("cube", cube,"N"))
  ROS_WARN_STREAM("Did not load node_rate.");

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
