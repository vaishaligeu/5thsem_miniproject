#include<stdio.h>
#include<conio.h>
#include<mem.h>
int pass_1()
{
    int start_add=0,i=0,pc=0,loc,space=0,j,k,l;
    char filename[20],opcode[10],operand[30],label[20],symtab[20][100];
    printf("enter file name\n");
    scanf("%s",filename);
     FILE *fp;
     fp=fopen(filename,"r");
     while(!feof(fp))
     {
         i=0;
         j=0;
         k=0;
         l=0;
         space=0;
         memset(line,'\0',sizeof(line));
         memset(line,'\0',sizeof(label));
         memset(line,'\0',sizeof(operand));
     ch = fgetc(fp);
while(ch != '\n')
  {
      if(space=0&&ch!='')
      {
          label[i]=ch;
          i++;
      }
      elseif(space=2&&)

  }
     if(opcode = "START")
    {
        start_add=operand;
        loc=start_add;
    }
     }
}
