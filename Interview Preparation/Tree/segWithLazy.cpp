void build(int* arr, int* tree, int start, int end, int treeNode)
{
    if(start == end){
        tree[treeNode] = arr[start];
        return;
    }
    int mid = (start+end)/2;
    build(arr,tree,start,mid,2*treeNode+1);
    build(arr,tree,mid+1,end,2*treeNode+2);
    tree[treeNode] = min(tree[2*treeNode+1], tree[2*treeNode+2]);
}

void  updateSegTreeLazy(int* tree,int *lazy,int rs,int re,int qs,int qe,int change,int pos){
  if(rs > re) return;

  //if update propagation required 
  if(lazy[pos]!=0){
    if(rs!=re){
      lazy[2*pos+1]+=lazy[pos];
      lazy[2*pos+1]+=lazy[pos];
    }
    lazy[pos]=0;
  }

  //no overlapp
  if(rs > qe || re < qs)
      return;

  //total overlapp
  if(rs >= qs && re <= qe){
      tree[pos]+=change;
      if(rs!=re){
        lazy[2*pos+1]+=change;
        lazy[2*pos+1]+=change;
      }
  }

  //partial overlapp
  int mid=(rs+re)/2;
  
  updateSegTreeLazy(tree,lazy,rs,mid,qs,qe,change,2*pos+1);
  
  updateSegTreeLazy(tree,lazy,mid+1,re,qs,qe,change,2*pos+2);
  
  tree[pos] = tree[2*pos+1]+tree[2*pos+2];
}