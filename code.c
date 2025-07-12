
 char a[37]={' ','a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','0','1','2','3','4','5','6','7','8','9'};
 void display(char ch)
 {
  switch(ch)
   {
    case 'a':
     PORTB=0x77;
     break;
    case 'b':
     PORTB=0x7C;
     break;
    case 'c':
     PORTB=0x39;
     break;
    case 'd':
     PORTB=0x5E;
     break;
    case 'e':
     PORTB=0x79;
     break;
    case 'f':
     PORTB=0x71;
     break;
    case 'g':
     PORTB=0x3D;
     break;
    case 'h':
     PORTB=0x74;
     break;
    case 'i':
     PORTB=0x04;
     break;
    case 'j':
     PORTB=0x0E;
     break;
    case 'k':
     PORTB=0x75;
     break;
    case 'l':
     PORTB=0x38;
     break;
    case 'm':
     PORTB=0x55;
     break;
    case 'n':
     PORTB=0x54;
     break;
    case 'o':
     PORTB=0x5C;
     break;
    case 'p':
     PORTB=0x73;
     break;
    case 'q':
     PORTB=0x67;
     break;
    case 'r':
     PORTB=0x50;
     break;
    case 's':
     PORTB=0x6D;
     break;
    case 't':
     PORTB=0x78;
     break;
    case 'u':
     PORTB=0x3E;
     break;
    case 'v':
     PORTB=0x1C;
     break;
    case 'w':
     PORTB=0x6A;
     break;
    case 'x':
     PORTB=0x76;
     break;
    case 'y':
     PORTB=0x6E;
     break;
    case 'z':
     PORTB=0x5B;
     break;
    case '0':
     PORTB=0x3F;
     break;
    case '1':
     PORTB=0x06;
     break;
    case '2':
     PORTB=0x5B;
     break;
    case '3':
     PORTB=0x4F;
     break;
    case '4':
     PORTB=0x66;
     break;
    case '5':
     PORTB=0x6D;
     break;
    case '6':
     PORTB=0x7D;
     break;
    case '7':
     PORTB=0x07;
     break;
    case '8':
     PORTB=0x7F;
     break;
    case '9':
     PORTB=0x6F;
     break;
    case ' ':
     PORTB=0x00;
     break;
    case '-':
     PORTB=0x40;
     break;
    default:
     PORTB=0x2D;
   }
 }

 void print(char *s)
 {
   short int i;
   for(i=0;i<9/*s[i]!='\0'*/;++i)
   {
      PORTC = ~(1<<i);
      PORTB=0x00;
      display(s[i]);
      Delay_ms(3);
   }
 }

void edit(char *s)
{
   short int i,j,k,fl=0,flg=0;
   for(i=0;i<25;++i)
      print("input   ");
   for(i=0;i<5;++i)
      print("        ");
   i=j=0;k=1;
   PORTA=0xFF;
   while(1)
   {
     if(i>36) i=0;
     if(k>8) j=k-8;
     if(fl==0) s[k]='-';
     print(s+j+1);
     if(PORTA.F0==0)
     {
      delay_ms(1);
      if(PORTA.F0==0&& ((s[1]>96&&s[1]<124)||(s[1]>47&&s[1]<59)) && fl==0) break;
     }
     else if(PORTA.F1==0)
     {
      Delay_ms(1);
      if(PORTA.F1==0)
      {
        s[k]=a[i++];
        fl=flg=1;
        Delay_ms(300);
      }
     }
     else if(PORTA.F2==0)
     {
      Delay_ms(1);
      if(PORTA.F2==0 && flg==1)
      {
        i=0;
        k++;
        fl=flg=0;
        Delay_ms(300);
      }
     }
   }
   s[k]=a[0];
   s[k+1]='\0';
}
void main()
{
  short int a,i,j,sp;
   char op[9],s[]="                          ";
  TRISA=1;
  TRISB=0;
  TRISC=0;
  ADCON0=0x00;
  ADCON1=0x07;
  sp=0;
  edit(s);
  while(1)
  {
    if(s[sp]=='\0') sp=0;
    for(i=0,j=sp;i<8;++i,++j)
    {
      if(s[j]=='\0') j=0;
      op[i]=s[j];
    }
    op[i]='\0';
    for(a=0;a<12;++a)
     print(op);
    ++sp;

  }
}