
// void PreOrder(Node *Root){
//   assert(Root!=nullptr and "Root null for preorder"); 
//   cout<<Root->Value<<" "; 
//   if(Root->Left) PreOrder(Root->Left); 
//   if(Root->Right) PreOrder(Root->Right);
// }

// void InOrder(Node *Root){
//   assert(Root!=nullptr and "Root null for inorder"); 
//   if(Root->Left) InOrder(Root->Left); 
//   cout<<Root->Value<<" "; 
//   if(Root->Right) InOrder(Root->Right);
// }

// void PostOrder(Node *Root){
//   assert(Root!=nullptr and "Root null for postorder"); 
//   if(Root->Left) PostOrder(Root->Left); 
//   if(Root->Right) PostOrder(Root->Right);
//   cout<<Root->Value<<" "; 
// }


// void VerifyTree(Node *Root){
//   cout<<"Preorder : ";
//   PreOrder(Root); 
//   cout<<'\n';

//   cout<<"Inorder : ";
//   InOrder(Root); 
//   cout<<'\n';

//   cout<<"Postorder : "; 
//   PostOrder(Root); 
//   cout<<'\n';
// }

// void VerifyNode(const Node *Node){
//   cout<<" NodeVal : "<<Node->Value<<' ';
//   if(Node->Parent) cout<<" Parent : "<<Node->Parent->Value<<' '; 
//   else cout<<" Parent : NULL";
//   if(Node->Left) cout<<" Left : "<<Node->Left->Value<<" "; 
//   else cout<<" Left : NULL";
//   if(Node->Right) cout<<" Right : "<<Node->Right->Value<<' '; 
//   else cout<<" Right : NULL";  
// }

// /*
//           1
//             \  
//               6
//              / \
//             3   8
//            / \
//           2   4
// */  
// void BuildTestTreeAndVerify(){
//   Node *Root = GetNewNode(1);
//   Node *RootR = GetNewNode(6);
//   Node *RootRR = GetNewNode(8);
//   Node *RootRL = GetNewNode(3);
//   Node *RootRLL = GetNewNode(2);
//   Node *RootRLR = GetNewNode(4);
//   Node *TreeNodes[] = {Root,RootR,RootRR,RootRL,RootRLL,RootRLR};
//   AttachAToRightOfB(RootR,Root);
//   AttachAToRightOfB(RootRR,RootR);
//   AttachAToLeftOfB(RootRL,RootR);
//   AttachAToLeftOfB(RootRLL,RootRL);
//   AttachAToRightOfB(RootRLR,RootRL);
//   VerifyTree(Root);
//   for(const Node * Nd : TreeNodes){
//     VerifyNode(Nd); 
//     cout<<"\n\n";
//   }
// }

// /*
//           1
//             \  
//               6
//              / \
//             3   8
//            / \
//           2   4
// */ 
// Node *GetTestTree(){
//   Node *Root = GetNewNode(1);
//   Node *RootR = GetNewNode(6);
//   Node *RootRR = GetNewNode(8);
//   Node *RootRL = GetNewNode(3);
//   Node *RootRLL = GetNewNode(2);
//   Node *RootRLR = GetNewNode(4);
//   Node *TreeNodes[] = {Root,RootR,RootRR,RootRL,RootRLL,RootRLR};
//   AttachAToRightOfB(RootR,Root);
//   AttachAToRightOfB(RootRR,RootR);
//   AttachAToLeftOfB(RootRL,RootR);
//   AttachAToLeftOfB(RootRLL,RootRL);
//   AttachAToRightOfB(RootRLR,RootRL);
//   return Root;
// }

// Node *TestTree2(){
//   Node *root = GetNewNode(6); 
//   Node *RR = GetNewNode(8); 
//   Node *RL  = GetNewNode(2); 
//   Node *RLR = GetNewNode(4); 
//   Node *RLL = GetNewNode(1);
//   Node *RLRL = GetNewNode(3);
//   Node *RLRR = GetNewNode(5); 
//   Node *TreeNodes[] = {root,RR,RL,RLR,RLL,RLRL,RLRR}; 
//   AttachAToLeftOfB(RL,root);
//   AttachAToRightOfB(RR,root); 
//   AttachAToRightOfB(RLR,RL); 
//   AttachAToLeftOfB(RLL,RL); 
//   AttachAToLeftOfB(RLRL,RLR); 
//   AttachAToRightOfB(RLRR,RLR);
//   return root;
// }

//  Node *root = GetNewNode(5); 
//   Node *RL = GetNewNode(3);
//   Node *RR = GetNewNode(6);
//   Node *RLL = GetNewNode(1);
//   Node *RLR = GetNewNode(4);
//   AttachAToLeftOfB(RL,root);
//   AttachAToRightOfB(RR,root);
//   AttachAToLeftOfB(RLL,RL);
//   AttachAToRightOfB(RLR,RL);
//   Node *TreeNodes[] = {root,RL,RR,RLL,RLR};

  
// vector<Node*>Tree; 
//   for(int x : {10,7,15,1,9,13,20,-1,30}){
//     Tree.push_back(GetNewNode(x));
//   } 
//   AttachAToLeftOfB(Tree[1],Tree[0]);
//   AttachAToRightOfB(Tree[2],Tree[0]);
//   AttachAToLeftOfB(Tree[3],Tree[1]);
//   AttachAToRightOfB(Tree[4],Tree[1]);
//   AttachAToLeftOfB(Tree[5],Tree[2]);
//   AttachAToRightOfB(Tree[6],Tree[2]);
//   AttachAToLeftOfB(Tree[7],Tree[3]);
//   AttachAToRightOfB(Tree[8],Tree[6]);

//   // Verifier v; 
//   // v.VerifyTree(Tree[0]);

//   // for(Node *x : Tree){
//   //   v.VerifyNode(x);
//   //   cout<<"\n";
//   // }
//   int x; 
//   cin>>x;

//   Node *newRoot = SplayOpreator(Tree[0],x);
//   Verifier v; 
//   v.VerifyTree(newRoot);

//   for(Node *x : Tree){
//     v.VerifyNode(x);
//     cout<<"\n";
//   }

//  vector<Node*>Tree; 
//   for(int x : {10,7,15,1,9,13,20,-1,30}){
//     Tree.push_back(GetNewNode(x));
//   } 
//   AttachAToLeftOfB(Tree[1],Tree[0]);
//   AttachAToRightOfB(Tree[2],Tree[0]);
//   AttachAToLeftOfB(Tree[3],Tree[1]);
//   AttachAToRightOfB(Tree[4],Tree[1]);
//   AttachAToLeftOfB(Tree[5],Tree[2]);
//   AttachAToRightOfB(Tree[6],Tree[2]);
//   AttachAToLeftOfB(Tree[7],Tree[3]);
//   AttachAToRightOfB(Tree[8],Tree[6]);
//   Node *Root = Tree[0];
//   int key; 
//   cin>>key;
//   Root = SplayOpreator(Root,key);
//   Verifier v; 
//   v.VerifyTree(Root);


// SplayTree T;
//   vector<Node*>Tree; 
//   for(int x : {10,7,15,1,9,13,20,-1,30}){
//     Tree.push_back(GetNewNode(x));
//   } 
//   T.AttachAToLeftOfB(Tree[1],Tree[0]);
//   T.AttachAToRightOfB(Tree[2],Tree[0]);
//   T.AttachAToLeftOfB(Tree[3],Tree[1]);
//   T.AttachAToRightOfB(Tree[4],Tree[1]);
//   T.AttachAToLeftOfB(Tree[5],Tree[2]);
//   T.AttachAToRightOfB(Tree[6],Tree[2]);
//   T.AttachAToLeftOfB(Tree[7],Tree[3]);
//   T.AttachAToRightOfB(Tree[8],Tree[6]);
//   T.SetRoot(Tree[0]);

//   Verifier v; 