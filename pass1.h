#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"symtab.h"
#include"myheader.h"

int pass_1(char file_name[])
{
    struct ins ten;
    char name[20];
int start_addr;
    int loc_coun,t,r,i,c=0,pc=0,n;
    char le[10],opcode[20],oprnd[10],tem[10];
    char *p;
    FILE *in,*out;
    in=fopen(file_name,"r");
    out=fopen("intermediate.txt","w+");
    opcode_func();
    fscanf(in,"%s%s%x",le,opcode,&t);
    strcpy(name,le);
    if(strcmp(opcode,"START")==0)
    {
        start_addr=t;
        loc_coun=start_addr;
        fscanf(in,"%s%s%s",le,opcode,oprnd);
    }
    else
    {
        loc_coun=0;

    }
    while(strcmp(opcode,"END")!=0)
    {

        if(le[0]!=';')
        {
            if(le[0]!='-')
            {
                if(c==0)
                {
                    create(le,loc_coun);
                }
                else
                {
                    if(strcmp(search_label(le).lab,'\0')!=0)
                    {
                        printf("\nDUPLICATE ERROR\n");
                    }
                    else
                    {
                        create(le,loc_coun);
                    }
                }
            }

            ten=search_opcode(opcode);

            if(ten.bit!=0)
            {
                loc_coun+=ten.bit;
                n=ten.bit;

            }
            else if(strcmp(opcode,"WORD")==0)
            {
                loc_coun+=3;
                n=3;
            }
            else if(strcmp(opcode,"RESW")==0)
            {
                 t = strtol (oprnd,&p,16);
                 loc_coun+=(3*t);
              n=3*t;
            }
             else if(strcmp(opcode,"RESB")==0)
            {
                itoa(atoi(oprnd),tem,16);
                r=atoi(tem);
                loc_coun+=r;
                n=r;
            }
             else if(strcmp(opcode,"BYTE")==0)
            {
                if(oprnd[0]=='X')
                {
                    loc_coun+=1;
                    n=1;
                }
                if(oprnd[0]=='C')
                {
                    loc_coun+=(strlen(oprnd)-3);
                    n=(strlen(oprnd)-3);
                }
            }
            else if(opcode[0]=='+')
            {
            for(i=1;i<strlen(opcode);i++)
            {
                tem[i-1]=opcode[i];
            }
            if((search_opcode(tem).bit)!=0)
            {
                loc_coun+=4;
                n=4;
            }
            else
            {
                printf("\nERROR:invalid opcode\n");

            }
            }
            else
            {
                printf("\n%sERROR:invalid opcode\n",opcode);

            }


        fprintf(out,"%x\t\t\t%s\t\t\t%s\n",loc_coun-n,opcode,oprnd);

        }
         fscanf(in,"%s%s%s",le,opcode,oprnd);

    }

         fprintf(out,"%x\t\t\t%s\t\t\t%s\n",loc_coun,opcode,oprnd);

        pc=loc_coun-start_addr;

        return pc;
}
