// A C program to implement Ukkonen's Suffix Tree Construction
#include <bits/stdc++.h>
#define MAX_CHAR 256

/*
Longest repeated substring with overlappnig
*/
using namespace std;
struct suffix {
  struct suffix *children[MAX_CHAR];
  struct suffix *suffixLink;
  int start;
  int *end;
  int suffixIndex;
};
  
typedef struct suffix Node;
  
char text[100]; //Input string
Node *root = NULL; //Pointer to root node
Node *lnode = NULL;
Node *anode = NULL;
int aedge = -1;
int alength = 0;
int rsuffixc = 0;
int leafEnd = -1;
int *rootEnd = NULL;
int *splitEnd = NULL;
int size = -1; //Length of input string
  
Node *newNode(int start, int *end){
  Node *node =(Node*) malloc(sizeof(Node));
  int i;
  for (i = 0; i < MAX_CHAR; i++)
    node->children[i] = NULL;
  node->suffixLink = root;
  node->start = start;
  node->end = end;
  node->suffixIndex = -1;
  return node;
}
  
int sedge(Node *n) {
  if(n == root) return 0;
  return *(n->end) - (n->start) + 1;
}
  
int walkDown(Node *currNode){
  if (alength >= sedge(currNode)){
    aedge += sedge(currNode);
    alength -= sedge(currNode);
    anode = currNode;
    return 1;
  }
  return 0;
}
  
void extendSuffixTree(int pos){
  leafEnd = pos;
  rsuffixc++;
  lnode = NULL;
  while(rsuffixc > 0) {
    if (alength == 0) aedge = pos; 
    if (anode->children[text[aedge]] == NULL){
      anode->children[text[aedge]] =newNode(pos, &leafEnd);
      if (lnode != NULL){
        lnode->suffixLink = anode;
        lnode = NULL;
      }
    }
    else{
      Node *next = anode->children[text[aedge]];
      if (walkDown(next)){
        continue;
      }
      if (text[next->start + alength] == text[pos]){
        if(lnode != NULL && anode != root){
          lnode->suffixLink = anode;
          lnode = NULL;
        }
        alength++;
        break;
      }
      splitEnd = (int*) malloc(sizeof(int));
      *splitEnd = next->start + alength - 1;
      Node *split = newNode(next->start, splitEnd);
      anode->children[text[aedge]] = split;
      split->children[text[pos]] = newNode(pos, &leafEnd);
      next->start += alength;
      split->children[text[next->start]] = next;
      if (lnode != NULL){
        lnode->suffixLink = split;
      }
      lnode = split;
    }
    rsuffixc--;
    if (anode == root && alength > 0) {
      alength--;
      aedge = pos - rsuffixc + 1;
    }
    else if (anode != root) {
      anode = anode->suffixLink;
    }
  }
}
  
void print(int i, int j){
  int k;
  for (k=i; k<=j; k++) printf("%c", text[k]);
}
void setSuffixIndexByDFS(Node *n, int labelHeight) {
  if (n == NULL)  return;
  int leaf = 1;
  int i;
  for (i = 0; i < MAX_CHAR; i++){
    if (n->children[i] != NULL){
      leaf = 0;
      setSuffixIndexByDFS(n->children[i], labelHeight + sedge(n->children[i]));
    }
  }
  if (leaf == 1) {
    n->suffixIndex = size - labelHeight;
  }
}
  
void freeSuffixTreeByPostOrder(Node *n){
  if (n == NULL) return;
  int i;
  for (i = 0; i < MAX_CHAR; i++){
    if (n->children[i] != NULL){
      freeSuffixTreeByPostOrder(n->children[i]);
    }
  }
  if (n->suffixIndex == -1) free(n->end);
  free(n);
}
void buildSuffixTree(){
  size = strlen(text);
  int i;
  rootEnd = (int*) malloc(sizeof(int));
  *rootEnd = - 1;
  root = newNode(-1, rootEnd);
  anode = root; //First anode will be root
  for (i=0; i<size; i++) extendSuffixTree(i);
  int labelHeight = 0;
  setSuffixIndexByDFS(root, labelHeight);
}
 
void doTraversal(Node *n, int lheight, int* mheight,  int* sstart) {
  if(n == NULL){
      return;
  }
  int i=0;
  if(n->suffixIndex == -1){
    for (i = 0; i < MAX_CHAR; i++) {
      if(n->children[i] != NULL){
        doTraversal(n->children[i], lheight +
                    sedge(n->children[i]), 
										mheight, sstart);
      }
    }
  }
  else if(n->suffixIndex > -1 &&  (*mheight < lheight - sedge(n))){
    *mheight = lheight - sedge(n);
    *sstart = n->suffixIndex;
  }
}
 
void getLongestRepeatedSubstring(){
  int maxHeight = 0;
  int substringStartIndex = 0;
  doTraversal(root, 0, &maxHeight, &substringStartIndex);
  printf("maxHeight %d, substringStartIndex %d\n", maxHeight,
         substringStartIndex);
  printf("Longest Repeated Substring in %s is: ", text);
  int k;
  for (k=0; k<maxHeight; k++)
      printf("%c", text[k + substringStartIndex]);
  if(k == 0)
      printf("No repeated substring");
  printf("\n");
}
  
// driver program to test above functions
int main(int argc, char *argv[]){
  strcpy(text, "GEEKSFORGEEKS$"); //GEEKS
  buildSuffixTree();  
  getLongestRepeatedSubstring();
  //Free the dynamically allocated memory
  freeSuffixTreeByPostOrder(root);

  strcpy(text, "AAAAAAAAAA$"); //ALL A
  buildSuffixTree();  
  getLongestRepeatedSubstring();
  //Free the dynamically allocated memory
  freeSuffixTreeByPostOrder(root);

  strcpy(text, "ABCDEFG$");  //NONE
  buildSuffixTree();  
  getLongestRepeatedSubstring();
  //Free the dynamically allocated memory  
  freeSuffixTreeByPostOrder(root);
    return 0;
}
