int read_line(char s[],int n)
{
int ch,i=0;
ch=getchar();
while(ch!='\n')
if (i<n)
s[i++]=ch;
s[i]='\0';
return i;
}
