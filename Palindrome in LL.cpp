#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

class Node
{
public:
  char data;
  Node* next;

  Node()
  {
    data='\0';
    next=NULL;
  }

  Node(char c)
  {
    this->data=c;
    this->next=NULL;
  }
};

class LinkedList
{
public:
  Node* head;

  LinkedList()
  {
    head=NULL;
  }

  void Insert(char c)
  {
    Node* n=new Node(c);
    if(head==NULL)
    {
      head=n;
      return;
    }
    Node* temp=head;
    while(temp->next!=NULL)
    {
      temp=temp->next;
    }
    temp->next=n;
    return;
  }
};

void createList(string s,LinkedList* l)
{
  for(int i=0;i<s.size();i++)
  {
    char ch=s[i];
    l->Insert(ch);
  }
}

int checkpalindrome(int size,LinkedList* l)
{
  int mid;
  vector<char> stack;
  if(l->head==NULL)
  {
    cout<<"Empty";
  }
  Node* temp=l->head;
  if(size%2==0) {mid=size/2;}
  else {mid=(size-1)/2;}

  for(int i=0;i<mid;i++)
  {
    stack.push_back(temp->data);
    temp=temp->next;
  }

  if(size%2==0)
  {
    for(int i=0;i<mid;i++)
    {
      if(temp->data==stack.back())
      {
        temp=temp->next;
        stack.pop_back();
        continue;
      }
      else
      {
        return -1;
      }
    }
  }
  else
  {
    for(int i=0;i<mid;i++)
    {
      temp=temp->next;
      if(temp->data==stack.back())
      {
        stack.pop_back();
        continue;
      }
      else
      {
        return -1;
      }
    }
  }
  return 1;
}

int main()
{
  vector<string> names;
  int n;
  LinkedList l[50];
  cout<<"Enter number of strings you want to check: ";
  cin>>n;
  cout<<"Enter strings: ";
  for(int i=0;i<n;i++)
  {
    string e;
    cin>>e;
    names.push_back(e);
    std::transform(e.begin(),e.end(),e.begin(),::tolower);
    createList(e,&l[i]);
    if(checkpalindrome(e.size(),&l[i])==1)
    {
      cout<<names[i]<<" is a palindrome."<<endl;
    }
    else
    {
      cout<<names[i]<<" is not a palindrome."<<endl;
    }
  }
  return 0;
}
