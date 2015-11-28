#include<stdio.h>
#include<conio.h>
#include"pass.c"
 char file_name[10];
 void banner()
 {
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\tGRAPHIC  ERA  UNIVERSITY\n");
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\tSIC ASSEMBLER\n");
     printf("\t\t\t\t\t\t\t\t\t\t\t\t\tMINI PROJECT V SEM\n\n\n");
 }
void reallocate(int add)
{
    FILE *f1,*f2;
    char la[10],mn[10],opr[10];
    int si;
    f1=fopen(file_name,"r");
    f2=fopen("new.txt","w");
    //printf("%s",file_name);
    fscanf(f1,"%s%s%s",la,mn,opr);
    //printf("\n\n%s%s%s",la,mn,opr);
    while(strcmp(mn,"END")!=0)
    {

        if(strcmp(mn,"START")==0)
        {
            fprintf(f2,"%s\t\t%s\t\t%d\n",la,mn,add);

        }
        else
        {
           fprintf(f2,"%s\t\t%s\t\t%s\n",la,mn,opr);
        }
        fscanf(f1,"%s%s%s",la,mn,opr);
      //  printf("\n%s\t%s\t%s",la,mn,opr);
//break;
    }
    fprintf(f2,"%s\t\t%s\t\t%s",la,mn,opr);
//si=3333;
fclose(f2);
    si=pass_1("new.txt");
   pass_two(si);
   //printf("\n\nsi=%x",si);
//fclose(f2);
    fclose(f1);
}


int main()
{
    int r,add;

    memset(file_name,'\0',sizeof(file_name));
banner();
    printf("\nFILE NAME:");
    scanf("%s",file_name);

    r=pass_1(file_name);

pass_two(r);
printf("\n\n\n\n\nenter address where program is to be reallocated\n");
scanf("%d",&add);
reallocate(add);
    return 1;
}
