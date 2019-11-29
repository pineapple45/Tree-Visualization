
#include<iostream>
using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    int height;
    Node* rchild;
};

class Queue{
private:
    int size = 100;
    int front;
    int rear;
    Node** Q;
public:
    Queue()
    {
        front = rear = NULL;
        Q = new Node*[size];
    }

   int create(Queue *q,int size);
   void enqueue(Queue *q,Node* x);
   Node* dequeue(Queue *q);
   int isEmpty(Queue q);
   int elementsCount(Queue q);;

};

int Queue :: create(Queue *q,int size)
{
 //q->Q = (Node**)malloc(size*sizeof(Node*)); //
  q->Q = new Node*[size];
 q->front = q->rear = -1;
}

void Queue :: enqueue(Queue *q,Node* x)
{
    if(q->rear == q->size-1)
        cout<<"The queue is full!";
    else
    {
       q->rear++;
       q->Q[q->rear] = x;
    }
}


Node* Queue :: dequeue(Queue *q)
{
    Node*x = NULL;
    if(q->rear == q->front)
        cout<<"The queue is empty!!";
    else
    {
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

int Queue :: isEmpty(Queue q)
{
    if(q.front == q.rear)   //WE CAN WRITE THE WHOLE FUNCTION IN A SINGLE LINE AS ---> "return q.front == q.rear"
        return 1;
    else
        return 0;
}


int Queue :: elementsCount(Queue q)
{
    return (q.rear - q.front);
}

class tree{
public:
    int total_nums;
    int *in;
    int *pre;
    Node*root;
    //Node* n_root;
    tree()
    {
       root = NULL;
    }

    void createArray(tree *t);
    void createtree();
    void preorder(Node* p,tree* t);

    void n_inorder(Node* p);
    void n_preorder(Node* p);

    void inorder(Node* p,tree* t);
    void postorder(Node* p);
    void levelorder(Node* p);
    void create_levelorder(Node* p);
    int countNodes(Node* p);
    struct Node *RInsert(struct Node *p,int key);

    void MAXInsert(int num[],int n);
    void MINInsert(int num[],int n);

    void create_Heap_Tree(int num[],int e);


    int NodeHeight(Node* g);
    int BalanceFactor(Node* g);
    Node* LLRotation(Node* g);
    Node* LRRotation(Node* g);
    Node* RLRotation(Node* g);      // THIS FUNCTION IS NOT WORKING
    Node* RRRotation(Node* g);

    Node* InsertElement(struct Node *g,int key);


    int Search(int data,tree* t,int inStart,int inEnd);
    Node* createTree(tree* t,int inStart,int inEnd);

};



void tree::createArray(tree* t)
{
    t->in = new int[t->total_nums];
    t->pre = new int[t->total_nums];
}



void tree :: MAXInsert(int num[],int n)
{
  int i = n;
  int temp;
  temp = num[i];
  while(i>1 && temp > num[i/2])
  {
      num[i] = num[i/2];
      i = i/2;
  }
  num[i] = temp;
}

void tree :: MINInsert(int num[],int n)
{
  int i = n;
  int temp;
  temp = num[i];
  while(i>1 && temp < num[i/2])
  {
      num[i] = num[i/2];
      i = i/2;
  }
  num[i] = temp;
}

void display(int num[],int e)
{
    for(int i = 1;i<=e;i++)
    {
        cout<<num[i]<<" ";
    }
}

void tree :: createtree()
{
   Queue q;
   q.create(&q,100);

    Node*p;
    int x;

    cout<<"enter the root value: ";
    cin>>x;

    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(&q,root);

    while(!q.isEmpty(q))
    {
        p = q.dequeue(&q);
        cout<<"Enter the value of the left child of "<<p->data<<" :";
        cin>>x;

        if(x != -1)
        {
           Node*t = new Node;
           t->data = x;
           t->lchild = t->rchild = NULL;
           p->lchild = t;
           q.enqueue(&q,t);
        }


        cout<<"Enter the value of the right child of "<<p->data<<" :";
        cin>>x;

        if(x != -1)
        {
           Node*t = new Node;
           t->data = x;
           t->lchild = t->rchild = NULL;
           p->rchild = t;
           q.enqueue(&q,t);
        }
    }
}



Node* tree :: RInsert(struct Node *p,int key)
{
 struct Node *t=NULL;

 if(p==NULL)
 {
 t=(struct Node *)malloc(sizeof(struct Node));
 t->data=key;
 t->lchild=t->rchild=NULL;
 return t;
 }
 if(key < p->data)
 p->lchild=RInsert(p->lchild,key);
 else if(key > p->data)
 p->rchild=RInsert(p->rchild,key);

 return p;
}



void tree :: create_Heap_Tree(int num[],int e)
{

    Queue q;
    q.create(&q,100);

    Node* p;

    root = new Node;
    root->data = num[1];
    root->lchild = root->rchild = NULL;
    q.enqueue(&q,root);

    int i = 1;
    while(!q.isEmpty(q))
    {
        int j = 2*i;
        p = q.dequeue(&q);
        if(j<=e-1)
        {
           Node*t = new Node;
           t->data = num[j];
           t->lchild = t->rchild = NULL;
           p->lchild = t;
           q.enqueue(&q,t);
        }


        j = 2*i+1;

        if(j<=e+1)
        {
           Node*t = new Node;
           t->data = num[j];
           t->lchild = t->rchild = NULL;
           p->rchild = t;
           q.enqueue(&q,t);
        }
        i++;
    }

}


int tree :: NodeHeight(Node* g)
{
    int hl,hr;
    hl = g && g->lchild?g->lchild->height:0;
    hr = g && g->rchild?g->rchild->height:0;

    return hl>hr?hl+1:hr+1;
}


int tree :: BalanceFactor(Node* g)
{
    int hl,hr;
    hl = g && g->lchild?g->lchild->height:0;
    hr = g && g->rchild?g->rchild->height:0;

    return hl-hr;
}

Node* tree :: LLRotation(Node* g)
{
    Node*gl = g->Lchild;
    Node*glr = gl->Rchild;

    gl->Rchild = g;
    g->Lchild = glr;
    g->height = NodeHeight(g);
    gl->height = NodeHeight(gl);

    if(root == g)
        root = gl;

    return gl;
}

Node*tree :: LRRotation(Node* g)
{
  Node*gl = g->Lchild;
  Node*glr = gl->Rchild;

  gl->Rchild = glr->Lchild;
  g->Lchild = glr->Rchild;

  glr->Lchild = gl;
  glr->Rchild = g;

  gl->height = NodeHeight(gl);
  g->height = NodeHeight(g);
  glr->height = NodeHeight(glr);

  if(root == g)
    root = glr;

  return glr;
}

Node*tree :: RLRotation(Node* g)      // THIS FUNCTION IS NOT WORKING
{
  Node*gr = g->Rchild;
  Node*grl = gr->Lchild;

  g->Rchild = grl->Lchild;
  gr->Lchild = grl->Rchild;

  grl->Lchild = g;
  grl->Rchild = gr;

  g->height = NodeHeight(g);
  gr->height = NodeHeight(gr);
  grl->height = NodeHeight(grl);

  if(root == g)
    root = grl;

  return grl;
}

Node*tree :: RRRotation(Node* g)
{
    Node*gr = g->Rchild;
    Node*grl = gr->Lchild;

    gr->Lchild = g;
    g->Rchild = grl;

    g->height = NodeHeight(g);
    gr->height = NodeHeight(gr);

    if(root == g)
        root = gr;

    return gr;
}



Node* tree :: InsertElement(struct Node *g,int key)
{
 Node *p=NULL;

 if(g==NULL)
 {
      p = new Node;
      p->data = key;
      p->height = 1;
      p->lchild = p->rchild = NULL;
      return p;
 }
 if(key < g->data)
 g->lchild=InsertElement(g->lchild,key);
 else if(key > g->data)
 g->rchild=InsertElement(g->rchild,key);

 g->height = NodeHeight(g);

  if(BalanceFactor(g) == 2 && BalanceFactor(g->lchild) == 1)
     return LLRotation(g);
  else if(BalanceFactor(g) == 2 && BalanceFactor(g->lchild) == -1)
     return LRRotation(g);
  else if(BalanceFactor(g) == -2 && BalanceFactor(g->rchild) == 1)
     return RLRotation(g);
  else if(BalanceFactor(g) == -2 && BalanceFactor(g->rchild) == -1)
     return RRRotation(g);

   return g;

}


void tree :: preorder(Node* p,tree* t)
{
    static int i = 0;
    if(p)
    {
        cout<<p->data<<" ";
        t->pre[i] = p->data;
        i++;
        preorder(p->lchild,t);
        preorder(p->rchild,t);
    }
}

void tree :: n_preorder(Node* p)
{
    if(p)
    {
        cout<<p->data<<" ";
        n_preorder(p->lchild);
        n_preorder(p->rchild);
    }
}


void tree :: inorder(Node* p,tree* t)
{
   static int i = 0;
   if(p)
   {
     inorder(p->lchild,t);
     cout<<p->data<<" ";
     t->in[i] = p->data;
     i++;
     inorder(p->rchild,t);
   }
}

void tree :: n_inorder(Node* p)
{
   if(p)
   {
     n_inorder(p->lchild);
     cout<<p->data<<" ";
     n_inorder(p->rchild);
   }
}


void tree :: postorder(Node* p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}



void tree :: levelorder(Node* p)
{
  Queue q;

  q.create(&q,100);
  cout<<p->data<<" ";
  q.enqueue(&q,p);

  while(!q.isEmpty(q))
  {
      p = q.dequeue(&q);
      if(p->lchild != NULL)
      {
          cout<<p->lchild->data<<" ";
          q.enqueue(&q,p->lchild);
      }

      if(p->rchild != NULL)
      {
          cout<<p->rchild->data<<" ";
          q.enqueue(&q,p->rchild);
      }
  }
}


void tree :: create_levelorder(Node* p)
{
  Node* track;
  Queue q;
  q.create(&q,100);
  cout<<"Element at each level are as follows: "<<endl;
  cout<<p->data<<" ";
  cout<<endl;
  q.enqueue(&q,p);

  int NodeCount = 0;
  while(!q.isEmpty(q))
  {
      p = q.dequeue(&q);
      track = p->rchild;
      if(p->lchild != NULL)
      {
          cout<<p->lchild->data<<" ";
          q.enqueue(&q,p->lchild);
          NodeCount++;
      }

      if(p->rchild != NULL)
      {
          cout<<p->rchild->data<<" ";
          q.enqueue(&q,p->rchild);
          NodeCount++;
      }

      int C = q.elementsCount(q);

      if(C == NodeCount)
      {
        cout<<endl;
        NodeCount = 0;
      }
  }
}

int tree :: countNodes(Node* p)
{
    int x,y;
    if(p)
    {
        x = countNodes(p->lchild);
        y = countNodes(p->rchild);
        return x+y+1;
    }
    return 0;
}



int tree::Search(int data,tree* t,int inStart,int inEnd)
{
    for(int i = inStart;i<=inEnd;i++)
    {
        if(t->in[i] == data)
            return i;
    }
    cout<<"Element not found in infix expression! Check your infix/prefix expression!";
}



Node* tree::createTree(tree* t,int inStart,int inEnd)
{
  static int preIndex = 0;
  if(inStart>inEnd)
    return NULL;

  Node* tNode = new Node;
  tNode->data = t->pre[preIndex++];
  tNode->lchild = NULL;
  tNode->rchild = NULL;

  int index = Search(tNode->data,t,inStart,inEnd);

  if(inStart == inEnd)
    return tNode;

  tNode->lchild = createTree(t,inStart,index-1);
  tNode->rchild = createTree(t,index+1,inEnd);
  return tNode;
}






int main()
{

  tree t;
  cout<<"The following program gives pre-order,post-order,in-order,Level-order reprsentation of the data present in different trees.But Most importantly the program also gives all the elements present at a particular level.";
  cout<<endl<<"The program works upon the following trees: ";
  cout<<endl;
  cout<<"1.General Binary Trees"<<endl;
  cout<<"2.Binary Search Trees"<<endl;
  cout<<"3.Max Heap Trees"<<endl;
  cout<<"4.Min Heap Trees"<<endl;
  cout<<"5.AVL Trees"<<endl;


  cout<<"Enter the number corrosponding to the tree type: "<<endl;
  int n;
  cin>>n;

  switch(n)
  {
  case 1:
      {
      t.createtree();
      cout<<endl;

      t.total_nums = t.countNodes(t.root);
      t.createArray(&t);

      cout<<"The preorder representation is: ";
      t.preorder(t.root,&t);
      cout<<endl;
      cout<<"The inorder reprsentation is: ";
      t.inorder(t.root,&t);
      cout<<endl;
      cout<<"The postorder representation is: ";
      t.postorder(t.root);
      cout<<endl;
      cout<<"The Level order representation is: ";
      t.levelorder(t.root);
      cout<<endl;

      t.root = t.createTree(&t,0,t.total_nums-1);
      t.create_levelorder(t.root);
      }
      break;


  case 2:
      {
      cout<<"Enter the numbers.Enter -1 to stop taking numbers!!: ";
      int num;
      int count = 0;
      while(num != -1)
      {
         cin>>num;

         if(num == -1)
         {
             break;
         }
         if(count == 0)
            t.root = t.RInsert(t.root,num);
         t.RInsert(t.root,num);
      }
      cout<<endl;

      t.total_nums = t.countNodes(t.root);
      t.createArray(&t);

      cout<<"The preorder representation is: ";
      t.preorder(t.root,&t);
      cout<<endl;
      cout<<"The inorder reprsentation is: ";
      t.inorder(t.root,&t);
      cout<<endl;
      cout<<"The postorder representation is: ";
      t.postorder(t.root);
      cout<<endl;
      cout<<"The Level order representation is: ";
      t.levelorder(t.root);
      cout<<endl;

      t.root = t.createTree(&t,0,t.total_nums-1);
      t.create_levelorder(t.root);
      }
      break;


   case 3:
       {
        cout<<"Enter the elements.Enter -1 to stop entering the numbers: ";
        int n;
        int num[50];
        num[0] = 0;
        int i = 1;
        while(n != -1)
        {
         cin>>n;
         if(n == -1)
            break;
         num[i++] = n;
        }

        for(int j = 2;j<i;j++)
        {
          t.MAXInsert(num,j);
        }

          t.create_Heap_Tree(num,i-1);

          cout<<"The preorder representation is: ";
          t.n_preorder(t.root);
          cout<<endl;
          cout<<"The inorder representation is: ";
          t.n_inorder(t.root);
          cout<<endl;
          cout<<"The postorder representation is: ";
          t.postorder(t.root);
          cout<<endl;
          cout<<"The Level order representation is: ";
          t.levelorder(t.root);
          cout<<endl;

          t.create_levelorder(t.root);
       }
          break;

   case 4:
       {
        cout<<"Enter the elements.Enter -1 to stop entering the numbers: ";
        int n;
        int num[50];
        num[0] = 0;
        int i = 1;
        while(n != -1)
        {
         cin>>n;
         if(n == -1)
            break;
         num[i++] = n;
        }

        for(int j = 2;j<i;j++)
        {
          t.MINInsert(num,j);
        }

          t.create_Heap_Tree(num,i-1);

          cout<<"The preorder representation is: ";
          t.n_preorder(t.root);
          cout<<endl;
          cout<<"The inorder representation is: ";
          t.n_inorder(t.root);
          cout<<endl;
          cout<<"The postorder representation is: ";
          t.postorder(t.root);
          cout<<endl;
          cout<<"The Level order representation is: ";
          t.levelorder(t.root);
          cout<<endl;

          t.create_levelorder(t.root);
       }
          break;

   case 5:
       {
      cout<<"Enter the numbers.Enter -1 to stop taking numbers!!: ";
      int num;
      int count = 0;
      while(num != -1)
      {
         cin>>num;

         if(num == -1)
         {
             break;
         }
         if(count == 0)
            t.root = t.InsertElement(t.root,num);
         t.InsertElement(t.root,num);
      }
      cout<<endl;

          cout<<"The preorder representation is: ";
          t.n_preorder(t.root);
          cout<<endl;
          cout<<"The inorder representation is: ";
          t.n_inorder(t.root);
          cout<<endl;
          cout<<"The postorder representation is: ";
          t.postorder(t.root);
          cout<<endl;
          cout<<"The Level order representation is: ";
          t.levelorder(t.root);
          cout<<endl;

          t.create_levelorder(t.root);
       }
       break;

}


 // t.total_nums = t.countNodes(t.root);
//  t.createArray(t.total_nums);
}





