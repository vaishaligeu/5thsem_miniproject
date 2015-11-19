#include<stdio.h>
#include<conio.h>
#include<mem.h>
#include"pass1.h"
int pass_2()
{
    struct ins temp;
    symtab *t;
    FILE * f1,* f2,* f3;
    int p,stad,ad;
    char op[10],operand[10],t[];
    p=pass_1("fi.txt");
    f1=fopen("intermediate.txt","r");
    f2=fopen("result.txt","w+");
    f3=fopen("fi.txt","r");
    fscanf(f3,"%s%s%x",label,op,&stad);
    fprintf(f2,"H^%s^%x^%x\n",label,stad,p);
    fscanf(f1,"%x%s%s",ad,op,operand);
    while(strcpy(op,"END")!=0)
    {
        temp=search_opcode(op);
        if(temp.bit!=0)
        {
            if(operand[0]!='-')
            {
                t=search_label(operand);
                if(strcmp(t->lab,'\0')!=0)
                {
                    ad=t->add;
                }
            }
        }
    }
}
int main()
{
    int r;
    r=pass_2();
    printf("done %d",r);
    return 1;
}

