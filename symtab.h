struct symtab
{
   char lab[20];
   int add;
   struct symtab * next;
}*start=NULL;
typedef struct symtab symtab;
void create(char l[],int a)
{
    symtab *new_node,*current;

  new_node=(symtab *)malloc(sizeof(symtab));
  strcpy(new_node->lab,l);
  new_node->add=a;
  new_node->next=NULL;

  if(start==NULL)
  {
  start=new_node;
  current=new_node;
  }
  else
  {
  current->next=new_node;
  current=new_node;
  }

}
int search_label(char l[])
{
int flag = 0;
symtab *temp;

temp = start;
  while(temp!=NULL)
  {
    if(strcmp(temp->lab,l)==0)
    {
    return(1); //Found
    }
    temp = temp->next;
  }

if(flag ==0)
    return(0); // Not found
}
