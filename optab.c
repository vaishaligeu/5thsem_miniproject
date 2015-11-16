#include<stdio.h>
#include<conio.h>
#include<string.h>
struct ins
{
    char mn[100];
    int bit;
    int op;
}o[33];
int main()
{
    strcpy(o[0].mn,"AD");
    o[0].bit=3;
    o[0].op=0x18;
     strcpy(o[1].mn,"ADF");
    o[1].bit=3;
    o[1].op=0x58;
     strcpy(o[2].mn,"ADR");
    o[2].bit=2;
    o[2].op=0x90;
     strcpy(o[3].mn,"AAND");
    o[3].bit=3;
    o[3].op=0x40;
     strcpy(o[4].mn,"CLRR");
    o[4].bit=2;
    o[4].op=0xb4;
     strcpy(o[5].mn,"CMPR");
    o[5].bit=3;
    o[5].op=0x28;
     strcpy(o[6].mn,"CMPRF");
    o[6].bit=3;
    o[6].op=0x88;
    strcpy(o[7].mn,"CMPRR");
    o[7].bit=2;
    o[7].op=0xa0;
     strcpy(o[8].mn,"DVSN");
    o[8].bit=3;
    o[8].op=0x24;
    strcpy(o[9].mn,"DVSNF");
    o[9].bit=3;
    o[9].op=0x64;
    strcpy(o[10].mn,"DVSNR");
    o[10].bit=2;
    o[10].op=0x9c;
     strcpy(o[11].mn,"JS");
    o[11].bit=3;
    o[11].op=0x3c;
     strcpy(o[12].mn,"JSEQ");
    o[12].bit=3;
    o[12].op=0x30;
     strcpy(o[13].mn,"JSGT");
    o[13].bit=3;
    o[13].op=0x34;
     strcpy(o[14].mn,"JSLT");
    o[14].bit=3;
    o[14].op=0x38;
     strcpy(o[15].mn,"JSSUB");
    o[15].bit=3;
    o[15].op=0x48;
     strcpy(o[16].mn,"LODA");
    o[16].bit=3;
    o[16].op=0x00;
     strcpy(o[17].mn,"LODB");
    o[17].bit=3;
    o[17].op=0x68;
    strcpy(o[18].mn,"LODCH");
    o[18].bit=3;
    o[18].op=0x50;
    strcpy(o[19].mn,"LODS");
    o[19].bit=3;
    o[19].op=0xd0;
    strcpy(o[20].mn,"MULPY");
    o[20].bit=3;
    o[20].op=0x20;
    strcpy(o[21].mn,"MULPYR");
    o[21].bit=2;
    o[21].op=0x98;
    strcpy(o[22].mn,"ORR");
    o[22].bit=3;
    o[22].op=0x44;
    strcpy(o[23].mn,"RRD");
    o[23].bit=3;
    o[23].op=0xd8;
    strcpy(o[24].mn,"SHRL");
    o[24].bit=2;
    o[24].op=0xa4;
    strcpy(o[25].mn,"SHRR");
    o[25].bit=2;
    o[25].op=0xa8;
      strcpy(o[26].mn,"STORA");
    o[26].bit=3;
    o[26].op=0x0c;
      strcpy(o[27].mn,"SUBTR");
    o[27].bit=3;
    o[27].op=0x1c;
      strcpy(o[28].mn,"SUBTRR");
    o[28].bit=2;
    o[28].op=0x94;
       strcpy(o[29].mn,"SVCC");
    o[29].bit=2;
    o[29].op=0xb0;
       strcpy(o[30].mn,"TIIO");
    o[30].bit=1;
    o[30].op=0xf8;
       strcpy(o[31].mn,"WDD");
    o[31].bit=3;
    o[31].op=0xdc;
        strcpy(o[32].mn,"STCH");
    o[32].bit=3;
    o[32].op=0x54;
        strcpy(o[33].mn,"STOL");
    o[33].bit=3;
    o[33].op=0xdc;
    printf("done");
    return 1;
}















