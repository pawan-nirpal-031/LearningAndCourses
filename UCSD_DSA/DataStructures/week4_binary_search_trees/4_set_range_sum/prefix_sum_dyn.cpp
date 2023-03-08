#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;
typedef long double ld;
#define Mod 1000000007
#define Infinity (ll)1e18
#define Append(a) push_back(a)
#define Pair(a,b) make_pair(a,b)
#define Clear(a) for(ll &x : a){x=0;}
#define Point(x) std::fixed<<setprecision(15)<<x
#define SetBits(x) __builtin_popcount(x);
#define DebugCase(i,x) cout<<"Case #"<<i<<": "<<x<<'\n'
#define FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define Status(b) (cout<<(b?"YES\n":"NO\n"));


struct Node{
  int Value; 
  Node *Left, *Right, *Parent; 
  Node(){
    Left = Right = Parent = nullptr;
  }
  Node(int Key){
    Value = Key; 
    Left = Right = Parent = nullptr; 
  } 
};


Node* GetNewNode(int Key){
  Node *Nn = new Node(Key);
  return Nn;
}


class Verifier{
public:
    void DepthFirstTreeVerifier(Node *Root){
      if(Root==nullptr) return; 
      cout<<Root->Value<<" > Parent : ";
      if(Root->Parent) cout<<Root->Parent->Value<<' '; 
      else cout<<" null ";
      cout<<"  Left : ";
      if(Root->Left) cout<<Root->Left->Value<<" "; 
      else cout<<"null "; 
      cout<<"  Right : "; 
      if(Root->Right) cout<<Root->Right->Value<<" "; 
      else cout<<"null ";  
      cout<<"\n\n";
      if(Root->Left) DepthFirstTreeVerifier(Root->Left); 
      if(Root->Right) DepthFirstTreeVerifier(Root->Right);
    }

    void VerifyNode(const Node *Node){
      cout<<" NodeVal : "<<Node->Value<<' ';
      if(Node->Parent) cout<<" Parent : "<<Node->Parent->Value<<' '; 
      else cout<<" Parent : NULL";
      if(Node->Left) cout<<" Left : "<<Node->Left->Value<<" "; 
      else cout<<" Left : NULL";
      if(Node->Right) cout<<" Right : "<<Node->Right->Value<<' '; 
      else cout<<" Right : NULL";  
    }
};


class SplayTree{
  Node *TreeRoot;

  // Splays the Given node and returns the root of the new tree.
  Node *ExplicitSplay(Node *NodeToBeSplayed){
    while(NodeToBeSplayed->Parent!=nullptr){
      Node *Parent = NodeToBeSplayed->Parent;
      if(Parent==nullptr) return NodeToBeSplayed;
      if(NodeToBeSplayed->Value<Parent->Value){// This is left node hence right rotate
        RightRotateSubtree(Parent);
      }else{
        LeftRotateSubtree(Parent);
      }
    }
    SetRoot(NodeToBeSplayed);
    return TreeRoot;
  }

public:
  SplayTree(){
    TreeRoot = nullptr;
  }
  
  void AttachAToLeftOfB(Node *A, Node *B){
    B->Left = A; 
    A->Parent = B;
  }

  void AttachAToRightOfB(Node *A, Node *B){
    B->Right = A; 
    A->Parent = B;
  }

  void RightRotateSubtree(Node *SubtreeRoot){
    Node *LeftNode = SubtreeRoot->Left;
    Node *ParentNode = SubtreeRoot->Parent;
    if(LeftNode==nullptr) return;
    if(LeftNode->Right) AttachAToLeftOfB(LeftNode->Right,SubtreeRoot);
    else SubtreeRoot->Left = nullptr;
    LeftNode->Right = SubtreeRoot;
    SubtreeRoot->Parent = LeftNode;
    LeftNode->Parent = ParentNode;
    if(ParentNode){
      if(LeftNode->Value<ParentNode->Value) ParentNode->Left = LeftNode; 
      else ParentNode->Right = LeftNode;
    }
  }


  void LeftRotateSubtree(Node *SubtreeRoot){
    Node *RightNode = SubtreeRoot->Right; 
    Node *ParentNode = SubtreeRoot->Parent; 
    if(RightNode==nullptr) return;
    if(RightNode->Left) AttachAToRightOfB(RightNode->Left,SubtreeRoot);
    else SubtreeRoot->Right = nullptr;
    RightNode->Left = SubtreeRoot; 
    SubtreeRoot->Parent = RightNode; 
    RightNode->Parent = ParentNode;
    if(ParentNode){
      if(RightNode->Value<ParentNode->Value) ParentNode->Left = RightNode; 
      else ParentNode->Right = RightNode;
    }
  }


  Node *SplayOpreator(Node *Root, int Key){
    if(Key==Root->Value or Root==nullptr) return Root;
    Node *NodeToSplay = nullptr;
    Node *TreeRoot = Root;
    while(TreeRoot->Value!=Key){
      if(Key<TreeRoot->Value){
        if(TreeRoot->Left==nullptr){
          NodeToSplay = TreeRoot;
          break;
        }else{
          TreeRoot = TreeRoot->Left;
          NodeToSplay = TreeRoot;
        }
      }else{
        if(TreeRoot->Right==nullptr){
          NodeToSplay = TreeRoot; 
          break;
        }else{
          TreeRoot = TreeRoot->Right;
          NodeToSplay = TreeRoot;
        }
      }
    }
    return ExplicitSplay(NodeToSplay);
  }

  bool Search(int Key){
    TreeRoot = SplayOpreator(TreeRoot,Key);
    return TreeRoot->Value==Key;
  }

  void SetRoot(Node *CandidateRoot){
    this->TreeRoot = CandidateRoot;
  }

  Node *GetRoot(){
    return this->TreeRoot;
  }

  void Insert(int Key){
    Node *NewNode = GetNewNode(Key);
    Node *Root = this->TreeRoot; 
    if(Root==nullptr){
      this->TreeRoot = NewNode; 
      return;
    }
    Node *Iterator = Root; 
    while(Iterator){
      if(Iterator==nullptr) break;
      if(Key<Iterator->Value){
        if(Iterator->Left){
          Iterator = Iterator->Left;
        }else{
          Iterator->Left = NewNode; 
          NewNode->Parent = Iterator; 
          Iterator = nullptr;
        }
      }else{
        if(Iterator->Right){
          Iterator = Iterator->Right;
        }else{
          Iterator->Right = NewNode; 
          NewNode->Parent = Iterator; 
          Iterator = nullptr;
        }
      }
    }
    ExplicitSplay(NewNode);
  } 

  Node *ChatGPTExplicitSplay(Node *NodeToBeSplayed){
    while(NodeToBeSplayed->Parent!=nullptr){
      Node *Parent = NodeToBeSplayed->Parent; 
      Node *GrandParent = Parent->Parent;
      if(Parent==nullptr) return NodeToBeSplayed;
      if(GrandParent==nullptr){
        if(NodeToBeSplayed->Value<Parent->Value){// This is left node hence right rotate
          RightRotateSubtree(Parent);
        }else{
          LeftRotateSubtree(Parent);
        }
      }else{
        if((NodeToBeSplayed->Value<Parent->Value)==(Parent->Value<GrandParent->Value)){
          // Both values are on the same side
          if(NodeToBeSplayed->Value<Parent->Value){
            RightRotateSubtree(GrandParent);
            RightRotateSubtree(Parent);
          }else{
            LeftRotateSubtree(GrandParent);
            LeftRotateSubtree(Parent);
          }
        }else{
          if(NodeToBeSplayed->Value<Parent->Value){
            RightRotateSubtree(Parent);
            LeftRotateSubtree(Parent);
          }else{
            LeftRotateSubtree(Parent);
            RightRotateSubtree(Parent);
          }
        }
      }
    }
    SetRoot(NodeToBeSplayed);
    return TreeRoot;
  }
 

  void DeleteNode(int Key){
    Node *Root = GetRoot();
    if(Root==nullptr) return;
    if(Root->Left==nullptr and Root->Right==nullptr and Key==Root->Value){
      delete(Root);
      TreeRoot = nullptr;
      return;
    }
    SplayOpreator(Root,Key);
    Root = GetRoot();
    if(Root->Value!=Key) return;
    Node *AttacherNode = Root->Left;
    if(AttacherNode){
      if(Root->Right){
        Node *Iterator = Root->Right;
        while(Iterator->Left!=nullptr) Iterator = Iterator->Left; 
        Iterator->Left = AttacherNode;  
        AttacherNode->Parent = Iterator; 
        TreeRoot = Root->Right; 
        Root->Right = nullptr; 
        TreeRoot->Parent = nullptr; 
        delete(Root);
      }else{ 
        TreeRoot = Root->Left;
        Root->Left = nullptr;
        TreeRoot->Parent = nullptr; 
        delete(Root);
      }
    }else{
      if(Root->Right){
        TreeRoot = Root->Right;
        Root->Right = nullptr; 
        TreeRoot->Parent = nullptr; 
        delete(Root);
      }
    }
  }
};


void PerformanceBenchmarking(){
  SplayTree T; 
  int numnodes = 50;
  vector<int>values(numnodes,0);
  vector<int>randomizedInsert(numnodes,0);
  for(int i =0;i<numnodes;i++) randomizedInsert[i] = rand()%numnodes;
  for(int i =0;i<numnodes;i++) T.Insert(randomizedInsert[i]);
  vector<int>randomizedSpaly(numnodes,0);
  for(int i =0;i<numnodes;i++) randomizedSpaly[i] = rand()%numnodes;  
  // now bmk
  auto start = chrono::high_resolution_clock::now();
  for(int i =0;i<numnodes;i++) T.SplayOpreator(T.GetRoot(),randomizedSpaly[i]);
  auto end = chrono::high_resolution_clock::now();
  double time_taken = chrono::duration_cast<chrono::nanoseconds>(end - start).count(); 
  cout<<time_taken;
}

int main(){
  FastIO;
  PerformanceBenchmarking();
  return 0;
}
