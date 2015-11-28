#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#include"optab.c"

int pass_1(char file_name[])
{
    struct ins ten;
    char name[20];
int start_addr;
    int loc_coun,t,r,i,c=0,pc=0,n,flg=0;
    char le[10],opcode[20],oprnd[10],tem[10],te[10],tv[10];
    char *p;
    FILE *in,*out,*sy,*ss;
    in=fopen(file_name,"r");
    out=fopen("intermediate.txt","w+");
    sy=fopen("sym.txt","w+");
    printf("\n\nintermediate file\n\n");
    opcode_func();
    fscanf(in,"%s%s%06x",le,opcode,&t);
    strcpy(name,le);
    if(strcmp(opcode,"START")==0)
    {
        start_addr=t;
        loc_coun=start_addr;
        fprintf(out,"-\t\t\t\t%s\t\t\t\t%s\t\t\t%04x\n",le,opcode,t);
        printf("-\t\t%s\t\t%s\t\t%04x\n",le,opcode,t);
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
                    c++;
            fprintf(sy,"%s\t\t%04x\n",le,loc_coun);
                }
                else
                {
                    flg=0;
                    rewind(sy);
                    while(!feof(sy))
                    {
                        fscanf(sy,"%s%s",te,tv);
                        if(strcmp(le,te)==0)
                        {
                            flg=1;
                            break;
                        }
                    }

                    //ss=fopen("sym.txt","r");
                     if(flg==1)
                    {
                        printf("\nDUPLICATE ERROR:%s\n",le);

                    }
                    else
                    {

                       fprintf(sy,"%s\t\t%04x\n",le,loc_coun);
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
            else
            {
                printf("\n ERROR:invalid opcode:\n%s\n",opcode);


            }


        fprintf(out,"%04x\t\t\t\t%s\t\t\t\t%s\t\t\t%s\n",loc_coun-n,le,opcode,oprnd);
        printf("%04x\t\t%s\t\t%s\t\t%s\n",loc_coun-n,le,opcode,oprnd);


        }
         fscanf(in,"%s%s%s",le,opcode,oprnd);

    }

         fprintf(out,"%04x\t\t\t\t-\t\t\t\t%s\t\t\t%s\n",loc_coun,opcode,oprnd);
 printf("%04x\t\t-\t\t%s\t\t%s\n",loc_coun,opcode,oprnd);
        pc=loc_coun-start_addr;
        fclose(in);
 fclose(out);
fclose(sy);
        return pc;
}
void pass_two(int si)
{
    struct ins t;
     FILE *in,*out,*sy;
     int tl,a,rl,i,j,m[10],l,p,mm;
     char op[10],ad[10],oprnd[10],tex[100],le[10],addr[10],ov[10],tv[10],c[10],te[10],tm[10],tem[10];
    in=fopen("intermediate.txt","r");
    out=fopen("result.txt","w+");
    sy=fopen("sym.txt","r");
fscanf(in,"%s%s%s%x",&ad,le,op,&a);
l=a;
printf("\n\nobject file\n\n");
if(strcmp(op,"START")==0)
   {
   fprintf(out,"H^00%x^00%x\n",a,si);
   printf("H^00%x^00%x\n",a,si);
   fscanf(in,"%s%s%s%s",ad,le,op,oprnd);
   }
    while(strcmp(op,"END")!=0)
{


   strcpy(addr,ad);
   memset(tex,'\0',sizeof(tex));
   rl=0;
  while((rl<30)&&strcmp(op,"END")!=0)
{

    t=search_opcode(op);
    if(t.bit!=0)
    {

        rl+=3;

        strcat(tex,t.opco);
        if(strcmp(oprnd,"-")!=0)
        {
p=0;
            while(!feof(sy))
            {
                fscanf(sy,"%s%s",tm,te);
                if(strcmp(tm,oprnd)==0)
                {

                    p=1;
                    break;
                }
            }
rewind(sy);
            if(p==1)
               {


                   strcat(tex,te);
                   strcat(tex,"^");
               }
                else if(oprnd[0]=='#')
               {
                    memset(tem,'\0',sizeof(tem));
                   for(i=0;i<strlen(oprnd)-1;i++)
                   {
                       tem[i]=oprnd[i+1];
                   }
                   tem[i]='\0';
                     strcat(tex,tem);
                   strcat(tex,"^");
               }
               else if(oprnd[strlen(oprnd)-1]=='X')
               {
                   for(i=0;i<strlen(oprnd)-2;i++)
                   {
                       tem[i]=oprnd[i];

                   }
                   tem[i]='\0';
                   p=0;
            while(!feof(sy))
            {
                fscanf(sy,"%s%s",tm,te);
                if(strcmp(tm,tem)==0)
                {

                    p=1;
                    break;
                }
            }
rewind(sy);
                  if(p==1)
                  {
                      mm=48-te[0];

                       mm=mm+8;
                       mm=mm+8;
                     itoa(mm,tem,16);

                     for(i=0;i<strlen(te)-1;i++)
                     {
                         c[i]=te[i+1];
                     }
                     c[i]='\0';
                     strcat(tem,c);
                       strcat(tex,tem);
                   strcat(tex,"^");
                  }
               }
                else
                {

                    strcat(tex,"0000");
                     strcat(tex,"^");
                }
               fscanf(in,"%s\t%s\t%s\t%s",ad,le,op,oprnd);
        }
        else
        {
          strcat(tex,"0000");
          fscanf(in,"%s\t%s\t%s\t%s",ad,le,op,oprnd);
        }
    }
        else if(strcmp(op,"WORD")==0)
        {
            rl+=3;
            strcat(tex,"^");
            strcat(tex,"0000");

            p=atoi(oprnd);
            itoa(p,oprnd,16);
            strcat(tex,oprnd);
              fscanf(in,"%s\t%s\t%s\t%s",ad,le,op,oprnd);
        }
        else if(strcmp(op,"BYTE")==0)
        {
             strcat(tex,"^");
            p=strlen(oprnd);
            if(oprnd[0]=='c')
            {

                for(i=2,j=0;i<p-1;i++,j++)
                {
                    m[j]=oprnd[i];
                    itoa(m[j],c,16);
                     strcat(tex,c);
                }
                m[j]='\0';
                rl+=j;


           }
           if(oprnd[0]=='X')
           {
             for(i=2,j=0;i<p-1;i++,j++)
             {
                c[j]=oprnd[i];
             }
             c[j]='\0';

             if(j%2==0)
             {
              rl+=j/2;
             }
             else
             {
                 rl+=(j/2)+1;
             }

                strcat(tex,c);
           }
            fscanf(in,"%s\t%s\t%s\t%s",ad,le,op,oprnd);
        }
        else if(strcmp(op,"RESW")==0||strcmp(op,"RESB")==0)
        {
             fscanf(in,"%s\t%s\t%s\t%s",ad,le,op,oprnd);

        }
        else
        {

             fscanf(in,"%s\t%s\t%s\t%s",ad,le,op,oprnd);

break;
        }
}
fprintf(out,"T^%s^%02x^%s\n",addr,rl,tex);
printf("T^%s^%02x^%s\n",addr,rl,tex);

}
fprintf(out,"E^00%x",l);

printf("E^00%x",l);
}

