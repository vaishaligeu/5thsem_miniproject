#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int countlines(char filename[])
{
  // count the number of lines in the file called filename
  FILE *fp = fopen(filename,"r");
  int ch=0;
  int lines=0;

 lines++;
 while(!feof(fp))
{
  ch = fgetc(fp);

  if(ch == '\n')
  {
    lines++;
  }
}
  fclose(fp);
  return lines;
}
int main()
{
    int count_lines = 0;
    char filechar[40],*opcod,*operand;
    printf("Enter file name: ");
    scanf("%s", filechar);
    count_lines=countlines(filechar);

    return 1;
}
